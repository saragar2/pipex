/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saragar2 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 21:32:53 by saragar2          #+#    #+#             */
/*   Updated: 2023/10/07 12:55:18 by saragar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	int		i;

	i = 0;
	while (s[i] != '\0')
	{
		f(i, (s + i));
		i++;
	}
}
/*
void	onemoreo(unsigned int i, char *s)
{
	if (i % 2 == 0)
		*s = 32;
}

int main(void)
{
    char cadena[] = "Hola, Mundo! Esta es una prueba.";
    printf("Cadena original: %s\n", cadena);
    ft_striteri(cadena, onemoreo);
    printf("Cadena modificada: %s\n", cadena);
    return 0;
}*/
