/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_handler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avancoll <avancoll@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 14:52:45 by avancoll          #+#    #+#             */
/*   Updated: 2023/02/06 16:40:27 by avancoll         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*ft_lstnew(int content)
{
	t_list	*res;

	res = malloc(sizeof(t_list));
	if (!res)
		return (NULL);
	res->content = content;
	res->next = NULL;
	return (res);
}

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

int	ft_lstsize(t_list *lst)
{
	int		res;
	t_list	*temp;

	res = 0;
	temp = lst;
	while (temp)
	{
		temp = temp->next;
		res++;
	}
	return (res);
}

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*temp;

	if (!lst)
		return ;
	if (!*lst)
		*lst = new;
	else
	{
		temp = *lst;
		ft_lstlast(temp)->next = new;
	}
}

t_list	*free_list(t_list *stack_a, int event)
{
	t_list	*temp;

	while (stack_a)
	{
		temp = stack_a;
		stack_a = stack_a->next;
		free(temp);
		temp = NULL;
	}
	if (event == 1)
		write(2, "Error\n", 7);
	return (NULL);
}
