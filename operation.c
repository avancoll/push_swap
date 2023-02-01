/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avancoll <avancoll@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 16:50:39 by avancoll          #+#    #+#             */
/*   Updated: 2023/02/01 16:08:21 by avancoll         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_list *stack, int event)
{
	t_list	temp;

	if (event == SWAP_A)
		write(1, "sa\n", 3);
	else if (event == SWAP_B)
		write(1, "sb\n", 3);
	if (!stack || !stack->next)
		return ;
	temp.content = stack->content;
	stack->content = stack->next->content;
	stack = stack->next;
	stack->content = temp.content;
}

void	push(t_list **stack1, t_list **stack2, int event)
{
	t_list	*temp1;
	t_list	*temp2;

	if (event == PUSH_A)
		write(1, "pa\n", 3);
	else if (event == PUSH_B)
		write(1, "pb\n", 3);
	if (!*stack1)
		return ;
	temp1 = *stack1;
	temp2 = *stack2;
	(*stack1) = (*stack1)->next;
	temp1->next = temp2;
	*stack2 = temp1;
}

void	rotate(t_list **stack, int event)
{
	t_list	*temp1;
	t_list	*temp2;

	if (event == ROTATE_A)
		write(1, "ra\n", 3);
	else if (event == ROTATE_B)
		write(1, "rb\n", 3);
	if (!*stack || !(*stack)->next)
		return ;
	temp1 = *stack;
	temp2 = *stack;
	*stack = (*stack)->next;
	while (temp2->next)
		temp2 = temp2->next;
	temp2->next = temp1;
	temp1->next = NULL;
}

void	reverse_rotate(t_list **stack, int event)
{
	t_list	*temp1;
	t_list	*temp2;

	if (event == REVERSE_ROTATE_A)
		write(1, "rra\n", 4);
	else if (event == REVERSE_ROTATE_B)
		write(1, "rrb\n", 4);
	if (!*stack)
		return ;
	temp1 = *stack;
	temp2 = *stack;
	while ((*stack)->next)
		*stack = (*stack)->next;
	while (temp2->next->next)
		temp2 = temp2->next;
	(*stack)->next = temp1;
	temp2->next = NULL;
}

void	double_operation(t_list **stack_a, t_list **stack_b, int event)
{
	if (event == SWAP_ALL)
	{
		swap(*stack_a, 0);
		swap(*stack_b, 0);
		write(1, "ss\n", 3);
	}
	else if (event == ROTATE_ALL)
	{
		rotate(stack_a, 0);
		rotate(stack_b, 0);
		write(1, "rr\n", 3);
	}
	else if (event == REVERSE_ROTATE_ALL)
	{
		reverse_rotate(stack_a, 0);
		reverse_rotate(stack_b, 0);
		write(1, "rrr\n", 4);
	}
}
