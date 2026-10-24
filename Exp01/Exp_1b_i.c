#include<stdio.h>
#include<ctype.h>//isDIGIT & isALPHA
#include<String.h>
#include<stdlib.h>//EXIT0
#define MAX 50

//Stack Intialization
char st[MAX];
int top=-1;

//Function Prototype
void push(char);
char pop();

void InfixtoPostfix(char source[],char target[]);
int getPriority(char);

int main(){
    char infix[50],postfix[50];
    printf("Enter any expression :");
    scanf("%s",&infix);
    puts(infix);
    strcpy(postfix,"");
    InfixtoPostfix(infix,postfix);
    printf("the postfix expression is :");
    puts(postfix);
    return 0;
}

void push(char val){

    if(top==MAX-1){
        printf("\nWARNING : STACK OVERFLOw\n");
    }
    else{
          top++;
          st[top]=val;
    }
}//end of push

char pop(){
    char val=' ';
    if(top==-1){
        printf("\nWARNING : STACK UNDERFLOW\n");
    }
    else{
        val=st[top];
        top--;
    }
    return val;
}

int getPriority(char op){
    if(op=='/' || op=='+' || op=='%' || op=='^'){
        return 1;
    }
    else if(op=='+' || op=='-'){
        return 0;
        }
}

void InfixtoPostfix(char source[],char target[]){
    int i=0,j=0;
    char temp;
    strcpy(target,"");
    while(source[i]!='\0'){
        if(source[i]=='('){
            push(source[i]);//calling push function
            i++;
           }
        else if(source[i]==')'){
            while((top!=-1) && (st[top]!='(')){//till stack is empty or we reach '('
                    target[j]=pop();//pop
                    j++;
            }
            if(top==-1){
                printf("\n INCORRECT EXPRESSION");
                exit(1);
            }
            temp=pop();
            i++;
        }
        else if(isdigit(source[i]) || isalpha(source[i])){//ctype.h

            target[j]=source[i];
            j++;
            i++;
        }
        else if(source[i]=='+' || source[i]=='-' || source[i]=='*' || source[i]=='/' || source[i]=='%'){

            while((top!=-1)&&(st[top]!=')')&& (getPriority(st[top])>=getPriority(source[i]))){

                target[j]=pop();
                j++;
            }
        push(source[i]);
        i++;
        }
    else{
        printf("\n INCORRECT ELEMENT IN EXPRESSION");
        exit(1);
    }
    }//end of first while loop

    while((top==-1)&& (st[top]!='(')){
            target[j]=pop();
            j++;
    }
    target[j]='\0';
}
