#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main(){
	pid_t child_pid;

	if((child_pid=fork())==-1){
		perror("Fork");
		exit(EXIT_FAILURE);
	}
	if(child_pid>0){
		printf("Parent process: my PID is %d\n ",getpid());
                printf("Parent process: my child PID is %d\n ",child_pid);
	}
	else{
		printf("Child process: my PID is %d\n ",getpid());
		printf("Child process: my parent PID is %d\n ",getppid());
	}
	return 0;
}


