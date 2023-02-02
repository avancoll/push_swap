/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avancoll <avancoll@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 14:50:24 by avancoll          #+#    #+#             */
/*   Updated: 2023/02/02 15:48:25 by avancoll         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*free_list(t_list *stack_a)
{
	t_list	*temp;

	while (stack_a)
	{
		temp = stack_a;
		stack_a = stack_a->next;
		free(temp);
		temp = NULL;
	}
	return (NULL);
}

t_list	*parsing(char **argv, t_data *data)
{
	t_list	*stack_a;
	t_list	*new;
	int		i;

	i = 1;
	stack_a = ft_lstnew(ft_atoi(argv[i]));
	if (!stack_a)
		return (NULL);
	stack_a->value = 0;
	while (argv[++i])
	{
		new = ft_lstnew(ft_atoi(argv[i]));
		if (!new)
			return (free_list(stack_a));
		new->value = 0;
		ft_lstadd_back(&stack_a, new);
	}
	data->size = i - 1;
	return (stack_a);
}

int	is_double(t_list *stack_a)
{
	t_list	*temp;

	while (stack_a->next)
	{
		temp = stack_a->next;
		while (temp)
		{
			if (stack_a->content == temp->content)
			{
				free_list(stack_a);
				return (1);
			}
			temp = temp->next;
		}
		stack_a = stack_a->next;
	}
	return (0);
}

void	transform(t_list *stack_a, t_data *data)
{
	t_list	*temp1;
	t_list	*temp2;
	int		max;

	temp1 = stack_a;
	max = temp1->value;
	while (temp1)
	{
		temp2 = stack_a;
		while (temp2)
		{
			if (temp2->content < temp1->content)
				++temp1->value;
			if (max < temp2->value)
				max = temp2->value;
			temp2 = temp2->next;
		}
		temp1 = temp1->next;
	}
	data->max_bits = 1;
	while (max && data->max_bits++)
		max /= 2;
}
