# include <stdio.h>
# include <stdlib.h>
# define NO_OF_CHARS 256

/* Returns an array of size 256 containg count
   of characters in the passed char array */
int *getCharCountArray(char *str)
{
   int *count = (int *)calloc(NO_OF_CHARS, sizeof(int));
   int i;

   for (i = 0; *(str+i);  i++)
      count[*(str+i)]++;

   return count;
}

/* Print duplicates present in the passed string */
void printDups(char *str)
{
  int *count = getCharCountArray(str);
  int i;
  char temp;

  for (i = 0; i < NO_OF_CHARS; i++)
    if(count[i] > 1)
        printf("%c,  count = %d \n", i,  count[i]);
}

/* Driver program to test to pront printDups*/
int main()
{
    char str[] = "test string";
    printDups(str);
    getchar();
    return 0;
}
