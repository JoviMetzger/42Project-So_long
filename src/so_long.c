/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   so_long.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: jmetzger <jmetzger@student.codam.n>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/12 13:46:39 by jmetzger      #+#    #+#                 */
/*   Updated: 2023/03/03 13:01:11 by jmetzger      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// //___________________________________________
// // FOR LEAKS
// void ft_systemleaks(void)
// {
//     system("leaks -q so_long"); //remove
// }
// //  - atexit(ft_systemleaks); // USE FOR LEAKS
// //____________________________________________

//  5. check_ber_map() - check if file is a .ber
static int	check_ber_map(char *arg)
{
	int	i;

	i = 0;
	if (!arg)
		return (0);
	while (arg[i])
		i++;
	i = i - 1;
	if (arg[i] == 'r' && arg[i - 1] == 'e' && \
			arg[i - 2] == 'b' && arg[i - 3] == '.')
		return (1);
	return (0);
}

//  4. copy_map() - makes a copy of the original map for later use;
char	**copy_map(t_game *game)
{
	char	**map;

	map = ft_split(game->map_copy, '\n');
	if (!map)
		return (NULL);
	return (map);
}

//	3. second part of open_read_map();
char	*open_read_two(int fd)
{
	char	*tmp;
	char	*line;
	char	*map;

	line = "";
	map = ft_strdup("");
	while (line)
	{
		line = get_next_line(fd);
		if (line == NULL || line[0] == '\n')
			break ;
		tmp = ft_strjoin(map, line);
		if (!tmp)
			exit(0);
		free(map);
		free(line);
		map = tmp;
	}
	free(line);
	return (map);
}

//  2. open_read_map() - opens + converts file into a 2d array
char	**open_read_map(t_game *game, char *argv)
{
	int		fd;
	char	*map;
	char	**two_d_map;

	fd = open(argv, O_RDONLY);
	if (fd == -1)
		exit(0);
	map = open_read_two(fd);
	close(fd);
	game->map_copy = ft_strdup(map);
	if (map[0] == '\0')
	{
		write(1, "Error\nMap is empty\n", 20);
		exit(0);
	}
	two_d_map = ft_split(map, '\n');
	if (!two_d_map)
	{
		free(map);
		return (NULL);
	}
	free(map);
	return (two_d_map);
}

//  1. main();
int	main(int argc, char **argv)
{
	char	**copy;
	t_game	*game;

	game = (t_game *)ft_calloc(sizeof(t_game), 1);
	if (!game)
		exit(0);
	if (argc == 2)
	{
		if (check_ber_map(argv[1]) != 1)
		{
			write(1, "Error!\nDoesn't compile with .ber\n", 34);
			exit (0);
		}
		game->map = open_read_map(game, argv[1]);
		copy = copy_map(game);
		check_map_valid(game, game->map, copy);
		ft_free(copy);
		open_window(game);
		ft_free(game->map);
	}
	else
		write(1, "Error!\nOnly 2 argumments are valid!\n", 37);
	free(game);
	return (0);
}
