/*Binary Recursive Search Algorithm
Algorithm:
binary_recursive_search(A, low, high, val)
	if low <= high
		mid = (low + high) / 2
		if A[mid] == val	
			return mid
		if val < A[mid]
			binary_recursive_search(A, low, mid - 1, val)
		else
			binary_recursive_search(A, mid + 1, high, val)
	else
		return not found

Running time:it wil take log n to the base 2 or theta(lgn)

*/
#include <stdio.h>
#include <sys/time.h>

#define MAXS 100006

void check1(long int a[], long int mid, long int val){
	if( a[mid] == val)
		printf("position is %ld\n", mid);
		check1(a, mid + 1, val);
	return;
}

void check2(long int a[], long int mid, long int val){
	if( a[mid] == val)
		printf("position is %ld\n", mid);
		check2(a, mid - 1, val);
	return;
}		
	
long int binary_recursive_search(long int a[], long int low, long int high, long int val){
	long int mid;
	
	if(low <= high){
		mid = (low + high) / 2;
		if(a[mid] == val){
			printf("position is %ld\n", mid);
			//check1(a, mid + 1, val);
			//check2(a, mid - 1, val);
			return(mid);
		}
		if(val < a[mid]){
		 	return(binary_recursive_search(a, low, mid - 1, val));
		}
		else
		 	return(binary_recursive_search(a, mid + 1, high, val));
	}
	printf("Not found");
	return(0);
}

int main(){
	long int length, a[MAXS], i, j, val;
	struct timeval t1, t2;
	
	gettimeofday(&t1, NULL);
	scanf("%ld", &length);
	for(i = 1;i <= length;i++){
		scanf("%ld", &a[i]);
	}
	scanf("%ld", &val);
	j = binary_recursive_search(a, 1, length, val);
	printf("Position of search is: %ld", j);
	gettimeofday(&t2, NULL);
	printf("No of Second:%ld\t No of millisecond:%ld", t2.tv_sec - t1.tv_sec, t2.tv_usec - t1.tv_usec); 
	return(0);
}

		
			
