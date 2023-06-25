#include <string.h>
#include "lib_num_converters.h"
#include <stdio.h>


int test_min(void){
    int numbers[7] = {45, 12, 3, 6, 4, 34, 88};
    int min_num = min(numbers, 7);
    return (min_num == 3) ? 0 : 1;
}

int test_max(void){
    int numbers[7] = {45, 12, 3, 6, 4, 34, 88};
    int max_num = max(numbers, 7);
    return (88 == max_num) ? 0 : 1;
}

int test_int2bin(void){
    int number = 7;
    const char *bin_text = int2bin(number);
    printf("\nValue returned from int2bin(7): %s\n", bin_text);
    return (0 == strcmp("111", bin_text)) ? 0 : 1;
}

int test_bin2int(void){
    char* binary = "111";
    int ret_int = bin2int(binary);
    printf("\nValue returned from bin2int(\"111\"): %d\n", ret_int);
    return (ret_int == 7) ? 0 : 1;
}

int test_swap(void){
    int a = 5;
    int b = 8;
    swap(&a, &b);
    return (a == 8 && b == 5) ? 0 : 1;
}


int main(){
    int errors = 0;
    errors += test_min();
    errors += test_max();
    // errors += test_int2bin();
    // errors += test_bin2int();
    errors += test_swap();


    return (errors == 0) ? 0 : errors;
       
}