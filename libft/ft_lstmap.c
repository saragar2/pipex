/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saragar2 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 18:34:16 by saragar2          #+#    #+#             */
/*   Updated: 2023/10/21 00:31:27 by saragar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_lstclear_aux(t_list **new, t_list **val, void (*del)(void *))
{
	*val = (*new)->next;
	del((*new)->content);
	free(*new);
	*new = *val;
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*val;
	void	*content;

	if (!lst || !f || !del)
		return (0);
	new = NULL;
	while (lst)
	{
		content = f(lst->content);
		val = ft_lstnew(content);
		if (!val)
		{
			del(content);
			while (new)
				ft_lstclear_aux(&new, &val, del);
			lst = NULL;
			return (0);
		}
		ft_lstadd_back(&new, val);
		lst = lst->next;
	}
	return (new);
}
