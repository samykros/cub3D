/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spascual <spascual@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 15:45:01 by spascual          #+#    #+#             */
/*   Updated: 2025/03/24 16:19:19 by spascual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../cub3d.h"

// Función para inicializar la estructura del mapa
t_map	*init_map(void)
{
	t_map *map;

	map = malloc(sizeof(t_map));
	if (!map)
	{
		write(STDERR_FILENO, "Error: No se pudo asignar memoria para el mapa\n", 47);
		return (NULL);
	}

	map->grid = NULL;
	map->width = 0;
	map->height = 0;
	map->player_x = -1;
	map->player_y = -1;
	map->player_dir = '\0';
		
	map->wall_north = NULL;
	map->wall_south = NULL;
	map->wall_east = NULL;
	map->wall_west = NULL;

	map->floor_color = -1;
	map->ceiling_color = -1;
		
	return (map);
}
