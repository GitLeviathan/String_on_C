#include "../s21_string.h"

void *s21_memchr(const void *str, int c, s21_size_t n) {
    const unsigned char *char_str = (const unsigned char *)str;
    unsigned char char_c = (unsigned char)c;
    unsigned char *result = s21_NULL;

    for (s21_size_t i = 0; i < n; i++) {
        if (char_str[i] == char_c) {
            result = (void *)(char_str + i);
            break;
        }
    }
    return result;
}