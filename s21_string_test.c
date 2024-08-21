#include "s21_string_test.h"

#include <stdio.h>

#include "s21_string.h"

int main() {
#ifdef STRLEN
  char *string;
  s21_strlen_test(string, 0);
  string = "\n";
  s21_strlen_test(string, 1);
  string = "";
  s21_strlen_test(string, 0);
  string = "\0";
  s21_strlen_test(string, 0);
  printf("\n");
  string = "HELLO, WORLD!\n";
  s21_strlen_test(string, 14);
  string = "111111111111111111111111111111111 111111111111111111111111 1111111";
  s21_strlen_test(string, 66);
#endif

#ifdef STRCMP
  char *str1;
  char *str2;
  s21_strcmp_test(str1, str2, -2);
  printf("\n");
  str1 = "";
  str2 = "HELLO";
  s21_strcmp_test(str1, str2, -1);
  printf("\n");
  str1 = NULL;
  str2 = NULL;
  s21_strcmp_test(str1, str2, -2);
  printf("\n");
  str1 = "MY MAC";
  str2 = "MY CODE";
  s21_strcmp_test(str1, str2, 1);
  printf("\n");
  str1 = "\n";
  str2 = "MY CODE";
  s21_strcmp_test(str1, str2, -1);
  printf("\n");
  str1 = "0";
  str2 = "\0";
  s21_strcmp_test(str1, str2, 1);
  printf("\n");
  str1 = "123";
  str2 = "123";
  s21_strcmp_test(str1, str2, 0);
#endif

#ifdef STRCPY
  char *str1 = "School21";
  char str2[50] = "";
  s21_strcpy_test(str2, str1, "School21");
  str1 = "";
  s21_strcpy_test(str2, str1, "");
  printf("\n");
  str1 = NULL;
  s21_strcpy_test(str2, str1, "");
  printf("\n");
  str1 = "Hello, School21 YAR!!!";
  s21_strcpy_test(str2, str1, "Hello, School21 YAR!!!");
#endif

#ifdef STRCAT
  char *str1 = "School21";
  char str2[50] = "YAR";
  s21_strcat_test(str2, str1, "YARSchool21");
  printf("\n");
  str1 = "";
  s21_strcat_test(str2, str1, "YARSchool21");
  printf("\n");
  str1 = "\n";
  s21_strcat_test(str2, str1, "YARSchool21\n");
  printf("\n");
  str1 = "\0";
  s21_strcat_test(str2, str1, "YARSchool21\n");
#endif

#ifdef STRCHR
  char *str1 = "123456789";
  int ch = '6';
  s21_strchr_test(str1, ch, "6789");
  printf("\n");
  str1 = NULL;
  ch = ' ';
  s21_strchr_test(str1, ch, NULL);
  printf("\n");
  str1 = "HELLO";
  ch = '1';
  s21_strchr_test(str1, ch, NULL);
  printf("\n");
  str1 = "HELlO";
  ch = 'l';
  s21_strchr_test(str1, ch, "lO");
#endif

#ifdef STRSTR
  char *str1 = "123456789";
  char *substr = "456";
  s21_strstr_test(str1, substr, "456789");
  printf("\n");
  str1 = NULL;
  substr = " ";
  s21_strstr_test(str1, substr, NULL);
  printf("\n");
  str1 = "HELLO";
  substr = "1";
  s21_strstr_test(str1, substr, NULL);
  printf("\n");
  str1 = "HELlO";
  substr = "lO";
  s21_strstr_test(str1, substr, "lO");
#endif
  return 0;
}

#ifdef STRTOK
    char str1[] = "Hello, world! This is a test.";
    char *expected1[] = {"Hello", "world", "This", "is", "a", "test", NULL};
    s21_strtok_test(str1, " ,.!?", expected1, 6);

    char str2[] = ";;Hello;;world;;";
    char *expected2[] = {"Hello", "world", NULL};
    s21_strtok_test(str2, ";", expected2, 2);

    char str3[] = "NoDelimitersHere";
    char *expected3[] = {"NoDelimitersHere", NULL};
    s21_strtok_test(str3, " ", expected3, 1);

    char str4[] = "";
    char *expected4[] = {NULL};
    s21_strtok_test(str4, " ,.", expected4, 0);

    char str5[] = "One, two,,three, four,";
    char *expected5[] = {"One", "two", "three", "four", NULL};
    s21_strtok_test(str5, ", ", expected5, 4);
#endif

void s21_strlen_test(const char *str, int expected_len) {
  printf("%s\n", str);
  int len = s21_strlen(str);
  printf("%d\n", len);
  int result = len == expected_len ? 1 : 0;
  if (result)
    printf("SUCCESS");
  else
    printf("FAIL");
}

void s21_strcmp_test(const char *str1, const char *str2, int expected_result) {
  printf("str1 = %s, str2 = %s\n", str1, str2);
  int result = s21_strcmp(str1, str2);
  printf("%d\n", result);
  if (result == expected_result)
    printf("SUCCESS");
  else
    printf("FAIL");
}

void s21_strcpy_test(char *destination, const char *source,
                     char *expected_result) {
  printf("%s\n", source);
  char *str = s21_strcpy(destination, source);
  printf("%s\n", str);
  if (!s21_strcmp(expected_result, str))
    printf("SUCCESS");
  else
    printf("FAIL");
}

void s21_strcat_test(char *destination, const char *append,
                     char *expected_result) {
  printf("%s + %s\n", destination, append);
  char *result_cat = s21_strcat(destination, append);
  printf("%s\n", result_cat);
  if (!s21_strcmp(result_cat, expected_result))
    printf("SUCCESS");
  else
    printf("FAIL");
}

void s21_strchr_test(char *str, int ch, char *expected_result) {
  printf("%s symbol: %c\n", str, ch);
  char *result_chr = s21_strchr(str, ch);
  printf("%s\n", result_chr);
  if (!s21_strcmp(result_chr, expected_result) || result_chr == expected_result)
    printf("SUCCESS");
  else
    printf("FAIL");
}

void s21_strstr_test(const char *haystack, const char *needle, char *expected_result) {
  printf("Haystack: \"%s\", Needle: \"%s\"\n", haystack, needle);
  char* result_str = my_strstr(haystack, needle);
  printf("%s\n", result_str);
  if ((!result_str && !expected_result) || (result_str && expected_result && !s21_strcmp(result_str, expected_result)))
        printf("SUCCESS");
  else 
        printf("FAIL");
}

void s21_strtok_test(char *str, const char *delim, char *expected_tokens[], int expected_count) {
    printf("Testing string: \"%s\" with delimiters: \"%s\"\n", str, delim);
    char *token = my_strtok(str, delim);
    int token_index = 0;
    int success = 1;
    while (token != NULL) {
        printf("Token: \"%s\"\n", token);
        if (expected_tokens[token_index] == NULL || strcmp(token, expected_tokens[token_index]) != 0) {
            success = 0;
            break;
        }
        token = my_strtok(NULL, delim);
        token_index++;
    }
    if (token_index != expected_count || expected_tokens[token_index] != NULL) {
        success = 0;
    }
    if (success)
        printf("SUCCESS");
    else
        printf("FAIL");
}
