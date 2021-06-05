/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iariss <iariss@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/05 14:48:22 by iariss            #+#    #+#             */
/*   Updated: 2021/06/05 17:30:53 by iariss           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "file.h"

t_list	*initialize_a(int c, t_list *a, t_list *yo, char **v, t_stack *stack)
{
	int		k;
	int		i;
	char	**seb;
	int		s;
	int		count;

	s = 0;
	i = 0;
	k = 1;
	count = 0;
	while (k <= c - 1)
	{
		seb = ft_split(v[k], ' ');
		i = 0;
		while (seb[i])
		{
			if (!s)
			{
				check_arg(seb[i], &a);
				yo = ft_lstnew(seb[i]);
				a = yo;
				s = 1;
				count++;
			}
			else
			{
				check_arg(seb[i], &a);
				yo->next = ft_lstnew(seb[i]);
				yo = yo->next;
				count++;
			}
			i++;
		}
		free(seb);
		k++;
	}
	stack->topa = count;
	stack->sizeb = count;
	stack->sizea = count;
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
