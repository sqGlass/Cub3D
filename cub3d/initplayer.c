/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initplayer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sglass <sglass@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 13:08:26 by sglass            #+#    #+#             */
/*   Updated: 2021/01/22 17:19:53 by sglass           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	init_player(t_collect *collect)
{
	collect->img.posx = collect->squire.xplayer + 0.5;
	collect->img.posy = collect->squire.yplayer + 0.5;
	if (collect->squire.player == 'W')
		westplayer(collect);
	if (collect->squire.player == 'N')
		northplayer(collect);
	if (collect->squire.player == 'S')
		southplayer(collect);
	if (collect->squire.player == 'E')
		eastplayer(collect);
}

void	westplayer(t_collect *collect)
{
	collect->img.dirx = 0;
	collect->img.diry = -1;
	collect->img.planex = -0.66;
	collect->img.planey = 0;
}

void	northplayer(t_collect *collect)
{
	collect->img.dirx = -1;
	collect->img.diry = 0;
	collect->img.planex = 0;
	collect->img.planey = 0.66;
}

void	southplayer(t_collect *collect)
{
	collect->img.dirx = 1;
	collect->img.diry = 0;
	collect->img.planex = 0;
	collect->img.planey = -0.66;
}

void	eastplayer(t_collect *collect)
{
	collect->img.dirx = 0;
	collect->img.diry = 1;
	collect->img.planex = 0.66;
	collect->img.planey = 0;
}
