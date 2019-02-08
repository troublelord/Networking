#include <stdio.h>
#include <unistd.h>

int prime(int arr[],int limit){
   int sum=0;
   if(fork()==0){//child
      for(int i=0;i<limit;i++){
         int flag=1;
         for(int j=2;j<=arr[i]/2;j++){
            if(arr[i]%j==0){//non prime
               flag=0;
               break;
            }
            
         }
         if(flag==1){
            sum+=arr[i];
            printf("child %d and sum %d\n",arr[i],sum);  
         }
      }
       printf("Sum of non prime is %d\n",sum);  
   }
   else{//parent
      for(int i=0;i<limit;i++){
          for(int j=2;j<=arr[i]/2;j++){
            if(arr[i]%j==0){
               sum+=arr[i];
                printf("parent %d and sum %d\n",arr[i],sum);  
               
               break;
            }
         }
      }
      printf("Sum of prime is %d\n",sum);  
   }
   
   return 0;
}
void main(){
   
   int limit;
   scanf("%d",&limit);
   int arr[limit];
   for(int i=0;i<limit;i++){
      printf("Enter number%d:",i+1);
      scanf("%d",&arr[i]);
   }
//printf();

   //for(int i=2;i<12;i++){
     // arr[i-2]=i;
  // }
   prime(arr,limit);

}    
