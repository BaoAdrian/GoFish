# GoFish
Final Project for ECE175


<h1> Latest Adjustments </h1>

<ul>
  <li> 11/21/2018 - Implement structure to read in a file of pre-formatted input used to initialize the standard 52-deck and populate Linked List with values read from the file </li>
  
  <li> 11/24/2018 - Create Reference Programs folder to include various different programs to reference certain methods and function used to implement the final project structure.
  
- First program uploaded includes doubly-linked list creation by using double pointers.
- Second program uploaded includes how to swap values from two nodes with given indices. We can use this method to shuffle the deck of cards
</li>

<li> 11/24/2018 - Implement structure of Double-Linked List. Uses double pointers to populate the LinkedList by parsing a given file and adding each Card structure to the LinkedList. </li>
<li> 11/24/2018 - Implement shuffling structure of the main deck of cards upon initial start of the game. Currently set to 100 swaps to shuffle the deck. Will swap the value and suit of the card to avoid restructuring the entire linked list.

- Output also formatted to display the unicode character instead of the word. Will be replaced in the future with actual card designs.</li>
</ul>

<h1> Construction Documentation </h1>

<h2> 1. Doubly-Linked List Implementation </h2>

<p> This program implements the use of Doubly-Linked List for the ease of traversal and pointer adjustments when adding and removing cards to and from user decks and pool of cards. The following Struct declaration was used to hold specified attributes needed for the Card information and Doubly-Linked List capabilites: 

```C
typedef struct card_s {
    char suit[SUIT_LENGTH];
    int value;
    struct card_s *prev;
    struct card_s *next;
} card;
```
</p>

<br>

<p> The first portion of this program requires the user to choose if they want to shuffle a deck or load a predefined set of cards from a file. The current implementation of the program currently supports the latter with the former to be implemented in the future. The implementation is as follows. </p>

<h3> Shuffled Deck Selection </h3>
<p> Work in progress. When selected, program should loop through a set of arrays holding ranks and suits and automatically create a deck which can then be looped through and shuffled a set number of times to essentially present the users with a shuffled deck. </p>

<br>

<h3> Read from file Selection </h3>

<p> When the user selects this option, the program will read input from a specified file in the following format: 
  
  ```
  Rank Suit
  Rank Suit
  ...
  A hearts
  8 diamonds
  9 spades
  ```
  
  Suits are formatted as all lowercase and placed a single space after the given Rank. Rank will be provided in the following range: A, 2-10, J, Q, K. The program will read the Rank in as a character and typecast it to an <strong>int</strong> with the following guidelines:
  
  ```
  A -> 1
  J -> 11
  Q -> 12
  K -> 13
  ```
  
  This allows for ease of processing later in the program when the users are playing the game of GoFish and requesting for a specific suit. Rather than having to search for a specific character, they are order sequentially by values starting from 1 to 13.
  
  As each line is processed using a while loop, the line is passed along with references to the <strong>head-left</strong> and <strong>head-right</strong> of the Doubly-Linked List. The function call will look like so:
  
  ```C
  add_to_end(hr, &hl, &hr, line);
  ```
  
  Here, hr is the current Card Object that the pointer, hr (head-right), is pointing to. <strong>&hr and &hl</strong> are the address of the head pointers themselves so that the add_to_head function can make the necessary adjustments after the Card Object has been added to the LinkedList. The receiving parameters of the function look like the following:
  
  ```C
  void add_to_end(card *p, card **hl, card **hr, char line[]) { ... }
  ```

The return type is void since all changes made to head-left and head-right occur within the function, reassigning pointers when necessary. As stated before, hl and hr and references to the pointers in main so that we can make adjustments within this function without having to return them both...

Two cases are handled within this function. The first is when the list is currently empty, that means that <strong>head-left</strong> does not point to anything, thus is equal to NULL. If check is made for this condition and the result is TRUE, then we must first set the two head pointers (head-left and head-right) to point to the new Card introduced to the LinkedList. The final step once the pointers are set is to set the internal attributes of the Card. Since it was the first Card added to the LinkedList, we need to set the <strong>next</strong> and <strong>prev</strong> attributes to NULL since they will not point to anything yet.

```C
card *temp_card = (card*)malloc(sizeof(card));
temp_card = pull_card_data(line); // Parse data from line
    
if (*hl == NULL) {
     // List is empty
     *hl = temp_card;
     hr = temp_card;
     temp_card->next = NULL;
     temp_card->prev = NULL;
} else { ... }
```

The process of executing the above mentioned code is as follows:
<img src = "Project_Images/LinkedList_Add_to_Empty.png" width = "700" height = "900" hspace = "10" alt="add to empty list">
</p>
<br>
<p> The second case that is handled when adding to the list is when there is already Card Objects in the list, i.e. <strong>head-left is NOT NULL</strong>. When head-left is checked and found that it is pointing to a Card, then we must adjust the necessary pointers as before only this time, we need to ensure the <strong>prev</strong> attribute is adjusted. Note that <strong>p</strong> here is the Card that <strong>hr</strong> (head-right) is pointing to as stated in the function call. When <strong>p->next</strong> is NULL, that means it is the last element in the list and that is where the current Card should be inserted.
  
  ```C
  if (*hl == NULL) {
      // Broken down above
  } else if (p->next == NULL) {
      p->next = temp_card;
      temp_card->prev = p;
      temp_card->next = NULL;
      *hr = temp_card;
  }
  ```

The process of executing the above mentioned code is as follows:
<img src = "Project_Images/LinkedList_Add_to_End.png" width = "700" height = "900" hspace = "10" alt="add to end">
<br>

Once the file is completely processed and all data has been parsed into Card Structs, then the Doubly-Linked List is fully constructed with a total of 52 Cards. When the program is run using <strong>ordered_deck.txt</strong>, which is a file that sequentially goes through each suit and rank, the output of that program will look like the following. (NOTE: Current output is only formatted with unicode symbols, actual card representations will follow in future updates).

<img src = "Project_Images/ordered_text_output.png" width = "800" height = "400" hspace = "10" alt="ordered text output">

</p>
