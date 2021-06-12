/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iariss <iariss@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/05 14:48:22 by iariss            #+#    #+#             */
/*   Updated: 2021/06/07 08:56:39 by iariss           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "file.h"

void	fill_list(t_list **a, t_list **yo, t_add *add)
{
	add->i = 0;
	while (add->seb[add->i])
	{
		if (!add->s)
		{
			check_arg(add->seb[add->i], a);
			*yo = ft_lstnew(add->seb[add->i]);
			*a = *yo;
			add->s = 1;
		}
		else
		{
			check_arg(add->seb[add->i], a);
			(*yo)->next = ft_lstnew(add->seb[add->i]);
			*yo = (*yo)->next;
		}
		add->count++;
		add->i++;
	}
}

t_list	*initialize_a(int c, t_list *a, char **v, t_stack *stack)
{
	t_add	add;

	add.s = 0;
	add.k = 1;
	add.count = 0;
	initialize_vars(stack, c);
	while (add.k <= c - 1)
	{
		add.seb = ft_split(v[add.k], ' ');
		fill_list(&a, &stack->yo, &add);
		free(add.seb);
		add.k++;
	}
	stack->topa = add.count;
	stack->sizeb = add.count;
	stack->sizea = add.count;
	return (a);
}

void	initialize_vars(t_stack *stack, int c)
{
	stack->sizea = c - 1;
	stack->topb = -1;
}

void	initialize_vars2(t_srav *vars, char **all, t_stack *stack)
{
	vars->i = 0;
	vars->k = 0;
	vars->j = 0;
	vars->h = 0;
	vars->cursed = 0;
	vars->fixed = (char **)malloc(sizeof(char *) * (stack->topa + 1));
	vars->biggest = all[0];
	vars->smallest = all[0];
	vars->h = 0;
}

void	initialise_vars(t_stack *stack, t_vars *vars)
{
	vars->biggest = 0;
	vars->smallest = 0;
	stack->number_of_inst = 0;
	stack->indicate = 0;
	vars->k = 5;
	vars->s = 0;
}
