/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spascual <spascual@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 12:56:21 by spascual          #+#    #+#             */
/*   Updated: 2025/03/24 16:39:00 by spascual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../cub3d.h"
// ./cub3d maps/1.cub

int main(int argc, char **argv)
{
	if (argc == 2)
	{
		t_map *map = malloc(sizeof(t_map));
		if (!map)
		{
			// STDERR_FILENO == 2
			write(2, "Error: No se pudo asignar memoria para el mapa\n", 47);
			return (1);
		}

		if ((window_open()) != 0 && (check_map(argv[1], map) != 0))
		{
			free(map);
			// Manejo de error si no se pudo abrir la ventana
			return (1);
		}
	}
	return (0);
}

// TO DO
// struct para el mapa
// coger argumentos y eso para crear la struct
// validar mapa
// poner y buscar imagenes
// colores para el suelo y cielo
// raycasting, sea lo que sea eso
// movimiento jugador
// rotacion de la camara
// merorar suavidad movimiento con ajustes velocidad
// memory leaks y edge cases
// crear test maps
