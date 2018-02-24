#include <stdio.h>
#include <sys/time.h>

#define SIZE 60009

void swap(long int a[], long int i, long int j){
	long int temp;

	temp = a[i];
	a[i] = a[j];
	a[j] = temp;
	return;
}

long int partition_car_hoare(long int a[], long int p, long int r){
	long int i, j, x;
	
	x = a[p];
	i = p - 1;
	j = r + 1;
	while(1){
		while(x >= a[++i]);
		while(x <= a[--j]);
		if(i < j)
			swap(a, i, j);
		else{	
			swap(a, j, p);
			return(j);
		}
	}
}

long int partition_n_lomuto(long int a[], long int p, long int r){
	long  int i, j, x;
	
	i = p - 1;
	x = r;
	for(j = p;j <= r;j++){
		if(a[x] >= a[j]){
			i++;
			swap(a, j, i);
		}
	}
	return(i);
}


void quick_sort(long int a[], long int p, long int r){
	long int q, i;
	
	if(p < r){
		q = partition_n_lomuto(a, p, r);
		quick_sort(a, p, q - 1);
		quick_sort(a, q + 1, r);
	}
	
	return;
}

int main(){
	long int a[SIZE], n, i, j;
	struct timeval t1, t2;

	gettimeofday(&t1, NULL);	
	scanf("%ld", &n);
	for(i = 1;i <= n;i++){
		scanf("%ld", &a[i]);
	}
	quick_sort(a, 1, n);
	for(i = 1;i <= n;i++){
		printf("%ld\t", a[i]);
	}
	/*printf("%ld\t", partition_car_hoare(a, 1, n));
	for(i = 1;i <= n;i++){
		printf("%ld\t", a[i]);
	}*/
	gettimeofday(&t2, NULL);
	printf("no of second:%ld\t no of milisecond:%ld", t2.tv_sec - t1.tv_sec, t2.tv_usec - t1.tv_usec);
	return(0);
}
	
