/******************************************************************************

In this lab assignment you will be writing a C program which will first convert the two given
decimal numbers into their binary format and then perform binary addition on those binary
numbers. You need to implement the following two methods for the given task.
(a) Using Singly Linked List: In this method first you will convert a given decimal number [3]
into its binary format and store different bits sequentially in different nodes of a singly
linked list. Then you will reverse (in-place) the singly linked list. After that you will
perform addition using the two reversed singly linked list and store the result into another
singly linked list. If carry is generated then you have to create a node for it insert into
the resultant singly linked list.

Sample Input data (provided by the user):
Number 1 : 35
Number 2 : 42
Binary Representation of 35 is 100011 and 42 is 101010.
Reverse of 100011 is 110001 and 101010 is 010101
Addition of the binary number will be 1001101
Output: Your output will be in the following format (note the reverse order of binary
representation):
1 → 0 → 1 → 1 → 0 → 0 → 1
77

*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>

struct node 
{
        int data;
        struct node *next;
};
void printdata(struct node *head)
{     
        // we can print data without 'if(head!= NULL)' but i used it to print data in with arrow(->)
      if(head!= NULL)
      {
           printf("%d ",head->data);
           head=head->next;
               
      }
       while(head!= NULL)
            {     
                 printf(" ->%d ",head->data);
                 head=head->next;
            }
            
};

// ***************************************************************************************************************

struct node* linkedlist(struct node *head)

{   
    int n;        
    scanf("%d",&n);
    struct node *temp,*temp2;
    head=malloc(sizeof(struct node));
    head->next=NULL;
    head->data=n%2;
    n=n/2;
    temp=malloc(sizeof(struct node));
    head->next=temp;
    while(n>0)
    {
            
            temp->next=NULL;
            temp->data=n%2;
            n=n/2;
            if (n<=0)
            { continue;}
            temp2=malloc(sizeof(struct node));
            temp->next=temp2;
            temp=temp2;
    }

//     printdata(head);
    return head;
};


// *********************************************************************************************************
struct node* reverselinkedlist1(struct node *head1)

{       
        // printf("hi we are into reverse funtion");
        struct node *temp,*temp2;
        temp=NULL;
        temp2=NULL;
        while(head1!=NULL)
        {
                temp2=head1->next;
                head1->next=temp;
                temp=head1;
                head1=temp2;
        }
        head1=temp;
        int result =0;
        while(head1!=NULL)
        {
                if (head1->data==1)
                {
                        result=result*2 +1;
                }
                else
                {
                        result=result*2;
                }
                head1=head1->next;
        }
        printf("\n%d\n",result);
        return 0;
};
 
// ***********************************************************************************************************

int main()
{
        struct node *head1;
        
        head1=linkedlist(head1);
        printf("\n");
        // printf("\n %d \n",head1->data);
        struct node *head2;
        head2=linkedlist(head2);
        printf("\n");
        // printf("\n %d \n",head2->data);
        int a=(head1->data) + (head2->data);
        // printf("\n %d \n",a);
        struct node *head ,*temp2,*temp;
        head=malloc(sizeof(struct node));
        head->next=NULL;
        head->data=a%2;
        a=a/2;
        temp=malloc(sizeof(struct node));
        head->next=temp;             
    
        head1=head1->next;
        head2=head2->next;   
        

        while(1)
        {
                // printf("while loop execution started.");
                a= a+(head1->data) + (head2->data);
                temp->next=NULL;
                temp->data=a%2;
                a=a/2;
                head1=head1->next;
                head2=head2->next;
                // if contdition is created for last step when we have 1 but head1==NULL&&head2==NULL
                if((head1==NULL&&head2==NULL))
                {  
                        temp2=malloc(sizeof(struct node));
                        temp->next=temp2;
                        temp=temp2;
                        temp->next=NULL;
                        temp->data=a%2;
                        break;
                }
                temp2=malloc(sizeof(struct node));
                temp->next=temp2;
                temp=temp2;
                
                
        }
       
//     printf("%d",head->next->data);
//     printf("%d",head->next->next->data);
        
        
        printdata(head);
        // printf("\n %d \n",head->data);
        reverselinkedlist1(head);
        

}
