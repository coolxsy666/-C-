#pragma once
#include "学生老师类.h"
#include "课程类.h"

int Readfile(vector<Required_Course>&re_c, vector<Elective_Course>&el_c, vector<Student>&stu, vector<Teacher>&tea);

int WriteSelectCourse(vector<Required_Course>&re_c, vector<Elective_Course>&el_c, vector<Student>&stu, vector<Teacher>&tea);