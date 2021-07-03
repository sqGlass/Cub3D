/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gettextures.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sglass <sglass@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/09 14:21:52 by sglass            #+#    #+#             */
/*   Updated: 2021/01/21 22:16:00 by sglass           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	getnorth(char *map, t_collect *collect, t_errors *errors)
{
	int i;
	int start;

	i = 0;
	if (map[i + 2] != ' ')
		return ;
	i = i + 2;
	while (map[i] == ' ')
		i++;
	start = i;
	while (map[i] != ' ' && map[i] != '\0')
		i++;
	collect->squire.ntxt = ft_substr(map, start, i - start);
	if (collect->squire.ntxt == NULL)
		errorexit(collect);
	while (map[i] == ' ')
		i++;
	if (map[i] != '\0')
		errors->northtextureerr = 1;
	collect->squire.flagnorthtexture++;
}

void	getsouth(char *map, t_collect *collect, t_errors *errors)
{
	int i;
	int start;

	i = 0;
	if (map[i + 2] != ' ')
		return ;
	i = i + 2;
	while (map[i] == ' ')
		i++;
	start = i;
	while (map[i] != ' ' && map[i] != '\0')
		i++;
	collect->squire.stxt = ft_substr(map, start, i - start);
	if (collect->squire.stxt == NULL)
		errorexit(collect);
	while (map[i] == ' ')
		i++;
	if (map[i] != '\0')
		errors->southtextureerr = 1;
	collect->squire.flagsouthtexture++;
}

void	getwest(char *map, t_collect *collect, t_errors *errors)
{
	int i;
	int start;

	i = 0;
	if (map[i + 2] != ' ')
		return ;
	i = i + 2;
	while (map[i] == ' ')
		i++;
	start = i;
	while (map[i] != ' ' && map[i] != '\0')
		i++;
	collect->squire.wtxt = ft_substr(map, start, i - start);
	if (collect->squire.wtxt == NULL)
		errorexit(collect);
	while (map[i] == ' ')
		i++;
	if (map[i] != '\0')
		errors->westtextureerr = 1;
	collect->squire.flagwesttexture++;
}

void	geteast(char *map, t_collect *collect, t_errors *errors)
{
	int i;
	int start;

	i = 0;
	if (map[i + 2] != ' ')
		return ;
	i = i + 2;
	while (map[i] == ' ')
		i++;
	start = i;
	while (map[i] != ' ' && map[i] != '\0')
		i++;
	collect->squire.etxt = ft_substr(map, start, i - start);
	if (collect->squire.etxt == NULL)
		errorexit(collect);
	while (map[i] == ' ')
		i++;
	if (map[i] != '\0')
		errors->easttextureerr = 1;
	collect->squire.flageasttexture++;
}

void	getsprite(char *map, t_collect *collect, t_errors *errors)
{
	int i;
	int start;

	i = 0;
	if (map[i + 1] != ' ')
		return ;
	i++;
	while (map[i] == ' ')
		i++;
	start = i;
	while (map[i] != ' ' && map[i] != '\0')
		i++;
	collect->squire.sptxt = ft_substr(map, start, i - start);
	if (collect->squire.sptxt == NULL)
		errorexit(collect);
	while (map[i] == ' ')
		i++;
	if (map[i] != '\0')
		errors->spritetextureerr = 1;
	collect->squire.flagspritetexture++;
}
