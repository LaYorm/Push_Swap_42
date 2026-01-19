/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yorimek <yorimek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 15:52:44 by yorimek           #+#    #+#             */
/*   Updated: 2026/01/19 11:42:52 by yorimek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>

//-------------Attribution----------//
# define INT_MAX 2147483647
# define INT_MIN -2147483648

/*---------Structures-------------*/

typedef struct s_stack
{
	int				value;
	int				index;
	int				above_median;
	int				cost_a;
	int				cost_b;
	struct s_stack	*next;
	struct s_stack	*prev;
	struct s_stack	*target_node;
}	t_stack;

/*---------Utils.c-------------*/
int		ft_strlen(char *str);
char	*ft_strdup(char *str);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_join_arg(int argc, char **argv);

/*---------check_arg.c-------------*/
void	ft_valid_char(char *tab);
long	ft_atol(char *tab);
int		ft_is_duplicate(int n, t_stack *stack);
int		ft_check_symbol(char *tab);

/*---------initiate_stack.c-------------*/
void	ft_tab_to_stack(char **tab, t_stack **stack_a);
void	ft_initiate_stack(t_stack *new_node, int val);
void	ft_add_to_stack(char **tab, t_stack **stack, int val);
void	ft_get_stack_ready(int ac, char **av, t_stack **stack_a);

/*---------split.c-------------*/
int		ft_count_int(char *str);
void	ft_write_in_lign(char *tab, char *str, char sep, int *start_int);
int		ft_malloc_lign(char *str, char sep, char **tab, int nb_int);
char	**ft_split(char *str, char sep);
void	ft_free_split(char **tab, int lign);

/*---------free_and_error.c-------------*/
void	ft_error(char **tab, t_stack **stack);
void	ft_free_stack(t_stack **stack);

/*---------swap.c-------------*/
void	ft_swap(t_stack *stack);
void	ft_swap_a(t_stack *stack_a);
void	ft_swap_b(t_stack *stack_b);
void	ft_s_swap(t_stack *stack_a, t_stack *stack_b);

/*---------push.c-------------*/
void	ft_push_a(t_stack **stack_a, t_stack **stack_b);
void	ft_set_after_extract(t_stack **stack_b);
void	ft_push_b(t_stack **stack_a, t_stack **stack_b);

/*---------rotate.c-------------*/
void	ft_rotate(t_stack **stack);
void	ft_rotate_a(t_stack **stack_a);
void	ft_rotate_b(t_stack **stack_b);
void	ft_r_rotate(t_stack **stack_a, t_stack **stack_b);

/*---------reverse_rotate.c-------------*/
void	ft_reverse_rotate(t_stack **stack);
void	ft_reverse_rotate_a(t_stack **stack_a);
void	ft_reverse_rotate_b(t_stack **stack_b);
void	ft_r_reverse_rotate(t_stack **stack_a, t_stack **stack_b);

/*--------prepare_for_sort.c-------------*/
int		ft_stack_size(t_stack *stack);
void	ft_set_index(t_stack **stack);
void	ft_set_cost(t_stack **stack_a, int size_a, int size_b);
void	ft_median(t_stack **stack, int size_stack);

/*--------sort_small.c-------------*/
void	ft_sort_three(t_stack **stack_a);
int		ft_sort_small_pile(t_stack **stack_a, int size);
t_stack	*ft_find_max(t_stack *stack);

/*--------sort.c-------------*/
void	ft_sorting_algo(t_stack **stack_a, t_stack **stack_b);
void	ft_bring_min_to_top(t_stack **stack_a);
int		ft_a_to_b(t_stack **stack_a, t_stack **stack_b);
void	ft_b_to_a(t_stack **stack_a, t_stack **stack_b);

/*--------find_target_a.c-------------*/
void	ft_find_target_a(t_stack **stack_a, t_stack **stack_b, int size_stack);
void	ft_find_target_b(t_stack **stack_a, t_stack **stack_b, int size_stack);
t_stack	*ft_get_bigger_small(int value, t_stack *stack_b);
t_stack	*ft_is_extrem(int value, t_stack *stack_b);

/*--------find_target_b.c-------------*/
t_stack	*ft_get_smallest_big(int value, t_stack *stack);
void	ft_find_target_b(t_stack **stack_a, t_stack **stack_b, int size_stack);
t_stack	*ft_find_min(t_stack *stack);

/*---------find_cheapest.c-------------*/
long	ft_cost_if_median(t_stack *curr_node);
t_stack	*ft_find_cheapest(t_stack **stack_a, int size_a);

/*---------move_from_stack.c-------------*/
void	ft_mv_cheapest(t_stack **stack_a, t_stack **stack_b, t_stack *cheapest);
void	ft_move_to_a(t_stack **stack_a, t_stack **stack_b);

#endif