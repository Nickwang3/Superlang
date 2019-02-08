#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#define ONE_MB (1 << 20)
#define BUFFER_SIZE ONE_MB

char source[BUFFER_SIZE]; //source code


// void get_token() {
    
// }

int is_letter(char c) {
    if ((c >= 'a' && c <= 'z') || (c >= 'A' || c <= 'Z')) {
        return 1;
    }
    return 0;
}

int is_number(char c) {
    return 0;
}

int is_valid_symbol(char c) {
    return 0;
}

int is_valid_char(char c) {
    if (is_letter(c) || is_number(c) || is_valid_symbol(c)) {
        return 1;
    }
    return 0;
}


void clear_string(char str[]) {
    for (int32_t i = 0; str[i]!=0; i++) {
        str[i] = 0;
    }
}

int get_string_size(char str[]) {

    int len = 0;

    for (int32_t i = 0; str[i]!=0; i++) {
        len++;
    }
    return len;
}


void read_file(const char file_name[]) {

    FILE * file;
    file = fopen(file_name, "r");

    if (file == NULL) {
        perror("Source file is null\n");
        exit(EXIT_FAILURE);
    }

    char c = 1;
    char current_word[50];
    uint8_t index = 0;

    while((c = fgetc(file)) && c != EOF) //reading from file
    {   
        // printf("%c", c);
        if (c == ' ') {

            int len = get_string_size(current_word);

            if (len!=0) {
                printf("%s", current_word);
                clear_string(current_word);
                index = 0;
                continue;
            }
            index = 0;
            printf("%d\n", len);
        }

        if (is_valid_char(c)) {           
            current_word[index] = c;
            index++;
        }
        
    }
    printf("\n");
}

int main(void) {

    read_file("superlang.txt");
    return 0;

}