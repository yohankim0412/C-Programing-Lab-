#include <stdio.h>

int main() {
    int size;
    printf("Enter size: ");
    scanf("%d", &size);

    int i, j;

  
    for (i = 0; i < size; i++) {
        for (j = 0; j < i; j++) {
            printf(" ");
        }
        printf("*");
        for (j = 0; j < (size - i - 1) * 2 - 1; j++) {
            printf(" ");
        }
        if (i != size - 1) {
            printf("*");
        }
        printf("\n");
    }

   
    for (i = 0; i < size; i++) {  
        for (j = 0; j < size * 2; j++) {  
            printf("*");
        }
        printf("\n");
    }

    
    int triangle_base = size * 2;  
    int triangle_height = size;    

    for (int i = 0; i < triangle_height; i++) {
        
        for (int j = 0; j < i; j++) {
            printf(" ");
        }
        
        
        for (int j = 0; j < triangle_base - 2 * i; j++) {
            printf("*");
        }
        
        printf("\n");
    }

    
    for (i = 0; i < size * 2; i++) {
        printf("*");
    }
    printf("\n");

    return 0;
}