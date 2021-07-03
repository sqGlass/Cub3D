/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validmap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sglass <sglass@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/09 13:09:34 by sglass            #+#    #+#             */
/*   Updated: 2021/01/21 22:28:00 by sglass           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	validmap(char **map, t_collect *collect, t_errors *errors)
{
	int i;
	int j;
	int countlines;

	i = 0;
	j = 0;
	if (countparameters(collect) != 8)
		errors->haserr = 1;
	while (map[i][j] != '\0')
	{
		if (map[i][j] != '1' && map[i][j] != ' ')
		{
			errors->firstlineerr = 1;
			return ;
		}
		j++;
	}
	countlines = checkemptylines(&map[0], errors);
	checksymbols(&map[0], collect, errors);
	checksurround(&map[0], countlines, errors);
	countsprites(&map[0], collect, errors);
}

int		countparameters(t_collect *collect)
{
	if (collect->squire.flagceilling == 1 &&
		collect->squire.flageasttexture == 1 &&
		collect->squire.flagfloor == 1 &&
		collect->squire.flagnorthtexture == 1 &&
		collect->squire.flagrender == 1 &&
		collect->squire.flagwesttexture == 1 &&
		collect->squire.flagsouthtexture == 1 &&
		collect->squire.flagspritetexture == 1)
		return (8);
	else
		return (1);
}

int		checkemptylines(char **map, t_errors *errors)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (map[i])
	{
		if (map[i][j] == '\0' || map[i][j] == '\n')
		{
			errors->lastlineerr = 1;
			return (1);
		}
		i++;
	}
	return (i);
}

void	checksymbols(char **m, t_collect *collect, t_errors *errors)
{
	int i;
	int j;

	i = -1;
	while (m[++i])
	{
		j = -1;
		while (m[i][++j] != '\0')
		{
			if (m[i][j] != ' ' && m[i][j] != '1' && m[i][j] != '2' &&
				m[i][j] != 'N' && m[i][j] != 'S' && m[i][j] != 'W' &&
				m[i][j] != 'E' && m[i][j] != '0')
				errors->mapsymbolerr = 1;
			if (m[i][j] == 'N' || m[i][j] == 'S' ||
				m[i][j] == 'W' || m[i][j] == 'E')
			{
				collect->squire.player = m[i][j];
				collect->squire.xplayer = i;
				collect->squire.yplayer = j;
				collect->squire.countplayer++;
			}
		}
	}
}

void	checksurround(char **map, int countlines, t_errors *errors)
{
	int i;
	int j;

	i = 0;
	while (++i < countlines)
	{
		j = -1;
		while (map[i][++j] != '\0')
		{
			if (map[i][j] != '1' && map[i][j] != ' ')
			{
				if ((map[i][j - 1] == ' ' || map[i][j - 1] == '\0') ||
					(map[i][j + 1] == ' ' || map[i][j + 1] == '\0') ||
					(map[i - 1][j] == ' ' || map[i - 1][j] == '\0') ||
					(map[i - 1][j - 1] == ' ' || map[i - 1][j - 1] == '\0') ||
					(map[i - 1][j + 1] == ' ' || map[i - 1][j + 1] == '\0') ||
					(map[i + 1][j] == ' ' || map[i + 1][j] == '\0') ||
					(map[i + 1][j - 1] == ' ' || map[i + 1][j - 1] == '\0') ||
					(map[i + 1][j + 1] == ' ' || map[i + 1][j + 1] == '\0'))
					errors->surrounderr = 1;
			}
		}
	}
}
