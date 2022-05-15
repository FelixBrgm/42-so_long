/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbruggem <fbruggem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 16:20:04 by fbruggem          #+#    #+#             */
/*   Updated: 2022/05/11 11:27:54 by fbruggem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	print_tile(t_game *game, int x, int y);

int	game_render(t_game *game)
{
	int	x;
	int	y;

	y = game->position.y - game->map.range;
	while (y <= game->position.y + game->map.range)
	{
		x = game->position.x - game->map.range;
		while (x <= game->position.x + game->map.range)
		{
			print_tile(game, x, y);
			x++;
		}
		y++;
	}
	return (0);
}

static void	print_tile(t_game *game, int x, int y)
{
	char	buf[2];
	char	*path;
	void	*img;
	int		size;

	size = 64;
	if (x < 0 || y < 0)
		path = ft_strdup("./img/V.xpm");
	else if (x >= game->map.width || y >= game->map.height)
		path = ft_strdup("./img/V.xpm");
	else
	{
		buf[0] = game->map.tiles[y][x];
		buf[1] = '\0';
		path = ft_strjoin_free(ft_strdup("./img/"), ft_strjoin(buf, ".xpm"));
	}
	img = mlx_xpm_file_to_image(game->mlx, path, &size, &size);
	game->update_position(game);
	mlx_put_image_to_window(game->mlx, game->win, img, (x - game->position.x
			+ game->map.range) * 64, (y - game->position.y
			+ game->map.range) * 64);
	free(path);
}
