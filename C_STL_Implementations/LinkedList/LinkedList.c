#include "LinkedList.h"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

Node *head = NULL;
Node *current = NULL;

//display the list
void printList() 
{
   Node *ptr = head;
   printf("\n[ ");
	
   //start from the beginning
   while(ptr != NULL) {
      printf("(%d,%d) ",ptr->key,ptr->data);
      ptr = ptr->next;
   }
	
   printf(" ]");
}

//insert link at the first location
void insertFirst(int key, int data) 
{
   //create a link
   Node *link = (Node*) malloc(sizeof(Node));
	
   link->key = key;
   link->data = data;
	
   //point it to old first node
   link->next = head;
	
   //point first to new first node
   head = link;
}

//delete first item
Node* deleteFirst() 
{

   //save reference to first link
   Node *tempLink = head;
	
   //mark next to first link as first 
   head = head->next;
	
   //return the deleted link
   return tempLink;
}

bool isEmpty() 
{
   return head == NULL;
}

int length() 
{
   int length = 0;
   Node *current = head;
	
   while (current != NULL) {
      ++length;
      current = current->next;
   }
	
   return length;
}

//find a link with given key
Node* find(int key) 
{
   Node* current = head;

   if(head == NULL)
      return NULL;

   while(current->key != key) {
      if(current->next == NULL) {
         return NULL;
      } else {
         current = current->next;
      }
   }      

   return current;
}

//delete a link with given key
Node* delete(int key)
{
   Node* current = head;
   Node* previous = NULL;
	
   if(head == NULL)
      return NULL;

   while(current->key != key) {
      if(current->next == NULL) {
         return NULL;
      } else {
         //store reference to current link
         previous = current;
         //move to next link
         current = current->next;
      }
   }

   // delete node. Different process used if node to delete is first node
   if(current == head)
      head = head->next;
   else
      previous->next = current->next;   
	
   return current;
}

void sort()
{
   int i, j, k, tempKey, tempData;
   Node *current;
   Node *next;
	
   int size = length();
   k = size ;
	
   for ( i = 0 ; i < size - 1 ; i++, k-- ) {
      current = head;
      next = head->next;
		
      for ( j = 1 ; j < k ; j++ ) {   

         if ( current->data > next->data ) {
            tempData = current->data;
            current->data = next->data;
            next->data = tempData;

            tempKey = current->key;
            current->key = next->key;
            next->key = tempKey;
         }
			
         current = current->next;
         next = next->next;
      }
   }   
}

void reverse(Node** head_ref) {
   Node* prev = NULL;
   Node* current = *head_ref;
   Node* next;
	
   while (current != NULL) {
      next  = current->next;
      current->next = prev;   
      prev = current;
      current = next;
   }
	
   *head_ref = prev;
}