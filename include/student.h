#ifndef STUDENT_H
#define STUDENT_H


#include "list.h"

typedef struct Student Student;


char * getname_from_struct(Student * self);
char * getsurname_from_struct(Student * self);
int getscore_from_struct(Student * self);
int ListNode_compare(Student_List * self, ListNode * self1);
void Student_free(Student ** self);
Student * new_stud(char * name, char * surname, int score);
Student * Student_new();
char * str_from_struct(Student * self);


#endif