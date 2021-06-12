/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iariss <iariss@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/19 16:48:10 by iariss            #+#    #+#             */
/*   Updated: 2021/05/14 12:36:20 by iariss           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	s;
	size_t	d;

	s = ft_strlen(src);
	if (dst == NULL)
		return (size + s);
	d = ft_strlen(dst);
	j = d;
	if (size == 0)
		return (s);
	i = 0;
	if (size < d)
		return (size + s);
	while (j < (size - 1) && i < s)
	{
		dst[j] = src[i];
		i++;
		j++;
	}
	dst[j] = '\0';
	return (d + s);
}
