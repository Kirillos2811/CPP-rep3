#include <stdio.h>
#include <string>

int main()
{   
    char str[100];
    int num;
    gets_s(str);
    printf("Enter the number of an element to delete: ");
    scanf_s("%i", &num);
    for (int i = num - 1; i < strlen(str); i++) {
        str[i] = str[i + 1];
    }
    printf("Output string:\n");
    puts(str);
}

