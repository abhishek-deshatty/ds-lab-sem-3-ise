#include<stdio.h>
#include<ctype.h>
#include<math.h>
#define max_size 100

struct opstk{
        int stk[max_size];
        int top;
};

int checkOverflow(int top)
{
        if(top==max_size-1)
                return 1;
        return 0;
}

int checkUnderflow(int top)
{
        if(top==-1)
                return 1;
        return 0;
}

void push(struct opstk *ptr, int n)
{
        if(checkOverflow(ptr->top))
        {
                printf("Stack Overflow\n");
        }
        else{
                ptr->top++;
                ptr->stk[ptr->top]=n;
        }
}

int pop(struct opstk *ptr)
{
        if(checkUnderflow(ptr->top)){
                        printf("Stack Underflow\n");
                        return 0;
        }
        else{
                return ptr->stk[ptr->top--];
        }
}

int posteval(char posf[100]){
        struct opstk st;
        st.top=-1;
        int i=0, c,a,b;
        char ch;
        while(posf[i]!='\0')
        {
                ch = posf[i];
                if(isdigit(ch))
                {
                        push(&st ,ch-'0');
                }
                else{
                        a = pop(&st);
                        b = pop(&st);


             switch(ch)
        {

                case '+': c = a+b;
                          break;
                case '-':
                        c = b-a;
                          break;

                case '*': c = a*b;
                          break;
                case '/':
                        c = b/a;
                          break;

                case '^': 
                case '$':c = pow(b,a);
                          break;

        }
             push(&st, c);

        }

                i++;
                }
        return pop(&st);
        }

int main()
{
        char posf[100];
        printf("Enter postfix expression\n");
        scanf("%s", posf);
        int ans = posteval(posf);
        printf("%s = %d\n", posf, ans);
        return 0;
}
  