#ifndef TESTS_H
#define TESTS_H
#include <check.h>
#include <stdio.h>
#include <stdlib.h>

#include "../s21_matrix.h"

Suite *init_test();
Suite *add_test();
Suite *determ_test();
Suite *inverse_test();

Suite *all_test();


#endif