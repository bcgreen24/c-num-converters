#include <string.h>
#include <math.h>
#include "library.h"

const char* int2bin(int number){
    int pcounter = 0;
    int intPlace = 1;
    int counter = 0;
    while (number > intPlace) {
        intPlace *= 2;
        pcounter += 1;
    }
    pcounter++;
    static char strResult[] = "";

    while (intPlace > 0) {
        if (number > intPlace || number == intPlace) {
            number = number % intPlace;
            strResult[counter] = '1';
        } else {
            strResult[counter] = '0';
        }
        intPlace = intPlace / 2;
        counter++;
    }
    strResult[counter] = '\0';
    return strResult;
}

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