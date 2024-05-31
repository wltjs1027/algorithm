//union find
#include <stdio.h>

int prtarr[1000000] = {};

int find(int p){ //최상위 루트 찾기
    if (p==prtarr[p]){
        return p;
    }else{
        return prtarr[p] = find(prtarr[p]);
    }
}
void unionfunc(int p, int c){//union 연산: 바로 연결이 아닌 최종 parent 연결
    p = find(p);
    c = find(c);
    
    if(p!=c){
        prtarr[c]=p;
    }
}

int checkSame(int p, int c){//두 원소가 같은 집합인지 확인  
    p = find(p);
    c = find(c);
    if(p==c){
        return 1;
    }
    return 0;
}


int main()
{
    
    int n, m; //n:자료, m:case
    scanf("%d %d", &n, &m);
    
    int i=0;
    
    for(i=0;i<=n;i++){ //대표 노드를 자기 자신으로 초기화 하기 
        prtarr[i]=i;
    }
    
    for(i=0; i<m; i++){
        int op, p, c;
        scanf("%d %d %d", &op, &p, &c);
        
        if (op==0){//집합 합치기
            unionfunc(p,c); 
        }
        else{//같은 집합의 원소인지 확인하기 
            if (checkSame(p,c)){
                printf("YES\n");
            }
            else{
                printf("NO\n");
            }
        }
    }

    return 0;
}
