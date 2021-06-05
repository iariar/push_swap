/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iariss <iariss@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 15:57:16 by iariss            #+#    #+#             */
/*   Updated: 2021/06/05 18:41:46 by iariss           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "file.h"

t_list	*find_before_last(t_list **head, t_list *last)
{
	t_list	*replica;

	replica = *head;
	while (replica->next != last)
	{
		replica = replica->next;
	}
	return (replica);
}

char	**put_in_place(char **all, int size, t_vars *varso, t_stack *stack)
{
	t_srav	vars;

	initialize_vars2(&vars, all, stack);
	find_big_and_small(all, &vars, stack, &varso->biggest);
	varso->smallest = ft_atoi(vars.smallest);
	while (vars.j < size)
	{
		vars.i = 0;
		while (vars.i < size)
		{
			if (all[vars.i] && vars.fixed[vars.j] && all[vars.i][0] != 'a')
			{
				if (ft_atoi(all[vars.i]) < ft_atoi(vars.fixed[vars.j]))
				{
					vars.fixed[vars.j] = all[vars.i];
					vars.cursed = vars.i;
				}
			}
			vars.i++;
		}
		all[vars.cursed] = "ameno";
		vars.j++;
		vars.fixed[vars.j] = vars.biggest;
	}
	vars.fixed[vars.j] = NULL;
	return (vars.fixed);
}

void	find_mid(t_list **a, t_stack *stack, t_vars *vars, int *mid)
{
	t_list	*replica;
	char	**all;
	char	**tmp;
	int		i;

	i = 0;
	replica = *a;
	all = (char **)malloc(sizeof(char *) * (stack->topa + 1));
	while (replica)
	{
		all[i] = replica->content;
		replica = replica->next;
		i++;
	}
	all[i] = NULL;
	stack->back1 = all;
	check_for_doubles(all, a, stack);
	tmp = put_in_place(all, stack->topa, vars, stack);
	*mid = meth(tmp, stack);
	stack->back2 = tmp;
}

void	check_arg(char *s, t_list **head)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if ((s[i] >= '0' && s[i] <= '9') || s[i] == '-')
			i++;
		else
		{
			error("Error\nBad character in arguments");
			free_and_ex(head);
		}
	}
	if (ft_atoi(s) == -1 && ft_strlen(s) > 9)
	{
		error("Error\nOut of int range");
		free_and_ex(head);
	}
}

int	main(int c, char **v)
{
	int		i;
	int		k;
	t_stack	stack;
	t_list	*yo;
	t_list	*a;
	t_list	*b;
	// char	**tab;

	i = c;
	k = 1;
	yo = NULL;
	a = NULL;
	b = NULL;
	initialize_vars(&stack, c);
	if (c > 1)
	{
		a = initialize_a(c, a, yo, v, &stack);
		if (check_order(&a, &stack, stack.topa))
		{
			free_list(&a);
			exit(0);
		}
		stack.tab = (char **)malloc(sizeof(char *) * (stack.topa + 1));
		stack.tab = operate(&a, &b, &stack);
		free_list(&a);
		free(stack.tab);
		return (0);
	}
	error("u forgot the argumments :)");
	return (1);
}
