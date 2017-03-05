
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdio.h>

#include "csv.h"
#include "student.h"



void str_to_list(Student_List * self, char * str){
    char surname[20];
    char name[20];
    int score = 0;
    int flag = 0;
    int k = 0;
    int flag1 = 0;
    int i = 0;
        for(i = 0; i < strlen(str); i++){
            if(str[i] == ',' && flag == 0){
                int start = 0;
                int j = i-k;
                for(; j < i; j++, start++){
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
                int j = i - k;
                for(; j < i; j++, start++){
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
                int j = i - k;
                for(; j < i; j++, start++){
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
                //List_addFirst(self,student);
                List_addLast(self, student);
                flag1 = 0;
            }
        }
    }

    char * str_from_List(Student_List * self){
        char * str;
        str = (char *)malloc(500 * sizeof(char) );
        str[0] = '\0';
        ListNode * cur = List_get_head(self);
        while(cur != NULL){
            char * student_string;
            student_string = str_from_struct(List_get(cur));
            strcat(str,student_string);
            cur = ListNode_next(cur);
        }
    return str;
}
