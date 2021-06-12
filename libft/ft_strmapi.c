/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iariss <iariss@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 19:14:07 by iariss            #+#    #+#             */
/*   Updated: 2021/05/14 12:41:17 by iariss           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(const char *s, char (*f)(unsigned int, char))
{
	int		i;
	char	*b;

	i = 0;
	if (s == NULL || !f)
		return (NULL);
	while (s[i])
	{
		i++;
	}
	b = (char *)malloc(sizeof(char) * (i + 1));
	if (!b)
		return (NULL);
	i = 0;
	while (s[i])
	{
		b[i] = f(i, s[i]);
		i++;
	}
	b[i] = '\0';
	return (b);
}
