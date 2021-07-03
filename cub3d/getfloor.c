/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getfloor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sglass <sglass@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/09 14:47:47 by sglass            #+#    #+#             */
/*   Updated: 2021/01/21 22:14:04 by sglass           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	getfloors3(char *map, t_collect *collect)
{
	int i;

	i = 1;
	while (map[i] == ' ')
		i++;
	if (map[i] >= '0' && map[i] <= '9')
		collect->squire.floorr = ft_atoi(&map[i]);
	while (map[i] >= '0' && map[i] <= '9')
		i++;
	while (map[i] == ' ' || map[i] == ',')
		i++;
	if (map[i] >= '0' && map[i] <= '9')
		collect->squire.floorg = ft_atoi(&map[i]);
	while (map[i] >= '0' && map[i] <= '9')
		i++;
	while (map[i] == ' ' || map[i] == ',')
		i++;
	if (map[i] >= '0' && map[i] <= '9')
		collect->squire.floorb = ft_atoi(&map[i]);
	collect->squire.flagfloor++;
}

int		getfloors2(char *map)
{
	int i;
	int counter;

	i = 0;
	counter = 0;
	while (map[i] != '\0')
	{
		i = i + scipspaces(&map[i]);
		if (map[i] >= '0' && map[i] <= '9' && counter < 3)
			counter++;
		else
			return (1);
		while (map[i] >= '0' && map[i] <= '9')
			i++;
		i = i + scipspaces(&map[i]);
		if (counter < 3)
		{
			if (map[i] == ',')
				i++;
			else
				return (1);
		}
	}
	return (0);
}

void	getfloors1(char *map, t_collect *collect, t_errors *errors)
{
	int i;
	int flag;

	i = 0;
	flag = 0;
	if (map[i] == 'F' && map[i + 1] == ' ')
	{
		flag = getfloors2(&map[i + 1]);
	}
	else
		errors->floorerr = 1;
	if (flag == 0)
		getfloors3(map, collect);
	else
		errors->floorerr = 1;
}

int		scipspaces(char *map)
{
	int i;

	i = 0;
	while (map[i] == ' ')
		i++;
	return (i);
}
