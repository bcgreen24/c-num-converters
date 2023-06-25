#include <string.h>
#include "lib_num_converters.h"
#include <stdio.h>


int test_min(void){
    int numbers[7] = {45, 12, 3, 6, 4, 34, 88};
    return (min(numbers, 7) == 3) ? 0 : 1;
}

int test_max(void){
    int numbers[7] = {45, 12, 3, 6, 4, 34, 88};
    return (88 == max(numbers, 7)) ? 0 : 1;
}

int test_int2bin(void){
    int number = 7;
    char *bin_text = int2bin(number);
    printf("\nValue returned from int2bin(7): %s\n", bin_text);
    return (0 == strcmp("111", int2bin(7))) ? 0 : 1;
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
    errors += test_int2bin();
    errors += test_bin2int();
    errors += test_swap();

    return (errors == 0) ? 0 : errors;
    // CU_pSuite pSuite = NULL;

    // if (CUE_SUCCESS != CU_initialize_registry())
    //     return CU_get_error();

    // pSuite = CU_add_suite("Test Suite", init_suite, clean_suite);
    // if (NULL == pSuite) {
    //     CU_cleanup_registry();
    //     return CU_get_error();
    // }

    // if ((NULL == CU_add_test(pSuite, "\n\nmin function Testing\n\n", test_min)))
    // {
    //     CU_cleanup_registry();
    //     return CU_get_error();
    // }

    // if ((NULL == CU_add_test(pSuite, "\n\nmax function Testing\n\n", test_max)))
    // {
    //     CU_cleanup_registry();
    //     return CU_get_error();
    // }

    // if ((NULL == CU_add_test(pSuite, "\n\nint2bin function Testing\n\n", test_int2bin)))
    // {
    //     CU_cleanup_registry();
    //     return CU_get_error();
    // }

    // if ((NULL == CU_add_test(pSuite, "\n\nbin2int function Testing\n\n", test_bin2int)))
    // {
    //     CU_cleanup_registry();
    //     return CU_get_error();
    // }

    //     if ((NULL == CU_add_test(pSuite, "\n\nswap function Testing\n\n", test_swap)))
    // {
    //     CU_cleanup_registry();
    //     return CU_get_error();
    // }

    // CU_basic_run_tests();

    // CU_cleanup_registry();
    // return CU_get_error();

}