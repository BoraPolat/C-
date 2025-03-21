#include <stdio.h>

int main() {
    int temp, address, table[11], inc, value, done_or_not = 0, check = 0;
    
    FILE *fp;
    fp = fopen("D:/bora/t.txt", "r");
    
    // Initialize the table with -1 (indicating empty slots)
    for (int i = 0; i < 11; i++) table[i] = -1;
    
    while (fscanf(fp, "%d", &temp) != EOF) {
        done_or_not = 0;
        address = temp % 11; // Calculate the initial address using modulo 11
        value = temp / 11;    // Calculate the value to be used for increment
        inc = 0;              // Initialize the increment to 0
        
        // Progressive overflow handling
        while (done_or_not == 0) {
            // If the table is not full
            if (check < 11) {
                // If the address is empty, place the number
                if (table[(address + inc) % 11] == -1) {
                    table[(address + inc) % 11] = temp; // Insert the value
                    check++;                            // Increment the count of inserted values
                    done_or_not = 1;                   // Set flag to indicate insertion is done
                } else {
                    // If the address is occupied, increment `inc` to check the next address
                    inc += (value % 11); // Increment by the value to avoid clustering
                    if (inc >= 11) {
                        // If the increment goes beyond 11, the table is full
                        printf("Table is full, unable to insert %d\n", temp);
                        done_or_not = 1; // Exit the loop since no insertion is possible
                    }
                }
            } else {
                // If the table is full, print a message and exit
                printf("Table is full, unable to insert %d\n", temp);
                done_or_not = 1; // End the loop
            }
        }
    }

    fclose(fp); // Close the file
    
    // Print the final table content
    printf("LINEAR QUOTIENT OVERFLOW INDEX TABLE\n------------------------------------------------------------\n");
    for (int a = 0; a < 11; a++) {
        printf("%5d %5d\n", a, table[a]); // Print each address and the corresponding value
    }
    
    return 0; 
}
