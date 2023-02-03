

#include <stdio.h>
#include <stdlib.h>

struct node
{
   struct node *prev;
   int data;
   struct node *next;
};
struct node *dequehead,*dequehead2;
struct node addque(int n)
{
    struct node *temp;
    if(dequehead==NULL)
    {
        dequehead=malloc(sizeof(struct node));
        dequehead->prev=NULL;
        dequehead->data=n;
        dequehead->next=NULL;
        dequehead2=dequehead;
    }
    else
    {
            temp=malloc(sizeof(struct node));
            temp->prev=dequehead2;
            dequehead2->next=temp;
            temp->data=n;
            temp->next=NULL; 
            dequehead2=temp;
            
    }
};
int max(int a,int b)
{
        if(a>b)
        {
                return a;
        }
        else
        {
                return b;
        }
};
int main()
{
    int n,k,val;
    scanf("%d",&n) ;
    scanf("%d",&k) ;
    for(int i=0;i<n;i++)
    {
        scanf("%d",&val) ;
        
        addque(val);    
    }
    
    struct node* temp2;
    temp2=dequehead;
    int sum=0;
    int maxi=0;
    struct node *temp;
    
    
    while(temp2!=NULL)
    {   
        
        
        temp=temp2;
        
        for(int j=1;j<=k;j++) 
        {
                
                maxi=max(maxi,temp->data);
                
                
                
                // && temp!=NULL
                if(j==k )
                {
                    
                    sum= sum + maxi;
                    
                }
                
                
                temp=temp->next;
                if(temp==NULL)
                {
                        printf("%d\n",sum);
                        return 0;
                }
                
        }
        temp2=temp2->next;
        maxi=0;
    }

    printf("%d",sum);
    
    return 0;
}
// SAMPLE INPUT 1
// 7 3
// 100 80 60 70 60 75 85
// SAMPLE OUTPUT 1
// 410
// SAMPLE INPUT 2
// 8 4
// 90 80 70 60 50 40 30 20
// SAMPLE OUTPUT 2
// 350
// SAMPLE INPUT 3
// 7 3
// 12 1 78 90 57 89 56



// SAMPLE OUTPUT 3
// 437



