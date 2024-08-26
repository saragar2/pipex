/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saragar2 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 19:34:19 by saragar2          #+#    #+#             */
/*   Updated: 2023/10/17 20:49:10 by saragar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	char	*search;
	void	*res;
	char	d;

	d = (char) c;
	search = (char *) s;
	while (n > 0)
	{
		if (*search == d)
		{
			res = (void *) search;
			return (res);
		}
		search++;
		n--;
	}
	return (NULL);
}
/*int main()
{
    const char *s = "Hola, mundo";
    char c = 'm';
    char *res = ft_memchr(s, c, 4);

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
