/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sglass <sglass@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/08 19:17:18 by sglass            #+#    #+#             */
/*   Updated: 2021/01/25 13:14:42 by sglass           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int		main(int argc, char **argv)
{
	int			fd;
	int			flag;
	char		*line;
	int			m;
	t_list		*head;

	flag = checkargs(argc, argv);
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		exit2();
	while ((m = get_next_line(fd, &line)))
	{
		if (m == -1)
			exit2();
		ft_lstadd_back(&head, ft_lstnew(line));
	}
	ft_lstadd_back(&head, ft_lstnew(line));
	close(fd);
	make_map(&head, ft_lstsize(head), flag);
}

void	mlxwindow(t_collect *collect)
{
	if (collect->img.flag == 1)
		screen(collect);
	collect->img.mlx = mlx_init();
	collect->img.mlx_win = mlx_new_window(collect->img.mlx,
	collect->squire.xrender, collect->squire.yrender, "Hello world!");
	collect->img.img = mlx_new_image(collect->img.mlx,
	collect->squire.xrender, collect->squire.yrender);
	initimgs(collect);
	init_player(collect);
	initkeys(collect);
	mlx_hook(collect->img.mlx_win, 2, 0, push, collect);
	mlx_hook(collect->img.mlx_win, 3, 0, nopush, collect);
	mlx_hook(collect->img.mlx_win, 17, 0, redexit, collect);
	mlx_loop_hook(collect->img.mlx, render_next_frame, collect);
	mlx_loop(collect->img.mlx);
}

void	my_mlx_pixel_put(t_collect *collect, int x, int y, int color)
{
	char *dst;

	dst = collect->img.addr + (y * collect->
	img.line_length + x * (collect->img.bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	exit2(void)
{
	write(1, "Error\n", 6);
	exit(0);
}
