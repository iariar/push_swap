/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iariss <iariss@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 15:57:16 by iariss            #+#    #+#             */
/*   Updated: 2021/06/07 18:14:23 by iariss           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "file.h"

void	blob(t_srav *vars, char **all, t_stack *stack, int *biggest)
{
	initialize_vars2(vars, all, stack);
	find_big_and_small(all, vars, stack, biggest);
}

char	**put_in_place(char **all, int size, t_vars *varso, t_stack *stack)
{
	t_srav	vars;

	blob(&vars, all, stack, &varso->biggest);
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
	if (stack->sizea < 10)
		*mid = meth3(tmp, stack);
	else if (stack->sizea <= 250)
		*mid = meth(tmp, stack);
	else
		*mid = meth2(tmp, stack);
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
	if ((ft_atoi(s) == -1 && ft_strlen(s) >= 10)
		|| (ft_atoi(s) == 0 && ft_strlen(s) >= 10))
	{
		error("Error\nOut of int range");
		free_and_ex(head);
	}
}

int	main(int c, char **v)
{
	int		k;
	t_stack	stack;
	t_list	*a;
	t_list	*b;

	k = 1;
	stack.yo = NULL;
	a = NULL;
	b = NULL;
	if (c > 1)
	{
		a = initialize_a(c, a, v, &stack);
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
	error("ERROR\nU Forgot The Argumments :)");
	return (1);
}
