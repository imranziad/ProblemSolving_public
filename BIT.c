#include <stdio.h>

int tree[100]={0};

int query(int idx)
{
    int sum = 0;
    while(idx>0)
    {
        sum += tree[idx];
        idx -= idx & (-idx);
    }
    return sum;
}
void update(int idx, int x, int n)
{
    while(idx<=n)
    {
        tree[idx] += x;
        idx += idx & (-idx);
    }
}

int main()
{
    int n, i, t, x;

    scanf("%d", &n);

    for(i=1; i<=n; i++) // Has to start from index 1
    {
        scanf("%d", &x);
        update(i, x, n); // Adds value to the index, does not replace
    }

    while( (scanf("%d", &t)) )
        printf("%d\n", query(t));

    return 0;
}
