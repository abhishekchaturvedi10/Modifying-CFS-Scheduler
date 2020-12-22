/* 	Name: Abhishek Chaturvedi
	Roll no: 2019401 		*/

#include <stdio.h>
#include <linux/kernel.h>
#include <sys/syscall.h>
#include <unistd.h>
#include <sys/time.h>
#include <sys/wait.h>
#include <errno.h>
#include <stdlib.h>

int status;

int main()
{
	long pid, tim;
	
	printf("Enter soft realtime: ");
	scanf("%ld", &tim);
	
	if(tim < 0){
		
		printf("Invalid argument\n");
		printf("Error no.: %d\n", 22);
		return 0;	
	}
	
	pid = fork();
	
	if(pid!=0)
	{
		status = syscall(440, pid, tim);
	
		if(status!=0){
		
			perror("Error ");
			printf("Error no.: %d\n", errno);
			return 0;
		}
		
		struct timeval t1,t2;
		gettimeofday(&t1,NULL);
		for(int i=0;i<123456789;i++);
		gettimeofday(&t2,NULL);		
		printf("Time with soft real time gaurantees in millisecs: %lf\n", (double)(t2.tv_sec-t1.tv_sec)*1000 + (double)(t2.tv_usec-t1.tv_usec)/1000);
		
		wait(NULL);
	}
	else
	{	
		struct timeval t1,t2;
		gettimeofday(&t1,NULL);
		for(int i=0;i<123456789;i++);
		gettimeofday(&t2,NULL);
		printf("Time with soft real time gaurantees in millisecs: %lf\n", (double)(t2.tv_sec-t1.tv_sec)*1000 + (double)(t2.tv_usec-t1.tv_usec)/1000);
		
		exit(0);
	}
	
	return 0;
}
