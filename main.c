
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
  char *str2 = getsurname_from_list(self);
  int score = getscore_from_list(self);
  
  ck_assert_str_eq("dddd", str1);  
  ck_assert_str_eq("ff", str2);
  ck_assert_int_eq(5,score);
}                         
END_TEST

START_TEST(delete_list){
  Student_List * self = List_new();
  char str[100] = {"dddd,ff,5\ndd,tt,5\n"};
  str_to_list(self,str);
  delete_Student(self);
  Student_List_cleanList(self);
  //ck_assert_ptr_eq(NULL, self);
}
END_TEST
START_TEST(create_student){
  Student * self = new_stud("dddd","ff",5);
  ck_assert_str_eq("dddd", getname_from_struct(self));
  ck_assert_str_eq("ff", getsurname_from_struct(self));
  ck_assert_int_eq(5, getscore_from_struct(self));
  Student * self1 = new_stud("","",0);
  ck_assert_str_eq("", getname_from_struct(self1));
  ck_assert_str_eq("", getsurname_from_struct(self1));
  ck_assert_int_eq(0, getscore_from_struct(self1));
  Student_free(&self);
  Student_free(&self1);
}
END_TEST

/*START_TEST(new_listnode){

}
END_TEST*/

START_TEST(list_compare){
  Student_List * self = List_new();
  ListNode * self1 = ListNode_new(new_stud("dddd","ff",5));
  ListNode * self2 = ListNode_new(new_stud("qq","ff",5)); 
  ListNode * self3 = ListNode_new(new_stud("dddd","qqq",5));  
  ListNode * self4 = ListNode_new(new_stud("aaa","ff",7));  
  char str[100] = {"dddd,ff,5\ndd,tt,5\n"};
  
  str_to_list(self,str);
  ck_assert_int_eq(0,  ListNode_compare(self,self1));
  ck_assert_int_eq(1,  ListNode_compare(self,self2));
  ck_assert_int_eq(1,  ListNode_compare(self,self3));
  ck_assert_int_eq(1,  ListNode_compare(self,self4));
  delete_Student(self);
  Student_List_cleanList(self);
}
END_TEST



Suite *test_suite() {
  Suite *s = suite_create("Module");
  TCase *tc_sample = tcase_create("TestCase");
  tcase_add_test(tc_sample, test_sample);
  TCase *test_str_tolist = tcase_create("TestCase");
  tcase_add_test(test_str_tolist, test_str_to_list);
  TCase *clear_list = tcase_create("TestCase");
  tcase_add_test(clear_list, delete_list);
  TCase *listel_compare = tcase_create("TestCase");
  tcase_add_test(clear_list, list_compare);
  TCase *student_create = tcase_create("TestCase");
  tcase_add_test(student_create,create_student);


  suite_add_tcase(s, student_create);
  suite_add_tcase(s, listel_compare);
  suite_add_tcase(s, clear_list);
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
