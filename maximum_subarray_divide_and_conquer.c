/* Finding Maximum Subarray of array using divide and conquer
FIND-MAX-CROSSING-SUBARRAY(A, low, mid, high)
1	left-sum = -(infinite)
2	sum = 0
3	for i = mid downto low
4		sum = sum + A[i]
5		if sum > left-sum
6			left-sum = sum
7			max-left = i 
8	right-sum = -(infinite)
9	sum = 0
10	for j = mid + 1 to high
11		sum  = sum + A[j]
12		if sum > right-sum
13			right-sum = sum
14			max-right = j
15	return(max-left, max-right, left-sum+right-sum)


FIND-MAXIMUM-SUBARRAY(A, low, high)
1 	if high == low
2		return(low, high, A[low])         // base case:only one element
3	else	mid = (low + high) / 2
4		(left-low, left-high, left-sum) = FIND-MAXIMUM-SUBARRAY(A, low, mid)
5 		(right-low, right-high, right-sum) = FIND-MAXIMUM-SUBARRAY(A, mid + 1, high)
6		(cross-low, cross-high, cross-sum) = FIND-MAX-CROSSING-SUBARRAY(A, low, mid , high)
7		if left-sum >= right-sum and left-sum >= cross-sum
8			return(left-low, left-high, left-sum)
9		elseif right-sum >= left-sum and right-sum >= cross-sum
10			return(right-low right-high, right-sum)
11		else return(cross-low, cross-high, cross-sum)

T(n) = tetha(1)           if n =1
       2T(n/2) + tetha(n) if n > 1

*/
#include <stdio.h>
#include <sys/time.h>

#define INFINITE -10000

int long max_cross_subarray(int a[], int *low, int *mid, int *high, int *lmax, int *rmax){
	long int i, lsum, rsum, sum;
	
	lsum = INFINITE;
	sum = 0;	
	for(i = *mid;i >= *low;i--){
		sum += a[i];
		if(sum > lsum){
			lsum = sum;
			*lmax = i;
		}
	}
	rsum = INFINITE;
	sum = 0;
	for(i = *mid + 1;i <= *high;i++){
		sum += a[i];
		if(sum > rsum){
			rsum = sum;
			*rmax = i;
		}
	}
	return(lsum + rsum);
}

long int max_subarray_brute_force(int a[], int *low, int *high, int *start, int *end){
	long int i, j, sum1, sum;

	sum = 0;
	for(i = *low;i <= *high;i++){
		sum1 = 0;
		for(j = i;j <= *high;j++){
			sum1 += a[j];
			if(sum < sum1){
				sum = sum1;
				*start = i;
				*end = j;
			}
		}
	}
	return(sum);
}

long int max_subarray(int a[], int *low, int *high, int *start, int *end){
	int mid, llow, lhigh, rlow, rhigh, clow, chigh;
	long int lsum, rsum, csum;
	if(*high == *low){
		*start = *low;
		*end = *high;
		return(a[*low]);
	}
	else if((*high - *low + 1) < 30){
		return(max_subarray_brute_force(a, low, high, start, end));
	}	
	else {
		mid = (*low + *high) / 2;
		lsum = max_subarray(a, low, &mid, &llow, &lhigh);
		csum = max_cross_subarray(a, low, &mid, high, &clow, &chigh);
		mid += 1;
		rsum = max_subarray(a, &mid, high, &rlow, &rhigh);
		if((lsum >= rsum) && (lsum >= csum)){
			*start = llow;
			*end = lhigh;
			return(lsum);
		}
		else if((rsum >= lsum) && (rsum >= csum)){
			*start = rlow;
			*end = rhigh;
			return(rsum);
		}
		else{
			*start = clow;
			*end = chigh;
			return(csum);
		}
	}
}

int main(){
	int a[102], n, i, low, high, start, end;
	long int sum;
	struct timeval t1, t2;
	
	gettimeofday(&t1, NULL);
	//printf("Enter length and array whose max subarray is to find:");
	scanf("%d", &n);
	for(i = 1;i <= n;i++){
		scanf("%d", &a[i]);
	}
	start = end = 0;
	low = 1;
	high = n;
	sum = max_subarray(a, &low, &high, &start, &end);
	printf("Sum:%ld\nStart:%d\nEnd:%d\n", sum, start, end);
	gettimeofday(&t2, NULL);
	printf("no of second:%ld\t no of milisecond:%ld", t2.tv_sec - t1.tv_sec, t2.tv_usec - t1.tv_usec);
	return(0);
}

