#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pbconsole.h>
#include <time.h>
#include <ctype.h>
#include <progbase.h>
#include <assert.h>

#include <ci.h>

int main(void){
    char str[3][1000]= {"dddd,ff,5\n","a,ss,8\n","sss,qq,63\n"};

    Student_List * self = List_new();
   // char str[1000];
    //fgets(str,1000,stdin);
    str_to_list(self,str,3);
     Teacher * new_teacher = Teacher_new(self);
     attachment_students_to_teacher(new_teacher, self);

    //char str1[3][1000]= {"ddd,ff,5;","a,s,8;","ss,qq,63;"};
     Student_List * self1 = List_new();
    // char str1[1000];
    // fgets(str1,1000,stdin);
    str_to_list(self1,str, 3);
   // Student_List * self3 = create_newList_from_teacher(new_teacher, self);
     
     print(self);
    // Student_List_cleanList(self);
    // Student_List_cleanList(self1);
    // free(self);
    // free(self1);
    delete_Student(self);
    delete_Student(self1);
    Student_List_cleanList(self);
    Student_List_cleanList(self1);
  //Student_List_cleanList(self3);
    free(self);
    free(self1);
     free(new_teacher);
    //free(self3);
    
    // char * str2 = create_str(nuy(new_teacher));
    // printf("%s", str2);
    //
   
    //print(self);        

return 0;
}
