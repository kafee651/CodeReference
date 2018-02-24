#include <stdio.h>
#include <math.h>

#define M 6000

int val(long int a, int d){
	return((fmod(a , pow(10, d))) / pow(10 , d - 1));
}

long int max(long int a[], int d, long int n){
	long int max, i;

	max = val(a[1], d);
	for(i = 2;i <= n;i++)
		if(max < val(a[i], d))
			max = val(a[i], d);
	return(max);
}

void counting_sort(long int a[], int d, long int n){
	long int b[M], c[M], i, k;

	k = max(a, d, n);
	for(i = 0;i <= k;i++)
		c[i] = 0;
	for(i = 1;i <= n;i++)
		c[val(a[i], d)]++;
	for(i = 1;i <= k;i++)
		c[i] += c[i - 1];
	for(i = n;i >= 1;i--){
		b[c[val(a[i], d)]] = a[i];
		c[val(a[i], d)]--;
	}
	for(i = 1;i <= n;i++)
		a[i] = b[i];
	return;
}

void radix_sort(long int a[], int d, long int n){
	int i, j;

	for(i = 1;i <= d;i++)
		counting_sort(a, i, n);
	return;
}

int main(){
	long int a[M], n, i, d;
	
	scanf("%ld%ld", &n, &d);
	for(i = 1;i <= n;i++)
		scanf("%ld", &a[i]);
	radix_sort(a, d, n);
	for(i = 1;i <= n;i++)
		printf("%ld\n", a[i]);
	return(0);
}
