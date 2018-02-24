#include <stdio.h>
#include <string.h>
#include <conio.h>

void LPS(char pat[], int m,  int lps[]){
     int i, len;
     i = 1;
     len = 0;
     lps[0] = 0;
     while(i < m){
             if(pat[i] == pat[len]){
                       len++;
                       lps[i] = len;
                       i++;
             }
             else{
                  if(len == 0){
                         lps[i] = 0;
                         i++;
                  }
                  else{
                         len = lps[len - 1];
                  }
             }
     }
     return;
}
             
void KMP_string_matching(char text[], char pat[]){
     int i, j, n, m, lps[100];
     
     n = strlen(text);
     m = strlen(pat);
     LPS(pat, m, lps);
     for(i = 0;i < m;i++)
     printf("%d\t", lps[i]);
     i = j = 0;
     while(i < n){
             if(text[i] == pat[j]){
                        i++;
                        j++;
                        if(j == m){
                             printf("%d\t", i - j);
                             j = lps[j - 1];
                        }
             }
             else{
                  if(j == 0){
                        i++;
                  }
                  else{
                       j = lps[j - 1];
                  }
             }
     }
     return;
}

int main(){
    char text[100], pat[10];
    int i, j, k;
    
    printf("\nEnter text and pattern string:");
    scanf("%s%s", text, pat);
    KMP_string_matching(text, pat);
    getchar();
    getchar();
    return(0);
}
