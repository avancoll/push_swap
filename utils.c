/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avancoll <avancoll@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 15:31:08 by avancoll          #+#    #+#             */
/*   Updated: 2023/01/23 16:06:00 by avancoll         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_atoi(const char *str)
{
	int						i;
	unsigned long long		res;
	int						sign;
	int						temp;

	i = 0;
	res = 0;
	sign = 1;
	temp = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-' || str[i] == '+')
		if (str[i++] == '-')
			sign = -sign;
	while (str[i] == '0')
		i++;
	while (str[i] && str[i] >= '0' && str[i] <= '9' && ++temp)
		res = res * 10 + str[i++] - 48;
	if ((res >= 9223372036854775807 || temp >= 20) && sign == 1)
		return (-1);
	else if ((res > 9223372036854775807 || temp >= 20) && sign == -1)
		return (0);
	return (res * sign);
}