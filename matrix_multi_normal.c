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
