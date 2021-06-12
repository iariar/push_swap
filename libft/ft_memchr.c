/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iariss <iariss@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/20 18:50:15 by iariss            #+#    #+#             */
/*   Updated: 2021/05/14 12:31:36 by iariss           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;
	char	*b;

	b = (char *)s;
	i = 0;
	while (i < n)
	{
		if (b[i] == c)
			return (b + i);
		i++;
	}
	return (NULL);
}
