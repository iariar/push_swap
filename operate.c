/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operate.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iariss <iariss@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/05 18:30:15 by iariss            #+#    #+#             */
/*   Updated: 2021/06/07 18:14:36 by iariss           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "file.h"

char	**operate(t_list **a, t_list **b, t_stack *stack)
{
	t_vars	vars;

	initialise_vars(stack, &vars);
	if (stack->sizea >= 10 && stack->sizea <= 250)
	{
		switch_by_mid(&vars, stack, a, b);
		rest_sorted(&vars, stack, a, b);
		to_a(&vars, stack, a, b);
	}
	else if (stack->sizea > 250)
		two_fifty(&vars, stack, a, b);
	else if (stack->sizea < 10 && stack->sizea >= 4)
		ten(&vars, stack, a, b);
	else
		four(a, stack);
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
				rotate_a(a, stack);
		}
		free(stack->back1);
		free(stack->back2);
		vars->k--;
	}
}

char	**find_biggest(t_list **list, t_stack *stack, int *b, char **tab)
{
	int		i;
	char	*biggest;

	stack->replica2 = *list;
	i = 0;
	while (stack->replica2)
	{
		tab[i] = stack->replica2->content;
		stack->replica2 = stack->replica2->next;
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

void	duplicate(char ***all, int top, t_stack *stack)
{
	int	i;

	i = 0;
	*all = (char **)malloc(sizeof(char *) * (top + 1));
	while (stack->replica)
	{
		(*all)[i] = stack->replica->content;
		stack->replica = stack->replica->next;
		i++;
	}
	(*all)[i] = NULL;
}

int	check_order(t_list **list, t_stack *stack, int top)
{
	char	**all;
	int		i;
	int		j;

	j = 0;
	stack->replica = *list;
	duplicate(&all, top, stack);
	i = 0;
	while (all[i])
	{
		j = i + 1;
		while (all[j])
		{
			if (ft_atoi(all[i]) > ft_atoi(all[j]))
			{
				free(all);
				return (0);
			}
			j++;
		}
		i++;
	}
	free(all);
	return (1);
}
