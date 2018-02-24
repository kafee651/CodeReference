#include <stdio.h>
#include <math.h>
//#include <sys/time.h>

#define M 600090
#define log2(n) log(n)/log(2)

void swap(long int a[], long int p, long int q){
	long int temp;

	temp = a[p];
	a[p] = a[q];
	a[q] = temp;
	return;
}
void max_heapify_iterative(long int a[], long  int size, long int heap_size){
	long int i, lt, rt, largest, temp;
	
//	temp = log10(size) / log10(2);
	for(i = 1;i <= size;i++){
		lt = heap_size * 2;
		rt = lt + 1;
		if((a[lt] > a[heap_size]) && (size >= lt)){
			largest = lt;
		}else 
			largest = heap_size;
		if((a[rt] > a[largest]) && (size  >= rt))
			largest = rt;
		if(largest == heap_size)
			break;
		swap(a, heap_size, largest);
		heap_size = largest;
	}
	return;
}

void max_heapify(long int a[], long int size, long int heap_size){
	long int lt, rt, largest;
	
	lt = heap_size * 2;
	rt = heap_size * 2 + 1;		
	if((a[lt] > a[heap_size]) && (size >= lt)){
		largest = lt;
	}else 
		largest = heap_size;
	if((a[rt] > a[largest]) && (size  >= rt))
		largest = rt;
	if(largest != heap_size){
		swap(a, heap_size, largest);
		max_heapify(a, size, largest);
	}
	return;
}

void min_heapify(long int a[], long int size, long int heap_size){
	long int lt, rt, smallest;

	lt = heap_size * 2;
	rt = lt + 1;
	if((lt <= size) && (a[lt] < a[heap_size])){
		smallest = lt;
	}
	else
		smallest = heap_size;
	if((rt <= size) && (a[rt] < a[smallest]))
		smallest = rt;
	if(smallest != heap_size){
		swap(a, smallest, heap_size);
		min_heapify(a, size, smallest);
	}
	return;
}

void build_max_heap(long int a[],long int size){
	long int i, j;
	
	for(i = size / 2;i >= 1;i--){
		max_heapify(a, size, i);
	}
	return;
}


void heapsort(long int a[],long int size){
	long int i, j, heap_size;
		
	build_max_heap(a, size);
	heap_size = size;
	for(i = size; i >= 2;i--){
		swap(a, 1, heap_size);
		heap_size -= 1;
		max_heapify(a, heap_size, 1);
	}
	return;
}


int main(){
	long int a[M], i, j, n;
//	struct timeval t1, t2;

	//gettimeofday(&t1, NULL);
	scanf("%ld", &n);
	for(i = 1;i <= n;i++){
		scanf("%ld", &a[i]);
	}
	heapsort(a, n);
	for(i = 1;i <= n;i++){
		printf("%ld\t", a[i]);
	}
	//gettimeofday(&t2, NULL);
	//printf("no of second:\n%ld\t no of milisecond:%ld", t2.tv_sec - t1.tv_sec, t2.tv_usec - t1.tv_usec);
	return(0);
}	
	
