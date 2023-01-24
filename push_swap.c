/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avancoll <avancoll@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 16:58:36 by avancoll          #+#    #+#             */
/*   Updated: 2023/01/24 16:36:49 by avancoll         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	printer(t_list *stack_a, t_list *stack_b)
{
	printf("-------------------\nstack a\n");
	while (stack_a)
	{
		printf("%s\n", stack_a->content);
		stack_a = stack_a->next;
	}
	printf("-------------------\nstack b\n");
	while (stack_b)
	{
		printf("%s\n", stack_b->content);
		stack_b = stack_b->next;
	}
}

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;

	if (argc < 2)
		return (1);
	stack_a = parsing(argv);
	stack_b = NULL;
	push(&stack_b, &stack_a, PUSH_B);
	double_operation(&stack_a, &stack_b, SWAP_ALL);
	rotate(&stack_b, ROTATE_A);
	reverse_rotate(&stack_a, REVERSE_ROTATE_A);
	printer(stack_a, stack_b);
	return (0);
}
