#include <stdio.h>

int main(){
    
    int arr[101][10]={}; //앞은 1~100, 뒤는 숫자
    
    int n;
    scanf("%d", &n);
    
    int i, j;
    
    for (i=1;i<=9;i++){
        arr[1][i]=1;
    }
    
    for(i=2;i<=n;i++){
       arr[i][0]=arr[i-1][1];
       arr[i][9]=arr[i-1][8];
       
       for(j=1;j<9;j++){
           //11~18, 21~28 등은 각 1의 자리수의 앞수, 뒷수의 dp값을 더함
           //111~118, 211~218 등은 10의 자리수 부터 1/10의 자리수의 앞수, 뒤수의 dp값을 더함
            int prev = j-1;
            arr[i][j]+=arr[i-1][prev];//전 자릿수의 이전수
            int next = j+1;
            arr[i][j]+=arr[i-1][next];//전 자릿수의 이후수
            arr[i][j]%=1000000000;
       }
       
    }
    
    int res = 0;
    for(i=0;i<10;i++){
        res += arr[n][i];
        res %= 1000000000;
    }
    
    printf("%d\n", res);
    return 0;
}
