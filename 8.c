#include<stdio.h>

#include<stdlib.h>

#include<sys/types.h>

#include<sys/socket.h>

#include<netinet/in.h>

main(int argc, char * argv[]) {
  int sockid, rval;
  char m1[20], m2[20];
  sockid = socket(AF_INET, SOCK_STREAM, 0);
  if (sockid == -1) {
    perror("SOCK-CRE-ERR");
    exit(1);
  }
  struct sockaddr_in s;
  system("clear");
  if (argc < 3) {
    printf("\nUSAGE : %s IP_ADDR PORT#\n", argv[0]);
    exit(0);
  }
  s.sin_family = AF_INET;
  s.sin_addr.s_addr = inet_addr(argv[1]);
  s.sin_port = htons(atoi(argv[2]));
  rval = connect(sockid, (struct sockaddr * ) & s, sizeof(s));
  if (rval == -1) {
    perror("CONN-ERR:");
    close(sockid);
    exit(1);
  }
  printf("\nEnter the request message : ");
  scanf("%s", m1);
  rval = send(sockid, m1, sizeof(m1), 0);
  if (rval == -1) {
    perror("MSG-SND-ERR:");
    close(sockid);
    exit(1);
  }
  printf("\nMessage sent successfully\n");
  rval = recv(sockid, m2, sizeof(m2), 0);
  if (rval == -1) {
    perror("MSG-RCV-ERR:");
    close(sockid);
    exit(1);
  }
  printf("\nServer response is : %s\n", m2);
  close(sockid);
}
/*SERVER PROGRAM*/
#include<stdio.h>

#include<stdlib.h>

#include<sys/types.h>

#include<sys/socket.h>

#include<netinet/in.h>

main(int argc, char * argv[]) {
  int sid, sid1, rval, itr, i; // sid is half association. sid1 is full association
  struct sockaddr_in s, c;
  char buffer[20];
  int clen; //accept() uses value-result parameter
  system("clear");
  if (argc < 3) {
    printf("\nUSAGE : %s IP_ADDRESS PORT#\n", argv[0]);
    exit(0);
    printf("\nEnter the number of clients to serve/ server iterations : ");
    scanf("%d", & itr);
    sid = socket(AF_INET, SOCK_STREAM, 0);
    if (sid == -1) {
      perror("SOCK-CRE-ERR:");
      exit(1);
    }
    /*DEFINING NAME OF THE SERVICE*/
    s.sin_family = AF_INET;
    s.sin_addr.s_addr = inet_addr(argv[1]);
    s.sin_port = htons(atoi(argv[2]));
    /*BIND SOCKET- indicates the process that is listening*/
    rval = bind(sid, (struct sockaddr * ) & s, sizeof(s));
    if (rval == -1) {
      perror("BIND-ERR:");
      close(sid);
      exit(1);
    }
    rval = listen(sid, 5); //range : 1-5
    if (rval == -1) {
      perror("LISTEN-ERR:");
      close(sid);
      exit(1);
    }
    for (i = 1; i <= itr; i++) {
      clen = sizeof(c);
      sid1 = accept(sid, (struct sockaddr * ) & c, & clen);
      /*sid1 is a full association tuple and has information of client,server and communication 
      protocol i.e serving socket*/
      rval = recv(sid1, buffer, sizeof(buffer), 0);
      if (rval == -1) {
        perror("MSG-RCV-ERR:")
      }
    } else {
      printf("\nClient request is %s\n", buffer);
    }
    rval = send(sid1, buffer, sizeof(buffer), 0);
    if (rval == -1) {
      perror("MSG-SND-ERR:");
    } else {
      printf("\nResponse sent\n");
    }
    close(sid1); //closing the serving socket
  }
  close(sid); //closing the listening socket
}
