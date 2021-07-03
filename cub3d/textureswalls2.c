/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textureswalls2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sglass <sglass@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 14:55:57 by sglass            #+#    #+#             */
/*   Updated: 2021/01/21 22:03:27 by sglass           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	etext2(t_collect *collect)
{
	char *dst;

	collect->img.step = 1.0 * collect->img.texhe / collect->img.lineheight;
	collect->img.texpos = (collect->img.drawstart - collect->
	squire.yrender / 2 + collect->img.lineheight / 2) * collect->img.step;
	collect->img.y = collect->img.drawstart;
	while (collect->img.y < collect->img.drawend)
	{
		collect->img.texy = (int)collect->img.texpos & (collect->img.texhe - 1);
		collect->img.texpos += collect->img.step;
		dst = collect->img.e_ad + ((collect->img.texy * collect->
		img.texhe + collect->img.texx) * (collect->img.bits_per_pixel / 8));
		collect->img.color = *(unsigned int *)dst;
		my_mlx_pixel_put(collect, collect->img.x, collect->img.y,
		collect->img.color);
		collect->img.y++;
	}
}

void	wtext(t_collect *collect)
{
	if (collect->img.side == 0)
		collect->img.wallx = collect->img.posy +
		collect->img.perpwalldist * collect->img.raydiry;
	else
		collect->img.wallx = collect->img.posx +
		collect->img.perpwalldist * collect->img.raydirx;
	collect->img.wallx -= floor((collect->img.wallx));
	collect->img.texx = (int)(collect->img.wallx * (double)collect->img.texww);
	if (collect->img.side == 0 && collect->img.raydirx > 0)
		collect->img.texx = collect->img.texww - collect->img.texx - 1;
	if (collect->img.side == 1 && collect->img.raydiry < 0)
		collect->img.texx = collect->img.texww - collect->img.texx - 1;
	wtext2(collect);
}

void	wtext2(t_collect *collect)
{
	char *dst;

	collect->img.step = 1.0 * collect->img.texhw / collect->img.lineheight;
	collect->img.texpos = (collect->img.drawstart - collect->
	squire.yrender / 2 + collect->img.lineheight / 2) * collect->img.step;
	collect->img.y = collect->img.drawstart;
	while (collect->img.y < collect->img.drawend)
	{
		collect->img.texy = (int)collect->img.texpos & (collect->img.texhw - 1);
		collect->img.texpos += collect->img.step;
		dst = collect->img.w_ad + ((collect->img.texy * collect->
		img.texhw + collect->img.texx) * (collect->img.bits_per_pixel / 8));
		collect->img.color = *(unsigned int *)dst;
		my_mlx_pixel_put(collect, collect->img.x,
		collect->img.y, collect->img.color);
		collect->img.y++;
	}
}
