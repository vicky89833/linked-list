/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/
// import library
#include <stdio.h>
#include<stdlib.h>

// make a stucture for node with has value and pointer
struct node
{
        int data;
        struct node *next;
};
// exucutible function start after main() that is { 
int main()
{       int n;  
// n is number for which we want to convert it into binary number
        scanf("%d",&n);
        struct node *head;
        // allocate memory to head pointer
        head = malloc(sizeof(struct node));
        head->data=n%2;
        head->next =NULL;
        struct node *head1;
        // head1 is a pointer used as variable pointer
        head1=head;
        n=n/2;
        
        while(n>0)
        {
            struct node *cnode;
            cnode = malloc(sizeof(struct node));
            cnode->data=n%2;
            cnode->next =NULL;
            head1->next=cnode; 
        //     update head1 by  head1=head1->next;
            head1=head1->next;
            n=n/2;
        }
        if(head==NULL)
        {
                printf("Empty linked list");
                
        }
        while (head!=NULL)
        {
                printf("%d",head->data);
                head=head->next;
        }
    return 0;
}
