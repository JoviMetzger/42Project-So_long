/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   check_map_valid.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: jmetzger <jmetzger@student.codam.n>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/15 02:33:00 by jmetzger      #+#    #+#                 */
/*   Updated: 2024/04/13 15:37:17 by jmetzger      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

//  5. map_rectangle() - is it a rectangle;
static void	map_rectangle(char **map)
{
	int	i;

	i = 0;
	if (!map)
		exit (0);
	while (map[i] != (void *)0)
	{
		if (ft_strlen(map[i]) != ft_strlen(map[0]))
		{
			write(1, "Error!\nMap is not rectangle\n", 28);
			exit (0);
		}
		i++;
	}
}

//  4. check_char() - checks that the map has only these characters (P,E,C,0,1)
static void	check_char(char **map)
{
	int	x;
	int	y;

	y = 0;
	if (!map)
		exit(0);
	while (map[y] != (void *)0)
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] != '1' && map[y][x] != '0' && map[y][x] != 'C' \
					&& map[y][x] != 'P' && map[y][x] != 'E')
			{
				write(1, "Error!\nMap is not correct\n", 26);
				exit (0);
			}
			x++;
		}
		y++;
	}
}

//  3. amount_of_char() - counts your player, exit, collectibales
//     Player == 1, Exit == 1, Colectibales >= 1;
static int	amount_of_char(t_game *game, char **map)
{
	int	x;
	int	y;

	y = -1;
	while (map[++y] != (void *)0)
	{
		x = -1;
		while (map[y][++x])
		{
			if (map[y][x] == 'C')
				game->count_c++;
			if (map[y][x] == 'P')
			{
				game->count_p++;
				game->p_position_x = x;
				game->p_position_y = y;
			}
			if (map[y][x] == 'E')
				game->count_e++;
		}
	}
	if (!(game->count_e == 1 && game->count_p == 1 && game->count_c >= 1))
		return (1);
	return (0);
}

//  2. map_surrounded_wall() - checks if the map is surrounded by '1'
static int	map_surrounded_wall(char **map)
{
	int	x;
	int	y;
	int	len_y;

	y = 0;
	len_y = 0;
	if (!map)
		exit(0);
	while (map[len_y])
		len_y++;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (!(map[0][x] == '1' && map[len_y - 1][x] == '1'))
				return (1);
			x++;
		}
		if (!(map[y][0] == '1' && map[y][ft_strlen(map[y]) - 1] == '1'))
			return (1);
		y++;
	}
	return (0);
}

//  1. Doing all the checks for map validation
//  NOTE: use a copy of the original map
void	check_map_valid(t_game *game, char **map, char **copy)
{
	map_rectangle(map);
	check_char(map);
	if (amount_of_char(game, map) == 1)
	{
		write(1, "Error\nPlease check your charactes;\nP, E, C\n", 43);
		exit(0);
	}
	if (map_surrounded_wall(map) == 1)
	{
		write(1, "Error\nMap not surrounded by walls\n", 34);
		exit(0);
	}
	flood_fill(game, copy, game->p_position_x, game->p_position_y);
	if (!game->exit_reachable || !game->collect_reachable)
	{
		write(1, "Error\nMap has no valid path\n", 28);
		exit(0);
	}
}
