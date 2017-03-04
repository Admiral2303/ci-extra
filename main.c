
#include <stdio.h>
#include <stdlib.h>

#include <check.h>
#include <ci.h>

START_TEST (test_sample)
{
    Student * st = Student_new();
    Student_free(&st);
}
END_TEST

START_TEST(test_str_to_list){
  Student_List * self = List_new();
  char str[100] = {"dddd,ff,5\n"};
  str_to_list(self,str);
  char * str1 = getname_from_list(self);
  ck_assert_str_eq("dddd", str1);
  char *str2 = getsurname_from_list(self);
  ck_assert_str_eq("ff", str2);
  int score = getscore_from_list(self);
  ck_assert_int_eq(5,score);
  self = NULL;
  ck_assert_ptr_eq(NULL, self); 
}
END_TEST


Suite *test_suite() {
  Suite *s = suite_create("Module");
  TCase *tc_sample = tcase_create("TestCase");
  tcase_add_test(tc_sample, test_sample);
  TCase *test_str_tolist = tcase_create("TestCase");
  tcase_add_test(test_str_tolist, test_str_to_list);

  suite_add_tcase(s, tc_sample);
  suite_add_tcase(s, test_str_tolist);
  return s;
}

int main() {
  Suite *s = test_suite();
  SRunner *sr = srunner_create(s);
  srunner_set_fork_status(sr, CK_NOFORK);  // important for debugging!

  srunner_run_all(sr, CK_VERBOSE);

  int num_tests_failed = srunner_ntests_failed(sr);
  srunner_free(sr);
  return num_tests_failed;
}
