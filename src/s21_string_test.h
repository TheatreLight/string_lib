#ifndef SRC_S21_STRING_TEST_H_
#define SRC_S21_STRING_TEST_H_
#include <limits.h>
#include <stddef.h>

#define TEST_CASE_COUNT 5
#define M_length 1024

struct mmch {
  char memchr_1[M_length];
  int memchr_2;
  size_t memchr_3;
} mmch_tc[TEST_CASE_COUNT] = {{"Vika, Dima, Petr, Ivan", 86, 15},
                              {"Hello world\0", 54, 8},
                              {"Hello world\n\0", 42, 3},
                              {"a\n\0", 99, 32},
                              {" \n\0", 90, 20}};

struct mmcmp {
  char memcmp_1[M_length];
  char memcmp_2[M_length];
  size_t memcmp_3;
} mmcmp_tc[TEST_CASE_COUNT] = {{"Vika, Dima, Petr, Ivan", "Hello world\0", 5},
                               {"Hello world\0", "Hello world\n\0", 3},
                               {"a\n\0", " \n\0", 18},
                               {"Hello world\0", " \n\0", 33},
                               {"Vika, Dima, Petr, Ivan", "a\n\0", 22}};

struct mmcpy {
  char memcpy_1[M_length];
  char memcpy_2[M_length];
  size_t memcpy_3;
} mmcpy_tc[TEST_CASE_COUNT] = {{"Vika, Dima, Petr, Ivan", "Hello world\0", 5},
                               {"Hello world\0", "Hello world\n\0", 3},
                               {"a\n\0", " \n\0", 18},
                               {"Hello world\0", " \n\0", 33},
                               {"Vika, Dima, Petr, Ivan", "a\n\0", 22}};

struct mmmv {
  char memmove_1[M_length];
  char memmove_2[M_length];
  size_t memmove_3;
} mmmv_tc[TEST_CASE_COUNT] = {{"Vika, Dima, Petr, Ivan", "Hello world\0", 5},
                              {"Hello world\0", "Hello world\n\0", 3},
                              {"a\n\0", " \n\0", 18},
                              {"Hello world\0", " \n\0", 33},
                              {"Vika, Dima, Petr, Ivan", "a\n\0", 22}};

struct mmst {
  char memset_1[M_length];
  int memset_2;
  size_t memset_3;
} mmst_tc[TEST_CASE_COUNT] = {{"Vika, Dima, Petr, Ivan", 126, 9},
                              {"Hello world\0", 104, 1},
                              {"Hello world\n\0", 42, 1},
                              {"a\n\0", 71, 5},
                              {" \n\0", 86, 4}};

struct strct {
  char strcat_1[M_length];
  char strcat_2[M_length];
} strct_tc[TEST_CASE_COUNT] = {{"Vika, Dima,", " Petr, Ivan"},
                               {"Hello world\0", "a\n\0"},
                               {" \n\0", "Vika, Dima, Petr, Ivan"},
                               {"Vika, Dima, Petr, Ivan,", "  \n\0"},
                               {"\0", "\n"}};

struct strnct {
  char strncat_1[M_length];
  char strncat_2[M_length];
  size_t strncat_3;
} strnct_tc[TEST_CASE_COUNT] = {
    {"Vika, Dima,", " Petr, Ivan, Roman, Andrei", 11},
    {"01234", "56789101112131415", 5},
    {"School", "_21 Moscow", 3},
    {"Hello,", " world and everybody", 6},
    {"\0", "\n", 0}};

struct strch {
  char strchr_1[M_length];
  int strchr_2;
} strch_tc[TEST_CASE_COUNT] = {{"Vika, Dima, Petr, Ivan", 0},
                               {"Hello world\0", 44},
                               {"Hello world\n\0", 92},
                               {"a\n\0", 95},
                               {" \n\0", 45}};

struct strcmp {
  char strcmp_1[M_length];
  char strcmp_2[M_length];
} strcmp_tc[TEST_CASE_COUNT] = {{"Vika, Dima, Petr, Ivan", "Hello world\0"},
                                {"Hello world\0", "Hello world\n\0"},
                                {"a\n\0", " \n\0"},
                                {"Hello world\0", " \n\0"},
                                {"Vika, Dima, Petr, Ivan", "a\n\0"}};

struct strncmp {
  char strncmp_1[M_length];
  char strncmp_2[M_length];
  size_t strncmp_3;
} strncmp_tc[TEST_CASE_COUNT] = {{"Vika, Dima, Petr, Ivan", "Hello world\0", 5},
                                 {"Hello world\0", "Hello world\n\0", 3},
                                 {"a\n\0", " \n\0", 18},
                                 {"Hello world\0", " \n\0", 33},
                                 {"Vika, Dima, Petr, Ivan", "a\n\0", 22}};

struct strcpy {
  char strcpy_1[M_length];
  char strcpy_2[M_length];
} strcp_tc[TEST_CASE_COUNT] = {{"Hello world\0", "Vika, Dima, Petr, Ivan"},
                               {"Hello world\n\0", " \n\0"},
                               {"Vika, Dima, Petr, Ivan", "Hello world\n\0"},
                               {" \n\0", "Hello world\0"},
                               {" \n\0", " \n\0"}};

struct strncpy {
  char strncpy_1[M_length];
  char strncpy_2[M_length];
  size_t strncpy_3;
} strncp_tc[TEST_CASE_COUNT] = {{"Vika, Dima, Petr, Ivan", "Hello world\0", 5},
                                {"Hello world\0", "Hello world\n\0", 3},
                                {"a\n\0", " \n\0", 18},
                                {"Hello world\0", " \n\0", 33},
                                {"Vika, Dima, Petr, Ivan", "a\n\0", 22}};

struct strcspn {
  char strcspn_1[M_length];
  char strcspn_2[M_length];
} strcspn_tc[TEST_CASE_COUNT] = {{"Vika, Dima, Petr, Ivan", "Hello world\0"},
                                 {"Hello world\0", "Hello world\n\0"},
                                 {"a\n\0", " \n\0"},
                                 {"Hello world\0", " \n\0"},
                                 {"Vika, Dima, Petr, Ivan", "a\n\0"}};

struct strer {
  int strerror_1;
} strer_tc[TEST_CASE_COUNT] = {{1}, {4}, {15}, {500}, {-10}};

struct strln {
  char strlen_1[M_length];
} strln_tc[TEST_CASE_COUNT] = {{"Vika, Dima, Petr, Ivan"},
                               {"Hello world\0"},
                               {"Hello world\n\0"},
                               {"a\n\0"},
                               {" \n\0"}};

struct strpbrk {
  char strpbrk_1[M_length];
  char strpbrk_2[M_length];
} strpbr_tc[TEST_CASE_COUNT] = {{"Vika, Dima, Petr, Ivan", "Hello world\0"},
                                {"Hello world\0", "Hello world\n\0"},
                                {"a\n\0", " \n\0"},
                                {"Hello world\0", " \n\0"},
                                {"Vika, Dima, Petr, Ivan", "a\n\0"}};

struct strrch {
  char strrchr_1[M_length];
  int strrchr_2;
} strrch_tc[TEST_CASE_COUNT] = {{"Vika, Dima, Petr, Ivan", 0},
                                {"Hello world\0", 44},
                                {"Hello world\n\0", 92},
                                {"a\n\0", 95},
                                {" \n\0", 45}};

struct strspn {
  char strspn_1[M_length];
  char strspn_2[M_length];
} strspn_tc[TEST_CASE_COUNT] = {{"Vika, Dima, Petr, Ivan", "Hello world\0"},
                                {"Hello world\0", "Hello world\n\0"},
                                {"a\n\0", " \n\0"},
                                {"Hello world\0", " \n\0"},
                                {"Vika, Dima, Petr, Ivan", "a\n\0"}};

struct strstr {
  char strstr_1[M_length];
  char strstr_2[M_length];
} strstr_tc[TEST_CASE_COUNT] = {
    {"Vika, Dima, Petr, Ivan", "Vika"},
    {"Vika, Dima, Petr, Ivan", "Dima,"},
    {"Vika, Dima, Petr, Ivan", "VPetr"},
    {"Vika, Dima, Petr, Ivan", "Ivan"},
    {"Vika, Dima, Petr, Ivan", "Vika, Dima, Petr, Ivan"}};

struct strtok {
  char strtok_1[M_length];
  char strtok_2[M_length];
  char strtok_3[M_length];
} strtok_tc[5] = {{"Vika, Dima, Petr, Ivan", " ", "Vika, Dima, Petr, Ivan"},
                  {"Vika, Dima, Petr, Ivan", " a", "Vika, Dima, Petr, Ivan"},
                  {"Hello world\0", "a\n\0", "Hello world\0"},
                  {"Vika, Dima, Petr, Ivan", " \n\0", "Vika, Dima, Petr, Ivan"},
                  {"Hello world\n\0", " ", "Hello world\n\0"}};

struct to_upper {
  char to_upper_1[M_length];
  char to_upper_2[M_length];
} t_up_tc[TEST_CASE_COUNT] = {{"S21_school", "S21_SCHOOL"},
                              {"", ""},
                              {"12312312312", "12312312312"},
                              {"qWeRTy", "QWERTY"},
                              {"SSS", "SSS"}};

struct to_lower {
  char to_lower_1[M_length];
  char to_lower_2[M_length];
} t_lw_tc[TEST_CASE_COUNT] = {{"S21_school", "s21_school"},
                              {"", ""},
                              {"12312312312", "12312312312"},
                              {"qWeRTy", "qwerty"},
                              {"a", "a"}};

struct insert {
  char insert_1[M_length];
  char insert_2[M_length];
  size_t insert_3;
  char insert_4[M_length];
} ins_tc[TEST_CASE_COUNT] = {
    {"Vika, Dima, Ivan", "Petr, ", 6, "Vika, Petr, Dima, Ivan"},
    {"Vika, Dima, Ivan", " - the best", 4, "Vika - the best, Dima, Ivan"},
    {"Vika, Dima, Ivan", " - the best", 10, "Vika, Dima - the best, Ivan"},
    {"Vika, Dima, Ivan", " - the best", 16, "Vika, Dima, Ivan - the best"},
    {"Vika, Dima, Petr, Ivan", " - the best", 16,
     "Vika, Dima, Petr - the best, Ivan"},
};

struct trim {
  char trim_1[M_length];
  char trim_2[M_length];
  char trim_3[M_length];
} trim_tc[TEST_CASE_COUNT] = {{"22211112334334qwe121333", "123", "4334qwe"},
                              {"123321qwe121333", "123", "qwe"},
                              {"111222333444qwe323232", "123", "444qwe"},
                              {"segamegadrives", "es", "gamegadriv"},
                              {"you don't know the dark side power", "you",
                               " don't know the dark side power"}};

struct sprintf_c {
  char str[M_length];
  char format[M_length];
} sprintf_tc_c[TEST_CASE_COUNT] = {
    {"S", "%+c"}, {"7", "%-c"}, {"sc", "%c"}};

struct sprintf_d {
  char str[M_length];
  char format[M_length];
} sprintf_tc_d[TEST_CASE_COUNT] = {{"123", "%d"},
                                   {"-123", "%-d"},
                                   {"123", "%+d"},
                                   {"123", "%2d"},
                                   {"123", "% d"}};

struct sprintf_i {
  char str[M_length];
  char format[M_length];
} sprintf_tc_i[TEST_CASE_COUNT] = {{"0123", "%i"},
                                   {"0x123", "%i"},
                                   {"-123", "%+i"},
                                   {"0x123", "%4i"},
                                   {"0123", "%+7i"}};

struct sprintf_e {
  double e;
  char format[M_length];
} sprintf_tc_e[TEST_CASE_COUNT] = {{3.926500e+02, "%e"},
                                   {3.926500e+02, "%e"},
                                   {3.926500e+02, "%e"},
                                   {3.926500e+02, "%e"},
                                   {3.926500e+02, "%e"}};

struct sprintf_E {
  double E;
  char format[M_length];
} sprintf_tc_E[TEST_CASE_COUNT] = {{3.926500E+02, "%E"},
                                   {3.926500E+02, "%E"},
                                   {3.926500E+02, "%E"},
                                   {3.926500E+02, "%E"},
                                   {3.926500E+02, "%E"}};

struct sprintf_f {
  double f;
  char format[M_length];
} sprintf_tc_f[TEST_CASE_COUNT] = {{3.14, "%f"},
                                   {201.5454892, "%f"},
                                   {201.5454892, "%+.3f"},
                                   {201.0000, "%#f"},
                                   {201.5454892, "%4f"}};

struct sprintf_g {
  double g;
  char format[M_length];
} sprintf_tc_g[TEST_CASE_COUNT] = {{3.926500e+02, "%g"},
                                   {3.926500e+02, "%g"},
                                   {3.926500e+02, "%g"},
                                   {3.926500e+02, "%g"},
                                   {3.926500e+02, "%g"}};

struct sprintf_G {
  double G;
  char format[M_length];
} sprintf_tc_G[TEST_CASE_COUNT] = {{3.926500e+02, "%G"},
                                   {3.926500e+02, "%G"},
                                   {3.926500e+02, "%G"},
                                   {3.926500e+02, "%G"},
                                   {3.926500e+02, "%G"}};

struct sprintf_o {
  unsigned int o;
  char format[M_length];
} sprintf_tc_o[TEST_CASE_COUNT] = {
    {21, "%o"}, {021, "%o"}, {0x21, "%o"}, {21, "%o"}, {21, "%o"}};

struct sprintf_s {
  char str[M_length];
  char format[M_length];
} sprintf_tc_s[TEST_CASE_COUNT] = {{"School", "%-s"},
                                   {"School 21", "%15s"},
                                   {"School 21 Ecole 42", "%+s"},
                                   {"School 21", "%.6s"}};

struct sprintf_u {
  unsigned int u;
  char format[M_length];
} sprintf_tc_u[TEST_CASE_COUNT] = {
    {48, "%u"}, {-48, "%+u"}, {85, "%003u"}, {25, "% u"}, {21, "%#u"}};

struct sprintf_x {
  unsigned int x;
  char format[M_length];
} sprintf_tc_x[TEST_CASE_COUNT] = {
    {19, "%x"}, {21, "%-x"}, {21, "%+x"}, {21, "%.5x"}, {32, "%#5.2x"}};

struct sprintf_X {
  unsigned int X;
  char format[M_length];
} sprintf_tc_X[TEST_CASE_COUNT] = {
    {19, "%X"}, {21, "%-X"}, {21, "%+x"}, {21, "%.5X"}, {32, "%#5.2X"}};

struct sprintf_p {
  char str[M_length];
  char format[M_length];
} sprintf_tc_p[TEST_CASE_COUNT] = {
    {"0060FEA8", "%p"}, {"", "%#p"}, {"", "%-p"}};

struct sprintf_pc {
  char str[M_length];
  char format[M_length];
} sprintf_tc_pc[TEST_CASE_COUNT] = {
    {"%", "%%"}, {"%", "%%"}, {"%", "%%"}, {"%", "%%"}, {"%", "%%"}};

struct s_test_data {
  char *data;
  char *format;
  int n;
} s_tests[] = {
    {"20lvl Insane people", "%s", 0},   {"20lvl Insane people", "%-25s", 0},
    {"20lvl Insane people", "%*s", 25}, {"20lvl Insane people", "%25s", 0},
    {"20lvl Insane people", "%25s", 0}, {"20lvl Insane people", "%.5s", 0},
    {"20lvl Insane people", "%.*s", 5}};

struct c_test_data {
  char data;
  char *format;
  int n;
} c_tests[] = {{'A', "%c", 0},   {'A', "%-25c", 0}, {'A', "%*c", 25},
               {'A', "%25c", 0}, {'A', "%25c", 0},  {'A', "%.5c", 0},
               {'A', "%.*c", 5}};

struct d_test_data {
  long int data;
  char *format;
  int n;
} d_tests[] = {{20, "%d", 0},
               {20, "%-5d", 0},
               {20, "%+d", 0},
               {20, "% d", 0},
               {20, "%05d", 0},
               {-20, "%5d", 0},
               {-20, "%*d", 5},
               {20, "%.5d", 0},
               {20, "%.*d", 5},
               {INT_MAX, "%d", 0},
               {INT_MAX, "%hd", 0},
               {9223372036854775807L, "%ld", 0},
               {INT_MIN, "%d", 0},
               {20, "%i", 0},
               {20, "%-5i", 0},
               {20, "%+i", 0},
               {20, "% i", 0},
               {20, "%05i", 0},
               {-20, "%5i", 0},
               {-20, "%*i", 5},
               {20, "%.5i", 0},
               {20, "%.*i", 5},
               {INT_MAX, "%i", 0},
               {INT_MAX, "%hi", 0},
               {9223372036854775807L, "%li", 0},
               {INT_MIN, "%i", 0}};

struct o_test_data {
  long int data;
  char *format;
  int n;
} o_tests[] = {{191, "%x", 0},       {191, "%-5x", 0},
               {191, "%05x", 0},     {191, "%#x", 0},
               {191, "%*x", 5},      {191, "%.5x", 0},
               {191, "%.*x", 5},     {UINT_MAX, "%x", 0},
               {UINT_MAX, "%hx", 0}, {9223372036854775807L, "%lx", 0},
               {191, "%X", 0}};

struct x_test_data {
  long int data;
  char *format;
  int n;
} x_tests[] = {{191, "%x", 0},       {191, "%-5x", 0},
               {191, "%05x", 0},     {191, "%#x", 0},
               {191, "%*x", 5},      {191, "%.5x", 0},
               {191, "%.*x", 5},     {UINT_MAX, "%x", 0},
               {UINT_MAX, "%hx", 0}, {9223372036854775807L, "%lx", 0},
               {191, "%X", 0}};

struct f_test_data {
  double data;
  char *format;
  int n;
} f_tests[] = {{5.0, "%f", 0},    {5.0, "%*f", 10},        {5.0, "%10f", 10},
               {5.0, "%-10f", 0}, {5.0, "%+f", 0},         {5.0, "% f", 0},
               {5.0, "%#.0f", 0}, {5.0, "%010f", 0},       {5.0, "%.5f", 0},
               {5.0, "%.*f", 5},  {INT_MIN * 1.0, "%f", 0}};

struct u_test_data {
  unsigned long int data;
  char *format;
  int n;
} u_tests[] = {{191, "%x", 0},       {191, "%-5x", 0},
               {191, "%05x", 0},     {191, "%#x", 0},
               {191, "%*x", 5},      {191, "%.5x", 0},
               {191, "%.*x", 5},     {UINT_MAX, "%x", 0},
               {UINT_MAX, "%hx", 0}, {9223372036854775807L, "%lx", 0},
               {191, "%X", 0}};

struct g_test_data {
  double data;
  char *format;
  int n;
} g_tests[] = {{5.0, "%e", 0},    {5.0, "%*e", 10},        {5.0, "%10e", 10},
               {5.0, "%-10e", 0}, {5.0, "%+e", 0},         {5.0, "% e", 0},
               {5.0, "%#.0e", 0}, {5.0, "%010e", 0},       {5.0, "%.5e", 0},
               {5.0, "%.*e", 5},  {INT_MIN * 1.0, "%e", 0}};

struct e_test_data {
  double data;
  char *format;
  int n;
} e_tests[] = {{5.0, "%e", 0},    {5.0, "%*e", 10},        {5.0, "%10e", 10},
               {5.0, "%-10e", 0}, {5.0, "%+e", 0},         {5.0, "% e", 0},
               {5.0, "%#.0e", 0}, {5.0, "%010e", 0},       {5.0, "%.5e", 0},
               {5.0, "%.*e", 5},  {INT_MIN * 1.0, "%e", 0}};

struct p_test_data {
  char *data;
  char *format;
  int n;
} p_tests[] = {{"", "%p", 0},     {"", "%-15p", 0}, {"", "%15p", 0},
               {"", "%015pe", 0}, {"", "%.15p", 0}, {"", "%*p", 15},
               {"", "%.*p", 15}};

#endif  // SRC_S21_STRING_TEST_H_
