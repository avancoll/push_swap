/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avancoll <avancoll@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 14:50:24 by avancoll          #+#    #+#             */
/*   Updated: 2023/02/06 17:45:55 by avancoll         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_atoi(const char *s, t_data *data)
{
	int						i;
	unsigned long long		res;
	int						sign;

	i = 0;
	res = 0;
	sign = 1;
	while ((s[i] >= 9 && s[i] <= 13) || s[i] == 32)
		i++;
	if (s[i] == '-' || s[i] == '+')
		if (s[i++] == '-')
			sign = -sign;
	if (!s[i])
		data->error = 1;
	while (s[i] == '0')
		i++;
	while (s[i] && s[i] >= '0' && s[i] <= '9')
		res = res * 10 + s[i++] - '0';
	if ((s[i] && (s[i] < '0' || s[i] > '9')) || (res > 2147483647 && sign == 1)
		|| (res > 2147483648 && sign == -1))
		data->error = 1;
	return (res * sign);
}

t_list	*parsing(char **argv, t_data *data)
{
	t_list	*stack_a;
	t_list	*new;
	int		i;

	i = 1;
	stack_a = ft_lstnew(ft_atoi(argv[i], data));
	if (!stack_a)
		return (NULL);
	stack_a->value = 0;
	while (argv[++i])
	{
		new = ft_lstnew(ft_atoi(argv[i], data));
		if (!new)
			return (free_list(stack_a, 1));
		new->value = 0;
		ft_lstadd_back(&stack_a, new);
	}
	data->size = i - 1;
	if (data->error)
		return (free_list(stack_a, 1));
	return (stack_a);
}

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
	free_list(stack_a, 0);
	return (1);
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
				free_list(stack_a, 1);
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
	data->max_bits = 0;
	while (max)
	{
		data->max_bits++;
		max /= 2;
	}
}
