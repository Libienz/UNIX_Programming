#include <stdio.h>

int main(void) {

    char buf[5];
    for (int i = 0; i<4; i++) {
	buf[i] = 'c'; 
    }
    buf[4] = '\0';

    printf("%s",buf);

    return 0;
}

