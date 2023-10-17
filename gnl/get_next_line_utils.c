/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jconde-a <jconde-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 10:01:55 by jconde-a          #+#    #+#             */
/*   Updated: 2023/10/17 20:36:55 by jconde-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_copy(char *buffer)
{
	char	*copia;
	int		i;

	copia = malloc(sizeof(char) * (ft_strlen((const char *)buffer) + 1));
	if (!copia)
		return (NULL);
	i = 0;
	while (i < ft_strlen ((const char *)buffer))
	{
		copia[i] = buffer[i];
		i++;
	}
	copia[i] = '\0';
	return (copia);
}

void	ft_ini_reader(char *readed)
{
	int	i;

	i = 0;
	while (i < (BUFFER_SIZE + 1))
	{
		readed[i] = '\0';
		i++;
	}
}

char	*ft_strcat(char *buffer, char *readed)
{
	size_t	cont;
	size_t	i;
	char	*destino;

	destino = (char *)malloc(sizeof(char) * (ft_strlen((const char *) buffer)
				+ ft_strlen((const char *) readed) + 1));
	if (!destino)
		return (NULL);
	i = 0;
	while (buffer && buffer[i] != '\0')
	{
		destino[i] = buffer[i];
		i++;
	}
	cont = 0;
	while (readed[cont] != '\0')
	{
		destino[i] = readed[cont];
			i++;
			cont++;
	}
	destino[i] = '\0';
	return (destino);
}

char	*ft_strchr(char const *s, int c)
{
	char const	*p;
	int			i;

	if (!s)
		return (NULL);
	if (s[0]== '\0')
		return (NULL);
	p = s;
	i =0;
	while (p && i < 5)
	{
		if (p[i] == c)
		{
			return ((char *)&p[i]);			
		}
		i++;
	}
	if (p[i] == '\0')
		return (0);
	return (0);
}

int	ft_strlen(const char *str)
{
	int	len;

	len = 0;
	if (!str)
		return (0);
	while (*str != '\0')
	{
		len ++;
		str ++;
	}
	return (len);
}


