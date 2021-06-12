/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iariss <iariss@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 15:03:07 by iariss            #+#    #+#             */
/*   Updated: 2021/06/07 18:13:59 by iariss           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "file.h"

int	meth2(char **all, t_stack *stack)
{
	int	i;

	i = stack->topa / 5;
	i = ft_atoi(all[i]);
	return (i);
}

int	meth3(char **all, t_stack *stack)
{
	int	i;

	i = stack->topa / 3;
	i = ft_atoi(all[i]);
	return (i);
}
