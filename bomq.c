#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/msg.h>
#include<unistd.h>
struct msg{
	long id;
	char m[20];
}m1,m2;

int main()
{
	int qid,pid,msgid,rval;
	system("clear");
	printf("\n MP-Q: Program to demonstrate basic operation on QS \n");
	qid = msgget((key_t)61,IPC_CREAT|0600);
	if(qid == -1){
		perror("Q-CE-ERR:");
		exit(1);
	}
	printf("\n MP-Q: Queue created with id = %d\n",qid);
	system("ipcs -q");

	printf("\nMP-Q: Enter the messgae id for communication\n");
	scanf("%d",&msgid);
	printf("\nMP-Q: Enter message to write to Msg.Q:\t");
	scanf("%s",m1.m);
	m1.id = msgid;
	rval = msgsnd(qid, &m1, sizeof(m1),0);
	if(rval == 0)
	{
		printf("\nMP-Q: Message written to the Msg.Q is %s\n",m1.m);
	}
	else
	{
		perror("Q-SND-ERR:");
		exit(1);
	}
	system("ipcs -q");
	rval = msgrcv(qid,&m2,sizeof(m2),msgid,0);
	

	if(rval == -1)
	{
		perror("Q-RD-ERR");
		exit(1);
	}
	else
	{
		printf("\n MP-Q: Message received from the Msg.Q is %s \n",m2.m);
		system("ipcs -q");
		msgctl(qid,IPC_RMID,0);
		system("ipcs -q");
	}
}
