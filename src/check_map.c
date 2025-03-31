/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spascual <spascual@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 16:06:24 by spascual          #+#    #+#             */
/*   Updated: 2025/03/24 17:01:22 by spascual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int check_map_extension(char *filename)
{
	int len = ft_strlen(filename);
	if (len < 4 || ft_strncmp(&filename[len - 4], ".cub", 4) != 0)
	{
		write(STDERR_FILENO, "Error: El archivo debe tener extensión .cub\n", 45);
		return (1);
	}
	return (0);
}

int parse_rgb(char *line)
{
	int r, g, b;
	char **colors = ft_split(line, ',');
		
	if (!colors || !colors[0] || !colors[1] || !colors[2] || colors[3])
	{
		write(STDERR_FILENO, "Error: Formato RGB inválido\n", 27);
		return (-1);
	}
		
	r = ft_atoi(colors[0]);
	g = ft_atoi(colors[1]);
	b = ft_atoi(colors[2]);
		
	if (r < 0 || r > 255 || g < 0 || g > 255 || b < 0 || b > 255)
	{
		write(STDERR_FILENO, "Error: Valores RGB fuera de rango\n", 33);
		return (-1);
	}
		
	free(colors[0]);
	free(colors[1]);
	free(colors[2]);
	free(colors);
		
	return (r << 16) | (g << 8) | b;
}

void parse_line(char *line, t_map *map, int *reading_map)
{
	if (*reading_map)
	{
		// Guardar la línea del mapa en grid
		map->grid[map->height] = ft_strdup(line);
		map->height++;
	}
	else if (ft_strncmp(line, "NO ", 3) == 0)
		map->wall_north = ft_strdup(line + 3);
	else if (ft_strncmp(line, "SO ", 3) == 0)
		map->wall_south = ft_strdup(line + 3);
	else if (ft_strncmp(line, "WE ", 3) == 0)
		map->wall_west = ft_strdup(line + 3);
	else if (ft_strncmp(line, "EA ", 3) == 0)
		map->wall_east = ft_strdup(line + 3);
	else if (ft_strncmp(line, "F ", 2) == 0)
		map->floor_color = parse_rgb(line + 2);
	else if (ft_strncmp(line, "C ", 2) == 0)
		map->ceiling_color = parse_rgb(line + 2);
	else if (ft_isdigit(line[0]) || line[0] == ' ')
	{
		*reading_map = 1;
		map->grid = realloc(map->grid, sizeof(char *) * (map->height + 1));
		map->grid[map->height] = ft_strdup(line);
		map->height++;
	}
}

int load_map(t_map *map, char *filename)
{
	int fd;
	char *line;
	int reading_map = 0;
		
	fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		write(STDERR_FILENO, "Error: No se pudo abrir el archivo\n", 35);
		return (1);
	}
		
	map->grid = NULL;
	map->height = 0;
		
	while ((line = get_next_line(fd)))
	{
		parse_line(line, map, &reading_map);
		free(line);
	}
	close(fd);
		
	if (map->grid == NULL)
	{
		write(STDERR_FILENO, "Error: El mapa no contiene una estructura válida\n", 50);
		return (1);
	}
		
	map->width = ft_strlen(map->grid[0]);
		
	return (0);
}

int check_map(char *filename, t_map *map)
{
	if (check_map_extension(filename) != 0)
		return (1);
		
	if (load_map(map, filename) != 0)
		return (1);
		
	//if (check_map_structure(map) != 0)
	//	return (1);
		
	return (0);
}
