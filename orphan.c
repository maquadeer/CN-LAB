#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<unistd.h>
int main()
{
	int pid;
	system("clear");
	printf("\nOrphan process\n");
	pid=fork();
	if(pid==0)
	{
		printf("\nChild PR:Process is %d \t Parent process id is %d \n\n",getpid(),getppid());
		system("ps -l");
		sleep(2);
		printf("\nChild PR:Process is %d \t Parent process id is %d \n\n",getpid(),getppid());
		system("ps -l");
	}
	else
	{
		//sleep(1);
		printf("\nParent PR:Process is %d \t Parent process id is %d \n\n",getpid(),getppid());
		system("ps -l");
	}

}
