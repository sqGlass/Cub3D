/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textureswalls.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sglass <sglass@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 14:32:55 by sglass            #+#    #+#             */
/*   Updated: 2021/01/21 22:01:08 by sglass           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	stext(t_collect *collect)
{
	if (collect->img.side == 0)
		collect->img.wallx = collect->img.posy + collect->
		img.perpwalldist * collect->img.raydiry;
	else
		collect->img.wallx = collect->img.posx + collect->
		img.perpwalldist * collect->img.raydirx;
	collect->img.wallx -= floor((collect->img.wallx));
	collect->img.texx = (int)(collect->img.wallx * (double)collect->img.texws);
	if (collect->img.side == 0 && collect->img.raydirx > 0)
		collect->img.texx = collect->img.texws - collect->img.texx - 1;
	if (collect->img.side == 1 && collect->img.raydiry < 0)
		collect->img.texx = collect->img.texws - collect->img.texx - 1;
	stext2(collect);
}

void	stext2(t_collect *collect)
{
	char *dst;

	collect->img.step = 1.0 * collect->img.texhs / collect->img.lineheight;
	collect->img.texpos = (collect->img.drawstart - collect->
	squire.yrender / 2 + collect->img.lineheight / 2) * collect->img.step;
	collect->img.y = collect->img.drawstart;
	while (collect->img.y < collect->img.drawend)
	{
		collect->img.texy = (int)collect->img.texpos & (collect->img.texhs - 1);
		collect->img.texpos += collect->img.step;
		dst = collect->img.so_ad + ((collect->img.texy * collect->
		img.texhs + collect->img.texx) * (collect->img.bits_per_pixel / 8));
		collect->img.color = *(unsigned int *)dst;
		my_mlx_pixel_put(collect, collect->img.x,
		collect->img.y, collect->img.color);
		collect->img.y++;
	}
}

void	ntext(t_collect *collect)
{
	if (collect->img.side == 0)
		collect->img.wallx = collect->img.posy +
		collect->img.perpwalldist * collect->img.raydiry;
	else
		collect->img.wallx = collect->img.posx +
		collect->img.perpwalldist * collect->img.raydirx;
	collect->img.wallx -= floor((collect->img.wallx));
	collect->img.texx = (int)(collect->img.wallx * (double)collect->img.texwn);
	if (collect->img.side == 0 && collect->img.raydirx > 0)
		collect->img.texx = collect->img.texwn - collect->img.texx - 1;
	if (collect->img.side == 1 && collect->img.raydiry < 0)
		collect->img.texx = collect->img.texwn - collect->img.texx - 1;
	ntext2(collect);
}

void	ntext2(t_collect *collect)
{
	char *dst;

	collect->img.step = 1.0 * collect->img.texhn / collect->img.lineheight;
	collect->img.texpos = (collect->img.drawstart - collect->
	squire.yrender / 2 + collect->img.lineheight / 2) * collect->img.step;
	collect->img.y = collect->img.drawstart;
	while (collect->img.y < collect->img.drawend)
	{
		collect->img.texy = (int)collect->img.texpos & (collect->img.texhn - 1);
		collect->img.texpos += collect->img.step;
		dst = collect->img.n_ad + ((collect->img.texy * collect->
		img.texhn + collect->img.texx) * (collect->img.bits_per_pixel / 8));
		collect->img.color = *(unsigned int *)dst;
		my_mlx_pixel_put(collect, collect->img.x,
		collect->img.y, collect->img.color);
		collect->img.y++;
	}
}

void	etext(t_collect *collect)
{
	if (collect->img.side == 0)
		collect->img.wallx = collect->img.posy +
		collect->img.perpwalldist * collect->img.raydiry;
	else
		collect->img.wallx = collect->img.posx +
		collect->img.perpwalldist * collect->img.raydirx;
	collect->img.wallx -= floor((collect->img.wallx));
	collect->img.texx = (int)(collect->img.wallx * (double)collect->img.texwe);
	if (collect->img.side == 0 && collect->img.raydirx > 0)
		collect->img.texx = collect->img.texwe - collect->img.texx - 1;
	if (collect->img.side == 1 && collect->img.raydiry < 0)
		collect->img.texx = collect->img.texwe - collect->img.texx - 1;
	etext2(collect);
}
