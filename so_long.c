/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbruggem <fbruggem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 13:16:27 by fbruggem          #+#    #+#             */
/*   Updated: 2022/06/28 14:42:41 by fbruggem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_game	*game;
	int		i;

	i = argc;
	if (argc != 2)
		exit(1);
	game = game_constructor();
	if (!game)
	{
		printf("Error\nError at creation\n");
		return (1);
	}
	if (game->init(game, argv[1]))
	{
		printf("Error\nError at map parsing\n");
		return (1);
	}
}
