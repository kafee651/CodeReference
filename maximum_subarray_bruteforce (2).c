/*Finding Maximum Subarray using Brute force Tachnique

*/


#include <stdio.h>
#include <sys/time.h>

int max_subarray_brute_force(int a[], int n, int *low, int *high){
	int i, j, sum1, sum;

	sum = 0;
	for(i = 1;i <= n;i++){
		sum1 = 0;
		for(j = i;j <= n;j++){
			sum1 += a[j];
			if(sum < sum1){
				sum = sum1;
				*low = i;
				*high = j;
			}
		}
	}
	return(sum);
}

int main(){
	int a[101], n, i, low, high, sum;
	struct timeval t1, t2;

	gettimeofday(&t1, NULL);	
	printf("Enter Length and Array whose Maximum subarray is to find using Brute force:");
	scanf("%d", &n);
	for(i = 1;i <= n;i++)
		scanf("%d", &a[i]);
	sum = max_subarray_brute_force(a, n, &low, &high);
	printf("Sum:%d\nStarting:%d\nEnding:%d\n", sum, low, high);
	gettimeofday(&t2, NULL);
	printf("no of second:%ld\t no of milisecond:%ld", t2.tv_sec - t1.tv_sec, t2.tv_usec - t1.tv_usec);
	return(0);
}
