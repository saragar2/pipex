/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saragar2 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 20:19:54 by saragar2          #+#    #+#             */
/*   Updated: 2023/10/19 18:55:12 by saragar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;

	if (count == 0 || size == 0)
	{
		ptr = (void *)malloc(0);
		return (ptr);
	}
	ptr = malloc(count * size);
	if (ptr == NULL)
		return (NULL);
	ft_memset(ptr, 0, count * size);
	return (ptr);
}
/*int main()
{
    size_t count = 5;
    size_t size = sizeof(int);
    int* arr = (int*)ft_calloc(count, size);

    if (arr != NULL)
	{
		free(arr);
    }
	else
	{
        printf("Error: No se pudo asignar memoria.\n");
    }

    return 0;
}*/
