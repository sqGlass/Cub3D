/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sglass <sglass@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 11:54:53 by sglass            #+#    #+#             */
/*   Updated: 2021/01/21 19:37:17 by sglass           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

t_list	*ft_lstnew(void *content)
{
	t_list *f;

	f = malloc(sizeof(t_list));
	if (f == NULL)
	{
		write(1, "Error\n", 6);
		exit(0);
	}
	f->content = content;
	f->next = NULL;
	return (f);
}
