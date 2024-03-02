#include <stdio.h>

int num[100] = {};   //배열 생성

int Fibo(int idx){

    if(idx<=2){     //index가 2 이하일 때는 1 리턴
        return 1;
    }

    if(num[idx]==0){    //dynamic programming의 기초, 아직 저장된 값이 없다면
        num[idx] = Fibo(idx-1)+Fibo(idx-2); // 배열에 저장 후 리턴
        return num[idx];
    }
    else{   //배열에 0이 아닌 값이 저장되어 있다면 다시 계산할 필요 x
        return num[idx];    //바로 배열에 저장된 값 리턴
    }
}

int main(void){
    int num = Fibo(6);  //1,1,2,3,5,8,13...
    printf("%d \n", num);
    return 0;
}


