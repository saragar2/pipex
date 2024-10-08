/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saragar2 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 20:03:10 by saragar2          #+#    #+#             */
/*   Updated: 2024/10/08 20:03:13 by saragar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	f_strcmp(const char *s1, const char *s2)
{
	int	cont;

	cont = 0;
	while (*s1 == *s2 && *s1 != '\0')
	{
		s1++;
		s2++;
	}
	if (*s1 != *s2)
		cont = (unsigned char)*s1 - (unsigned char)*s2;
	return (cont);
}

void	free_split(char **split)
{
	int	i;

	i = -1;
	while (split[++i])
		free(split[i]);
	free(split);
}
