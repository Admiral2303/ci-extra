
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdio.h>
#include <assert.h>

#include "csv.h"
#include "list.h"
#include "student.h"


struct Student{
    char name[20];
    char surname[20];
    int score;
};



char * str_from_struct(Student * self){
    char * str;
    str = (char *)malloc(500 * sizeof(char) );
    str[0] = '\0';
    sprintf(str,"%s,%s,%i\n", self->name, self->surname, self->score);
    return str;
}




char * getname_from_struct(Student * self){
    return self->name;
}
char * getsurname_from_struct(Student * self){
    return self->surname;
}
int getscore_from_struct(Student * self){
    return self->score;
}


int ListNode_compare(Student_List * self, ListNode * self1){
    ListNode * cur =  List_get_head(self);
    int flag = 0;
    Student * curr1 = List_get(self1);
    int count = Student_List_count(self);
    int i = 0;
    while(count != i){
        Student * curr = List_get(cur);
        if(strcmp(curr->name, curr1->name) == 0 && strcmp(curr->surname, curr1->surname) == 0
        && curr->score == curr1->score){
            flag = 1;
        }
        i++;
    }
    if(flag == 1){
        return 0;
    }
    else{
        return 1;
    }
}






void Student_free(Student ** self){
  assert(NULL != self);
  free(*self);
  *self = NULL;
}


Student * new_stud(char * name, char * surname, int score){
        Student * student = Student_new();
        strcpy(student->name,name);
        strcpy(student->surname,surname);
        student->score = score;
        return student;
}



Student * Student_new(){
    struct Student * cur = (struct Student *)malloc(sizeof(struct Student));
    strcpy(cur->name, "\0");
    strcpy(cur->surname, "\0");
    cur->score = 0;
    return cur;
}
