#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>


int main() {
	int fd, num1,num2,res;
	
	fd = open("/tmp/client_fifo", O_WRONLY);
	if(fd < 0) {
		perror("open() failed");
		_exit(1);
	}

	printf("Enter num1: ");
	scanf("%d",&num1);
	printf("Enter num2: ");
	scanf("%d",&num2);

	num1 = write(fd, &num1, sizeof(num1));
	num2 = write(fd, &num2, sizeof(num2));

	fd = open("/tmp/server_fifo", O_RDONLY);
	if(fd < 0) {
		perror("open() failed");
		_exit(1);
	}

	read(fd, &res, sizeof(res));
	printf("read from fifo: %d\n", res);

	close(fd);
	close(fd);
	return 0;
}

