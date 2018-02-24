/*Selection Sort:
Algorithm:
sort in non-decresing order

Selecting Smaller number form array each times excluding previous selected

for j = 1 to A.length - 1
	//Select jth element and compair with other element if it is found that it is greater than other element than it is swap with that
	for i = j + 1 to A.length
		if A[j] > A[i] then
			temp = A[j]
			A[j] = A[i]
			A[i] = temp

Best case, Worst case, Average case: All have same as time complexity theta(n2)
*/



#include <stdio.h>
#include <sys/time.h>

#define MAX 100006

void selection_sort(long int a[], long int length){
	long int j, i, temp;
	
	for(j = 1;j <= length - 1;j++){
		for(i = j + 1;i <= length;i++){
			if(a[j] > a[i]){
				temp = a[j];				
				a[j] = a[i];
				a[i] = temp;
			}
		}
	}
	return;
}

int main(){
	long int length, a[MAX], i;
	struct timeval t1, t2;
	
	gettimeofday(&t1, NULL);
	scanf("%ld", &length);
	for(i = 1;i <= length;i++){
		scanf("%ld", &a[i]);
	}
	selection_sort(a, length);
	printf("Selection Sort\n");
	for(i = 1;i <= length;i++){
		printf("%ld\n",a[i]);
	}
	gettimeofday(&t2, NULL);
	printf("no of second:%ld\t no of milisecond:%ld", t2.tv_sec - t1.tv_sec, t2.tv_usec - t1.tv_usec);
	return(0);
}
