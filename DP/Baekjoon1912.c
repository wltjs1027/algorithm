#include <stdio.h>

int arr[100000]={};
int DP[100000]={};

int main()
{
    int n;
    scanf("%d", &n);
    
    int i;
    for(i=0;i<n;i++){
        scanf("%d", &arr[i]);
    }
    
    DP[0]=arr[0];
    
    int max=DP[0];
    
    for(i=1;i<n;i++){
        int cumsum = arr[i]+DP[i-1]; //이전 누적합과 현재 수를 더하고
        if(cumsum>arr[i]){ //그 수가 현재 수보다 크다면
            DP[i]=cumsum; //그 수를 넣기
        }
        else{
            DP[i]=arr[i]; //아니라면 그냥 현재 수만 저장
        }
        if(DP[i]>max){ //만약 dp[i]가 max보다 크다면 최댓값에 저장
            max=DP[i];
        }
    }
    
    printf("%d", max);
    return 0;
}
