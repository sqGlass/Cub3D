/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controller.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sglass <sglass@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 17:56:42 by sglass            #+#    #+#             */
/*   Updated: 2021/01/22 20:46:00 by sglass           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int		render_next_frame(t_collect *collect)
{
	if (collect->img.wasd[0] == 1)
		wkey(collect);
	if (collect->img.wasd[1] == 1)
		skey(collect);
	if (collect->img.wasd[2] == 1)
		lkey(collect);
	if (collect->img.wasd[3] == 1)
		rkey(collect);
	if (collect->img.wasd[4] == 1)
		dkey(collect);
	if (collect->img.wasd[5] == 1)
		akey(collect);
	collect->img.addr = mlx_get_data_addr(collect->img.img, &collect->
	img.bits_per_pixel, &collect->img.line_length, &collect->img.endian);
	game_engine(collect);
	mlx_put_image_to_window(collect->img.mlx, collect->
	img.mlx_win, collect->img.img, 0, 0);
	mlx_destroy_image(collect->img.mlx, collect->img.img);
	collect->img.img = mlx_new_image(collect->img.mlx,
	collect->squire.xrender, collect->squire.yrender);
	return (0);
}

void	wkey(t_collect *collect)
{
	if (collect->squire.tmap[(int)(collect->img.posx +
	collect->img.dirx * 0.15)][(int)collect->img.posy] != '1')
		if (collect->squire.tmap[(int)(collect->img.posx +
		collect->img.dirx * 0.15)][(int)collect->img.posy] != '2')
			collect->img.posx += (collect->img.dirx) * 0.15;
	if (collect->squire.tmap[(int)collect->img.posx][(int)
	(collect->img.posy + collect->img.diry * 0.15)] != '1')
		if (collect->squire.tmap[(int)collect->img.posx][(int)
		(collect->img.posy + collect->img.diry * 0.15)] != '2')
			collect->img.posy += (collect->img.diry) * 0.15;
}

void	skey(t_collect *collect)
{
	if (collect->squire.tmap[(int)(collect->img.posx -
	collect->img.dirx * 0.15)][(int)collect->img.posy] != '1'
	&& collect->squire.tmap[(int)(collect->img.posx -
	collect->img.dirx * 0.15)][(int)collect->img.posy] != '2')
		collect->img.posx += collect->img.dirx * -0.15;
	if (collect->squire.tmap[(int)collect->img.posx][(int)(collect->
	img.posy - collect->img.diry * 0.15)] != '1' &&
	collect->squire.tmap[(int)collect->img.posx][(int)(collect->
	img.posy - collect->img.diry * 0.15)] != '2')
		collect->img.posy += collect->img.diry * -0.15;
}

void	lkey(t_collect *collect)
{
	collect->img.olddirx = collect->img.dirx;
	collect->img.dirx = collect->img.dirx *
	cos(0.06) - collect->img.diry * sin(0.06);
	collect->img.diry = collect->img.olddirx *
	sin(0.06) + collect->img.diry * cos(0.06);
	collect->img.oldplanex = collect->img.planex;
	collect->img.planex = collect->img.planex *
	cos(0.06) - collect->img.planey * sin(0.06);
	collect->img.planey = collect->img.oldplanex *
	sin(0.06) + collect->img.planey * cos(0.06);
}

void	rkey(t_collect *collect)
{
	collect->img.olddirx = collect->img.dirx;
	collect->img.dirx = collect->img.dirx *
	cos(-0.06) - collect->img.diry * sin(-0.06);
	collect->img.diry = collect->img.olddirx *
	sin(-0.06) + collect->img.diry * cos(-0.06);
	collect->img.oldplanex = collect->img.planex;
	collect->img.planex = collect->img.planex *
	cos(-0.06) - collect->img.planey * sin(-0.06);
	collect->img.planey = collect->img.oldplanex *
	sin(-0.06) + collect->img.planey * cos(-0.06);
}
