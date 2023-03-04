/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   make_window.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: jmetzger <jmetzger@student.codam.n>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/15 03:25:22 by jmetzger      #+#    #+#                 */
/*   Updated: 2023/02/14 11:42:28 by jmetzger      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

//  2. size_window() - count map to adjust the window size to the map;
//     NOTE: map is made of 64x64 tiles; - number of pixels in a tile;
static void	size_window(t_game *game)
{
	int	i;

	game->map_width = ft_strlen(game->map[0]) * PIXELS;
	i = 0;
	while (game->map[i] != '\0')
		i++;
	game->map_height = i * PIXELS;
}

//  1. open_window() - uses MLX to open a window and 
//     displays images and do key commands;
void	open_window(t_game *game)
{
	size_window(game);
	game->mlx = mlx_init(game->map_width, game->map_height, "so_long", true);
	if (!game->mlx)
		exit(0);
	game->img = mlx_new_image(game->mlx, game->map_width, game->map_height);
	map_render(game);
	mlx_key_hook(game->mlx, (mlx_keyfunc)key_action, game);
	mlx_loop(game->mlx);
	mlx_terminate(game->mlx);
}
