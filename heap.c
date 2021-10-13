#include<stdio.h>
#include<stdlib.h>

struct heap* createHeap(int capacity);
void insertInHeap(struct heap *h,int data);
void heapifyFromBottom(struct heap *h,int c);
int deleteInHeap(struct heap *h);
void heapifyFromTop(struct heap *h,int p);
void swap(int *a,int *b);
void display(struct heap *h);

struct heap
{
    int capacity; //currently how much is the capacity of heap array or say tree ??
    int count; //currently how many elements are present in heap array or say tree
    int *array; //pointer containing the actual address of the array
};

int main()
{
    struct heap *h;
    int choice,capacity,data;
    printf("Enter initial capacity of Heap\n");
    scanf("%d",&capacity);
    h=createHeap(capacity);
    while(1)
    {
        system("cls");
        printf("1. Insert in Heap\n");
        printf("2. Delete in Heap\n");
        printf("3. Display Heap\n");
        printf("4. Exit\n\n");

        printf("Enter your choice\n");
        scanf("%d",&choice);
        printf("\n");
        switch(choice)
        {
            case 1:
                printf("Enter data\n");
                scanf("%d",&data);
                insertInHeap(h,data);
                break;
            case 2:
                data=deleteInHeap(h);
                printf("Deleted value is %d\n",data);
                getch();
                break;
            case 3:
                display(h);
                getch();
                break;
            case 4:     
                free(h->array);
                free(h);
                exit(0);
            default:
                printf("Enter valid choice\n");
                getch();
        }
    }
}

int deleteInHeap(struct heap *h)
{
    int data;
    if(h->count==0)
    {
        printf("Heap is empty, can't delete\n");
        return -1;
    }
    data=h->array[0];
    h->array[0]=h->array[h->count-1];
    h->count--;
    heapifyFromTop(h,0);
    return data;
}

void heapifyFromTop(struct heap *h,int p) // p=parent index   n=no. of elements in heap or sub heap
{
    int c1,c2; // c1=left child c2=right child
    c1=2*p+1;   c2=2*p+2;
    if(c1<=h->count-1 || c2<=h->count-1)
    {
        if(h->array[c1]<h->array[c2])
        {
            swap(&h->array[p],&h->array[c2]);
            heapifyFromTop(h,c2);
        }
        else
        {
            swap(&h->array[c1],&h->array[p]);
            heapifyFromTop(h,c1);
        }
    }
}

void insertInHeap(struct heap *h,int data)
{
    if(h->capacity==h->count) // is heap array full
    {
        h->array=(int*)realloc(h->array,sizeof(int)*2*h->capacity);
        h->capacity=2*h->capacity;
    }
    if(h->count==0) // is array empty
    {
        h->array[0]=data;
        h->count++;;
        return;
    }
    else
    {
        h->array[h->count]=data;
        h->count++;
        heapifyFromBottom(h,h->count-1);
    }
}

void heapifyFromBottom(struct heap *h,int c)
{
    int p; // representing the index. c=child index   p=parent index
    if(c!=0) // bhai root kabse kiska child hone lag gaya !!
    {
        p=(c-1)/2;
        if(h->array[c]<h->array[p]) // is child < parent ??
            return;
        else // is child > parent ??
        {
            swap(&h->array[c],&h->array[p]);
            c=p;
            heapifyFromBottom(h,c);
        }
    }
}

struct heap* createHeap(int capacity) // a function to just create "DHACHA" of heap and in return it gives the address of the heap variable created by malloc
{
    struct heap *h;
    h=(struct heap*)malloc(sizeof(struct heap));
    h->capacity=capacity;
    h->count=0;
    h->array=(int*)malloc(sizeof(int)*capacity);
    return h;
}

void display(struct heap *h)
{
    int i;
    for(i=0; i<h->count; i++)
        printf("%d ",h->array[i]);
    printf("\n");
}

void swap(int *a,int *b)
{
    int temp;
    temp=*a;
    *a=*b;
    *b=temp;
}