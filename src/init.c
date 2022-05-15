/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbruggem <fbruggem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 13:31:15 by fbruggem          #+#    #+#             */
/*   Updated: 2022/05/11 10:49:30 by fbruggem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	game_init(t_game *game, char *path)
{
	if (game_init_map(game, path))
		return (-1);
	if (game_init_hooks(game))
		return (-1);
	game->render(game);
	mlx_loop(game->mlx);
	return (0);
}
