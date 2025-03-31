/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spascual <spascual@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 13:11:53 by spascual          #+#    #+#             */
/*   Updated: 2025/03/24 16:19:01 by spascual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define WIDTH 1000
# define HEIGHT 500

# define ESC_KEY 65307
# define L_ARROW 65361
# define U_ARROW 65362
# define R_ARROW 65363
# define D_ARROW 65364

# define CHAR_PATH "img/"
# define WALL_N_PATH "img/"
# define WALL_S_PATH "img/"
# define WALL_E_PATH "img/"
# define WALL_W_PATH "img/"
# define GROUND_PATH "img/"
# define SKY_PATH "img/"
# define EXIT_PATH "img/exit.xpm"

# include "libs/libft/libft.h"
# include "libs/mlx/mlx.h"
# include "libs/mlx/mlx_int.h"
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>


typedef struct s_vars
{
	void	*mlx;
	void	*win;
}	t_vars;

typedef struct s_map
{
	char	**grid;	 // Matriz del mapa
	int		 width;	  // Ancho del mapa
	int		 height;	 // Alto del mapa
	int		 player_x;   // Posición X del jugador
	int	 	player_y;   // Posición Y del jugador
	char	player_dir; // Dirección inicial del jugador ('N', 'S', 'E', 'W')

	char	*wall_north; // Ruta textura pared norte
	char	*wall_south; // Ruta textura pared sur
	char	*wall_east;  // Ruta textura pared este
	char	*wall_west;  // Ruta textura pared oeste
	int	 	floor_color; // Color del suelo en formato RGB
	int		ceiling_color; // Color del cielo en formato RGB

} t_map;

// o en define? // si tu struct esta lleno de const es lo mismo que que todos sean define?
typedef struct s_keys
{
	
}	t_keys;



// Inicializacion
int		window_open(void);

// Map checks
int		check_map_extension(char *filename);
int		parse_rgb(char *line);
void	parse_line(char *line, t_map *map, int *reading_map);
int		load_map(t_map *map, char *filename);
int		check_map(char *filename, t_map *map);



#endif