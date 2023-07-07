#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* next;
    struct node* prev;
};

typedef struct node* NODE;

NODE getnode(){
    NODE p=(NODE)malloc(sizeof(struct node));
    return p;
}

NODE insertF(NODE first,int ele){
    NODE q=getnode();
    q->data=ele;
    if(first==NULL){
        q->next=q->prev=NULL;
        return q;
    }
    else{
        q->next=first;
        first->prev=q;
        q->prev=NULL;
        first=q;
        return first;
    }
}

NODE deletepos(NODE first,int pos){
    if(first==NULL){
        printf("deletion not possible\n");
        return NULL;
    }
    else if(pos==1){
        if(first->next==NULL)
            return NULL;
        NODE q=first;
        first=first->next;
        first->prev=NULL;
        free(q);
        return first;
    }
    else{
        NODE s=first;
        NODE prev1;
        for(int i=0;i<pos-1;i++){
            prev1=s;
            s=s->next;
            if(s==NULL){
                printf("pos>size,deletion not possible\n");
                return first;
            }
        }
        prev1->next=s->next;
        if(s->next!=NULL){
        s->next->prev=prev1;}
        printf("Deleted element is %d\n",s->data);
        free(s);
        return first;
    }
}

void printasc(NODE first){
    if(first==NULL){
        printf("NO elements\n");
        return;
    }
    NODE s=first;
    while(s!=NULL){
        printf("%d\t",s->data);
        s=s->next;
    }
    printf("\n");
}

void printdes(NODE first){
    if(first==NULL){
        printf("NO elements\n");
        return;
    }
    NODE s=first;
    while(s->next!=NULL){
        s=s->next;
    }
    while(s!=NULL){
        printf("%d\t",s->data);
        s=s->prev;
    }
    printf("\n");
}


void main(){
    int ch,ele,pos;
    NODE first=NULL;
    while(1){
        printf("Enter 1.insertFront\t2.DeletePos\t3.PrintAsc\t4.Desc\t5.Exit!!\n");
        scanf("%d",&ch);
        switch(ch){
            case 1:printf("Enter element\n");
                    scanf("%d",&ele);
                    first=insertF(first,ele);
                    break;
            case 2:printf("Enter position\n");
                    scanf("%d",&pos);
                    first=deletepos(first,pos);
                    break;
            case 3:printasc(first);
                    break;
            case 4:printdes(first);
                    break;
            case 5:exit(0);
                    break;
            default:printf("Invalid Choice\n");
        }
    }
}