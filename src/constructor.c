/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   constructor.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbruggem <fbruggem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 13:22:20 by fbruggem          #+#    #+#             */
/*   Updated: 2022/06/16 19:33:47 by fbruggem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

t_game	*game_constructor(void)
{
	t_game	*game;

	game = ft_calloc(1, sizeof(t_game));
	if (!game)
		return (NULL);
	game->map.range = 4;
	game->steps = 0;
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, (game->map.range * 2 + 1) * 64,
			(game->map.range * 2 + 1) * 64, "So_Long");
	game->init = (int (*)(void *, char *)) & game_init;
	game->update_position = (int (*)(void *)) & game_update_position;
	game->render = (void (*)(void *)) & game_render;
	game->get_remaining_collectibles
		= (int (*)(void *)) & get_collectibles_count;
	return (game);
}
