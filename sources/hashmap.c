/*
** EPITECH PROJECT, 2018
** hashmap library
** File description:
** Hashmap lirary utils functions.
*/

#include "outter.h"
#include "inner.h"

hash_t hash(const char *str)
{
	unsigned long int hash = 5381;
	char c;

	while (*str) {
		c = *str;
		hash = ((hash << 5) + hash) + c;
		str++;
	}
	return (hash);
}

int has(struct hashmap *hashmap, const char *key)
{
	hash_t h = hash(key);

	for (struct hashmap *temp = hashmap; temp; temp = temp->next) {
		if (temp->hash == h)
			return (1);
	}
	return (0);
}

int del(struct hashmap **hashmap, const char *key, void (*free_it)(void *))
{
	hash_t h = hash(key);
	struct hashmap **temp = 0x0;

	if (*hashmap == 0x0)
		return (1);
	for (temp = hashmap; *temp; temp = &((*temp)->next)) {
		if ((*temp)->hash == h)
			break;
	}
	if (*temp == 0x0)
		return (1);
	free_it((*temp)->data);
	free((*temp)->key);
	if ((*temp)->next)
		(*temp)->next->prev = (*temp)->prev;
	if ((*temp)->prev)
		(*temp)->prev->next = (*temp)->next;
	return (0);
}

int add(struct hashmap **hashmap, const char *key, void *data)
{
	hash_t h = hash(key);
	struct hashmap **temp = 0x0;
	struct hashmap *temp_prev = 0x0;

	if (*hashmap == 0x0) {
		temp = hashmap;
	} else {
		for (temp = hashmap; (*temp); temp = &((*temp)->next))
			temp_prev = (*temp);
	}
	*temp = my_calloc(sizeof(struct hashmap));
	(*temp)->prev = temp_prev;
	(*temp)->next = 0x0;
	(*temp)->hash = h;
	(*temp)->data = data;
	(*temp)->key = my_calloc(my_strlen(key) + 1);
	my_memcpy((*temp)->key, key, my_strlen(key));
	return (0);
}

void *get(struct hashmap *hashmap, const char *key)
{
	hash_t h = hash(key);

	for (struct hashmap *temp = hashmap; temp; temp = temp->next) {
		if (temp->hash == h)
			return (temp->data);
	}
	return (0x0);
}
