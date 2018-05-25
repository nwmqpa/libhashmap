/*
** EPITECH PROJECT, 2018
** hashmap library
** File description:
** Utility functions for the hashmap library
*/

#include <stdlib.h>
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

void *my_calloc(size_t size)
{
	void *temp = malloc(size);
	unsigned int counter = 0;

	while (counter < size) {
		((char *)temp)[counter] = 0;
		counter++;
	}
	return (temp);
}

int my_strlen(char const *str)
{
	int i = 0;

	while (str[i])
		i++;
	return (i);
}

void my_memcpy(char *str1, char const *str2, int len)
{
	for (int i = 0; i < len; i++) {
		*str1 = *str2;
		++str1;
		++str2;
	}
}
