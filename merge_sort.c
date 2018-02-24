#include <stdio.h> 
#include <sys/time.h>

#define MAXIMUM 100007

void merge_sort(long int a[], long int p, long int r){
	long int q;
		
	if(p < r){
		q = (p + r) / 2;
		merge_sort(a, p, q);
		merge_sort(a, q + 1, r);
		merges(a, p, q, r);
	}
	return;
}
	
		
int main(){
	long int length, a[MAXIMUM], i;
	struct timeval t1,t2;
	
	gettimeofday(&t1, NULL);
	scanf("%ld", &length);
	for(i = 1;i <= length;i++){
		scanf("%ld", &a[i]);
	}
	merge_sort(a, 1, length);
	printf("Merge Sort:\n");
	for(i = 1;i <= length;i++){
		printf("%ld\n", a[i]);
	}
	gettimeofday(&t2, NULL);
	printf("No. of Second:%ld\tNo. of Milisecond :%ld", t2.tv_sec - t1.tv_sec, t2.tv_usec - t1.tv_usec);
	return(0);
}
