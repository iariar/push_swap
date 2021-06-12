/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iariss <iariss@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/05 15:11:17 by iariss            #+#    #+#             */
/*   Updated: 2021/06/06 18:19:47 by iariss           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "file.h"

void	error(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		write(2, &s[i], 1);
		i++;
	}
	write(2, "\n", 1);
}

void	free_and_ex(t_list **list)
{
	while (*list)
	{
		(*list)->content = NULL;
		free(*list);
		*list = (*list)->next;
	}
	exit(1);
}

void	free_list(t_list **list)
{
	t_list	*next;

	while (*list)
	{
		free((*list)->content);
		(*list)->content = NULL;
		next = (*list)->next;
		free(*list);
		*list = next;
	}
	exit(0);
}

void	ft_string_put(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		write(1, &s[i], 1);
		i++;
	}
	write(1, "\n", 1);
}
