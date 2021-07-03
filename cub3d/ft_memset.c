/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sglass <sglass@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 10:54:19 by sglass            #+#    #+#             */
/*   Updated: 2021/01/21 17:01:59 by sglass           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned int	i;
	unsigned char	*x;
	unsigned char	cc;

	i = 0;
	x = b;
	cc = c;
	while (i < len)
	{
		*x++ = cc;
		i++;
	}
	return (b);
}
