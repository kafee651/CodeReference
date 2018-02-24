/*Merges two sorted array into one sorted array
Algorithm:
MERGE(A, p, q,r)
	n1 = q - p + 1
	n2 = r - q
	//let L[1..n1+1] and R[1..n2+1] be new arrays
	for i = 1 to n1
		L[i] = A[p + i -1]
	for j = 1 to n2
		R[j] = A[q + i]
	L[n1 + 1] = high
	R[n2 + 1] = high	
	i = 1
	j = 1
	for k = p to r
		if L[i] <= R[j]
			A[k] = L[i]
			i = i + 1
		else    A[k] = R[j]
			j = j + 1

Running time in all case will be theta(n)
Space : it require theta(n) space extra

*/
#include <stdio.h>

#define MAXS 1000000000
#define LIMIT 100000

void merges(long int a[], long int p, long int q, long int r){
	long int n1, n2, i, j, k, lf[LIMIT], rt[LIMIT];

	n1 = q - p + 1;
	n2 = r - q;
	for(i = 1;i <= n1;i++){
		lf[i] = a[p + i - 1];
	}
	for(j = 1;j <= n2;j++){
		rt[j] = a[q + j];
	}
	lf[n1 + 1] = MAXS;
	rt[n2 + 1] = MAXS;
	i = j = 1;
	for(k = p;k <= r;k++){
		if(lf[i] <= rt[j]){
			a[k] = lf[i];
			i++;
		}
		else{
			a[k] = rt[j];
			j++;
		}
	}
	return;
}
