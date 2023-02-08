# Linked-List & Circular-Linked_list
## Summary
By ulitizing the terminal, this program allows a user to create a Linked List or a Circular Linked List of type **int** and manipulate its contents. The terminal displays a main menu of options and the user can select the options entering the into the terminal. For information on the list of all of the methods for the Linked List, please see Methods and the header files.

Developed using C.

<details>
  <summary>Input</summary>
  There are several cases in which this programs fails to execute properly or as intended provided that the input is not acceptable.  
  
  
  The first case is selecting the option from the main menu. The user has to enter a capital letter from A-G to continue to the next step. Otherwise, the program will display an error message.  
  
  The second case is the value of the data in nodes. The value has to be an integer, otherwise the program will cease to work. For the circular Linked List, for the best display, it is advised to input an integer with as little digits as possible. The display is not adjusted for multiple digit numbers and can be off by mulitple symbols.  
  
  The third case is selecting a position to insert a node. To avoid repetition, a valid position is a position that is between, and not including 1 and the size(Linked List) + 1. For example, if the Linked List has 4 Nodes, then the following are valid positions: 2,3. If the Linked List has 1 Node, then there are no valid position. In cases of invalid position or a redo, the user has to restart.
</details>
<details>
  <summary>Methods</summary>
  
  1. printMenu(): displays a list of options for the user to choose from. The user chooses an option by typing and entering a capital letter. An error message is displayed if an invalid option is chosen.  
  ![Screen Shot 2023-02-08 at 1 16 54 PM](https://user-images.githubusercontent.com/115419534/217617256-a1312744-1bae-4aa9-9cbd-3087cce5542a.png)

  2. printLinkedList()/printCircularLinkedList(): displays the Linked List in a specific format.  
  For the regular Linked List, it is displayed using arrows pointing to the right direction between nodes.  
  ![Screen Shot 2023-02-08 at 1 19 20 PM](https://user-images.githubusercontent.com/115419534/217617686-56b40103-8695-49bb-8110-cc83aa12d70a.png)  
  For the Circular Linked List, it is displayed in the same format but there is no null node and the last node points to the first node.  
  ![Screen Shot 2023-02-08 at 1 07 48 PM](https://user-images.githubusercontent.com/115419534/217617884-ee1ce693-f5ed-4850-815a-c4dae9e94600.png)  
  
  3. getSize(): returns the size of the linked list. It is used as a helper method.
  
  4. insert(int key, char option): allocates memory to a new node and the user can choose from 3 options for where to put it.  
    The 3 options are: 
     - Insert at the head
     - Insert at a given valid position
     - Insert at the end 
  
  5. search(int key): returns the position of the first instance of key that is found, otherwise, return -1.
  6. deleteNode(int key): deallocates memory and deletes the first instance of key and updates pointers of affected nodes.
  7. sortAscending(): sorts the Linked List in ascending order; implemented using Selection Sort.
  8. sortDescending(): sorts the Linked List in descending order; implemented using Selection Sort.
  
</details>
