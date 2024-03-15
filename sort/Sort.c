#include <stdio.h>
#include<stdlib.h>

void MergeTwoArea(int arr[], int left, int mid, int right){
    printf("merge 1:m:r = %d:%d:%d\n", left, mid, right);

    int fIdx = left; //first index
    int rIdx = mid+1; //last index
    int i;

    int * sortArr = (int*)malloc(sizeof(int)*(right+1)); //임시 배열 만들기

    int sIdx = left;
    while (fIdx<=mid && rIdx<=right){ //자기 배열이 아닌거에 넘어가지 않게 하기 위해
        if(arr[fIdx]<=arr[rIdx]){
            sortArr[sIdx] = arr[fIdx++];
        }
        else{
            sortArr[sIdx] = arr[rIdx++];
        }
        sIdx++;
    }
    //while을 빠져 나오면 잔여 배열을 몰아넣기
    if(fIdx > mid){
        for(i=rIdx; i<=right; i++){
            sortArr[sIdx++] = arr[i];
        }
    }
    else{
        for(i=fIdx; i<=mid; i++){
            sortArr[sIdx++] = arr[i];
        }
    }
    for(i=left; i<=right; i++){ //임시배열에 있던 것들 원래 배열에 넣기
        arr[i]= sortArr[i];
        printf("arr[%d]=%d\n", i,arr[i]);
    }
    free(sortArr); //free쳐서 메모리 할당 해제
}


void Divide(int arr[], int left, int right){ //나눠주는 함수
    printf("divide 1:r = %d:%d\n", left, right);

    int mid;

    if (left<right){
        mid = (left+right)/2;
        Divide(arr, left, mid); //재귀로 계속 부르기
        Divide(arr, mid+1, right);

        MergeTwoArea(arr, left, mid, right); //재귀 끝나면 머지시키기
    }
}



int main(void)
{
    int arr[7] = {7,6,5,4,3,2,1};
    int i;

    Divide(arr, 0, sizeof(arr)/sizeof(int)-1);

    for(i=0; i<7;i++){
        printf("%d", arr[i]);
    }

    return 0;
}