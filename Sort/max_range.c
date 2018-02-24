#include <stdio.h>

#define SIZE 5005

void swap(long int a[], int i, int j){
	long int temp;

	temp = a[i];
	a[i] = a[j];
	a[j] = temp;
	return;
}
int partition_n_lomuto(long int a[], int p, int r){
	int i, j, x;
	
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


void quick_sort(long int a[], int p, int r){
	int q, i;
	
	if(p < r){
		q = partition_n_lomuto(a, p, r);
		quick_sort(a, p, q - 1);
		quick_sort(a, q + 1, r);
	}
	return;
}

int main(){
	long int a[SIZE], min;
    int t, n, i;
	
	scanf("%d", &t);
    while(t--){
               scanf("%d", &n);
               for(i = 1;i <= n;i++)
		             scanf("%ld", &a[i]);
               quick_sort(a, 1, n);
               min = a[2] - a[1];
	           for(i = 3;i <= n;i++){
                     if(min > a[i] - a[i - 1])
                            min = a[i] - a[i - 1];
               }
               printf("%ld\n", min);
	}
	return(0);
}
	
