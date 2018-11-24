//
//  main.c
//  ECE175_FinalProject
//
//  Created by Adrian Bao on 11/21/18.
//  Copyright © 2018 Adrian Bao. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

const int LINE_SIZE = 15;
const int SUIT_LENGTH = 10;

// Card declaration
typedef struct card_s {
    char suit[SUIT_LENGTH];
    int value;
    // struct card_s *prev;
    struct card_s *next; // Pointer to the next card in the LinkedList
} card;

struct card_s* pull_card_data(char line[]);
void print_list(struct card_s *card);
void create_list(struct card_s *card); // Function used to create the deck of cards to be used as the pool
void add_to_end(struct card_s *head, struct card_s *tail, struct card_s *card); // Add card to end of list

int main(void) {
    
    /* Variable Declarations */
    char line[LINE_SIZE];
    struct card_s *temp_card = NULL;
    temp_card = (struct card_s*)malloc(sizeof(struct card_s));
    
    
    // Declare head and tail pointer to keep track of each end of the list
    struct card_s *head = NULL;
    struct card_s *tail = NULL;
    
    // Dynamically allocate memory for head and tail
    head = (struct card_s*)malloc(sizeof(struct card_s));
    tail = (struct card_s*)malloc(sizeof(struct card_s));
    
    // Input file that may be used to read in the formatted output to populate linkedlist
    FILE *inp;
    inp = fopen("ordered_deck.txt", "r");
    if (inp == NULL) {
        printf("ERROR: Could not open file. Ending Program\n");
        return -1;
    }
    
    
    
    while (fgets(line, LINE_SIZE, inp) != NULL) {
        
        temp_card = pull_card_data(line);
        
        add_to_end(head, tail, temp_card);
        
        printf("[%d : %s] -> ", temp_card->value, temp_card->suit);

        temp_card = NULL; // Clear out the pointer to process next value
    }
    
    printf("\n===================================\n");
    
    
    
    // print_list(head);
    
    
    return 0;
}

struct card_s* pull_card_data(char line[]) {
    
    char *temp;
    int i;
    struct card_s *temp_card;
    temp_card = (struct card_s*)malloc(sizeof(struct card_s));
    
    // Remove trailing new line when reading from file
    line[strlen(line) - 1] = '\0';
    
    // Parse data and begin process of creating Linked List
    if (line[0] == 'J') {
        temp_card->value = 11;
    } else if (line[0] == 'Q') {
        temp_card->value = 12;
    } else if (line[0] == 'K') {
        temp_card->value = 13;
    } else {
        temp_card->value = atoi(&line[0]); // Pull integer value
    }
    temp = &line[2]; // Set pointer to begin pulling suit
    i = 0;
    
    // Move pointer one more (covers the 10 case)
    if (*temp == ' ') {
        temp++;
    }
    // Loop until the end of the line, saving them into suit attribute
    while (*temp != '\0') {
        temp_card->suit[i] = *temp;
        temp++;
        i++;
    }
    
    
    
    return temp_card;
    
}


void print_list(struct card_s *card) {
    
    while (card != NULL) {
        printf("[%d : %s] -> ", card->value, card->suit);
        card = card->next;
    }
}

void add_to_end(struct card_s *head, struct card_s *tail, struct card_s *temp_card) {
    
    if (head == NULL) {
        // List is empty, add to the front
        head = temp_card;
        tail = temp_card;
        temp_card->next = NULL;
    } else {
        // Add to end, whatever tail is pointing to
        tail->next = temp_card;
        temp_card->next = NULL;
        tail = temp_card;
    }
    
}
