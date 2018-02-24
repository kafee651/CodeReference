#include <stdio.h>
#include <conio.h>

void swap(char list[], int start, int end){
     int temp;
     
     temp = list[start];
     list[start] = list[end];
     list[end] = temp;
     return;
}

void ReverseString(char list[], int start, int end){
     while(start < end){
                 swap(list, start, end);
                 start++;
                 end--;
     }
     return;
}

void ReverseWord(char list[]){
     int start, endword;
     
     start = 0;
     endword = 0;
     while(1){
              
              if(list[endword] == ' ' || list[endword] == '\0'){
                               ReverseString(list, start, endword - 1);
                               start = endword + 1;
              }
              if(list[endword] == '\0'){
                               ReverseString(list, 0, endword - 1);
                               break;
              }
              endword++;
     }
     return;
}

int main(){
    char list[100];
    gets(list);
    ReverseWord(list);
    puts(list);
    getchar();
    return(0);
}
