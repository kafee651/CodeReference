/*Horner's Rule for evaluating a polynomial
P(x) = summation for k = 0 to n (a(k) * x rase to k)
     = a0 + x(a1 + x(a2 + ... + x(a(n-1) + xan)...))
given the coeficients a0, a1, a2, ...an and a value for x:


HORNER_POLY()
1	y = 0
2 	for i = n downto 0
3		y = a[i] + x.y


conclusion:  n + 1 multiplication
	     n + 1 addition


Normal evaluation of a polynomial

NORMAL_POLY()
1	y = a[0]
2	for i = 1 downto n
3		temp = 1;
4		for j = 1 downto i
5			temp = temp * x
6		y = y + temp * a[i]

Conclusion: (n * (n + 1)) / 2 + n multiplication
	    n                     addition

*/
#include <stdio.h>
#include <sys/time.h>

#define MAX 10000
#define X 1

long int horner_poly(long int a[], long int n, long int x){
	long int y, i;
	
	y = 0;
	for(i = n;i >= 0;i--){
		y = a[i] + x * y;
	}
	return(y);
}

long int normal_poly(long int a[], long int n, long int x){
	long int y, i, j, temp;
	
	y = a[0];
	for(i = 1;i <= n;i++){
		temp = 1;
		for(j = 1;j <= i;j++)
			temp = temp * x;
		y = y + temp * a[i];
	}
	return(y);
}


int main(){
	long int length, a[MAX], i, y1, y2, n;
	struct timeval t1, t2;
	
	gettimeofday(&t1, NULL);
	scanf("%ld", &n);
	for(i = 0;i <= n;i++){
		scanf("%ld", &a[i]);
	}
	y1 = horner_poly(a, n, X);
	//y2 = normal_poly(a, n, X);
	printf("Value using Horner methode:%ld\t", y1);
	//printf("Value using Normal methode:%ld", y2);
	gettimeofday(&t2, NULL);
	printf("no of second:%ld\t no of milisecond:%ld", t2.tv_sec - t1.tv_sec, t2.tv_usec - t1.tv_usec);
	return(0);
}
