/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hotrace.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabukirento <yabukirento@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 13:19:55 by yabukirento       #+#    #+#             */
/*   Updated: 2025/06/25 13:20:05 by yabukirento      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HOTRACE_H
# define HOTRACE_H

# define TABLE_SIZE 10007
# define BUFFER_SIZE 1000000

# include <unistd.h>
# include <stdlib.h>

typedef struct s_entry {
	char *key;
	char *value;
	struct s_entry *next;
} t_entry;

extern t_entry *hash_table[TABLE_SIZE];

// hash.c
unsigned long	hash(const char *str);
void			insert(const char *key, const char *value);
char			*search(const char *key);
void			free_table(void);

// utils.c
char	*str_dup(const char *s);
int		str_cmp(const char *s1, const char *s2);
int		str_len(const char *s);
void	fatal_error(void);

#endif
