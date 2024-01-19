#include<stdio.h>
#include<stdlib.h>
int size;
int *a;

int merge(int a[],int lb,int mid,int ub){
    int i=lb;
    int j;
    j=mid+1;
    int k =lb;
    int b[ub];
    while(i<=mid && j<=ub){
        if(a[i]<=a[j]){
            b[k]=a[i];
            i++;
        }
        else {
            b[k]=a[j];
            j++;
        }
        k++;
    }
    if(i>mid){
        while(j<=ub){
            b[k]=a[j];
            j++;
            k++;
        }
       
    }
     else{
            while(i<=mid){
                b[k]=a[i];
                i++;
                k++;
            }
        }

        for (i = lb; i <= ub; i++) {
        a[i] = b[i];
    }
}

int mergeSort(int a[],int lb,int ub){
    if(lb<ub){
       int mid=(lb+ub)/2;
        mergeSort(a,lb,mid);
        mergeSort(a,mid+1,ub);
        merge(a,lb,mid,ub);
    }
    
}


int main()
{
    int val;
    printf("Enter the size of the array");
    scanf("%d",&size);
    a = (int *)malloc(size * sizeof(int));
 printf("Enter the values of the array, up to %d values: ", size);
    for (int i = 0; i < size; i++) {
        scanf("%d", &a[i]);
    }
int lb =0;
int ub = size-1;
printf("The given array is");
    for(int i=0;i<size;i++){
        printf("%d ",a[i]);
    }

mergeSort(a,lb,ub);

  printf("\nThe sorted array is: ");
    for (int i = 0; i <size; i++) {
        printf("%d ", a[i]);
    }
     free(a);
return 0;
}