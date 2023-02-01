/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avancoll <avancoll@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 16:58:36 by avancoll          #+#    #+#             */
/*   Updated: 2023/02/01 16:07:56 by avancoll         ###   ########.fr       */
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

void	value_print(t_list *stack_a, t_list *stack_b)
{
	printf("-------------------\nstack a\n");
	while (stack_a)
	{
		printf("%d\n", stack_a->value);
		stack_a = stack_a->next;
	}
	printf("-------------------\nstack b\n");
	while (stack_b)
	{
		printf("%d\n", stack_b->value);
		stack_b = stack_b->next;
	}
}

int	is_sorted(t_list *stack_a)
{
	while (stack_a->next)
	{
		if (stack_a->next->content > stack_a->content)
			stack_a = stack_a->next;
		else
			return (0);
	}
	// write(2, "Error\n", 6);
	return (1);
}

int	radix(t_list **stack_a, t_list **stack_b, t_data data)
{
	int	i = 0;
	int	max_bits = 1;
	while (i < data.step)
	{
		data.index = 0;
		while (data.index < data.size)
		{
			if (((*stack_a)->value & max_bits) == 0)
				push(stack_a, stack_b, PUSH_B);
			else
				rotate(stack_a, ROTATE_A);
			data.index++;
		}
		while (*stack_b)
				push(stack_b, stack_a, PUSH_A);
		if (is_sorted(*stack_a))
			return (0);
		max_bits *= 2;
		i++;
	}
	return (0);
}


void	transform(t_list *stack_a)
{
	t_list	*temp1;
	t_list	*temp2;

	temp1 = stack_a;
	while (temp1)
	{
		temp2 = stack_a;
		while (temp2)
		{
			if (temp2->content < temp1->content)
				++temp1->value;
			temp2 = temp2->next;
		}
		temp1 = temp1->next;
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
	if (is_sorted(stack_a))
		return (1);
	transform(stack_a);
	// value_print(stack_a, stack_b);
	radix(&stack_a, &stack_b, data);
	// printer(stack_a, stack_b);
	return (0);
}
