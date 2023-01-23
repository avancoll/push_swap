/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avancoll <avancoll@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 16:50:39 by avancoll          #+#    #+#             */
/*   Updated: 2023/01/23 17:51:33 by avancoll         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_a(t_list *stack_a) //exactement le meme pour stack_b
{
	t_list	temp;

	temp.content = stack_a->content;
	stack_a->content = stack_a->next->content;
	stack_a = stack_a->next;
	stack_a->content = temp.content;
}
void	push(t_list *stack1, t_list *stack2)
{

}