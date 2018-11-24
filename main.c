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
    struct card_s *prev;
    struct card_s *next;
} card;

card* pull_card_data(char line[]);
void print_list(card *card);
void create_list(card *card); // Function used to create the deck of cards to be used as the pool
void add_to_end(card *p, card **hl, card **hr, char line[]); // Add card to end of list

int main(void) {
    
    /* Variable Declarations */
    char line[LINE_SIZE];
    
    // Declare head and tail pointer to keep track of each end of the list
    card *hl = NULL;
    card *hr = NULL;
    
    // Input file that may be used to read in the formatted output to populate linkedlist
    FILE *inp;
    inp = fopen("ordered_deck.txt", "r");
    if (inp == NULL) {
        printf("ERROR: Could not open file. Ending Program\n");
        return -1;
    }
    
    
    
    while (fgets(line, LINE_SIZE, inp) != NULL) {
        add_to_end(hr, &hl, &hr, line);
    }
    
    printf("\n===================================\n");
    
    
    
    print_list(hl);
    
    
    return 0;
}

card* pull_card_data(char line[]) {
    
    char *temp;
    int i;
    card *temp_card = (card*)malloc(sizeof(card));
    
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
    
    temp_card->suit[i] = '\0'; // terminate the string
    
    
    
    return temp_card;
    
}


void print_list(card *p) {
    card *curr = p;
    while (curr != NULL) {
        printf("[%d : %s] -> ", curr->value, curr->suit);
        curr = curr->next;
    }
}

void add_to_end(card *p, card **hl, card **hr, char line[]) {
    
    card *temp_card = (card*)malloc(sizeof(card));
    
    temp_card = pull_card_data(line);
    printf("[%d : %s] -> ", temp_card->value, temp_card->suit);
    
    if (*hl == NULL) {
        // List is empty
        *hl = temp_card;
        *hr = temp_card;
        temp_card->next = NULL;
        temp_card->prev = NULL;
    } else if (p->next == NULL) {
        p->next = temp_card;
        temp_card->prev = p;
        temp_card->next = NULL;
        *hr = temp_card;
    }
    
    temp_card = NULL; // Clears buffer for suit (removes any characters remaining inside)
    
    
    
}
