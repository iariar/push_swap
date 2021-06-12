/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iariss <iariss@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 16:48:03 by iariss            #+#    #+#             */
/*   Updated: 2021/05/14 12:38:06 by iariss           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	char	*b;
	size_t	i;

	if (s == NULL || start > ft_strlen(s))
		return (NULL);
	b = (char *)malloc(sizeof(char) * (len + 1));
	if (!b)
		return (NULL);
	i = 0;
	while (s[start] != '\0' && i < len && start < ft_strlen(s))
	{
		b[i] = s[start];
		i++;
		start++;
	}
	b[i] = '\0';
	return (b);
}
