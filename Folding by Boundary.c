#include <stdio.h>

int main() {
    int i = 0, temp, array[9], array2[3], carry = 0, choice;
    FILE *fp;

    fp = fopen("D:/bora/t.txt", "r");
    if (fp == NULL) {
        printf("File could not be opened!\n");
        return 1;
    }

    while (fscanf(fp, "%1d", &temp) != EOF && i < 9) {
        array[i] = temp;
        i++;
    }
    fclose(fp);

    if (i < 9) {
        printf("Insufficient data!\n");
        return 1;
    }

    printf("Choose mode:\n1 - Without carry\n2 - With carry\n");
    scanf("%d", &choice);

    array2[2] = array[5] + array[0] + array[6];
    if (choice == 2) {
        carry = array2[2] / 10;
    }
    array2[2] %= 10;

    array2[1] = array[4] + array[1] + array[7] + carry;
    if (choice == 2) {
        carry = array2[1] / 10;
    }
    array2[1] %= 10;

    array2[0] = array[3] + array[2] + array[8] + carry;
    if (choice == 2) {
        carry = array2[0] / 10;
    }
    array2[0] %= 10;

    if (choice == 2 && carry) {
        printf("\nCarry: %d", carry);
    }

    printf("\nResult: ");
    for (int j = 0; j < 3; j++) {
        printf("%d", array2[j]);
    }

    return 0;
}
