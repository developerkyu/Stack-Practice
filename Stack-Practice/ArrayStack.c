//
//  ArrayStack.c
//  Stack-Practice
//
//  Created by 이규진 on 2023/05/13.
//

#include "ArrayStack.h"

// ArrayStack* Stack = NULL;
// AS_CreateStack(&Stack, 10);
void AS_CreateStack(ArrayStack** Stack, int Capacity) {
    
    // ArrayStack을 가리키는 포인터 Stack을 가리키는 포인터 Stack 생성
    (*Stack) = (ArrayStack*)malloc(sizeof(ArrayStack));
    (*Stack) -> Nodes = (Node*)malloc(sizeof(Node) * Capacity);
    
    (*Stack) -> Capacity = Capacity;
    (*Stack) -> Top = -1;
}

void AS_DestroyStack(ArrayStack* Stack) {
    free(Stack -> Nodes);
    free(Stack);
}

// AS_PUSH(Stack, 3);
void AS_Push(ArrayStack* Stack, ElementType Data) {
    Stack -> Top++;
    Stack -> Nodes[Stack -> Top].Data = Data;
}

// AS_Pop(Stack);
ElementType AS_Pop(ArrayStack* Stack) {
    int Position = Stack -> Top--;
    return Stack -> Nodes[Position].Data;
}

ElementType AS_Top(ArrayStack* Stack) {
    return Stack -> Nodes[Stack -> Top].Data;
}

int AS_GetSize(ArrayStack* Stack) {
    return Stack -> Top + 1;
}

int AS_IsEmpty(ArrayStack* Stack) {
    return (Stack -> Top == -1);
}

int AS_IsFull(ArrayStack* Stack) {
    return (Stack -> Capacity == Stack -> Top + 1);
}
