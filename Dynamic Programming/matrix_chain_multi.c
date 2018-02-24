#include <stdio.h>

#define M 1000000000

void MaxMatrix_chain_multi(long int order[], long int length, long int multi[][100], long int s[][100]){
	long int l, i, j, q, k;

	for(i = 1;i <= length;i++)
		multi[i][i] = 0;
	for(l = 2;l <= length;l++){
		for(i = 1;i <= length - l + 1;i++){
			j = i + l - 1;
			multi[i][j] = 0;
			for(k = i;k < j;k++){
				q = multi[i][k] + multi[k + 1][j] + order[i - 1] * order[k] * order[j];
				if(q > multi[i][j]){
					multi[i][j] = q;
					s[i][j] = k;
				}
			}
			printf("%ld\t", multi[i][j]);
		}
	}
	return;
}


void matrix_chain_multi(long int order[], long int length, long int multi[][100], long int s[][100]){
	long int l, i, j, q, k;

	for(i = 1;i <= length;i++)
		multi[i][i] = 0;
	for(l = 2;l <= length;l++){
		for(i = 1;i <= length - l + 1;i++){
			j = i + l - 1;
			multi[i][j] = M;
			for(k = i;k < j;k++){
				q = multi[i][k] + multi[k + 1][j] + order[i - 1] * order[k] * order[j];
				if(q < multi[i][j]){
					multi[i][j] = q;
					s[i][j] = k;
				}
			}
			printf("%ld\t", multi[i][j]);
		}
	}
	return;
}



void parenthesis_matrix(long int s[][100], long int i, long int j){

	if(i == j)
		printf("A");
	else{
		printf("(");
		parenthesis_matrix(s, i, s[i][j]);
		parenthesis_matrix(s, s[i][j] + 1, j);
		printf(")");
	}
	return;
}

long int TDmatrix_chain(long int order[], long int i, long int j, long int multi[][100], long int s[][100]){
	long int k, q;
	
	if(i == j){
		return(0);
	}
	else if(multi[i][j] < M)
		return(multi[i][j]);
	else{
		for(k = i;k < j;k++){
			q = TDmatrix_chain(order, i, k, multi, s) + TDmatrix_chain(order, k + 1, j, multi, s) + order[i - 1] * order[k] * order[j];
			if(q < multi[i][j]){
				multi[i][j] = q;
				s[i][j] = k;
			}
		}
		return(multi[i][j]);
	}
}		
		

void TDmatrix_chain_multi(long int order[], long int length, long int multi[][100], long int s[][100]){
	long int i, j, k;

	for(i = 1;i <= length;i++)
		for(j = 1;j <= length;j++)
			multi[i][j] = M;	
	multi[1][length] = TDmatrix_chain(order, 1, length, multi, s);
	return;
}

int main(){
	long int order[100], length, multi[100][100], s[100][100], i, j, k;

	scanf("%ld", &length);
	for(i = 0;i <= length;i++){
		scanf("%ld", &order[i]);
	}
	MaxMatrix_chain_multi(order, length, multi, s);
	printf("%ld", multi[1][length]);
	printf("Fully parenthesis matrix chain is:");
	parenthesis_matrix(s, 1, length);
	return(0);
}
