/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sglass <sglass@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 16:59:59 by sglass            #+#    #+#             */
/*   Updated: 2021/01/21 21:38:02 by sglass           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	scr1(t_collect *collect)
{
	static unsigned char bmppad[3] = {0, 0, 0};

	collect->img.img2 = NULL;
	collect->img.filesize = 54 + 3 * collect->
	squire.xrender * collect->squire.yrender;
	collect->img.img2 = (unsigned char *)malloc(3 *
	collect->squire.xrender * collect->squire.yrender);
	if (collect->img.img2 == NULL)
		exit(0);
	ft_memset(collect->img.img2, 0, 3 * collect->squire.xrender *
	collect->squire.yrender);
	scr2(collect);
	scr4(collect);
	collect->img.i = -1;
	while (++collect->img.i <= collect->squire.yrender)
	{
		write(collect->img.fd, collect->img.img2 + (collect->squire.xrender *
		(collect->squire.yrender - collect->img.i - 1) * 3),
		collect->squire.xrender * 3);
		write(collect->img.fd, bmppad, (4 - (collect->
		squire.xrender * 3) % 4) % 4);
	}
	free(collect->img.img2);
	close(collect->img.fd);
}

void	scr2(t_collect *collect)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < collect->squire.xrender)
	{
		while (j < collect->squire.yrender)
		{
			scr3(collect, i, j);
			j++;
		}
		j = 0;
		i++;
	}
}

void	scr3(t_collect *collect, int i, int j)
{
	collect->img.x = i;
	collect->img.y = (collect->squire.yrender - 1) - j;
	collect->img.dst = collect->img.addr + (collect->img.y * collect->
	img.line_length + collect->img.x * (collect->img.bits_per_pixel / 8));
	collect->img.color = *(unsigned int *)collect->img.dst;
	collect->img.r = (collect->img.color >> 16) & 0xff;
	collect->img.g = (collect->img.color >> 8) & 0xff;
	collect->img.b = (collect->img.color) & 0xff;
	collect->img.img2[(collect->img.x + collect->img.y *
	collect->squire.xrender) * 3 + 2] = (unsigned char)(collect->img.r);
	collect->img.img2[(collect->img.x + collect->img.y *
	collect->squire.xrender) * 3 + 1] = (unsigned char)(collect->img.g);
	collect->img.img2[(collect->img.x + collect->img.y *
	collect->squire.xrender) * 3 + 0] = (unsigned char)(collect->img.b);
}

void	scr4(t_collect *collect)
{
	static unsigned char bmpfileheader[14] =
	{'B', 'M', 0, 0, 0, 0, 0, 0, 0, 0, 54, 0, 0, 0};
	static unsigned char bmpinfoheader[40] =
	{40, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 24, 0};

	bmpfileheader[2] = (unsigned char)(collect->img.filesize);
	bmpfileheader[3] = (unsigned char)(collect->img.filesize >> 8);
	bmpfileheader[4] = (unsigned char)(collect->img.filesize >> 16);
	bmpfileheader[5] = (unsigned char)(collect->img.filesize >> 24);
	bmpinfoheader[4] = (unsigned char)(collect->squire.xrender);
	bmpinfoheader[5] = (unsigned char)(collect->squire.xrender >> 8);
	bmpinfoheader[6] = (unsigned char)(collect->squire.xrender >> 16);
	bmpinfoheader[7] = (unsigned char)(collect->squire.xrender >> 24);
	bmpinfoheader[8] = (unsigned char)(collect->squire.yrender);
	bmpinfoheader[9] = (unsigned char)(collect->squire.yrender >> 8);
	bmpinfoheader[10] = (unsigned char)(collect->squire.yrender >> 16);
	bmpinfoheader[11] = (unsigned char)(collect->squire.yrender >> 24);
	collect->img.fd = open("img.bmp", O_RDWR | O_TRUNC | O_CREAT, S_IRWXU);
	write(collect->img.fd, bmpfileheader, 14);
	write(collect->img.fd, bmpinfoheader, 40);
}
