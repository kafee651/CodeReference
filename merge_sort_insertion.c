#include <stdio.h> 
#include <sys/time.h>

#define MAXIMUM 100007
#define INSERTLG 16

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

void merge_sort_insertion(long int a[], long int ln){
	long int q, i, l, j;
	
	q = ln;
	i = 0;
	while(q > INSERTLG){
		insertion_sort( &a[i],INSERTLG);
		q -= INSERTLG;
		i += INSERTLG;
	}
	insertion_sort( &a[i], q);
	j = ln / INSERTLG;
	for(l = 2;l <= j;l++){
		merges(a, 1, INSERTLG * (l - 1), INSERTLG * l);
	}
	merges(a, 1, INSERTLG * l, ln);
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
	merge_sort_insertion(a, length);
	printf("Merge Sort:\n");
	for(i = 1;i <= length;i++){
		printf("%ld\n", a[i]);
	}
	gettimeofday(&t2, NULL);
	printf("No. of Second:%ld\tNo. of Milisecond :%ld\n Hello kafee", t2.tv_sec - t1.tv_sec, t2.tv_usec - t1.tv_usec);
	return(0);
}
