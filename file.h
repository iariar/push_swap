/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iariss <iariss@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 11:03:18 by iariss            #+#    #+#             */
/*   Updated: 2021/06/05 18:41:41 by iariss           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILE_H
# define FILE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "libft/libft.h" 
#include <limits.h>

typedef struct s_stack
{
    int topa;
    int topb;
    int sizea;
    int sizeb;
    int number_of_inst;
    int indicate;
    char **back1;
    char **back2;
    t_list *replica;
    char    **tab;
}               t_stack;

typedef struct s_vars
{
    int mid;
    int biggest;
    int smallest;
    int top;
    int k;
    int num;
    char **save;
    int bcl;
    int s;
}               t_vars;

typedef struct s_srav
{
    char **fixed;
    int i;
    int j;
    int k;
    int h;
    char *biggest;
    char *smallest;
    int cursed;
    int kk;
}               t_srav;

int check_order(t_list **list, t_stack *stack, int top);
int meth(char **all, t_stack *stack);
void    error(char *s);
void    free_and_ex(t_list **list);
void    initialize_vars(t_stack *stack, int c);
void    initialise_vars(t_stack *stack, t_vars *vars);
void    initialize_vars2(t_srav *vars, char **all, t_stack *stack);
void    check_arg(char *s, t_list **head);
void    push_b(t_list **a, t_list **b, t_stack *stack);
void    push_a(t_list **a, t_list **b, t_stack *stack);
void    rotate_b(t_list **head, t_stack *stack);
void    rotate_a(t_list **head, t_stack *stack);
void    reverse_rotate_b(t_list **head, t_stack *stack);
void    reverse_rotate_a(t_list **head, t_stack *stack);
void    sb_swapb(t_list **head, t_stack *stack);
void    sa_swapa(t_list **head, t_stack *stack);
void    switch_tops(t_list **a, t_list **b, t_stack *stack);
void    free_list(t_list **list);
void    ft_string_put(char *s);
void	check_for_doubles(char **all, t_list **a, t_stack *stack);
void	to_a(t_vars *vars, t_stack *stack, t_list **a, t_list **b);
void	rest_sorted(t_vars *vars, t_stack *stack, t_list **a, t_list **b);
void	switch_by_mid(t_vars *vars, t_stack *stack, t_list **a, t_list **b);
void	find_big_and_small(char **all, t_srav *vars, t_stack *stack, int *big);
void	find_mid(t_list **a, t_stack *stack, t_vars *vars, int *mid);
char    **find_biggest(t_list **list, t_stack *stack, int *b, char **tab);
char	**operate(t_list **a, t_list **b, t_stack *stack);
t_list  *find_before_last(t_list **head, t_list *last);
t_list  *initialize_a(int c, t_list *a, t_list *yo, char **v, t_stack *stack);


#endif
