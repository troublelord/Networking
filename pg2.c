#include<stdio.h>
#include<unistd.h>
void nfork(int n){
   if(n==0)
    return;
   int pid=getpid(); 
   if(fork()==0){//child
      printf("The parent process %d has child process %d\n",pid,getpid());//generates the right childs
      nfork(--n);
   }
   else{//parent process
      printf("The parent process %d has parent process %d\n",pid,getpid());//generates the left childs
      nfork(--n);
   }
    
}

void main(){
   int n;
   printf("Enter the value of n:");
   scanf("%d",&n);
   nfork(n);
}
