/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saragar2 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 16:56:29 by saragar2          #+#    #+#             */
/*   Updated: 2023/09/21 20:53:20 by saragar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	char	*aux;

	aux = (char *) b;
	while (len > 0)
	{
		*aux = c;
		aux++;
		len--;
	}
	return (b);
}
/*int	main()
{
	char buffer[20];

	ft_memset(buffer, 'A', 23);
	printf("Buffer: %s\n", buffer);
}*/
