#include <stdio.h>
#include <stdlib.h>

#include "version.h"

void usage(int e)
{
    fprintf(stderr,
            "USAGE: mysort [OPTIONS] number ...\n"
            "\n"
            "OPTIONS:\n"
            "  -H, -h:\tShow this help messag and exit.\n"
            "  -V, -v:\tShow the version information and exit.\n\n");

    version(e);
}

void version(int e)
{
    fprintf(stderr,
            "mysort version %s (git %s)\n"
            "Yet another free implementation of sort(1)\n"
            "Written in 2013 by Maxthon Chan\n"
            "\n"
            "This software is licensed under GNU GPL v3 or up..\n", VERSION, VCS_VERSION);
    exit(e);
}
