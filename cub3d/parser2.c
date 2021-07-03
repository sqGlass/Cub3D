/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sglass <sglass@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/09 14:58:10 by sglass            #+#    #+#             */
/*   Updated: 2021/01/21 22:13:24 by sglass           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	finalinputvalidation(t_errors *errors)
{
	int i;

	i = 0;
	if (errors->ceillingerr == 1 || errors->easttextureerr == 1 ||
	errors->firstlineerr == 1 ||
		errors->floorerr == 1 || errors->lastlineerr == 1 ||
		errors->mapsymbolerr == 1 ||
		errors->northtextureerr == 1 || errors->rendererr == 1 ||
		errors->southtextureerr == 1 ||
		errors->spritetextureerr == 1 || errors->surrounderr == 1
		|| errors->westtextureerr == 1 || errors->haserr == 1)
	{
		errors->haserr = 1;
		write(1, "Error\n", 6);
	}
}

void	parseinputparameters2(char *map, t_collect *collect, t_errors *errors)
{
	map[0] == 'R' ? getreso1(map, collect, errors) : 0;
	map[0] == 'N' ? getnorth(map, collect, errors) : 0;
	map[0] == 'S' ? getsouth(map, collect, errors) : 0;
	map[0] == 'W' ? getwest(map, collect, errors) : 0;
	map[0] == 'E' ? geteast(map, collect, errors) : 0;
	map[0] == 'S' ? getsprite(map, collect, errors) : 0;
	map[0] == 'F' ? getfloors1(map, collect, errors) : 0;
	map[0] == 'C' ? getceill1(map, collect, errors) : 0;
}
