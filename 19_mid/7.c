#include <stdio.h>
#include <sys/stat.h>
#include <unistd.h>
#include <sys/types.h>

int main() {
    struct stat statbuf;

    stat("linux.txt", &statbuf);

    symlink("linux.txt","linux.sym");
    lstat("linux.sym",&statbuf);
