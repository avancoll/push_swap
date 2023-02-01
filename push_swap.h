/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avancoll <avancoll@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 16:58:54 by avancoll          #+#    #+#             */
/*   Updated: 2023/02/01 17:49:23 by avancoll         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <stdio.h> // A EFFACER ATTENTION

# define SWAP_A 1
# define SWAP_B 2
# define SWAP_ALL 3
# define PUSH_A 4
# define PUSH_B 5
# define ROTATE_A 6
# define ROTATE_B 7
# define ROTATE_ALL 8
# define REVERSE_ROTATE_A 9
# define REVERSE_ROTATE_B 10
# define REVERSE_ROTATE_ALL 11

typedef struct s_list
{
	int				content;
	int				value;
	struct s_list	*next;
}					t_list;

typedef struct s_data
{
	int	size;
	int	max;
	int	max_bits;
}	t_data;

t_list	*ft_lstnew(int content);
t_list	*ft_lstlast(t_list *lst);
int		ft_lstsize(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstadd_front(t_list **lst, t_list *new);
void	ft_lstdelone(t_list *lst, void (*del)(void *));

t_list	*parsing(char **argv, t_data *data);
int		ft_atoi(const char *str);

void	swap(t_list *stack, int event);
void	push(t_list **stack1, t_list **stack2, int event);
void	rotate(t_list **stack, int event);
void	reverse_rotate(t_list **stack, int event);
void	double_operation(t_list **stack_a, t_list **stack_b, int event);
int		radix(t_list **stack_a, t_list **stack_b, t_data data);
void	transform(t_list *stack_a, t_data *data);
int		is_sorted(t_list *stack_a);

#endif