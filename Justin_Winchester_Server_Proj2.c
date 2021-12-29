/* ************************************************************************************************************************************************************************************************************************
Programmer/Student:	Justin Winchester 

Instructor/Professor:	Dr. Zhao

Instituton:		Cameron University

Project # & Details:  	This is project number 2. This project is used to outline the server & client architecture that is used for network communication between devices via the internet. The project focuses on 
			understanding of how the sockets can be bound with internet and network information for communication. It also focuses on how data is sent back and forth between a client and server and how
			these processes are handled on either side. The server make a connection with the client and then perform multiples step to ensure accurate data transfers and then must deal with unexpected connection 
			interupts and signals sent from it's child processs that is spawned to hand the client request. This projects helps to understand troubleshooing in these types of scenarios for instance during communication
			the server looses power or internet connectiviity or vice versa. Communication can be interrupted for many other reasons so programs must code the programs to deal with the issues for efficient communication 
			accurate data transfer. 






Course:			Network Programming 2020
Program:		This is the server program for network communication between a client and a server. This program includes a header file "myunp.h" which include public libraries that contains functions
			needed for the program. These include standard input/output functions, system call functions: like read and write, unix functions  for network communication, structure address functions for
			the client and server and so on. This program creats a socket for the server that binds to it and waits, listens, accepts, and connects to client request for communication and data transfer
			through a network using TCP/IP protocols. 


* ********************************************************************************************************************************************************************************************************************** */


#define MAX 80 
#define PORT 9877 
#define SA struct sockaddr 

#include "myunp.h"
#include "str_echo.c"  

  
// Main function 

int main() 
{ 

    int sockfd, connfd;  //Socket File Descriptors 
    socklen_t  len;      //Declare variable of socket length type to hold length of socket values
	pid_t	childpid;
    struct sockaddr_in servaddr, cli; //structures that will store client & server network info

  

    // Create the socket & check for issues!

    sockfd = socket(AF_INET, SOCK_STREAM, 0); 

    if (sockfd == -1) { 

        printf("socket creation failed...\n"); //-1 gets returned on error

        exit(0); 

    } 

    else

        printf("Socket successfully created..\n"); //if not we have a socket !

    bzero(&servaddr, sizeof(servaddr));  //must always "zero" out the address

  

    //  IP, PORT assignment using wildcard internet address of internet family convert host to network on port and IP 

    servaddr.sin_family = AF_INET; 

    servaddr.sin_addr.s_addr = htonl(INADDR_ANY); 

    servaddr.sin_port = htons(PORT); 

  

    // Binding newly created socket to the IP Address Provided  

    if ((bind(sockfd, (SA*)&servaddr, sizeof(servaddr))) != 0) { 

        printf("socket bind failed...\n"); 

        exit(0); 

    } 

    else    //Should return 0, if so we have binded server prog to socket!!

        printf("Socket successfully binded..\n"); 

  

    // Now server should listen for incoming request to spawn children servers for!!!

    if ((listen(sockfd, 5)) != 0) {     //Error checking & specify que for backlog to process @ most five(5) client connections at a time!~

        printf("Listen failed...\n"); 

        exit(0); 

    } 

    else

        printf("Server listening..\n"); //Ensure that server is doing what it should be @ this point that is LISTENING!!!

    len = sizeof(cli);  //specify earlier length type variable to cli info 

  

    // Accept the data packet from client !

    connfd = accept(sockfd, (SA*)&cli, &len); //Use connected File Descriptor variable to specify info from client and provid it to other functions for communicating !

    if (connfd < 0) { 

        printf("server acccept failed...\n"); //Accept ErroR Checking!!

        exit(0); 

    } 

    else

        printf("server acccept the client...\n"); //Connecton Made if Accept Work (Three Way Handshake (RTT))

  
for ( ; ; ) {
    // Function for chatting between client and server 
if ( (childpid = fork()) == 0) {	// CHILD proccess will Begin to make little child server for CLIENT(s)
    str_echo(connfd); 
exit(0);
		}
  

    // After chatting close the socket 

    close(sockfd); 
}

}
