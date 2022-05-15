/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_hooks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbruggem <fbruggem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 16:14:17 by fbruggem          #+#    #+#             */
/*   Updated: 2022/05/11 10:52:37 by fbruggem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	button_pressed(int keyhook, t_game *game);
static void	move_player(t_game *game, int shift_x, int shift_y);
static int	close_window(t_game *game);

int	game_init_hooks(t_game *game)
{
	mlx_key_hook(game->win, (int (*)())button_pressed, (void *)game);
	mlx_hook(game->win, 17, 0L, close_window, game);
	return (0);
}

static void	button_pressed(int keycode, t_game *game)
{
	if (keycode == 53)
	{
		ft_printf("Game ended without success\n");
		delet_game(game);
		exit(0);
	}
	if (keycode == 13)
		move_player(game, 0, -1);
	if (keycode == 1)
		move_player(game, 0, 1);
	if (keycode == 2)
		move_player(game, 1, 0);
	if (keycode == 0)
		move_player(game, -1, 0);
}

static void	move_player(t_game *game, int shift_x, int shift_y)
{
	char	*next_tile;

	next_tile = &game->map.tiles[game->position.y + shift_y]
	[game->position.x + shift_x];
	if (*next_tile == 'E' && game->get_remaining_collectibles(game) == 0)
	{
		game->steps++;
		ft_printf("COMPLETE STEPS NEEDED: %i\n", game->steps);
		delet_game(game);
		exit(0);
	}
	if (*next_tile != '1' && *next_tile != 'E')
	{
		game->steps++;
		*next_tile = 'P';
		game->map.tiles[game->position.y][game->position.x] = '0';
	}
	ft_printf("Steps: %i\n", game->steps);
	game->update_position(game);
	game->render(game);
}

static int	close_window(t_game *game)
{
	delet_game(game);
	ft_printf("Game ended without success!\n");
	exit(1);
	return (0);
}
