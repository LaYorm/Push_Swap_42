/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yorimek <yorimek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 15:52:44 by yorimek           #+#    #+#             */
/*   Updated: 2026/01/13 19:09:42 by yorimek          ###   ########.fr       */
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
	struct s_stack	*next;
	struct s_stack	*prev;
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
void	ft_swap_a(t_stack *stack_a);
void	ft_swap_b(t_stack *stack_b);
void	ft_s_swap(t_stack *stack_a, t_stack *stack_b);

/*---------push.c-------------*/
void	ft_push_a(t_stack **stack_a, t_stack **stack_b);
void	ft_set_b_after_extract(t_stack **stack_b);
void	ft_push_b(t_stack **stack_a, t_stack **stack_b);
void	ft_set_a_after_extract(t_stack **stack_a);

#endif