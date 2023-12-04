#include<stdio.h>

#include<stdlib.h>

#include<sys/socket.h>
#include<netinet/in.h>
#include<sys/types.h>
#include<string.h>

int main(int argc, char * argv[]) {
	struct sockaddr_in s,c;
    	int rval, sockid, clen;
    	char buffer[20];
    	system("clear");
    	if (argc < 3) {
      		printf("\nUSAGE : %s IP-Address Port#\n", argv[0]);
      		exit(1);
    	}
    	sockid = socket(AF_INET, SOCK_DGRAM, 0);
    	if (sockid == -1) {
    		perror("SOCK-CRE-ERR:");
      		exit(1);
    	}
    	s.sin_family = AF_INET;
    	s.sin_addr.s_addr = inet_addr(argv[1]);
    	s.sin_port = htons(atoi(argv[2]));
    	printf("\nsocket created : \n");
    	rval = bind(sockid, (struct sockaddr *)&s, sizeof(s));
    	if (rval == -1) {
      		perror("BIND-ERR");
      		close(sockid);
		exit(1);
	}
	
	printf("socket binded\n");
	clen=sizeof(c);
	rval=recvfrom(sockid,buffer,sizeof(buffer),0,(struct sockaddr*)&c,&clen);
	if(rval==-1){
		perror("MSG-RCV-ERR");
		exit(1);
	}
	strcat(buffer," my name is q");
	printf("msg rec:%s\n",buffer);
	close(sockid);
}
