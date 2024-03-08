#include <stdio.h>

void SelSort(int arr[], int n){//선택 정렬: 배열에서 가장 작은 값을 찾아 교환

    int minidx;

    int i, j;

    for(i=0; i<n-1; i++){//맨 앞부터 맨 뒤의 앞까지만 돌리면 됨 (i가 기준)
        minidx = i;
        printf("minidx: %d\n", minidx);
        for(j=i+1; j<n; j++){//i+1 부터 끝까지 돌리면서 최솟값 찾기
            if(arr[j]<arr[minidx]){
                minidx=j;
                printf("new minidx-data : %d-%d\n", minidx, arr[minidx]);
            }
        }
        int temp;
        temp = arr[i];
        arr[i] = arr[minidx];
        arr[minidx] = temp;
    }

}

int main()
{
    int arr[5]={16, 3, 28, 1, 2};

    SelSort(arr, sizeof(arr)/sizeof(int));

    int i;
    for(i=0; i<sizeof(arr)/sizeof(int); i++){
        printf("%d ", arr[i]);
    }
    return 0;

}
