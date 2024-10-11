#include <stdlib.h>
#include <check.h>
#include <stdio.h>
#include <neolog/neolog.h>
#include <neolib/hmap.h>

START_TEST(calc_hash)
{
    // Calculates hash
    size_t hash = _hash("key", 51);
    ck_assert_int_eq(29, hash);
}
END_TEST

Suite * hashtable_suite(void)
{
    Suite *s;
    TCase *tc_core;

    s = suite_create("hashtable");

    /* Core test case */
    tc_core = tcase_create("utils");

    tcase_add_test(tc_core, calc_hash);
    suite_add_tcase(s, tc_core);

    return s;
}

int main(void) {
    printf("Running test.\n");
    int number_failed;
    Suite *s;
    SRunner *sr;

    s = hashtable_suite();
    sr = srunner_create(s);

    srunner_run_all(sr, CK_NORMAL);
    number_failed = srunner_ntests_failed(sr);
    srunner_free(sr);
    return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;

    return 0;
}
