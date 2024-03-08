#include <stdio.h>

void InsertSort(int arr[], int n){ //삽입정렬

    int flagData; //정렬할 값

    int i, j;

    for(i=1; i<n; i++){
        flagData = arr[i];
        printf("check [%d]: %d \n", i, flagData);

        for(j=i-1; j>=0; j--){ //자기 앞에부터 앞으로 순차대로 돔
            if(arr[j]>flagData){
                arr[j+1] = arr[j];
            }
            else{
                break;
            }
        }
        arr[j+1] = flagData; //찾은 위치에 기준값 삽입
    }

}

int main(void)
{
    int arr[5]={12, 3, 9, 10, 1};
    int i;

    InsertSort(arr, sizeof(arr)/sizeof(int));

    for(i=0;i<5;i++){
        printf("%d \n", arr[i]);
    }
    return 0;
}

