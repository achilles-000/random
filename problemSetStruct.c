#include <stdio.h>
#include <string.h>


struct student {
    char Student_Name[100];
    int Student_ID;
    int Student_Age;
};

int main(){
    struct student Student1;

    strcpy(Student1.Student_Name, "Marshall Mathers");
    Student1.Student_Age = 22;
    Student1.Student_ID = 901923;

    printf("\nname: %s", Student1.Student_Name);
    printf("\nage: %d", Student1.Student_Age);
    printf("\nStudent Id: %d", Student1.Student_ID);




    return 0;
}