# string_lib

It's my own implementation of standart string library in C;

make s21_string.a - build a library;

make test - build and run unit-tests (need a check.h library);

make gcov-report - build an html-report (need lcov);

make clean - remove object and library files.

## Information

The C programming language has a set of functions implementing operations on strings (character strings and byte strings) in its standard library. Various operations, such as copying, concatenation, tokenization and searching are supported. For character strings, the standard library uses the convention that strings are null-terminated: a string of n characters is represented as an array of n + 1 elements, the last of which is a "NULL" character. 
The only support for strings in the programming language proper is that the compiler translates quoted string constants into null-terminated strings.

### 1. Functions
+ void *memchr(const void *str, int c, size_t n);
+ int memcmp(const void *str1, const void *str2, size_t n);
+ void *memcpy(void *dest, const void *src, size_t n);
+ void *memmove(void *dest, const void *src, size_t n);
+ void *memset(void *str, int c, size_t n);
+ char *strcat(char *dest, const char *src);
char *strncat(char *dest, const char *src, size_t n);
char *strchr(const char *str, int c);
int strcmp(const char *str1, const char *str2);
int strncmp(const char *str1, const char *str2, size_t n);
char *strcpy(char *dest, const char *src);
char *strncpy(char *dest, const char *src, size_t n);
size_t strcspn(const char *str1, const char *str2);
char *strerror(int errnum);
size_t strlen(const char *str);
char *strpbrk(const char *str1, const char *str2);
char *strrchr(const char *str, int c);
size_t strspn(const char *str1, const char *str2);
char *strstr(const char *haystack, const char *needle);
char *strtok(char *str, const char *delim);

### 2. Additional functions

int sscanf(const char *str, const char *format, ...) - reads formatted input from a string.
int sprintf(char *str, const char *format, ...) - sends formatted output to a string pointed to, by str.

### 3. C# functions

void *to_upper(const char *str);
void *to_lower(const char *str);
void *insert(const char *src, const char *str, size_t start_index);
void *trim(const char *src, const char *trim_chars).
