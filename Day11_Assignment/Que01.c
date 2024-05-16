#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>

int main() {
	int ret, err, s, fd;
	printf("parent started!\n");
	ret = fork();
	if(ret == 0) {
		fd = open("in.txt", O_CREAT | O_TRUNC | O_WRONLY, 0644);
		close(1);
		dup(fd); 
		close(fd);

		
		fd = open("err.txt", O_CREAT | O_TRUNC | O_WRONLY, 0644);
		dup2(fd, 2);
		close(fd);
		
		err = execlp("wc", NULL);
		if(err < 0) {
			perror("exec() failed");
			_exit(1);
		}
	}
	else
		waitpid(-1, &s, 0);
	printf("parent completed!\n");
	return 0;
}

