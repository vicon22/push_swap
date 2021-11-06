/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eveiled <eveiled@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 17:39:28 by eveiled           #+#    #+#             */
/*   Updated: 2021/11/05 17:39:28 by eveiled          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <limits.h>
/*libft's struct*/
typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;
/*libft's functions*/
t_list	*ft_lstnew(void *content);
void	ft_lstadd_front(t_list **lst, t_list *new);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstdelone(t_list *lst, void (*del)(void *));
void	ft_lstclear(t_list **lst, void (*del)(void *));
void	ft_lstiter(t_list *lst, void (*f)(void *));
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
size_t	ft_strlen(char *str);
void	ft_lst_dell_all(t_list *lst_a);
char	**ft_split(char const *s, char c);
char	*ft_substr(char const *s, unsigned int start, size_t len);
/*own functions*/
void	ft_check_argv(int argc, char **argv);
t_list	*ft_cr_list_a(int argc, char **argv);
int		ft_atoi(const char *str);
int		ft_check_duplicates(t_list *lst_a);
void	ft_sort_a(t_list **lst_a, t_list **lst_b);
void	ft_sort_b(t_list **lst_a, t_list **lst_b);
int		ft_check_sorted_b(t_list *lst_b);
void	ft_sort_small_array(t_list **lst_a, t_list **lst_b);
void	ft_sort_big_array(t_list **lst_a, t_list **lst_b);
int		ft_lstsize_modern(t_list *lst, int max);
/*functions for finding median*/
int		ft_find_median(t_list **lst_a, int min, int max);
/*operations functions*/
void	ft_swap_a(t_list **lst);
void	ft_swap_b(t_list **lst);
void	ft_swap_both(t_list **lst1, t_list **lst2);
void	ft_push_a(t_list **lst_2, t_list **lst_1);
void	ft_push_b(t_list **lst_1, t_list **lst_2);
void	ft_rotate_a(t_list **lst);
void	ft_rotate_b(t_list **lst);
void	ft_rotate_both(t_list **lst1, t_list **lst2);
t_list	*ft_lstpenult(t_list *lst);
void	ft_reverse_rotate_a(t_list **lst);
void	ft_reverse_rotate_b(t_list **lst);
void	ft_reverse_rotate_both(t_list **lst1, t_list **lst2);
/*sorting functions*/
int		ft_find_max(t_list **lst_b);
int		ft_find_min(t_list **lst_b);
int		find_elem(t_list **lst, int number);
t_list	*find_elem_by_index(t_list **lst, int index);
int		ft_find_suif_elems(t_list **lst_a, int min, int max, int median);
t_list	*ft_previous_last(t_list **lst_a, t_list *last);
int		ft_find_suif_elems_diff_side(t_list **lst_a, int min, int max,
			int median);
void	ft_push_between(t_list **lst_a, t_list **lst_b, int min, int max);
int		ft_find_place_in_a(t_list **lst_a, int current);
int		ft_count_less_step(t_list **lst_a, t_list **lst_b, t_list *current);
int		ft_count_less_index(t_list **lst_a, t_list **lst_b);
void	ft_rotate_all_b(t_list **lst_a, t_list **lst_b, int i_b);
void	ft_rotate_all_a(t_list **lst_a, t_list **lst_b, int current_value);
void	ft_rotate_a_b_together(t_list **lst_a, t_list **lst_b,
			int current_value, int i_b);
void	ft_push_back(t_list **lst_a, t_list **lst_b);

void	ft_finally_sort_a(t_list **lst_a);
void	ft_half_of_separator(t_list *saver, int median_half, t_list **lst_a,
			t_list **lst_b);
void	ft_separator(t_list **lst_a, t_list **lst_b,
			int max, int median);
void	ft_push_between_3(t_list **lst_a, t_list **lst_b, int min, int max);
void	ft_push_between_4(t_list **lst_a, t_list **lst_b, int min, int max);
void	ft_count_for_rotate_both(int *i_a, int *i_b,
			t_list **lst_a, t_list **lst_b);
void	ft_count_for_reverse_rotate_both(int *i_a, int *i_b,
			t_list **lst_a, t_list **lst_b);
/*add functions*/
void	show_all_list(t_list *list_a, t_list *list_b);
void	ft_free_all_split(char **all);

#endif
