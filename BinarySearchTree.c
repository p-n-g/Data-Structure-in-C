#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

struct BSTNode{
    int info;
    struct BSTNode *left;
    struct BSTNode *right;
};

struct BSTNode* createBSTNode();
void insertBSTNode(struct BSTNode **r,int data);
void inorderDisplay(struct BSTNode *r);
void releaseBST(struct BSTNode *r);

struct BSTNode* createBSTNode(){
    struct BSTNode *n;
    n=(struct BSTNode*)malloc(sizeof(struct BSTNode));
    n->left=NULL;
    n->right=NULL;
    return n;
}

void insertBSTNode(struct BSTNode **r,int data){
    struct BSTNode *t,*n;
    n=createBSTNode();
    n->info=data;

    if(*r==NULL)
        *r=n;
    else{
        t=*r;
        while(t->left!=NULL && t->right!=NULL){
            if(t->info<data)
                t=t->right;
            else
                t=t->left;
        }
        if(t->info<data)
            t->right=n;
        else
            t->left=n;
    }
}

void inorderDisplay(struct BSTNode *r){
    if(r==NULL)
        return;
    if(r->left!=NULL){
        inorderDisplay(r->left);
        printf("%d ",r->info);
        inorderDisplay(r->right);
    }
    else{
        printf("%d ",r->info);
        inorderDisplay(r->right);
    }
}

void releaseBST(struct BSTNode *r){
    if(r==NULL)
        return;
    if(r->left!=NULL){
        releaseBST(r->left);
        r->left=NULL;
        releaseBST(r->right);
        r->right=NULL;
    }
    else{
        releaseBST(r->right);
        r->right=NULL;
    }
    if(r->left==NULL && r->right==NULL){
        free(r);
    }
}

int main(){
    struct BSTNode *root=NULL;
    int choice,data;
    while(1){
        system("cls");
        printf("1. Insert a node in BST\n");
        printf("2. Display BST in inorder form\n");
        printf("3. Exit\n");

        printf("Enter your choice\n");
        scanf("%d",&choice);

        switch(choice){
            case 1:
                printf("Enter data:\n");
                scanf("%d",&data);
                insertBSTNode(&root,data);
                break;
            case 2:
                inorderDisplay(root);
                getch();
                break;
            case 3:
                releaseBST(root);
                exit(0);
            default:
                printf("Enter a valid choice\n");
        }
    }
}
