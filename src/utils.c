/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbruggem <fbruggem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 13:24:10 by fbruggem          #+#    #+#             */
/*   Updated: 2022/05/11 11:16:07 by fbruggem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	game_update_position(t_game *game)
{
	t_position	pos;

	if (game->map.tiles)
	{
		pos.y = 0;
		while (game->map.tiles[pos.y])
		{
			pos.x = 0;
			while (game->map.tiles[pos.y][pos.x])
			{
				if (game->map.tiles[pos.y][pos.x] == 'P')
				{
					game->position = pos;
					return (0);
				}
				pos.x++;
			}
			pos.y++;
		}
	}
	return (-1);
}

void	delet_game(t_game *game)
{
	int	i;

	i = 0;
	mlx_destroy_window(game->mlx, game->win);
	while (game->map.tiles[i])
	{
		free(game->map.tiles[i]);
		i++;
	}
	free(game->map.tiles);
	free(game);
}

int	check_path(char *path, int fd)
{
	char	*buf;

	buf = path + ft_strlen(path) - 4;
	if (ft_strncmp(buf, ".ber", 4))
		return (-1);
	if (read(fd, NULL, 0) < 0)
		return (-1);
	return (0);
}

int	get_collectibles_count(t_game *game)
{
	int	count;
	int	x;
	int	y;

	count = 0;
	y = 0;
	if (!game)
		return (count);
	while (game->map.tiles[y])
	{
		x = 0;
		while (game->map.tiles[y][x])
		{
			if (game->map.tiles[y][x] == 'C')
				count++;
			x++;
		}
		y++;
	}
	return (count);
}

int	helper_init_map(t_game *game)
{
	if (check_map(&game->map))
	{
		delet_game(game);
		return (-1);
	}
	game->map.height = ft_2ptrlen((void **)game->map.tiles);
	game->map.width = ft_strlen(game->map.tiles[0]);
	return (0);
}
