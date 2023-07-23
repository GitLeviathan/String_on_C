#include "../s21_string.h"

s21_size_t s21_strcspn(const char *str1, const char *str2) {
    s21_size_t count = 0;

    while (str1[count] != '\0') {
        s21_size_t index = 0;
        while (str2[index] != '\0') {
            if (str1[count] == str2[index]) {
                return count;
            }
            index++;
        }
        count++;
    }

    return count;
}