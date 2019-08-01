#include <stdio.h> 
#include <sys/socket.h> 
#include <arpa/inet.h> 
#include <unistd.h> 
#include <string.h>
#define MAX 80
#define PORT 8080

int main(int argc,char const *argv[])
{
    int node2_fd, msg;
    struct sockaddr_in s_address;
    char buffer[MAX]={0};
    if((node2_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("Socket creation failed!");
        return -1;
    }
    s_address.sin_family=AF_INET;
    s_address.sin_port = htons(PORT);
    if(inet_pton(AF_INET, "127.0.0.1", &s_address.sin_addr)<=0) {
        printf("\nError in address\n"); 
        return -1; 
    }  
    if (connect(node2_fd, (struct sockaddr *)&s_address, sizeof(s_address)) < 0) {
        printf("\nConnection Failed \n"); 
        return -1; 
    }
    while(1) {
        char messag[MAX];
        printf("Enter message to be sent to server.\n");
        scanf("%s",messag);
        send(node2_fd , messag , strlen(messag) , 0 );
        printf("Message sent\nReply:\n");
        msg = read( node2_fd , buffer, MAX); 
        printf("%s\n",buffer ); 
    }
    return 0; 
} 
