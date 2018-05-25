/*
** EPITECH PROJECT, 2018
** hashmap library
** File description:
** Inner function prototypes
*/

typedef unsigned long int hash_t;

#ifndef INNER_H_
	#define INNER_H_

	#include <stdlib.h>

void *my_calloc(size_t size);
int my_strlen(char const *str);
void my_memcpy(char *str1, char const *str2, int len);
hash_t hash(char const *key);


#endif /* !INNER_H_ */
