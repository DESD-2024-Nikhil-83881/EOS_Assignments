#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
	int fd, num1,num2,res;
	fd = open("/tmp/client_fifo", O_RDONLY);
	if(fd < 0) {
		perror("open() failed");
		_exit(1);
	}

	printf("waiting for data...\n");
	 read(fd, &num1, sizeof(num1));
	 read(fd, &num2, sizeof(num2));
	printf("read from fifo: %d %d\n", num1, num2);
	

	fd = open("/tmp/server_fifo", O_WRONLY);
	if(fd < 0) {
		perror("open() failed");
		_exit(1);
	}

	res = num1 + num2;

	 write(fd, &res, sizeof(res));
	close(fd);
	close(fd);
	return 0;
}


