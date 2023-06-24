#include <string.h>
#include <math.h>
#include "lib_num_converters.h"

/**
 * This function converts an integer to a binary number (as a string).
 * @param number
 * @return The integer number converted to its binary representation.
 */
const char* int2bin(int number){
    int intPlaceValue = 1;
    int counter = 0;

    while (number >= intPlaceValue) {
        intPlaceValue *= 2;
    }

    if(intPlaceValue > number){
        intPlaceValue /= 2;
    }

    static char strResult[] = "";

    while (intPlaceValue > 0) {
        if (number > intPlaceValue || number == intPlaceValue) {
            number = number % intPlaceValue;
            strResult[counter] = '1';
        } else {
            strResult[counter] = '0';
        }
        intPlaceValue = intPlaceValue / 2;
        counter++;
    }
    strResult[counter] = '\0';
    return strResult;
}

/**
 * This function converts a binary number (string) into an integer.
 * @param number
 * @return The integer represented by the binary string 'number'
 */
int bin2int(char* number){
    const int num_length = strlen(number);
    static int result = 0;
    int place = num_length - 1;
    char digit;
    for( int i = 0; i < num_length; i++ ){
        digit = number[i];
        if(digit == '1'){
            result += pow(2,place);
        }
        place -= 1;
    }
    return result;
}

/**
 * When passed the pointers to two integers, this function will swap the underlying values.
 * @param a
 * @param b
 */

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

int min(const int numbers[], int arr_size){
    int min_num = numbers[0];
    for(int i = 0; i < arr_size; i++){
        if(numbers[i] < min_num){
            min_num = numbers[i];
        }
    }
    return min_num;
}

int max(const int numbers[], int arr_size){
    int max_num = numbers[0];
    for(int i = 0; i < arr_size; i++){
        if(numbers[i] > max_num){
            max_num = numbers[i];
        }
    }
    return max_num;
}
