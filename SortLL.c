#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

struct node* createNode();
void insertNode(struct node **h,int data);
void display(struct node **h);
void release(struct node **h);
void sortLL(struct node **h);

struct node {
    int info;
    struct node *link;
};

int main() {
    struct node *head=NULL;
    insertNode(&head,10);
    insertNode(&head,40);
    insertNode(&head,60);
    insertNode(&head,20);
    insertNode(&head,80);
    insertNode(&head,30);
    insertNode(&head,90);

    sortLL(&head);
    display(&head);
    release(&head);
    getch();
}

void sortLL(struct node **h) {
    struct node *t;
    int n=0,i,j,temp;
    t=*h;
    while(t!=NULL) {
        n++;
        t=t->link;
    }// n represent no. of elements in LL
    //  Bubble Sort
    for(i=1; i<=n; i++){
        t=*h;
        for(j=1; j<=n-i; j++) {
            if(t->info>t->link->info) {
                temp=t->info;
                t->info=t->link->info;
                t->link->info=temp;
            }
        t=t->link;
        }
    }
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