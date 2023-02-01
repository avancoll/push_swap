/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avancoll <avancoll@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 17:24:49 by avancoll          #+#    #+#             */
/*   Updated: 2023/02/01 18:00:26 by avancoll         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	radix(t_list **stack_a, t_list **stack_b, t_data data)
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
	return (0);
}
