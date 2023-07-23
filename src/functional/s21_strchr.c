#include "../s21_string.h"

char *s21_strchr(const char *str, int c) {
    char char_c = (char)c;
    char* result = s21_NULL; 
    while (*str != '\0') {
        if (*str == char_c) {
            result = (char *)str;
            break;
        }
        str++;
    }
    if (c == '\0') result = (char *)str;

    // Если символ c не найден, возвращаем NULL
    return result;
}