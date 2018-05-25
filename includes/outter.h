/*
** EPITECH PROJECT, 2018
** 42sh
** File description:
** Header for hasmap utilities
*/

typedef unsigned long int hash_t;
typedef struct hashmap hashmap_t;
typedef struct hashmap hashmap_elem_t;
typedef struct hashmap hm_elem_t;

#ifndef HASHMAP_H_
	#define HASHMAP_H_

struct hashmap {
	char *key;
	void *data;
	struct hashmap *next;
	struct hashmap *prev;
	hash_t hash;
};

hash_t hashmap_hash(char const *key);

int hashmap_has(struct hashmap *map, const char *key);
int hashmap_del(struct hashmap **map, const char *key, void (*fr)(void *));
int hashmap_add(struct hashmap **map, const char *key, void *data);
void *hashmap_get(struct hashmap *map, const char *key);

#endif /* !HASHMAP_H_ */
