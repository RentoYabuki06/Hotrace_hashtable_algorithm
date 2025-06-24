/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabukirento <yabukirento@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 13:21:04 by yabukirento       #+#    #+#             */
/*   Updated: 2025/06/25 13:21:12 by yabukirento      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/hotrace.h"

t_entry *hash_table[TABLE_SIZE] = {0};

static char *read_line(char *buf, int *index, int bufsize) {
	int start = *index;
	if (start >= bufsize)
		return NULL;
	while (*index < bufsize && buf[*index] != '\n')
		(*index)++;
	if (*index == start)
		return NULL;
	buf[(*index)++] = 0;
	return buf + start;
}

int	main(void)
{
	char	buffer[BUFFER_SIZE];
	int		n = read(0, buffer, BUFFER_SIZE);
	if (n <= 0)
		fatal_error();
	int		i = 0;

	// Insert phase
	while (i < n) {
		char *key = read_line(buffer, &i, n);
		if (!key || *key == 0) break;
		char *value = read_line(buffer, &i, n);
		if (!value) break;
		insert(key, value);
	}

	// Search phase
	while (i < n) {
		char *query = read_line(buffer, &i, n);
		if (!query || *query == 0) continue;
		char *result = search(query);
		if (result) {
			write(1, result, str_len(result));
			write(1, "\n", 1);
		} else {
			write(1, query, str_len(query));
			write(1, " Not found.\n", 12);
		}
	}

	free_table();
	return (0);
}
