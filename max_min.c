#include <stdio.h>

#define M 10000

void max_min(long int a[], long int n, long int *max, long int *min){
	long int i, j, k;
	
	i = 1;
	if(n % 2 )
		if(a[i] > a[i + 1]){
			*max = a[i++];
			*min = a[i++];
		}
		else{
			*max = a[i + 1];
			*min = a[i];
			i += 2;
		}
	else	
		*max = *min = a[i++];
	while(i <= n){
		if(a[i] > a[i + 1]){
			if(a[i] > *max)
				*max = a[i];
			if(a[i + 1] < *min)
				*min = a[i + 1];
		}
		else{	
			if(a[i + 1] > *max)
				*max = a[i + 1];
			if(a[i] < *min)
				*min = a[i];
		}
		i += 2;
	}
	return;
}

int main(){
	long int a[M], i, j, k, n, max, min;

	scanf("%ld", &n);
	for(i = 1;i <= n;i++)
		scanf("%ld", &a[i]);
	max_min(a, n, &max, &min);
	printf("Max:%ld\tMin:%ld", max, min);
	
	return(0);
}
