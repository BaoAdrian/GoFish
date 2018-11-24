//
//  hw9p1.c
//  ECE175_HW9P1
//
//  Created by Adrian Bao on 11/23/18.
//  Copyright © 2018 Adrian Bao. All rights reserved.
//

/*
 * Program Objective: Create a doubly-linked list of integers. List will
 *      be initialized by the user who enters a set of integers until their
 *      response becomes 'n'. Makes all appropriate connections depending
 *      on the state of the current LinkedList.
 */



#include <stdio.h>
#include <stdlib.h>

// Struct Declaration
typedef struct node_s {
    int x;
    struct node_s *next;
    struct node_s *prev;
} node;

// Function Prototypes
void addMember(node *p, node **hl, node **hr);
void print_output(node *hl);

int main(void) {
    
    char response = 'y';
    
    node *hl = NULL; // Initially null for empty list
    node *hr = NULL;
    
    // Loop through creating linked list until user decides to stop
    while (response == 'y') {
        addMember(hr, &hl, &hr);
        printf("Do you want to enter another integer (y/n)?");
        scanf("%*c%c", &response);
    }
    
    
    print_output(hl);
    
    return 0;
}

void addMember(node *p, node **hl, node **hr) {
    
    // Create temporary node to hold the new inputted values
    node *temp = (node*)malloc(sizeof(node));
    
    printf("Enter an integer: ");
    scanf("%d", &(temp->x));
    
    // If list is empty, set all links and pointers accordingly
    if (*hl == NULL) {
        
        *hl = temp;
        *hr = temp;
        temp->next = NULL;
        temp->prev = NULL;
        
    } else if (p->next == NULL) {
        
        // Adding to end of list (p is headright (tail))
        p->next = temp;
        temp->prev = p;
        temp->next = NULL;
        *hr = temp;
        
    }
    
}

void print_output(node *hl) {
    printf("\nThe integers are: ");
    node *curr = hl;
    while (curr != NULL) {
        printf("%d ", curr->x);
        curr = curr->next;
    }
}
