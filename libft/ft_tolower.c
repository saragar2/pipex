/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saragar2 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 19:43:18 by saragar2          #+#    #+#             */
/*   Updated: 2023/09/21 19:22:15 by saragar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		c += 32;
	return (c);
}
/*int main()
{
    char letra = 'J';
    int minuscula = tolower(letra);
	printf("La letra '%c' en minuscula es '%c'\n", letra, minuscula);
	minuscula = ft_tolower(letra);
    printf("La letra '%c' en minuscula es '%c'\n", letra, minuscula);
	return (0);
}*/
