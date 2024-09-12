#include <stdio.h>

void copyString(char *source, char *destination, int index) {
    destination[index] = source[index];
    if (source[index] == '\0')
        return;
    copyString(source, destination, index + 1);
}

int main() {
    char source[100], destination[100];
    printf("Enter a string: ");
    scanf("%s", source);

    copyString(source, destination, 0);
    printf("Copied string: %s\n", destination);

    return 0;
}
