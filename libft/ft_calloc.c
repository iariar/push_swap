/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iariss <iariss@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/20 19:20:40 by iariss            #+#    #+#             */
/*   Updated: 2021/05/14 12:15:54 by iariss           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void				*b;
	unsigned long		i;

	i = 0;
	b = malloc(size * count);
	if (!b)
		return (NULL);
	while (i < count * size)
	{
		((char *)b)[i] = 0;
		i++;
	}
	return (b);
}
