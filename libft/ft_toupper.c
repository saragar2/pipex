/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saragar2 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 19:31:22 by saragar2          #+#    #+#             */
/*   Updated: 2023/09/21 19:22:44 by saragar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		c -= 32;
	return (c);
}
/*int main()
{
    char letra = 'j';
    int mayuscula = toupper(letra);
	printf("La letra '%c' en mayúscula es '%c'\n", letra, mayuscula);
	mayuscula = ft_toupper(letra);
    printf("La letra '%c' en mayúscula es '%c'\n", letra, mayuscula);
	return (0);
}*/
