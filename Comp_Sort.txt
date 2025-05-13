#include <stdio.h>
#define lenght 9

int isSorted(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        if (arr[i] > arr[i + 1]) {
            return 0;
        }
    }
    return 1;
}

int main() {
    int temp, arr[lenght], i = 0, swap = 0, test = 0, gap;
    float shrink = 1.3;

    FILE *fp;
    fp = fopen("D:/t_comp_sort.txt", "r");

    while (fscanf(fp, "%d", &temp) != EOF) {
        arr[i++] = temp;
    }
    fclose(fp);

    gap = lenght;
    do {
        test = isSorted(arr, lenght);

        while (gap > 1) {
            gap = (int)(gap / shrink);

            for (i = 0; i + gap < lenght; i++) {
                if (arr[i] > arr[i + gap]) {
                	for(int p=0;p<lenght;p++){
                    	printf("%3d", arr[p]);
               	
					}
                    arr[i] = arr[i] ^ arr[i + gap];
                    arr[i + gap] = arr[i] ^ arr[i + gap];
                    arr[i] = arr[i] ^ arr[i + gap];
                    swap++;
                    
					printf("\n\n");
                }
                
            }
        }
        
          
    } while (test == 0);
    
    for(int u=0;u<lenght;u++)
                printf("%3d",arr[u]);
                
    printf("\n\n\nLAST VALUES\n");
    for (i = 0; i < lenght; i++) {
        printf("%d\n", arr[i]);
    }
    printf("\nSwap = %d", swap);

    return 0;
}
