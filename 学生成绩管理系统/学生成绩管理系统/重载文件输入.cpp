#include "重载文件输入.h"
//重载文件流fstream
//必修课信息
fstream &operator>>(fstream &input, Required_Course &recourse)
{
	string number;
	string course_name;
	float credit;
	input >> course_name >> number >> credit;
	recourse.setcourse_name(course_name);
	recourse.set_number(number);
	recourse.set_credit(credit);
	return input;
}
//选修课信息
fstream &operator>>(fstream &input, Elective_Course &elcourse)
{
	string number;
	string course_name;
	float credit;
	input >> course_name >> number >> credit;
	elcourse.setcourse_name(course_name);
	elcourse.set_number(number);
	elcourse.set_credit(credit);
	return input;
}
//学生信息   选课信息
fstream &operator>>(fstream &input, Student &s)
{
	string id;                                 //学号
	string name;                                     //姓名
	string college;                                  //学院
	string class_id;                        //班级
	input >> id >> name >> college >> class_id;
	s.setid(id);
	s.setname(name);
	s.setcollege(college);
	s.setclass_id(class_id);

	return input;
}
//教师信息
fstream &operator>>(fstream &input, Teacher &t)
{
	string id;                                 //学号
	string name;                                     //姓名
	string college;                                  //学院
	string class_id;                        //班级
	string onecourse;
	vector<string>recourse;                //任课课程
	vector<string>elcourse;

	input >> id >> name >> college;
	t.setid(id);
	t.setname(name);
	t.setcollege(college);
	input >> onecourse;
	while (onecourse != "必修课")
	{
		recourse.push_back(onecourse);
		input >> onecourse;
	}
	t.setrecourse(recourse);
	input >> onecourse;
	while (onecourse != "选修课")
	{
		elcourse.push_back(onecourse);
		input >> onecourse;
	}
	t.setelcourse(elcourse);
	return input;
}
//成绩信息
fstream &operator>>(fstream &input, Student *s)
{
	string id;                                 //学号
	string name;                                     //姓名
	string college;                                  //课程
	string class_id;                        //是否提交
	float score;
	input >> name >> college >> id >> score >> class_id;
	s->setid(id);
	s->setname(name);
	s->setcollege(college);
	s->setscore(score);
	s->setclass_id(class_id);
	return input;
}
//成绩信息
fstream &operator<<(fstream &output, Student s)
{
	string id;                                 //学号
	string name;                                     //姓名
	string college;                                  //课程
	string class_id;                        //是否提交
	float score = s.getscore();
	output << s.getname() << " " << s.getcollege() << " " << s.getid() << " " << setw(8) << score << " " << s.getclass_id() << endl;

	return output;
}
//选课信息
fstream &operator<<(fstream &output, Student *s)
{
	string id;                                 //学号
	string name;                                     //姓名
	string college;                                  //课程
	string class_id;                        //是否提交

	output << s->getid() << " " << s->getname() << " "  << s->getcollege() << " "<< s->getclass_id()<< endl;

	return output;
}