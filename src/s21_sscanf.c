#include <stdarg.h>
#include <stdlib.h>
#include "s21_string.h"
#include <stdio.h>

int s21_sscanf(const char *str, const char *format, ...) {
  va_list arg;
  va_start(arg, format);
  int width, length;
  int count = 0;
  int sign = 1;
  int charge = 0;
  for (const char *j = format, *i = str; *j; j++) {
    if (*j == ' ') {
      continue;
    }
    if (*j == '%') {
      width = 0;
      length = 0;
      sign = 1;
      charge = 1;
    }
    if (*j == '*' && charge) {
      width = -1;
    }
    if (*j >= '1' && *j <= '9' && charge) {
      width = atoi(j);
      while (*j >= '0' && *j <= '9') {
        j++;
      }
    }
    if (*j == 'l' && charge) {
      length = 1;
    } else if (*j == 'h' && charge) {
      length = -1;
    } else if (*j == 'L' && charge) {
      length = 2;
    }
    if (*j == '%') {
      continue;
    } else if ((*j == 'c') && charge) {
      if (*i == ' ') {
        i++;
        j--;
        continue;
      }
      if (width != -1) {
        char *ch = va_arg(arg, char *);
        *ch = *i;
        i++;
      } else {
        { i++; }
      }
      charge = 0;
      count++;
      continue;
    } else if ((*j == 'd' || *j == 'i' || *j == 'u') && charge) {
      if (*i == ' ' || *i == '\n' || *i == '\t' || *i == '\r') {
        i++;
        j--;
        continue;
      }
      if (*i == '.') {
        i++;
      }
      if (*i == '-') {
        if (width && sign != -1) {
          width--;
        }
        sign = -1;
        i++;
        j--;
        continue;
      }
      if (width < 0) {
        while (*i >= '0' && *i <= '9') {
          i++;
        }
      } else {
        if (!length) {
          int *x = va_arg(arg, int *);
          if (*j == 'd' || *j == 'u') {
            *x = (int)s21_sscanf_d(&i, width) * sign;
          }
          if (*j == 'i') {
            *x = (int)s21_sscanf_o(&i, width, 0) * sign;
          }
        } else if (length == 1) {
          long int *x = va_arg(arg, long int *);
          if (*j == 'd' || *j == 'u') {
            *x = (long int)s21_sscanf_d(&i, width) * sign;
          }
          if (*j == 'i') {
            *x = (long int)s21_sscanf_o(&i, width, 0) * sign;
          }
        } else if (length == -1) {
          short int *x = va_arg(arg, short int *);
          if (*j == 'd' || *j == 'u') {
            *x = (short int)s21_sscanf_d(&i, width) * sign;
          }
          if (*j == 'i') {
            *x = (short int)s21_sscanf_o(&i, width, 0) * sign;
          }
        } else if (length == 2 && *j != 'u') {
          long long int *x = va_arg(arg, long long int *);
          *x = s21_sscanf_d(&i, width) * sign;
        }
      }
      charge = 0;
      count++;
      continue;
    } else if ((*j == 'E' || *j == 'e' || *j == 'f' || *j == 'g' ||
                *j == 'G') &&
               charge) {
      if (*i == ' ' || *i == '\n' || *i == '\t' || *i == '\r') {
        i++;
        j--;
        continue;
      }
      if (*i == '-') {
        if (width && sign != -1) {
          width--;
        }
        sign = -1;
        i++;
        j--;
        continue;
      }
      if (width < 0) {
        while ((*i >= '0' && *i <= '9') ||
               (*i == '.' || *i == 'E' || *i == 'e')) {
          i++;
        }
      } else {
        if (!length) {
          float *x = va_arg(arg, float *);
          *x = (float)s21_sscanf_ld(&i, width) * sign;
        } else if (length == 1) {
          double *x = va_arg(arg, double *);
          *x = (double)s21_sscanf_ld(&i, width) * sign;
        } else if (length == 2) {
          long double *x = va_arg(arg, long double *);
          *x = s21_sscanf_ld(&i, width) * sign;
        }
      }
      charge = 0;
      count++;
      continue;
    } else if (*j == 'o' && charge) {
      if (*i == ' ' || *i == '\n' || *i == '\t' || *i == '\r') {
        i++;
        j--;
        continue;
      }
      if (*i == '-') {
        if (width && sign != -1) {
          width--;
        }
        sign = -1;
        i++;
        j--;
        continue;
      }
      if (width < 0) {
        while (*i >= '0' && *i <= '9') {
          i++;
        }
      } else {
        if (!length) {
          int *x = va_arg(arg, int *);
          *x = (int)s21_sscanf_o(&i, width, 8) * sign;
        } else if (length == -1) {
          short int *x = va_arg(arg, short int *);
          *x = (short int)s21_sscanf_o(&i, width, 8) * sign;
        } else if (length == 1) {
          long int *x = va_arg(arg, long int *);
          *x = (long int)s21_sscanf_o(&i, width, 8) * sign;
        } else if (length == 2) {
          long long int *x = va_arg(arg, long long int *);
          *x = s21_sscanf_o(&i, width, 8) * sign;
        }
      }
      charge = 0;
      count++;
      continue;
    } else if (*j == 's' && charge) {
      if (*i == '\n' || *i == ' ' || *i == '\t' || *i == '\r') {
        i++;
        j--;
        continue;
      }
      if (width < 0) {
        while (1) {
          i++;
          if (*i == ' ' || *i == '\0' || *i == '\n') {
            break;
          }
        }
      } else {
        char *res = va_arg(arg, char *);
        s21_sscanf_s(&i, width, res);
      }
      charge = 0;
      count++;
      continue;
    } else if ((*j == 'p' || *j == 'x' || *j == 'X') && charge) {
      if (*i == '.') {
        i++;
      }
      if (*i == '\n' || *i == ' ' || *i == '\t' || *i == '\r') {
        i++;
        j--;
        continue;
      }
      if (*i == '-') {
        i++;
      }
      if (width < 0) {
        while ((*i >= '0' && *i <= '9') || (*i >= 'A' && *i >= 'F') ||
               *i == 'x') {
          i++;
        }
      } else {
        if (*j != 'p') {
          unsigned long *ul = va_arg(arg, unsigned long int *);
          *ul = (unsigned long)s21_sscanf_x(&i, width);
        }
        if (*j == 'p') {
          void **ul = va_arg(arg, void **);
          *ul = (void **)s21_sscanf_x(&i, width);
        }
      }
      charge = 0;
      count++;
      continue;
    } else if (*j == 'n' && charge) {
      if (*i == '\n' || *i == ' ' || *i == '\t' || *i == '\r') {
        i++;
        j--;
        continue;
      }
      if (width < 0) {
        charge = 0;
        continue;
      }
      int *number_n = va_arg(arg, int *);
      *number_n = s21_strlen(str) - s21_strlen(i);
      charge = 0;
      count++;
    } else if (!charge) {
      if (*i == ' ') {
        i++;
      }
      i++;
    }
  }
  va_end(arg);
  return count;
}

long long int s21_sscanf_d(const char **i, int width) {
  long long int res8 = 0;
  char *end;
  if (!width) {
    res8 = strtoll(*i, &end, 10);
    *i = (const char *)end;
  } else {
    char *tmp = (char *)calloc((width + 1), sizeof(char));
    s21_memcpy(tmp, *i, width);
    res8 = strtoll(tmp, _S21_NULL, 10);
    *i += width;
    free(tmp);
  }
  return res8;
}

long double s21_sscanf_ld(const char **i, int width) {
  long double res = 0;
  char *end;
  if (!width) {
    res = strtold(*i, &end);
    *i = (const char *)end;
  } else {
    char *tmp = (char *)calloc((width + 1), sizeof(char));
    s21_memcpy(tmp, *i, width);
    res = strtold(tmp, &end);
    *i += width;
    free(tmp);
  }
  return res;
}

long long int s21_sscanf_o(const char **i, int width, int type) {
  long long int res8 = 0;
  char *end;
  if (!width) {
    res8 = strtoll(*i, &end, type);
    *i = (const char *)end;
  } else {
    char *tmp = (char *)calloc((width + 1), sizeof(char));
    s21_memcpy(tmp, *i, width);
    res8 = strtoll(tmp, _S21_NULL, type);
    *i += width;
    free(tmp);
  }
  return res8;
}

void s21_sscanf_s(const char **i, int width, char *res) {
  int w = width;
  while (1) {
    if (width && w) {
      w--;
    } else if (width && !w) {
      break;
    }
    *res = **i;
    (*i)++;
    res++;
    if (**i == ' ' || **i == '\0' || **i == '\n') {
      break;
    }
  }
  *res = '\0';
}

long long int s21_sscanf_x(const char **i, int width) {
  long long int res = 0;
  char *end;
  if (!width) {
    res = strtoll(*i, &end, 16);
    *i = (const char *)end;
  } else {
    char *tmp = (char *)calloc((width + 1), sizeof(char));
    s21_memcpy(tmp, *i, width);
    res = strtoll(tmp, _S21_NULL, 16);
    *i += width;
    free(tmp);
  }
  return res;
}
