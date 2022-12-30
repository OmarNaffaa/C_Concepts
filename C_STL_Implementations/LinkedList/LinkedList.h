#ifndef LINKED_LIST
#define LINKED_LIST

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node {
   int data;
   int key;
   struct node *next;
} Node;

extern Node *head;
extern Node *current;
extern long listSize;

void printList();
void insertFirst(int key, int data);
Node* deleteFirst();
bool isEmpty();
int length();
Node* find(int key);
Node* delete(int key);
void sort();
void reverse(Node** head_ref);

#endif