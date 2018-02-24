#include <stdio.h>
#include <conio.h>

int main(){
    int i;
     
    i = -102;
    i = i >> 2;
    printf("%d", i);
    getch();
    return(0);
}
