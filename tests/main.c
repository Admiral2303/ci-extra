
#include <stdio.h>
#include <stdlib.h>

#include <check.h>
#include "list.h"
#include "csv.h"
#include "student.h"


START_TEST(test_str_to_list){
  Student_List * self = List_new();
  char str[100] = {"dima,levchenko,4\nvadim,scherbina,5\n"};
  str_to_list(self,str);

  char * name = getname_from_struct(List_get(List_elementAt(self, 0)));
  char * surname = getsurname_from_struct(List_get(List_elementAt(self, 0)));
  int score = getscore_from_struct(List_get(List_elementAt(self, 0)));
  char * name1 = getname_from_struct(List_get(List_elementAt(self, 1)));
  char * surname1 = getsurname_from_struct(List_get(List_elementAt(self, 1)));
  int score1 = getscore_from_struct(List_get(List_elementAt(self, 1)));


  ck_assert_int_eq(4, score);
  ck_assert_str_eq("dima", name);
  ck_assert_str_eq("levchenko", surname);

  ck_assert_int_eq(5, score1);
  ck_assert_str_eq("vadim", name1);
  ck_assert_str_eq("scherbina", surname1);

  
}                         
END_TEST


START_TEST(strtolist_emptylist)
{
    char str[] = "";
    char str2[] = "Ivan, Savchenko";
    Student_List * list = List_new();
    str_to_list(list,str);
    ck_assert_int_eq(Student_List_count(list), 0);
    delete_Student(list);
    Student_List_cleanList(list);;
    Student_List * list1 = List_new();
    str_to_list(list1,str2);
    ck_assert_int_eq(Student_List_count(list1), 0);
    delete_Student(list1);
    Student_List_cleanList(list1);    
}
END_TEST




START_TEST(create_student){
  Student * self = new_stud("dima","levchenko",5);
  ck_assert_str_eq("dima", getname_from_struct(self));
  ck_assert_str_eq("levchenko", getsurname_from_struct(self));
  ck_assert_int_eq(5, getscore_from_struct(self));

  Student * self1 = new_stud("","",0);
  ck_assert_str_eq("", getname_from_struct(self1));
  ck_assert_str_eq("", getsurname_from_struct(self1));
  ck_assert_int_eq(0, getscore_from_struct(self1));

  Student_free(&self);
  Student_free(&self1);
}
END_TEST


START_TEST(list_compare){
  Student_List * self = List_new();
  Student_List * list = List_new();
  ListNode * self1 = ListNode_new(new_stud("dima","levchenko",5));
  ListNode * self2 = ListNode_new(new_stud("qq","levchenko",5)); 
  ListNode * self3 = ListNode_new(new_stud("dima","savchenko",5));  
  ListNode * self4 = ListNode_new(new_stud("aaa","levchenko",7));  
  ListNode * self5 = ListNode_new(new_stud("","",0));  
  char str[100] = {"dima,levchenko,5\ndd,tt,5\n"};

  str_to_list(list,"");
  ck_assert_int_eq(1,  ListNode_compare(list,self5));
  str_to_list(self,str);
  ck_assert_int_eq(0,  ListNode_compare(self,self1));
  ck_assert_int_eq(1,  ListNode_compare(self,self2));
  ck_assert_int_eq(1,  ListNode_compare(self,self3));
  ck_assert_int_eq(1,  ListNode_compare(self,self4));
  delete_Student(self);
  Student_List_cleanList(self);
}
END_TEST


START_TEST(create_str_from_struct){
   Student * self = new_stud("dima","ff",5);
   Student * self1 = new_stud("","",0);  
   Student * self2 = new_stud("\t","\t",0);
    
   char * str = str_from_struct(self);
   char * str1 = str_from_struct(self1);
   char * str2 = str_from_struct(self2);
   
   ck_assert_str_eq(str, "dima,ff,5\n");
   ck_assert_str_eq(str1, ",,0\n");
   ck_assert_str_eq(str2, "\t,\t,0\n");
}
END_TEST

START_TEST(create_str_from_List){
  Student_List * self = List_new(); 
  Student_List * self1 = List_new(); 
  char str[100] = {"dima,levchenko,5\nvadim,scherbina,4\n"};
  str_to_list(self,str);
  char * str1 = str_from_List(self);  
  str_to_list(self,",,5\n,,4\n");
  char * str2 = str_from_List(self1);
  ck_assert_str_eq(str1, "dima,levchenko,5\nvadim,scherbina,4\n");
  ck_assert_str_eq(str2, "");
  delete_Student(self);
  Student_List_cleanList(self);
  delete_Student(self1);
  Student_List_cleanList(self1);
}
END_TEST




START_TEST(add_students_to_teacher){
  Teacher * self = Teacher_new();
  Teacher * self_empty_list = Teacher_new();
  Student_List * list = List_new();
  Student_List * list_empty = List_new();
  

  char str1[100] = {""};
  str_to_list(list_empty,str1);
  attachment_students_to_teacher(self_empty_list,list_empty);
  Student_List * list2 = get_List_from_teacher(self_empty_list);
  char * students1 = str_from_List(list2);
  


  char str[100] = {"dima,levchenko,5\nvadim,scherbina,4\n"};  
  str_to_list(list,str);
  attachment_students_to_teacher(self,list);
  Student_List * list1 = get_List_from_teacher(self);
  char * students = str_from_List(list1);


  ck_assert_str_eq(students1, "");
  ck_assert_str_eq(students, "dima,levchenko,5\nvadim,scherbina,4\n");
 
  delete_Student(list);
  Student_List_cleanList(list);
  delete_Student(list1);
  Student_List_cleanList(list1);
  Teacher_free(&self);
  Teacher_free(&self_empty_list);
  

}
END_TEST


START_TEST(new_list_from_teacher){
  Teacher * self = Teacher_new();
  Teacher * self_empty_list = Teacher_new();
  
  Student_List * list = List_new();
  Student_List * list1 = List_new();
  
  Student_List * list2 = List_new();
  Student_List * list3 = List_new();


  str_to_list(list,"dima,levchenko,5\nvadim,scherbina,4\n");
  attachment_students_to_teacher(self,list);
  str_to_list(list1,"dima,levchenko,5\nsasha,kopyl,5\n");
  
  str_to_list(list2,"dima,levchenko,5\nvadim,scherbina,4\n");
  attachment_students_to_teacher(self_empty_list,list2);
  str_to_list(list3,"dima,levchenko,5\nvadim,scherbina,4\n");

  Student_List * list_new = create_newList_from_teacher(self, list1);
  Student_List * list_new1 = create_newList_from_teacher(self_empty_list, list3);
   
  char * name = getname_from_struct(List_get(List_elementAt(list_new, 0)));
  char * surname = getsurname_from_struct(List_get(List_elementAt(list_new, 0)));
  int score = getscore_from_struct(List_get(List_elementAt(list_new, 0)));
  

  ck_assert_int_eq(5, score);
  ck_assert_str_eq("sasha", name);
  ck_assert_str_eq("kopyl", surname);
  int k = 0;
  if(list_new1 != NULL){
    k=1;
  }
  ck_assert_int_eq(0,k);


  delete_Student(list);
  Student_List_cleanList(list);
  delete_Student(list1);
  Student_List_cleanList(list1);
  delete_Student(list2);
  Student_List_cleanList(list2);
  delete_Student(list3);
  Student_List_cleanList(list3);
  
  Teacher_free(&self);
  Teacher_free(&self_empty_list);

}
END_TEST




Suite *test_suite() {
  Suite *s = suite_create("Module");
  TCase *test_str_tolist = tcase_create("TestCase");
  tcase_add_test(test_str_tolist, test_str_to_list);
  TCase *listel_compare = tcase_create("TestCase");
  tcase_add_test(listel_compare, list_compare);
  TCase *student_create = tcase_create("TestCase");
  tcase_add_test(student_create,create_student);
  TCase *str_from_struct = tcase_create("TestCase");
  tcase_add_test(str_from_struct,create_str_from_struct);
  TCase *list_to_str = tcase_create("TestCase");
  tcase_add_test(list_to_str,create_str_from_List);
  TCase *str_to_emptylist = tcase_create("TestCase");
  tcase_add_test(str_to_emptylist,strtolist_emptylist);
  TCase *add_stud_to_teacher = tcase_create("TestCase");
  tcase_add_test(add_stud_to_teacher,add_students_to_teacher);
  TCase *new_list_from_teach= tcase_create("TestCase");
  tcase_add_test(new_list_from_teach,new_list_from_teacher);





  suite_add_tcase(s, new_list_from_teach);
  suite_add_tcase(s, add_stud_to_teacher);
  suite_add_tcase(s, str_to_emptylist);
  suite_add_tcase(s, list_to_str);
  suite_add_tcase(s, str_from_struct);
  suite_add_tcase(s, student_create);
  suite_add_tcase(s, listel_compare);
  suite_add_tcase(s, test_str_tolist);
  return s;
}

int main() {
  Suite *s = test_suite();
  SRunner *sr = srunner_create(s);
  srunner_set_fork_status(sr, CK_NOFORK);  

  srunner_run_all(sr, CK_VERBOSE);

  int num_tests_failed = srunner_ntests_failed(sr);
  srunner_free(sr);
  return num_tests_failed;
}

