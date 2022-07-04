//
// Created by 43462 on 2022/7/2.
//
#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"
#define numSize 35

int main(int argc, char *argv[]) {
    int fd[2];
    pipe(fd);
    close(fd[0]);
    for (int i = 2; i <= numSize; ++i) {
        
    }
}