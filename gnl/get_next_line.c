/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jconde-a <jconde-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 09:58:56 by jconde-a          #+#    #+#             */
/*   Updated: 2023/10/17 21:54:44 by jconde-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_get_read(char *readed, char *buffer, int fd);

char	*ft_read(int fd, char *buffer)
{
	char	*readed;

	readed = (char *) malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!readed)
		return (NULL);
	buffer = ft_get_read(readed, buffer, fd);
	free(readed);
	if (!buffer)
		return (NULL);
	return (buffer);
}

char	*ft_get_read(char *readed, char *buffer, int fd)
{
	int		num;
	char	*buffer_old;

	while (!ft_strchr(buffer, '\n'))
	{
		num = read(fd, readed, BUFFER_SIZE);
		if ((num < 0) || ((num == 0) && (ft_strlen(buffer) == 0 || (!buffer))))
			return (NULL);
		if (num == 0)
			break ;
		readed[num] = '\0';
		buffer_old = buffer;
		buffer = ft_strcat(buffer, readed);
		free (buffer_old);
		if (!buffer)
			break ;
	}
	return (buffer);
}

char	*ft_get_linea(char *buffer)
{
	int		i;
	int		ind;
	char	*line;

	if (!ft_strchr((char *)buffer, '\n'))
	{
		return (ft_copy(buffer));
	}
	i = (ft_strchr((char *)buffer, '\n') - buffer + 1);
		line = malloc(sizeof(char) * (i + 1));
	if (!line)
	{
		return (NULL);
	}
	ind = 0;
	while (ind < i)
	{
		line[ind] = buffer[ind];
		ind++;
	}
	line[ind] = '\0';
	return (line);
}

char	*ft_rest_read(char *old_buffer)
{
	int		i;
	int		ind;
	char	*buff;

	if ((old_buffer[0] == '\0') || (!old_buffer)
		|| !ft_strchr((char *)old_buffer, '\n'))
	{
		buff = (char *) calloc(1, sizeof(char));
		if (!buff)
			return (NULL);
		return (buff);
	}
	i = (ft_strlen((const char *)old_buffer)
			- (ft_strchr((char *)old_buffer, '\n') - old_buffer + 1));
	buff = calloc((i + 1), sizeof(char));
	if (!buff)
		return (NULL);
	i = (ft_strchr((char *) old_buffer, '\n') - old_buffer);
	ind = 0;
	while (ind + i + 1 < ft_strlen((const char *)old_buffer))
	{
		buff[ind] = old_buffer[ind + i +1];
		ind++;
	}
	return (buff);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*old_buffer;
	char		*linea;

	if ((fd < 0) || (BUFFER_SIZE <= 0))
		return (NULL);
	buffer = ft_read(fd, buffer);
	if (!buffer)
		return (NULL);
	linea = ft_get_linea(buffer);
	if (!linea)
		return (NULL);
	old_buffer = buffer;
	buffer = ft_rest_read (buffer);
	free(old_buffer);
	if (!buffer)
		return (NULL);
	return (linea);
}
