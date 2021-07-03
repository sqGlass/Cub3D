/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkerrors.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sglass <sglass@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/08 20:15:52 by sglass            #+#    #+#             */
/*   Updated: 2021/01/21 22:19:52 by sglass           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	checkerrors1(t_errors *errors, t_collect *collect)
{
	int fd;

	if (collect->squire.xrender == 0 || collect->squire.yrender == 0)
		errors->rendererr = 1;
	fd = open(collect->squire.ntxt, O_RDONLY);
	if (fd == -1)
		errors->northtextureerr = 1;
	close(fd);
	fd = open(collect->squire.stxt, O_RDONLY);
	if (fd == -1)
		errors->southtextureerr = 1;
	close(fd);
	fd = open(collect->squire.etxt, O_RDONLY);
	if (fd == -1)
		errors->easttextureerr = 1;
	close(fd);
	fd = open(collect->squire.wtxt, O_RDONLY);
	if (fd == -1)
		errors->westtextureerr = 1;
	close(fd);
	fd = open(collect->squire.sptxt, O_RDONLY);
	if (fd == -1)
		errors->spritetextureerr = 1;
	close(fd);
}

void	checkerrors2(t_errors *errors, t_collect *collect)
{
	if ((collect->squire.floorr == -1 || collect->squire.floorr > 255) ||
		(collect->squire.floorg == -1 ||
		collect->squire.floorg > 255) || (collect->squire.floorb == -1 ||
		collect->squire.floorb > 255))
		errors->floorerr = 1;
	if ((collect->squire.ceillingr == -1 || collect->squire.ceillingr > 255) ||
		(collect->squire.ceillingg == -1 ||
		collect->squire.ceillingg > 255) || (collect->squire.ceillingb == -1 ||
		collect->squire.ceillingb > 255))
		errors->ceillingerr = 1;
	if (collect->squire.countplayer != 1)
		errors->mapsymbolerr = 1;
}
