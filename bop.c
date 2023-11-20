
/*Basic operations on pipes*/
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>
#include<sys/types.h>
#include<string.h>
int main()
{
	int pid,a[2];
	char str[30],buff[30];
	pipe(a);
	pid=fork();
	if(pid==0)
	{
		strcpy(str,"Welcome to Os lab");
		write(a[1],str,sizeof(str));
		printf("\nchild process sent %s\n",str);
	}
	else{
		wait(0);
		read(a[0],buff,sizeof(buff));
		printf("\nParent process received %s\n",buff);
	}
}

