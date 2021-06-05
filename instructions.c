/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iariss <iariss@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/05 15:03:52 by iariss            #+#    #+#             */
/*   Updated: 2021/06/05 15:54:22 by iariss           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "file.h"

void	push_b(t_list **a, t_list **b, t_stack *stack)
{
	t_list	*b_new_head;
	t_list	*a_new_head;

	if (stack->topa > -1 && stack->sizeb > stack->topb)
	{
		a_new_head = (*a)->next;
		b_new_head = *a;
		b_new_head->next = *b;
		*a = a_new_head;
		*b = b_new_head;
		stack->topb++;
		stack->topa--;
	}
	ft_string_put("pb");
	stack->number_of_inst++;
}

void	push_a(t_list **a, t_list **b, t_stack *stack)
{
	t_list	*b_new_head;
	t_list	*a_new_head;

	if (stack->topb > -1 && stack->sizea > stack->topa)
	{
		b_new_head = (*b)->next;
		a_new_head = *b;
		a_new_head->next = *a;
		*b = b_new_head;
		*a = a_new_head;
		stack->topa++;
		stack->topb--;
	}
	ft_string_put("pa");
	stack->number_of_inst++;
}

void	rotate_b(t_list **head, t_stack *stack)
{
	t_list	*ho;
	t_list	*new_head;

	ho = *head;
	new_head = (*head)->next;
	ft_lstadd_back(head, ho);
	(*head)->next = NULL;
	*head = new_head;
	ft_string_put("rb");
	stack->number_of_inst++;
}

void	rotate_a(t_list **head, t_stack *stack)
{
	t_list	*ho;
	t_list	*new_head;

	ho = *head;
	new_head = (*head)->next;
	ft_lstadd_back(head, ho);
	(*head)->next = NULL;
	*head = new_head;
	ft_string_put("ra");
	stack->number_of_inst++;
}

void	reverse_rotate_b(t_list **head, t_stack *stack)
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
	ft_string_put("rrb");
	stack->number_of_inst++;
}
