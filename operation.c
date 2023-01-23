/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avancoll <avancoll@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 16:50:39 by avancoll          #+#    #+#             */
/*   Updated: 2023/01/23 18:56:36 by avancoll         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_list *stack, int event)
{
	t_list	temp;

	temp.content = stack->content;
	stack->content = stack->next->content;
	stack = stack->next;
	stack->content = temp.content;
	if (event == 1)
		write(1, "sa\n", 3);
	else if (event == 2)
		write(1, "sb\n", 3);
}

// void	push(t_list *stack1, t_list *stack2, int event)
// {
// 	t_list	temp;

// 	temp.content = ;
// }

void	rotate(t_list **stack) //A MODIFIER CAR PAS OPTI
{
	t_list	*new;
	t_list	*temp;

	temp = *stack;
	new = ft_lstnew((*stack)->content);
	temp->content = NULL;
	*stack = (*stack)->next;
	ft_lstadd_back(stack, new);
	printf("content: %s\n", (*stack)->content);
}

void	reverse_rotate(t_list *stack)
{
	t_list	*new;
	t_list	*temp;

	temp = stack;
	while (temp->next)
		temp = temp->next;
	new = ft_lstnew(temp->content);
	ft_lstadd_front(&stack, new);
}