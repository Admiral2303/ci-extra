#include <stdlib.h>
#include <assert.h>

#include <list.h>
#include <student.h>


#define throw(MSG) assert(0 && MSG);


struct ListNode{
    void * data;
    struct ListNode * next;
};

struct Student_List{
  struct ListNode * head;
};

struct Teacher{
    Student_List * head;
};





void * List_get(ListNode * self) {
    return self->data;
}
void * ListNode_next(ListNode * self){
    return self->next;
}

void * List_get_head(Student_List * self){
    return self->head;
}




Student_List* create_newList_from_teacher(Teacher *self, Student_List * data){
    Student_List * new_List = List_new();
    Student_List * cur = self->head;
    ListNode * curr =  data->head;
    while (curr != NULL){
        if(ListNode_compare(cur,curr) == 1){
            List_addLast(new_List, curr->data);
        }
        curr = curr->next;
    }
    if(Student_List_count(new_List) != 0){
        return new_List;
    }
    else{
        return NULL;
    }
}

void attachment_students_to_teacher(Teacher * self, Student_List * head){
    self->head = head;
}

Teacher * Teacher_new(void){
    struct Teacher * self = (struct Teacher *)malloc(sizeof(struct Teacher));
    self->head = NULL;
    return self;
}


void Teacher_free(Teacher ** self) {
    assert(NULL != self);
    free(*self);
    *self = NULL;
}

void * get_List_from_teacher(Teacher * self){
    return self->head;
}


ListNode * List_elementAt(Student_List * self, int position) {
    assert(position >= 0);
    if (self->head == NULL) throw("list->head = NULL");
    ListNode * cur = self->head;
    int count = 0;
    while (cur != NULL && count != position) {
          cur = cur->next;
          count++;
    }
    return cur;
}



struct ListNode * ListNode_new(void * data) {
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

void List_addLast(Student_List * self, void * data) {
    ListNode * node = ListNode_new(data); 
    if (self->head == NULL) {        
          self->head = node;          
          return;
    }   
    ListNode * cur = self->head;
    while (cur->next != NULL) {
          cur = cur->next;
    }
    cur->next = node;
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



void Student_List_cleanList(Student_List * self){
    int size = Student_List_count(self);
    int i = 0;
    for(i = 0; i < size; i++){
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


void delete_Student(Student_List * self){
     int size = Student_List_count(self);
     ListNode * cur = self->head;
     int i = 0; 
     for(; i < size; i++){
         Student * curr = cur->data;
         Student_free(&curr);
         cur = cur->next;
     }
}
