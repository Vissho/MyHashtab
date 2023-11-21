#include <myHashtab.h>
#include <stdio.h>
#include <string.h>
#include <sys/time.h>
#include <time.h>

char* Hash_Functions[]
        = {"Hash function KRHash",
           "Hash function ELFHash",
           "Hash function jen",
           "Hash function djb2",
           "Hash function fnvHash"};

double wtime()
{
    struct timeval t;
    gettimeofday(&t, NULL);
    return (double)t.tv_sec + (double)t.tv_usec * 1E-6;
}

int main()
{
    struct listnode* hashtab[HASH_SIZE];

    for (int i = 0; i < 25; i++) {
        mode = i / 5;
        int fn = i % 5 + 1;
        hashtab_init(hashtab);

        char bf[32];
        FILE* f = fopen("data/dict1.txt", "r");
        if (!f) {
            fprintf(stderr, "gen: fatal error: f == NULL\n");
            return -1;
        }

        char key[20];
        double time1 = wtime();
        for (int j = 0; j < 200000 * fn; j++) {
            fscanf(f, "%s", key);
            hashtab_add(hashtab, key, j);
        }
        double time2 = wtime() - time1;

        struct listnode* temp;
        double time3 = wtime();
        fseek(f, 0, SEEK_SET);
        for (int j = 0; j < 200000 * fn; j++) {
            fscanf(f, "%s", key);
            temp = hashtab_lookup(hashtab, key);
            if (strcmp(temp->key, key)) {
                printf("Error!\n");
                fclose(f);
                hashtab_free(hashtab);
                return -1;
            }
        }
        double time4 = wtime() - time3;

        fclose(f);

        FILE* z;
        if (i % 5 == 0) {
            sprintf(bf, "graph/%s.dat", Hash_Functions[mode]);
            z = fopen(bf, "w");
            if (!z) {
                fprintf(stderr, "gen: fatal error: f == NULL\n");
                return -1;
            }
        }
        fprintf(z, "%d\t%d\t%lf\t%lf\n", collision, 200000 * fn, time2, time4);
        if (i % 5 == 4)
            fclose(z);

        hashtab_free(hashtab);
    }

    return 0;
}
