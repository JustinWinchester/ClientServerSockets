# ClientServerSockets
*^^^^Read me *^^*^
This is a READ ME file that corresponds to a program that uses socket programming to do network computer between a client and server program. This C program uses the TCP Stream protocol to for its network standard. TCP allows for error checking and and is used for protocols in network communication such as :

This program actually is a compilation of four individual programs  and a nessaccsrry head file program that contains important information. The files have then been included into their respective programs in the client and server programs and are now just split into two one client and one server program that communicate with each other over a network. The two programs use the string client and echo functions to write a message from the client that’s read by the server and sent back to the client and printed. This program is an example of a client and server communication using TCP protocols. The two so simple communication to show how network connections and request are accepted and how data is transferred between the two ! 

This program can be compiled by :
cc Justin_Winchester_Server_Proj2.c -o tcpserver
./tcpserver 
In another terminal window!
cc Justin_Winchester_Client_Proj2.c  -o tcpclient
./tcpclient 
(Ip already specified in client code) 
Libraries:
#include <string.h>  //bzero function
#include <sys/socket.h> //basic socket functions
#include <netinet/in.h> //basic definations for sockect structure,socket options
#include <ctype.h> // data types
#include <stdlib.h> //standard library functions
#include <stdio.h> // standard i/o functions
#include <signal.h> //signal function
//#include <error.h> 
#include <errno.h> //errno
Functions:


Programmer: Justin Winchester	
Professor:   Dr. Zhao
Institution: Cameron University
