/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spascual <spascual@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 15:18:08 by spascual          #+#    #+#             */
/*   Updated: 2025/03/24 18:13:11 by spascual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../cub3d.h"

static int handle_esc(int keycode, t_vars *vars)
{
	if (keycode == ESC_KEY) // Código de tecla para ESC en macOS/MLX
	{
		printf("Exit window\n");
		mlx_destroy_window(vars->mlx, vars->win); // Sustituye el segundo argumento por la ventana actual
		exit(0);
	}
	return (0);
}

// Callback para cerrar la ventana con la X
static int handle_close(t_vars *vars)
{
	printf("Exit window\n");
	mlx_destroy_window(vars->mlx, vars->win); // Sustituye el segundo argumento por la ventana actual
	exit(0);
	return (0); // Devolvemos 0 para salir del loop
}

int window_open(void)
{
	t_vars vars;

	// Inicializa la conexión con la gráfica
	vars.mlx = mlx_init();
	if (!vars.mlx)
	{
		write(STDERR_FILENO, "Error: MLX initialization failed\n", 33);
		return (1);
	}

	// Crea la ventana
	vars.win = mlx_new_window(vars.mlx, WIDTH, HEIGHT, "Cub3D");
	if (!vars.win)
	{
		write(STDERR_FILENO, "Error: Window creation failed\n", 30);
		return (1);
	}

	// Captura el evento de cerrar ventana con la X
	mlx_hook(vars.win, 17, 0, (void *)handle_close, &vars);

	// Captura la tecla ESC para salir
	mlx_hook(vars.win, 2, 1L << 0, (void *)handle_esc, &vars);

	// Entra en el loop de eventos de MLX
	mlx_loop(vars.mlx);

	return (0);
}
