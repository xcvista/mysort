#!/bin/bash
cat << EOF
/*
 * version.h - Project version information
 *
 * Copyright (c) 2013 Maxthon Chan
 * Generated with version.sh
 *
 */

#ifndef _VERSION_H_
#define _VERSION_H_

#define VERSION "1.0"
#define VCS_VERSION "`git rev-parse --short HEAD`"

#include <sys/cdefs.h>

__BEGIN_DECLS
void usage(int) __attribute__((noreturn));
void version(int) __attribute__((noreturn));
__END_DECLS

#endif
EOF

