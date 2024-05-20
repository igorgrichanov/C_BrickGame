#ifndef TEST_SUITES
#define TEST_SUITES

#include <check.h>
#include <unistd.h>

#include "..//model/backend.h"
#include "..//model/fsm.h"

Suite *tetris_backend_test_suite();
Suite *matrix_test_suite();
Suite *tetris_field_test_suite();
Suite *tetris_controller_test_suite();

void get_next_test(GameInfo_t *info, int i);
void fill_bottom_test(GameInfo_t *info);

#endif