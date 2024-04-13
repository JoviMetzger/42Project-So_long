/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   so_long.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: jmetzger <jmetzger@student.codam.n>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/20 12:18:35 by jmetzger      #+#    #+#                 */
/*   Updated: 2024/04/13 15:32:52 by jmetzger      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libraries/libft/libft.h"
# include "../libraries/mlx42/include/MLX42/MLX42.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <memory.h>
# include <fcntl.h>

# define WALL "./graphics/textures/wall.png"
# define PLAYER "./graphics/textures/player.png"
# define COLLECT "./graphics/textures/collect.png"
# define EXIT "./graphics/textures/exit.png"
# define FLOOR "./graphics/textures/floor.png"
# define P_LEFT "./graphics/textures/p_left.png"
# define P_RIGHT "./graphics/textures/p_right.png"
# define PIXELS 64

typedef struct to_data
{
	mlx_texture_t	*texture;
	mlx_image_t		*img;
	mlx_image_t		*text;
	mlx_image_t		*text_collect;
	mlx_t			*mlx;
	char			**map;
	char			*map_copy;
	void			*window;
	void			*img_wall;
	void			*img_player;
	void			*img_p_l;
	void			*img_p_r;
	void			*img_collect;
	void			*img_exit;
	void			*img_floor;
	int				map_height;
	int				map_width;
	int				p_position_x;
	int				p_position_y;
	int				count_c;
	int				count_p;
	int				count_e;
	bool			exit_reachable;
	bool			collect_reachable;
}	t_game;

int		main(int argc, char **argv);
char	**open_read_map(t_game *game, char *argv);
void	check_map_valid(t_game *game, char **map, char **copy);
void	open_window(t_game *game);
void	map_render(t_game *game);
void	*convert_img(t_game *game, char *path);
void	load_img(t_game *game);
void	key_action(mlx_key_data_t keydata, t_game *game);
void	flood_fill(t_game *game, char **map, int x, int y);
void	count_print_moves(t_game *game);
void	check_collect(t_game *game);
void	ft_free(char **map);
void	char_render(t_game *game, int x, int y);
void	change_img(t_game *game, char c, int x, int y);

#endif
