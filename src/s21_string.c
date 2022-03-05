#include <stdio.h>
#include <stdlib.h>
#include "s21_string.h"
#include <stdarg.h>

void *s21_memchr(const void *str, int c, s21_size_t n) {
    const unsigned char *ch = str;
    const unsigned char *x = NULL;
    for (s21_size_t i = 0; i < n; i++) {
        if (ch[i] == c) {
            x = &ch[i];
            i = n;
        }
    }
    return (void*)x;
}

int s21_memcmp(const void *str1, const void *str2, s21_size_t n) {
  const unsigned char *p1, *p2;
  int res = 0;
  for (p1 = str1, p2 = str2; 0 < n;) {
    res = *p1 - *p2;
    p1 += 1;
    p2 += 1;
    if (res != 0) break;
    n -= 1;
  }
  return res;
}

void *s21_memcpy(void *dest, const void *src, s21_size_t n) {
    char *tmp = dest;
    const char *p = src;
    while (n--) {
        *tmp = *p;
        tmp++;
        p++;
    }
    return dest;
}

void *s21_memmove(void *dest, const void *src, s21_size_t n) {
    char *source = (char*)src;
    char *destination = dest;
    char *new_src = source + (n - 1);
    char *new_dest = destination + (n - 1);
    if (destination > source) {
        while (n--) {
            *new_dest = *new_src;
            new_dest--;
            new_src--;
        }
    } else {
        while (n--) {
            *destination = *source;
            destination++;
            source++;
        }
    }
    return dest;
}

void *s21_memset(void *str, int c, s21_size_t n) {
    char *p = str;
    while (n) {
        n -= 1;
        *p = c;
        p += 1;
    }
    return str;
}

char *s21_strcat(char *dest, const char *src) {
    char *tmp = dest;
    while (*tmp) {
        tmp++;
    }
    while (*src) {
        *tmp = *src;
        tmp++;
        src++;
    }
    *tmp = 0;
    return dest;
}

char *s21_strncat(char *dest, const char *src, size_t n) {
    char *tmp = dest;
    if (n) {
        while (*dest)
            dest += 1;
        while ((*dest = *src) != 0) {
            dest++;
            src++;
            n--;
            if (n == 0) {
                *dest = '\0';
                break;
            }
        }
    }
    return tmp;
}

char *s21_strchr(const char *str, int c) {
    const char *ch = _S21_NULL;
    do {
        if (*str == c) {
            ch = str;
            break;
        }
    } while (*str++ != '\0');
    return (char*)ch;
}

int s21_strcmp(const char *str1, const char *str2) {
    while (*str1 && *str1 == *str2) {
        str1++;
        str2++;
    }
    return *str1 - *str2;
}

int s21_strncmp(const char *str1, const char *str2, s21_size_t n) {
    while (*str1 && *str1 == *str2) {
        n--;
        if (n == 0) {
            break;
            }
        str1++;
        str2++;
    }
    return *str1 - *str2;
}

char *s21_strcpy(char *dest, const char *src) {
    char *ch = dest;
    for (; *src != '\0'; src++, ch++) {
        *ch = *src;
    }
    *ch = '\0';
    return dest;
}

char *s21_strncpy(char *dest, const char *src, s21_size_t n) {
    for (s21_size_t i = 0; i < n; i++) {
        if (src[i] != '\0') {
            dest[i] = src[i];
        } else {
            for (s21_size_t j = i; j < n; j++) {
                dest[j] = 0;
                i = n;
            }
        }
    }
    return dest;
}

s21_size_t s21_strcspn(const char *str1, const char *str2) {
    s21_size_t res = 0;
    int flag = 0;
    const char *ch1;
    const char *ch2;
    for (ch1 = str1; *ch1 != '\0'; ++ch1) {
        for (ch2 = str2; *ch2 != '\0'; ++ch2) {
            if (*ch1 == *ch2) {
                flag = 1;
                break;
            }
        }
        if (flag)
            break;
        ++res;
    }
    return res;
}

char *s21_strerror(int errnum) {
    static char ch[3000];
    char *str = ch;
    if (errnum >= 0 && errnum <= _S21_NERR_) {
      char *errlist[_S21_NERR_ + 1] = _ERROR_S21_;
      s21_sprintf(str, "%s", errlist[errnum]);
    } else {
      char uerr[] = _UNKN_ER_;
      s21_sprintf(str, "%s%d", uerr, errnum);
    }
    return ch;
}

s21_size_t s21_strlen(const char *str) {
    s21_size_t length = 0;
    while (*(str + length)) {
        length++;
    }
    return length;
}

char *s21_strpbrk(const char *str1, const char *str2) {
    char *ch = _S21_NULL;
    int flag = 0;
    for (const char *i = str1; *i != '\0'; i++) {
        for (const char *j = str2; *j != '\0'; j++) {
            if (*i == *j) {
                flag = 1;
                ch = (char*)i;
                break;
            }
        }
        if (flag) {break;}
    }
    return ch;
}

char *s21_strrchr(const char *str, int c) {
    const char *tmp = NULL;
    do {
        if (*str == (char)c) {
            tmp = str;
        }
    } while (*str++);
    return (char*)tmp;
}



s21_size_t s21_strspn(const char *str1, const char *str2) {
    const char *ch1;
    const char *ch2;
    s21_size_t res = 0;
    for (ch1 = str1; *ch1 != '\0'; ch1++) {
        for (ch2 = str2; *ch2 != '\0'; ch2++) {
            if (*ch1 == *ch2) {
                break;
            }
        }
        if (*ch2 == '\0') {
            break;
        }
        res++;
    }
    return res;
}

char *s21_strstr(const char *haystack, const char *needle) {
    char *addr = NULL;
    s21_size_t len1 = s21_strlen(haystack);
    s21_size_t len2 = s21_strlen(needle);
    int flag = 1;
    if (!len2) {
        flag = 0;
        addr = (char *)haystack;
    }
    while (len1 >= len2 && flag) {
        len1--;
        if (!s21_memcmp(haystack, needle, len2)) {
            addr = (char*)haystack;
            flag = 0;
        }
        if (flag)
            haystack++;
    }
    return addr;
}

char *s21_strtok(char *str, const char *delim) {
    static char *tmp = _S21_NULL;
    if ((str == _S21_NULL && tmp == _S21_NULL) || delim == _S21_NULL) return _S21_NULL;
    static int check = 0;
    if (*delim == '\0')
        check = 1;
    if (str != _S21_NULL) {
        tmp = str;
        check = 0;
    }
    if (check != 1) {
        char *tkn = _S21_NULL;
        tkn = tmp;
        for (s21_size_t i = 0; i < s21_strlen(tkn); i++) {
            if (tmp[i + 1] == '\0') {
                str = tkn;
                check = 1;
            }
            for (s21_size_t j = 0; j < s21_strlen(delim); j++) {
                if (tmp[i] == delim[j]) {
                    if (i == 0) {
                        tmp += i + 1;
                        tkn += i + 1;
                        str = tkn;
                        i--;
                        break;
                    } else {
                        tmp[i] = '\0';
                        tmp += i + 1;
                        str = tkn;
                    }
                }
            }
        }
    }
    return str;
}

/* BONUS TRACK */

void *s21_to_upper(const char *str) {
    char *temp = calloc((s21_strlen(str) + 1), sizeof(char));
    char *upstr = temp;
    while (*str != '\0') {
        if (*str >= 'a' && *str <= 'z') {
            *temp = *str - ' ';
        } else {
            *temp = *str;
        }
        str++;
        temp++;
    }
    return (void*)upstr;
}

void *s21_to_lower(const char *str) {
    char *temp = calloc((s21_strlen(str) + 1), sizeof(char));
    char *lowstr = temp;
    while (*str != '\0') {
        if (*str >= 'A' && *str <= 'Z') {
            *temp = *str + ' ';
        } else {
            *temp = *str;
        }
        str++;
        temp++;
    }
    return (void*)lowstr;
}

void *s21_insert(const char *src, const char *str, s21_size_t start_index) {
    char *ret_str = _S21_NULL;
    if (src != _S21_NULL && str != _S21_NULL && start_index <= s21_strlen(src)) {
    int len = (int)s21_strlen(src) + (int)s21_strlen(str);
    char *newstr = calloc((len + 1), sizeof(char));
    ret_str = newstr;
    for (int i = 0, k = 0; i < len; i++, k++) {
        if (i == (int)start_index) {
            int thisPos = i;
            for (int j = 0; i < thisPos + (int)s21_strlen(str); i++, j++) {
                newstr[i] = str[j];
            }
        }
        newstr[i] = src[k];
    }
    newstr[len + 1] = '\0';
    }
    return (void*)ret_str;
}

void *s21_trim(const char *src, const char *trim_chars) {
    char *ret_str = _S21_NULL;
    if (src != _S21_NULL) {
        char *ch = (char*)trim_chars;
        if (s21_strcmp(trim_chars, "") == 0)
            ch = " \n\t\r\0";
        int len = (int)s21_strlen(src);
        int len_start = (int)s21_strspn(src, ch);
        int len1 = len - len_start;
        char *temp = calloc((len1 + 1), sizeof(char));
        for (int i = 0, j = len - 1; j >= len_start; i++, j--) {
            temp[i] = src[j];
        }
        int len_end = (int)s21_strspn(temp, ch);
        int len2 = len1 - len_end;
        char *newstr = calloc((len2 + 1), sizeof(char));
        for (int i = 0, j = len1 - 1; j >= len_end; i++, j--) {
            newstr[i] = temp[j];
        }
        free(temp);
        ret_str = newstr;
    }
    return (void*)ret_str;
}
