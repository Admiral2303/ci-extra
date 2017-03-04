#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>
#include <assert.h>

#include <ci.h>

struct Teacher{
    Student_List * head;
};


struct ListNode{
    Student * data;
    struct ListNode * next;
};

struct Student_List{
  struct ListNode * head;
};

struct Student{
    char name[20];
    char surname[20];
    int score;
};


char * getname_from_list(Student_List * self){
    return self->head->data->name;
}
char * getsurname_from_list(Student_List * self){
    return self->head->data->surname;
}
int getscore_from_list(Student_List * self){
    return self->head->data->score;
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




Student_List* create_newList_from_teacher(Teacher *self, Student_List * data){
    Student_List * new_List = List_new();
    Student_List * cur = self->head;
    ListNode * curr =  data->head;
    while (curr != NULL){
        if(ListNode_compare(cur,curr) == 1){
            List_addFirst(new_List, curr->data);
        }
        curr = curr->next;
    }
    return new_List;
}


int ListNode_compare(Student_List * self, ListNode * self1){
    ListNode * cur =  self->head;
    int flag = 0;
    while(cur != NULL){
        if(strcmp(cur->data->name, self1->data->name) == 0 && strcmp(cur->data->surname, self1->data->surname) == 0
        && cur->data->score == self1->data->score){
            flag = 1;
        }
        cur = cur->next;
    }
    if(flag == 1){
        return 0;
    }
    else{
        return 1;
    }
}



void attachment_students_to_teacher(Teacher * self, Student_List * head){
    self->head = head;
}

 Student_List * nuy(Teacher* self){
    return self->head;
}



void print(Student_List * self){
    ListNode * cur = self->head;
    while(cur != NULL){
        printf("\n%s\n", cur->data->name);
        printf("%s\n", cur->data->surname);
        printf("%i\n",cur->data->score);
        cur = cur->next;
    }
}

void print1(Student * self){
    printf("%s", self->name);
    printf("%s", self->surname);
    printf("%i", self->score);
}



void str_to_list(Student_List * self, char * str){
    char surname[20];
    char name[20];
    int score = 0;
    int flag = 0;
    int k = 0;
    int flag1 = 0;
        for(int i = 0; i < strlen(str); i++){
            if(str[i] == ',' && flag == 0){
                int start = 0;
                for(int j = i-k; j < i; j++, start++){
                    name[start] = str[j];
                }
                name[start] = '\0';
                k=0;
                flag = 1;
                i++;
            }
            if(str[i] == ',' && flag == 1){
                int start = 0;
                surname[0] = '\0';
                for(int j = i - k; j < i; j++, start++){
                    surname[start] = str[j];
                }
                surname[start] = '\0';
                k=0;
                flag = 2;
                i++;
            }
            if(str[i] == '\n' && flag == 2){
                int start = 0;
                char score1 [20];
                score1[0] = '\0';
                for(int j = i - k; j < i; j++, start++){
                    score1[start] = str[j];
                }
                score1[start] = '\0';
                score = atoi(score1);
                k=0;
                flag = 0;
                flag1 = 1;
                i++;

            }
            if(!isspace(str[i]) || !ispunct(str[i])){
                k++;
            }
            if(flag1 == 1){
                Student * student = new_stud(name,surname,score);
                List_addFirst(self,student);
                flag1 = 0;
            }
        }
    }


void Student_free(Student ** self){
  assert(NULL != self);
  free(*self);
  *self = NULL;
}




char * str_from_List(Student_List * self){
    char * str;
    str = (char *)malloc(500 * sizeof(char) );
    ListNode * cur = self->head;
    while(cur != NULL){
        char * student_string;
        student_string = str_from_struct(cur->data);
        strcat(str,student_string);
        cur = cur->next;
    }
    return str;
}

char * str_from_struct(Student * self){
    char * str;
    str = (char *)malloc(500 * sizeof(char) );
    sprintf(str,"%s,%s,%i\n", self->name, self->surname, self->score);
    return str;
}


Student * new_stud(char * name, char * surname, int score){
        Student * student = Student_new();
        strcpy(student->name,name);
        strcpy(student->surname,surname);
        student->score = score;
        return student;
}






Teacher * Teacher_new(Student_List * head){
    struct Teacher * self = (struct Teacher *)malloc(sizeof(struct Teacher));
    //strcpy(self->name, "\0");
    self->head = head;
    return self;
}



Student * Student_new(){
    struct Student * cur = (struct Student *)malloc(sizeof(struct Student));
    strcpy(cur->name, "\0");
    strcpy(cur->surname, "\0");
    cur->score = 0;
    return cur;
}




struct ListNode * ListNode_new(Student * data) {
  struct ListNode * node = (struct ListNode *)malloc(sizeof(struct ListNode));
  node->next = NULL;
  node->data = data;
  return node;
}


struct Student_List * List_new(void) {
  struct Student_List * list = (struct Student_List *)malloc(sizeof(struct Student_List));
  list->head = NULL;
  return list;
}


void List_addFirst(struct Student_List * self, Student * data) {
  struct ListNode * node = ListNode_new(data);
  node->next = self->head;
  self->head = node;
}

void List_addLast(struct Student_List * self, Student * data) {
  struct ListNode * node = ListNode_new(data);
  if (self->head == NULL) {
    self->head = node;
    return;
  }
  struct ListNode * cur = self->head;
  while (cur->next != NULL) {
    cur = cur->next;
  }
  cur->next = node;
}



ListNode * ListNode_removeFirst(Student_List * self) {
    assert(self->head != NULL);
    struct ListNode * node = self->head;
    self->head = node->next;
    ListNode_free(&node);
    return self->head;
}





void ListNode_free(ListNode ** self){
    assert(NULL != self);
    free(*self);
    *self = NULL;
}

int Student_List_count(Student_List * self){
    ListNode * cur = self->head;
    int count = 0;
    while(cur != NULL){
        count++;
        cur = cur->next;
    }
    return count;
}


void delete_Student(Student_List * self){
     int size = Student_List_count(self);
     ListNode * cur = self->head;
     
     for(int i = 0; i < size; i++){
         Student * curr = cur->data;
         Student_free(&curr);
         cur = cur->next;
     }
}




void Student_List_cleanList(Student_List * self){
    int size = Student_List_count(self);
    for(int i = 0; i < size; i++){
        ListNode * curr = self->head;
        if(curr == NULL) return;
        if(curr->next == NULL){
            ListNode_free(&curr);
            self->head = NULL;
            return;
        } 
        while(curr->next->next != NULL){
            curr = curr->next;
        }
        ListNode_free(&(curr->next));
        curr->next = NULL;
    }
    Student_List_free(&self);
    
}

void Student_List_free(Student_List ** self){
    free(*self);
    *self = NULL;
}
