/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabukirento <yabukirento@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 13:21:52 by yabukirento       #+#    #+#             */
/*   Updated: 2025/06/25 13:22:02 by yabukirento      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/hotrace.h"

unsigned long hash(const char *str)
{
	unsigned long hash = 5381;
	int c;
	while ((c = *str++))
		hash = ((hash << 5) + hash) + c;
	return hash % TABLE_SIZE;
}

void insert(const char *key, const char *value)
{
	t_entry *new = malloc(sizeof(t_entry));
	if (!new)
		fatal_error();
	new->key = str_dup(key);
	new->value = str_dup(value);
	unsigned long idx = hash(key);
	new->next = hash_table[idx];
	hash_table[idx] = new;
}

char *search(const char *key)
{
	t_entry *entry = hash_table[hash(key)];
	while (entry) {
		if (str_cmp(entry->key, key) == 0)
			return entry->value;
		entry = entry->next;
	}
	return NULL;
}

void free_table(void)
{
	for (int i = 0; i < TABLE_SIZE; i++) {
		t_entry *entry = hash_table[i];
		while (entry) {
			t_entry *tmp = entry;
			entry = entry->next;
			free(tmp->key);
			free(tmp->value);
			free(tmp);
		}
	}
}
