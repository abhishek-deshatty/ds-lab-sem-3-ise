#include<stdio.h>
#include<ctype.h>
#define maxsize 50

struct opstk
{
    char stk[maxsize];
    int top;
};

int isEmpty(struct opstk *ptr)
{
    if (ptr->top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
 
int isFull(struct opstk *ptr)
{
    if (ptr->top == maxsize - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void push(struct opstk* ptr, char val){
    if(isFull(ptr)){
        printf("Stack Overflow! Cannot push %c to the stack\n", val);
    }
    else{
        ptr->top++;
        ptr->stk[ptr->top] = val;
    }
}
 
char pop(struct opstk* ptr){
    if(isEmpty(ptr)){
        printf("Stack Underflow! Cannot pop from the stack\n");
        return -1;
    }
    else{
        char val = ptr->stk[ptr->top];
        ptr->top--;
        return val;
    }
}

int prec(char ch){
    if (ch == '#' )
    {
        return 0;
    }
    else if (ch == '(' )
    {
        return 1;
    }
    
    else if(ch == '+' || ch=='-')
        return 2; 
    else if(ch == '*' || ch=='/')
        return 3;
    else if(ch == '^' || ch=='$')
        return 4; 
        return 0;
}

void infixToPostfix(char inf[maxsize], char posf[maxsize])
{
    char symb, s;
    struct opstk st;
    st.top=-1;
    int i=0, j=0;
    char c;
    push(&st, '#');
    while (inf[i]!='\0')
    {
        symb = inf[i];
       if (symb =='(')
       {
        push(&st, symb);
       }
       else if (isalnum(symb))
       {
        posf[j++]=symb;
       }
       else if (symb ==')')
       {
        while (1)
        {
            c = pop(&st);
            if(c=='(')
            {
                break;
            }
            posf[j++]=c;

        }
        
       }
       else
       {
            while (prec(symb) <= prec(st.stk[st.top]))
            {
                posf[j++] = pop(&st);
            }
            push(&st, symb);
            
       }
       i++;  
    }
    
    while (1)
    {
        c = pop(&st);
        if (c=='#')
        {
            break;
        }
        posf[j++]=c;
    }
    
    posf[j]='\0';

    printf("%s\n",posf);
    
}

void main()
{   
    char inf[maxsize] = "a+(((b-c)*(d-e)+f)/g)$(h-j)", posf[maxsize];
    //printf("Enter the infix expression\n");
    //scanf("%s", inf);
    infixToPostfix(inf, posf);
    printf("%s", posf);
}