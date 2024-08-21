#include <stdio.h>
#include <stdlib.h>

#define MAX_INPUT_LENGTH 100

int split_word(char *word, int width, int *chars_written);

int main(int argc, char *argv[]) {
    if (argc != 2 || argv[1][0] != '-' || argv[1][1] != 'w' || argv[1][2] != '\0') {
        printf("n/a");
        return 0;
    }

    int width;
    if (scanf("%d\n", &width) != 1) {
        printf("n/a");
        return 0;
    }

    char text[MAX_INPUT_LENGTH + 1];
    fgets(text, MAX_INPUT_LENGTH + 1, stdin);

    int i = 0, start = 0, line_length = 0;
    while (text[i] != '\0' && text[i] != '\n') {
        if (line_length == width) {
            while (line_length > 0 && text[start + line_length - 1] == ' ') line_length--;
            printf("\n");
            line_length = 0;
        }

        char word[MAX_INPUT_LENGTH + 1];
        int word_length = 0;

        while (text[i] != ' ' && text[i] != '\0' && text[i] != '\n') {
            word[word_length] = text[i];
            word_length++;
            i++;
        }
        word[word_length] = '\0';

        if (line_length == 0) {
            if (word_length > width) {
                line_length = split_word(word, width, &start);
            } else {
                printf("%s", word);
                line_length = word_length;
            }
        } else {
            if (line_length + 1 + word_length <= width) {
                printf(" %s", word);
                line_length += 1 + word_length;
            } else {
                printf("\n");
                if (word_length > width) {
                    line_length = split_word(word, width, &start);
                } else {
                    printf("%s", word);
                    line_length = word_length;
                }
            }
        }

        while (text[i] == ' ') {
            i++;
        }
    }

    return 0;
}

int split_word(char *word, int width, int *chars_written) {
    int len = 0, print_len = 0, remainder = 0;
    while (word[len] != '\0') len++;

    if (len <= width) {
        printf("%s", word);
        *chars_written = len;
    } else {
        for (int i = 0; i < width - 1; i++) {
            printf("%c", word[i]);
            print_len++;
        }
        printf("-");
        printf("\n");

        for (int i = width - 1; i < len; i++) {
            printf("%c", word[i]);
            remainder++;
        }
        *chars_written = remainder;
    }
    return remainder;
}
