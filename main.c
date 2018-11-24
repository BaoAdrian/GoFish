//
//  main.c
//  ECE175_FinalProject
//
//  Created by Adrian Bao on 11/21/18.
//  Copyright © 2018 Adrian Bao. All rights reserved.
//

#include <stdio.h>
#include <string.h> // string functions
#include <stdlib.h>
#include <math.h> // Random number generator for shuffling
#include <time.h> // Used to seed the random number generator

const int LINE_SIZE = 15;
const int SUIT_LENGTH = 10;

// Card declaration
typedef struct card_s {
    char suit[SUIT_LENGTH];
    int value;
    struct card_s *prev;
    struct card_s *next;
} card;

/* Function Prototypes */
void create_list(card *card); // Function used to create the deck of cards to be used as the pool
void add_to_end(card *p, card **hl, card **hr, char line[]); // Add card to end of list
card* pull_card_data(char line[]);
int find_length(card *hl);
void print_list(card *card);
void swap(card *pt, int i, int j); // Function used to swap cards at index i and j
int rand_gen(int count);



int main(void) {
    
    // Seed the RNG
    srand((int)time(NULL));
    
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
    
    // At this point, list is fully populated with length of 52
    int num_cards = find_length(hl);
    
    // Print before swap
    print_list(hl);
    
    // Perform 100 swaps
    int num_swaps = 3;
    int idx_1, idx_2;
    for (int i = 0; i < num_swaps; i++) {
        idx_1 = rand_gen(num_cards);
        idx_2 = rand_gen(num_cards);
        
        // Need to ensure that we don't swap a card with itself
        while (idx_2 == idx_1) {
            // Grab another random index
            idx_2 = rand_gen(num_cards);
        }
        swap(hl, idx_1, idx_2);
    }
    
    
    printf("\n===================================\n");
    
    // Print after swapping first two values
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

int find_length(card *hl) {
    
    int length = 0;
    
    card *curr = (card*)malloc(sizeof(card));
    curr = hl;
    
    while (curr != NULL) {
        length++;
        curr = curr->next;
    }
    
    return length;
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


/************************************************************************
 * swap(): Function that accepts the two target indices and the pointer *
 *      to the head of the LinkedList. Traverses the list pulling the   *
 *      nodes at the given indices (i, j) then performs a swap of the   *
 *      value and suit of the card, essentially swapping cards          *
 ************************************************************************/
void swap(card *pt, int i, int j) {
    
    card *temp = pt;
    card *node_1 = NULL;
    card *node_2 = NULL;
    int flag;
    
    // Pull Node 1
    flag = 0; // start at beginning of list
    while (flag < i) {
        temp = temp->next;
        flag++;
    }
    node_1 = temp;
    
    // Reset and Pull Node 2
    temp = pt;
    flag = 0;
    
    while (flag < j) {
        temp = temp->next;
        flag++;
    }
    node_2 = temp;
    
    // Temporary values
    int temp_value;
    char temp_suit[SUIT_LENGTH];
    
    temp_value = node_1->value;
    strcpy(temp_suit, node_1->suit);
    
    node_1->value = node_2->value;
    //node_1->suit[0] = '\0';
    strcpy(node_1->suit, node_2->suit);
    
    node_2->value = temp_value;
    //node_2->suit[0] = '\0';
    strcpy(node_2->suit, temp_suit);
    
}


/************************************************************************
 * rand_gen(): Function that generates a random number from 0 to length *
 *      of the LinkedList in order to pull two indices to swap their    *
 *      values (i.e. their value and suit of card)                      *
 ************************************************************************/
int rand_gen(int count) {
    double frac;
    frac = (double)rand()/((double)RAND_MAX+1);
    return floor(count*frac);
}
