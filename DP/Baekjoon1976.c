//union find 응용
#include <stdio.h>


int prtarr[201] = {};

int find(int p){ //최상위 루트 찾기
    if (p == prtarr[p]){
        return p;
    }else{
        return prtarr[p] = find(prtarr[p]);
    }
}

void unionfunc(int p, int c){//union 연산: 바로 연결이 아닌 최종 parent 연결
   
    p = find(p);
    c = find(c);
    
    if(p!=c){ // 루트 노드가 다르다면
        prtarr[c]=p; 
    }
}

int main()
{
    int N, M;
    scanf("%d %d", &N, &M);
    
    int dosi[201][201];
    
    for (int i=1;i<=N;i++){
        for (int j=1;j<=N;j++){
            scanf("%d", &dosi[i][j]); //dosi 입력받기 
        }
    }

    int route[1001];
    
    for(int i=1;i<=M;i++){
        scanf("%d", &route[i]); //route 입력받기
    }
    
    for (int i=1;i<=N;i++){
        prtarr[i] = i; //prtarr에 i 넣기
    }
    
    for(int i=1; i<=N;i++){
        for(int j=1;j<=N;j++){
            if (dosi[i][j]==1){ //dosi의 i,j가 1이라면
                unionfunc(i,j); //unionfunc를 통해 i번째와 j번째 조상 잇기
            }
        }
    }
    int connect = 1; 
    
    int parent = find(route[1]); //route[1]의 조상 찾기
    
    for (int i=2; i<=M; i++){
        if (parent!=find(route[i])){ //route[i]를 찾아서 그게 parent가 아니라면
            connect = 0;//connect에 0 저장하고 NO 출력
            printf("NO\n");
            break;
        }
    }
    if (connect ==1){
        printf("YES\n");
    }
    
    return 0;
}
