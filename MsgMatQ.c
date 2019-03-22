#include <stdio.h> 
#include <sys/ipc.h> 
#include <sys/msg.h> 
#include <sys/wait.h> 
#include <unistd.h>
  
int n,m;  
// structure for message queue 
struct mesg_buffer { 
    long mesg_type; 
    int n,m;
    int mesg_text[25][25]; 
};
  
int main() 
{ 
	if(!(fork()>0)){
		wait(NULL);
    	key_t key; 
    	int msgid;
    	struct mesg_buffer message;
    	 
  
    	// ftok to generate unique key 
    	key = ftok("progfile", 65); 
  
    	// msgget creates a message queue 
    	// and returns identifier 
    	msgid = msgget(key, 0666 | IPC_CREAT); 
    	message.mesg_type = 1; 
  
    	printf("Enter the dimension of the matrix : "); 
    	scanf("%d%d",&message.n,&message.m);
    	printf("Enter the elements of the matrix :\n ");
    	for(int i=0;i<message.n;i++){
    		for(int j=0;j<message.m;j++){
    			scanf("%d",&message.mesg_text[i][j]);
    		}
    	}
    	//gets(message.mesg_text); 
  
    	// msgsnd to send message 
    	msgsnd(msgid, &message, sizeof(message), 0); 
  
    	// display the message 
    	printf("\nData successfully sent \n\n"); 
  }
  else{
  	key_t key; 
    int msgid; 
    struct mesg_buffer message;
  
    // ftok to generate unique key 
    key = ftok("progfile", 65); 
  
    // msgget creates a message queue 
    // and returns identifier 
    msgid = msgget(key, 0666 | IPC_CREAT); 
  
    // msgrcv to receive message 
    msgrcv(msgid, &message, sizeof(message), 1, 0); 
	
	
	printf("\nData recieved is \n\n");  
    // display the message 
     for(int i=0;i<message.n;i++){
    	//for(int j=0;j<message.m;j++){
    		printf("%d ",message.mesg_text[i][i]);
    	//}
    	printf("\n");
    }
  
    // to destroy the message queue 
    msgctl(msgid, IPC_RMID, NULL); 
  }
    return 0; 
} 
