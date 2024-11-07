/*
 *Name: Matthew Lira
 *Professor Garrett Poppe
 *Class: CSC-341-40
 *Date: October 4 24
 *Assignment: Lab #4
*/

#include <stdio.h>
#include <stdlib.h>

int x;
int y = 15;

void printOrder(void *tempA,void *tempB,void *tempC,void *tempD, void *tempE);


int main(int argc, char *argv[]){

	int i;
	int z = 0;
	int arr[5] = {0};

	int *pointer;
	pointer = &z;

	printf("The value of variable z is %d\n",z);
	printf("The address of variable z is %p\n",&z);
	printf("The value of pointer = %p which is the same as the address of z which is %p \n",pointer,&z);

	for(i = 0; i < 5; i++){
		printf("arr[%d] = %d with address of %p\n",i,arr[i],&arr[i]);
	}	

	//argc
	printf("\nThe address of argc is %p \n",&argc);
	
	//stack variables
	int stack = 22;
	int *pointStack;
	pointStack = &stack;

	printf("The stack variable is %d and the address of this stack variable is %p\n",stack,pointStack);

	//heap variables
	int *heap_var = (int*)malloc(sizeof(int));
	*heap_var = 64;

	printf("The address of heap variable is %p \n",heap_var);

	//uninitialized data
	int no_value;
	int *pointNoValue;
	pointNoValue = &no_value;
	printf("The uninitialized value is %d and the uninitialized address is %p\n",no_value,pointNoValue);

	//initialized data
	int has_value = 78;
	int *pointHasValue;
	pointHasValue = &has_value;
	printf("The initialized value is %d and the initialized address is %p\n",has_value,pointHasValue);


	//print from high to lowest based on address(without array and sort)using recursive calls
	printf("\nAddress from highest to lowest: \n");
	printOrder(&argc,pointStack,heap_var,pointNoValue,pointHasValue);


	
	return EXIT_SUCCESS;
}

void printOrder(void *tempA,void *tempB,void *tempC,void *tempD,void *tempE){
	if(tempA > tempB && tempA > tempC && tempA > tempD && tempA > tempE){
		printf("%p\n",tempA);
		printOrder(tempB,tempC,tempD,tempE,NULL);
	}
	else if(tempB > tempA && tempB > tempC && tempB > tempD && tempB > tempE){
		printf("%p\n",tempB);
		printOrder(tempA,tempC,tempD,tempE,NULL);
	}
	else if(tempC > tempA && tempC > tempB && tempC > tempD && tempC > tempE){
		printf("%p\n",tempC);
		printOrder(tempA,tempB,tempD,tempE,NULL);
	}
	else if(tempD > tempA && tempD > tempB && tempD > tempC && tempD > tempE){
		printf("%p\n",tempD);
		printOrder(tempA,tempB,tempC,tempE,NULL);
	}
	else if(tempE != NULL){
		printf("%p\n",tempE);
		printOrder(tempA,tempB,tempC,tempD,NULL);
	}


}
