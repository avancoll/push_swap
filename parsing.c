/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avancoll <avancoll@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 14:50:24 by avancoll          #+#    #+#             */
/*   Updated: 2023/01/30 17:41:01 by avancoll         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*parsing(char **argv, t_data *data)
{
	t_list	*stack_a;
	t_list	*new;
	int		i;
	i = 1;
	stack_a = ft_lstnew(ft_atoi(argv[i]));
	data->max = stack_a->content;
	while (argv[++i])
	{
		new = ft_lstnew(ft_atoi(argv[i]));
		if (new->content > data->max)
			data->max = new->content;
		ft_lstadd_back(&stack_a, new);
	}
	data->size = i - 1;
	data->step = 1;
	while(data->max /= 2)
		data->step++;
	return (stack_a);
}
