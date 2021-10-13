#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

struct node* createNode();
void insertNode(struct node **h,int data);
void display(struct node **h);
void mergeLL(struct node **h1,struct node **h2);
void release(struct node **h);

struct node {
    int info;
    struct node *link;
};

int main() {
    struct node *head1=NULL,*head2=NULL;
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

    mergeLL(&head1,&head2);
    display(&head1);
    release(&head1);
    getch();
}

void insertNode(struct node **h,int data) {
    struct node *n,*t;
    n=createNode();
    n->info=data;
    if((*h)==NULL)
        (*h)=n;
    else {
        t=*h;
        while(t->link!=NULL)
            t=t->link;
        t->link=n;
    }

}

void mergeLL(struct node **h1,struct node **h2) {
    struct node *t;
    t=*h1;
    while(t->link!=NULL)
        t=t->link;
    t->link=*h2;
}

void display(struct node **h) {
    struct node *t;
    t=*h;
    while(t!=NULL) {
        printf("%d ",t->info);
        t=t->link;
    }
}

struct node* createNode() {
    struct node *n;
    n=(struct node*)malloc(sizeof(struct node));
    n->link=NULL;
    return(n);
}

void release(struct node **h) {
    struct node *t;
    t=*h;
    while(*h!=NULL) {
        t=*h;
        *h=(*h)->link;
        free(t);
    }
}