#ifndef LIST_H
#define LIST_H




typedef struct ListNode ListNode;
typedef struct Student_List Student_List;
typedef struct Teacher Teacher;




struct ListNode * ListNode_new(void * data);
struct Student_List * List_new(void);
void List_addLast(Student_List * self, void * data);
void ListNode_free(ListNode ** self);
int Student_List_count(Student_List * self);
void Student_List_cleanList(Student_List * self);
void Student_List_free(Student_List ** self);
ListNode * List_elementAt(Student_List * self, int position);
int ListNode_compare(Student_List * self, ListNode * self1);
void * List_get(ListNode * self);
void * List_get_head(Student_List * self);
void delete_Student(Student_List * self);
void * ListNode_next(ListNode * self);


Student_List* create_newList_from_teacher(Teacher *self, Student_List * data);
void attachment_students_to_teacher(Teacher * self, Student_List * head);
Teacher * Teacher_new(void);
void Teacher_free(Teacher ** self);
void * get_List_from_teacher(Teacher * self);


#endif