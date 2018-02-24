#include <stdio.h>

#define M 10000
int max(int a, int b){
    if(a > b)
         return(a);
    else
         return(b);
}

int CutRod(int p[], int n){
    int q, i;
    
    if(n == 0)
        return(0);
    q = -M;
    for(i = 1;i <= n;i++)
          q = max(q, p[i] + CutRod(p, n - i));
    return(q);

} 
int main(){
    int p[100], n, q, i, j, k;
    
    scanf("%d", &n);
    for(i = 1;i <= n;i++){
          scanf("%d", &p[i]);
    }
    scanf("%d", &q);
    q = CutRod(p, q);
    printf("%d", q);
    return(0);
}
