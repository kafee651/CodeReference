/*Bubble Sort
Algorithm:
Repeatedly swapping adjacent elements that are out of order

BUBBLESORT(A)
1	for i = 1 to A.length -1
2		for j = A.length downto i+1
3			if A[j] < A[j - 1]
4				exchange A[j] with A[j - 1]

Best case, Worst case, Average case: All have same as time complexity theta(n2)

Sort in non Decresing order
*/

#include <stdio.h>
#include <sys/time.h>

#define MAX 100006

void bubble_sort(long int a[], long int length){
	long int i, j, temp;

	for(i = 1;i < length;i++){
		for(j = length;j > i;j--){
			if(a[j] < a[j - 1]){
				temp = a[j];
				a[j] = a[j - 1];
				a[j - 1] = temp;
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
	bubble_sort(a, length);
	printf("Bubble Sort:\n");
	for(i = 1;i <= length;i++){
		printf("%ld\n",a[i]);
	}
	gettimeofday(&t2, NULL);
	printf("no of second:%ld\t no of milisecond:%ld", t2.tv_sec - t1.tv_sec, t2.tv_usec - t1.tv_usec);
	return(0);
}
