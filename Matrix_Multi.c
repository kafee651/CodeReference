#include <stdio.h>

#define M 1000

void matrix_normal(int a[][M], int b[][M], int c[][M], int row, int col){
	int i, j, k;
	
	for(i = 1;i <= row;i++){
		for(j = 1;j <= col;j++){
			c[i][j] = 0;
			for(k = 1;k <= col;k++){
				c[i][j] += a[i][k] * b[k][j];
			}
		}
	}
	return;
}

int main(){
	int row, col, i, j, a[M][M], b[M][M], c[M][M];
	
	printf("Enter order of first matrix:");
	scanf("%d%d", &row, &col);
	printf("Enter matrix element of first matrix:\n");
	for(i = 1;i <= row;i++){
		for(j = 1;j <= col;j++){
			scanf("%d", &a[i][j]);
		}
	}
	printf("Enter order of second matrix:");
	scanf("%d%d", &row, &col);
	printf("Enter matrix element of Second matrix:\n");
	for(i = 1;i <= row;i++){
		for(j = 1;j <= col;j++){
			scanf("%d", &b[i][j]);
		}
	}
	matrix_normal(a[], b[], c[], row, col);
	printf("Resultant matrix is:\n");	
	for(i = 1;i <= row;i++){
		printf("|");
		for(j = 1;j <= col;j++){
			printf("%d\t", c[i][j]);
		}
		printf("|\n");
	}
	return(0);
}
		
