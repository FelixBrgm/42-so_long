/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbruggem <fbruggem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 16:10:11 by fbruggem          #+#    #+#             */
/*   Updated: 2022/05/11 11:40:55 by fbruggem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

typedef struct s_vars
{
	int	e;
	int	p;
	int	c;
	int	i;
	int	j;
}				t_vars;

static int	check_rect(char **structure);
static int	check_places(char **structure);

int	game_init_map(t_game *game, char *path)
{
	int		fd;
	char	*temp_tiles;
	char	*buf;

	fd = open(path, O_RDONLY);
	if (check_path(path, fd))
		return (-1);
	temp_tiles = NULL;
	buf = "";
	while (buf)
	{
		temp_tiles = ft_strjoin_free(temp_tiles, buf);
		buf = get_next_line(fd);
	}
	close(fd);
	game->map.tiles = ft_split(temp_tiles, '\n');
	if (temp_tiles)
		free(temp_tiles);
	return (helper_init_map(game));
}

int	check_map(t_map *map)
{
	int	is_ok;

	is_ok = 0;
	if (check_rect(map->tiles) == 0)
		is_ok = 1;
	if (check_places(map->tiles) == 0)
		is_ok = 1;
	return (is_ok);
}

static void	helper(char **structure, int *is_ok)
{
	size_t	temp;
	int		x;
	int		y;

	x = ft_strlen(structure[0]) - 1;
	y = 0;
	while (structure[y])
	{
		if (structure[y][0] != '1')
			*is_ok = 0;
		if (structure[y][x] != '1')
			*is_ok = 0;
		y++;
	}
	y = 0;
	temp = ft_strlen(structure[0]);
	while (structure[y])
	{
		if (ft_strlen(structure[y]) != temp)
			*is_ok = 0;
		temp = ft_strlen(structure[y]);
		y++;
	}
}

static int	check_rect(char **structure)
{
	int		x;
	int		y;
	int		is_ok;

	if (!structure)
		return (0);
	x = 0;
	while (structure[0][x] != '\0')
	{
		if (structure[0][x] != '1')
			is_ok = 0;
		x++;
	}
	x = 0;
	y = ft_2ptrlen((void **) structure) - 1;
	while (structure[y][x])
	{
		if (structure[y][x] != '1')
			is_ok = 0;
		x++;
	}
	helper(structure, &is_ok);
	return (is_ok);
}

static int	check_places(char **structure)
{
	t_vars	vars;

	vars.e = 0;
	vars.c = 0;
	vars.p = 0;
	vars.j = 0;
	vars.i = 0;
	while (*structure)
	{
		vars.i = 0;
		while (structure[vars.j][vars.i])
		{
			if (structure[vars.j][vars.i] == 'E')
				vars.e = 1;
			if (structure[vars.j][vars.i] == 'P')
				vars.p++;
			if (structure[vars.j][vars.i] == 'C')
				vars.c = 1;
			vars.i++;
		}
		structure++;
	}
	if (vars.e && vars.p == 1 && vars.c)
		return (1);
	return (0);
}
