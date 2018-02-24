/*There are two ways in dynamic programming First is Top down method, other is BottomUp method
  Difference between these two methodes are:
          1.Top down is recursive, where as Bottom up is iterative.
          2.Top down use Depth first search approch, where as Bottom up use reverse topological sorting path.
	  3.Top down we start from given 'n' value, where as In Bottom up use use 1 to n calculation

Dynamic programming change exponantial time program into polonomial time program in the cost of memory that why it is called as time-memory trade-off
*One thing very important to note that hear subproblem is not limited to particular range i.e it's subproblem is not disjoint in nature.

we usually do with Bottom up approch as we generally get the stating point


There are four steps in Dynamic programming:
	1.Categories "the structure" of an optimal solution.
	2.Recursively define "the value" of an optimal solution.
	3.Compute the value of an optimal solution, typically in bottom up fashion.
	4.Construct an optimal solution from computed information.

Designed by Mohammad Kafee Uddin (Referene CLRS)*/

#include <stdio.h>

#define M 1000

int max(int a, int b){
    if(a > b)
         return(a);
    else
         return(b);
}

/*Top down approach*/

int TDrodcut(int price[], int length_rod, int r[]){
	int i, j, q;

	if(r[length_rod] > -M)
		return(r[length_rod]);
	if(length_rod == 0)
		return(0);
	else{
		q = -M;
		for(i = 1;i <= length_rod;i++){
			q = max(q, price[i] + TDrodcut(price, length_rod - i, r));
		}
		r[i] = q;
	}
	return(q);
}		

int topDownRodCut(int price[], int length_rod){
	int r[M], i;

	for(i = 1;i <= length_rod;i++){
		r[i] = -M;
	}
	return(TDrodcut(price, length_rod, r));
}		

void printCutRodSol(int s[], int length_rod){
	while(length_rod){
		printf("\t%d", s[length_rod]);
		length_rod -= s[length_rod];
	}
	return;
}

int bottomUpRodCut(int price[], int length_rod){
	int r[M], s[M], q, i, j;

	r[0] = 0;
	for(i = 1;i <= length_rod;i++){
		q = -M;
		for(j = 1;j <= i;j++){
			if(q < price[j] + r[i - j] ){
				q = price[j] + r[i - j];
				s[i] = j;
		}
		r[i] = q;
	}
	printCutRodSol(s, length_rod);
	return(r[length_rod]);
}	

int main(){
    int price[100], number, length_rod, i, tOPrice;
    
    scanf("%d", &number);
    for(i = 1;i <= number;i++){
          scanf("%d", &price[i]);
    }
    scanf("%d", &length_rod);
    tOPrice = bottomUpRodCut(price, length_rod);
    printf("%d", tOPrice);
    return(0);
}
