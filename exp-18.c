#include <stdio.h>
#include <stdlib.h>

int main() {
    int rq[20], n, head, size, move, total = 0;

    printf("Enter number of requests: ");
    scanf("%d", &n);

    printf("Enter request sequence:\n");
    for(int i = 0; i < n; i++)
        scanf("%d", &rq[i]);

    printf("Enter initial head position: ");
    scanf("%d", &head);

    printf("Enter disk size: ");
    scanf("%d", &size);

    printf("Enter direction (0 = left, 1 = right): ");
    scanf("%d", &move);

    rq[n] = head;
    n++;

    // Sort
    for(int i = 0; i < n; i++)
        for(int j = i+1; j < n; j++)
            if(rq[i] > rq[j]) {
                int temp = rq[i];
                rq[i] = rq[j];
                rq[j] = temp;
            }

    int pos;
    for(int i = 0; i < n; i++)
        if(rq[i] == head)
            pos = i;

    if(move == 1) {
        for(int i = pos; i < n-1; i++)
            total += abs(rq[i+1] - rq[i]);
        total += abs((size - 1) - rq[n-1]);
        for(int i = pos-1; i >= 0; i--)
            total += abs(rq[i+1] - rq[i]);
    } else {
        for(int i = pos; i > 0; i--)
            total += abs(rq[i] - rq[i-1]);
        total += abs(rq[0] - 0);
        for(int i = pos+1; i < n; i++)
            total += abs(rq[i] - rq[i-1]);
    }

    printf("Total head movement = %d\n", total);
    return 0;
}
