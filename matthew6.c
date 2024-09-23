#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

//Global var
int sum; 

void*runner(void*param);

int main(int argc, char *argv[])
{

	pthread_t tid;
	pthread_attr_t attr;
        int input[10];

	while(1){
	printf("Enter A number'(or enter 99 to quit)': ");
	scanf("%d",&input[0]);

	if(input[0] == 99)
	break;
	
	}


	pthread_attr_init(&attr);
	pthread_create(&tid,&attr,runner,&input[0]);

	pthread_join(tid,NULL);
	printf("sum = %d \n",sum);

	return 0;
}//end of main
 
void *runner(void*param){
 
	int i ,upper = atoi(param);
	sum = 0;
	for(i = 1; i <= upper; i++)
		sum += i;
	pthread_exit(0);

}//end of runner
