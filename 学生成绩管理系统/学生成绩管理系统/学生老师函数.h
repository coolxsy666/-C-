#pragma once
#include "ѧ����ʦ��.h"
#include "�γ���.h"




//ѧ�������Լ����������пγ�
void FindMyCourse(string name);

////ѧ���鿴��ѡ���ѡѡ�޿�
void ViewAndSelectElCourse(string name);

////ѧ��ɾ����ѡѡ�޿�
void DeleteElCourse(string name);

////������Ѱ��ѧ��
vector<Student>::iterator FindStuFromVec(string name);

void PrintTeaCourse(string name);
void ViewMyStudent(string name);
////��ʦ¼��ɼ�
void AddScore(string name);

////��ʦ�ύ�ɼ�
void SubmitScore(string name);

////��ʦ�޸ĳɼ�
void ModifyScore(string name);

////ѧ���鿴�ɼ��ͼ���
void ViewMyScore(string name);


void examine(string name);
void examinenum(string str);

bool CompScoreUp(Student &s1, Student &s2);
bool CompScoreDown(Student &s1, Student &s2);
bool CompCreditUp(Student &s1, Student &s2);
bool CompCreditDown(Student &s1, Student &s2);
bool CompIdUp(Student &s1, Student &s2);
bool CompIdDown(Student &s1, Student &s2);
//ѧ���鿴�����ĳɼ�
void PrintStuScore(string name);
void PrintStuScoreForTea(string name);





