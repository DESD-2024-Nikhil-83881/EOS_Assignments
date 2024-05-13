#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>

int main(){
	int ret1, ret2, ret3,ret4,ret5,i,s,child_pid;
	ret1 = fork();
	if(ret1==0){
		for(i=1; i<=5; i++) {
			printf("child1: %d\n", i);
			printf("child1pid:%d\n",getpid());
		sleep(1);
		}
		_exit(0);
}
	ret2 = fork();
	if(ret2==0){
		for(i=1; i<=5; i++) {
			printf("child2: %d\n", i);
			printf("child2pid:%d\n",getpid());
		sleep(1);
		}
		_exit(0);
	}
	ret3 = fork();
	if(ret3==0){
		for(i=1; i<=5; i++) {
			printf("child3: %d\n", i);
			printf("child3pid:%d\n",getpid());
		sleep(1);
		}
		_exit(0);
}
	ret4 = fork();
	if(ret4==0){
		for(i=1; i<=5; i++) {
			printf("child4: %d\n", i);
			printf("child4pid:%d\n",getpid());
		sleep(1);
		}
		_exit(0);
}
ret5 = fork();
	if(ret5==0){
		for(i=1; i<=5; i++) {
			printf("child5: %d\n", i);
			printf("child5pid:%d\n",getpid());
		sleep(1);
		}
		_exit(0);
}
	for(i=1;i<=5;i++){
		child_pid = wait(&s);
	}
}
