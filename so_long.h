/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbruggem <fbruggem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 12:29:36 by fbruggem          #+#    #+#             */
/*   Updated: 2022/05/11 11:27:34 by fbruggem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include <stddef.h>
# include <fcntl.h>
// TESTING INCLUDES
# include <stdio.h>

# include "includes/get_next_line/get_next_line.h"
# include "includes/libft/libft.h"
# include "includes/minilibx/mlx.h"
# include "includes/printf/printf.h"

// Structs
typedef struct s_position
{
	int		x;
	int		y;
}				t_position;

typedef struct s_map
{
	char	**tiles;
	int		width;
	int		height;
	int		range;
}				t_map;
typedef struct s_game
{
	t_map		map;
	t_position	position;
	int			steps;

	void		*mlx;
	void		*win;

	int			(*init)(void *, char *);
	void		(*render)(void *);
	int			(*update_position)(void *);
	int			(*get_remaining_collectibles)(void *);

}				t_game;

// Map
t_game	*game_constructor(void);
int		game_init(t_game *game, char *path);
int		game_init_map(t_game *game, char *path);
int		game_init_hooks(t_game *game);

// Utils
void	delet_game(t_game *game);
int		game_update_position(t_game *game);
int		check_path(char *path, int fd);
int		check_map(t_map *map);
int		get_collectibles_count(t_game *game);

int		game_render(t_game *game);
int		helper_init_map(t_game *game);

#endif