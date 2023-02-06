/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avancoll <avancoll@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 17:24:49 by avancoll          #+#    #+#             */
/*   Updated: 2023/02/06 16:36:03 by avancoll         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	radix(t_list **stack_a, t_list **stack_b, t_data data)
{
	int	i;
	int	j;

	i = 0;
	while (i < data.max_bits)
	{
		j = 0;
		while (j < data.size)
		{
			if ((((*stack_a)->value >> i) & 1) == 0)
				push(stack_a, stack_b, PUSH_B);
			else
				rotate(stack_a, ROTATE_A);
			j++;
		}
		while (*stack_b)
			push(stack_b, stack_a, PUSH_A);
		i++;
	}
}

void	sort_two(t_list **stack_a)
{
	if ((*stack_a)->value > (*stack_a)->next->value)
		swap(stack_a, SWAP_A);
}

void	sort_three(t_list **stack_a, int max)
{
	if ((*stack_a)->value == max)
		rotate(stack_a, ROTATE_A);
	else if ((*stack_a)->next->value == max)
		reverse_rotate(stack_a, REVERSE_ROTATE_A);
	sort_two(stack_a);
}

void	sort_four(t_list **stack_a, t_list **stack_b, int min, int max)
{
	if ((*stack_a)->next->value == min)
		swap(stack_a, SWAP_A);
	else if ((*stack_a)->next->next->value == min)
	{
		rotate(stack_a, ROTATE_A);
		rotate(stack_a, ROTATE_A);
	}
	else if ((*stack_a)->next->next->next->value == min)
		reverse_rotate(stack_a, REVERSE_ROTATE_A);
	push(stack_a, stack_b, PUSH_B);
	sort_three(stack_a, max);
	push(stack_b, stack_a, PUSH_A);
}

void	sort_five(t_list **stack_a, t_list **stack_b)
{
	if ((*stack_a)->next->value == 0)
		swap(stack_a, SWAP_A);
	else if ((*stack_a)->next->next->value == 0)
	{
		rotate(stack_a, ROTATE_A);
		rotate(stack_a, ROTATE_A);
	}
	else if ((*stack_a)->next->next->next->value == 0)
	{
		reverse_rotate(stack_a, REVERSE_ROTATE_A);
		reverse_rotate(stack_a, REVERSE_ROTATE_A);
	}
	else if ((*stack_a)->next->next->next->next->value == 0)
		reverse_rotate(stack_a, REVERSE_ROTATE_A);
	push(stack_a, stack_b, PUSH_B);
	sort_four(stack_a, stack_b, 1, 4);
	push(stack_b, stack_a, PUSH_A);
}
