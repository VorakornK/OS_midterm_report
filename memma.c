#include<stdio.h>
#include<stdlib.h>


int n_loop = 3;
int *addressArray[3];
char seperator[] = "===================================================================================\n";

int Global_1;
int Global_2;
int Global_3 = 1;

int summation(int n, int step) {
    if (n == 0) {
        return 0;
    }
    int x = n;
    if (step != 0) {
        addressArray[n_loop-n] = &x;
    }
    x += summation(n - step, step);
    return x;
}

int main() {

    int check;
    printf("%s", seperator);
    printf("Do initialized global variable has lower address than an uninitialized one?\n");
    printf("address of Global_1(uninitialized): %p\n", &Global_1);
    printf("address of Global_3(initialized): %p\n", &Global_3);
    check = &Global_1 > &Global_3;
    printf(check == 1 ? "True, so initialized global variable has lower address than an uninitialized one!\n" : "False, so initialized global variable has higher address than an uninitialized one! (something went wrong isn't it?)\n");


    printf("%s", seperator);
    printf("Do stack grow down from high address to low address?\n");
    printf("Let's see the address of local variable in recursive function\n");
    printf("In this recursive function it define variable first then do a recursive\n");
    printf("So, local variable at depth i is define before depth i+1\n");
    summation(n_loop, 1);
    for (int i=0; i<n_loop; i++) {
        printf("address of local variable at depth %d: %p\n", i, addressArray[i]);
    }
    printf("If stack is accutally grow down, the address should be decreasing\n");
    printf("Then, address at depth i must greater than address at depth i+1\n");
    printf("Which is...");
    check = addressArray[0] > addressArray[1] && addressArray[1] > addressArray[2];
    printf(check == 1 ? "True, so stack is grow down!\n" : "False, so stack is grow up! (something went wrong isn't it?)\n");



    printf("%s", seperator);
    int *heap_1 = (int *)malloc(sizeof(int) * 5);
    int *heap_2 = (int *)malloc(sizeof(int) * 5);
    int *heap_3 = (int *)malloc(sizeof(int) * 5);
    printf("Do heap grow up from low address to high address?\n");
    printf("Let's see the address of memmory allocate variable\n");
    printf("We allocate 3 variable in heap\n");
    printf("in order of heap_1, heap_2 and heap_3\n");
    printf("address of heap_1: %p\n", heap_1);
    printf("address of heap_2: %p\n", heap_2);
    printf("address of heap_3: %p\n", heap_3);
    printf("If heap is accutally grow up, the address should be increasing\n");
    printf("Then, address of heap_(i) must less than address of heap_(i+1)\n");
    printf("Which is...");
    check = heap_1 < heap_2 && heap_2 < heap_3;
    printf(check == 1 ? "True, so heap is grow up!\n" : "False, so heap is grow down! (something went wrong isn't it?)\n");
    free(heap_1);
    free(heap_2);
    free(heap_3);
    
    printf("%s", seperator);
    char stackoverflow;
    printf("Would you like to see stackoverflow?(y, n): ");
    scanf("%c", &stackoverflow);
    if (stackoverflow == 'y') {
        summation(n_loop, 0);
    }
    return 0;
}