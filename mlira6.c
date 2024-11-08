/*
 *Name: Matthew Lira
 *Professor Garrett Poppe
 *Class: CSC-341-40
 *Date: October 4 24
 *Assignment: Lab #6
*/
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

int sum;

void *runner(void *param);

int main(int argc, char *argv[]){
	pthread_t tid;
	pthread_attr_t attr;
	pthread_attr_init(&attr);
	pthread_create(&tid,&attr,runner,argv[1]);
	pthread_join(tid,NULL);

	printf("sum = %d \n",sum);
}

void *runner(void *param){
	int i,upper = atoi(param);
	sum = 0;
	for(i = 1; i <=upper; i++)
		sum += i;
	
	printf("Awaiting user input therefore paused unlessed pressed (enter)");
	getchar();

	pthread_exit(0);


}
