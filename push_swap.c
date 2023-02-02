/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avancoll <avancoll@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 16:58:36 by avancoll          #+#    #+#             */
/*   Updated: 2023/02/02 15:46:30 by avancoll         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_list *stack_a)
{
	t_list	*temp;

	temp = stack_a;
	while (temp->next)
	{
		if (temp->next->content > temp->content)
			temp = temp->next;
		else
			return (0);
	}
	free_list(stack_a);
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
	if (is_double(stack_a))
		return (1);
	transform(stack_a, &data);
	radix(&stack_a, &stack_b, data);
	free_list(stack_a);
	return (0);
}
