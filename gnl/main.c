/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jconde-a <jconde-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 19:16:46 by paescano          #+#    #+#             */
/*   Updated: 2023/10/15 20:15:50 by jconde-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

#include <unistd.h>

void imprimirCadena(const char *cadena) {
    // Verifica si el puntero es NULL.
    if (cadena == NULL) {
        const char *mensaje = "(null)\n";
        write(STDOUT_FILENO, mensaje, strlen(mensaje));
    } else {
        // Itera sobre la cadena hasta encontrar el carácter nulo.
        for (int i = 0; cadena[i] != '\0'; i++) {
            // Escribe cada carácter en la salida estándar (pantalla).
            write(STDOUT_FILENO, &cadena[i], 1);
        }
    }
}

int	main(void)
{
	char	*str;
	int		fd;

	fd = open("prueba", O_RDONLY);
	str = get_next_line(fd);
//	printf("resultado:%s", str);
	imprimirCadena (str);
	//system("sleep 1");
	while (str)
	{
		str = get_next_line(fd);
//		printf("resultado:%s", str);
		imprimirCadena (str);
	//	system("sleep 1");
	}
	close (fd);
}
