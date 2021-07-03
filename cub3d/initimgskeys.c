/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initimgskeys.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sglass <sglass@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 20:05:38 by sglass            #+#    #+#             */
/*   Updated: 2021/01/21 21:21:43 by sglass           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	initimgs(t_collect *col)
{
	col->img.w_img = mlx_xpm_file_to_image(col->img.mlx,
	col->squire.wtxt, &col->img.texww, &col->img.texhw);
	col->img.so_img = mlx_xpm_file_to_image(col->img.mlx,
	col->squire.stxt, &col->img.texws, &col->img.texhs);
	col->img.n_img = mlx_xpm_file_to_image(col->img.mlx,
	col->squire.ntxt, &col->img.texwn, &col->img.texhn);
	col->img.e_img = mlx_xpm_file_to_image(col->img.mlx,
	col->squire.etxt, &col->img.texwe, &col->img.texhe);
	col->img.sp_img = mlx_xpm_file_to_image(col->img.mlx,
	col->squire.sptxt, &col->img.texwsp, &col->img.texhsp);
	col->img.w_ad = mlx_get_data_addr(col->img.w_img,
	&col->img.bits_per_pixel, &col->img.line_length, &col->img.endian);
	col->img.so_ad = mlx_get_data_addr(col->img.so_img,
	&col->img.bits_per_pixel, &col->img.line_length, &col->img.endian);
	col->img.n_ad = mlx_get_data_addr(col->img.n_img,
	&col->img.bits_per_pixel, &col->img.line_length, &col->img.endian);
	col->img.e_ad = mlx_get_data_addr(col->img.e_img,
	&col->img.bits_per_pixel, &col->img.line_length, &col->img.endian);
	col->img.sp_ad = mlx_get_data_addr(col->img.sp_img,
	&col->img.bits_per_pixel, &col->img.line_length, &col->img.endian);
}

void	initkeys(t_collect *col)
{
	col->img.wasd[0] = 0;
	col->img.wasd[1] = 0;
	col->img.wasd[2] = 0;
	col->img.wasd[3] = 0;
	col->img.wasd[4] = 0;
	col->img.wasd[5] = 0;
}

int		push(int keycode, t_collect *collect)
{
	if (keycode == 13)
		collect->img.wasd[0] = 1;
	if (keycode == 1)
		collect->img.wasd[1] = 1;
	if (keycode == 123)
		collect->img.wasd[2] = 1;
	if (keycode == 124)
		collect->img.wasd[3] = 1;
	if (keycode == 2)
		collect->img.wasd[4] = 1;
	if (keycode == 0)
		collect->img.wasd[5] = 1;
	if (keycode == 53)
		exit(0);
	return (0);
}

int		nopush(int keycode, t_collect *collect)
{
	if (keycode == 13)
		collect->img.wasd[0] = 0;
	if (keycode == 1)
		collect->img.wasd[1] = 0;
	if (keycode == 123)
		collect->img.wasd[2] = 0;
	if (keycode == 124)
		collect->img.wasd[3] = 0;
	if (keycode == 2)
		collect->img.wasd[4] = 0;
	if (keycode == 0)
		collect->img.wasd[5] = 0;
	return (0);
}
