#include <stdio.h>

int main() {
    int temp, address, table[11], inc, done_or_not, check = 0;
    FILE *fp;
    
    fp = fopen("D:/bora/t.txt", "r");
    if (fp == NULL) {
        printf("Error opening file!\n");
        return 1;
    }
    
    // Initialize the table with -1 (indicating empty slots)
    for (int i = 0; i < 11; i++) table[i] = -1;
    
    while (fscanf(fp, "%d", &temp) != EOF) {
        done_or_not = 0;
        address = temp % 11; // Calculate the initial address using modulo 11
        inc = 0;             // Start with no increment
        
        // Progressive overflow handling with step-by-step increments
        while (done_or_not == 0) {
            if (check < 11) { // Ensure table is not full
                if (table[(address + inc) % 11] == -1) { // Check if the slot is free
                    table[(address + inc) % 11] = temp; // Insert the value
                    check++; // Increment count of inserted values
                    done_or_not = 1; // Mark insertion as done
                } else {
                    inc++; // Move to the next slot (increment by 1)
                }
            } else {
                printf("Table is full, unable to insert %d\n", temp);
                done_or_not = 1;
            }
        }
    }
    
    fclose(fp); // Close the file
    
    // Print the final table content
    printf("PROGRESSIVE OVERFLOW INDEX TABLE\n");
    printf("------------------------------------------------------------\n");
    for (int a = 0; a < 11; a++) {
        printf("%5d %5d\n", a, table[a]); // Print each index and its stored value
    }
    
    return 0; 
}
