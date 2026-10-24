#include <stdio.h>
#include <ctype.h>  // isdigit & isalpha
#include <string.h>
#include <stdlib.h>

#define MAX 50

// Stack Initialization
char st[MAX];
int top = -1;


void push(char);
char pop();
int getPriority(char);
void infixToPostfix(char source[], char target[]);

int main() {
    char infix[50], postfix[50];
    printf("Enter any expression: ");
    fgets(infix, sizeof(infix), stdin);
    infix[strcspn(infix, "\n")] = '\0';

    strcpy(postfix, "");
    infixToPostfix(infix, postfix);
    printf("The postfix expression is: ");
    puts(postfix);

    return 0;
}

void push(char val) {
    if (top == MAX - 1) {
        printf("\nWARNING: STACK OVERFLOW\n");
    } else {
        top++;
        st[top] = val;
    }
}

char pop() {
    char val = ' ';
    if (top == -1) {
        printf("\nWARNING: STACK UNDERFLOW\n");
    } else {
        val = st[top];
        top--;
    }
    return val;
}


int getPriority(char op) {
    if (op == '^') {
        return 3;
    } else if (op == '*' || op == '/' || op == '%') {
        return 2;
    } else if (op == '+' || op == '-') {
        return 1;
    }
    return 0;
}

void infixToPostfix(char source[], char target[]) {
    int i = 0, j = 0;
    char temp;
    strcpy(target, "");

    while (source[i] != '\0') {
        if (source[i] == '(') {
            push(source[i]);  // Push '(' onto the stack
            i++;
        } else if (source[i] == ')') {
            while (top != -1 && st[top] != '(') {  // Pop until '(' is found
                target[j] = pop();
                j++;
            }
            if (top == -1) {  // If the stack is empty, there's an error
                printf("\nINCORRECT EXPRESSION\n");
                exit(1);
            }
            pop();  // Pop the '(' from the stack
            i++;
        } else if (isdigit(source[i]) || isalpha(source[i])) {  // Operand
            target[j] = source[i];
            j++;
            i++;
        } else if (source[i] == '+' || source[i] == '-' || source[i] == '*' || source[i] == '/' || source[i] == '%') {
            while (top != -1 && st[top] != '(' && getPriority(st[top]) >= getPriority(source[i])) {
                target[j] = pop();
                j++;
            }
            push(source[i]);  // Push the operator to the stack
            i++;
        } else {
            printf("\nINCORRECT ELEMENT IN EXPRESSION\n");
            exit(1);
        }
    }


    while (top != -1) {
        target[j] = pop();
        j++;
    }
    target[j] = '\0';
}
