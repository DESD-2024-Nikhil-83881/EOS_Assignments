

#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main(){
	int ret1,ret2,ret3,s1,s2,s3,i;
	ret1 = fork();
	if(ret1 == 0){
		ret2 = fork();
		if(ret2 == 0){
			ret3 = fork();
			if(ret3 == 0){
				for(i=1;i<=5;i++){
					printf("the pid and ppid of child 3 is pid:%d ppid:%d\n",getpid(),getppid());
					sleep(1);
				}
				_exit(0);
			}
		for(i=1;i<=5;i++){
			printf("the pid and ppid of child 2 is pid:%dppid:%d\n",getpid(),getppid());
			sleep(1);
		}
		waitpid(ret3,&s3,0);
		_exit(0);

		}
	for(i=1;i<=5;i++){
		printf("the pid and ppid of child 1 is pid:%dppid:%d\n",getpid(),getppid());
        sleep(1);
     }
	 waitpid(ret2,&s2,0);
	 _exit(0);

	}
	for(i=1;i<=5;i++){
		printf("the pid and ppid of parent A is pid:%dppid:%d\n",getpid(),getppid());
		sleep(1);
	}
	waitpid(ret1,&s1,0);
	
	return 0;
}
