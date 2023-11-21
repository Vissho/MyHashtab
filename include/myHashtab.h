#pragma once
#define HASH_SIZE 700001

extern int collision;
extern int mode;

struct listnode {
    char* key;
    int value;
    struct listnode* next;
};

unsigned int hashtab_hash_KRHash(char* key);
unsigned int hashtab_hash_ELFHash(char* key);
unsigned int hashtab_hash_jen(char* key);
unsigned int hashtab_hash_djb2(char* key);
unsigned int hashtab_hash_fnvHash(char* key);
unsigned int hashtab_hash_function(char* key);
void hashtab_init(struct listnode** hashtab);
void hashtab_add(struct listnode** hashtab, char* key, int value);
struct listnode* hashtab_lookup(struct listnode** hashtab, char* key);
void hashtab_delete(struct listnode** hashtab, char* key);
void hashtab_free(struct listnode** hashtab);
void hashtab_print(struct listnode** hashtab);
