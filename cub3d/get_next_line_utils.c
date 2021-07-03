/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sglass <sglass@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 17:15:10 by sglass            #+#    #+#             */
/*   Updated: 2021/01/21 21:23:22 by sglass           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	ft_bzero(void *s, size_t n)
{
	size_t	i;
	char	*x;

	i = 0;
	x = s;
	if (n == 0)
	{
		return ;
	}
	while (i < n)
	{
		x[i] = '\0';
		i++;
	}
}

char	*ft_strchr(const char *s, int c)
{
	int				i;
	const char		*ss;
	unsigned char	cc;

	i = 0;
	ss = s;
	cc = c;
	while (ss[i] != '\0')
	{
		if (ss[i] == cc)
			return ((char *)&ss[i]);
		i++;
	}
	if (ss[i] == cc)
		return ((char *)&ss[i]);
	return (NULL);
}
