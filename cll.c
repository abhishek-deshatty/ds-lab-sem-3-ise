#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *next;
};

typedef struct Node* NODE;

NODE insertfront(NODE last,int ele){
    NODE q;
    q=(NODE)malloc(sizeof(struct Node));
    q->data=ele;
    q->next=q;
    if(last==NULL)
        return q;
    else{
        q->next=last->next;
        last->next=q;
        return last;
    }
}

NODE deletefront(NODE last){
    if(last==NULL){
        printf("No Elements to delete\n");
        return NULL;
    }
    else if(last->next==last){
        free(last);
        return NULL;
    }
    else{
        NODE s=last->next;
        last->next=s->next;
        free(s);
        return last;
    }
}

NODE insertrear(NODE last,int ele){
    NODE q;
    q=(NODE)malloc(sizeof(struct Node));
    q->data=ele;
    q->next=q;
    if(last==NULL)
        return q;
    else{
        q->next=last->next;
        last->next=q;
        return q;
    }
}


NODE deleterear(NODE last){
    if(last==NULL){
        printf("No Elements to delete\n");
        return NULL;
    }
    else if(last->next==last){
        free(last);
        return NULL;
    }
    else{
        NODE s=last->next;
        while(s->next!=last){
            s=s->next;
        }
        s->next=last->next;
        free(last);
        return s;
    }
}

int search(NODE last,int ele){
    int count=0;
    NODE s=last->next;
    if(s->data==ele){
        count++;
        return count;
    }
    else{
    while(s!=last){
        if(s->data==ele){
            count++;
            return count;
        }
        s=s->next;
        count++;
    }
    if(last->data==ele){
        count++;
        return count;
    }
    return -1;
    }
}

NODE insertpos(NODE last,int pos,int ele){
    NODE q;
    q=(NODE)malloc(sizeof(struct Node));
    q->data=ele;
    q->next=q;
    if(last==NULL)
        return q;
    else if(pos==1){
        q->next=last->next;
        last->next=q;
        return last;
    }
    else{
        NODE s=last->next;
        for(int i=0;i<pos-2;i++){
            s=s->next;
            if(s==last){
                printf("pos>size\n");
                q->next=last->next;
                last->next=q;
                return q;
            }
        }
        q->next=s->next;
        s->next=q;
        return last;
    }
}


NODE deletepos(NODE last,int pos){
    if(last==NULL){
        printf("No elements to delete\n");
        return NULL;
    }
    else if(last->next==last){
        free(last);
        return NULL;
    }
    else if(pos==1){
        NODE s=last->next;
        last->next=s->next;
        free(s);
        return last;
    }
    else{
        NODE s=last->next;
        NODE s1;
        for(int i=0;i<pos-1;i++){
            s1=s;
            s=s->next;
            if(s==last){
                printf("pos>size\n");
                last=deleterear(last);
                return last;
            }
        }
        s1->next=s->next;
        free(s);
        return last;
    }
}

void display(NODE last){
    if(last==NULL){
        printf("No elements to display\n");
        return ;
    }
    else{
        NODE s=last->next;
        while(s!=last){
            printf("%d\t",s->data);
            s=s->next;
        }
    printf("%d\n",s->data);
    }
}



void main(){
    NODE last=NULL;
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
                last=insertpos(last,pos,ele);
                break;
        case 2:printf("Enter position\n");
                scanf("%d",&pos);
                last=deletepos(last,pos);
                break;
        case 3:printf("Enter element\n");
                scanf("%d",&ele);
                last=insertfront(last,ele);
                break;
        case 4:last=deletefront(last);
                break;
        case 5:printf("Enter element\n");
                scanf("%d",&ele);
                last=insertrear(last,ele);
                break;
        case 6:last=deleterear(last);
                break;
        case 7:printf("Enter element to be searched\n");
                scanf("%d",&ele);
                if(search(last,ele)==-1){
                    printf("Not found\n");
                }
                else{
                    printf("found at %d\n",search(last,ele));
                }
                break;
        case 8:display(last);
                break;
        case 9:exit(0);
        default:printf("Invalid Choice\n");
    }
}
}