
#include "学生老师函数.h"
#include "重载文件输入.h"

extern vector<Required_Course>::iterator re_c_it;
extern vector<Elective_Course>::iterator el_c_it;
extern vector<Required_Course>re_c;
extern vector<Elective_Course>el_c;

extern vector<Student>stu;
extern vector<Teacher>tea;
extern vector<Student>::iterator stu_it;
extern vector<Teacher>::iterator tea_it;


string Student::getid()
{
	return id;
}
string Student::getname()
{
	return name;
}
string Student::getcollege()
{
	return college;
}
string Student::getclass_id()
{
	return class_id;
}
vector<string> Student::getelcourse()
{
	return elcourse;
}
float Student::getscore()
{
	return score;
}
float Student::getcredit()
{
	return credit;
}
void Student::setscore(float score)
{
	this->score = score;
}
void Student::setid(string id)
{
	this->id = id;
}
void Student::setname(string name)
{
	this->name = name;
}
void Student::setcollege(string college)
{
	this->college = college;
}
void Student::setclass_id(string class_id)
{
	this->class_id = class_id;
}
void Student::addelcourse(string elcourse)
{
	this->elcourse.push_back(elcourse);
}
void Student::deleteelcourse(string deelcourse)
{
	vector<string>::iterator it;
	for (it = elcourse.begin(); it != elcourse.end(); it++)
	{
		if (*it == deelcourse)
		{
			elcourse.erase(it);
			cout << endl << deelcourse << "已删除！" << endl << endl;
			break;
		}
	}
}
void Student::setcredit(float credit)
{
	this->credit = credit;
}
Student::Student()
{

}
Student::~Student()
{

}

string Teacher::getid()
{
	return id;
}
string Teacher::getname()
{
	return name;
}
string Teacher::getcollege()
{
	return college;
}
vector<string> Teacher::getrecourse()
{
	return recourse;
}
vector<string> Teacher::getelcourse()
{
	return elcourse;
}
void Teacher::setid(string id)
{
	this->id = id;
}
void Teacher::setname(string name)
{
	this->name = name;
}
void Teacher::setcollege(string college)
{
	this->college = college;
}
void Teacher::setrecourse(vector<string> recourse)
{
	this->recourse = recourse;
}
void Teacher::setelcourse(vector<string> elcourse)
{
	this->elcourse = elcourse;
}
Teacher::Teacher()
{

}
Teacher::~Teacher()
{

}


//学生查找自己的所有已有课程-----------------------
void FindMyCourse(string name)
{
	string str;
	int Isfind = 0;
	cout << "你的必修课有：" << endl;

	for (int i = 0; i < re_c.size(); i++)
	{
		cout << re_c[i].getcourse_name() << "  ";
		Isfind = 1;
	}
	cout << endl << "你的选修课有：" << endl;
	for (stu_it = stu.begin(); stu_it != stu.end(); stu_it++)
	{
		if (stu_it->getname() == name)
		{
			for (int i = 0; i < stu_it->getelcourse().size(); i++)
			{
				cout << stu_it->getelcourse()[i] << "  ";
				Isfind = 2;
			}
		}
	}

	if (Isfind == 1) cout << "无";
	cout << endl;
	if (!Isfind) cout << "没有找到" << name << "的数据哦！" << endl;

}

//学生查看并选择可选选修课-------------------------------
void ViewAndSelectElCourse(string name)
{
	cout << "以下为学校所有选修课：" << endl;
	//选修课信息
	cout << std::left << setw(20) << "课程名称" << setw(15) << "课程编号" << setw(15) << "课程学分" << endl;
	for (el_c_it = el_c.begin(); el_c_it != el_c.end(); el_c_it++)
	{
		cout << std::left << setw(20) << el_c_it->getcourse_name();
		cout << std::left << setw(15) << el_c_it->getcredit();
		cout << std::left << setw(15) << el_c_it->getnumber();
		cout << endl;
	}
	cout << endl;
	string course;
	int Isfind = 0;
	while (1)
	{
		Isfind = 0;
		cout << "请选择你想选的选修课(输入课程名字,返回请输入0):" << endl;
		cin >> course;
		if (course == "0") break;
		//确认选修课名字是否输入正确
		for (el_c_it = el_c.begin(); el_c_it != el_c.end(); el_c_it++)
		{
			if (el_c_it->getcourse_name() == course)
			{
				Isfind = 1;
				break;
			}
		}
		if (!Isfind)
		{
			cout << endl << "有这个选修课吗，是不是打错了？" << endl << endl;
			continue;
		}
		Isfind = 0;
		//确认学生是否已选该课程
		for (stu_it = stu.begin(); stu_it != stu.end(); stu_it++)
		{
			if (stu_it->getname() == name)
			{
				break;
			}
		}
		//如果找到了
		for (int i = 0; i<stu_it->getelcourse().size(); i++)
		{
			if (stu_it->getelcourse()[i] == course)
			{
				Isfind = 1;
				break;
			}
		}
		if (Isfind)
			cout << endl << "你已经选过这门课了，给别的同学一个机会吧!" << endl << endl;
		else
		{
			cout << endl << "抢课成功！" << endl << endl;
			stu_it->addelcourse(course);
		}
	}

}

//学生删除已选选修课------------------------------------
void DeleteElCourse(string name)
{
	Student *s = new Student;
	for (stu_it = stu.begin(); stu_it != stu.end(); stu_it++)
	{
		if (stu_it->getname() == name)
		{
			break;
		}
	}

	//如果你没有选修课
	if (stu_it->getelcourse().size() == 0)
	{
		cout << "你还没选上课那，去选课吧！" << endl << endl;
		return;
	}
	cout << "以下为你已经选择的选修课：" << endl;
	//选修课信息
	cout << std::left << setw(20) << "课程名称" << setw(15) << "课程编号" << setw(15) << "课程学分" << endl;
	string course;
	for (int i = 0; i < stu_it->getelcourse().size(); i++)
	{
		course = stu_it->getelcourse()[i];
		for (el_c_it = el_c.begin(); el_c_it != el_c.end(); el_c_it++)
		{
			if (course == el_c_it->getcourse_name()) {
				cout << std::left << setw(20) << el_c_it->getcourse_name();
				cout << std::left << setw(15) << el_c_it->getcredit();
				cout << std::left << setw(15) << el_c_it->getnumber();
				cout << endl;
				break;
			}
		}
	}


	int Isfind = 0;
	string str;
	cout << "请输入你要删除的课程(输入0返回):" << endl;
	cin >> course;
	if (course == "0") return;
	//查看成绩是否已提交
	fstream Score_f("课程成绩.txt", ios::in | ios::out);
	if (!Score_f)
	{
		cout << "课程成绩文件打开失败!" << endl;
		return;
	}
	//while (getline(Score_f, str))
	while (!Score_f.eof())
	{
		Score_f >> s;
		if (name == s->getname() && course == s->getcollege() && "已提交" == s->getclass_id())
		{
			cout << "课程成绩已提交，无法删除课程！" << endl;
			Score_f.close();
			return;
		}
	}
	stu_it->deleteelcourse(course);
	Score_f.close();
	delete s;
}

//由名字寻找学生-----------------------------------
vector<Student>::iterator FindStuFromVec(string name)
{
	for (stu_it = stu.begin(); stu_it != stu.end(); stu_it++)
	{
		if (stu_it->getname() == name)
			return stu_it;
	}
	cout << "没有找到" << name << "的信息!" << endl;

}

//查看自己的学生信息--------------------------------
void ViewMyStudent(string name)
{
	int i, Isfind = 0;
	Student select;
	string str;
	string course;
	fstream Select_f("选课信息.txt");                //这里用fstream会有奇怪的bug
	if (!Select_f)
	{
		cout << "选课信息文件打开失败!" << endl;
		return;
	}
	for (i = 0; i < tea.size(); i++)
	{
		if (tea[i].getname() == name)
			break;
	}
	//寻找必修课的学生
	for (int j = 0; j < tea[i].getrecourse().size(); j++)
	{
		course = tea[i].getrecourse()[j];
		cout << "--必修--" << course << "的学生有：" << endl;
		Select_f.clear();
		Select_f.seekg(0, ios::beg);                 //把文件的读指针从文件开头位置向后移0个字节

		for (stu_it = stu.begin(); stu_it != stu.end(); stu_it++)
		{
			cout << std::left << "学生姓名：" << setw(15) << stu_it->getname() << "  学号:" << setw(15) << stu_it->getid();
			cout << "  班级:" << setw(15) << stu_it->getclass_id() << "  学院:" << setw(15) << stu_it->getcollege() << endl;
		}


	}

	//寻找选修课的学生
	for (int j = 0; j < tea[i].getelcourse().size(); j++)
	{
		course = tea[i].getelcourse()[j];
		Select_f.clear();
		Select_f.seekg(0, ios::beg);//重置指针
		cout << "--选修--" << course << "的学生有：" << endl;

		for (stu_it = stu.begin(); stu_it != stu.end(); stu_it++)
		{
			for (int i = 0; i < stu_it->getelcourse().size(); i++)
			{
				if (stu_it->getelcourse()[i] == course)
				{
					cout << std::left << "学生姓名：" << setw(15) << stu_it->getname() << "  学号:" << setw(15) << stu_it->getid();
					cout << "  班级:" << setw(15) << stu_it->getclass_id() << "  学院:" << setw(15) << stu_it->getcollege() << endl;
					Isfind = 1;
				}
			}
		}
		if (!Isfind) cout << "(这门课竟然没有学生。" << endl;
		Isfind = 0;
	}

	while (1)
	{
		Isfind = 0;
		cout << endl << "请选择你想查看学生信息的课程(输入0退出)：" << endl;
		cin >> course;
		if (course == "0") break;
		for (int j = 0; j < tea[i].getrecourse().size(); j++)
		{
			if (course == tea[i].getrecourse()[j])
			{
				Isfind = 1;
				break;
			}
		}
		if (!Isfind)
		{
			for (int j = 0; j < tea[i].getelcourse().size(); j++)
			{
				if (course == tea[i].getelcourse()[j])
				{
					Isfind = 2;
					break;
				}
			}
		}
		if (!Isfind)
		{
			cout << "这门不是你代的课，是不是输错了？" << endl;
			continue;
		}
		Isfind = 0;
		cout << endl << "请选择你想查看信息的学生姓名：" << endl;
		string name;
		cin >> name;
		Select_f.clear();
		Select_f.seekg(0, ios::beg);//重置指针
									/*while (getline(Select_f, str))*/
		while (!Select_f.eof())
		{
			Select_f >> select;
			if (name == select.getname() && course == select.getcollege())
			{
				stu_it = FindStuFromVec(name);
				cout << "姓名：" << stu_it->getname() << "  学号:" << stu_it->getid() << "  学院:" << stu_it->getcollege();
				cout << "  班级:" << stu_it->getclass_id() << endl;
				Isfind = 1;
				break;
			}
		}
		if (!Isfind)
			cout << "没有找到这个学生！" << endl;
	}
	Select_f.close();
}

//打印老师代的课-------------------
void PrintTeaCourse(string name)
{
	for (tea_it = tea.begin(); tea_it != tea.end(); tea_it++)
	{
		if (name == tea_it->getname())
		{
			for (int i = 0; i < tea_it->getrecourse().size(); i++)
			{
				if (i == 0) cout << "我代的必修课有：";
				cout << tea_it->getrecourse()[i] << " ";
			}
			cout << endl;
			for (int i = 0; i < tea_it->getelcourse().size(); i++)
			{
				if (i == 0) cout << "我代的选修课有：";
				cout << tea_it->getelcourse()[i] << " ";
			}
			cout << endl;
			return;
		}
	}
}

//老师录入成绩--------------------
void AddScore(string name)
{

	fstream Score_f("课程成绩.txt", ios::in | ios::out);
	if (!Score_f)
	{
		cout << "课程成绩文件打开失败!" << endl;
		return;
	}
	string course;
	int Isfind = 0;
	string score;
	Student *ss = new Student;
	while (1)
	{
		Isfind = 0;        //必修课则值为1，选修为2
		PrintTeaCourse(name);
		cout << "请选择你想录入成绩的课程：(退出请输入0)" << endl;
		cin >> course;
		if (course == "0") break;
		//确认这门课是否存在
		for (int i = 0; i < tea_it->getrecourse().size(); i++)
		{
			if (course == tea_it->getrecourse()[i])
			{
				Isfind = 1;
				break;
			}
		}
		if (!Isfind)
		{
			for (int i = 0; i < tea_it->getelcourse().size(); i++)
			{
				if (course == tea_it->getelcourse()[i])
				{
					Isfind = 2;
					break;
				}
			}
		}

		if (!Isfind)
		{
			cout << "你输入的课程有误，是不是输错了？" << endl;
			continue;
		}
		//录入成绩（未提交
		Score_f.seekg(0, ios::end);
		if (Isfind == 1)
		{
			for (stu_it = stu.begin(); stu_it != stu.end(); )
			{
				cout << "请为" << stu_it->getname() << "打分：";
				try
				{
					cin >> score;
					examinenum(score);
				}
				catch (int)
				{
					cout << "请合法打分，只允许数字！" << endl;

					continue;
				}
				/////num=atof(str.c_str())  
				//string 转 float
				stu_it->setscore(atof(score.c_str()));

				//output >> s->getname() >>" ">> s->getcollege() >>" ">> s->getid()  >>" ">> setw(8) >> score>> " ">>"未提交";
				//Score_f << stu_it->getname() << ' ' << course << ' ' << stu_it->getid() << ' ' << setw(8) << score << ' ' << "未提交" << endl;

				*ss = *stu_it;
				ss->setcollege(course);
				ss->setclass_id("未提交");
				Score_f << *ss;
				stu_it++;
			}
		}
		else
		{
			for (stu_it = stu.begin(); stu_it != stu.end(); stu_it++)
			{
				for (int i = 0; i < stu_it->getelcourse().size(); i++)
				{
					if (stu_it->getelcourse()[i] == course)
					{
						cout << "请为" << stu_it->getname() << "打分：";
						try
						{
							cin >> score;
							examinenum(score);
						}
						catch (int)
						{
							cout << "请合法打分，只允许数字！" << endl;
							i--;
							continue;
						}
						//	Score_f << stu_it->getname() << ' ' << course << ' ' << stu_it->getid() << ' ' << setw(8) << score << ' ' << "未提交" << endl;
						*ss = *stu_it;
						ss->setcollege(course);
						ss->setscore(atof(score.c_str()));
						ss->setclass_id("未提交");
						Score_f << *ss;
						break;
					}
				}
			}
		}


	}
	Score_f.close();
	delete ss;
}



//老师提交成绩-----------------
void SubmitScore(string name)
{
	fstream Score_f("课程成绩.txt", ios::in | ios::out);
	if (!Score_f)
	{
		cout << "课程成绩文件打开失败!" << endl;
		return;
	}
	string course;
	int Isfind = 0;
	string score;
	Student *s = new Student;
	while (1)
	{
		Isfind = 0;        //必修课则值为1，选修为2
		PrintTeaCourse(name);
		cout << "请选择你想提交成绩的课程：(退出请输入0)" << endl;
		cin >> course;
		if (course == "0") break;
		//确认这门课是否存在
		for (int i = 0; i < tea_it->getrecourse().size(); i++)
		{
			if (course == tea_it->getrecourse()[i])
			{
				Isfind = 1;
				break;
			}
		}
		if (!Isfind)
		{
			for (int i = 0; i < tea_it->getelcourse().size(); i++)
			{
				if (course == tea_it->getelcourse()[i])
				{
					Isfind = 2;
					break;
				}
			}
		}

		if (!Isfind)
		{
			cout << "你输入的课程有误，是不是输错了？" << endl;
			continue;
		}
		//提交成绩
		string str;
		long len = 0;
		int Is = 0;
		//while (getline(Score_f, str))
		while (!Score_f.eof())
		{
			Score_f >> s;
			if (course == s->getcollege())
			{
				if ("已提交" == s->getclass_id())
				{
					cout << "成绩已提交！" << endl;
					Isfind = 0;
					break;
				}
				//	cout << str << endl;
				//处理最后一行的情况
				if (Score_f.eof())
					Score_f.clear();

				Score_f.seekg(len, ios::beg);
				if (len && !Is)
				{
					Is = 1;
					Score_f << endl;
				}
				s->setclass_id("已提交");
				Score_f << *s;

				/*str.erase(str.end() - 6, str.end());
				Score_f << str << "已提交" << endl;*/

			}
			len = Score_f.tellg();                                ///////////别的方法都有bug////////////
		}


		cout << "提交成功！" << endl;


	}



	delete s;
	Score_f.close();
}

//老师修改成绩---------------------------
void ModifyScore(string name)
{
	fstream Score_f("课程成绩.txt", ios::in | ios::out);
	if (!Score_f)
	{
		cout << "课程成绩文件打开失败!" << endl;
		return;
	}
	string course;
	int Isfind = 0;
	string score;
	Student *ss = new  Student, *tem = new Student;
	while (1)
	{
		/////////*Score_f.clear();
		////////Score_f.seekg(0, ios::beg);*/
		Isfind = 0;        //必修课则值为1，选修为2
		PrintTeaCourse(name);
		cout << "请选择你想修改成绩的课程(输入0退出)：" << endl;
		cin >> course;
		if (course == "0") break;
		//确认这门课是否存在
		for (int i = 0; i < tea_it->getrecourse().size(); i++)
		{
			if (course == tea_it->getrecourse()[i])
			{
				Isfind = 1;
				break;
			}
		}
		if (!Isfind)
		{
			for (int i = 0; i < tea_it->getelcourse().size(); i++)
			{
				if (course == tea_it->getelcourse()[i])
				{
					Isfind = 2;
					break;
				}
			}
		}

		if (!Isfind)
		{
			cout << "你输入的课程有误，是不是输错了？" << endl;
			continue;
		}

		cout << "哪位同学中奖了呢？ " << endl;
		string stuname;
		string str;
		long len = 0;
		float score;
		string modifyscore;
		cin >> stuname;
		stu_it = FindStuFromVec(stuname);
		*tem = *stu_it;
		//修改成绩
		Score_f.clear();
		Score_f.seekg(0, ios::beg);
		//while (getline(Score_f, str))
		while (!Score_f.eof())
		{
			Score_f >> ss;
			if (stuname == ss->getname() && course == ss->getcollege())
			{
				if ("已提交" == ss->getclass_id())
				{
					cout << "成绩已提交，无法修改！" << endl;
					Isfind = 11;
					break;
				}
				cout << ss->getname() << " " << ss->getscore() << endl;
				Isfind = 1;
				cout << "他应得的分数是： " << endl;
				cin >> modifyscore;
				if (Score_f.eof())
					Score_f.clear();

				Score_f.seekg(len, ios::beg);
				ss->setscore(atof(modifyscore.c_str()));
				//Score_f << stu_it->getname() << ' ' << course << ' ' << stu_it->getid() << ' ' << setw(8) << modifyscore << ' ' << "未提交" << endl;
				if (len) Score_f << endl;
				Score_f << *ss;
				cout << "修改成功！" << endl;
				break;
			}
			len = Score_f.tellg();                                ///////////别的方法都有bug////////////
		}

		if (!Isfind)
		{
			cout << "没有找到学生信息！" << endl;
			Isfind = 0;
			continue;
		}



	}



	delete ss;
	delete tem;
	Score_f.close();
}

//学生查看成绩和绩点---------------------
void ViewMyScore(string name)
{
	fstream Score_f("课程成绩.txt", ios::in | ios::out);
	if (!Score_f)
	{
		cout << "课程成绩文件打开失败!" << endl;
		return;
	}

	//string course, str, id, score, Issubmit, stuname, stucourse;
	string course;
	Student *ss = new Student;
	int Isfind = 0, Isfind1 = 0;
	float gpa;
	cout << "你想查看哪门课的成绩(想看全部成绩请输入1)：" << endl;
	cin >> course;
	//输出全部已提交成绩
	if (course == "1")
	{
		while (!Score_f.eof())
		{
			Isfind = 0;
			Score_f >> ss;
			if (ss->getname() == name)
			{
				if (ss->getclass_id() == "未提交")
				{

					cout << ss->getcollege() << "成绩未提交，无法查看！" << endl;
					Isfind = 0;
					continue;
				}
				for (re_c_it = re_c.begin(); re_c_it != re_c.end(); re_c_it++)
				{
					if (re_c_it->getcourse_name() == ss->getcollege())
					{
						Isfind = 1;
						break;
					}
				}
				if (Isfind == 0)
					for (el_c_it = el_c.begin(); el_c_it != el_c.end(); el_c_it++)
					{
						if (el_c_it->getcourse_name() == ss->getcollege()) {
							Isfind = 2;
							break;
						}
					}
				if (Isfind == 1) gpa = re_c_it->count_gpa(ss->getcollege(), ss->getname());
				else if (Isfind == 2) gpa = el_c_it->count_gpa(ss->getcollege(), ss->getname());
				cout << "你的" << ss->getcollege() << "的成绩为：" << ss->getscore() << ",绩点为：" << gpa << endl;

			}

		}
		Score_f.close();
		return;
	}
	for (re_c_it = re_c.begin(); re_c_it != re_c.end(); re_c_it++)
	{
		if (re_c_it->getcourse_name() == course)
		{
			Isfind = 1;
			break;
		}
	}
	for (el_c_it = el_c.begin(); el_c_it != el_c.end(); el_c_it++)
	{
		if (el_c_it->getcourse_name() == course) {
			Isfind = 2;
			break;
		}
	}

	while (!Score_f.eof())
	{
		Isfind1 = 0;
		Score_f >> ss;
		if (ss->getname() == name && ss->getcollege() == course)
		{
			if (ss->getclass_id() == "未提交")
			{
				cout << "成绩未提交，无法查看！" << endl << endl;
				Isfind = 0;
				break;
			}
			if (Isfind == 1) gpa = re_c_it->count_gpa(ss->getcollege(), ss->getname());
			else if (Isfind == 2) gpa = el_c_it->count_gpa(ss->getcollege(), ss->getname());
			cout << "你的" << course << "的成绩为：" << ss->getscore() << ",绩点为：" << gpa << endl;
			break;
		}
		Isfind1 = 4;
	}
	if (Isfind1 == 4)
		cout << "没有找到这门课的成绩！" << endl << endl;
	Score_f.close();
	delete ss;
	return;
}

//检查姓名是否合法-----
void examine(string name)
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

//检查字符串是否有数字之外的字符-----
void examinenum(string str)
{
	for (int i = 0; i<str.size(); i++)
	{
		if ((str.at(i)>'9') || (str.at(i)<'0'))
		{
			throw 1;
		}
	}

}

bool CompScoreUp(Student &s1, Student &s2)
{
	return s1.getscore() < s2.getscore();
}

bool CompScoreDown(Student &s1, Student &s2)
{
	return s1.getscore() > s2.getscore();
}

bool CompCreditUp(Student &s1, Student &s2)
{
	return s1.getcredit() < s2.getcredit();
}

bool CompCreditDown(Student &s1, Student &s2)
{
	return s1.getcredit() > s2.getcredit();
}

bool CompIdUp(Student &s1, Student &s2)
{
	return s1.getid() < s2.getid();
}

bool CompIdDown(Student &s1, Student &s2)
{
	return s1.getid() > s2.getid();
}

//学生查看排序后的成绩
void PrintStuScore(string name)
{
	Student *s = new Student;
	vector<Student> vecstu;

	string str, str1;
	int Isfind;
	fstream Score_f("课程成绩.txt", ios::in | ios::out);
	if (!Score_f)
	{
		cout << "课程成绩文件打开失败!" << endl;
		return;
	}
	while (!Score_f.eof())
	{
		Isfind = 0;
		Score_f >> s;
		if (s->getname() == name&&s->getclass_id() != "未提交")
		{
			for (re_c_it = re_c.begin(); re_c_it != re_c.end(); re_c_it++)
			{
				if (re_c_it->getcourse_name() == s->getcollege())
				{
					Isfind = 1;
					break;
				}
			}
			if (!Isfind)
			{
				for (el_c_it = el_c.begin(); el_c_it != el_c.end(); el_c_it++)
				{
					if (el_c_it->getcourse_name() == s->getcollege())
					{
						Isfind = 2;
						break;
					}
				}
			}

			if (Isfind == 1)     s->setcredit(re_c_it->count_gpa(re_c_it->getcourse_name(), name));
			else if (Isfind == 2)     s->setcredit(el_c_it->count_gpa(el_c_it->getcourse_name(), name));

			vecstu.push_back(*s);
		}
	}


	cout << "对绩点进行排序输入0，对成绩进行排序输入1：" << endl;
	cin >> str;
	cout << "按升序输出请按0，降序输出请按1：" << endl;
	cin >> str1;
	if (str == "1"&&str1 == "1")
	{
		sort(vecstu.begin(), vecstu.end(), CompScoreDown);
	}
	else if (str == "1"&&str1 == "0")
	{
		sort(vecstu.begin(), vecstu.end(), CompScoreUp);
	}
	else if (str == "0"&&str1 == "1")
	{
		sort(vecstu.begin(), vecstu.end(), CompCreditDown);
	}
	else if (str == "0"&&str1 == "0")
	{
		sort(vecstu.begin(), vecstu.end(), CompCreditUp);
	}

	cout << std::left << setw(15) << "课程" << "  " << setw(15) << "成绩" << setw(15) << "绩点" << endl;
	for (stu_it = vecstu.begin(); stu_it != vecstu.end(); stu_it++)
	{
		cout << std::left << setw(15) << stu_it->getcollege() << "  " << setw(15) << stu_it->getscore() << setw(15) << stu_it->getcredit() << endl;
	}


	Score_f.close();
	delete s;
}

void PrintStuScoreForTea(string name)
{
	fstream Score_f("课程成绩.txt", ios::in | ios::out);
	if (!Score_f)
	{
		cout << "课程成绩文件打开失败!" << endl;
		return;
	}
	Student *s = new Student;
	string course, str, str1;
	vector<Student> vecstu;
	int Isfind = 0, num = 0;
	while (1)
	{
		PrintTeaCourse(name);
		cout << "请输入你想查看成绩的课程：(退出请按0)" << endl;
		cin >> course;
		if (course == "0")  break;
		//确认这门课是否存在
		for (int i = 0; i < tea_it->getrecourse().size(); i++)
		{
			if (course == tea_it->getrecourse()[i])
			{
				Isfind = 1;
				break;
			}
		}
		if (!Isfind)
		{
			for (int i = 0; i < tea_it->getelcourse().size(); i++)
			{
				if (course == tea_it->getelcourse()[i])
				{
					Isfind = 2;
					break;
				}
			}
		}

		if (!Isfind)
		{
			cout << "你输入的课程有误，是不是输错了？" << endl;
			continue;
		}

		Score_f.clear();
		Score_f.seekg(0, ios::beg);
		while (!Score_f.eof())
		{
			Score_f >> s;
			if (s->getcollege() == course)
				vecstu.push_back(*s);
		}
		if (vecstu.size() == 0)
		{
			cout << "这门课还没有录入成绩哦" << endl;
			continue;
		}
		cout << "对学号进行排序输入0，对成绩进行排序输入1：" << endl;
		cin >> str;
		cout << "按升序输出请按0，降序输出请按1：" << endl;
		cin >> str1;
		if (str == "1"&&str1 == "1")
		{
			sort(vecstu.begin(), vecstu.end(), CompScoreDown);
		}
		else if (str == "1"&&str1 == "0")
		{
			sort(vecstu.begin(), vecstu.end(), CompScoreUp);
		}
		else if (str == "0"&&str1 == "1")
		{
			sort(vecstu.begin(), vecstu.end(), CompIdDown);
		}
		else if (str == "0"&&str1 == "0")
		{
			sort(vecstu.begin(), vecstu.end(), CompIdUp);
		}
		num = 1;
		cout << std::left << setw(15) << "姓名" << "  " << setw(15) << "学号" << setw(15) << "成绩" << setw(15) << "序号" << endl;
		for (stu_it = vecstu.begin(); stu_it != vecstu.end(); stu_it++)
		{
			cout << std::left << setw(15) << stu_it->getname() << "  " << setw(15) << stu_it->getid() << setw(15) << stu_it->getscore() << setw(15) << num++ << endl;
		}
		vecstu.clear();
		vecstu.swap((std::vector <Student>)(vecstu));
	}
	delete s;
	Score_f.close();
}
