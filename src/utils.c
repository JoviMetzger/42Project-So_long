/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: jmetzger <jmetzger@student.codam.n>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/10 14:37:43 by jmetzger      #+#    #+#                 */
/*   Updated: 2023/02/15 11:26:46 by jmetzger      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// EXTRA FUNCTION FOR FREE;
void	ft_free(char **map)
{
	while (*map)
	{
		free(*map);
		map++;
	}
	return ;
}

//  FLOOD_FILL() - CHECKS IF MAP IS VALID;
//  - is exit reachable; - are all collectibales reachable;
//  NOTE: use copy of map otherwise it will fill map with '1';
void	flood_fill(t_game *game, char **map, int x, int y)
{
	static int	collect;

	if (map[y][x] == '1')
		return ;
	if (map[y][x] == 'E')
	{
		game->exit_reachable = true;
		return ;
	}
	if (map[y][x] == 'C')
	{
		collect++;
		if (collect == game->count_c)
			game->collect_reachable = true;
	}
	map[y][x] = '1';
	flood_fill(game, map, x + 1, y);
	flood_fill(game, map, x - 1, y);
	flood_fill(game, map, x, y + 1);
	flood_fill(game, map, x, y - 1);
}

//  COUNT_PRINT_MOVES() - COUNTS MOVES AND DISPLAYS THEM ON WINDOW AND TERMINAL;
void	count_print_moves(t_game *game)
{
	char		*step;
	static int	count_moves;

	count_moves++;
	if (game->text)
		mlx_delete_image(game->mlx, game->text);
	step = ft_itoa(count_moves);
	if (!step)
		exit(0);
	game->text = mlx_put_string(game->mlx, step, 55, 5);
	free(step);
	ft_printf("Moves: %d\n", count_moves);
}

//  CHECK_COLLECT() - CHECKS IF YOU COLLECTED ALL COLLECTABILS BEFORE EXIT;
void	check_collect(t_game *game)
{
	if (game->count_c == 0)
	{
		write(1, "Congratilations! You win!\n", 26);
		ft_free(game->map);
		exit (EXIT_SUCCESS);
	}
	else
	{
		game->text_collect = mlx_put_string(game->mlx, "You didn't collect \
				everything!", game->p_position_x * PIXELS, game->p_position_y \
				* PIXELS + 55);
		write(1, "You didn't collect everything!\n", 31);
	}
}

void	change_img(t_game *game, char c, int x, int y)
{
	if (c == 'a')
		mlx_image_to_window(game->mlx, game->img_p_l, x * PIXELS, y * PIXELS);
	if (c == 'd')
		mlx_image_to_window(game->mlx, game->img_p_r, x * PIXELS, y * PIXELS);
	if (c == 'w')
		mlx_image_to_window(game->mlx, game->img_player, x * PIXELS, \
				y * PIXELS);
	if (c == 's')
		mlx_image_to_window(game->mlx, game->img_player, x * PIXELS, \
				y * PIXELS);
}
