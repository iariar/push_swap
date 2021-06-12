/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cases.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iariss <iariss@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 16:02:53 by iariss            #+#    #+#             */
/*   Updated: 2021/06/07 18:08:13 by iariss           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "file.h"

void	ten2(t_stack *stack, t_list **a, t_list **b)
{
	if (!check_order(a, stack, stack->topa))
	{
		if (ft_atoi((*a)->content) > ft_atoi((*a)->next->content))
			sa_swapa(a, stack);
		while (stack->topb >= 0)
			push_a(a, b, stack);
	}
	else
	{
		while (stack->topb >= 0)
			push_a(a, b, stack);
	}
}

void	ten(t_vars *vars, t_stack *stack, t_list **a, t_list **b)
{
	while (stack->topa > 2)
	{
		find_mid(a, stack, vars, &vars->mid);
		vars->save = stack->back1;
		if (stack->indicate <= stack->sizea / 2)
		{
			while (ft_atoi((*a)->content) > vars->smallest)
				rotate_a(a, stack);
		}
		else if (stack->indicate > stack->sizea / 2)
		{
			while (ft_atoi((*a)->content) > vars->smallest)
				reverse_rotate_a(a, stack);
		}
		push_b(a, b, stack);
		free(stack->back1);
		free(stack->back2);
	}
	ten2(stack, a, b);
}

void	four(t_list **a, t_stack *stack)
{
	while (!check_order(a, stack, stack->topa))
	{
		if (ft_atoi((*a)->content) > ft_atoi((*a)->next->content))
			sa_swapa(a, stack);
		else
			reverse_rotate_a(a, stack);
	}
}

void	two_fifty(t_vars *vars, t_stack *stack, t_list **a, t_list **b)
{
	vars->k = 10;
	while (vars->k > 0)
	{
		vars->top = stack->topa;
		vars->bcl = vars->top / 5;
		find_mid(a, stack, vars, &vars->mid);
		vars->save = stack->back1;
		while (vars->bcl)
		{
			vars->num = ft_atoi((*a)->content);
			if (vars->num < vars->mid)
			{
				push_b(a, b, stack);
				vars->bcl--;
			}
			else
				rotate_a(a, stack);
		}
		free(stack->back1);
		free(stack->back2);
		vars->k--;
	}
	rest_sorted(vars, stack, a, b);
	to_a(vars, stack, a, b);
}
