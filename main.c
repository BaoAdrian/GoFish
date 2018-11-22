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
    struct card_s *prev; // Pointer to the previous card in LinkedList
    struct card_s *next; // Pointer to the next card in the LinkedList
} card;

int main(void) {
    
    // Declare head and tail pointer to keep track of each end of the list
    card *head = NULL;
    card *tail = NULL;
    
    // Input file that may be used to read in the formatted output to populate linkedlist
    FILE *inp;
    inp = fopen("ordered_deck.txt", "r");
    
    // String used to hold line read from file
    char line[LINE_SIZE];
    
    if (inp == NULL) {
        // File could not be opened. Print error and exit
        printf("ERROR: Could not open file. Ending Program\n");
        return -1;
    }
    
    
    card temp_card;
    char *temp;
    int i;
    while (fgets(line, LINE_SIZE, inp) != NULL) {
        
        
        
        // Remove trailing new line when reading from file
        line[strlen(line) - 1] = '\0';
        
        // Parse data and begin process of creating Linked List
        if (line[0] == 'J') {
            temp_card.value = 11;
        } else if (line[0] == 'Q') {
            temp_card.value = 12;
        } else if (line[0] == 'K') {
            temp_card.value = 13;
        } else {
            temp_card.value = atoi(&line[0]); // Pull integer value
        }
        temp = &line[2]; // Set pointer to begin pulling suit
        i = 0;
        
        // Move pointer one more (covers the 10 case)
        if (*temp == ' ') {
            temp++;
        }
        // Loop until the end of the line, saving them into suit attribute
        while (*temp != '\0') {
            temp_card.suit[i] = *temp;
            temp++;
            i++;
        }
        
        // Set to head if the head is currently NULL
        if (head == NULL) {
            head = &temp_card;
            temp_card.prev = NULL;
            temp_card.next = NULL;
        } else {
            // Add to end of list, setting next and prev pointers accordingly
            tail->next = &temp_card;
            temp_card.prev = tail;
            temp_card.next = NULL;
        }
        
        tail = &temp_card;
        
        printf("[%d : %s] -> ", temp_card.value, temp_card.suit);
        
        // Clear the suit string to avoid trailing characters
        for (int j = 0; j < SUIT_LENGTH; j++) {
            temp_card.suit[j] = '\0';
        }
        
    }
    
    printf("\n===================================\n");
    
    if (head != NULL) {
        card *temp_ptr = head;
        
        printf("<%d:%s>", temp_ptr->value, temp_ptr->suit);
        
        while (temp_ptr != NULL) {
            printf("[%d : %s] -> ", temp_ptr->value, temp_ptr->suit);
            temp_ptr = temp_ptr->next;
        }
    } else {
        printf("HEAD NULL");
    }
    
    
    return 0;
}
