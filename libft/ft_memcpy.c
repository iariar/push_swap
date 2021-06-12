/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iariss <iariss@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/19 19:13:27 by iariss            #+#    #+#             */
/*   Updated: 2021/05/14 12:32:19 by iariss           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stdio.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char	*c1;
	char	*c2;

	c1 = (char *)dst;
	c2 = (char *)src;
	if (n == 0 || (dst == src))
		return (dst);
	while (n--)
	{
		*c1 = *c2;
		c1++;
		c2++;
	}
	return (dst);
}
