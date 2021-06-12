/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iariss <iariss@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/05 18:28:33 by iariss            #+#    #+#             */
/*   Updated: 2021/06/07 15:03:50 by iariss           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "file.h"

void	check_for_doubles(char **all, t_list **a, t_stack *stack)
{
	int	j;
	int	i;

	i = 0;
	j = 0;
	stack->number_of_inst = 0;
	while (all[i])
	{
		j = 0;
		j = i + 1;
		while (all[j])
		{
			if (ft_atoi(all[i]) == ft_atoi(all[j]))
			{
				error("Error\nDouble number");
				free_and_ex(a);
			}
			j++;
		}
		i++;
	}
}

void	find_big_and_small(char **all, t_srav *vars, t_stack *stack, int *big)
{
	while (all[vars->h])
	{
		if (ft_atoi(all[vars->h]) > ft_atoi(vars->biggest))
		{
			vars->biggest = all[vars->h];
		}
		vars->h++;
	}
	*big = ft_atoi(vars->biggest);
	vars->fixed[0] = vars->biggest;
	vars->kk = vars->h;
	vars->h = 0;
	while (vars->h < vars->kk && all[vars->h])
	{
		if (all[0] && all[vars->h])
		{
			if (ft_atoi(all[vars->h]) < ft_atoi(vars->smallest))
			{
				vars->smallest = all[vars->h];
				stack->indicate = vars->h;
			}
		}
		vars->h++;
	}
}

int	meth(char **all, t_stack *stack)
{
	int	i;

	i = stack->topa / 3;
	i = ft_atoi(all[i]);
	return (i);
}

void	rest_sorted(t_vars *vars, t_stack *stack, t_list **a, t_list **b)
{
	vars->s = 0;
	while (stack->topa > 0)
	{
		find_mid(a, stack, vars, &vars->mid);
		if (stack->indicate <= stack->topa / 2)
		{
			while (ft_atoi((*a)->content) > vars->smallest)
				rotate_a(a, stack);
		}
		else if (stack->indicate > stack->topa / 2)
		{
			while (ft_atoi((*a)->content) > vars->smallest)
				reverse_rotate_a(a, stack);
		}
		push_b(a, b, stack);
		free(stack->back1);
		free(stack->back2);
	}
}

void	to_a(t_vars *vars, t_stack *stack, t_list **a, t_list **b)
{
	while (stack->topb >= 0)
	{
		stack->tab = find_biggest(b, stack, &vars->biggest, stack->tab);
		if (stack->indicate <= stack->topb / 2)
		{
			while (ft_atoi((*b)->content) < vars->biggest)
				rotate_b(b, stack);
		}
		else if (stack->indicate > stack->topb / 2)
		{
			while (ft_atoi((*b)->content) < vars->biggest)
				reverse_rotate_b(b, stack);
		}
		push_a(a, b, stack);
	}
}
