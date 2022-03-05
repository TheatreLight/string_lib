#include "s21_string.h"
#include <check.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "s21_string_test.h"

#define STR_SIZE 30

START_TEST(s21_memchr_test) {
  for (int i = 0; i < TEST_CASE_COUNT; i++) {
    ck_assert_ptr_eq(
        s21_memchr(mmch_tc[i].memchr_1, mmch_tc[i].memchr_2,
                   mmch_tc[i].memchr_3),
        memchr(mmch_tc[i].memchr_1, mmch_tc[i].memchr_2, mmch_tc[i].memchr_3));
  }
}
END_TEST

START_TEST(s21_memcmp_test) {
  for (int i = 0; i < TEST_CASE_COUNT; i++) {
    int akt = s21_memcmp(mmcmp_tc[i].memcmp_1, mmcmp_tc[i].memcmp_2,
                         mmcmp_tc[i].memcmp_3);
    int exp = memcmp(mmcmp_tc[i].memcmp_1, mmcmp_tc[i].memcmp_2,
                     mmcmp_tc[i].memcmp_3);
    ck_assert_int_eq((akt > 0) == (exp > 0), 1);
  }
}
END_TEST

START_TEST(s21_memcpy_test) {
  for (int i = 0; i < TEST_CASE_COUNT; i++) {
    ck_assert_str_eq(s21_memcpy(mmcpy_tc[i].memcpy_1, mmcpy_tc[i].memcpy_2,
                                mmcpy_tc[i].memcpy_3),
                     memcpy(mmcpy_tc[i].memcpy_1, mmcpy_tc[i].memcpy_2,
                            mmcpy_tc[i].memcpy_3));
  }
}
END_TEST

START_TEST(s21_memmove_test) {
  for (int i = 0; i < TEST_CASE_COUNT; i++) {
    ck_assert_str_eq(s21_memmove(mmmv_tc[i].memmove_1, mmmv_tc[i].memmove_2,
                                 mmmv_tc[i].memmove_3),
                     memmove(mmmv_tc[i].memmove_1, mmmv_tc[i].memmove_2,
                             mmmv_tc[i].memmove_3));
  }
}
END_TEST

START_TEST(s21_memset_test) {
  for (int i = 0; i < TEST_CASE_COUNT; i++) {
    ck_assert_str_eq(
        s21_memset(mmst_tc[i].memset_1, mmst_tc[i].memset_2,
                   mmst_tc[i].memset_3),
        memset(mmst_tc[i].memset_1, mmst_tc[i].memset_2, mmst_tc[i].memset_3));
  }
}
END_TEST

START_TEST(s21_strcat_test) {
  for (int i = 0; i < TEST_CASE_COUNT; i++) {
    ck_assert_str_eq(s21_strcat(strct_tc[i].strcat_1, strct_tc[i].strcat_2),
                     strcat(strct_tc[i].strcat_1, strct_tc[i].strcat_2));
  }
}
END_TEST

START_TEST(s21_strncat_test) {
  for (int i = 0; i < TEST_CASE_COUNT; i++) {
    ck_assert_str_eq(s21_strncat(strnct_tc[i].strncat_1, strnct_tc[i].strncat_2,
                                 strnct_tc[i].strncat_3),
                     strncat(strnct_tc[i].strncat_1, strnct_tc[i].strncat_2,
                             strnct_tc[i].strncat_3));
  }
}
END_TEST

START_TEST(s21_strchr_test) {
  for (int i = 0; i < TEST_CASE_COUNT; i++) {
    ck_assert_ptr_eq(s21_strchr(strch_tc[i].strchr_1, strch_tc[i].strchr_2),
                     strchr(strch_tc[i].strchr_1, strch_tc[i].strchr_2));
  }
}
END_TEST

START_TEST(s21_strcmp_test) {
  for (int i = 0; i < TEST_CASE_COUNT; i++) {
    ck_assert_int_eq(s21_strcmp(strcmp_tc[i].strcmp_1, strcmp_tc[i].strcmp_2),
                     strcmp(strcmp_tc[i].strcmp_1, strcmp_tc[i].strcmp_2));
  }
}
END_TEST

START_TEST(s21_strncmp_test) {
  for (int i = 0; i < TEST_CASE_COUNT; i++) {
    ck_assert_int_eq(
        s21_strncmp(strncmp_tc[i].strncmp_1, strncmp_tc[i].strncmp_2,
                    strncmp_tc[i].strncmp_3),
        strncmp(strncmp_tc[i].strncmp_1, strncmp_tc[i].strncmp_2,
                strncmp_tc[i].strncmp_3));
  }
}
END_TEST

START_TEST(s21_strcpy_test) {
  for (int i = 0; i < TEST_CASE_COUNT; i++) {
    ck_assert_str_eq(s21_strcpy(strcp_tc[i].strcpy_1, strcp_tc[i].strcpy_2),
                     strcpy(strcp_tc[i].strcpy_1, strcp_tc[i].strcpy_2));
  }
}
END_TEST

START_TEST(s21_strncpy_test) {
  for (int i = 0; i < TEST_CASE_COUNT; i++) {
    ck_assert_str_eq(s21_strncpy(strncp_tc[i].strncpy_1, strncp_tc[i].strncpy_2,
                                 strncp_tc[i].strncpy_3),
                     strncpy(strncp_tc[i].strncpy_1, strncp_tc[i].strncpy_2,
                             strncp_tc[i].strncpy_3));
  }
}
END_TEST

START_TEST(s21_strcspn_test) {
  for (int i = 0; i < TEST_CASE_COUNT; i++) {
    ck_assert_int_eq(
        s21_strcspn(strcspn_tc[i].strcspn_1, strcspn_tc[i].strcspn_2),
        strcspn(strcspn_tc[i].strcspn_1, strcspn_tc[i].strcspn_2));
  }
}
END_TEST

START_TEST(s21_strerror_test) {
  for (int i = -1000; i < 1000; i++) {
    ck_assert_str_eq(s21_strerror(i),
                     strerror(i));
  }
}
END_TEST

START_TEST(s21_strlen_test) {
  for (int i = 0; i < TEST_CASE_COUNT; i++) {
    ck_assert_int_eq(s21_strlen(strln_tc[i].strlen_1),
                     strlen(strln_tc[i].strlen_1));
  }
}
END_TEST

START_TEST(s21_strpbrk_test) {
  for (int i = 0; i < TEST_CASE_COUNT; i++) {
    ck_assert_ptr_eq(
        s21_strpbrk(strpbr_tc[i].strpbrk_1, strpbr_tc[i].strpbrk_2),
        strpbrk(strpbr_tc[i].strpbrk_1, strpbr_tc[i].strpbrk_2));
  }
}
END_TEST

START_TEST(s21_strrchr_test) {
  for (int i = 0; i < TEST_CASE_COUNT; i++) {
    ck_assert_ptr_eq(
        s21_strrchr(strrch_tc[i].strrchr_1, strrch_tc[i].strrchr_2),
        strrchr(strrch_tc[i].strrchr_1, strrch_tc[i].strrchr_2));
  }
}
END_TEST

START_TEST(s21_strspn_test) {
  for (int i = 0; i < TEST_CASE_COUNT; i++) {
    ck_assert_int_eq(s21_strspn(strspn_tc[i].strspn_1, strspn_tc[i].strspn_2),
                     strspn(strspn_tc[i].strspn_1, strspn_tc[i].strspn_2));
  }
}
END_TEST

START_TEST(s21_strstr_test) {
  for (int i = 0; i < TEST_CASE_COUNT; i++) {
    ck_assert_ptr_eq(s21_strstr(strstr_tc[i].strstr_1, strstr_tc[i].strstr_2),
                     strstr(strstr_tc[i].strstr_1, strstr_tc[i].strstr_2));
  }
}
END_TEST

START_TEST(s21_strtok_test) {
  for (int i = 0; i < TEST_CASE_COUNT; i++) {
    char *tok1 = s21_strtok(strtok_tc[i].strtok_1, strtok_tc[i].strtok_2);
    char *tok2 = strtok(strtok_tc[i].strtok_3, strtok_tc[i].strtok_2);
    while (tok2 != NULL) {
      ck_assert_str_eq(tok1, tok2);
      tok1 = s21_strtok(NULL, strtok_tc[i].strtok_2);
      tok2 = strtok(NULL, strtok_tc[i].strtok_2);
    }
  }
}
END_TEST

START_TEST(s21_to_upper_test) {
  for (int i = 0; i < TEST_CASE_COUNT; i++) {
    char *upr = s21_to_upper(t_up_tc[i].to_upper_1);
    ck_assert_str_eq(upr, t_up_tc[i].to_upper_2);
    free(upr);
  }
}
END_TEST

START_TEST(s21_to_lower_test) {
  for (int i = 0; i < TEST_CASE_COUNT; i++) {
    char *lwr = s21_to_lower(t_lw_tc[i].to_lower_1);
    ck_assert_str_eq(lwr, t_lw_tc[i].to_lower_2);
    free(lwr);
  }
}
END_TEST

START_TEST(s21_insert_test) {
  for (int i = 0; i < TEST_CASE_COUNT; i++) {
    char *insrt =
        s21_insert(ins_tc[i].insert_1, ins_tc[i].insert_2, ins_tc[i].insert_3);
    ck_assert_str_eq(insrt, ins_tc[i].insert_4);
    free(insrt);
  }
}
END_TEST

START_TEST(s21_trim_test) {
  for (int i = 0; i < TEST_CASE_COUNT; i++) {
    char *trm = s21_trim(trim_tc[i].trim_1, trim_tc[i].trim_2);
    ck_assert_str_eq(trm, trim_tc[i].trim_3);
    free(trm);
  }
}
END_TEST

START_TEST(s21_sprintf_c_test) {
  for (int i = 0; i < TEST_CASE_COUNT; i++) {
    char str1[M_length];
    char str2[M_length];
    s21_sprintf(str1, sprintf_tc_c[i].format, sprintf_tc_c[i].str);
    sprintf(str2, sprintf_tc_c[i].format, sprintf_tc_c[i].str);
    ck_assert_str_eq(str1, str2);
  }
}
END_TEST

START_TEST(s21_sprintf_d_test) {
  for (int i = 0; i < TEST_CASE_COUNT; i++) {
    char str1[M_length];
    char str2[M_length];
    s21_sprintf(str1, sprintf_tc_d[i].format, sprintf_tc_d[i].str);
    sprintf(str2, sprintf_tc_d[i].format, sprintf_tc_d[i].str);
    ck_assert_str_eq(str1, str2);
  }
}
END_TEST

START_TEST(s21_sprintf_i_test) {
  for (int i = 0; i < TEST_CASE_COUNT; i++) {
    char str1[M_length];
    char str2[M_length];
    s21_sprintf(str1, sprintf_tc_i[i].format, sprintf_tc_i[i].str);
    sprintf(str2, sprintf_tc_i[i].format, sprintf_tc_i[i].str);
    ck_assert_str_eq(str1, str2);
  }
}
END_TEST

START_TEST(s21_sprintf_e_test) {
  for (int i = 0; i < TEST_CASE_COUNT; i++) {
    char str1[M_length];
    char str2[M_length];
    s21_sprintf(str1, sprintf_tc_e[i].format, sprintf_tc_e[i].e);
    sprintf(str2, sprintf_tc_e[i].format, sprintf_tc_e[i].e);
    ck_assert_str_eq(str1, str2);
  }
  char str1[M_length];
  char str2[M_length];

  s21_sprintf(str1, "%e", 3.926500e+02);
  sprintf(str2, "%e", 3.926500e+02);
  ck_assert_str_eq(str1, str2);

  s21_sprintf(str1, "%025e", 3.926500e+02);
  sprintf(str2, "%025e", 3.926500e+02);
  ck_assert_str_eq(str1, str2);

  s21_sprintf(str1, "%+025e", 3.926500e+02);
  sprintf(str2, "%+025e", 3.926500e+02);
  ck_assert_str_eq(str1, str2);

  s21_sprintf(str1, "%# 25e", 3.926500e+02);
  sprintf(str2, "%# 25e", 3.926500e+02);
  ck_assert_str_eq(str1, str2);

  s21_sprintf(str1, "% -25e", 3.926500e+02);
  sprintf(str2, "% -25e", 3.926500e+02);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_E_test) {
  for (int i = 0; i < TEST_CASE_COUNT; i++) {
    char str1[M_length];
    char str2[M_length];
    s21_sprintf(str1, sprintf_tc_E[i].format, sprintf_tc_E[i].E);
    sprintf(str2, sprintf_tc_E[i].format, sprintf_tc_E[i].E);
    ck_assert_str_eq(str1, str2);
  }
  char str1[M_length];
  char str2[M_length];

  s21_sprintf(str1, "%E", 3.926500E+02);
  sprintf(str2, "%E", 3.926500E+02);
  ck_assert_str_eq(str1, str2);

  s21_sprintf(str1, "%025E", 3.926500E+02);
  sprintf(str2, "%025E", 3.926500E+02);
  ck_assert_str_eq(str1, str2);

  s21_sprintf(str1, "%+025e", 3.926500E+02);
  sprintf(str2, "%+025e", 3.926500E+02);
  ck_assert_str_eq(str1, str2);

  s21_sprintf(str1, "%# 25e", 3.926500E+02);
  sprintf(str2, "%# 25e", 3.926500E+02);
  ck_assert_str_eq(str1, str2);

  s21_sprintf(str1, "% -25e", 3.926500E+02);
  sprintf(str2, "% -25e", 3.926500E+02);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_f_test) {
  for (int i = 0; i < TEST_CASE_COUNT; i++) {
    char str1[M_length];
    char str2[M_length];
    s21_sprintf(str1, sprintf_tc_f[i].format, sprintf_tc_f[i].f);
    sprintf(str2, sprintf_tc_f[i].format, sprintf_tc_f[i].f);
    ck_assert_str_eq(str1, str2);
  }
}
END_TEST

START_TEST(s21_sprintf_g_test) {
  for (int i = 0; i < TEST_CASE_COUNT; i++) {
    char str1[M_length];
    char str2[M_length];
    s21_sprintf(str1, sprintf_tc_g[i].format, sprintf_tc_g[i].g);
    sprintf(str2, sprintf_tc_g[i].format, sprintf_tc_g[i].g);
    ck_assert_str_eq(str1, str2);
  }
}
END_TEST

START_TEST(s21_sprintf_G_test) {
  for (int i = 0; i < TEST_CASE_COUNT; i++) {
    char str1[M_length];
    char str2[M_length];
    s21_sprintf(str1, sprintf_tc_G[i].format, sprintf_tc_G[i].G);
    sprintf(str2, sprintf_tc_G[i].format, sprintf_tc_G[i].G);
    ck_assert_str_eq(str1, str2);
  }
}
END_TEST

START_TEST(s21_sprintf_o_test) {
  for (int i = 0; i < TEST_CASE_COUNT; i++) {
    char str1[M_length];
    char str2[M_length];
    s21_sprintf(str1, sprintf_tc_o[i].format, sprintf_tc_o[i].o);
    sprintf(str2, sprintf_tc_o[i].format, sprintf_tc_o[i].o);
    ck_assert_str_eq(str1, str2);
  }
}
END_TEST

START_TEST(s21_sprintf_s_test) {
  for (int i = 0; i < TEST_CASE_COUNT; i++) {
    char str1[M_length];
    char str2[M_length];
    s21_sprintf(str1, sprintf_tc_s[i].format, sprintf_tc_s[i].str);
    sprintf(str2, sprintf_tc_s[i].format, sprintf_tc_s[i].str);
    ck_assert_str_eq(str1, str2);
  }
}
END_TEST

START_TEST(s21_sprintf_u_test) {
  for (int i = 0; i < TEST_CASE_COUNT; i++) {
    char str1[M_length];
    char str2[M_length];
    s21_sprintf(str1, sprintf_tc_u[i].format, sprintf_tc_u[i].u);
    sprintf(str2, sprintf_tc_u[i].format, sprintf_tc_u[i].u);
    ck_assert_str_eq(str1, str2);
  }
}
END_TEST

START_TEST(s21_sprintf_x_test) {
  for (int i = 0; i < TEST_CASE_COUNT; i++) {
    char str1[M_length];
    char str2[M_length];
    s21_sprintf(str1, sprintf_tc_x[i].format, sprintf_tc_x[i].x);
    sprintf(str2, sprintf_tc_x[i].format, sprintf_tc_x[i].x);
    ck_assert_str_eq(str1, str2);
  }
}
END_TEST

START_TEST(s21_sprintf_X_test) {
  for (int i = 0; i < TEST_CASE_COUNT; i++) {
    char str1[M_length];
    char str2[M_length];
    s21_sprintf(str1, sprintf_tc_X[i].format, sprintf_tc_X[i].X);
    sprintf(str2, sprintf_tc_X[i].format, sprintf_tc_X[i].X);
    ck_assert_str_eq(str1, str2);
  }
}
END_TEST

START_TEST(s21_sprintf_p_test) {
  for (int i = 0; i < TEST_CASE_COUNT; i++) {
    char str1[M_length];
    char str2[M_length];
    s21_sprintf(str1, sprintf_tc_p[i].format, sprintf_tc_p[i].str);
    sprintf(str2, sprintf_tc_p[i].format, sprintf_tc_p[i].str);
    ck_assert_str_eq(str1, str2);
  }
}
END_TEST

START_TEST(s21_sprintf_pc_test) {
  for (int i = 0; i < TEST_CASE_COUNT; i++) {
    char str1[M_length];
    char str2[M_length];
    s21_sprintf(str1, sprintf_tc_pc[i].format, sprintf_tc_pc[i].str);
    sprintf(str2, sprintf_tc_pc[i].format, sprintf_tc_pc[i].str);
    ck_assert_str_eq(str1, str2);
  }
}
END_TEST

START_TEST(string_sprintf_s) {
  char actual[STR_SIZE] = "";
  char expected[STR_SIZE] = "";
  if (s_tests[_i].n == 0) {
    s21_sprintf(actual, s_tests[_i].format, s_tests[_i].data);
    sprintf(expected, s_tests[_i].format, s_tests[_i].data);
  } else {
    s21_sprintf(actual, s_tests[_i].format, s_tests[_i].n, s_tests[_i].data);
    sprintf(expected, s_tests[_i].format, s_tests[_i].n, s_tests[_i].data);
  }
  ck_assert_str_eq(actual, expected);
}
END_TEST

START_TEST(string_sprintf_c) {
  char actual[STR_SIZE] = "";
  char expected[STR_SIZE] = "";
  if (s_tests[_i].n == 0) {
    s21_sprintf(actual, s_tests[_i].format, s_tests[_i].data);
    sprintf(expected, s_tests[_i].format, s_tests[_i].data);
  } else {
    s21_sprintf(actual, s_tests[_i].format, s_tests[_i].n, s_tests[_i].data);
    sprintf(expected, s_tests[_i].format, s_tests[_i].n, s_tests[_i].data);
  }
  ck_assert_str_eq(actual, expected);
}
END_TEST

START_TEST(string_sprintf_d) {
  char actual[STR_SIZE] = "";
  char expected[STR_SIZE] = "";
  if (d_tests[_i].n == 0) {
    s21_sprintf(actual, d_tests[_i].format, d_tests[_i].data);
    sprintf(expected, d_tests[_i].format, d_tests[_i].data);
  } else {
    s21_sprintf(actual, d_tests[_i].format, d_tests[_i].n, d_tests[_i].data);
    sprintf(expected, d_tests[_i].format, d_tests[_i].n, d_tests[_i].data);
  }
  ck_assert_str_eq(actual, expected);
}
END_TEST

START_TEST(string_sprintf_o) {
  char actual[STR_SIZE] = "";
  char expected[STR_SIZE] = "";
  if (o_tests[_i].n == 0) {
    s21_sprintf(actual, o_tests[_i].format, o_tests[_i].data);
    sprintf(expected, o_tests[_i].format, o_tests[_i].data);
  } else {
    s21_sprintf(actual, o_tests[_i].format, o_tests[_i].n, o_tests[_i].data);
    sprintf(expected, o_tests[_i].format, o_tests[_i].n, o_tests[_i].data);
  }
  ck_assert_str_eq(actual, expected);
}
END_TEST

START_TEST(string_sprintf_x) {
  char actual[STR_SIZE] = "";
  char expected[STR_SIZE] = "";
  if (x_tests[_i].n == 0) {
    s21_sprintf(actual, x_tests[_i].format, x_tests[_i].data);
    sprintf(expected, x_tests[_i].format, x_tests[_i].data);
  } else {
    s21_sprintf(actual, x_tests[_i].format, x_tests[_i].n, x_tests[_i].data);
    sprintf(expected, x_tests[_i].format, x_tests[_i].n, x_tests[_i].data);
  }
  ck_assert_str_eq(actual, expected);
}
END_TEST

START_TEST(string_sprintf_f) {
  char actual[STR_SIZE] = "";
  char expected[STR_SIZE] = "";
  if (f_tests[_i].n == 0) {
    s21_sprintf(actual, f_tests[_i].format, f_tests[_i].data);
    sprintf(expected, f_tests[_i].format, f_tests[_i].data);
  } else {
    s21_sprintf(actual, f_tests[_i].format, f_tests[_i].n, f_tests[_i].data);
    sprintf(expected, f_tests[_i].format, f_tests[_i].n, f_tests[_i].data);
  }
  ck_assert_str_eq(actual, expected);
}
END_TEST

START_TEST(string_sprintf_u) {
  char actual[STR_SIZE] = "";
  char expected[STR_SIZE] = "";
  if (u_tests[_i].n == 0) {
    s21_sprintf(actual, u_tests[_i].format, u_tests[_i].data);
    sprintf(expected, u_tests[_i].format, u_tests[_i].data);
  } else {
    s21_sprintf(actual, u_tests[_i].format, u_tests[_i].n, u_tests[_i].data);
    sprintf(expected, u_tests[_i].format, u_tests[_i].n, u_tests[_i].data);
  }
  ck_assert_str_eq(actual, expected);
}
END_TEST

START_TEST(string_sprintf_e) {
  char actual[STR_SIZE] = "";
  char expected[STR_SIZE] = "";
  if (e_tests[_i].n == 0) {
    s21_sprintf(actual, e_tests[_i].format, e_tests[_i].data);
    sprintf(expected, e_tests[_i].format, e_tests[_i].data);
  } else {
    s21_sprintf(actual, e_tests[_i].format, e_tests[_i].n, e_tests[_i].data);
    sprintf(expected, e_tests[_i].format, e_tests[_i].n, e_tests[_i].data);
  }
  ck_assert_str_eq(actual, expected);
}
END_TEST

START_TEST(string_sprintf_g) {
  char actual[STR_SIZE] = "";
  char expected[STR_SIZE] = "";
  if (g_tests[_i].n == 0) {
    s21_sprintf(actual, g_tests[_i].format, g_tests[_i].data);
    sprintf(expected, g_tests[_i].format, g_tests[_i].data);
  } else {
    s21_sprintf(actual, g_tests[_i].format, g_tests[_i].n, g_tests[_i].data);
    sprintf(expected, g_tests[_i].format, g_tests[_i].n, g_tests[_i].data);
  }
  ck_assert_str_eq(actual, expected);
}
END_TEST

START_TEST(string_sprintf_p) {
  char actual[STR_SIZE] = "";
  char expected[STR_SIZE] = "";
  if (p_tests[_i].n == 0) {
    s21_sprintf(actual, p_tests[_i].format, p_tests[_i].data);
    sprintf(expected, p_tests[_i].format, p_tests[_i].data);
  } else {
    s21_sprintf(actual, p_tests[_i].format, p_tests[_i].n, p_tests[_i].data);
    sprintf(expected, p_tests[_i].format, p_tests[_i].n, p_tests[_i].data);
  }
  ck_assert_str_eq(actual, expected);
}
END_TEST

struct n_test_data {
  char *data;
  char *format;
  int n;
} n_tests[] = {{"20lvl Insane people", "%s%n", 0}};

START_TEST(string_sprintf_n) {
  char actual[STR_SIZE] = "";
  char expected[STR_SIZE] = "";
  s21_sprintf(actual, n_tests[_i].format, n_tests[_i].data, &n_tests[_i].n);
  sprintf(expected, n_tests[_i].format, n_tests[_i].data, &n_tests[_i].n);
  ck_assert_str_eq(actual, expected);
}
END_TEST

START_TEST(s21_sscanf_test1) {
  char c = '\0';
  int d = 0;
  long int ld = 0;
  long long Ld = 0;
  int i = 0;
  long li = 0;
  float e = 0;
  float E = 0;
  long double LE = 0;
  double lf = 0;
  unsigned short ho = 0;
  unsigned int o = 0;
  unsigned long lo = 0;
  unsigned long long Lo = 0;
  char s[M_length];
  unsigned long lu = 0;
  void **p = NULL;
  int n = 0;

  char c2 = '\0';
  int d2 = 0;
  long int ld2 = 0;
  long long Ld2 = 0;
  int i2 = 0;
  long li2 = 0;
  float e2 = 0;
  float E2 = 0;
  long double LE2 = 0;
  double lf2 = 0;
  unsigned short ho2 = 0;
  unsigned int o2 = 0;
  unsigned long lo2 = 0;
  unsigned long long Lo2 = 0;
  char s2[M_length];
  unsigned long lu2 = 0;
  void **p2 = NULL;
  int n2 = 0;

  s21_sscanf("2342", "%*c %*c %c", &c);
  sscanf("2342", "%*c %*c %c", &c2);
  ck_assert_int_eq(c, c2);

  s21_sscanf("213123123", "%*c %*c %%c", &c);
  sscanf("213123123", "%*c %*c %c", &c2);
  ck_assert_int_eq(c, c2);

  s21_sscanf("213123123", "%*c %*c %*c %c", &c);
  sscanf("213123123", "%*c %*c %*c %c", &c2);
  ck_assert_int_eq(c, c2);

  s21_sscanf("2131asdasdas3123", "%*c %*c %*c %c %3s", &c, &s[0]);
  sscanf("2131asdasdas3123", "%*c %*c %*c %c %3s", &c2, &s2[0]);
  ck_assert_int_eq(c, c2);
  ck_assert_str_eq(s, s2);

  s21_sscanf("Dima_234", "%*c %*c %*c %*c %*s");
  sscanf("Dima_234", "%*c %*c %*c %*c %*s");
  s21_sscanf("Dima_234", "%4s %c %ld", &s[0], &c, &ld);
  sscanf("Dima_234", "%4s %c %ld", &s2[0], &c2, &ld2);
  ck_assert_int_eq(c, c2);
  ck_assert_int_eq(ld, ld2);

  s21_sscanf("2345612345", "%4s %ld", &s[0], &ld);
  sscanf("2345612345", "%4s %ld", &s2[0], &ld2);
  ck_assert_int_eq(ld, ld2);
  ck_assert_str_eq(s, s2);

  s21_sscanf("2345612345asd", "%*s %Ld", &Ld);
  sscanf("2345612345asdassad", "%*s %lld", &Ld2);
  ck_assert_int_eq(Ld, Ld2);

  s21_sscanf("2345612345asd", "%3d %n %3lo %li %3s", &d, &n, &lo, &li, &s[0]);
  sscanf("2345612345asd", "%3d %n %3lo %li %3s", &d2, &n2, &lo2, &li2, &s2[0]);
  ck_assert_int_eq(d, d2);
  ck_assert_int_eq(n, n2);
  ck_assert_int_eq(lo, lo2);
  ck_assert_int_eq(li, li2);
  ck_assert_str_eq(s, s2);

  s21_sscanf("\n\nSchool-21F", "%8s %3e %i", &s[0], &e, &i);
  sscanf("\n\nSchool-21F", "%8s %3e %i", &s2[0], &e2, &i2);
  ck_assert_str_eq(s, s2);
  ck_assert_int_eq(e, e2);
  ck_assert_int_eq(i, i2);

  s21_sscanf("\n\nSchool-21F  -s  0x12345A", "%c %*s %2s %p", &c, &s[0], &p);
  sscanf("\n\nSchool-21F  -s  0x12345A", "%c %*s %2s %p", &c2, &s2[0], &p2);
  ck_assert_int_eq(c, c2);
  ck_assert_str_eq(s, s2);
  ck_assert_ptr_eq(p, p2);

  s21_sscanf("123 0456sdsf", "%ld %4i %4s", &ld, &i, &s[0]);
  sscanf("123 0456sdsf", "%ld %4i %4s", &ld2, &i2, &s2[0]);
  ck_assert_int_eq(ld, ld2);
  ck_assert_int_eq(i, i2);
  ck_assert_str_eq(s, s2);

  s21_sscanf("-93240000 0456sdsfadsa44", "%9ld %4i %9s", &ld, &i, &s[0]);
  sscanf("-93240000 0456sdsfadsa44", "%9ld %4i %9s", &ld2, &i2, &s2[0]);
  ck_assert_int_eq(ld, ld2);
  ck_assert_int_eq(i, i2);
  ck_assert_str_eq(s, s2);

  s21_sscanf("-93240000 0456sdsfadsa44", "%9Ld %4o %9s", &Ld, &o, &s[0]);
  sscanf("-93240000 0456sdsfadsa44", "%9lld %4o %9s", &Ld2, &o2, &s2[0]);
  ck_assert_str_eq(s, s2);
  ck_assert_int_eq(o, o2);
  ck_assert_int_eq(Ld, Ld2);

  s21_sscanf("123E1 456 sdsfadsa44", "%5E %o %9s", &E, &o, &s[0]);
  sscanf("123E1 456 sdsfadsa44", "%5E %o %9s", &E2, &o2, &s2[0]);
  ck_assert_str_eq(s, s2);
  ck_assert_int_eq(o, o2);
  ck_assert_int_eq(E, E2);

  s21_sscanf("-12351 456 sdsfadsa44", "%lu %o %3s %*s", &lu, &o, &s[0]);
  sscanf("-12351 456 sdsfadsa44", "%lu %o %3s %*s", &lu2, &o2, &s2[0]);
  ck_assert_str_eq(s, s2);
  ck_assert_int_eq(o, o2);
  ck_assert_int_eq(lu, lu2);

  s21_sscanf("-12351.456 2e5 1.234", "%ld %*E %lf %*s", &ld, &lf);
  sscanf("-12351.456 2e5 1.234", "%ld %*E %lf %*s", &ld2, &lf2);
  ck_assert_int_eq(ld, ld2);
  ck_assert_int_eq(lf, lf2);

  s21_sscanf("0xF123 2e5 04563 ", "%*x %*E %llo %*s", &Lo);
  sscanf("0xF123 2e5 04563", "%*x %*E %llo %*s", &Lo2);
  ck_assert_int_eq(Lo, Lo2);

  s21_sscanf("-3e3 -034567", "%4LE %4Lo %*s", &LE, &Lo);
  sscanf("-3e3 -034567", "%4LE %4llo %*s", &LE2, &Lo2);
  ck_assert_int_eq(LE, LE2);
  ck_assert_int_eq(Lo, Lo2);

  s21_sscanf("-3e3 -034567", "%4LE %4ho %*s", &LE, &ho);
  sscanf("-3e3 -034567", "%4LE %4ho %*s", &LE2, &ho2);
  ck_assert_int_eq(LE, LE2);
  ck_assert_int_eq(ho, ho2);

  s21_sscanf("432e3 -034567", "%5LE %4ho %*c %3s", &LE, &ho, &s[0]);
  sscanf("432e3 -034567", "%5LE %4ho %*c %3s", &LE2, &ho2, &s2[0]);
  ck_assert_int_eq(LE, LE2);
  ck_assert_int_eq(ho, ho2);
  ck_assert_str_eq(s, s2);
}
END_TEST

Suite *s21_stringp(void) {
  Suite *s;
  TCase *tc_core;
  s = suite_create("s21_string");
  tc_core = tcase_create("CORE");
  tcase_add_test(tc_core, s21_memchr_test);
  tcase_add_test(tc_core, s21_memcmp_test);
  tcase_add_test(tc_core, s21_memcpy_test);
  tcase_add_test(tc_core, s21_memmove_test);
  tcase_add_test(tc_core, s21_memset_test);
  tcase_add_test(tc_core, s21_strcat_test);
  tcase_add_test(tc_core, s21_strncat_test);
  tcase_add_test(tc_core, s21_strchr_test);
  tcase_add_test(tc_core, s21_strcmp_test);
  tcase_add_test(tc_core, s21_strncmp_test);
  tcase_add_test(tc_core, s21_strcpy_test);
  tcase_add_test(tc_core, s21_strncpy_test);
  tcase_add_test(tc_core, s21_strcspn_test);
  tcase_add_test(tc_core, s21_strerror_test);
  tcase_add_test(tc_core, s21_strlen_test);
  tcase_add_test(tc_core, s21_strpbrk_test);
  tcase_add_test(tc_core, s21_strrchr_test);
  tcase_add_test(tc_core, s21_strspn_test);
  tcase_add_test(tc_core, s21_strstr_test);
  tcase_add_test(tc_core, s21_strtok_test);
  tcase_add_test(tc_core, s21_to_upper_test);
  tcase_add_test(tc_core, s21_to_lower_test);
  tcase_add_test(tc_core, s21_insert_test);
  tcase_add_test(tc_core, s21_trim_test);
  tcase_add_test(tc_core, s21_sprintf_c_test);
  tcase_add_test(tc_core, s21_sprintf_d_test);
  tcase_add_test(tc_core, s21_sprintf_i_test);
  tcase_add_test(tc_core, s21_sprintf_e_test);
  tcase_add_test(tc_core, s21_sprintf_E_test);
  tcase_add_test(tc_core, s21_sprintf_f_test);
  tcase_add_test(tc_core, s21_sprintf_g_test);
  tcase_add_test(tc_core, s21_sprintf_G_test);
  tcase_add_test(tc_core, s21_sprintf_o_test);
  tcase_add_test(tc_core, s21_sprintf_s_test);
  tcase_add_test(tc_core, s21_sprintf_u_test);
  tcase_add_test(tc_core, s21_sprintf_x_test);
  tcase_add_test(tc_core, s21_sprintf_X_test);
  tcase_add_test(tc_core, s21_sprintf_p_test);
  tcase_add_test(tc_core, s21_sprintf_pc_test);
  tcase_add_test(tc_core, s21_sscanf_test1);

  TCase *test_case_s = tcase_create("test case %%s");
  tcase_add_loop_test(test_case_s, string_sprintf_s, 0,
                      sizeof(s_tests) / sizeof(s_tests[0]));
  suite_add_tcase(s, test_case_s);

  TCase *test_case_c = tcase_create("test case %%c");
  tcase_add_loop_test(test_case_c, string_sprintf_c, 0,
                      sizeof(c_tests) / sizeof(c_tests[0]));
  suite_add_tcase(s, test_case_c);

  TCase *test_case_d = tcase_create("test case %%d");
  tcase_add_loop_test(test_case_d, string_sprintf_d, 0,
                      sizeof(d_tests) / sizeof(d_tests[0]));
  suite_add_tcase(s, test_case_d);

  TCase *test_case_o = tcase_create("test case %%o");
  tcase_add_loop_test(test_case_o, string_sprintf_o, 0,
                      sizeof(o_tests) / sizeof(o_tests[0]));
  suite_add_tcase(s, test_case_o);

  TCase *test_case_x = tcase_create("test case %%x");
  tcase_add_loop_test(test_case_x, string_sprintf_x, 0,
                      sizeof(x_tests) / sizeof(x_tests[0]));
  suite_add_tcase(s, test_case_x);

  TCase *test_case_f = tcase_create("test case %%f");
  tcase_add_loop_test(test_case_f, string_sprintf_f, 0,
                      sizeof(f_tests) / sizeof(f_tests[0]));
  suite_add_tcase(s, test_case_f);

  TCase *test_case_u = tcase_create("test case %%u");
  tcase_add_loop_test(test_case_u, string_sprintf_u, 0,
                      sizeof(u_tests) / sizeof(u_tests[0]));
  suite_add_tcase(s, test_case_u);

  TCase *test_case_e = tcase_create("test case %%e");
  tcase_add_loop_test(test_case_e, string_sprintf_e, 0,
                      sizeof(e_tests) / sizeof(e_tests[0]));
  suite_add_tcase(s, test_case_e);

  TCase *test_case_g = tcase_create("test case %%g");
  tcase_add_loop_test(test_case_g, string_sprintf_g, 0,
                      sizeof(g_tests) / sizeof(g_tests[0]));
  suite_add_tcase(s, test_case_g);

  TCase *test_case_p = tcase_create("test case %%p");
  tcase_add_loop_test(test_case_p, string_sprintf_p, 0,
                      sizeof(p_tests) / sizeof(p_tests[0]));
  suite_add_tcase(s, test_case_p);

  TCase *test_case_n = tcase_create("test case %%n");
  tcase_add_loop_test(test_case_n, string_sprintf_n, 0,
                      sizeof(n_tests) / sizeof(n_tests[0]));
  suite_add_tcase(s, test_case_n);

  suite_add_tcase(s, tc_core);
  return s;
}

int main(void) {
  int number_failed;
  Suite *s;
  SRunner *sr;
  s = s21_stringp();
  sr = srunner_create(s);
  srunner_run_all(sr, CK_VERBOSE);
  number_failed = srunner_ntests_failed(sr);
  srunner_free(sr);
  return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
