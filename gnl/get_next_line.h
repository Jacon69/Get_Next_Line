/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jconde-a <jconde-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 09:51:38 by jconde-a          #+#    #+#             */
/*   Updated: 2023/10/15 18:51:32 by jconde-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef    GET_NEXT_LINE_H
# define    GET_NEXT_LINE_H

# include <unistd.h>
# include <fcntl.h>  //Tiene la función Read
# include <stdio.h>
# include <stdlib.h>
# include <ctype.h>
# include <string.h>
# include <stddef.h>  // tiene los tippos

char	*get_next_line(int fd);
char	*ft_read(int fd, char *buffer);
char	*ft_get_linea(char *buffer);
char	*ft_rest_read(char *old_buffer);
int	    ft_strlen(const char *str);
char	*ft_strchr(const char *s, int c);
char	*ft_copy(char *buffer);
void	ft_ini_reader(char *readed);
char	*ft_strcat(char *buffer, char *readed);
#endif

#ifndef  BUFFER_SIZE
# define BUFFER_SIZE 2
#endif