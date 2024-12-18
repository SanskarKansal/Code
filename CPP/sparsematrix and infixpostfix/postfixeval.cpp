#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 100
typedef struct {
    int top;
    int items[MAX_SIZE];
} Stack;
void push(Stack *s, int value) {
    if (s->top == MAX_SIZE - 1) {
        printf("Stack Overflow\n");
        exit(EXIT_FAILURE);
    } else {
        s->items[++(s->top)] = value;
    }
}
int pop(Stack *s) {
    if (s->top == -1) {
        printf("Stack Underflow\n");
        exit(EXIT_FAILURE);
    } else {
        return s->items[(s->top)--];
    }
}
int isOperator(char ch) {
    return ch == '+' || ch == '-' || ch == '*' || ch == '/';
}
int evaluatePostfix(char *expression) {
    Stack s;
    s.top = -1;
    int i = 0;
    while (expression[i] != '\0') {
        char ch = expression[i];
        if (ch >= '0' && ch <= '9') {
            push(&s, ch - '0');
        }
         else if (isOperator(ch)) {
            int operand2 = pop(&s);
            int operand1 = pop(&s);
            switch (ch) {
                case '+':
                    push(&s, operand1 + operand2);
                    break;
                case '-':
                    push(&s, operand1 - operand2);
                    break;
                case '*':
                    push(&s, operand1 * operand2);
                    break;
                case '/':
                    push(&s, operand1 / operand2);
                    break;
                default:
                    printf("Invalid postfix expression\n");
            }
        }
        i++;
    }
    return pop(&s);
}
int main() {
    char postfixExpression[MAX_SIZE];
    printf("Enter a postfix expression: ");
    fgets(postfixExpression, MAX_SIZE, stdin);
    int result = evaluatePostfix(postfixExpression);
    printf("Result: %d\n", result);
    return 0;
}