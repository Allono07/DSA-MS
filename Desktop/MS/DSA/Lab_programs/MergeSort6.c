#include<stdio.h>

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
int a[8] = {4,1,6,2,6,78,95,1};
int lb =0;
int ub = 7;
printf("The given array is");
    for(int i=0;i<8;i++){
        printf("%d ",a[i]);
    }

mergeSort(a,lb,ub);

  printf("\nThe sorted array is: ");
    for (int i = 0; i < 8; i++) {
        printf("%d ", a[i]);
    }
return 0;
}