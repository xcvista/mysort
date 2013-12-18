/*
 * string.h
 *
 * Augumented string.h that provides an extra prototype.
 *
 */

#include <sys/cdefs.h>
#include_next <string.h>

__BEGIN_DECLS
int strverscmp(const char *, const char *);
__END_DECLS

