#pragma once



#include "fastmath.h"
#include <memory.h>
#include <string.h>
#include <malloc.h>

#include <stdio.h>

inline void* MemAllocNoZero(unsigned int cBytes)
{
    return malloc(cBytes);
}

inline void* MemAlloc(unsigned int cBytes)
{
    void* p = MemAllocNoZero(cBytes);
    if (p)
    {
        memset(p, 0, cBytes);
    }
    return p;
}

inline void MemFree(void* pv)
{
    if (pv != NULL)
    {
        free(pv);
    }
}

inline void mem_cpy(void *dst, void* src, size_t size)
{
    size_t i;
    for (i = 0; i < size; i++)
    {
        ((unsigned char*)dst)[i] = ((unsigned char*)src)[i];
    }
}
