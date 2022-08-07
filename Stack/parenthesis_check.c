#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct stack
{
    int top,size;char *arr;
}stack;
void push(stack *s,char n)
{
    s->arr[++(s->top)]=n;
}
void pop(stack *s)
{
    s->top--;
}
int check_parenthesis(char *s)
{
    stack *ss=(stack*)malloc(sizeof(stack));
    ss->top=-1;
    ss->arr=(char*)malloc(1000*sizeof(char));
    ss->size=strlen(s);
    for(int i=0;s[i]!='\0';i++)
    {
        if(s[i]=='(')
        push(ss,s[i]);
        else if(s[i]==')')
        {
            if(ss->top==-1)
            return 0;
            if(ss->arr[ss->top]=='(')
            pop(ss);
            else
            return 0;
        }
        if(s[i]=='{')
        push(ss,s[i]);
        else if(s[i]=='}')
        {
            if(ss->top==-1)
            return 0;
            if(ss->arr[ss->top]=='{')
            pop(ss);
            else
            return 0;
        }
        if(s[i]=='[')
        push(ss,s[i]);
        else if(s[i]==']')
        {
            if(ss->top==-1)
            return 0;
            if(ss->arr[ss->top]=='[')
            pop(ss);
            else
            return 0;
        }
    }
    if(ss->top==-1)
    return 1;
    else
    return 0;

}
int main()
{
    char s[1000];
    scanf("%[^\n]",s);
    if(check_parenthesis(s)==1)
    printf("Balanced Brackets");
    else
    printf("Unbalanced Brackets");
}