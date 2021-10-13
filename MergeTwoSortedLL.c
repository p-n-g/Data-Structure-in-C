#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

struct node{
    int info;
    struct node *link;
};

struct node* createNode();
void insertNode(struct node **h,int data);
void display(struct node **h);
struct node* mergeTwoSortedLL(struct node **h1,struct node **h2);
void release(struct node **h);

void release(struct node **h){
    struct node *t;
    while(*h!=NULL){
        t=*h;
        (*h)=(*h)->link;
        free(t);
    }
}

struct node* mergeTwoSortedLL(struct node **h1,struct node **h2){
    struct node *t1,*t2,*head,*t;
    head=createNode();
    t=head;
    t1=*h1; t2=*h2;

    while(t1!=NULL && t2!=NULL){
        if(t1->info > t2->info){
            t->info=t2->info;
            t2=t2->link;
        }
        else{
            t->info=t1->info;
            t1=t1->link;
        }
        t->link=createNode();
        t=t->link;
    }

    if(t2==NULL){
        while(t1!=NULL){
            t->info=t1->info;
            t1=t1->link;

            if(t1!=NULL){
                t->link=createNode();
                t=t->link;
            }
            else
                t->link=NULL;
        }
    }
    else{
        while(t2!=NULL){
            t->info=t2->info;
            t2=t2->link;

            if(t2!=NULL){
                t->link=createNode();
                t=t->link;
            }
            else
                t->link=NULL;
        }
    }
    return head;
}

void display(struct node **h){
    struct node *t;
    t=*h;
    while(t!=NULL){
        printf("%d ",t->info);
        t=t->link;
    }
    printf("\n");

}
void insertNode(struct node **h,int data){
    struct node *n,*t;
    n=createNode();
    n->info=data;
    if((*h)==NULL){
        (*h)=n;
        return;
    }
    t=*h;
    while(t->link!=NULL)
        t=t->link;
    t->link=n;
}
struct node* createNode(){
    struct node *n;
    n=(struct node*)malloc(sizeof(struct node));
    n->link=NULL;
    return n;
}

int main(){
    struct node *head1=NULL,*head2=NULL,*head=NULL;
    int i,cap,data;

    scanf("%d",&cap);
    for(i=0;i<cap;i++) {
        scanf("%d",&data);
        insertNode(&head1,data);
    }

    scanf("%d",&cap);
    for(i=0;i<cap;i++) {
        scanf("%d",&data);
        insertNode(&head2,data);
    }
    /*insertNode(&head1,10);
    insertNode(&head1,20);
    insertNode(&head1,30);
    insertNode(&head1,40);
    insertNode(&head1,50);

    insertNode(&head2,5);
    insertNode(&head2,15);
    insertNode(&head2,25);*/

    head=mergeTwoSortedLL(&head1,&head2);
    display(&head1);
    display(&head2);
    display(&head);

    release(&head1);
    release(&head2);
    release(&head);
    getch();

}