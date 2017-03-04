#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pbconsole.h>
#include <time.h>
#include <ctype.h>
#include <progbase.h>
#include <assert.h>

#include "list.h"

int main(void){
    
    Student_List * self = List_new();
    char str[1000];
    fgets(str,1000,stdin);
    str_to_list(self,str);
   // Teacher * new_teacher = Teacher_new(self);
  //  attachment_students_to_teacher(new_teacher, self);

    Student_List * self1 = List_new();
    char str1[1000];
    fgets(str1,1000,stdin);
    str_to_list(self1,str1);
   // Student_List * self3 = create_newList_from_teacher(new_teacher, self1);
     
   // print(self3);
    Student_List_cleanList(self);
    Student_List_cleanList(self1);
    free(self);
    free(self1);
   // Student_List_cleanList(self3);

    // char * str2 = create_str(nuy(new_teacher));
    // printf("%s", str2);
    //
   
    //print(self);        

return 0;
}
