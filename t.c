#define _GNU_SOURCE

#include <dlfcn.h>
#include <stdio.h>

int main(int argc, char** argv) {
    const char* libs[] = {"libc.so.6", "libdl.so.2"};
    for (int i=0; i<2; ++i) {
        void* lib = dlopen(libs[i], RTLD_NOW);
        void* dlsym_2_34 = dlvsym(lib, "dlsym", "GLIBC_2.34");
        void* dlsym_2_2_5 = dlvsym(lib, "dlsym", "GLIBC_2.2.5");
        void* dlsym_2_1 = dlvsym(lib, "dlsym", "GLIBC_2.1");
        printf("Search for lib: %s\n", libs[i]);
        printf("p_2.34: %p, p_2.2.5: %p, p_2.1: %p\n", dlsym_2_34, dlsym_2_2_5, dlsym_2_1);
    }
}
