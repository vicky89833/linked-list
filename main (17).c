
#include<stdio.h>
#include<stdlib.h>

struct node
{
        int data;
        struct node *next;
};

struct node *front,*rear;
struct node enqueu(int id)
{    rear->data=id;
     rear->next=NULL;
};
struct node reversequeue()
{     
        
            
      struct node *temp,*temp2;
      temp=NULL;
      temp2=front->next;
      front->next=temp;
      temp=front;
      rear=front;
      front=temp2;
      while(front!=NULL)
      {
              
              
              temp2=front->next;
              
              front->next=temp;
              
              temp=front;
              front=temp2;
              
              
      }
      front = temp;
      
      
};

void printlist(struct node *front)
{  
        // printf(" hi2");
        struct node *temp;
        temp=front;
        while(temp!=NULL)
        {
                printf("%d ",temp->data);
                temp=temp->next;
        }
        
};
int main()
{ 
        int stregth,id;
        scanf("%d",&stregth);
        if(stregth==0)
        {
            
            printf("-*20");
            return 0;
        }
        
        if(stregth==1)
        {
            scanf("%d",&id);
            printf("%d",id);
            return 0;
        }
        front=malloc(sizeof(struct node));
        rear=front;
        
        for(int i=1;i<=stregth/2;i++)
        {
        // take input from 1 to stregth/2;
             scanf("%d",&id);
             enqueu(id);
             
             if(i!=stregth/2)
                {
                     struct node*temp =malloc(sizeof(struct node));
                     rear->next=temp;
                     rear=temp;
                }
                
        
        }
        
        // reverse it;
        reversequeue();
        // if(rear->next==NULL){
        // printf("%d\n",rear->data);}
        
        
        // take other input from n/2 + 1 to n in the same list
        for(int j=(stregth/2) ;j<stregth;j++)
        {
             
             
                     struct node*temp =malloc(sizeof(struct node));
                     rear->next=temp;
                     rear=temp;
                
             scanf("%d",&id);
             enqueu(id);
             
             
                
        
        }
        
        // and print all data using iteration
        
        printlist(front);
        
        return 0;
}
