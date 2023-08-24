#include "../s21_string.h"

#include <stdarg.h>
#include <limits.h>

struct Arguments {
  short asterisk;  // either 0 or 1
  int width;       // -1 by default
  char modifier;   // '\0' by default
  int success;     // 0 by default
};

int case_d(va_list valist, const char *str, struct Arguments *Arglist);
int case_c(va_list valist, const char *str, struct Arguments *Arglist);
int case_s(va_list valist, const char *str, struct Arguments *Arglist);
int case_f(va_list valist, const char *str, struct Arguments *Arglist,
           int *total_count);
void case_f_write_to_destination(va_list valist, struct Arguments *Arglist,
                                 long double *result);
void case_d_write_to_destination(va_list valist, struct Arguments *Arglist,
                                 long int *result);
int case_e(const char *str, long double *result, int *symbols_counter,
           struct Arguments *Arglist);
int case_u(va_list valist, const char *str, struct Arguments *Arglist);
int case_o(va_list valist, const char *str, struct Arguments *Arglist);
int case_x(va_list valist, const char *str, struct Arguments *Arglist);
long case_x_read(const char *str, struct Arguments *Arglist,
                 int *symbols_counter);
int case_i(va_list valist, const char *str, struct Arguments *Arglist);
int case_p(va_list valist, const char *str, struct Arguments *Arglist);
