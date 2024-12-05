// C lang code to figure out identifier types
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int is_valid_identifier(char *str) {
    if (!isalpha(str[0]) && str[0] != '_') return 0;
    for (int i = 1; str[i] != '\0'; i++) {
        if (!isalnum(str[i]) && str[i] != '_' && str[i] != '(' && str[i] != ')' && str[i] != '[' && str[i] != ']')
            return 0;
    }
    return 1;
}

int get_identifier_type(char *str) {
    int len = strlen(str);
    if (str[len - 1] == ')') return 1; // Function
    if (strchr(str, '[') && str[len - 1] == ']') return 2; // Array
    return 3; // Variable
}

int main() {
    char input[100];
    printf("Enter the identifier: ");
    fgets(input, sizeof(input), stdin);
    input[strcspn(input, "\n")] = 0;

    if (!is_valid_identifier(input)) {
        printf("Invalid identifier.\n");
        return 0;
    }

    switch (get_identifier_type(input)) {
        case 1:
            printf("This is a function identifier.\n");
            break;
        case 2:
            printf("This is an array identifier.\n");
            break;
        case 3:
            printf("This is a variable identifier.\n");
            break;
        default:
            printf("Unknown identifier type.\n");
    }

    return 0;
}
