/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avancoll <avancoll@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 16:58:36 by avancoll          #+#    #+#             */
/*   Updated: 2023/02/01 18:09:44 by avancoll         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_list *stack_a)
{
	while (stack_a->next)
	{
		if (stack_a->next->content > stack_a->content)
			stack_a = stack_a->next;
		else
			return (0);
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;
	t_data	data;

	if (argc < 3)
		return (0);
	stack_a = parsing(argv, &data);
	stack_b = NULL;
	if (is_sorted(stack_a))
		return (0);
	transform(stack_a, &data);
	radix(&stack_a, &stack_b, data);
	return (0);
}
