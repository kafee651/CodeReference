/*TWO-ARRAY-MEDIAN(X, Y)
n ← length[X]      £ n also equals length[Y ]
median ← FIND-MEDIAN(X, Y, n, 1, n)
if median = NOT-FOUND
then median ← FIND-MEDIAN(Y, X, n, 1, n)
return median

FIND-MEDIAN ( A, B, n, low, high)
	if low > high
		then return NOT-FOUND
	else 
		k ← (low + high)/2
	if k = n and A[n] ≤ B[1]
		then return A[n]
	else if k < n and B[n − k] ≤ A[k] ≤ B[n − k + 1]
		then return A[k]
	else if A[k] > B[n − k + 1]
		then return FIND-MEDIAN ( A, B, n, low, k − 1)
	else 
		return FIND-MEDIAN ( A, B, n, k + 1, high)
*/

#include <stdio.h>

#define M 1000


long int find_median(long int a[], long int b[], long int n, long int low, long int high){
	long int k;

	if(low > high)
		return(0);
	else
		k = (low + high) / 2;
	if((k == n) && (a[n] <= b[1]))
		return(a[n]);
	else if((k < n) && a[k] <= b[n - k + 1] && a[k] >= b[n - k])
		return(a[k]);
	else if(a[k] > b[n - k + 1])
		return(find_median(a, b, n, low, k - 1));
	else
		return(find_median(a, b, n, k + 1, high));
}

long int two_array_median(long int a[], long int b[], long int n){
	long int median;

	if(median = find_median(a, b, n, 1, n))
		return(median);
	else
		median = find_median(b, a, n, 1, n);
	return(median);
}

	
int main(){
	long int a[M], b[M], n, i, j, k;

	scanf("%ld", &n);
	for(i = 1;i <= n;i++)
		scanf("%ld", &a[i]);
	for(i = 1;i <= n;i++)
		scanf("%ld", &b[i]);
	printf("%ld", two_array_median(a, b, n));
	
	return(0);
}
	
