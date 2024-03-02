#include <stdio.h>

int Fibo(int idx){
    if(idx<=2){ //idx가 2이하면 1 return
        return 1;
    }
    return Fibo(idx-1)+Fibo(idx-2); //idx가 2 초과라면 f(n)=f(n-1)+f(n-2)이용해 재귀 return
}

int main(void){
    int num = Fibo(6);
    printf("%d \n", num);
    return 0;
}

