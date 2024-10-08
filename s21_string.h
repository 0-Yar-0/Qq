#ifndef SRC_S21_STRING_H_
#define SRC_S21_STRING_H_

int s21_strlen(const char *string);
int s21_strcmp(const char *str1, const char *str2);
char *s21_strcpy(char *destination, const char *source);
char *s21_strcat(char *destination, const char *append);
char *s21_strchr(char *str, int ch);
char *s21_strstr(const char *haystack, const char *needle);
char* s21_strtok(char* str, const char* delim);

#endif  // SRC_S21_STRING_H_
