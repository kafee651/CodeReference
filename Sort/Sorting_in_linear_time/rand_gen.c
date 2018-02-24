#include <stdio.h>
#include <stdlib.h>

#define MAXS 600

int main(){
	long int i;
	double j;
	
	printf("%ld\n", MAXS);
	for(i = 1;i <= MAXS;i++){
		j = rand() % MAXS;
		printf("%lf\n", j / 600);
	}
	return(0);
}
