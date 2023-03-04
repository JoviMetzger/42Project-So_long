/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   render_map.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jmetzger <jmetzger@student.codam.n>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/15 02:35:47 by jmetzger      #+#    #+#                 */
/*   Updated: 2023/02/14 13:19:34 by jmetzger      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

//  4. load_img() - saves the image to its asigned struct
void	load_img(t_game *game)
{
	game->img_wall = convert_img(game, WALL);
	game->img_exit = convert_img(game, EXIT);
	game->img_player = convert_img(game, PLAYER);
	game->img_collect = convert_img(game, COLLECT);
	game->img_floor = convert_img(game, FLOOR);
	game->img_p_l = convert_img(game, P_LEFT);
	game->img_p_r = convert_img(game, P_RIGHT);
}

//  3. *cconvert_img() - uses MLX to convert the img, 
//     so it can be used later in the window
void	*convert_img(t_game *game, char *path)
{
	if (!path)
	{
		write(1, "Error\nThere is no image to load!\n", 33);
		exit(0);
	}
	game->texture = mlx_load_png(path);
	if (!game->texture)
		exit(0);
	game->img = mlx_texture_to_image(game->mlx, game->texture);
	if (!game->img)
		exit(0);
	mlx_delete_texture(game->texture);
	return (game->img);
}

//  2. print_bg() - loads the backround(FLOOR) on each tile
void	print_bg(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	load_img(game);
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			mlx_image_to_window(game->mlx, game->img_floor, \
					x * PIXELS, y * PIXELS);
			x++;
		}
		y++;
	}
}

//  1. map_render() - loops through the map and places the right img
//     on the right character (P, E, C, 0, 1);
void	map_render(t_game *game)
{
	int	x;
	int	y;

	y = -1;
	print_bg(game);
	while (game->map[++y])
	{
		x = -1;
		while (game->map[y][++x])
		{
			if (game->map[y][x] == '1')
				mlx_image_to_window(game->mlx, game->img_wall, \
						x * PIXELS, y * PIXELS);
			if (game->map[y][x] == 'E')
				mlx_image_to_window(game->mlx, game->img_exit, \
						x * PIXELS, y * PIXELS);
			if (game->map[y][x] == 'C')
				mlx_image_to_window(game->mlx, game->img_collect, \
						x * PIXELS, y * PIXELS);
			if (game->map[y][x] == 'P')
				mlx_image_to_window(game->mlx, game->img_player, \
						x * PIXELS, y * PIXELS);
		}
	}
}
