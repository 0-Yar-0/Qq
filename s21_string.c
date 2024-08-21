#include "s21_string.h"

#include <stdio.h>

int s21_strlen(const char *str) {
  int len = 0;
  if (str == NULL) {
    len = -1;
  } else {
    for (; *(str + len); len++) {
    }
  }
  return len;
}

int s21_strcmp(const char *str1, const char *str2) {
  int rtn = -2;
  if (str1 != NULL && str2 != NULL) {
    for (; *str1 && *str1 == *str2; str1++, str2++) {
    }
    int result = *str1 - *str2;
    if (result > 0)
      rtn = 1;
    else if (result < 0)
      rtn = -1;
    else
      rtn = 0;
  }
  return rtn;
}

char *s21_strcpy(char *destination, const char *source) {
  if (source != NULL) {
    for (int i = 0; (destination[i] = source[i]) != '\0'; i++) {
    }
  }
  return destination;
}

char *s21_strcat(char *destination, const char *append) {
  int len = 0;
  for (; destination[len] != '\0'; len++) {
  }
  for (; *append; append++, len++) {
    destination[len] = *append;
  }
  return destination;
}

char *s21_strchr(char *str, int ch) {
  char *rtn = NULL;
  if (str != NULL) {
    for (; *str && *str != ch; str++) {
    }
    if (*str != '\0') rtn = str;
  }
  return rtn;
}

char *s21_strstr(const char *haystack, const char *needle){
  if (!*needle) {
        return (char*)haystack;  
    }
    while (*haystack) {
        const char* h = haystack;
        const char* n = needle;
        while (*h && *n && (*h == *n)) {
            h++;
            n++;
        }
        if (!*n) {
            return (char*)haystack;
        }
        haystack++;
    }
    return NULL; 
}

char* s21_strtok(char* str, const char* delim) {
    static char* next_token = NULL; 
    if (str != NULL) {
        next_token = str; 
    }
    if (next_token == NULL) {
        return NULL; 
    }
    char* token_start = next_token;
    while (*token_start != '\0') {
        const char* d = delim;
        while (*d != '\0') {
            if (*token_start == *d) {
                token_start++;
                break;
            }
            d++;
        }
        if (*d == '\0') {
            break; 
        }
    }
    if (*token_start == '\0') {
        next_token = NULL;
        return NULL;
    }
    char* token_end = token_start;
    while (*token_end != '\0') {
        const char* d = delim;
        while (*d != '\0') {
            if (*token_end == *d) {
                *token_end = '\0'; 
                next_token = token_end + 1; 
                return token_start; 
            }
            d++;
        }
        token_end++;
    }
    next_token = NULL;
    return token_start; 
}