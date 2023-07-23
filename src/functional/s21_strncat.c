#include "../s21_string.h"

char *s21_strncat(char *dest, const char *src, s21_size_t n) {
    char *dest_end = dest; 
    // Находим конец строки dest
    while (*dest_end != '\0') {
        dest_end++;
    }
    // Копируем n символов из src в конец строки dest
    while (n > 0 && *src != '\0') {
        *dest_end = *src;
        dest_end++;
        src++;
        n--;
    }
    // Убеждаемся, что строка dest заканчивается нулевым символом
    *dest_end = '\0';
    return dest;
}
