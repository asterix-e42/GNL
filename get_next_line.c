/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdumouli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 06:21:14 by tdumouli          #+#    #+#             */
/*   Updated: 2016/11/21 06:21:18 by tdumouli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include "get_next_line.h"
#include "libft.h"
#include <stdlib.h>

int		remplissage(const int fd, char **line)
{
	char	*buf;
	char	*tmp;
	int		rd;
	int		i;
	int		flag;

	i = 0;
	while (*(*line + i) != '\n' && *(*line + i) != -1 && (*((*line) + i)))
		++i;
	flag = (*(*line + i) == '\n' || *(*line + i) == -1);
	if (!(buf = (char *)malloc(sizeof(char) * (BUFF_SIZE + 1))))
		return (-1);
	while (!flag && (rd = read(fd, buf, BUFF_SIZE)))
	{
		if (rd == -1)
			return (-1);
		buf[rd] = '\0';
		i = 0;
		while (*(buf + i) != '\n' && i != rd)
			++i;
		if (*(buf + i) == '\n')
			flag = 1;
		else
			*(buf + i + 1) = '\0';
		if (!(tmp = ft_strjoin(*line, buf)))
			return (-1);
		free(*line);
		*line = tmp;
	}
	free(buf);
	return (flag);
}

int		decoupage(char **line, char **stk)
{
	int		start;
	int		end;
	char	*tmp;

	start = 0;
	end = 0;
	while (*(*line + start) != '\n' && *(*line + start) != -1)
		++start;
	while (*(*line + start + end) != '\0')
		++end;
	tmp = *line;
	*stk = ft_strsub(tmp, 0, start);
	*line = ft_strsub(tmp, start + 1, end - 1);
	free(tmp);
	return (0);
}

int		get_next_line(const int fd, char **line)
{
	static char	*offset;
	int			ret;

	if (!offset)
		if (!(offset = (char *)malloc(1)))
			return (-1);
	if ((ret = remplissage(fd, &offset)) == -1)
		return (-1);
	if (!ret)
		return (0);
	decoupage(&offset, line);
	return (1);
}
