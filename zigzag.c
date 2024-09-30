#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* convert(char* s, int numRows) {
    if (numRows == 1 || strlen(s) <= numRows) {
        return s;
    }

    char** rows = malloc(sizeof(char*) * numRows);
    for (int i = 0; i < numRows; i++) {
        rows[i] = malloc(sizeof(char) * (strlen(s) + 1));
        rows[i][0] = '\0';
    }

    int row = 0, goingDown = 1;
    for (int i = 0; i < strlen(s); i++) {
        int len = strlen(rows[row]);
        rows[row][len] = s[i];
        rows[row][len + 1] = '\0';

        if (row == 0) goingDown = 1;
        else if (row == numRows - 1) goingDown = -1;

        row += goingDown;
    }

    char* result = malloc(sizeof(char) * (strlen(s) + 1));
    result[0] = '\0';

    for (int i = 0; i < numRows; i++) {
        strcat(result, rows[i]);
    }

    for (int i = 0; i < numRows; i++) {
        free(rows[i]);
    }
    free(rows);

    return result;
}

int main() {
    char s[] = "PAYPALISHIRING";
    int numRows = 3;
    char* result = convert(s, numRows);
    printf("Converted string: %s\n", result);
    free(result);
    return 0;
}

