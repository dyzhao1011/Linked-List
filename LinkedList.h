#include <stdio.h>
#include <stdlib.h>

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

//Node is the structure used to create the actual Node. Each one has a information of type (int) and a pointer to the next node
struct Node{
   int data;
   struct Node* next;
};

//Head and tail are global variables that point to the head and the tail of the linked list, respectively. The head and tail are 
//updated according as the linked list is manipulated
struct Node* head = NULL;
struct Node* tail = NULL;

/* The following method provides the user the ability to access or change the linked list.
   1. printMenu(): displays a list of options for the user to choose from. The user chooses an option by inputing a capital 
      letter. An error message is displayed if an invalid option is chosen.
   2. printCircLinkedList(): displays the linked list in the format: | ? | --> | ? | --> NULL. If list is empty, it will display NULL.
   3. getSize(): returns the size of the linked list.
   4. insert(int key, char option): creates and allocates memory to a new node. There are 3 options to choose where to insert
      the node that the user can choose from.
   5. search(int key): returns the position of the first instance of key that is found, otherwise, return -1.
   6. Nodes(int key): deallocates memory of the first instance of key and updates pointers of affected nodes.
   7. sortAscending() & sortDescending(): implemented using Selection Sort.

*/
void printMenu(){
   printf("Please enter one of the following capital letters to select an action\n");
   printf("A - Print Linked List\n");
   printf("B - Insert a New Item\n");
   printf("C - Search for an Item\n");
   printf("D - Node an Item\n");
   printf("E - Sort (Ascending)\n");
   printf("F - Sort (Descending)\n");
   printf("G - Exit\n");
}

void printLinkedList(){
   printf("Your Linked List: ");
   struct Node* currNode = head;
   while (currNode != NULL){
      printf("| %d |-->", currNode->data);
      currNode = currNode->next;
   }
   printf("NULL\n\n");
}

int getSize(){
   int numElement = 0;
   struct Node* currNode = head;
   while (currNode != NULL){
      numElement++;
      currNode = currNode->next;
   }
   return numElement;
}

void insert (int key, char option){
   struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
   newNode->data = key;
   newNode->next = NULL;

   if (head == NULL){
      head = newNode;
      tail = newNode;
      printf("Success! %d has been inserted at the start.\n\n", key);
   }
   else{
      switch (option){
      //Insert at the start
      case 'A':{
         struct Node* successor = head;
         head = newNode;
         newNode-> next = successor;
         printf("Success! %d has been inserted at the start.\n\n", key);
         break;
      }
      //Insert at a given position
      case 'B':{
         int position;
         printf("For position 1 (insert at the front) or position %d (insert at the end), enter 0 and please go back to the insertion menu. What position do you want to insert the element? ", getSize()+1);
         scanf(" %d", &position);
         printf("\n");
         if (position < 2 || position > getSize()){
            printf("Invalid position.\n\n");
            break;
         }
         else{
            struct Node* predecessor = head;
            for (int i= 0; i < position-2; i++){
               predecessor = predecessor->next;
            }
            newNode->next = predecessor->next;
            predecessor->next = newNode;
            printf("Success! %d has been inserted at position %d.\n\n", key, position);
            break;
         }
      }
      //Insert at the end
      case 'C':{
         tail->next = newNode;
         tail = newNode;
         printf("Success! %d has been inserted at the end.\n\n", key);
         break;
      }
      }
   }
}

int search(int key){
   int currPosition = 1;
   struct Node* currNode = head;
   while (currNode != NULL){
      if (currNode->data == key){
         return currPosition;
         break;
      }
      currNode = currNode->next;
      currPosition++;
   }
   return -1;
}

void deleteNode(int key){
   if (head->data == key){
      struct Node* nodeToBeNoded = head;
      head = head->next;
      nodeToBeNoded->next = NULL;
      free(nodeToBeNoded);
   }
   else{
      struct Node* predecessor = head;
      while (predecessor->next->data != key){
         predecessor= predecessor->next;
      }
      struct Node* nodeToBeNoded = predecessor->next;
      predecessor->next = predecessor->next->next;
      nodeToBeNoded->next = NULL;
      free(nodeToBeNoded);
      if (predecessor->next == NULL){
         tail = predecessor;
      }
   }
   printf("Success! %d is Noded from the linked list.\n\n", key);
}

void sortAscending(){
   for (struct Node* i = head; i != NULL; i = i->next){
      if (i->next == NULL){
         break;
      }
      struct Node* smallestNode = i;
      for (struct Node* j = i->next; j != NULL; j = j->next){
         if (j->data < smallestNode->data){
            smallestNode = j;
         }
      }
      int temp = i->data;
      i->data = smallestNode->data;
      smallestNode->data = temp;
   }
}

void sortDescending(){
   for (struct Node* i = head; i != NULL; i = i->next){
      if (i->next == NULL){
         break;
      }
      struct Node* biggestNode = i;
      for (struct Node* j = i->next; j != NULL; j = j->next){
         if (j->data > biggestNode->data){
            biggestNode = j;
         }
      }
      int temp = i->data;
      i->data = biggestNode->data;
      biggestNode->data = temp;
   }
}
#endif