//
//  main.c
//  BaseToBaseConverter
//
//  Created by Rithvik Arun on 9/11/19.
//  Copyright © 2019 Rithvik Arun. All rights reserved.
//

#include <stdio.h>
#include <stdbool.h>
#include <math.h>

#define MaxLength 1000
int converter(int,int);
bool checkIfNumberIsLowerThanBase(char[], char);
int lengthOfArray(char[]);
int convertToBase10(char[], char);

//intial ask for base, value and what base they want converted to
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
    
    convertToBase10((valueArray), base);
    return 0;
}

//check if value is allowed in that paticular base
bool checkIfNumberIsLowerThanBase(char valueArray[], char base){
    for (int i = 0; i < lengthOfArray(valueArray); i++) {
        char value = valueArray[i];
        if (value >= base) {
            return false;
        }
    }
    return true;
}

//count the number of elements in the array
int lengthOfArray(char valueArray[]){
   int arrayLength = 0;
   for (int i =0; i < MaxLength && valueArray[i] != '\0'; i++) {
       arrayLength++;
   }
   return arrayLength;
}

// convert to base 10
int convertToBase10(char value[] , char base){
    int base10Value = 0;
    int baseCount = 0;
    for (int i = lengthOfArray(value) - 1; i >= 0; i--) {
        int val = value[i] - '0';
        int power = pow((base - '0'), baseCount);
        base10Value = base10Value + (power * val);
        baseCount++;
    }
    return 0;
}

int converter(int number, int base){
   
    return 0;
}
