/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sglass <sglass@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 15:19:52 by sglass            #+#    #+#             */
/*   Updated: 2021/01/22 17:27:17 by sglass           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	sorter(t_collect *collect)
{
	int i;
	int x;
	int y;

	i = 0;
	x = 0;
	y = 0;
	while (i < collect->squire.numsprites - 1)
	{
		if ((((int)collect->img.posx - collect->squire.sprites[i + 1][0]) *
		((int)collect->img.posx - collect->squire.sprites[i + 1][0]) +
		((int)collect->img.posy - collect->squire.sprites[i + 1][1]) *
		((int)collect->img.posy - collect->squire.sprites[i + 1][1])) >
		(((int)collect->img.posx - collect->squire.sprites[i][0]) *
		((int)collect->img.posx - collect->squire.sprites[i][0]) +
		((int)collect->img.posy - collect->squire.sprites[i][1]) *
		((int)collect->img.posy - collect->squire.sprites[i][1])))
		{
			sorter2(collect, x, y, i);
			i = 0;
		}
		i++;
	}
}

void	sorter2(t_collect *collect, int x, int y, int i)
{
	x = collect->squire.sprites[i][0];
	y = collect->squire.sprites[i][1];
	collect->squire.sprites[i][0] = collect->squire.sprites[i + 1][0];
	collect->squire.sprites[i][1] = collect->squire.sprites[i + 1][1];
	collect->squire.sprites[i + 1][0] = x;
	collect->squire.sprites[i + 1][1] = y;
}

void	sprites(t_collect *col, double *zbuffer)
{
	int i;

	i = 0;
	while (i < col->squire.numsprites)
	{
		sprites2(col, i);
		while (col->img.stripe < col->img.drawendx)
		{
			sprites3(col, zbuffer);
			col->img.stripe++;
		}
		i++;
	}
}

void	sprites2(t_collect *col, int i)
{
	col->img.spritex = col->squire.sprites[i][0] - col->img.posx + 0.5;
	col->img.spritey = col->squire.sprites[i][1] - col->img.posy + 0.5;
	col->img.invdet = 1.0 / (col->img.planex * col->img.diry -
	col->img.dirx * col->img.planey);
	col->img.transformx = col->img.invdet * (col->img.diry *
	col->img.spritex - col->img.dirx * col->img.spritey);
	col->img.transformy = col->img.invdet * (-col->img.planey *
	col->img.spritex + col->img.planex * col->img.spritey);
	col->img.spritescreenx = (int)((col->squire.xrender / 2) *
	(1 + col->img.transformx / col->img.transformy));
	col->img.spriteheight = fabs((col->squire.yrender / col->img.transformy));
	col->img.drawstarty = -col->img.spriteheight / 2 + col->squire.yrender / 2;
	if (col->img.drawstarty < 0)
		col->img.drawstarty = 0;
	col->img.drawendy = col->img.spriteheight / 2 + col->squire.yrender / 2;
	if (col->img.drawendy >= col->squire.yrender)
		col->img.drawendy = col->squire.yrender - 1;
	col->img.spritewidth = fabs((col->squire.yrender / (col->img.transformy)));
	col->img.drawstartx = -col->img.spritewidth / 2 + col->img.spritescreenx;
	if (col->img.drawstartx < 0)
		col->img.drawstartx = 0;
	col->img.drawendx = col->img.spritewidth / 2 + col->img.spritescreenx;
	if (col->img.drawendx >= col->squire.xrender)
		col->img.drawendx = col->squire.xrender - 1;
	col->img.stripe = col->img.drawstartx;
}

void	sprites3(t_collect *col, double *zbuffer)
{
	char			*dst;

	col->img.texx = (int)(256 * (col->img.stripe - (-col->img.spritewidth / 2
	+ col->img.spritescreenx)) * col->img.texwsp / col->img.spritewidth) / 256;
	col->img.y = col->img.drawstarty;
	if (col->img.transformy > 0 && col->img.stripe > 0
	&& col->img.stripe < col->squire.xrender &&
		col->img.transformy < zbuffer[col->img.stripe])
	{
		while (col->img.y < col->img.drawendy)
		{
			col->img.d = (col->img.y) * 256 - col->squire.yrender
			* 128 + col->img.spriteheight * 128;
			col->img.texy = ((col->img.d * col->img.texhsp)
			/ col->img.spriteheight) / 256;
			dst = col->img.sp_ad + ((col->img.texy * col->img.texwsp
			+ col->img.texx) * (col->img.bits_per_pixel / 8));
			col->img.color = *(unsigned int *)dst;
			if ((col->img.color & 0x00FFFFFF) != 0)
				my_mlx_pixel_put(col, col->img.stripe,
				col->img.y, col->img.color);
			col->img.y++;
		}
	}
}
