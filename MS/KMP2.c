#include<stdio.h>
#include<string.h>
#include<stdlib.h>
 
void computeLPSArray(char *pat, int M, int *lps);
 
void KMPSearch(char *pat, char *txt)
{
    int M = strlen(pat);
    int N = strlen(txt);
    int *lps = (int *)malloc(sizeof(int)*M);
    int j  = 0; 
 

    computeLPSArray(pat, M, lps);
 
    int i = 0; 
    while(i < N)
    {
      if(pat[j] == txt[i])
      {
        j++;
        i++;
      }
 
      if (j == M)
      {
        printf("Found pattern at index %d \n", i-j);
        j = lps[j-1];
      }
 

      else if(pat[j] != txt[i])
      {


        if(j != 0)
         j = lps[j-1];
        else
         i = i+1;
      }
    }
    free(lps); 
}
 
void computeLPSArray(char pat[], int m, int lps[]){
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
/*void computeLPSArray(char *pat, int M, int *lps)
{
    int len = 0; 
    int i;
 
    lps[0] = 0; 
    i = 1;
 

    while(i < M)
    {
       if(pat[i] == pat[len])
       {
         len++;
         lps[i] = len;
         i++;
       }
       else
       {
         if( len != 0 )
         {
           
           len = lps[len-1];
 
           
         }
         else 
         {
           lps[i] = 0;
           i++;
         }
       }
    }
}
 */

int main()
{
   char *txt = "ABABDABACDABABCABAB";
   char *pat = "ABABCABAB";
   KMPSearch(pat, txt);
   getchar();
   return 0;
}
