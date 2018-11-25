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

<h2> Doubly-Linked List Implementation </h2>

<p> The first portion of this program requires the use to choose if they want to shuffle a deck or load a predefined set of cards from a file. The current implementation of the program currently supports the latter with the former to be implemented in the future. The implementation is as follows. </p>

<h3> Shuffled Deck Selection </h3>
<p> Work in progress. When selected, program should loop through a set of arrays holding ranks and suits and automatically create a deck which can then be looped through and shuffled a set number of times to essentially present the users with a shuffled deck. </p>

<br>

<h3> Read from file Selection </h3>

<p> When the user selects this option, the program will read input from a specified file in the following format: 
  
  ```C
  Rank Suit
  Rank Suit
  ...
  ```
  
  Rank will be provided in the following range: A, 2-10, J, Q, K. The program will read the Rank in as a character and type case it to an int with the following guidelines:
  
  ```
  A -> 1
  J -> 11
  Q -> 12
  K -> 13
  ```
  
  This allows for ease of processing later in the program when the users are playing the game of GoFish and requesting for a specific suit. Rather than having to search for a specific character, they are order sequentially by values starting from 1 to 13.
