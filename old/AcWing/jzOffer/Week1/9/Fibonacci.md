## 21. 斐波那契数列
[这里](https://www.acwing.com/problem/content/19/)
输入一个整数n,求斐波那契数列的第n项。

**Note:** n从0开始,n=0时返回0。(n<=39) <br />

**Example :**
```
Input:n=5
Output:5
```
## hints
```
    fomular : F[n]=F[n-1]+F[n-2](n>=3,F[1]=1,F[2]=1)
```
## Solution
``` c
int Fibonacci(int n){
    if(n == 0) return 0;
    else if(n==1 || n == 2) return 1;
    else {
        return Fibonacci(n-1) + Fibonacci(n-2);
    }
}
```
## hints2
```
    1.不需要递归.直接迭代
```
## Solution2
```
int Fibonacci(int n){
    if(n == 0) return 0;
    int a = 0; int b = 1;
    while(n>0){
        int c = a + b;
        a = b;
        b = c;
        n--;
    }
    return a;
}
```