#include <stdio.h>

int GCD(int a, int b)
{
    return b==0 ? a : GCD(b, a%b);
}

int LCM(int a, int b)
{
    return (a / GCD(a, b)) * b;
}

int main()
{
    int a, b;

    scanf("%d%d", &a, &b);

    printf("%d %d\n", GCD(a, b), LCM(a, b));

    main();

    return 0;
}


