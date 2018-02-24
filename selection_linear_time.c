#include <stdio.h>

#define M 60009

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

long int select(long int a[], long int p, long int r, long int i){
	long int j, k;
	
	if(p == r)
		return(a[p]);
	k = partition_n_lomuto(a, p, r);
	if(i == k)
		return(a[k]);
	else if(i < k)
		return(select(a, p, k - 1, i));
	else
		return(select(a, k + 1, r, i));
}

int main(){
	long int a[M], n, i, j, k;

	scanf("%ld", &n);
	for(j = 1;j <= n;j++)
		scanf("%ld", &a[j]);
	scanf("%ld", &i);
	printf("%ld", select(a, 1, n, i));

	return(0);
}
