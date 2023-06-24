#include <string.h>
#include "CUnit/Basic.h"
#include "lib_num_converters.h"

int init_suite(void) { return 0; }
int clean_suite(void) { return 0; }

void test_min(void){
    int numbers[7] = {45, 12, 3, 6, 4, 34, 88};
    CU_ASSERT(3==min(numbers, 7));
}

void test_max(void){
    int numbers[7] = {45, 12, 3, 6, 4, 34, 88};
    CU_ASSERT(88==max(numbers, 7));
}

void test_int2bin(void){
    int number = 7;
    printf("\nValue returned from int2bin(7): %s\n", int2bin(number));
    CU_ASSERT(0 == strcmp("111", int2bin(7)));
}

void test_bin2int(void){
    char* binary = "111";
    int ret_int = bin2int(binary);
    printf("\nValue returned from bin2int(\"111\"): %d\n", bin2int(binary));
    CU_ASSERT(ret_int == 7);
}

void test_swap(void){
    int a = 5;
    int b = 8;
    swap(&a, &b);
    CU_ASSERT(a == 8 && b == 5);
}

int main(){
    CU_pSuite pSuite = NULL;

    if (CUE_SUCCESS != CU_initialize_registry())
        return CU_get_error();

    pSuite = CU_add_suite("Test Suite", init_suite, clean_suite);
    if (NULL == pSuite) {
        CU_cleanup_registry();
        return CU_get_error();
    }

    if ((NULL == CU_add_test(pSuite, "\n\nmin function Testing\n\n", test_min)))
    {
        CU_cleanup_registry();
        return CU_get_error();
    }

    if ((NULL == CU_add_test(pSuite, "\n\nmax function Testing\n\n", test_max)))
    {
        CU_cleanup_registry();
        return CU_get_error();
    }

    if ((NULL == CU_add_test(pSuite, "\n\nint2bin function Testing\n\n", test_int2bin)))
    {
        CU_cleanup_registry();
        return CU_get_error();
    }

    if ((NULL == CU_add_test(pSuite, "\n\nbin2int function Testing\n\n", test_bin2int)))
    {
        CU_cleanup_registry();
        return CU_get_error();
    }

        if ((NULL == CU_add_test(pSuite, "\n\nswap function Testing\n\n", test_swap)))
    {
        CU_cleanup_registry();
        return CU_get_error();
    }

    CU_basic_run_tests();

    CU_cleanup_registry();
    return CU_get_error();


}