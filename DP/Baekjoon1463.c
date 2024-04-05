#include <stdio.h>

int min(int a, int b){
    if(a>b){
        return b;
    }
    return a;
}

int main()
{
    
    int n;
    scanf("%d", &n);
    
    int DP[1000001] ={};
    DP[1] = 0;
    DP[2] = 1;
    DP[3] = 1;
    
    for (int i=4; i<=n; i++){
        
        DP[i] = DP[i-1] +1;
        
        if(i%2==0){
            DP[i] = min(DP[i], DP[i/2]+1);
        }
        if(i%3==0){
            DP[i] = min(DP[i], DP[i/3]+1);
        }
        
    }
    printf("n:%d - DP[n]:%d", n, DP[n]);
    return 0;
}
