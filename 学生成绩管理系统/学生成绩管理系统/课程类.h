#pragma once
#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<math.h>
#include <iomanip>//setw()
#include <algorithm>
using namespace std;

class Course
{
private:
	string course_name;      //课程名称
	string number;                   //课程编号 
	float credit;                   //课程学分
	float score;                   //课程成绩

public:
	virtual float count_gpa(string course, string name);
	string getcourse_name();
	string getnumber();
	float getcredit();
	float Course::getscore();
	void setcourse_name(string course_name);
	void set_number(string number);
	void set_credit(float credit);
	void set_score(float score);
	Course();
	Course(string course_name, string);
	~Course();
};


class Required_Course :public Course
{
public:
	virtual float count_gpa(string course, string name);
	Required_Course();
	~Required_Course();
};


class Elective_Course :public Course
{
public:
	virtual float count_gpa(string course, string name);
	Elective_Course();
	~Elective_Course();
};

