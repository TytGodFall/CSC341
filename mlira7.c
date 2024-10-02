#include <stdio.h>
#include <stdlib.h>

int compare_and_swap(int *pointb, int expected, int new_value);
void swap(int *pointerValue,int *pointerExpected,int *pointerNumOne, int *pointerNumTwo);

int main(void)
{
	int *pointa; 
	int new_value=22 ;
	int expect =1; 
	int numOne = 74;
	int numTwo = 24;

	pointa = &expect;
	
	printf("Address Stored in pointa is %p\n",pointa);
	printf("\naddress of variable named expected is %p\n",&expect);
	printf("\nvalue the pointa points to is %d",*pointa);
	printf("\nvalue of expected is %d",expect);

	int value_returned = compare_and_swap(pointa,expect,new_value);
	printf("expected = %d, old value which was returned is %d:", expect,value_returned);



	printf("\n\nBefore swap\nValue Returend:%d,\nExpected:%d,\nValue One:%d,\nValue Two:%d\n\n",value_returned,expect,numOne,numTwo);
        

	swap(&value_returned, &expect, &numOne, &numTwo);



	printf("After swap\nValue Returned:%d,\nExpected:%d,\nValue One:%d,\nValue Two:%d",value_returned,expect,numOne,numTwo);

	return EXIT_SUCCESS;

}//end of main
 
int compare_and_swap(int *pointb,int expected,int new_value){
	int temp = *pointb;
	if(*pointb == expected){
		*pointb = new_value;
	}
	return temp;

}

void swap(int *pointerValue,int *pointerExpected,int *pointerNumOne,int *pointerNumTwo){

	int temp;

	//first swapping the value with expected
	temp = *pointerValue;
	*pointerValue = *pointerExpected;
	*pointerExpected = temp;

	//Then swap NumOne with NumTwo
	temp = *pointerNumOne;
	*pointerNumOne = *pointerNumTwo;
	*pointerNumTwo = temp;


}//end of swap
