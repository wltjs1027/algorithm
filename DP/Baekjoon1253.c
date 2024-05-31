#include <stdio.h>
#include <stdlib.h>

int asc(const void* A, const void* B) {
	return (*(int*)A - *(int*)B);
}


int main()
{
    int N;

    scanf("%d", &N);
    
    int arr[2001]={0};
    
    int i=0;
    
    for(i=0;i<N;i++){
        scanf("%d", &arr[i]);
    }
        
    qsort(arr, N, sizeof(int), asc); //sort

    int result = 0;
    
    int k = 0;
    
    for(k=0;k<N;k++){
        
        int find = arr[k];
        int i=0;
        int j=N-1;
        
        while(i<j){ //투포인터 알고리즘 
            if(arr[i]+arr[j]==find){ 
                if(i!=k && j!=k){ //i랑 j가 같지 않다면 
                    result++;
                    break;
                }
                else if (i==k){ 
                    i++;
                }else if (j==k){ // 0 1 2 3 의 경우 j(3)==k(3)이니까 j를 줄여야돼 
                    j--;
                }
                
            }
            else if (arr[i]+arr[j]<find) {
                i++;
            }else{
                j--;
            }
        }
    }
    printf("%d", result);
    
    return 0;
}

