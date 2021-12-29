/* ************************************************************************************************************************************************************************************************************************
Programmer/Student:     Justin Winchester

Instructor/Professor:   Dr. Zhao

Instituton:             Cameron University

Project # & Details:    This is project number 2. This project is used to outline the server & client architecture that is used for network communication between devices via the internet. The project focuses on
                        understanding of how the sockets can be bound with internet and network information for communication. It also focuses on how data is sent back and forth between a client and server and how
                        these processes are handled on either side. The server make a connection with the client and then perform multiples step to ensure accurate data transfers and then must deal with unexpected connection
                        interupts and signals sent from it's child processs that is spawned to hand the client request. This projects helps to understand troubleshooing in these types of scenarios for instance during communication
                        the server looses power or internet connectiviity or vice versa. Communication can be interrupted for many other reasons so programs must code the programs to deal with the issues for efficient communication
                        accurate data transfer.






Course:			Network Programming 2020
Program:                This is the Client program for network communication between a client and a server. This program includes a header file "myunp.h" which include public libraries that contains functions
                        needed for the program. These include standard input/output functions, system call functions: like read and write, unix functions  for network communication, structure address functions for
                        the client and server and so on. This program creats a socket for the server that binds to it and waits, listens, accepts, and connects to client request for communication and data transfer
                        through a network using TCP/IP protocols. This part of the two connected programs includes the string client (str_cli) function that writes datat to a shared buffer and then sends that to the server
			program which uses a similar string function called the str_echo or string echo function, this part on the server sides rides that information written by the client processes it in it's echo function
			by reading the data sent in the buffer by the server "copying" that data by writng it into it's own buffer and sending that same message or info back to the client which reads this buffer and then prints 
			it!!!>


* ********************************************************************************************************************************************************************************************************************** */



#include "myunp.h"
#define MAX 80 
#define PORT 9877 
#include "str_cli.c"
//#define SA struct sockaddr 

  

int main() 
{ 

    int sockfd, connfd; //File Descriptors

    struct sockaddr_in servaddr, cli; //..Structs For client & server internet addresses!!

  

    // Client Socket Creation!

    sockfd = socket(AF_INET, SOCK_STREAM, 0); //assign client info for file descriptor of socket declare protocol type, address family

    if (sockfd == -1) { 

        printf("socket creation failed...\n"); //Tell if there is an error creating socket for client!!

        exit(0); 

    } 

    else

        printf("Socket successfully created..\n"); //If not it's successfully created client socket!

    bzero(&servaddr, sizeof(servaddr)); //Zero out structs !

  

    //  IP, PORT Assignment 

    servaddr.sin_family = AF_INET; 

    servaddr.sin_addr.s_addr = inet_addr("127.0.0.1");  //Using loopack Address For SERVER connection

    servaddr.sin_port = htons(PORT); //Port is Defined at Beggining of program!

  

    // connect the client socket to server socket 

    if (connect(sockfd, (SA*)&servaddr, sizeof(servaddr)) != 0) { 

        printf("connection with the server failed...\n"); //Erro checking

        exit(0); 

    } 

    else

        printf("connected to the server..\n"); //Tell user that client has made successful connection to SERVER

  

    // function for chat 

    str_cli(sockfd); 

  

    // close the socket 

    close(sockfd); //if finished close socket 
}

