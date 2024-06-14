#include <stdio.h>

int main()
{

    int N;
    scanf("%d", &N);
    char str[101] = {};
    scanf("%s", str);

    int num_arr[101] = {};
    int i = 0;
    for (i = 0; i < N; i++)
    {
        scanf("%d", &num_arr[i]);
    }

    double stack[101] = {0.0};
    int top = -1;
    int idx = 0;
    i = 0;

    while (str[idx] != 0)
    {
        char c = str[idx];
        if (c >= 'A' && c <= 'z')
        {
            stack[++top] = num_arr[c - 'A'];
        }
        else
        { // 연산자 일 때
            double d2 = stack[top--];
            double d1 = stack[top--];
            double res = 0.0;
            if (c == '+')
            {
                res = d1 + d2;
            }
            else if (c == '-')
            {
                res = d1 - d2;
            }
            else if (c == '*')
            {
                res = d1 * d2;
            }
            else
            {
                res = d1 / d2;
            }
            stack[++top] = res;
        }
        idx++;
    }
    printf("%.2lf", stack[0]);
}
