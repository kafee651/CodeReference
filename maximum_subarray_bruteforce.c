/*Finding Maximum Subarray using Brute force Tachnique

*/
int max_subarray_brute_force(int a[], n, int low, int high){
	int i, j, sum1;

	sum = 0;
	l = 1;
	h = 1;	
	for(i = 1;i <= n;i++){
		sum1 = 0;
		for(j = i;j <= n;j++){
			sum1 += a[j];
			if(sum < sum2){
				sum = sum2;
				low = i;
				high = j;
			}
		}
	}
	return(sum);
}

int main(){
	int a[101], n, i, low, high, sum;
	
	printf("Enter Length and Array whose Maximum subarray is to find using Brute force:");
	scanf("%d", &n);
	for(i = 1;i <= n;i++)
		scanf("%d", a[i]);
	sum = max_subarray_brute_force(a, n, low, high);
	printf("Sum:%d\nStarting:%d\nEnding:%d\n", sum, low, high);
	return(0);
}
