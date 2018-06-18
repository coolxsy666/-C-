#pragma once
#include "学生老师类.h"
#include "课程类.h"




//学生查找自己的所有已有课程
void FindMyCourse(string name);

////学生查看并选择可选选修课
void ViewAndSelectElCourse(string name);

////学生删除已选选修课
void DeleteElCourse(string name);

////由名字寻找学生
vector<Student>::iterator FindStuFromVec(string name);

void PrintTeaCourse(string name);
void ViewMyStudent(string name);
////老师录入成绩
void AddScore(string name);

////老师提交成绩
void SubmitScore(string name);

////老师修改成绩
void ModifyScore(string name);

////学生查看成绩和绩点
void ViewMyScore(string name);


void examine(string name);
void examinenum(string str);

bool CompScoreUp(Student &s1, Student &s2);
bool CompScoreDown(Student &s1, Student &s2);
bool CompCreditUp(Student &s1, Student &s2);
bool CompCreditDown(Student &s1, Student &s2);
bool CompIdUp(Student &s1, Student &s2);
bool CompIdDown(Student &s1, Student &s2);
//学生查看排序后的成绩
void PrintStuScore(string name);
void PrintStuScoreForTea(string name);





