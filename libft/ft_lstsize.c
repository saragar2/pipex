/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saragar2 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 19:27:37 by saragar2          #+#    #+#             */
/*   Updated: 2023/10/13 12:07:50 by saragar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int		cont;
	t_list	*nodo;

	nodo = lst;
	cont = 0;
	if (!lst)
		return (0);
	while (nodo != NULL)
	{
		cont++;
		nodo = nodo -> next;
	}
	return (cont);
}
