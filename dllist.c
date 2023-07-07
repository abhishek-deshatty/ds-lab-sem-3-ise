#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *next;
    struct Node *prev;
};

typedef struct Node* NODE;

NODE insertfront(NODE first,int ele){
    NODE q=(NODE)malloc(sizeof(struct Node));
    q->data=ele;
    q->next=q->prev=NULL;
    if(first==NULL){
        return q;
    }
    else{
        q->next=first;
        first->prev=q;
        return q;
    }
}

NODE deletefront(NODE first){
    if(first==NULL){
        printf("No elements to delete\n");
        return NULL;
    }
    else if(first->next==NULL){
        free(first);
        return NULL;
    }
    else{
        NODE s;
        s=first->next;
        s->prev=NULL;
        free(first);
        return s;
    }
}

NODE insertrear(NODE first,int ele){
    NODE q=(NODE)malloc(sizeof(struct Node));
    q->data=ele;
    q->next=NULL;
    q->prev=NULL;
    NODE s=first;
    if(first==NULL){
        return q;
    }
    else{
    while(s->next!=NULL){
        s=s->next;
    }
    q->prev=s;
    s->next=q;
    return first;
    }
}

NODE deleterear(NODE first){
    if(first==NULL){
        printf("No elements to delete\n");
        return NULL;
    }
    else if(first->next==NULL){
            free(first);
            return NULL;
        }
    else{
        NODE s1;
        NODE s=first;
        
        while(s->next!=NULL){
            s1=s;
            s=s->next;
        }
        s->prev=NULL;
        s1->next=NULL;
        free(s);
        return first;
    }
}

NODE insertpos(NODE first,int pos,int ele){
    NODE q=(NODE)malloc(sizeof(struct Node));
    q->data=ele;
    q->next=NULL;
    q->prev=NULL;
    if(first==NULL)
        return q;
    else if(pos==1){
        q->next=first;
        first->prev=q;
        return q;
    }
    else{
        NODE s=first;
        for(int i=0;i<pos-2;i++){
            if(s->next==NULL){
                q->prev=s;
                s->next=q;
                return first;
            }
            s=s->next;
        }
        q->next=s->next;
        q->prev=s;
        s->next=q;
        q->next->prev=q;
        return first;
    }
}

int search(NODE first,int ele){
    if(first==NULL){
        printf("No Elements to search\n");
        return -1;
    }
    else{
        NODE s=first;int count=0;
        while(s!=NULL){
            if(s->data==ele){
                count++;
                return count;
            }
            s=s->next;
            count++;
        }
    printf("NO such element\n");
    return -1;
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

void display(NODE first){
    if(first==NULL){
        printf("No elements to display\n");
    }
    else{
        NODE s=first;
        while(s!=NULL){
            printf("%d\t",s->data);
            s=s->next;
        }
        printf("\n");
    }
}

void main(){
    NODE first=NULL;
    int ch;
    int ele,pos;
    while(1){
        printf("enter 1.insertpos\t 2.deletepos\t 3.insertFront\t 4.deleteF \n 5.insRe \t6.delRe \t 7.search\t 8.display\t 9.EXIT!\n");
        scanf("%d",&ch);
    switch(ch){
        case 1:printf("Enter element\n");
                scanf("%d",&ele);
                printf("Enter position\n");
                scanf("%d",&pos);
                first=insertpos(first,pos,ele);
                break;
        case 2:printf("Enter position\n");
                scanf("%d",&pos);
                first=deletepos(first,pos);
                break;
        case 3:printf("Enter element\n");
                scanf("%d",&ele);
                first=insertfront(first,ele);
                break;
        case 4:first=deletefront(first);
                break;
        case 5:printf("Enter element\n");
                scanf("%d",&ele);
                first=insertrear(first,ele);
                break;
        case 6:first=deleterear(first);
                break;
        case 7:printf("Enter element to be searched\n");
                scanf("%d",&ele);
                if(search(first,ele)==-1){
                    printf("Not found\n");
                }
                else{
                    printf("found at %d\n",search(first,ele));
                }
                break;
        case 8:display(first);
                break;
        case 9:exit(0);
        default:printf("Invalid Choice\n");
    }
}
}