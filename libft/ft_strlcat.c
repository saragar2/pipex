/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saragar2 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 21:14:50 by saragar2          #+#    #+#             */
/*   Updated: 2023/10/09 20:18:32 by saragar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	len;
	size_t	dlen;

	len = 0;
	dlen = 0;
	while (*dst && dlen < dstsize)
	{
		dst++;
		dlen++;
	}
	if (dlen == dstsize)
	{
		while (*src++)
			len++;
		return (dlen + len);
	}
	while (*src && dlen < dstsize - 1)
	{
		*dst++ = *src++;
		dlen++;
	}
	*dst = '\0';
	while (*src++)
		len++;
	return (dlen + len);
}
/*int main()
{
    char dst[14] = "a";
    const char src[] = "lorem ipsum dolor sit amet";

	// size_t total_length = strlcat(dst, src, 15);
	size_t total_length = ft_strlcat(dst, src, 15);

    printf("Cadena destino: %s\n", dst);
    printf("Longitud total: %zu\n", total_length);
    return 0;
}*/
