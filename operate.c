/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operate.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iariss <iariss@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/05 18:30:15 by iariss            #+#    #+#             */
/*   Updated: 2021/06/05 18:40:25 by iariss           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "file.h"

char	**operate(t_list **a, t_list **b, t_stack *stack)
{
	t_vars	vars;

	initialise_vars(stack, &vars);
	switch_by_mid(&vars, stack, a, b);
	rest_sorted(&vars, stack, a, b);
	to_a(&vars, stack, a, b);
	return (stack->tab);
}

void	switch_by_mid(t_vars *vars, t_stack *stack, t_list **a, t_list **b)
{
	while (vars->k > 0)
	{
		vars->top = stack->topa;
		vars->bcl = vars->top / 3;
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
			{
				rotate_a(a, stack);
			}
		}
		free(stack->back1);
		free(stack->back2);
		vars->k--;
	}
}

char	**find_biggest(t_list **list, t_stack *stack, int *b, char **tab)
{
	t_list	*replica;
	int		i;
	char	*biggest;

	replica = *list;
	i = 0;
	while (replica)
	{
		tab[i] = replica->content;
		replica = replica->next;
		i++;
	}
	tab[i] = NULL;
	biggest = tab[0];
	i = 0;
	while (tab[i])
	{
		if (ft_atoi(tab[i]) > ft_atoi(biggest))
		{
			biggest = tab[i];
			stack->indicate = i;
		}
		i++;
	}
	*b = ft_atoi(biggest);
	return (tab);
}

int	check_order(t_list **list, t_stack *stack, int top)
{
	char	**all;
	int		i;

	stack->replica = *list;
	i = 0;
	all = (char **)malloc(sizeof(char *) * (top + 1));
	while (stack->replica)
	{
		all[i] = stack->replica->content;
		stack->replica = stack->replica->next;
		i++;
	}
	all[i] = NULL;
	i = 0;
	while (all[i] && i < stack->sizea)
	{
		if (all[i + 1] && ft_atoi(all[i]) < ft_atoi(all[i + 1]))
		{
			free(all);
			return (0);
		}
		i++;
	}
	free(all);
	return (1);
}