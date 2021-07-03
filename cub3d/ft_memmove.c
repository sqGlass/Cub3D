/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sglass <sglass@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 15:54:05 by sglass            #+#    #+#             */
/*   Updated: 2020/12/08 16:51:06 by sglass           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t				i;
	unsigned char		*d;
	const unsigned char	*s;

	i = 0;
	d = dst;
	s = src;
	if (dst == '\0' && src == '\0')
		return (NULL);
	if (src > dst)
		while (i < len)
		{
			d[i] = s[i];
			i++;
		}
	else
		while (len > 0)
		{
			d[len - 1] = s[len - 1];
			len--;
		}
	return (dst);
}
