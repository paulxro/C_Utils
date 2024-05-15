#ifndef __VEC_H
#define __VEC_H

#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

 #define max(a,b) \
    ({ __typeof__ (a) _a = (a); \
       __typeof__ (b) _b = (b); \
     _a > _b ? _a : _b; })

#define min(a,b) \
    ({ __typeof__ (a) _a = (a); \
       __typeof__ (b) _b = (b); \
     _a > _b ? _b : _a; })

typedef unsigned long size_t;

typedef struct {
    void **data;
    size_t size;
    size_t capacity;
    size_t elem_size;
    char   is_valid;
} Vector;

void  init_vector (Vector*, size_t);
void  free_vector (Vector*);
void  push_back   (Vector*, void*);
void  pop_back    (Vector*);
void  resize      (Vector*, size_t);
void  clear       (Vector*);
void *at          (Vector*, size_t);

/* Info Methods */

size_t  capacity  (Vector*);
size_t  size      (Vector*);

#endif