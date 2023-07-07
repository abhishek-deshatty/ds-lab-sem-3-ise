#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* llink;
    struct node* rlink;
};

typedef struct node* NODE;

NODE getnode(){
    NODE temp=(NODE)malloc(sizeof(struct node));
    temp->llink=NULL;
    temp->rlink=NULL;
    return temp;
}

NODE insert(NODE root,int ele){
    NODE temp=getnode();
    temp->data=ele;
    if(root==NULL){
        return temp;
    }
    else{
        NODE p=root;
        while(1){
            if(ele>p->data){
                if(p->rlink==NULL){
                    p->rlink=temp;
                    break;
                }
                p=p->rlink;
            }
            else{
                if(p->llink==NULL){
                    p->llink=temp;
                    break;
                }
                p=p->llink;
            }
        }
        return root;
    }
}

void inorder(NODE root){
    if(root==NULL)
        return;
    inorder(root->llink);
    printf("%d\t",root->data);
    inorder(root->rlink);
}

void preorder(NODE root){
    if(root==NULL)
        return;
    printf("%d\t",root->data);
    preorder(root->llink);
    preorder(root->rlink);
}

void postorder(NODE root){
    if(root==NULL)
        return;
    postorder(root->llink);
    postorder(root->rlink);
    printf("%d\t",root->data);
}

NODE search(int item,NODE root){
    if(root==NULL)
        return NULL;
    else{
        NODE cur=root;
        while(cur!=NULL){
            if(item==cur->data){
                printf("Item found\n");
                return cur;
            }
            if(item>cur->data)
                cur=cur->rlink;
            else{
                cur=cur->llink;
            }
        }
        printf("Not found\n");
        return NULL;
    }
}

void main(){
    int ch,ele;
    NODE root=NULL;
    while(1){
        printf("1.Insert\t2.Inorder\t3.Preorder\t4.Postorder\t5.Search!!\n->");
        scanf("%d",&ch);
        switch(ch){
            case 1:
            printf("Enter the element\n");
            scanf("%d",&ele);
            root = insert(root,ele);
            break;
        case 2:
            inorder(root);
            printf("\n");
            break;
        case 3:
            preorder(root);
            printf("\n");
            break;
        case 4:
            postorder(root);
            printf("\n");
            break;
        case 5:printf("Enter the element to be searched\n");
            scanf("%d",&ele);
            search(ele,root);
            break;

        default:
            break;
        }
    }
}