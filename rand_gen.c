#include <stdio.h>
#include <stdlib.h>

#define MAXS 1000
int main(){
	long int i;
	
	printf("%ld\n", MAXS);
	for(i = 1;i <= MAXS;i++){
		printf("%ld\n",(rand() % MAXS));
	}
	return(0);
}
