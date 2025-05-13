#include <stdio.h>
#include <stdlib.h>
#define lenght 12

int isSorted(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        if (arr[i] > arr[i + 1]) {
            return 0;
        }
    }
    return 1;
}

int main() {
    int temp, arr[lenght], i = 0, swap = 0, test = 0;

    FILE *fp;
    fp = fopen("D:/t_sorting.txt", "r");

    while (fscanf(fp, "%d", &temp) != EOF) {
        arr[i] = temp;
        i++;
    }
    fclose(fp);

    do {
        test = isSorted(arr, lenght);
        
            for (i = 0; i < lenght - 1; i++) {
                if (arr[i] > arr[i + 1]) {
                    arr[i] = arr[i] ^ arr[i + 1];
                    arr[i + 1] = arr[i] ^ arr[i + 1];
                    arr[i] = arr[i] ^ arr[i + 1];
                    
                    swap++;
                }
            }
        
    } while (test == 0);

    printf("-------------------------------------\n");

    for (i = 0; i < lenght; i++) {
        printf("%d\n", arr[i]);
    }
    printf("\nSwap = %d", swap);

    return 0;
}
