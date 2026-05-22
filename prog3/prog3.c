#include<stdio.h>

void printsbits(int n)
{

    for(int i=31;i>=0;i--)
    {
        printf("%d",(n>>i) & 1);

    }
    printf("\n");
}
int countsbits(int n)
{
 int count =0;
 while(n)
 {
    n=n&(n-1);
 }
 return count;
}
void checkEndian()
{
    int x = 1;

    char *p = (char*)&x;

    if(*p == 1)
        printf("Little Endian\n");
    else
        printf("Big Endian\n");
}







int main()
{
    int n;
    printf("Enter the value of n:\n");
    scanf("%d",&n);

    printsbits(n);

    printf("count 1 bits\n");
    printf("%d",countsbits(n));

    printf("\nRight Shift:\n");
    printf("n >> 1 = %d\n", n >> 1);
    printf("n >> 2 = %d\n", n >> 2);

    printf("\nLeft Shift:\n");
    printf("n<< 1 = %d\n", n << 1);

    if(n & 1)
        printf("Odd\n");
    else
        printf("Even\n");

    printf("\nEndian Check:\n");
    checkEndian();

    printf("\nNegative Number Bits (-5):\n");
    printsbits(-5);

    float f = 5.75;

    printf("\nFloat Value:\n");
    printf("%f\n", f);


    return 0;

}