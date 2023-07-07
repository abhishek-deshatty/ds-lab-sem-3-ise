#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node* next;
};

struct Queue{
    struct Node* front;
    struct Node* rear;
};

struct Node* newNode(int data){
    struct Node* node=(struct Node*)malloc(sizeof(struct Node));
    node->data=data;
    node->next=NULL;
    return node;
}

struct Queue* createQ(){
    struct Queue* q=(struct Queue*)malloc(sizeof(struct Queue));
    q->front=NULL;
    q->rear=NULL;
    return q;
}

void enqueue(struct Queue* q,int ele){
    struct Node* temp=newNode(ele);
    if(q->rear==NULL){
        q->front=q->rear=temp;
        return;
    }
    q->rear->next=temp;
    q->rear=temp;
}

int dequeue(struct Queue* q){
    if(q->front==NULL){
        printf("No elements\n");
        return -1;
    }
    int data=q->front->data;
    struct Node* temp=q->front;
    q->front=q->front->next;
    free(temp);
    if(q->front==NULL)q->rear=NULL;
    return data;
}


int search(struct Queue* q,int ele){
    struct Node* temp=q->front;
    int count=0;
    while(temp!=NULL){
        if(temp->data==ele){
            count++;
            return count;
        }
        temp=temp->next;
        count++;
    }
    printf("Not found\n");
    return -1;
}

void display(struct Queue* q){
    struct Node* temp=q->front;
    while(temp!=NULL){
        printf("%d\t",temp->data);
        temp=temp->next;
    }
    printf("\n");
}

int main() {
    struct Queue* q = createQ();
    int ch,ele,p,c;
    while(1){
        printf("Enter 1.push\t2.pop\t3.search\t4.display\n");
        scanf("%d",&ch);
        switch(ch){
            case 1:printf("Enter element\n");
                    scanf("%d",&ele);
                    enqueue(q,ele);
                    break;
            case 2:p=dequeue(q);
                    if(p!=-1)printf("%d is poped\n",p);
                    else
                    printf("No elements\n");
                    break;
            case 3:printf("Enter element\n");
                    scanf("%d",&ele);
                    c=search(q,ele);
                    if(c!=-1)printf("Fount at %d\n",c);
                    break;
            case 4:display(q);
                    break;
        }
    }
    return 0;
}