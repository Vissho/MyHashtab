#include <ctest.h>
#include <myHashtab.h>
#include <stdio.h>

CTEST(hashtab_init, correctly_hashtab_init)
{
    struct listnode* hashtab[HASH_SIZE];
    hashtab_init(hashtab);
    ASSERT_EQUAL(0, collision);
}

CTEST(hashtab_add, correctly_hashtab_add)
{
    struct listnode* hashtab[HASH_SIZE];
    hashtab_init(hashtab);
    hashtab_add(hashtab, "car", 10);
    hashtab_add(hashtab, "car", 11);
    ASSERT_EQUAL(1, collision);
    hashtab_free(hashtab);
}

CTEST(hashtab_lookup, correctly_hashtab_lookup)
{
    struct listnode* hashtab[HASH_SIZE];
    hashtab_init(hashtab);
    hashtab_add(hashtab, "car", 10);
    struct listnode* temp = hashtab_lookup(hashtab, "car");
    ASSERT_NOT_NULL(temp);
    hashtab_free(hashtab);
}

CTEST(hashtab_delete, correctly_hashtab_delete)
{
    struct listnode* hashtab[HASH_SIZE];
    hashtab_init(hashtab);
    hashtab_add(hashtab, "car", 10);
    hashtab_add(hashtab, "cat", 11);
    hashtab_delete(hashtab, "car");
    struct listnode* temp = hashtab_lookup(hashtab, "car");
    ASSERT_NULL(temp);
    hashtab_free(hashtab);
}

CTEST(hashtab_free, correctly_hashtab_free)
{
    struct listnode* hashtab[HASH_SIZE];
    hashtab_init(hashtab);
    hashtab_add(hashtab, "car", 10);
    hashtab_add(hashtab, "cat", 11);
    hashtab_free(hashtab);
    ASSERT_EQUAL(0, collision);
}
