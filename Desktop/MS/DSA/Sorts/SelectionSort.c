#include<stdio.h>
#define N 7
void main()
{
    printf("The sorted array is\n");
int arr[]={1,5,1,2,7,3,3};
for(int i=0;i<N-1;i++){
   int min = i;
    for (int j=i+1;j<N;j++){
        if(arr[j]<arr[min]){
            min = j;
        }
    }


  if(min!=i){
        int temp;
        temp = arr[i];
        arr[i]=arr[min];
        arr[min] = temp;
    }

}

for(int i=0;i<N;i++){
    printf("%d",arr[i]);
}

}