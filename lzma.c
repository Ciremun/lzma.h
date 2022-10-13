#define LZMA_IMPLEMENTATION
#include "lzma.h"

#include <stdio.h>
#include <stdint.h>
#include <assert.h>
#include <string.h>

int main()
{
    uint8_t data[] = "I'd just like to interject for a moment. "
    "What you're referring to as C++, is in fact, C/C++, "
    "or as I've recently taken to calling it, C plus C++. "
    "C++ is not an programming language unto itself, "
    "but rather another free component of a fully functioning C system made useful by the libc, "
    "preprocessor and vital system components comprising "
    "a full programming language as defined by POSIX.\n\n"
    "- Tinus Lorvalds";

    uint8_t comp[sizeof(data) + LZMA_HEADER_SIZE];
    size_t comp_sz = sizeof(comp);
    assert(lzma_compress(comp, &comp_sz, data, sizeof(data)) == SZ_OK);

    uint8_t uncomp[sizeof(data)];
    size_t uncomp_sz = sizeof(uncomp);
    assert(lzma_uncompress(uncomp, &uncomp_sz, comp, &comp_sz) == SZ_OK);

    assert(memcmp(data, uncomp, sizeof(data)) == 0);

    printf("%s\n", uncomp);
}
