/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sglass <sglass@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 17:35:49 by sglass            #+#    #+#             */
/*   Updated: 2020/12/16 13:17:37 by sglass           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	int		i;
	size_t	j;
	char	*a;

	i = 0;
	j = 0;
	while (s[i] != '\0')
		i++;
	if ((int)start >= i)
	{
		a = malloc(1);
		a[0] = '\0';
		return (a);
	}
	a = malloc(sizeof(char) * len + 1);
	if (a == NULL)
		return (NULL);
	while (s[start] != '\0' && j < len)
	{
		a[j] = s[start];
		j++;
		start++;
	}
	a[j] = '\0';
	return (a);
}
