#include<pthread.h>
#include<stdio.h>
#include<unistd.h>
void *runner();
int main()
{
	printf("\nDEmo of Thread\n");
	pthread_t tid;
	pthread_create(&tid,NULL,runner,0);
	pthread_join(tid,0);
	for(int i=1;i<=5;i++)
	{
		printf("\n\nInside Main");
			sleep(1);
	}
}
void *runner()
{
	int i;
	for(i=1;i<=5;i++)
	{
		printf("\n\nInside Thread");
		sleep(1);
	}
	pthread_exit(0);
}


