# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mpeulet <mpeulet@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/11 11:29:48 by OrioPrisc         #+#    #+#              #
#    Updated: 2024/02/07 12:38:30 by OrioPrisc        ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


CC				=	cc

SRC_COMMON				=	raycast.c \
					math_utils.c \
					vec2d.c \
					env.c \
					image.c \
					image2.c \
					draw.c \
					deal_key.c \
					hooks.c \
					collision.c \
					utils.c \
					vector_to_2dtab.c \
					map_to_lines/map_to_lines.c \
					map_to_lines/need_lines.c \
					mini_map/mini_map.c \
					parsing/convert_cub_to_vector.c \
					parsing/debug_print_cub.c \
					parsing/error_management.c \
					parsing/extract_colors.c \
					parsing/flood_fill.c \
					parsing/extract_textures.c \
					parsing/find_player.c \
					parsing/parse_utils.c \

ALL_SRC = $(SRC_COMMON) main.c

NAME			=	cub3d
NAME_BONUS		=	cub3d_bonus

OBJ_FOLDER		=	objs/

CFLAGS			=	-Wall -Wextra -Werror -g

SRC_FOLDER		=	srcs/

INC_FOLDER		=	includes/

HEADERS_FOLDER	=	includes/\
					libft/includes/\
					minilibx-linux/\

LIBS			=	libft/libft.a\
					libft/libftprintf.a\
					libft/libgetnextline.a\
					minilibx-linux/libmlx.a\

#here to ensure things get pulled properly
SUBMODULES		=	libft/.git\
					libft/ftprintf/.git\
					libft/getnextline/.git\
					minilibx-linux/.git\

LFLAGS			=	-Llibft -Lminilibx-linux -lftprintf -lvector -lgetnextline -lft -lmlx -lXext -lX11 -lm -lbsd

DEPENDS		:=	$(patsubst %.c,$(OBJ_FOLDER)%.d,$(ALL_SRC))
OBJS		:=	$(patsubst %.c,$(OBJ_FOLDER)%.o,$(SRC_COMMON) main.c)
OBJS_BONUS	:=	$(patsubst %.c,$(OBJ_FOLDER)%.o,$(SRC_COMMON) main_bonus.c)
COMMANDS	:=	$(patsubst %.c,$(OBJ_FOLDER)%.cc,$(ALL_SRC))

all: $(NAME) compile_commands.json

bonus: $(NAME_BONUS) compile_commands.json

-include $(DEPENDS)

$(SUBMODULES) :
	git submodule update --init --recursive

%.a: | $(SUBMODULES)
	make -C $(@D) MAKEFLAGS=

$(NAME_BONUS): $(LIBS) $(OBJS_BONUS) | $(SUBMODULES)
	$(CC) $(CFLAGS) $(OBJS_BONUS) $(LFLAGS) -o $@

$(NAME): $(LIBS) $(OBJS) | $(SUBMODULES)
	$(CC) $(CFLAGS) $(OBJS) $(LFLAGS) -o $@

COMP_COMMAND = $(CC) -c $(CFLAGS) $(addprefix -I,$(HEADERS_FOLDER)) -MMD -MP $< -o $@
CONCAT = awk 'FNR==1 && NR!=1 {print ","}{print}'

$(OBJ_FOLDER)main_bonus.o $(OBJ_FOLDER)main.cc: $(SRC_FOLDER)main.c Makefile | $(SUBMODULES)
	@mkdir -p $(@D)
	$(COMP_COMMAND) -DBONUS=1
	@printf '{\n\t"directory" : "$(shell pwd)",\n\t"command" : "$(COMP_COMMAND)",\n\t"file" : "$<"\n}' > $(OBJ_FOLDER)main.cc

$(OBJ_FOLDER)%.o $(OBJ_FOLDER)%.cc: $(SRC_FOLDER)%.c Makefile | $(SUBMODULES)
	@mkdir -p $(@D)
	$(COMP_COMMAND)
	@printf '{\n\t"directory" : "$(shell pwd)",\n\t"command" : "$(COMP_COMMAND)",\n\t"file" : "$<"\n}' > $(OBJ_FOLDER)$*.cc

compile_commands.json : $(COMMANDS) Makefile
	@echo "Making compile_commands.json"
	@echo "[" > compile_commands.json
	@$(CONCAT) $(COMMANDS) >> compile_commands.json
	@echo "]" >> compile_commands.json

clean: | $(SUBMODULES)
	rm -f $(OBJS) $(DEPENDS) $(COMMANDS)
	for lib in $(shell dirname $(LIBS)); do \
		make -C $$lib clean; \
	done

fclean: clean | $(SUBMODULES)
	rm -f $(NAME) compile_commands.json
	make -C libft fclean

re: fclean all

norm:
	@norminette $(SRC_FOLDER) $(INC_FOLDER) | grep -A1 -B1 Error | grep -v 'OK!' || true

.PHONY: all clean fclean re norm bonus
.SUFFIXES:
MAKEFLAGS += --warn-undefined-variables
MAKEFLAGS += --no-builtin-rules
