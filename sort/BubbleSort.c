#include <stdio.h>

void BubbleSort(int arr[], int n){
    int i,j;
    int temp;
    
    for(i=0; i<n-1; i++){ //처음부터 끝 전까지 왜냐면 맨끝은 비교할 다음게 없으니까
        printf("i : %d\n", i);
        
        for(j=0; j<n-1; j++){ //버블 정렬
            if(arr[j]>arr[j+1]){
                printf("change %d: %d \n", j, j+1);
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

int main(void)
{
    int arr[5]= {15, 3, 11, 2, 9};
    int i;
    
    BubbleSort(arr, sizeof(arr)/sizeof(int));
    
    for(i=0; i<5; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}
