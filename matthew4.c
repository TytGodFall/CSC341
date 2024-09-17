#include <stdio.h>
#include <stdlib.h>

//We are casting %p using void so avoid error arguments  
//Matt Lira
//Lab4


int initialized = 22;
int uninitialized;

//Structure helps to set specific values 
typedef struct{
   void *location;
   const char *name;
} AddressInfo;

//Having a compare function allows comparison between the address sizes
int compare(const void *a, const void *b) {
    AddressInfo *locA = (AddressInfo *)a;
    AddressInfo *locB = (AddressInfo *)b;
    return (locB ->location>locA->location)-(locB->location<locA->location);
}//end of compare
 
  int main(int argc, char *argv[]){

    //Setting the values and pointers(int)
    int num = 0;
    int array[5] = {0};
    int *pointer = &num;

    //set pointer to equal the address of num
    pointer = &num;

    //printing the address and values 
    printf("The value of num is %d\n", num);
    printf("The address of num is %p\n", (void*)&num);
    printf("The value of pointer is %p which is the same as num\n", (void*)pointer);
    printf("The address pointing to %p which is same as address in num which is %p\n", (void*)pointer, (void*)&num);

    for(int i = 0; i < 5; i++)
    printf("Array[%d] = %d with address %p\n", i, array[i], (void*)&array[i]);


    //Write A sample C program[highfromlow]-> Order output of address
    //argc, stack, heap, unintialized, and initialized 

    int stack = 0;
    int *heap = malloc(sizeof(int));
    *heap = 42;

    //calling the structure and creating an array of5 to store
    AddressInfo address[5];
    //inserting each address as a void into our void pointer address array; 
    address[0].location  = (void*)&argc;
    address[0].name = "Argc";
    address[1].location = (void*)&stack;
    address[1].name = "Stack";
    address[2].location  = (void*)&heap;
    address[2].name = "Heap";
    address[3].location = (void*)uninitialized;
    address[3].name = "Uninitialized";
    address[4].location = (void*)initialized;
    address[4].name = "Initialized";

    //using qsort to help sort the address in the corresponding order high to low
    qsort(address,5,sizeof(AddressInfo),compare);

    printf("\nPrinting outputs from the Highest to the Lowest based on the address given in the lab\n");

    //printing
    for(int i = 0;i < 5; i++)
	    printf("Name: %s, Address: %p\n",address[i].name,address[i].location);
    
    //free unused memory
    free(heap);

    return EXIT_SUCCESS;
    
}//end of main

