/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   startparser.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sglass <sglass@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/08 19:01:02 by sglass            #+#    #+#             */
/*   Updated: 2021/01/25 12:53:17 by sglass           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

char	**make_map(t_list **head, int size, int flag)
{
	char	**map;
	int		i;
	t_list	*tmp;

	i = -1;
	tmp = *head;
	map = ft_calloc(size + 1, sizeof(char *));
	if (map == NULL)
	{
		write(1, "Error\n", 6);
		write(1, "No calloc for you!", 18);
		exit(1);
	}
	while (tmp)
	{
		map[++i] = tmp->content;
		tmp = tmp->next;
	}
	processinginputparameters(map, flag);
	return (map);
}

void	processinginputparameters(char **map, int flag)
{
	t_errors	errors;
	t_collect	collect;

	collect.img.flag = flag;
	initializationsquire(&collect);
	initializationerrors(&errors);
	parseinputparameters(map, &collect, &errors);
	checkerrors1(&errors, &collect);
	checkerrors2(&errors, &collect);
	finalinputvalidation(&errors);
	if (errors.haserr != 1)
		mlxwindow(&collect);
	else
		exit(1);
}

void	initializationsquire(t_collect *collect)
{
	collect->squire.countplayer = 0;
	collect->squire.xrender = 0;
	collect->squire.yrender = 0;
	collect->squire.floorr = -1;
	collect->squire.floorg = -1;
	collect->squire.floorb = -1;
	collect->squire.ceillingr = -1;
	collect->squire.ceillingb = -1;
	collect->squire.ceillingg = -1;
	collect->squire.flagceilling = 0;
	collect->squire.flageasttexture = 0;
	collect->squire.flagsouthtexture = 0;
	collect->squire.flagnorthtexture = 0;
	collect->squire.flagwesttexture = 0;
	collect->squire.flagfloor = 0;
	collect->squire.flagrender = 0;
	collect->squire.flagspritetexture = 0;
	collect->squire.numsprites = 0;
}

void	initializationerrors(t_errors *errors)
{
	errors->haserr = 0;
	errors->rendererr = 0;
	errors->ceillingerr = 0;
	errors->easttextureerr = 0;
	errors->firstlineerr = 0;
	errors->westtextureerr = 0;
	errors->floorerr = 0;
	errors->mapsymbolerr = 0;
	errors->northtextureerr = 0;
	errors->southtextureerr = 0;
	errors->spritetextureerr = 0;
	errors->surrounderr = 0;
	errors->lastlineerr = 0;
}

void	parseinputparameters(char **map, t_collect *collect, t_errors *errors)
{
	int i;
	int j;

	i = -1;
	inittextures(collect);
	while (map[++i])
	{
		j = 0;
		while (map[i][j] == ' ')
			j++;
		if (map[i][j] == 'R' || map[i][j] == 'N' || map[i][j] == '\0' ||
			map[i][j] == 'S' || map[i][j] == 'W' || map[i][j] == 'E' ||
			map[i][j] == 'F' || map[i][j] == 'C')
			parseinputparameters2(&map[i][j], collect, errors);
		else
			break ;
	}
	validmap(&map[i], collect, errors);
	collect->squire.tmap = &map[i];
}
