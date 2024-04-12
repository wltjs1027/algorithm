#include <stdio.h>


int max(int a, int b){
    if(a>=b){
        return a;
    }
    else{
        return b;
    }
}

int main()
{
    
    int n;
    scanf("%d", &n);
    
    int prc[1010]={}; //가격
    int DP[1010]={};
    
    int i, j;
    
    for(i=1;i<=n;i++){
        scanf("%d", &prc[i]);
    }
    for(i=1;i<=n;i++){ //총 카드의 장 수
        for(j=1;j<=i;j++){ //그 전에거 모두 비교하려고
            printf("i:j %d:%d\n", i, j);
            
            DP[i] = max(DP[i], DP[i-j]+prc[j]);
            printf("%d \n", DP[i]);
        }
    }
    printf("%d", DP[n]);

    return 0;
}
