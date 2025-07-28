/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: penchoivanov <penchoivanov@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 15:58:19 by ipavlov           #+#    #+#             */
/*   Updated: 2025/02/12 14:08:13 by penchoivano      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct s_node
{
	int				x;
	int				index;
	struct s_node	*next_node;
}	t_node;

void	sa(t_node **stack_a);
void	sb(t_node **stack_b);
void	ss(t_node **stack_a, t_node **stack_b);
void	swap(t_node **stack);
void	pa(t_node **stack_a, t_node **stack_b);
void	pb(t_node **stack_a, t_node **stack_b);
void	ra(t_node **stack_a);
void	rb(t_node **stack_b);
void	rr(t_node **stack_a, t_node **stack_b);
void	rra(t_node **stack_a);
void	rrb(t_node **stack_b);
void	rrr(t_node **stack_a, t_node **stack_b);
void	populate_stack(int argc, char *argv[], t_node **stack_a);
t_node	*create_t_node(int value, int j);
void	add_t_node_back(t_node *temp_t_node, t_node **stack_a);
int		len_t_node(t_node **stack_a);
void	sort_stack(t_node **stack_a, t_node **stack_b);
void	ft_sort_small_two(t_node **stack_a);
void	ft_sort_small_three(t_node **stack_a);
void	ft_sort_small_four(t_node **stack_a, t_node **stack_b);
void	ft_sort_small_five(t_node **stack_a, t_node **stack_b);
int		find_min_num(t_node **stack);
int		find_max_num(t_node **stack);
void	move_min_num_b(t_node **stack_a, t_node **stack_b);
int		is_list_organised(t_node **stack);
void	sort_index(t_node **stack_a);
void	ft_quick_sort(t_node **stack_a, \
		t_node **stack_b, int t_node_length);
void	prepare_quick_sort(t_node **stack_a, \
		t_node **stack_b, int t_node_length);
int		*create_sort_arr(t_node **stack_a, int t_node_length);
void	check_argv(int argc, char *argv[]);
int		len_t_node(t_node **stack_a);
int		split_or_pass_argv(int argc, char **argv, char ***temp_argv, int *i);
int		ft_all_num(char *temp_argv);
int		ft_is_overflow(char *temp_argv);
int		ft_is_duplicate(char *temp_argv, char **entire_argv, int i);
void	ft_arr_free(char **argv);
long	ft_overflow_atoi(const char *nptr, int *overflow);
void	ft_putstr_fd(char *s, int fd);
void	ft_exit(void);
void	ft_error(void);
int		ft_atoi(const char *nptr);
char	**ft_split(char const *s, char c);
char	*ft_strdup(const char *s);
size_t	ft_strlen(const char *s);
char	*ft_substr(char const *s, unsigned int start, size_t len);
int		ft_isnum(int c);
void	ft_putendl_fd(char *s, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_redix_sort(t_node **stack_a, t_node **stack_b, int t_node_length);
int		*create_sort_arr(t_node **stack_a, int t_node_length);
void	free_stack(t_node *stack);

#endif
