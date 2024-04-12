#include <stdio.h>

int DP[12];

int func (int n){
    
    DP[1]=1;
    DP[2]=2;
    DP[3]=4;
    
    if (n>3) {
        DP[n]=func(n-1)+func(n-2)+func(n-3);
    }
    
    return DP[n];
}

int main()
{
    int cnt;
    scanf("%d", &cnt);
    
    int i;
    
    for (i=0;i<cnt;i++){
        int n;
        scanf("%d", &n);
        printf("%d", func(n));
    }
    return 0;
}