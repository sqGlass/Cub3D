/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getresolutionandceil.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sglass <sglass@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/09 14:30:38 by sglass            #+#    #+#             */
/*   Updated: 2021/01/22 21:11:28 by sglass           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	getreso2(char *map, t_collect *collect)
{
	int i;

	i = 1;
	while (map[i] == ' ')
		i++;
	if (map[i] >= '0' && map[i] <= '9')
		collect->squire.xrender = ft_atoi(&map[i]);
	while (map[i] >= '0' && map[i] <= '9')
		i++;
	while (map[i] == ' ')
		i++;
	if (map[i] >= '0' && map[i] <= '9')
		collect->squire.yrender = ft_atoi(&map[i]);
	collect->squire.flagrender++;
	if (collect->squire.xrender <= 0 || collect->squire.yrender <= 0)
	{
		write(1, "Error\n", 6);
		exit(0);
	}
	collect->squire.xrender > 2560 ? collect->squire.xrender = 2560 : 0;
	collect->squire.xrender < 100 ? collect->squire.xrender = 100 : 0;
	collect->squire.yrender > 1440 ? collect->squire.yrender = 1440 : 0;
	collect->squire.yrender < 100 ? collect->squire.yrender = 100 : 0;
}

void	getreso1(char *map, t_collect *collect, t_errors *errors)
{
	int i;
	int counter;

	i = 0;
	counter = 0;
	if (map[i] == 'R' && map[i + 1] == ' ')
	{
		i++;
		while (map[i] != '\0')
		{
			while (map[i] == ' ')
				i++;
			if (map[i] >= '0' && map[i] <= '9')
			{
				counter++;
				while (map[i] >= '0' && map[i] <= '9')
					i++;
			}
			else
				break ;
		}
		if (map[i] != '\0' || counter != 2)
			errors->rendererr = 1;
		getreso2(map, collect);
	}
}

void	getceill3(char *map, t_collect *collect)
{
	int i;

	i = 1;
	while (map[i] == ' ')
		i++;
	if (map[i] >= '0' && map[i] <= '9')
		collect->squire.ceillingr = ft_atoi(&map[i]);
	while (map[i] >= '0' && map[i] <= '9')
		i++;
	while (map[i] == ' ' || map[i] == ',')
		i++;
	if (map[i] >= '0' && map[i] <= '9')
		collect->squire.ceillingg = ft_atoi(&map[i]);
	while (map[i] >= '0' && map[i] <= '9')
		i++;
	while (map[i] == ' ' || map[i] == ',')
		i++;
	if (map[i] >= '0' && map[i] <= '9')
		collect->squire.ceillingb = ft_atoi(&map[i]);
	collect->squire.flagceilling++;
}

int		getceill2(char *map)
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

void	getceill1(char *map, t_collect *collect, t_errors *errors)
{
	int i;
	int flag;

	i = 0;
	flag = 0;
	if (map[i] == 'C' && map[i + 1] == ' ')
	{
		flag = getceill2(&map[i + 1]);
	}
	else
		errors->ceillingerr = 1;
	if (flag == 0)
		getceill3(map, collect);
	else
		errors->ceillingerr = 1;
}
