//
//  main.c
//  BaseToBaseConverter
//
//  Created by Rithvik Arun on 9/11/19.
//  Copyright © 2019 Rithvik Arun. All rights reserved.
//

#include <stdio.h>
#include <stdbool.h>

#define MaxLength 1000
int converter(int,int);
bool checkIfNumberIsLowerThanBase(char[], char);
int lengthOfArray(char[]);

int main(int argc, const char * argv[]) {
    
    char base;
    int convertbase;
    char valueArray[MaxLength];
    
      printf("Enter base: ");
      scanf("%s", &base);
      printf("Enter value: ");
      scanf("%s", valueArray);
    
    while (checkIfNumberIsLowerThanBase(valueArray, base) == false) {
        printf("You cannot convert this! Enter another value: ");
        scanf("%s", valueArray);
    }
    
    printf("Enter base you want converted to: ");
    scanf("%d", &convertbase);
    return 0;
}

bool checkIfNumberIsLowerThanBase(char valueArray[], char base){
    for (int i = 0; i < lengthOfArray(valueArray); i++) {
        char value = valueArray[i];
        if (value >= base) {
            return false;
        }
    }
    return true;
}

int lengthOfArray(char valueArray[]){
   int arrayLength = 0;
   for (int i =0; i < MaxLength && valueArray[i] != '\0'; i++) {
       arrayLength++;
   }
   return arrayLength;
}

int converter(int number, int base){
   
    return 0;
}
