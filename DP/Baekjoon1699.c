#include <stdio.h>

int DP[1000001];

int min(int a, int b){
    if(a>b){
        return b;
    }
    else{
        return a;
    }
}

int main(void)
{
    int N;
    scanf("%d", &N); //수 받아오기
    
    int i, j;
    for(i=1; i<=N; i++){ //DP를 위해 다 돌리기
        DP[i]=i; //일단 i넣어놓기 왜냐면 최대 i니까 ex)DP[5]=1+1+1+1+1
        
        for(j=1; j*j<=i;j++){ //j*j가 i보다 작거나 같을 때까지 ex)4=2^2, 5=2^2+1 이런식
            DP[i]=min(DP[i], DP[i-j*j]+1); //j*j보다 작은거랑 크기 비교해서 min 계산
        }
    }
    printf("%d", DP[N]);

}

