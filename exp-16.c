#include <stdio.h>

int main() {
    int blockSize[10], processSize[10];
    int blocks, processes, allocation[10];

    printf("Enter number of blocks: ");
    scanf("%d", &blocks);

    printf("Enter size of each block:\n");
    for(int i = 0; i < blocks; i++)
        scanf("%d", &blockSize[i]);

    printf("Enter number of processes: ");
    scanf("%d", &processes);

    printf("Enter size of each process:\n");
    for(int i = 0; i < processes; i++) {
        scanf("%d", &processSize[i]);
        allocation[i] = -1;
    }

    for(int i = 0; i < processes; i++) {
        for(int j = 0; j < blocks; j++) {
            if(blockSize[j] >= processSize[i]) {
                allocation[i] = j;
                blockSize[j] -= processSize[i];
                break;
            }
        }
    }

    printf("\nProcess No\tProcess Size\tBlock No\n");
    for(int i = 0; i < processes; i++) {
        printf("%d\t\t%d\t\t", i+1, processSize[i]);
        if(allocation[i] != -1)
            printf("%d\n", allocation[i]+1);
        else
            printf("Not Allocated\n");
    }

    return 0;
}
