/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iariss <iariss@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/05 15:05:45 by iariss            #+#    #+#             */
/*   Updated: 2021/06/06 18:04:44 by iariss           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "file.h"

void	reverse_rotate_a(t_list **head, t_stack *stack)
{
	t_list	*ho;
	t_list	*new_head;
	t_list	*before_last;

	ho = ft_lstlast(*head);
	new_head = ho;
	new_head->next = *head;
	*head = new_head;
	before_last = find_before_last(head, ho);
	before_last->next = NULL;
	ft_string_put("rra");
	stack->number_of_inst++;
}

void	sb_swapb(t_list **head, t_stack *stack)
{
	char	*s;

	if (stack->sizeb > 1)
	{
		s = head[0]->content;
		head[0]->content = (*head)->next->content;
		(*head)->next->content = s;
	}
	ft_string_put("sb");
	stack->number_of_inst++;
}

void	sa_swapa(t_list **head, t_stack *stack)
{
	char	*s;

	if (stack->sizea > 1)
	{
		s = head[0]->content;
		head[0]->content = (*head)->next->content;
		(*head)->next->content = s;
	}
	ft_string_put("sa");
	stack->number_of_inst++;
}

void	switch_tops(t_list **a, t_list **b, t_stack *stack)
{
	push_b(a, b, stack);
	sb_swapb(b, stack);
	push_a(a, b, stack);
}

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
