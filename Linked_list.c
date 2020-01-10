#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include<conio.h>
void create();
void display();
void insert();
void del();
struct node
{
    int data;
    struct node *next;
};
struct node *start = NULL;
int main()
{
    int ch;
    do
    {
        printf("1.Create a data\n");
        printf("2.Display a data\n");
        printf("3.Insert a data\n");
        printf("4.delete a data\n");
        printf("Enter your choice\n");
        scanf("%d",&ch);
        switch(ch)
        {
        case 1:
            create();
            break;
        case 2:
            display();
            break;
        case 3:
            insert();
            break;
        case 4:
            del();
            break;
        default:
            printf("Invalid input\n");
        }
    }while(ch!=5);
    return 0;
}
void create()
{
    struct node *new_node,*ptr;
    int n;
    printf("How may data needed to allocate\n");
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        new_node=(struct node*)malloc(sizeof(struct node));
        printf("Enter the data\n");
        scanf("%d",&new_node->data);
        if(start==NULL)
        {
            new_node->next=NULL;
            start=new_node;
        }
        else
        {
            ptr=start;
            while(ptr->next!=NULL)
            ptr=ptr->next;
            ptr->next=new_node;
            new_node->next=NULL;
        }
    }
}
void display()
{
    struct node *ptr=start;
    int count=0;
    printf("The data is .....\n");
    while(ptr!=NULL)
    {
        printf("%d ",ptr->data);
        ptr=ptr->next;
        count++;
    }
    printf("\nThe number of nodes are %d\n",count);
}
void insert()
{
    int ch;
    struct node *new_node,*ptr;
    do
    {
        printf("1.Insert in the beg\n");
        printf("2.Insert in the end\n");
        printf("Enter your choice\n");
        scanf("%d",&ch);
        switch(ch)
        {
        case 1:
            new_node=(struct node*)malloc(sizeof(struct node));
            printf("Enter the value to be entered in the beginning\n");
            scanf("%d",&new_node->data);
            new_node->next=start;
            start=new_node;
            display();
            break;
        case 2:
            new_node=(struct node*)malloc(sizeof(struct node));
            printf("Enter the data to be entered at the last\n");
            scanf("%d",&new_node->data);
            new_node->next=NULL;
            ptr=start;
            while(ptr->next!=NULL)
                ptr=ptr->next;
            ptr->next=new_node;
            display();
            break;
        default:
            printf("Invalid Input\n");
        }
    }while(ch!=3);
}
void del()
{
    struct node *ptr,*preptr;
    int ch;
    do
    {
        printf("1.Delete in the beginning\n");
        printf("2.Delete in the end\n");
        printf("Enter your choice\n");
        scanf("%d",&ch);
        switch(ch)
        {
        case 1:
            ptr=start;
            start=start->next;
            free(ptr);
            display();
            break;
        case 2:
            ptr=start;
            while(ptr->next!=NULL)
            {
                preptr=ptr;
                ptr=ptr->next;
            }
            preptr->next=NULL;
            free(ptr);
            display();
            break;
        }
    }while(ch!=3);
}
