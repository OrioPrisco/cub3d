# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mpeulet <mpeulet@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/11 11:29:48 by OrioPrisc         #+#    #+#              #
#    Updated: 2024/01/11 13:48:55 by mpeulet          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC				=	cc

SRC				=	main.c \
					raycast.c \
					math_utils.c \
					vec2d.c \
					parsing/convert_cub_to_vector.c \
					parsing/parse_utils.c \
					parsing/small_utils.c \

NAME			=	cub3d

OBJ_FOLDER		=	objs/

CFLAGS			=	-Wall -Wextra -Werror -g

SRC_FOLDER		=	srcs/

HEADERS_FOLDER	=	includes/\
					libft/includes/\

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

DEPENDS		:=	$(patsubst %.c,$(OBJ_FOLDER)%.d,$(SRC))
OBJS		:=	$(patsubst %.c,$(OBJ_FOLDER)%.o,$(SRC))
COMMANDS	:=	$(patsubst %.c,$(OBJ_FOLDER)%.cc,$(SRC))

all: $(NAME) compile_commands.json

bonus: all

-include $(DEPENDS)

$(SUBMODULES) :
	git submodule update --init --recursive

%.a: | $(SUBMODULES)
	make -C $(@D) MAKEFLAGS=

$(NAME): $(LIBS) $(OBJS) | $(SUBMODULES)
	$(CC) $(CFLAGS) $(OBJS) $(LFLAGS) -o $@

COMP_COMMAND = $(CC) -c $(CFLAGS) $(addprefix -I,$(HEADERS_FOLDER)) -MMD -MP $< -o $@
CONCAT = awk 'FNR==1 && NR!=1 {print ","}{print}'

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

.PHONY: all clean fclean re bonus
.SUFFIXES:
MAKEFLAGS += --warn-undefined-variables
MAKEFLAGS += --no-builtin-rules
