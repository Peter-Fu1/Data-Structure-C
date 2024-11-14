#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct Stack {
    char data[MAX_SIZE];
    int top;
} Stack;

void initStack(Stack *stack) {
    stack->top = -1;
}

int isEmpty(Stack *stack) {
    return stack->top == -1;
}

int isFull(Stack *stack) {
    return stack->top == MAX_SIZE - 1;
}

void push(Stack *stack, char value) {
    if (!isFull(stack)) {
        stack->data[++stack->top] = value;
    }
}

char pop(Stack *stack) {
    if (!isEmpty(stack)) {
        return stack->data[stack->top--];
    }
    return '\0';
}

char peek(Stack *stack) {
    if (!isEmpty(stack)) {
        return stack->data[stack->top];
    }
    return '\0';
}

int isMatchingPair(char left, char right) {
    return (left == '(' && right == ')') || (left == '[' && right == ']') || (left == '{' && right == '}');
}

int isBalanced(char *str) {
    Stack stack;
    initStack(&stack);
    for (int i = 0; i < strlen(str); i++) {
        if (str[i] == '(' || str[i] == '[' || str[i] == '{') {
            push(&stack, str[i]);
        } else if (str[i] == ')' || str[i] == ']' || str[i] == '}') {
            if (isEmpty(&stack) || !isMatchingPair(pop(&stack), str[i])) {
                return 0;
            }
        }
    }
    return isEmpty(&stack);
}

int main() {
    char str[MAX_SIZE];
    printf("请输入由各种括号组成的字符串：");
    scanf("%s", str);
    if (isBalanced(str)) {
        printf("括号匹配成功\n");
    } else {
        printf("括号不匹配\n");
    }
    return 0;
}
