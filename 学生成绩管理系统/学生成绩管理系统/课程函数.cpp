#include "课程类.h"

extern vector<Required_Course>::iterator re_c_it;
extern vector<Elective_Course>::iterator el_c_it;
extern vector<Required_Course>re_c;
extern vector<Elective_Course>el_c;


//查看所有课程信息----------------- 
void ViewAllCourse()
{
	cout << "必修课如下:" << endl;
	cout << std::left << setw(20) << "课程名称" << setw(15) << "课程编号" << setw(15) << "课程学分" << endl;
	for (re_c_it = re_c.begin(); re_c_it != re_c.end(); re_c_it++)
	{
		cout << std::left << setw(20) << re_c_it->getcourse_name();
		cout << std::left << setw(15) << re_c_it->getnumber();
		cout << std::left << setw(15) << re_c_it->getcredit();
		cout << endl;
	}
	cout << "选修课如下:" << endl;
	cout << std::left << setw(20) << "课程名称" << setw(15) << "课程编号" << setw(15) << "课程学分" << endl;
	for (el_c_it = el_c.begin(); el_c_it != el_c.end(); el_c_it++)
	{
		cout << std::left << setw(20) << el_c_it->getcourse_name();
		cout << std::left << setw(15) << el_c_it->getnumber();
		cout << std::left << setw(15) << el_c_it->getcredit();
		cout << endl;
	}
	cout << endl;
}

Course::Course(string course_name, string)
{
	this->course_name = course_name;
	this->number = number;
	this->credit = 0;
}
string Course::getcourse_name()
{
	return course_name;
}
string Course::getnumber()
{
	return number;
}
float Course::getcredit()
{
	return credit;
}
float Course::getscore()
{
	return score;
}
float Course::count_gpa(string course, string name)
{
	return 0;
}
void Course::setcourse_name(string course_name)
{
	this->course_name = course_name;
}
void Course::set_number(string number)
{
	this->number = number;
}
void Course::set_credit(float credit)
{
	this->credit = credit;
}
void Course::set_score(float score)
{
	this->score = score;
}
Course::Course()
{

}
Course::~Course()
{

}


Required_Course::Required_Course()
{

}
Required_Course::~Required_Course()
{

}
float Required_Course::count_gpa(string course, string name)
{
	fstream Score_f("课程成绩.txt", ios::in | ios::out);
	if (!Score_f)
	{
		cout << "课程成绩文件打开失败!" << endl;
		return 0;
	}
	float num, myscore, sum = 0;
	string  id, score, Issubmit, stuname, stucourse;

	while (!Score_f.eof())
	{

		Score_f >> stuname;
		Score_f >> stucourse;
		Score_f >> id;
		Score_f >> score;
		Score_f >> Issubmit;
		if (stucourse == course)
		{
			num = atof(score.c_str());
			sum += num;
			if (stuname == name) myscore = atof(score.c_str());
		}
	}
	Score_f.close();

	return myscore / sum*this->getcredit();

}

Elective_Course::Elective_Course()
{

}
Elective_Course::~Elective_Course()
{

}
float  Elective_Course::count_gpa(string course, string name)
{
	fstream Score_f("课程成绩.txt", ios::in | ios::out);
	if (!Score_f)
	{
		cout << "课程成绩文件打开失败!" << endl;
		return 0;
	}

	float num, myscore, credit, gpa;
	string  id, score, Issubmit, stuname, stucourse;
	while (!Score_f.eof())
	{
		Score_f >> stuname;
		Score_f >> stucourse;
		Score_f >> id;
		Score_f >> score;
		Score_f >> Issubmit;


		if (stucourse == course&&stuname == name)
		{
			num = atof(score.c_str());

			gpa = sqrt(num) / 10 * this->getcredit();
			Score_f.close();

			return gpa;
		}
	}


}