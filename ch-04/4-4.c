#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main() {
    int fd, n;
    char buf[10];

    fd = open("linux.txt", O_RDONLY);
    if (fd == -1) {
        perror("Open");
        exit(1);
    }

    

    while ((n=read(fd,buf,5)) != 0 ) { // n이 0이라는 것은 다 읽었다는 뜻 

   
      if (n == -1) { //error occur
          perror("Read");
          exit(1);
      }

    buf[n] = '\0'; //맨뒤에 널하나 붙인다. 
    printf("n=%d, buf=%s\n", n, buf);
    
    }

    close(fd);
    
}
