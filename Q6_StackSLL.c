#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *next;
};

struct Stack{
    struct Node* top;
};

struct Stack* createstack(){
    struct Stack* stack=(struct Stack*)malloc(sizeof(struct Stack));
    stack->top=NULL;
    return stack;
}

void push(struct Stack* stack,int ele){
    struct Node* p=(struct Node*)malloc(sizeof(struct Node));
    p->data=ele;
    p->next=stack->top;
    stack->top=p;
}

int pop(struct Stack* stack){
    if(stack->top==NULL){
        return -1;
    }
    int data=stack->top->data;
    struct Node* temp=stack->top;
    stack->top=stack->top->next;
    free(temp);
    return data;
}

int search(struct Stack* stack,int ele){
    struct Node* current=stack->top;
    int count=0;
    while(current!=NULL){
        if(current->data==ele){
            count++;
            return count;
        }
        current=current->next;
        count++;
    }
    printf("Not found\n");
    return -1;
}


void display(struct Stack* stack){
    struct Node* s=stack->top;
    while(s!=NULL){
        printf("%d\t",s->data);
        s=s->next;
    }
    printf("\n");
}

int main() {
    struct Stack* stack = createstack();
    int ch,ele,p,c;
    while(1){
        printf("Enter 1.push\t2.pop\t3.search\t4.display\n");
        scanf("%d",&ch);
        switch(ch){
            case 1:printf("Enter element\n");
                    scanf("%d",&ele);
                    push(stack,ele);
                    break;
            case 2:p=pop(stack);
                    if(p!=-1)printf("%d is poped\n",p);
                    else
                    printf("No elements\n");
                    break;
            case 3:printf("Enter element\n");
                    scanf("%d",&ele);
                    c=search(stack,ele);
                    if(c!=-1)printf("Fount at %d\n",c);
                    break;
            case 4:display(stack);
                    break;
        }
    }
}