/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabukirento <yabukirento@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 13:22:42 by yabukirento       #+#    #+#             */
/*   Updated: 2025/06/25 13:22:49 by yabukirento      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/hotrace.h"

char *str_dup(const char *s)
{
	int len = str_len(s);
	char *new = malloc(len + 1);
	if (!new)
		fatal_error();
	for (int i = 0; i <= len; i++)
		new[i] = s[i];
	return new;
}

int str_cmp(const char *s1, const char *s2)
{
	while (*s1 && *s2 && *s1 == *s2) {
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

int str_len(const char *s)
{
	int len = 0;
	while (s[len])
		len++;
	return len;
}

void fatal_error(void)
{
	write(2, "Fatal error\n", 12);
	exit(1);
}
