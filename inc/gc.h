/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gc.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipuig-pa <ipuig-pa@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 16:52:18 by ipuig-pa          #+#    #+#             */
/*   Updated: 2025/03/12 18:09:49 by ipuig-pa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GC_H
# define GC_H

# include <stddef.h>

typedef struct s_gc_list
{
	void				*allocated;
	struct s_gc_list	*next;
}						t_gc_list;

void		*gc_malloc(size_t size);
void		*gc_realloc(void *ptr, size_t old, size_t new);
t_gc_list	**get_gc_list(void);
void		gc_malloc_error(void);
void		add_gc_list(void *new_alloc);
void		gc_free(void *free_ptr);
void		free_double_pointer(char **str);
void		gc_clean(void);
char		**gc_split(char const *s, char c);
char		*gc_strdup(const char *s1);
char		*gc_strjoin(char const *s1, char const *s2);
char		*gc_substr(char const *s, unsigned int start, size_t len);
char		*gc_strtrim(char const *s1, char const *set);
char		*gc_itoa(int n);

#endif