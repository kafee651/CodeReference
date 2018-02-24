#include <stdio.h>
 
int main(){
    int i, j, k, t, x, temp, m, n, a[200];
    
    scanf("%d", &t);
    for(k = 1;k <= t;k++){
        scanf("%d", &n);
        m = j = 0;
        i = 1;
        temp = 0;
        a[0] = 1;
        while(i <= n){
                while(j <= m){
                        x = a[j] * i + temp;
                        a[j] = x % 100;
                        temp = x / 100;
                        j++;
                }
                while(temp != 0){
                        a[j] = temp % 100;
                        temp = temp / 100;
                        j++;
                }
                m = --j;
                j = 0;
                i++;
        }
        printf("%d", a[m--]);
        for(i = m;i >= 0;i--){
              if(a[i] < 10)
                      printf("0%d", a[i]);
              else
                      printf("%d", a[i]);
        }
        printf("\n");
    }
    return(0);
} 
