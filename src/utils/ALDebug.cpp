#include "utils/ALDebug.h"
#include <stdio.h>
#ifndef BUILD_FOR_ANDROID
#include <execinfo.h>
void al_dump_stack()
{
    void* callstack[128];
    int i, frames = backtrace(callstack, 128);
    char** strs = backtrace_symbols(callstack, frames);
    for (i = 0; i < frames; ++i) {
        printf("%s\n", strs[i]);
    }
    free(strs);
}
#else
void al_dump_stack()
{
}
#endif
