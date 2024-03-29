#include <stdio.h>

//Quick sort

void Swap(int *arr, int idx1, int idx2){
    printf("o:t=%d:%d\n", idx1, idx2);

    int temp = arr[idx1];
    arr[idx1] =arr[idx2];
    arr[idx2] = temp;

    int len = sizeof(arr)/sizeof(int);

    int i;

    for (i=0;i<8;i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int Partition(int arr[], int left, int right){
    printf("partition 1:r = %d:%d\n", left, right);

    int flagval = arr[left];
    printf("falgval: %d\n", flagval);
    int low = left+1;
    int high = right;

    while(low<=high){ //low가 high보다 작을 때까지 계속 반복
        while(flagval>arr[low]){ //flagval이 arr[row]보다 클 때까지 low 계속 증가
            low++;
        }
        while(flagval<arr[high]){//flagval이 arr[high]보다 작을 때까지 계속 high 감소
            high--;
        }
        if(low<=high){ //low가 high보다 작다면 swap하기
            Swap(arr, low, high);
        }
    }
    Swap(arr, left, high); //비교 위치가 교차했으면 기준값이랑 최솟값 바꾸기

    return high; //옮겨진 flag값 위치 정보

}


void QuickSort(int arr[], int left, int right){
    printf("\n\nQuickSort 1:r = %d:%d\n", left, right);

    if(left<=right){
        int flagind = Partition(arr, left, right); //기준값 위치 구하기

        QuickSort(arr, left, flagind-1); //왼쪽 영역 정렬
        QuickSort(arr, flagind+1, right); //오른쪽 영역 정렬
    }
}


int main(void)
{
    int arr[8]={20, 18, 50, 40, 9, 19, 5, 25};

    int len = sizeof(arr)/sizeof(int);

    QuickSort(arr,0,sizeof(arr)/sizeof(int)-1);

    int i;
    for(i=0; i<len; i++){
        printf("%d ", arr[i]);
    }
    return 0;
}