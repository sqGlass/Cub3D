/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sglass <sglass@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 16:50:48 by sglass            #+#    #+#             */
/*   Updated: 2021/01/21 21:58:02 by sglass           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	floors(t_collect *collect)
{
	if (collect->img.side == 0 && collect->img.raydirx > 0)
	{
		collect->img.floorxwall = collect->img.mapx;
		collect->img.floorywall = collect->img.mapy + collect->img.wallx;
	}
	else if (collect->img.side == 0 && collect->img.raydirx < 0)
	{
		collect->img.floorxwall = collect->img.mapx + 1.0;
		collect->img.floorywall = collect->img.mapy + collect->img.wallx;
	}
	else if (collect->img.side == 1 && collect->img.raydiry > 0)
	{
		collect->img.floorxwall = collect->img.mapx + collect->img.wallx;
		collect->img.floorywall = collect->img.mapy;
	}
	else
	{
		collect->img.floorxwall = collect->img.mapx + collect->img.wallx;
		collect->img.floorywall = collect->img.mapy + 1.0;
	}
	collect->img.distwall = collect->img.perpwalldist;
	collect->img.distplayer = 0.0;
	if (collect->img.drawend < 0)
		collect->img.drawend = collect->squire.yrender;
	floors2(collect);
}

void	floors2(t_collect *collect)
{
	collect->img.y = collect->img.drawend + 1;
	while (collect->img.y < collect->squire.yrender)
	{
		collect->img.currentdist = collect->squire.yrender /
		(2.0 * collect->img.y - collect->squire.yrender);
		collect->img.weight = (collect->img.currentdist - collect->
		img.distplayer) / (collect->img.distwall - collect->img.distplayer);
		collect->img.currentfloorx = collect->img.weight * collect->
		img.floorxwall + (1.0 - collect->img.weight) * collect->img.posx;
		collect->img.currentfloory = collect->img.weight * collect->
		img.floorywall + (1.0 - collect->img.weight) * collect->img.posy;
		my_mlx_pixel_put(collect, collect->img.x, collect->img.y,
		((collect->squire.floorr & 0xff) << 16) + ((collect->
		squire.floorg & 0xff) << 8) + (collect->squire.floorb & 0xff));
		my_mlx_pixel_put(collect, collect->img.x,
		collect->squire.yrender - collect->img.y, ((collect->
		squire.ceillingr & 0xff) << 16) + ((collect->squire.ceillingg
		& 0xff) << 8) + (collect->squire.ceillingb & 0xff));
		collect->img.y++;
	}
}
