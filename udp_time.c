#include<stdio.h>
#include<stdlib.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<sys/types.h>
#include<string.h>
main(int argc, char * argv[])
{
	unsigned long timeval,tempval;
	struct sockaddr_in s;
	int rval,sockid,slen;
	char m1[20],m2[50];
	system("clear");
	if(argc<3){
		printf("\nUSAGE :%s IP-Address Port #\n", argv[0]);
		exit(1);
	}
	sockid = socket(AF_INET, SOCK_DGRAM,0);
	if(sockid ==  -1){
		perror("SOCK-CRE-ERR:");
		exit(1);
	}
	s.sin_family= AF_INET;
	s.sin_addr.s_addr = inet_addr(argv[1]);
	s.sin_port = htons(atoi(argv[2]));
	printf("\nSocket created");
	slen = sizeof(s);
	rval = sendto(sockid,m1,sizeof(m1),0,(struct sockaddr *)&s,slen);
	if(rval == -1){
		perror("\nMSG-SEND-ERR:");
		exit(1);
	}
	printf("\nMessage sent successfully\n");
	rval = recvfrom(sockid,&tempval,sizeof(tempval),0, (struct sockaddr *)&s,&slen);
	if(rval == -1){
	perror("MSG-RCV-ERR");
	exit(1);
	}
	timeval = htonl(tempval);
	printf("\nMessage received is :%u\n",timeval);
	close(sockid);
}

