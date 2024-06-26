/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   messages.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpeulet <mpeulet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 13:48:17 by mpeulet           #+#    #+#             */
/*   Updated: 2024/02/09 15:12:48 by mpeulet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MESSAGES_H
# define MESSAGES_H

/*DEF_COLOR		= \033[0;39m
GRAY			= \033[0;90m
RED				= \033[0;91m
GREEN			= \033[0;92m
YELLOW			= \033[0;93m
BLUE			= \033[0;94m
MAGENTA			= \033[0;95m
CYAN			= \033[0;96m
WHITE			= \033[0;97m*/

# define ARG_NB "You must only pass one .cub file as a \
parameter.\n\033[0;92mExample : ./cub3d maps/your_map.cub\033[0;39m"
# define CUB_IS_DIR "The file you passed as a parameter is a directory."
# define IS_NOT_CUB "The file extension must be a .cub."

# define VECTOR_APP_ERR "Error coming from vector memory management."
# define OPEN_CUB "when opening .cub file."

# define INVALID_SIZE "Map is invalid due to the file size, it must contain \
4 textures, 2 colors and a playable map.\n\n\033[0;92mMinimum expected 9 lines :\n\nNO \
./textures/NO.xpm\nSO ./textures/SO.xpm\nWE ./textures/WE.xpm\n\
EA ./textures/EA.xpm\nF 220,100,0\nC 225,30,0\n 1\n1N1\n 1\n\033[0;39m\
\n\033[0;91mFile size tested :\033[0;39m"

# define F_FORMAT "Format for floor color is invalid\nF line :"
# define C_FORMAT "Format for ceiling color is invalid\nC line :"
# define F_MISSING "Couldn't find F line in the first part of the file. \
Please check if there is a valid format for F line and no invalid line in \
the first 6 lines after clearing empty lines."
# define C_MISSING "Couldn't find C line in the first part of the file. \
Please check if there is a valid format for F line and no invalid line in \
the first 6 lines after clearing empty lines."

# define NO_MISSING "Line containing path to NO texture is missing or invalid."
# define SO_MISSING "Line containing path to SO texture is missing or invalid."
# define WE_MISSING "Line containing path to WE texture is missing or invalid."
# define EA_MISSING "Line containing path to EA texture is missing or invalid."

# define TEXT_MALLOC_FAIL "Malloc failed in texture_utils fn resulting \
in program malfunction."
# define MALLOC_FAIL "Malloc failed"

# define INV_CHAR "Invalid character found in the map.\nFirst invalid \
character found in the map :"

# define NO_PLAYER_FOUND "Player is missing in the map."
# define TOO_MANY_PLAYER "There are too many players found in the map.\nNumber \
of player found : "
# define MAP_EDGE "Player is on the edge of the map."
# define CLOSED_MAP "Map is invalid, walls do not close"

# define NO_WALL "Map is invalid.\nA hole in the wall was found here :"

# define BONUS_XPM_ERR "Failed to read the bonus files."

# define MLX_PB "Mlx encountered a problem"

#endif
