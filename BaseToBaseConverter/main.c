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
void converter(int,int);
bool checkIfNumberIsLowerThanBase(char[], int);
int lengthOfArray(char[]);
int convertToBase10(char[], int);
void printArrayBackwards(int[], int);

//intial ask for base, value and what base they want converted to
int main(int argc, const char * argv[]) {
    
    int base;
    int convertbase;
    char valueArray[MaxLength];
    
      printf("Enter base: ");
      scanf("%d", &base);
      printf("Enter value: ");
      scanf("%s", valueArray);
    
    while (checkIfNumberIsLowerThanBase(valueArray, base) == false) {
        printf("You cannot convert this! Enter another value: ");
        scanf("%s", valueArray);
    }
    
    printf("Enter base you want converted to: ");
    scanf("%d", &convertbase);
    
    converter(convertToBase10((valueArray), base), convertbase);
    return 0;
}

//check if value is allowed in that paticular base
bool checkIfNumberIsLowerThanBase(char valueArray[], int base){
    for (int i = 0; i < lengthOfArray(valueArray); i++) {
        int value = valueArray[i] - '0';
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
int convertToBase10(char value[] , int base){
    int base10Value = 0;
    int baseCount = 0;
    for (int i = lengthOfArray(value) - 1; i >= 0; i--) {
        int val = value[i] - '0';
        int power = pow((base), baseCount);
        base10Value = base10Value + (power * val);
        baseCount++;
    }
    return base10Value;
}

//Converts from base 10 to other bases
void converter(int number, int base){
    int remainder,divider,count;
    count = 0;
    int finalValues[MaxLength];
    divider = number / base;
    remainder = number % base;
    finalValues[count] = remainder;
    count++;
    while (divider != 0) {
        remainder = divider % base;
        divider = divider / base;
        finalValues[count] = remainder;
        count++;
    }
    printArrayBackwards(finalValues,count);
}

//prints array backwards
void printArrayBackwards(int final[], int count){
    for (int i = count - 1; i >= 0 ; i--) {
        printf("%d", final[i]);
    }
    printf("\n");
}


