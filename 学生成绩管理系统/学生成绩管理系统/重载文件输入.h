#pragma once
#include "ѧ����ʦ��.h"
#include "�γ���.h"



fstream &operator>>(fstream &input, Required_Course &recourse);
fstream &operator>>(fstream &input, Elective_Course &elcourse);
fstream &operator>>(fstream &input, Student &s);
fstream &operator>>(fstream &input, Teacher &t);
fstream &operator>>(fstream &input, Student *s);
fstream &operator<<(fstream &output, Student s);
fstream &operator<<(fstream &output, Student *s);

void f_examine(string name);