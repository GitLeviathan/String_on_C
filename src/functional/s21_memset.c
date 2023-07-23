#include "../s21_string.h"

void *s21_memset(void *str, int c, s21_size_t n) {
    unsigned char *char_str = (unsigned char *)str;
    unsigned char char_c = (unsigned char)c;
    for (s21_size_t i = 0; i < n; i++) {
        char_str[i] = char_c;
    }
    return str;
}