#include <stdio.h>
#include <unistd.h>
#include <pwd.h>
#include <sys/types.h>

int main(void) {
	char* name;
	name = getlogin();
	struct passwd* pw;
	//pw_dir
	//pw_shell
	pw = getpwnam(name);
	printf("%s\n",pw->pw_dir);
	printf("%s\n",pw->pw_shell);

	return 0;
}


	
