/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sglass <sglass@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 13:41:15 by sglass            #+#    #+#             */
/*   Updated: 2021/01/21 21:23:05 by sglass           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	f;
	char	*a;

	i = 0;
	f = 0;
	if (s1 == NULL || s2 == NULL)
		return (NULL);
	while (s1[i] != '\0')
		i++;
	while (s2[f] != '\0')
		f++;
	a = malloc((i + f + 1) * sizeof(char));
	if (a == NULL)
		return (NULL);
	f = -1;
	i = 0;
	while (s1[++f] != '\0')
		a[f] = s1[f];
	while (s2[i] != '\0')
		a[f++] = s2[i++];
	a[f] = '\0';
	return (a);
}

int		try1(int fd, char **line, char *buf)
{
	int		r;
	char	*temp;

	temp = NULL;
	if (**line != '\0')
		temp = *line;
	line[0] = ft_strjoin(line[0], buf);
	if (temp != NULL)
		free(temp);
	ft_bzero(buf, BUFFER_SIZE);
	r = read(fd, buf, BUFFER_SIZE);
	if (r == 0 && buf != NULL)
	{
		return (0);
	}
	if (r < 0)
		return (-1);
	return (1);
}

void	try2(char **line, char *buf)
{
	char	*temp;
	char	*temp1;
	int		size;
	char	*a;

	a = ft_strchr(buf, '\n');
	size = a - buf;
	temp = NULL;
	if (**line != 0)
		temp = *line;
	temp1 = ft_substr(buf, 0, size);
	*line = ft_strjoin(*line, temp1);
	if (temp != NULL)
		free(temp);
	free(temp1);
	ft_memmove(buf, &buf[size + 1], BUFFER_SIZE - size - 1);
	ft_bzero(&buf[BUFFER_SIZE - size - 1], size + 1);
}

int		gnl(char *buf, int fd, char **line)
{
	int		r;

	while (1)
	{
		if (ft_strchr(buf, '\n') == NULL)
		{
			r = try1(fd, line, buf);
			if (r == 0)
				return (0);
			if (r < 0)
				return (-1);
		}
		else
		{
			try2(line, buf);
			return (1);
		}
	}
	return (21);
}

int		get_next_line(int fd, char **line)
{
	static char	*buf;
	int			r;

	if (buf == NULL)
	{
		buf = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
		if (read(fd, buf, BUFFER_SIZE) < 0 || BUFFER_SIZE <= 0)
		{
			free(buf);
			buf = NULL;
			return (-1);
		}
	}
	*line = "\0";
	r = gnl(buf, fd, line);
	if (r == 0 || r == -1 || (r == 1 && *buf == '\0'))
	{
		free(buf);
		buf = NULL;
	}
	return (r);
}
