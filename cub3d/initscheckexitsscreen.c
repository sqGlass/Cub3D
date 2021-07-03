/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initscheckexitsscreen.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sglass <sglass@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 19:14:35 by sglass            #+#    #+#             */
/*   Updated: 2021/01/22 12:27:15 by sglass           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	screen(t_collect *collect)
{
	collect->img.mlx = mlx_init();
	collect->img.img = mlx_new_image(collect->img.mlx,
	collect->squire.xrender, collect->squire.yrender);
	initimgs(collect);
	init_player(collect);
	collect->img.addr = mlx_get_data_addr(collect->img.img, &collect->
	img.bits_per_pixel, &collect->img.line_length, &collect->img.endian);
	game_engine(collect);
	scr1(collect);
	mlx_destroy_image(collect->img.mlx, collect->img.img);
	exit(0);
}

int		checkargs(int argc, char **argv)
{
	if (argc > 3 || argc < 2)
	{
		write(1, "Error\n", 6);
		exit(0);
	}
	if (argc == 3)
	{
		if (ft_strcmp(argv[2], "--save") == 0)
			return (1);
		else
		{
			write(1, "Error\n", 6);
			exit(0);
		}
	}
	return (0);
}

int		redexit(t_collect *collect)
{
	(void)collect;
	exit(0);
}

void	inittextures(t_collect *collect)
{
	collect->squire.ntxt = NULL;
	collect->squire.stxt = NULL;
	collect->squire.wtxt = NULL;
	collect->squire.etxt = NULL;
	collect->squire.sptxt = NULL;
}

void	errorexit(t_collect *collect)
{
	(void)collect;
	write(1, "Error\n", 6);
	exit(1);
}
