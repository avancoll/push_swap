/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avancoll <avancoll@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 16:58:54 by avancoll          #+#    #+#             */
/*   Updated: 2023/02/06 17:38:47 by avancoll         ###   ########.fr       */
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
	int	max_bits;
	int	error;
}	t_data;

t_list	*ft_lstnew(int content);
t_list	*ft_lstlast(t_list *lst);
int		ft_lstsize(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstadd_front(t_list **lst, t_list *new);
t_list	*free_list(t_list *stack_a, int event);
t_list	*parsing(char **argv, t_data *data);
int		ft_atoi(const char *s, t_data *data);
void	swap(t_list **stack, int event);
void	push(t_list **stack1, t_list **stack2, int event);
void	rotate(t_list **stack, int event);
void	reverse_rotate(t_list **stack, int event);
void	double_operation(t_list **stack_a, t_list **stack_b, int event);
void	transform(t_list *stack_a, t_data *data);
int		is_sorted(t_list *stack_a);
int		is_double(t_list *stack_a);
void	sort_two(t_list **stack_a);
void	sort_three(t_list **stack_a, int max);
void	sort_four(t_list **stack_a, t_list **stack_b, int min, int max);
void	sort_five(t_list **stack_a, t_list **stack_b);
void	radix(t_list **stack_a, t_list **stack_b, t_data data);
void	algorithm(t_list **stack_a, t_list **stack_b, t_data data);

#endif