#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <myHashtab.h>

int collision = 0;
int mode = 0;

unsigned int hashtab_hash_KRHash(char* key)
{
    unsigned int h = 0, hash_mul = 31;
    while (*key)
        h = h * hash_mul + (unsigned int)*key++;
    return h % HASH_SIZE;
}

unsigned int hashtab_hash_ELFHash(char* key)
{
    unsigned int h = 0, g;
    while (*key) {
        h = (h << 4) + (unsigned int)*key++;
        g = h & 0xF0000000L;
        if (g)
            h ^= g >> 24;
        h &= ~g;
    }
    return h % HASH_SIZE;
}

unsigned int hashtab_hash_jen(char* key)
{
    unsigned int hash = 0, i;
    for (i = 0; key[i] != '\0'; i++) {
        hash += key[i];
        hash += (hash << 10);
        hash ^= (hash >> 6);
    }
    hash += (hash << 3);
    hash ^= (hash >> 11);
    hash += (hash << 15);
    return hash % HASH_SIZE;
}

unsigned int hashtab_hash_djb2(char* key)
{
    unsigned long hash = 5381;
    int c;
    while ((c = *key++))
        hash = ((hash << 5) + hash) + c;

    return hash % HASH_SIZE;
}

unsigned int hashtab_hash_fnvHash(char* key)
{
    const unsigned int fnv_prime = 0x811C9DC5;
    unsigned int hash = 0;
    unsigned int i = 0;
    unsigned int len = strlen(key);

    for (i = 0; i < len; i++) {
        hash *= fnv_prime;
        hash ^= (key[i]);
    }

    return hash % HASH_SIZE;
}

unsigned int hashtab_hash_function(char* key)
{
    unsigned int index = 0;
    if (mode == 0) {
        index = hashtab_hash_KRHash(key);
    } else if (mode == 1) {
        index = hashtab_hash_ELFHash(key);
    } else if (mode == 2) {
        index = hashtab_hash_jen(key);
    } else if (mode == 3) {
        index = hashtab_hash_djb2(key);
    } else if (mode == 4) {
        index = hashtab_hash_fnvHash(key);
    } else {
        index = -1;
    }

    return index;
}

void hashtab_init(struct listnode** hashtab)
{
    int i;
    for (i = 0; i < HASH_SIZE; i++) {
        hashtab[i] = NULL;
    }
    collision = 0;
}

void hashtab_add(struct listnode** hashtab, char* key, int value)
{
    struct listnode* node;
    int index = hashtab_hash_function(key);
    node = malloc(sizeof(*node));
    if (node != NULL) {
        node->key = key;
        node->value = value;
        if (hashtab[index] != NULL) {
            collision++;
        }
        node->next = hashtab[index];
        hashtab[index] = node;
    }
}

struct listnode* hashtab_lookup(struct listnode** hashtab, char* key)
{
    struct listnode* node;
    int index = hashtab_hash_function(key);
    for (node = hashtab[index]; node != NULL; node = node->next) {
        if (strcmp(node->key, key) == 0)
            return node;
    }
    return NULL;
}

void hashtab_delete(struct listnode** hashtab, char* key)
{
    struct listnode *node, *prev = NULL;
    int index = hashtab_hash_function(key);
    for (node = hashtab[index]; node != NULL; node = node->next) {
        if (strcmp(node->key, key) == 0) {
            if (prev == NULL) {
                hashtab[index] = node->next;
            } else {
                prev->next = node->next;
            }
            free(node);
            return;
        }
        prev = node;
    }
}

void hashtab_free(struct listnode** hashtab)
{
    int i;
    struct listnode *node, *next = NULL;
    for (i = 0; i < HASH_SIZE; i++) {
        while (hashtab[i] != NULL) {
            node = hashtab[i];
            if (hashtab[i]->next != NULL) {
                next = node->next;
            }
            free(node);
            hashtab[i] = next;
            next = NULL;
        }
    }
    collision = 0;
}

void hashtab_print(struct listnode** hashtab)
{
    int i;
    struct listnode* node;
    for (i = 0; i < HASH_SIZE; i++) {
        if (hashtab[i] == NULL) {
            printf("Node[%d]: NULL\n\n", i);
            continue;
        }
        node = hashtab[i];
        printf("Node[%d]: %s, %d\n", i, node->key, node->value);
        while (node->next != NULL) {
            node = node->next;
            printf("Node[%d]: %s, %d\n", i, node->key, node->value);
        }
        printf("\n");
    }
}
