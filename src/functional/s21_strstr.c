#include "../s21_string.h"

char *s21_strstr(const char *haystack, const char *needle) {
    if (*needle == '\0') {
        return (char *)haystack; // needle является пустой строкой, haystack является подстрокой needle
    }
    while (*haystack != '\0') {
        const char *temp_haystack = haystack;
        const char *temp_needle = needle;

        while (*temp_needle != '\0' && *temp_haystack == *temp_needle) {
            temp_haystack++;
            temp_needle++;
        }

        if (*temp_needle == '\0') {
            return (char *)haystack; // первое вхождение needle найдено
        }

        haystack++;
    }
    return s21_NULL; // needle не найден в haystack
}