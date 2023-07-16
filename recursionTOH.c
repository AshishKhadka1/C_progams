#include<stdio.h>
#include<conio.h>
void toh(int n, char s, char i, char d)
{
    if(n>0)
    {
        toh(n-1,s,d,i);
        printf(" Move %d \ndisk from %c to %c.",n,s,d);
        toh(n-1,'I','S','D');
    }
}
void main()
{
    int n;
    printf("how many disk:");
    scanf("%d",&n);
    toh(n,'S','I','D');
    getch();

}