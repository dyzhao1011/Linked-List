#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"

//main() is the brain of the program. It displays the options, gathers the input, and executes methods accordingly
int main() {
   printf("Hello, welcome to the Linked List Simulation.\n");

   char userOption;
   while (userOption != 'G'){
      printMenu();
      scanf(" %c", &userOption);
      printf("\n");
      switch (userOption){
         case 'A':
            printf("There are %d elements in the linked list.\n\n", getSize());
            printLinkedList();
            break;
         case 'B':{
            int key;
            char option;
            printf("What element are you inserting? ");
            scanf(" %d", &key);
            printf("Before Insertion\n");
            printLinkedList();

            printf("Select a letter below to choose where to insert\n");
            printf("A - Insert at the start\n");
            printf("B - Insert at a given position\n");
            printf("C - Insert at the end\n");
            scanf(" %c", &option);
            printf("\n");
            
            insert(key, option);
            printf("After Insertion\n");
            printLinkedList();
            break;
         }
         case 'C':{
            int key;
            printf("What element are you searching for? ");
            scanf("%d", &key);
            int position = search(key);
            if (position == -1){
               printf("The element %d is currently not in the linked list.\n\n", key);
            }
            else{
               printLinkedList();
               printf("The element %d is in position %d.\n\n", key, position);
            }
            break;
         }
         case 'D':{
            int key;
            printf("Before Deletion\n");
            printLinkedList();
            printf("What element are you deleting? ");
            scanf("%d", &key);
            if (search(key) == -1){
               printf("The element is currently not in the linked list.\n\n");
            }
            else{
               deleteNode(key);
               printf("After Deletion\n");
               printLinkedList();
            }
            break;
         }
         case 'E':
            sortAscending();
            printLinkedList();
            break;
         case 'F':
            sortDescending();
            printLinkedList();
            break;
         case 'G':
            break;
         default:
            printf("Invalid selection. Please try again. \n");
      }
      printf("---------------------------------------------------------------------\n\n");
   }
   return 0;
}
