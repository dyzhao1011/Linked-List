#include <stdio.h>
#include <stdlib.h>

#ifndef CLINKEDLIST_H
#define CLINKEDLIST_H

//Node is the structure used to create the actual Node. Each one has a information of type (int) and a pointer to the next node
struct Node{
   int data;
   struct Node* next;
};

//Head and tail are global variables that point to the head and the tail of the linked list, respectively. The head and tail are 
//updated according as the linked list is manipulated
struct Node* head = NULL;
struct Node* tail = NULL;

/* The following method provides the user the ability to access or change the linked list .
   1. printMenu(): displays a list of options for the user to choose from. The user chooses an option by inputing a capital 
      letter. An error message is displayed if an invalid option is chosen.
   2. printLinkedList(): displays the circular linked list in the format: | ? | --> | ? | 
                                                                            ^         |
                                                                            |_________|
      If list is empty, it will display NULL.
   3. getSize(): returns the size of the linked list.
   4. insert(int key, char option): creates and allocates memory to a new node. There are 3 options to choose where to insert
      the node that the user can choose from.
   5. search(int key): returns the position of the first instance of key that is found, otherwise, return -1.
   6. deletes(int key): deallocates memory of the first instance of key and updates pointers of affected nodes. 
   7. sortAscending() & sortDescending(): implemented using Selection Sort.

*/

void printMenu(){
   printf("Please enter one of the following capital letters to select an action\n");
   printf("A - Print Linked List\n");
   printf("B - Insert a New Item\n");
   printf("C - Search for an Item\n");
   printf("D - Delete an Item\n");
   printf("E - Sort (Ascending)\n");
   printf("F - Sort (Descending)\n");
   printf("G - Exit\n");
}

int getSize(){
   int numElement = 0;
   struct Node* currNode = head;
   do{
      if (head != NULL){
         currNode = currNode->next;
         numElement++;
      }
   }
   while (currNode != head);
   return numElement;
}

void printCircLinkedList(){
   printf("Your Circular Linked List: ");
   struct Node* currNode = head;
   do{
      
      if (head != NULL){
         if (currNode == tail){
            printf("| %d |\n\n", currNode->data);
            currNode = currNode->next;
         }
         else{
            printf("| %d |-->", currNode->data);
            currNode = currNode->next;
         }
      }
      else{
         printf("NULL\n\n");
      }
   }
   while (currNode != head);
   
   //format to show the connection between the first and last node
   if (getSize() == 2){
      printf("                             ^       |\n");
      printf("                             |_______|\n\n");
   }
   else if (getSize() > 2){
      printf("                             ^");
      for (int i = 0; i < ((getSize()-1)*8)-1; i++){
         printf(" ");
      }
      printf("|\n");
      printf("                             |");
      for (int i = 0; i < ((getSize()-1)*8)-1; i++){
         printf("_");
      }
      printf("|\n\n");
   }
   
   
}


void insert (int key, char option){
   struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
   newNode->data = key;
   newNode->next = NULL;

   if (head == NULL){
      head = newNode;
      tail = newNode;
      newNode->next = newNode;
      tail->next = head;
      printf("Success! %d has been inserted at the start.\n\n", key);
   }
   else{
      switch (option){
      //Insert at the start
      case 'A':{
         struct Node* successor = head;
         head = newNode;
         newNode-> next = successor;
         tail->next = head;
         printf("Success! %d has been inserted at the start.\n\n", key);
         break;
      }
      //Insert at a given position
      case 'B':{
         int position;
         printf("For position 1 (insert at the front) or position %d (insert at the end), enter 0 and please go back to the insertion menu. What position/index do you want to insert the element? ", getSize()+1);
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
         tail->next = head;
         printf("Success! %d has been inserted at the end.\n\n", key);
         break;
      }
      }
   }
}

int search(int key){
   int currIndex = 1;
   struct Node* currNode = head;
   do{
      if (head != NULL){
         if (currNode->data == key){
            return currIndex;
            break;
         }
         currNode = currNode->next;
         currIndex++;
      }
   }
   while (currNode != head);
   return -1;
}

void deleteNode(int key){
   //if there is only 1 node
   if (head == tail){
      struct Node* nodeToBeDeleted = head;
      free(nodeToBeDeleted);
      head = NULL;
      tail = NULL;
   }
   else if (head->data == key){
      struct Node* successor = head->next;
      struct Node* nodeToBeDeleted = head;
      nodeToBeDeleted->next = NULL;
      head = successor;
      tail->next = successor;
      free(nodeToBeDeleted);

   }
   else{
      struct Node* predecessor = head;
      while (predecessor->next->data != key){
         predecessor= predecessor->next;
      }
      struct Node* nodeToBeDeleted = predecessor->next;
      predecessor->next = predecessor->next->next;
      nodeToBeDeleted->next = NULL;
      if (nodeToBeDeleted == tail){
         tail = predecessor;
      }
      free(nodeToBeDeleted);
   }
   printf("Success! %d is deleted from the linked list.\n\n", key);
}

void sortAscending(){
   int count = 1;
   for (struct Node* i = head; i != tail; i = i->next){
      if (i->next == tail && count != 1){
         break;
      }
      struct Node* smallestNode = i;
      for (struct Node* j = i->next; j != head; j = j->next){
         if (j->data < smallestNode->data){
            smallestNode = j;
         }
      }
      int temp = i->data;
      i->data = smallestNode->data;
      smallestNode->data = temp;
      count++;
   }
}

void sortDescending(){
   int count = 1;
   for (struct Node* i = head; i != tail; i = i->next){
      if (i->next == tail && count != 1){
         break;
      }
      struct Node* biggestNode = i;
      for (struct Node* j = i->next; j != head; j = j->next){
         if (j->data > biggestNode->data){
            biggestNode = j;
         }
      }
      int temp = i->data;
      i->data = biggestNode->data;
      biggestNode->data = temp;
      count++;
   }
}

#endif