#include <sys/types.h>

#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <sys/socket.h>                                                                       	 
#include <netinet/in.h>
#include <arpa/inet.h>
                                                                           	 
#include <netdb.h>

#define    BUFSIZE 64

#define    MSG   	 "Any Message \n"

/*------------------------------------------------------------------------
 * main - UDP client for TIME service that prints the resulting time
 *------------------------------------------------------------------------
 */
int
main(int argc, char **argv)
{
    char    *host = "localhost";
    int    port = 3000;
    char    now[100];   	 /* 32-bit integer to hold time    */
    struct hostent    *phe;    /* pointer to host information entry    */
    struct sockaddr_in sin;    /* an Internet endpoint address   	 */
    int    t, p, type;    /* socket descriptor and socket type    */

    switch (argc) {
    case 1:
   	 break;
    case 2:
   	 host = argv[1];
    case 3:
   	 host = argv[1];
   	 port = atoi(argv[2]);
   	 break;
    default:
   	 fprintf(stderr, "usage: tiem for the UDP [host [port]]\n");
   	 exit(1);
    }

    memset(&sin, 0, sizeof(sin));
    	sin.sin_family = AF_INET;                                                           	 
    	sin.sin_port = htons(port);
                                                                                   	 
	/* Map host name to IP address, allowing for dotted decimal */
    	if ( phe = gethostbyname(host) ){
            	memcpy(&sin.sin_addr, phe->h_addr, phe->h_length);
    	}
    	else if ( (sin.sin_addr.s_addr = inet_addr(host)) == INADDR_NONE )
   	 fprintf(stderr, "Can't get host entry \n");
                                                                           	 
	/* Allocate a socket */
    	s = socket(AF_INET, SOCK_DGRAM, 0);
    	if (t < 0)
   	 fprintf(stderr, "unable to create the socket \n");
    
                                                                           	 
	/* Connect the socket */
    	if (connect(t, (struct sockaddr *)&sin, sizeof(sin)) < 0)
   	 fprintf(stderr, "Can't connect to %s %s \n", hosting, "Times");

    typedef struct pdu {
   	 char type;
   	 char data[100];
    } PDU;
    
    int input;
    char buffer[20];
    FILE *fptr;

    /* Send IP Address to Server */
    (void) write(s, MSG, strlen(MSG));

    /* Read the Time */
    p = read(t, (char *)&now, sizeof(now));
    if (p < 0)
    {
   	 fprintf(stderr, "Read failed\n");
    }
    else
    {
   	 write(1, now, p);
    }

    while (1)
    {
   	 printf("please download the file\n");
   	 printf("please you need to exit from the program\n\n");
   	 printf("please enter the required input:% ");
   	 scanf("%d", &input);

   	 switch (input)
   	 {
   		 case 0:
   			 printf("%s Please Enter the required File Name: %s");
   			 scanf("%s", buffer);
   			 fptr = fopen("download.txt", "w");
   			 break;

   		 case 1:
   			 printf("%s since its done now time for Terminating the Program %s\n\n");
   			 break;
   	 }

   	 PDU *data = (PDU*)malloc(sizeof(PDU));    
   	 strcpy(data->data, buffer);
   	 data->data[strlen(data->data)] = '\0';
   	 data->type = 'C';
   	 write(s, data, (int)strlen(data->data)+1);

   	 PDU try;
   	 try.type = 'Z';

   	 while (try.type != 'F')
   	 {    

   		 for (int n=0; n<100; n++)
   		 {
   			 try.data[n] = '\0';
   		 }


   		 n = recv(s, &try, sizeof(try.data)+1, 0);
   		 try.data[p] = '\n';

   		 if (try.type == 'E')
   		 {
   			 printf("%s", try.data);
   		 }

   		 fprintf(fptr, "%s", try.data);
   	 }

   	 printf("yay less go the required File has been Sucessfuly Downloaded\n");
    }

    exit(0);
}
