#include <stdio.h>

int max(int a, int b){
    if (a>b){
        return a;
    }
    else{
        return b;
    }
}

int main()
{
    int T;
    scanf("%d", &T);
    
    int arr[2][100010]={0};
    int DP[3][100010]={0};

    int k;
    
    for(k=0;k<T;k++){
        
        int n;
        scanf("%d", &n);
        
        int i, j;
        
        for (i=0;i<2;i++){
            for (j=1;j<=n;j++){
                scanf("%d", &arr[i][j]);
            }
        }
        
        for(i=1;i<=n;i++){
            //0: 위를 선택하고 싶은 경우
            //1: 아래를 선택하고 싶은 경우
            //2: 선택 안하는 경우
            DP[0][i]= max(DP[1][i-1], DP[2][i-1])+arr[0][i];
            DP[1][i]= max(DP[0][i-1], DP[2][i-1])+arr[1][i];
            DP[2][i]= max(DP[0][i-1], DP[1][i-1]) ;
            
            //printf("%d > %d : %d : %d \n", i , DP[0][i], DP[1][i], DP[2][i]);
        }
        printf("%d\n", max(DP[0][n], DP[1][n]));
  
    }
    
    return 0;
}




