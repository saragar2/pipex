/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saragar2 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 19:51:44 by saragar2          #+#    #+#             */
/*   Updated: 2023/10/16 23:16:40 by saragar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*search;

	while (*s != '\0')
	{
		if (*s == (char)c)
		{
			search = (char *) s;
			return (search);
		}
		else
			s++;
	}
	if (*s == (char)c)
	{
		search = (char *) s;
		return (search);
	}
	return (NULL);
}
/*int main()
{
    const char *s = "Hola, mundo";
    char c = 'H';
    char *res = ft_strchr(s, c);

    if (res != NULL)
	{
		//unir las dos siguientes en una
        printf("Se encontró '%c' en la posición
		%ld de la cadena.\n", c, res - s);
    }
	else
	{
        printf("'%c' no se encontró en la cadena.\n", c);
    }

    return 0;
}*/
