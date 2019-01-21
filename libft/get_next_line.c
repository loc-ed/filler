/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfrederi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/07 11:18:29 by cfrederi          #+#    #+#             */
/*   Updated: 2018/07/31 23:35:31 by cfrederi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*rd_line(const int fd, char *buf, int *bytes_read)
{
	char			*tmp;
	char			hold[BUFF_SIZE + 1];

	*bytes_read = read(fd, hold, BUFF_SIZE);
	hold[*bytes_read] = '\0';
	tmp = buf;
	if (!(buf = ft_strjoin(tmp, hold)))
		return (NULL);
	ft_strdel(&tmp);
	return (buf);
}

int			sweep(char **buf, char **line)
{
	if (!(*line = ft_strdup(*buf)))
		return (-1);
	ft_bzero(*buf, ft_strlen(*buf));
	return (1);
}

int			get_next_line(const int fd, char **line)
{
	static char		*buf = "";
	int				bytes_read;
	char			*lim;

	bytes_read = 1;
	if (!line || fd < 0 || read(fd, 0, 0) ||
			(buf[0] == '\0' && (!(buf = ft_strnew(0)))))
		return (-1);
	while (bytes_read > 0)
	{
		if ((lim = ft_strchr(buf, '\n')) != NULL)
		{
			*lim = '\0';
			if (!(*line = ft_strdup(buf)))
				return (-1);
			ft_memmove(buf, (lim + 1), ft_strlen(lim + 1) + 1);
			return (1);
		}
		if (!(buf = rd_line(fd, buf, &bytes_read)))
			return (-1);
	}
	ft_strdel(&lim);
	if ((bytes_read == 0 && (ft_strlen(buf) || (buf && *buf))))
		bytes_read = sweep(&buf, &(*line));
	return (bytes_read);
}
