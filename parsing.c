/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avancoll <avancoll@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 14:50:24 by avancoll          #+#    #+#             */
/*   Updated: 2023/01/23 18:24:05 by avancoll         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*parsing(char **argv)
{
	t_list	*stack_a;
	t_list	*new;
	int		i;

	i = 1;
	stack_a = ft_lstnew(argv[i]);
	while (argv[++i])
	{
		new = ft_lstnew(argv[i]);
		ft_lstadd_back(&stack_a, new);
	}
	return (stack_a);
}
