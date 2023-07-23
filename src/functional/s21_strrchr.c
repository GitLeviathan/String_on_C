#include "../s21_string.h"

char *s21_strrchr(const char *str, int c) {
    char char_c = (char)c;
    char *result = s21_NULL;

    while (*str != '\0') {
        if (*str == char_c) {
            result = (char *)str; // Запоминаем последнее вхождение символа c
        }
        str++;
    }
    if (c == '\0') result = (char *)str;

    // Возвращаем указатель на последнее вхождение символа c
    return result;
}