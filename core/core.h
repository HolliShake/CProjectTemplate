#include <inttypes.h>
#include <stdarg.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "libgc/gc.h"

#ifndef CORE_H
#define CORE_H
    #define CHECKMALLOC(_ptr) if (_ptr == NULL) { fprintf(stderr, "%s::%s[%ld]: Memory allocation failed!!!\n", __FILE__, __func__, __LINE__); exit(1); }

    #define gc_malloc(_size)        GC_MALLOC(_size)
    #define gc_malloc_atomic(_size) GC_MALLOC_ATOMIC(_size)
    #define gc_realloc(_ptr, _size) GC_REALLOC(_ptr, _size)
    #define gc_free(_ptr)           GC_FREE(_ptr)
    #define gc_run(_ptr)            GC_gcollect()

    typedef char* string_t;
    int start(int argc, char* argv[]);
#endif
