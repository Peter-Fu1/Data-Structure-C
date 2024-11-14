#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_QUEUE_SIZE 100

typedef struct Person {
    char name[50];
    char gender;
} Person;

typedef struct Queue {
    Person data[MAX_QUEUE_SIZE];
    int front;
    int rear;
} Queue;

void initQueue(Queue *queue) {
    queue->front = queue->rear = 0;
}

int isQueueEmpty(Queue *queue) {
    return queue->front == queue->rear;
}

int isQueueFull(Queue *queue) {
    return (queue->rear + 1) % MAX_QUEUE_SIZE == queue->front;
}

void enqueue(Queue *queue, Person person) {
    if (!isQueueFull(queue)) {
        queue->data[queue->rear] = person;
        queue->rear = (queue->rear + 1) % MAX_QUEUE_SIZE;
    }
}

Person dequeue(Queue *queue) {
    Person p = {"", '\0'};
    if (!isQueueEmpty(queue)) {
        p = queue->data[queue->front];
        queue->front = (queue->front + 1) % MAX_QUEUE_SIZE;
    }
    return p;
}

int main() {
    Queue maleQueue, femaleQueue;
    initQueue(&maleQueue);
    initQueue(&femaleQueue);
    
    int n;
    printf("请输入进入舞厅的人员数量：");
    scanf("%d", &n);
    
    for (int i = 0; i < n; i++) {
        Person person;
        printf("请输入人员的姓名和性别(M/F)：");
        scanf("%s %c", person.name, &person.gender);
        if (person.gender == 'M' || person.gender == 'm') {
            enqueue(&maleQueue, person);
        } else if (person.gender == 'F' || person.gender == 'f') {
            enqueue(&femaleQueue, person);
        }
    }
    
    printf("舞伴配对结果：\n");
    while (!isQueueEmpty(&maleQueue) && !isQueueEmpty(&femaleQueue)) {
        Person male = dequeue(&maleQueue);
        Person female = dequeue(&femaleQueue);
        printf("%s 和 %s 配成舞伴\n", male.name, female.name);
    }
    
    if (!isQueueEmpty(&maleQueue)) {
        printf("未配对的男士人数：%d，下一轮第一个可获得舞伴的是：%s\n", (maleQueue.rear - maleQueue.front + MAX_QUEUE_SIZE) % MAX_QUEUE_SIZE, maleQueue.data[maleQueue.front].name);
    }
    if (!isQueueEmpty(&femaleQueue)) {
        printf("未配对的女士人数：%d，下一轮第一个可获得舞伴的是：%s\n", (femaleQueue.rear - femaleQueue.front + MAX_QUEUE_SIZE) % MAX_QUEUE_SIZE, femaleQueue.data[femaleQueue.front].name);
    }
    
    return 0;
}