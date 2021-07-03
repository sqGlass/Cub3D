/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arraysprite.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sglass <sglass@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 15:12:52 by sglass            #+#    #+#             */
/*   Updated: 2021/01/21 22:50:09 by sglass           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	takepossprites(char **map, t_collect *collect)
{
	int i;
	int j;
	int m;

	i = -1;
	m = 0;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j] != '\0')
		{
			if (map[i][j] == '2')
			{
				collect->squire.sprites[m][0] = i;
				collect->squire.sprites[m][1] = j;
				m++;
			}
		}
	}
}

void	mallocsprites(char **map, t_collect *col, t_errors *err, int count)
{
	int i;

	i = 0;
	col->squire.sprites = (int**)malloc(count * sizeof(int*));
	if (col->squire.sprites == NULL)
	{
		err->haserr = 1;
		return ;
	}
	while (i < count)
	{
		col->squire.sprites[i] = (int*)malloc(2 * sizeof(int));
		if (col->squire.sprites[i] == NULL)
		{
			err->haserr = 1;
			return ;
		}
		i++;
	}
	takepossprites(&map[0], col);
}

void	countsprites(char **map, t_collect *collect, t_errors *errors)
{
	int i;
	int j;

	i = -1;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j] != '\0')
		{
			if (map[i][j] == '2')
				collect->squire.numsprites++;
		}
	}
	if (collect->squire.numsprites != 0)
	{
		mallocsprites(&map[0], collect, errors, collect->squire.numsprites);
	}
}
