#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ptrace.h>

#include "gdb.h"
#include "various.h"
#include "env.h"

int main(int argc, char** argv){
    unsigned int res = 0;

    printf(".: GDB detector :.\n\n");

    if(res += dbg_file_descriptor())
        printf("[x] file descriptor\n");
    else
        printf("[ ] file descriptor\n");

    if(res += dbg_cmdline())
        printf("[x] /proc/PID/cmdline\n");
    else
        printf("[ ] /proc/PID/cmdline\n");

    if(res += dbg_sigtrap())
        printf("[x] SIGTRAP\n");
    else
        printf("[ ] SIGTRAP\n");

    if(res += dbg_getppid_name())
        printf("[x] getppid name\n");
    else
        printf("[ ] getppid name\n");

    if(res += dbg_ptrace())
        printf("[x] ptrace\n");
    else
        printf("[ ] ptrace\n");

    if(res)
        printf("\n[*] GDB detected\n");
    else
        printf("\n[ ] No GDB detected\n");


    res = 0;
    printf("\n\n");
    printf(".: Various tricks detector :.\n\n");

    if(res += various_ldpreload())
        printf("[x] LD_PRELOAD\n");
    else
        printf("[ ] LD_PRELOAD\n");

    if(res += various_ldpreload_custom_getenv())
        printf("[x] hidden LD_PRELOAD\n");
    else
        printf("[ ] hidden LD_PRELOAD\n");

    if(res += various_rdtsc())
        printf("[x] Something is slowing the process...\n");
    else
        printf("[ ] Everything is running well\n");

    if(res)
        printf("\n[*] Something is wrong\n");
    else
        printf("\n[ ] Everything seems fine\n");

    res = 0;
    printf("\n\n");
    printf(".: GDB env detector :.\n\n");

    if(res += gdb_columns())
        printf("[x] COLUMNS_ENV\n");
    else
        printf("[ ] COLUMNS_ENV\n");

    if(res += gdb_lines())
        printf("[x] LINES_ENV\n");
    else
        printf("[ ] LINES_ENV\n");

    if(res += gdb_path())
        printf("[x] GDB_ENV\n");
    else
        printf("[ ] GDB_ENV\n");

    if(res)
        printf("\n[*] GDB detected\n");
    else
        printf("\n[ ] No GDB detected\n");
    return 0;
}
