/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gamecalc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sglass <sglass@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 12:49:41 by sglass            #+#    #+#             */
/*   Updated: 2021/01/22 17:17:26 by sglass           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	movement(t_collect *collect)
{
	collect->img.camerax = (2 * collect->img.x) /
	(double)collect->squire.xrender - 1;
	collect->img.raydirx = collect->img.dirx + collect->img.planex *
	collect->img.camerax;
	collect->img.raydiry = collect->img.diry + collect->img.planey *
	collect->img.camerax;
	collect->img.mapx = (int)collect->img.posx;
	collect->img.mapy = (int)collect->img.posy;
	collect->img.deltadistx = fabs(1 / collect->img.raydirx);
	collect->img.deltadisty = fabs(1 / collect->img.raydiry);
	collect->img.hit = 0;
}

void	calcstep(t_collect *collect)
{
	if (collect->img.raydirx < 0)
	{
		collect->img.stepx = -1;
		collect->img.sidedistx = (collect->img.posx - collect->img.mapx)
		* collect->img.deltadistx;
	}
	else
	{
		collect->img.stepx = 1;
		collect->img.sidedistx = (collect->img.mapx + 1.0 - collect->img.posx)
		* collect->img.deltadistx;
	}
	if (collect->img.raydiry < 0)
	{
		collect->img.stepy = -1;
		collect->img.sidedisty = (collect->img.posy - collect->img.mapy)
		* collect->img.deltadisty;
	}
	else
	{
		collect->img.stepy = 1;
		collect->img.sidedisty = (collect->img.mapy + 1.0 - collect->img.posy)
		* collect->img.deltadisty;
	}
}

void	checkhit(t_collect *collect)
{
	while (collect->img.hit == 0)
	{
		if (collect->img.sidedistx < collect->img.sidedisty)
		{
			collect->img.sidedistx += collect->img.deltadistx;
			collect->img.mapx += collect->img.stepx;
			collect->img.side = 0;
		}
		else
		{
			collect->img.sidedisty += collect->img.deltadisty;
			collect->img.mapy += collect->img.stepy;
			collect->img.side = 1;
		}
		if (collect->squire.tmap[collect->img.mapx][collect->img.mapy] == '1')
			collect->img.hit = 1;
	}
}

void	camdist(t_collect *collect)
{
	if (collect->img.side == 0)
		collect->img.perpwalldist = (collect->img.mapx - collect->img.posx +
		(1 - collect->img.stepx) / 2) / collect->img.raydirx;
	else
		collect->img.perpwalldist = (collect->img.mapy - collect->img.posy +
		(1 - collect->img.stepy) / 2) / collect->img.raydiry;
}

void	game_engine(t_collect *collect)
{
	double zbuffer[collect->squire.xrender];

	collect->img.x = 0;
	while (collect->img.x < collect->squire.xrender)
	{
		movement(collect);
		calcstep(collect);
		checkhit(collect);
		camdist(collect);
		calclineheight(collect);
		if (collect->img.mapx < collect->img.posx && collect->img.side == 0)
			ntext(collect);
		if (collect->img.side == 1 && collect->img.mapy < collect->img.posy)
			wtext(collect);
		if (collect->img.side == 1 && collect->img.mapy > collect->img.posy)
			etext(collect);
		if (collect->img.mapx > collect->img.posx && collect->img.side == 0)
			stext(collect);
		floors(collect);
		zbuffer[collect->img.x] = collect->img.perpwalldist;
		collect->img.x++;
	}
	sorter(collect);
	sprites(collect, zbuffer);
}
