/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calcheight.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sglass <sglass@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 14:23:18 by sglass            #+#    #+#             */
/*   Updated: 2021/01/21 22:04:47 by sglass           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	calclineheight(t_collect *collect)
{
	collect->img.lineheight = (int)(collect->squire.yrender /
	collect->img.perpwalldist);
	collect->img.drawstart = -collect->img.lineheight / 2 +
	collect->squire.yrender / 2;
	if (collect->img.drawstart < 0)
		collect->img.drawstart = 0;
	collect->img.drawend = collect->img.lineheight / 2 +
	collect->squire.yrender / 2;
	if (collect->img.drawend >= collect->squire.yrender)
		collect->img.drawend = collect->squire.yrender - 1;
}
