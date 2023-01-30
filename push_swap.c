/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avancoll <avancoll@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 16:58:36 by avancoll          #+#    #+#             */
/*   Updated: 2023/01/30 17:41:11 by avancoll         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	printer(t_list *stack_a, t_list *stack_b)
{
	printf("-------------------\nstack a\n");
	while (stack_a)
	{
		printf("%d\n", stack_a->content);
		stack_a = stack_a->next;
	}
	printf("-------------------\nstack b\n");
	while (stack_b)
	{
		printf("%d\n", stack_b->content);
		stack_b = stack_b->next;
	}
}

void	radix(t_list **stack_a, t_list **stack_b, t_data data)
{
	int	i = 0;
	int	bitwise = 1;
	while (i < data.step)
	{
		data.index = 0;
		while (data.index < data.size)
		{
			if (((*stack_a)->content & bitwise) == 0)
				push(stack_a, stack_b, PUSH_B);
			else
				rotate(stack_a, ROTATE_A);
			data.index++;
		}
		while (*stack_b)
				push(stack_b, stack_a, PUSH_A);
		bitwise *= 2;
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;
	t_data	data;

	if (argc < 2)
		return (1);
	stack_a = parsing(argv, &data);
	stack_b = NULL;
	radix(&stack_a, &stack_b, data);
	printer(stack_a, stack_b);
	printf("step: %d\n", data.step);
	return (0);
}
