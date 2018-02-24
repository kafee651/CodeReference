/*Insertion sort:
Algorithm:
Sorting Hand of cards


insertion_sort(A)
for j = 2 to A.length
	key = A[j]
	//Insert A[j] into the sorted sequence A[1..j-1]
	i = j - 1
	while i > 0 and A[i] > key
		A[i + 1] = A[i]
		i = i - 1
	A[i + 1] = key

Best case: For this algorithm when array is sorted
           running time: theta(n)
Worst case:For this algorithm when array is sorted in reverse order
	   running time: theta(n2)
Average case:Same as Worst case
*/

#include <stdio.h>
#include <sys/time.h>

#define MAXSIZE 100006

void insertion_sort(long int a[], long int length){
	long int j, i, key;
	
	for(j = 2;j <= length;j++){
		key = a[j];
		i = j - 1;
		while(i > 0 && a[i] > key){
			a[i + 1] = a[i];
			i--;
		}
		a[i + 1] = key;
	}
	return;
}
int main(){
	long int i, j, length, a[MAXSIZE];
	struct timeval t1, t2;
	
	gettimeofday(&t1, NULL);
	scanf("%ld", &length);
	for(i = 1;i <= length;i++){
		scanf("%ld", &a[i]);
	}
	insertion_sort(a, length);
	printf("Insertion Sort\n");
	for(i = 1;i <= length;i++){
		printf("%ld\n", a[i]);
	}
	gettimeofday(&t2, NULL);
	printf("no of second:%ld\t no of milisecond:%ld", t2.tv_sec - t1.tv_sec, t2.tv_usec - t1.tv_usec);
	return(0);
}
