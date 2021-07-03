/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controller2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sglass <sglass@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 13:41:14 by sglass            #+#    #+#             */
/*   Updated: 2021/01/21 22:22:37 by sglass           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	dkey(t_collect *collect)
{
	if (collect->squire.tmap[(int)(collect->img.posx + collect->
	img.planex * 0.3)][(int)collect->img.posy] != '1' &&
	collect->squire.tmap[(int)(collect->img.posx + collect->
	img.planex * 0.3)][(int)collect->img.posy] != '2')
		collect->img.posx += collect->img.planex * 0.1;
	if (collect->squire.tmap[(int)collect->img.posx][(int)(collect->
	img.posy + collect->img.planey * 0.3)] != '1' &&
	collect->squire.tmap[(int)collect->img.posx][(int)(collect->
	img.posy + collect->img.planey * 0.3)] != '2')
		collect->img.posy += collect->img.planey * 0.1;
}

void	akey(t_collect *collect)
{
	if (collect->squire.tmap[(int)(collect->img.posx - collect->
	img.planex * 0.3)][(int)collect->img.posy] != '1' &&
	collect->squire.tmap[(int)(collect->img.posx - collect->
	img.planex * 0.3)][(int)collect->img.posy] != '2')
		collect->img.posx += collect->img.planex * -0.1;
	if (collect->squire.tmap[(int)collect->img.posx][(int)(collect->
	img.posy - collect->img.planey * 0.3)] != '1' &&
	collect->squire.tmap[(int)collect->img.posx][(int)(collect->
	img.posy - collect->img.planey * 0.3)] != '2')
		collect->img.posy += collect->img.planey * -0.1;
}
