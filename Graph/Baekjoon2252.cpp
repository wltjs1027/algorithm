#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main()
{
    int N, M;
    cin >> N >> M;

    vector<vector<int>> A; // 연결리스트 이중 배열 (1:N)
    vector<int> indegree;  // 진입차수

    A.resize(N + 1);
    indegree.resize(N + 1);

    for (int i = 0; i < M; i++)
    {
        int S, E;
        cin >> S >> E;

        A[S].push_back(E); // 연결 리스트 구성

        indegree[E]++; // 진입차수 배열 데이터 저장하기
    }

    queue<int> queue;

    for (int i = 1; i <= N; i++)
    { // 처음껀 무조건 0이니까 1부터 보기
        if (indegree[i] == 0)
        {
            queue.push(i);
        }
    }
    while (!queue.empty())
    {

        int now = queue.front();
        queue.pop();
        cout << now << " ";

        for (int i = 0; i < A[now].size(); i++)
        {
            int next = A[now][i];
            indegree[next]--; // 진입차수 배열 1개 빼기

            if (indegree[next] == 0)
            { // 진입차수가 0이 되었으면 queue에 삽입
                queue.push(next);
            }
        }
    }

    return 0;
}
