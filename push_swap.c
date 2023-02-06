/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avancoll <avancoll@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 16:58:36 by avancoll          #+#    #+#             */
/*   Updated: 2023/02/06 17:46:40 by avancoll         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	algorithm(t_list **stack_a, t_list **stack_b, t_data data)
{
	if (data.size == 2)
		sort_two(stack_a);
	else if (data.size == 3)
		sort_three(stack_a, 2);
	else if (data.size == 4)
		sort_four(stack_a, stack_b, 0, 3);
	else if (data.size == 5)
		sort_five(stack_a, stack_b);
	else
		radix(stack_a, stack_b, data);
}

int	one_arg(char *argv, t_data data)
{
	ft_atoi(argv, &data);
	if (!data.error)
		return (0);
	write(2, "Error\n", 7);
	return (1);
}

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;
	t_data	data;

	if (argc == 1)
		return (0);
	data.error = 0;
	if (argc == 2)
		return (one_arg(argv[1], data));
	stack_a = parsing(argv, &data);
	if (!stack_a)
		return (1);
	stack_b = NULL;
	if (is_sorted(stack_a))
		return (0);
	if (is_double(stack_a))
		return (1);
	transform(stack_a, &data);
	algorithm(&stack_a, &stack_b, data);
	free_list(stack_a, 0);
	return (0);
}
