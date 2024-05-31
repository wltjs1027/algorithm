#include <stdio.h>
#include <stdlib.h>

int asc(const void* A, const void* B) {
	return (*(int*)A - *(int*)B);
}


int main()
{
    
    int N;

    scanf("%d", &N);
    
    int M;
    scanf("%d", &M);

    
    int arr[15001]={0};
    
    int i=0;
    
    for(i=0;i<N;i++){
        scanf("%d", &arr[i]);
    }
        
    qsort(arr, N, sizeof(int), asc); //sort

    int result = 0;
    
    int k = 0;
    
        
    int find = M;
    i=0;
    int j=N-1;
    
    while(i<j){ //투포인터 알고리즘 
        if(arr[i]+arr[j]==find){ 
            result++;
            i++;
            j--;
        }
        else if (arr[i]+arr[j]<find) {
            i++;
        }else{
            j--;
        }
    }
    
    printf("%d", result);
    
    return 0;
}
