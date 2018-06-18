
#include "学生老师类.h"
#include "重载文件输入.h"

extern vector<Required_Course>::iterator re_c_it;
extern vector<Elective_Course>::iterator el_c_it;
extern vector<Required_Course>re_c;
extern vector<Elective_Course>el_c;

extern vector<Student>stu;
extern vector<Teacher>tea;
extern vector<Student>::iterator stu_it;
extern vector<Teacher>::iterator tea_it;

void f_examine(string name)
{
	for (int i = 0; i<name.size(); i++)
	{
		if ((name.at(i) <= '9') && (name.at(i) >= '0'))
		{
			throw 1;
			return;
		}
	}
}

int Readfile(vector<Required_Course>&re_c, vector<Elective_Course>&el_c, vector<Student>&stu, vector<Teacher>&tea)
{
	//读取必修课程信息
	fstream Required("必修课程信息.txt", ios::in | ios::out);
	if (!Required)
	{
		cout << "必修课程文件打开失败!";
		system("pause");
		return 0;
	}
	Required_Course l;
	//Course_file.seekg(0, ios::end);
	while (!Required.eof()) {
		Required >> l;
		re_c.push_back(l);
	}

	Required.close();


	//选修课程文件读取--------------------
	fstream Elective("选修课程信息.txt", ios::in | ios::out);
	if (!Elective)
	{
		cout << "选修课程文件打开失败!";
		system("pause");
		return 0;
	}

	Elective_Course ec;
	while (!Elective.eof()) {
		Elective >> ec;
		el_c.push_back(ec);
	}


	Elective.close();

	//学生信息读取
	fstream Stuf("学生信息.txt", ios::in | ios::out);
	if (!Stuf)
	{
		cout << "学生信息文件打开失败!";
		system("pause");
		return 0;
	}
	fstream Select_f("选课信息.txt", ios::in | ios::out);//trunc 意思是重写文件
	if (!Select_f)
	{
		cout << "选课信息文件打开失败!" << endl;
		system("pause");
		return 0;
	}
	string id;                                 //学号
	string name;                                     //姓名
	string college;                                  //学院
	string class_id;                        //班级
	string kind;
	string course;

	string onecourse;
	Student s, select;
	while (!Stuf.eof())
	{
		Stuf >> s;
		try {
			
			f_examine(s.getname());
		}
		catch (int)
		{
			cout << "学生信息文件中存在不合法姓名,请尽快修改！" << endl;
			system("pause");
				
		}

		int Isfind = 0;
		Select_f.clear();
		Select_f.seekg(0, ios::beg);
		while (!Select_f.eof())
		{
			Isfind = 0;
			Select_f >> select;
			if (select.getclass_id() == "选修课"&&select.getname() == s.getname())
			{
				for (int i = 0; i<s.getelcourse().size(); i++)
				{
					if (select.getcollege() == s.getelcourse()[i])  Isfind = 1;

				}
				if (Isfind) continue;
				s.addelcourse(select.getcollege());
			}
		}
		stu.push_back(s);

	}
	Stuf.close();
	Select_f.close();

	//教师信息读取
	fstream Teaf("教师信息.txt", ios::in | ios::out);
	if (!Teaf)
	{
		cout << "教师信息文件打开失败!";
		system("pause");
		return 0;
	}
	Teacher t;

	while (!Teaf.eof())
	{
		Teaf >> t;
		try {

			f_examine(t.getname());
		}
		catch (int)
		{
			cout << "老师信息文件中存在不合法姓名,请尽快修改！" << endl;
			system("pause");

		}
		tea.push_back(t);

	}


	Teaf.close();
}

//选课信息写入文件
int WriteSelectCourse(vector<Required_Course>&re_c, vector<Elective_Course>&el_c, vector<Student>&stu, vector<Teacher>&tea)
{
	fstream Select_f("选课信息.txt", ios::in | ios::out | ios::trunc);//trunc 意思是重写文件
	if (!Select_f)
	{
		cout << "选课信息文件打开失败!" << endl;
		return 0;
	}
	Student *ss = new Student;
	vector<string>::iterator str_it;
	for (stu_it = stu.begin(); stu_it != stu.end(); stu_it++)
	{
		*ss = *stu_it;
		for (re_c_it = re_c.begin(); re_c_it != re_c.end(); re_c_it++)
		{
			ss->setcollege(re_c_it->getcourse_name());
			ss->setclass_id("必修课");
			Select_f << ss;
		}
		for (int i = 0; i<stu_it->getelcourse().size(); i++)
		{
			ss->setcollege(stu_it->getelcourse()[i]);
			ss->setclass_id("选修课");
			Select_f << ss;
		}
	}


	delete ss;
	Select_f.close();
}