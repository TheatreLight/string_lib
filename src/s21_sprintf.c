#include <stdarg.h>
#include <stdio.h>

#include "s21_string.h"

int s21_sprintf(char* str, const char* format, ...) {
  int chars_count = 0, width, precision, flag, sign, zero, space, sharp, length;
  va_list arg;
  va_start(arg, format);
  for (const char* j = format; *j; j++) {
    if (*j == '%') {
      j++;
      width = 0;
      flag = 0;
      sign = 0;
      zero = 0;
      space = 0;
      sharp = 0;
      length = 0;
      precision = -1;
      while (!s21_strchr("cdieEfgGosuxXpn", *j)) {
        if (*j == '%') {
          chars_count++;
          *str = *j;
          str++;
          j++;
        }
        if (*j == '-') {
          j++;
          flag = 1;
        }
        if (*j == '+') {
          j++;
          sign = 1;
        }
        if (*j == ' ') {
          j++;
          space = 1;
        }
        if (*j == '#') {
          j++;
          sharp = 1;
        }
        while (*j == '0') {
          j++;
          zero = 1;
        }
        if (*j == '*') {
          width = va_arg(arg, int);
          j++;
        } else {
          while (*j >= '0' && *j <= '9') {
            width *= 10;
            width += *j - '0';
            j++;
          }
        }
        if (*j == '.') {
          precision = 0;
          j++;
          if (*j == '*') {
            precision = va_arg(arg, int);
            j++;
          } else {
            while (*j >= '0' && *j <= '9') {
              precision *= 10;
              precision += *j - '0';
              j++;
            }
          }
        }
        if (*j == 'h') {
          length = *j;
          j++;
        } else if (*j == 'l') {
          length = *j;
          j++;
        } else if (*j == 'L') {
          length = *j;
          j++;
        }
      }
      switch (*j) {
        case 'c': {
          char c[2];
          c[0] = (char)va_arg(arg, int);
          c[1] = '\0';
          chars_count += s21_sprintf_s(&str, c, width, precision, flag, zero);
          break;
        }
        case 'i':
        case 'd':
          chars_count +=
              s21_sprintf_d(&str, va_arg(arg, long long int), 10, width,
                            precision, flag, sign, zero, space, length);
          break;
        case 'e': {
          if (length == 'L') {
            chars_count +=
                s21_sprintf_e(&str, va_arg(arg, long double), width, precision,
                              0, flag, sign, zero, space, sharp, 'e');
          } else {
            chars_count +=
                s21_sprintf_e(&str, va_arg(arg, double), width, precision, 0,
                              flag, sign, zero, space, sharp, 'e');
          }
          break;
        }
        case 'E': {
          if (length == 'L') {
            chars_count +=
                s21_sprintf_e(&str, va_arg(arg, long double), width, precision,
                              0, flag, sign, zero, space, sharp, 'E');
          } else {
            chars_count +=
                s21_sprintf_e(&str, va_arg(arg, double), width, precision, 0,
                              flag, sign, zero, space, sharp, 'E');
          }
          break;
        }
        case 'f': {
          if (length == 'L') {
            chars_count +=
                s21_sprintf_f(&str, va_arg(arg, long double), width, precision,
                              0, flag, sign, zero, space, sharp);
          } else {
            chars_count +=
                s21_sprintf_f(&str, va_arg(arg, double), width, precision, 0,
                              flag, sign, zero, space, sharp);
          }
          break;
        }
        case 'g':
          chars_count +=
              s21_sprintf_g(&str, va_arg(arg, double), width, precision, flag,
                            sign, zero, space, sharp, 'e');
          break;
        case 'G':
          chars_count +=
              s21_sprintf_g(&str, va_arg(arg, double), width, precision, flag,
                            sign, zero, space, sharp, 'E');
          break;
        case 'o':
          chars_count +=
              s21_sprintf_u(&str, va_arg(arg, unsigned long long int), 8, width,
                            precision, flag, zero, sharp, 'a', length);
          break;
        case 's': {
          char* string = va_arg(arg, char*);
          chars_count +=
              s21_sprintf_s(&str, string, width, precision, flag, zero);
          break;
        }
        case 'u':
          chars_count +=
              s21_sprintf_u(&str, va_arg(arg, unsigned long long int), 10,
                            width, precision, 0, zero, space, 'a', length);
          break;
        case 'x':
          chars_count +=
              s21_sprintf_u(&str, va_arg(arg, unsigned long long int), 16,
                            width, precision, flag, zero, sharp, 'a', length);
          break;
        case 'X':
          chars_count +=
              s21_sprintf_u(&str, va_arg(arg, unsigned long long int), 16,
                            width, precision, flag, zero, sharp, 'A', length);
          break;
        case 'p':
          chars_count +=
              s21_sprintf_u(&str, va_arg(arg, unsigned long long int), 16,
                            width, precision, flag, zero, -1, 'a', 'l');
          break;
        case 'n':
          *va_arg(arg, int*) = chars_count;
          break;
      }
    } else {
      *str = *j;
      str++;
      chars_count++;
    }
    if (!*j) break;
  }
  *str = '\0';
  va_end(arg);
  return chars_count;
}

int s21_sprintf_s(char** str, const char* string, int width, int precision,
                  int flag, int zero) {
  int chars_count = 0, flag_char = ' ';
  if (zero) {
    flag_char = '0';
  }
  if (precision != 0) {
    if (precision == -1) {
      precision = 0;
      for (const char* p = string; *p; p++) precision++;
    }
    if (width > 0) {
      width -= precision;
    }
    if (width > 0) precision += width;
    if (!flag) {
      for (; width > 0; width--) {
        **str = flag_char;
        chars_count++;
        (*str)++;
      }
    }
    for (; *string; string++) {
      **str = *string;
      chars_count++;
      (*str)++;
    }
    for (; width > 0; width--) {
      **str = flag_char;
      chars_count++;
      (*str)++;
    }
    if (precision < chars_count) {
      *str = *str - (chars_count - precision);
    }
  }
  return chars_count;
}

int s21_sprintf_d(char** str, long long int i, int base, int width,
                  int precision, int flag, int sign, int zero, int space,
                  int length) {
  char buf[INT_BUFER_LEN];
  char* s = buf + INT_BUFER_LEN - 1;
  int char_count, num_count;
  if (length == 'h') {
    i = (short int)i;
  } else if (length == 0) {
    i = (int)i;
  }
  char_count = 0;
  if (i < 0) {
    sign = '-';
    i = -i;
  } else if (sign) {
    sign = '+';
  } else if (space) {
    sign = ' ';
  }
  *s = '\0';
  num_count = 0;
  if (i == 0) {
    s--;
    *s = '0';
    num_count++;
  }
  while (i) {
    long long int temp = 0;
    s--;
    num_count++;
    if (base) temp = i % base;
    temp = (temp < 0) ? -temp : temp;
    *s = temp + '0';
    if (base) i /= base;
  }
  if (precision == -2) {
    precision += num_count;
    while (precision < 0) {
      s--;
      *s = '0';
      precision++;
    }
    if (sign) {
      s--;
      *s = sign;
    }
  } else {
    if (sign) {
      s--;
      *s = sign;
    }
    if (precision > 0) {
      precision -= num_count;
      while (precision > 0) {
        s--;
        *s = '0';
        precision--;
      }
    }
  }
  if (width < 0) width = 0;
  return char_count + s21_sprintf_s(str, s, width, -1, flag, zero);
}

int s21_sprintf_e(char** str, long double e, int width, int precision, int g,
                  int flag, int sign, int zero, int space, int sharp,
                  int char_case) {
  char buf[DBL_BUFER_LEN], *s;
  int char_count;
  char_count = 0;
  if (precision == -1) precision = 6;
  if (e < 0) {
    char_count += s21_sprintf_s(str, "-", 0, -1, 0, 0);
    e = -e;
  } else if (sign) {
    char_count += s21_sprintf_s(str, "+", 0, -1, 0, 0);
  } else if (space) {
    char_count += s21_sprintf_s(str, " ", 0, -1, 0, 0);
  }
  int power = get_power(e, precision);
  if (power > 0) {
    for (int i = power; i > 0; i--) e /= 10;
  } else {
    for (int i = power; i; i++) e *= 10;
  }
  long double frac = e - (int)e;
  s = buf;
  s21_sprintf_d(&s, (long long int)e, 10, 0, -1, 0, 0, 0, 0, 0);
  if (precision > 0) {
    s21_sprintf_s(&s, ".", 0, -1, 0, 0);
    sharp = 0;
  }
  if (precision) {
    for (int i = precision; i > 0; i--) frac = frac * 10;
    s21_sprintf_d(&s, (int)(frac), 10, 0, precision, 0, 0, 0, 0, 0);
    *s = '\0';
    if (g) {
      do {
        *s = 0;
        s--;
      } while (*s == '0');
    }
  }
  frac = (frac - (int)frac) * 10;
  if ((int)frac > 4) {
    raund(buf);
  }
  if (sharp) {
    *s = '.';
    s++;
  }
  *s = char_case;
  s++;
  s21_sprintf_d(&s, power, 10, 0, -2, 0, 1, 0, 0, 0);

  *s = 0;
  char_count += s21_sprintf_s(str, buf, width - char_count, -1, flag, zero);
  return char_count;
}

void raund(char* str) {
  char* p = str + s21_strlen(str) - 1;
  *p = *p + 1;
  while (*p > '9') {
    *p = '0';
    p--;
    *p = *p + 1;
  }
}

int get_power(long double d, int precision) {
  int power = 0;
  if (d < 0) d = -d;
  double calc_error = 1.0;
  for (int i = precision; i > 0; i--) calc_error /= 10;
  if (d > calc_error) {
    for (long double i = d; i > 10; i /= 10) {
      power++;
    }
  } else {
    for (; (d < 10); d *= 10) {
      power--;
    }
    power++;
  }
  return power;
}

int s21_sprintf_g(char** str, long double g, int width, int precision, int flag,
                  int sign, int zero, int space, int sharp, int char_case) {
  int char_count = 0;
  int power = get_power(g, precision);
  if (precision == -1) precision = 6;
  if (precision > power && power >= -4) {
    char_count += s21_sprintf_f(str, g, width, precision - power - 1, 1, flag,
                                sign, zero, space, sharp);
  } else {
    char_count += s21_sprintf_e(str, g, width, precision, 1, flag, sign, zero,
                                space, sharp, char_case);
  }
  return char_count;
}

int s21_sprintf_f(char** str, long double d, int width, int precision, int g,
                  int flag, int sign, int zero, int space, int sharp) {
  char buf[DBL_BUFER_LEN], *s;
  int char_count;
  long double frac = d - (int)d;
  char_count = 0;
  if (precision == -1) precision = 6;
  if (d < 0) {
    char_count += s21_sprintf_s(str, "-", 0, -1, 0, 0);
    d = -d;
    frac = -frac;
  } else if (sign) {
    char_count += s21_sprintf_s(str, "+", 0, -1, 0, 0);
  } else if (space) {
    char_count += s21_sprintf_s(str, " ", 0, -1, 0, 0);
  }
  s = buf;
  char_count += s21_sprintf_d(&s, (long long int)d, 10, 0, -1, 0, 0, 0, 0, 'l');
  if (precision > 0) {
    char_count += s21_sprintf_s(&s, ".", 0, -1, 0, 0);
    sharp = 0;
  }
  for (int i = precision; i > 0; i--) frac = frac * 10;
  if (precision) {
    char_count +=
        s21_sprintf_d(&s, (int)(frac), 10, 0, precision, 0, 0, 0, 0, 0);
    if (g) {
      do {
        *s = 0;
        s--;
      } while (*s == '0');
    }
  }
  frac = (frac - (int)frac) * 10;
  if (sharp) {
    *s = '.';
    s++;
  }
  *s = '\0';
  if ((int)frac > 5) {
    raund(buf);
  }
  return char_count + s21_sprintf_s(str, buf, width, -1, flag, zero);
}

int s21_sprintf_u(char** str, unsigned long long int u, int base, int width,
                  int precision, int flag, int zero, int sharp, int char_case,
                  int length) {
  char buf[INT_BUFER_LEN];
  char* s = buf + INT_BUFER_LEN - 1;
  int char_count, num_count;

  if (length == 'h') {
    u = (unsigned short int)u;
  } else if (length == 0) {
    u = (unsigned int)u;
  }

  char_count = 0;
  *s = '\0';
  num_count = 0;
  if (u == 0) {
    s--;
    *s = '0';
    num_count++;
  }
  while (u) {
    int temp = 0;
    s--;
    num_count++;
    if (base) temp = u % base;
    if (temp >= 10) temp += char_case - '0' - 10;
    *s = temp + '0';
    if (base) u /= base;
  }
  if (precision > 0) {
    precision -= num_count;
    while (precision > 0) {
      s--;
      *s = '0';
      precision--;
    }
  }
  if (width < 0) width = 0;
  if (sharp == 1) {
    if (base == 8) {
      s--;
      *s = '0';
    } else if (base == 16) {
      s--;
      *s = char_case + 23;
      s--;
      *s = '0';
    }
    char_count += s21_sprintf_s(str, s, width, -1, flag, zero);
  } else if (sharp == -1) {
    if (zero) {
      width = width - num_count - 2;
      while (width) {
        s--;
        *s = '0';
        width--;
      }
    }
    s--;
    *s = 'x';
    s--;
    *s = '0';
    char_count += s21_sprintf_s(str, s, width, -1, flag, zero);
  } else {
    char_count += s21_sprintf_s(str, s, width, -1, flag, zero);
  }
  return char_count;
}
