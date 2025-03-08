#include <stdio.h>

int main() {
    int person[4][3] = {0}; 
    int sum[3] = {0}; 
    float ratio[3]; 
    int i, j;

    printf("Check room (Men)\n");
    for (i = 0; i < 2; i++) { 
        for (j = 0; j < 3; j++) {
            printf("Room #%d%d%d > ", i + 1, 0, j + 1);
            scanf("%d", &person[i][j]);
            sum[0] += person[i][j]; 
        }
    }

    printf("\nCheck room (Women)\n");
    for (i = 2; i < 4; i++) { 
        for (j = 0; j < 3; j++) {
            printf("Room #%d%d%d > ", i + 1, 0, j + 1);
            scanf("%d", &person[i][j]);
            sum[1] += person[i][j]; 
        }
    }

    sum[2] = sum[0] + sum[1]; 

    ratio[0] = (sum[0] / 24.0) * 100; 
    ratio[1] = (sum[1] / 24.0) * 100; 
    ratio[2] = (sum[2] / 48.0) * 100; 

    printf("\nCheck Result !\n");
    printf("Men: %d/24 (%.1f%%)\n", sum[0], ratio[0]);
    printf("Women: %d/24 (%.1f%%)\n", sum[1], ratio[1]);
    printf("Total: %d/48 (%.1f%%)\n", sum[2], ratio[2]);

    return 0;
}
