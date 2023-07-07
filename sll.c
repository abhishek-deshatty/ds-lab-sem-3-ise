#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *next;
};

typedef struct Node* NODE;

NODE insertfront(NODE p,int ele){
    NODE q;
    q=(NODE)malloc(sizeof(struct Node));
    q->data=ele;
    q->next=NULL;
    if(p==NULL){
        return q;
    }
    else{
        q->next=p;
        return q;
    }
}

NODE deletefront(NODE p){
    if(p==NULL){
        printf("No Elements to delete\n");
        return NULL;
    }
    else{
        NODE s=p;
        p=p->next;
        free(s);
        return p;
    }
}

NODE insertrear(NODE p,int ele){
    NODE q;
    q=(NODE)malloc(sizeof(struct Node));
    q->data=ele;
    q->next=NULL;
    if(p==NULL){
        return q;
    }
    else{
        NODE s=p;
        while(s->next!=NULL){
            s=s->next;
        }
        s->next=q;
        return p;
    }
}

NODE deleterear(NODE p){
    if(p==NULL){
        printf("No Elements to delete\n");
        return NULL;
    }
    else{
        NODE s=p;NODE s1;
        if(s->next==NULL){
            free(s);
            return NULL;
        }
        while(s->next!=NULL){
            s1=s;
            s=s->next;
        }
        s1->next=NULL;
        free(s);
        return p;
    }
}

int search(NODE p,int ele){
    if(p==NULL){
        printf("No Elements to search\n");
        return -1;
    }
    else{
        NODE s=p;int count=0;
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

NODE insertpos(NODE p,int pos,int ele){
    NODE q;
    q=(NODE)malloc(sizeof(struct Node));
    q->data=ele;
    q->next=NULL;
    if(p==NULL)
        return q;
    else if(pos==1){
        q->next=p;
        p=q;
        return p;
    }
    else{
        NODE s=p;
        for(int i=0;i<pos-2;i++){
            if(s->next==NULL){
                printf("pos>size\n");
                s->next=q;
                return p;
            }
            s=s->next;
            /*if(s==NULL){
                printf("pos>size\n");
                p=insertrear(p,ele);
                return p; 
            }*/
        }
        q->next=s->next;
        s->next=q;
        return p;
    }
}


NODE deletepos(NODE p,int pos){
    if(p==NULL){
        printf("No elements to delete\n");
        return NULL;
    }
    else if(pos==1){
        NODE temp=p;
        p=p->next;
        free(temp);
        return p;
    }
    else{
        NODE s=p;
        NODE s1;
        for(int i=0;i<pos-1;i++){
            s1=s;
            s=s->next;
            if(s==NULL){
                printf("pos>size\n");
                return p;
            }
        }
        s1->next=s->next;
        free(s);
        return p;
    }
}

void display(NODE p){
    NODE s=p;
    if(p==NULL){
        printf("No elements to display\n");
        return;
    }
    else{
    while(s!=NULL){
        printf("%d\t",s->data);
        s=s->next;
    }
    printf("\n");
    }
}



void main(){
    NODE p=NULL;
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
                p=insertpos(p,pos,ele);
                break;
        case 2:printf("Enter position\n");
                scanf("%d",&pos);
                p=deletepos(p,pos);
                break;
        case 3:printf("Enter element\n");
                scanf("%d",&ele);
                p=insertfront(p,ele);
                break;
        case 4:p=deletefront(p);
                break;
        case 5:printf("Enter element\n");
                scanf("%d",&ele);
                p=insertrear(p,ele);
                break;
        case 6:p=deleterear(p);
                break;
        case 7:printf("Enter element to be searched\n");
                scanf("%d",&ele);
                int d=search(p,ele);
                if(d==-1){
                    printf("Not found\n");
                }
                else{
                    printf("found at %d\n",d);
                }
                break;
        case 8:display(p);
                break;
        case 9:exit(0);
        default:printf("Invalid Choice\n");
    }
}
}