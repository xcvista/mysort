/*
 * main.c - Main executable of mysort
 *
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <getopt.h>
#include "vector.h"
#include "version.h"

int main(int argc, char **argv)
{
    opterr = 0;
    int c = 0;
    int anything = 0;
    int ok = 0;

    while ((c = getopt(argc, (char **)argv, "HhVv")) != -1)
    {
        switch (c)
        {
            case 'H':
            case 'h':
                usage(0);
            case 'V':
            case 'v':
                version(0);
            case '?':
                if (isprint(optopt))
                    fprintf(stderr, "error: unknown option: -%c\n\n", optopt);
                else
                    fprintf(stderr, "error: unrecognized character: \\x%x\n\n", optopt);
            default:
                usage(1);
        }
    }

    vector_t vec = vector_init_empty(sizeof(char *), 32);
    if (!vec)
    {
        fprintf(stderr, "error: cannot allocate memory.\n");
        exit(1);
    }

    while (1)
    {
        char *buf = malloc(BUFSIZ);
        if (!buf)
        {
            fprintf(stderr, "error: cannot allocate memory\n");
            exit(1);
        }

        if (fgets(buf, BUFSIZ, stdin))
        {
            buf[strlen(buf) - 1] = 0;
            vector_append(vec, buf);
        }
        else
        {
            free(buf);
            break;
        }
    }

    if (!vector_count(vec))
    {
        exit(0);
    }

    vector_sort(vec, strverscmp);

    char *obj = NULL;

    printf("%s\n", (char *)vector_objectat(vec, &obj, 0));
    printf("%s\n", (char *)vector_objectat(vec, &obj, vector_count(vec) - 1));
    return 0;
}
