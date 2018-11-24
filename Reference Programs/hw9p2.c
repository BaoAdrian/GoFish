//
//  hw9p2.c
//  ECE175_HW9P2
//
//  Created by Adrian Bao on 11/24/18.
//  Copyright © 2018 Adrian Bao. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

// Struct Declaration
typedef struct node_s {
    int x;
    struct node_s *next;
    struct node_s *prev;
} node;

// Function Prototypes
void addMember(node *p, node **hl, node **hr);
int traverse_list(node *hl);
int rand_gen(int count);
void swap(node *pt, int i, int j);

int main(void) {
    
    char response = 'y';
    int swap_count;
    int list_len = 0;
    int idx_1, idx_2;
    
    // Seed random number generator
    srand((int)time(NULL));
    
    node *hl = NULL;
    node *hr = NULL;
    
    // Create Linked List
    while (response == 'y') {
        // Pass in pointer to the last value as well as address to headRight and headLeft
        addMember(hr, &hl, &hr);
        printf("Do you want to enter another integer (y/n)?");
        scanf("%*c%c", &response);
    }
    
    // Display BEFORE swapping values
    list_len = traverse_list(hl); // Also returns the length of the list
    
    printf("\nEnter the number of swaps: ");
    scanf("%d", &swap_count);
    
    // Iterate swap_count times
    for (int i = 0; i < swap_count; i++) {
        // Get the two random numbers to swap
        idx_1 = rand_gen(list_len);
        idx_2 = rand_gen(list_len);
        swap(hl, idx_1, idx_2);
    }
    
    // Prints swapped LinkedList
    node *curr = hl;
    while (curr != NULL) {
        printf("%d ", curr->x);
        curr = curr->next;
    }
    
    
    
    return 0;
}

/************************************************************************
 * addMember(): Function pulled from previous assignment that makes use *
 *      of double pointers to create a LinkedList.                      *
 ************************************************************************/
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

/************************************************************************
 * traverse_list(): Function that traverses the created LinkedList and  *
 *      prints the sequential values at each node. Simultaneously keeps *
 *      count to return the total amount of nodes in list (length)      *
 ************************************************************************/
int traverse_list(node *hl) {
    int len = 0;
    node *curr = hl;
    while (curr != NULL) {
        printf("%d ", curr->x);
        curr = curr->next;
        len++;
    }
    return len;
}

/************************************************************************
 * rand_gen(): Function that generates a random number from 0 to length *
 *      of the LinkedList in order to pull two indices to swap their    *
 *      values.                                                         *
 ************************************************************************/
int rand_gen(int count) {
    // count is the length of the list
    double frac;
    frac = (double)rand() / ((double)RAND_MAX+1);
    return floor(count * frac); // random number in [0, count]
    
}

/************************************************************************
 * swap(): Function that accepts the two target indices and the pointer *
 *      to the head of the LinkedList. Traverses the list pulling the   *
 *      nodes at the given indices (i, j) then performs a value swap    *
 ************************************************************************/
void swap(node *pt, int i, int j) {
    // pt is the head of the list, i and j are the indexes of elements to swap
    node *curr = pt;
    node *node_1 = NULL;
    node *node_2 = NULL;
    
    // Pull node_1
    int flag = 0;
    while (flag < i) {
        curr = curr->next;
        flag++;
    }
    node_1 = curr;
    
    // Reset to beginning
    curr = pt;
    
    // Pull node_2
    flag = 0;
    while (flag < j) {
        curr = curr->next;
        flag++;
    }
    node_2 = curr;
    
    // Perform the swap
    int temp;
    
    /* Commented out below shows the steps of swapping each value and specified indices. */
    
//    printf("\nBEFORE: Node1[index(i) = %d, value = %d], Node2[index(j) = %d, value = %d]\n", i, node_1->x, j, node_2->x);
//    curr = pt;
//    while (curr != NULL) {
//        printf("%d -> ", curr->x);
//        curr = curr->next;
//    }
//    printf("NULL");
    
    temp = node_1->x;
    node_1->x = node_2->x;
    node_2->x = temp;
    
//    printf("\nAFTER: Node1[indedx(i) = %d, value = %d], Node2[index(j) = %d. value = %d]\n", i, node_1->x, j, node_2->x);
//    curr = pt;
//    while (curr != NULL) {
//        printf("%d -> ", curr->x);
//        curr = curr->next;
//    }
//    printf("NULL");
//    printf("\n\n");
    
    
}
