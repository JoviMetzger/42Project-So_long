/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   keyBoard_hooks.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: jmetzger <jmetzger@student.codam.n>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/15 02:34:01 by jmetzger      #+#    #+#                 */
/*   Updated: 2023/02/15 11:23:26 by jmetzger      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

//  4. move_up() - key action for up
static int	move_up(t_game *game)
{
	int	x;
	int	y;

	game->p_position_y--;
	x = game->p_position_x;
	y = game->p_position_y;
	if (game->text_collect)
		mlx_delete_image(game->mlx, game->text_collect);
	if (game->map[y][x] == '0' || game->map[y][x] == 'C')
	{
		if (game->map[y][x] == 'C')
			game->count_c--;
		game->map[y][x] = 'P';
		mlx_image_to_window(game->mlx, game->img_floor, x * PIXELS, y * PIXELS);
		mlx_image_to_window(game->mlx, game->img_floor, x * PIXELS, \
				(y + 1) * PIXELS);
		game->map[y + 1][x] = '0';
		change_img(game, 'w', x, y);
		count_print_moves(game);
		return (1);
	}
	if (game->map[y][x] == 'E')
		check_collect(game);
	game->p_position_y++;
	return (0);
}

//  4. move_down() - key action for down
static int	move_down(t_game *game)
{
	int	x;
	int	y;

	game->p_position_y++;
	x = game->p_position_x;
	y = game->p_position_y;
	if (game->text_collect)
		mlx_delete_image(game->mlx, game->text_collect);
	if (game->map[y][x] == '0' || game->map[y][x] == 'C')
	{
		if (game->map[y][x] == 'C')
			game->count_c--;
		game->map[y][x] = 'P';
		mlx_image_to_window(game->mlx, game->img_floor, x * PIXELS, y * PIXELS);
		mlx_image_to_window(game->mlx, game->img_floor, x * PIXELS, \
				(y - 1) * PIXELS);
		game->map[y - 1][x] = '0';
		change_img(game, 's', x, y);
		count_print_moves(game);
		return (1);
	}
	if (game->map[y][x] == 'E')
		check_collect(game);
	game->p_position_y--;
	return (0);
}

//  3. move_left() - key action for left
static int	move_left(t_game *game)
{
	int	x;
	int	y;

	game->p_position_x--;
	x = game->p_position_x;
	y = game->p_position_y;
	if (game->text_collect)
		mlx_delete_image(game->mlx, game->text_collect);
	if (game->map[y][x] == '0' || game->map[y][x] == 'C')
	{
		if (game->map[y][x] == 'C')
			game->count_c--;
		game->map[y][x] = 'P';
		mlx_image_to_window(game->mlx, game->img_floor, x * PIXELS, y * PIXELS);
		mlx_image_to_window(game->mlx, game->img_floor, \
				(x + 1) * PIXELS, y * PIXELS);
		game->map[y][x + 1] = '0';
		change_img(game, 'a', x, y);
		count_print_moves(game);
		return (1);
	}
	if (game->map[y][x] == 'E')
		check_collect(game);
	game->p_position_x++;
	return (0);
}

//  2. move_right() - key action for right
static int	move_right(t_game *game)
{
	int	x;
	int	y;

	game->p_position_x++;
	x = game->p_position_x;
	y = game->p_position_y;
	if (game->text_collect)
		mlx_delete_image(game->mlx, game->text_collect);
	if (game->map[y][x] == '0' || game->map[y][x] == 'C')
	{
		if (game->map[y][x] == 'C')
			game->count_c--;
		game->map[y][x] = 'P';
		mlx_image_to_window(game->mlx, game->img_floor, x * PIXELS, y * PIXELS);
		mlx_image_to_window(game->mlx, game->img_floor, \
				(x - 1) * PIXELS, y * PIXELS);
		game->map[y][x - 1] = '0';
		change_img(game, 'd', x, y);
		count_print_moves(game);
		return (1);
	}
	if (game->map[y][x] == 'E')
		check_collect(game);
	game->p_position_x--;
	return (0);
}

//  1. key_action() - takes key action and checks if action is possible;
//     up, down, left, right + w,a,s,d;
void	key_action(mlx_key_data_t keydata, t_game *game)
{
	if (mlx_is_key_down(game->mlx, MLX_KEY_ESCAPE))
		exit(0);
	if (mlx_is_key_down(game->mlx, MLX_KEY_UP) || \
			mlx_is_key_down(game->mlx, MLX_KEY_W))
		move_up(game);
	if (mlx_is_key_down(game->mlx, MLX_KEY_DOWN) || \
			mlx_is_key_down(game->mlx, MLX_KEY_S))
		move_down(game);
	if (mlx_is_key_down(game->mlx, MLX_KEY_LEFT) || \
			mlx_is_key_down(game->mlx, MLX_KEY_A))
		move_left(game);
	if (mlx_is_key_down(game->mlx, MLX_KEY_RIGHT) || \
			mlx_is_key_down(game->mlx, MLX_KEY_D))
		move_right(game);
	(void)keydata;
}
