#include<stdio.h>
void shellsort(int arr[], int n)
{
    int gap,i,j,temp;
    for(gap=n/2; gap>0; gap/=2)
    {
        for(i=gap;i<n;i++)
        {
            temp=arr[i];
            for(j=i-gap;j>=0 && arr[j]>temp;j=j-gap)
            {
                arr[j+gap]=arr[j];
            }
            arr[j+gap]=temp;
        }
    }
}
int main()
{
    int arr[]={7,4,8,10,16,6,11,3,1,2};
    int i;
    printf("Before Sorting.........\n");
    for(i=0;i<10;i++)
    printf("%d ",arr[i]);
    shellsort(arr,10);
    printf("\nAfter Sorting..........\n");
    for(i=0;i<10;i++)
    {
        printf("%d ",arr[i]);
    }
    return 0; 
}