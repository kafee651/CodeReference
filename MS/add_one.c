#include <stdio.h>
#include <conio.h>

int add_one(int x){
    return(printf("%*c%*c", x, '\r', 1, '\r'));
    return printf("%*c%*c",  x, '\r',  1, '\r');
    
}

int main(){
    int x;
    
    scanf("%d", &x);
    printf("%d", add_one(x));
    getch();
    return(0);
}
