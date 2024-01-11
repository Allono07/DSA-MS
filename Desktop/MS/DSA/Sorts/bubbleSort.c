#include <stdio.h>

int main() {
    int arr[] = {5,1,3,2,5,7};
    for(int i=0;i<6;i++){
        for(int j=0;j<6;j++){
            if(arr[j]>arr[i]){
                int a = arr[j];
                arr[j]=arr[i];
                arr[i]=a;
            }
        }
    }
    for(int i=0;i<6;i++){
        printf("%d", arr[i]);
    }
    }