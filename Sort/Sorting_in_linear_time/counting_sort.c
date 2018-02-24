#include <stdio.h>
#include <sys/time.h>

#define M 600000

long int max(long int a[], long int n){
	long int max, i;

	max = a[1];
	for(i = 2;i <= n;i++)
		if(max < a[i])
			max = a[i];
	return(max);
}

void counting_sort(long int a[], long int n){
	long int b[M], c[M], i, k;

	k = max(a, n);
	printf("%ld\n", k);
	for(i = 0;i <= k;i++)
		c[i] = 0;
	for(i = 1;i <= n;i++)
		c[a[i]]++;
	for(i = 1;i <= k;i++)
		c[i] += c[i - 1];
	for(i = 1;i <= n;i++){
		b[c[a[i]]] = a[i];
		c[a[i]]--;
	}
	for(i = 1;i <= n;i++)
		a[i] = b[i];
	return;
}

int main(){
	long int a[M], n, i;
	struct timeval t1, t2;

	gettimeofday(&t1, NULL);
	scanf("%ld", &n);
	for(i = 1;i <= n;i++)
		scanf("%ld", &a[i]);
	counting_sort(a, n);
	for(i = 1;i <= n;i++)
		printf("%ld\t", a[i]);
	gettimeofday(&t2, NULL);
	printf("Time in second:%ld\tTime in millisecond:%ld", t2.tv_sec - t1.tv_sec, t2.tv_usec - t1.tv_usec); 
	return(0);
}

