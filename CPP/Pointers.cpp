/*
 * You have to complete the function void update(int *a,int *b),
 * which reads two integers as argument,
 * and sets  with the sum of them,
 * and with the absolute difference of them.
*/

#include <stdio.h>
#include <math.h>

void update(int *a,int *b) {
    // Complete this function
    int temp = *a;
    *a += *b;
    *b = std::abs(temp - *b);
}

int main() {
    int a, b;
    int *pa = &a, *pb = &b;
    
    scanf("%d %d", &a, &b);
    update(pa, pb);
    printf("%d\n%d\n", a, b);

    return 0;
}