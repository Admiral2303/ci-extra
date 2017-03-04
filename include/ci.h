#ifndef LIST_H
#define LIST_H




typedef struct ListNode ListNode;
typedef struct Student_List Student_List;

typedef struct Student Student;
typedef struct Teacher Teacher;




void ListNode_free(ListNode ** self);
ListNode * ListNode_removeFirst(Student_List * self);
void List_addLast(struct Student_List * self, Student * data);
void List_addFirst(struct Student_List * self, Student * data);
struct Student_List * List_new(void);
struct ListNode * ListNode_new(Student * data);
void str_to_list(Student_List * self, char * str);
Student * Student_new();

void print(Student_List * self);

void print1(Student * self);

Student * new_stud(char * name, char * surname, int score);
char * str_from_List(Student_List * self);
char * str_from_struct(Student * self);
void attachment_students_to_teacher(Teacher * self, Student_List * head);
Teacher * Teacher_new(Student_List * head);

int ListNode_compare(Student_List * self, ListNode * self1);
Student_List* create_newList_from_teacher(Teacher *self, Student_List * data);


Student_List * nuy(Teacher* self);
void Student_free(Student ** self);

int Student_List_count(Student_List * self);
void Student_List_cleanList(Student_List * self);


void delete_Student(Student_List * self);

char * getname_from_list(Student_List * self);
char * getsurname_from_list(Student_List * self);
int getscore_from_list(Student_List * self);
char * getname_from_struct(Student * self);
char * getsurname_from_struct(Student * self);
int getscore_from_struct(Student * self);


void Student_List_free(Student_List ** self);


#endif
