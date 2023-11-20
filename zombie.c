#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<unistd.h>
int main()
{
	int pid;
	printf("\nProgram to demonstarte Zombie process\n");
	pid=fork();
	if(pid==0)
	{
		printf("\nChild PR:process id is %d\t Parent process is %d \n\n",getpid(),getppid());
		system("ps -l");
		exit(0);
	}
	else
	{
		sleep(1);
		printf("\nParent PR:process id is %d\t Parent process is %d \n\n",getpid(),getppid());
		system("ps -l");
	}
}
