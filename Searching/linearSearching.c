#include<stdio.h>
int linearSearch(int arr[], int n, int key)
{
    int i;
    for(i=0; i<n; i++)
    if(arr[i]==key)
    return i;
    return -1;
}
int main()
{
    int arr[]={12,45,67,87,43,23,44,90,11,52};
    int key,found;
    printf("Enter a number you want to search:");
    scanf("%d",&key);;
    found=linearSearch(arr,10,key);
    if(found=-1)
    printf("%d doesnot exist in the list.",key);
    else
    printf("%d found at position %d",key,found+1);
    return 0;
}


