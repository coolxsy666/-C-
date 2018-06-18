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
	string id;                                 //学号
	string name;                                     //姓名
	string college;                                  //学院
	string class_id;                        //班级
	vector<string>elcourse;        //选修课程
	float score;                            //课程成绩
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
	string id;                            //工号
	string name;                                //姓名
	string college;                             //学院
	vector<string>recourse;                //任课课程
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

