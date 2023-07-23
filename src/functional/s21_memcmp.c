#include "../s21_string.h"

int s21_memcmp(const void *str1, const void *str2, s21_size_t n) {
    const unsigned char *char_str1 = (const unsigned char *)str1;
    const unsigned char *char_str2 = (const unsigned char *)str2;

    for (s21_size_t i = 0; i < n; i++) {
        if (char_str1[i] != char_str2[i]) {
            return char_str1[i] - char_str2[i];
        }
    }
    return 0;
}