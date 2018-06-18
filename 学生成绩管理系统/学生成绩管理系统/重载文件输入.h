#pragma once
#include "学生老师类.h"
#include "课程类.h"



fstream &operator>>(fstream &input, Required_Course &recourse);
fstream &operator>>(fstream &input, Elective_Course &elcourse);
fstream &operator>>(fstream &input, Student &s);
fstream &operator>>(fstream &input, Teacher &t);
fstream &operator>>(fstream &input, Student *s);
fstream &operator<<(fstream &output, Student s);
fstream &operator<<(fstream &output, Student *s);

void f_examine(string name);