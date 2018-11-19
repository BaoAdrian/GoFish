//
//  main.c
//  Testing_CardDisplay
//
//  Created by Adrian Bao on 11/17/18.
//  Copyright © 2018 Adrian Bao. All rights reserved.
//

#include <stdio.h>
#include <wchar.h>

int main(int argc, const char * argv[]) {
    
    // Unicode escape characters for each symbol
    /*
     Heart - \u2665
     Spades - \u2660
     Diamond - \u2666
     Club - \u2663
     
     
     */
    
    printf(" ------ \n");
    printf("|A\u2665    |\n");
    printf("|      |\n");
    printf("|      |\n");
    printf("|    A\u2665|\n");
    printf(" ------ \n");
    
    printf("\n");
    
    printf(" ------ \n");
    printf("|A\u2660    |\n");
    printf("|      |\n");
    printf("|      |\n");
    printf("|    A\u2660|\n");
    printf(" ------ \n");
    
    printf("\n");
    
    printf(" ------ \n");
    printf("|A\u2666    |\n");
    printf("|      |\n");
    printf("|      |\n");
    printf("|    A\u2666|\n");
    printf(" ------ \n");
    
    printf("\n");
    
    printf(" ------ \n");
    printf("|A\u2663    |\n");
    printf("|      |\n");
    printf("|      |\n");
    printf("|    A\u2663|\n");
    printf(" ------ \n");
    
    return 0;
}
