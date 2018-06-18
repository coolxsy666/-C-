#pragma once
#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<math.h>
#include <iomanip>//setw()
#include <algorithm>
using namespace std;



class Student
{
private:
	string id;                                 //ѧ��
	string name;                                     //����
	string college;                                  //ѧԺ
	string class_id;                        //�༶
	vector<string>elcourse;        //ѡ�޿γ�
	float score;                            //�γ̳ɼ�
	float credit;
public:
	string getid();
	string getname();
	string getcollege();
	string getclass_id();
	float getcredit();
	vector<string>getelcourse();
	float getscore();
	void setcredit(float credit);
	void setscore(float score);
	void setid(string id);
	void setname(string name);
	void setcollege(string college);
	void setclass_id(string class_id);
	void addelcourse(string elcourse);
	void deleteelcourse(string elcourse);
	Student();
	~Student();
};




class Teacher
{
private:
	string id;                            //����
	string name;                                //����
	string college;                             //ѧԺ
	vector<string>recourse;                //�οογ�
	vector<string>elcourse;
public:
	string getid();
	string getname();
	string getcollege();
	vector<string> getrecourse();
	vector<string> getelcourse();
	void setid(string id);
	void setname(string name);
	void setcollege(string college);
	void setrecourse(vector<string> recourse);
	void setelcourse(vector<string> elcourse);
	Teacher();
	~Teacher();
};

