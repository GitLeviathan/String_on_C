#include "../s21_string.h"

char *s21_strerror(int errnum) {
    //static char buffer[256]; // Буфер для хранения строки с описанием ошибки

    switch (errnum) {
        case 0:
            return "Success";
        case 1:
            return "Operation not permitted";
        case 2:
            return "No such file or directory";
        case 3:
            return "No such process";
        // Добавьте другие ошибки по мере необходимости
        default:
            return "Unknown error with code";
            /*sprintf(buffer, "Unknown error with code %d", errnum);
            return buffer;*/
    }
}