////#pragma once
//#include "MyClass.h"
//#include "My.h"
//int Readfile(vector<Required_Course>&re_c, vector<Elective_Course>&el_c, vector<Student>&stu, vector<Teacher>&tea)
//{
//	//读取必修课程信息
//	fstream Required("必修课程信息.txt", ios::in | ios::out);
//	if (!Required)
//	{
//		cout << "必修课程文件打开失败!";
//		return 0;
//	}
//	string number;
//	Required_Course l;
//	string course_name;
//	float credit;
//
//	//Course_file.seekg(0, ios::end);
//	while (!Required.eof())
//	{
//		Required >> course_name;
//		l.setcourse_name(course_name);
//		Required >> number;
//		l.set_number(number);
//		Required >> credit;
//		l.set_credit(credit);
//		re_c.push_back(l);
//	}
//	Required.close();
//
//
//	//选修课程文件读取
//	fstream Elective("选修课程信息.txt", ios::in | ios::out);
//	if (!Elective)
//	{
//		cout << "选修课程文件打开失败!";
//		return 0;
//	}
//
//	Elective_Course ec;
//	while (!Elective.eof())
//	{
//		Elective >> course_name;
//		ec.setcourse_name(course_name);
//		Elective >> number;
//		ec.set_number(number);
//		Elective >> credit;
//		ec.set_credit(credit);
//		el_c.push_back(ec);
//	}
//	Elective.close();
//
//	//学生信息读取
//	fstream Stuf("学生信息.txt", ios::in | ios::out);
//	if (!Stuf)
//	{
//		cout << "学生信息文件打开失败!";
//		return 0;
//	}
//	fstream Select_f("选课信息.txt", ios::in | ios::out);//trunc 意思是重写文件
//	if (!Select_f)
//	{
//		cout << "选课信息文件打开失败!" << endl;
//		return 0;
//	}
//	string id;                                 //学号
//	string name;                                     //姓名
//	string college;                                  //学院
//	string class_id;                        //班级
//	string kind;
//	string course;
//
//	string onecourse;
//
//	while (!Stuf.eof())
//	{
//		Student *s = new Student;
//		Stuf >> id;
//		s->setid(id);
//		Stuf >> name;
//		s->setname(name);
//		Stuf >> college;
//		s->setcollege(college);
//		Stuf >> class_id;
//		s->setclass_id(class_id);
//
//
//		Select_f.clear();
//		Select_f.seekg(0, ios::beg);
//		while (!Select_f.eof())
//		{
//			Select_f >> id;
//			Select_f >> name;
//			Select_f >> course;
//			Select_f >> kind;
//			if (kind == "选修课"&&name == s->getname())
//			{
//				s->addelcourse(course);
//			}
//		}
//		/*Stuf >> onecourse;
//		while (onecourse != "选修课")
//		{
//		s.addelcourse(onecourse);
//		Stuf >> onecourse;
//		}*/
//
//
//		stu.push_back(*s);
//		delete s;
//	}
//	Stuf.close();
//	Select_f.close();
//
//	//教师信息读取
//	fstream Teaf("教师信息.txt", ios::in | ios::out);
//	if (!Teaf)
//	{
//		cout << "教师信息文件打开失败!";
//		return 0;
//	}
//
//	vector<string>recourse;                //任课课程
//	vector<string>elcourse;
//	Teacher t;
//	while (!Teaf.eof())
//	{
//		recourse.clear();
//		elcourse.clear();
//		Teaf >> id;
//		t.setid(id);
//		Teaf >> name;
//		t.setname(name);
//		Teaf >> college;
//		t.setcollege(college);
//		Teaf >> onecourse;
//		while (onecourse != "必修课")
//		{
//			recourse.push_back(onecourse);
//			Teaf >> onecourse;
//		}
//		t.setrecourse(recourse);
//		Teaf >> onecourse;
//		while (onecourse != "选修课")
//		{
//			elcourse.push_back(onecourse);
//			Teaf >> onecourse;
//		}
//		t.setelcourse(elcourse);
//
//		tea.push_back(t);
//	}
//
//
//	Teaf.close();
//}
//
////选课信息写入文件
//int WriteSelectCourse(vector<Required_Course>&re_c, vector<Elective_Course>&el_c, vector<Student>&stu, vector<Teacher>&tea)
//{
//	fstream Select_f("选课信息.txt", ios::in | ios::out | ios::trunc);//trunc 意思是重写文件
//	if (!Select_f)
//	{
//		cout << "选课信息文件打开失败!" << endl;
//		return 0;
//	}
//	vector<string>::iterator str_it;
//	for (stu_it = stu.begin(); stu_it != stu.end(); stu_it++)
//	{
//		for (re_c_it = re_c.begin(); re_c_it != re_c.end(); re_c_it++)
//		{
//			Select_f << stu_it->getid() << ' ';
//			Select_f << stu_it->getname() << ' ';
//			Select_f << re_c_it->getcourse_name() << ' ';
//			Select_f << "必修课";
//			Select_f << endl;
//		}
//		for (int i = 0; i<stu_it->getelcourse().size(); i++)
//		{
//			Select_f << stu_it->getid() << ' ';
//			Select_f << stu_it->getname() << ' ';
//			Select_f << stu_it->getelcourse()[i] << ' ';
//			Select_f << "选修课";
//			Select_f << endl;
//		}
//	}
//
//
//
//	Select_f.close();
//}
//
////查看所有课程信息
//void ViewAllCourse()
//{
//	cout << "必修课如下:" << endl;
//	cout << std::left << setw(20) << "课程名称" << setw(15) << "课程编号" << setw(15) << "课程学分" << endl;
//	for (re_c_it = re_c.begin(); re_c_it != re_c.end(); re_c_it++)
//	{
//		cout << std::left << setw(20) << re_c_it->getcourse_name();
//		cout << std::left << setw(15) << re_c_it->getnumber();
//		cout << std::left << setw(15) << re_c_it->getcredit();
//		cout << endl;
//	}
//	cout << "选修课如下:" << endl;
//	cout << std::left << setw(20) << "课程名称" << setw(15) << "课程编号" << setw(15) << "课程学分" << endl;
//	for (el_c_it = el_c.begin(); el_c_it != el_c.end(); el_c_it++)
//	{
//		cout << std::left << setw(20) << el_c_it->getcourse_name();
//		cout << std::left << setw(15) << el_c_it->getnumber();
//		cout << std::left << setw(15) << el_c_it->getcredit();
//		cout << endl;
//	}
//	cout << endl;
//}
////学生查找自己的所有已有课程
//void FindMyCourse(string name)
//{
//	fstream Select_f("选课信息.txt", ios::in | ios::out);
//	if (!Select_f)
//	{
//		cout << "选课信息文件打开失败!" << endl;
//		return;
//	}
//	string str;
//	int Isfind = 0;
//	cout << "你的必修课有：" << endl;
//
//	for (int i = 0; i < re_c.size(); i++)
//	{
//		cout << re_c[i].getcourse_name() << "  ";
//		Isfind = 1;
//	}
//	cout << endl << "你的选修课有：" << endl;
//	for (stu_it = stu.begin(); stu_it != stu.end(); stu_it++)
//	{
//		if (stu_it->getname() == name)
//		{
//			for (int i = 0; i < stu_it->getelcourse().size(); stu_it++)
//			{
//				cout << stu_it->getelcourse()[i] << "  ";
//				Isfind = 2;
//			}
//		}
//	}
//
//	if (Isfind == 1) cout << "无";
//	cout << endl;
//	if (!Isfind) cout << "没有找到" << name << "的数据哦！" << endl;
//
//}
//
////学生查看并选择可选选修课
//void ViewAndSelectElCourse(string name)
//{
//	cout << "以下为学校所有选修课：" << endl;
//	//选修课信息
//	cout << std::left << setw(20) << "课程名称" << setw(15) << "课程编号" << setw(15) << "课程学分" << endl;
//	for (el_c_it = el_c.begin(); el_c_it != el_c.end(); el_c_it++)
//	{
//		cout << std::left << setw(20) << el_c_it->getcourse_name();
//		cout << std::left << setw(15) << el_c_it->getcredit();
//		cout << std::left << setw(15) << el_c_it->getnumber();
//		cout << endl;
//	}
//	cout << endl;
//	string course;
//	int Isfind = 0;
//	while (1)
//	{
//		Isfind = 0;
//		cout << "请选择你想选的选修课(输入课程名字,返回请输入0):" << endl;
//		cin >> course;
//		if (course == "0") break;
//		//确认选修课名字是否输入正确
//		for (el_c_it = el_c.begin(); el_c_it != el_c.end(); el_c_it++)
//		{
//			if (el_c_it->getcourse_name() == course)
//			{
//				Isfind = 1;
//				break;
//			}
//		}
//		if (!Isfind)
//		{
//			cout << endl << "有这个选修课吗，是不是打错了？" << endl << endl;
//			continue;
//		}
//		Isfind = 0;
//		//确认学生是否已选该课程
//		for (stu_it = stu.begin(); stu_it != stu.end(); stu_it++)
//		{
//			if (stu_it->getname() == name)
//			{
//				break;
//			}
//		}
//		//如果找到了
//		for (int i = 0; i<stu_it->getelcourse().size(); i++)
//		{
//			if (stu_it->getelcourse()[i] == course)
//			{
//				Isfind = 1;
//				break;
//			}
//		}
//		if (Isfind)
//			cout << endl << "你已经选过这门课了，给别的同学一个机会吧!" << endl << endl;
//		else
//		{
//			cout << endl << "抢课成功！" << endl << endl;
//			stu_it->addelcourse(course);
//		}
//	}
//
//}
//
////学生删除已选选修课
//void DeleteElCourse(string name)
//{
//	for (stu_it = stu.begin(); stu_it != stu.end(); stu_it++)
//	{
//		if (stu_it->getname() == name)
//		{
//			break;
//		}
//	}
//
//	//如果你没有选修课
//	if (stu_it->getelcourse().size() == 0)
//	{
//		cout << "你还没选上课那，去选课吧！" << endl << endl;
//		return;
//	}
//	cout << "以下为你已经选择的选修课：" << endl;
//	//选修课信息
//	cout << std::left << setw(20) << "课程名称" << setw(15) << "课程编号" << setw(15) << "课程学分" << endl;
//	string course;
//	for (int i = 0; i < stu_it->getelcourse().size(); i++)
//	{
//		course = stu_it->getelcourse()[i];
//		for (el_c_it = el_c.begin(); el_c_it != el_c.end(); el_c_it++)
//		{
//			if (course == el_c_it->getcourse_name()) {
//				cout << std::left << setw(20) << el_c_it->getcourse_name();
//				cout << std::left << setw(15) << el_c_it->getcredit();
//				cout << std::left << setw(15) << el_c_it->getnumber();
//				cout << endl;
//				break;
//			}
//		}
//	}
//
//
//	int Isfind = 0;
//	string str;
//	cout << "请输入你要删除的课程(输入0返回):" << endl;
//	cin >> course;
//	if (course == "0") return;
//	//查看成绩是否已提交
//	fstream Score_f("课程成绩.txt", ios::in | ios::out);
//	if (!Score_f)
//	{
//		cout << "课程成绩文件打开失败!" << endl;
//		return;
//	}
//	while (getline(Score_f, str))
//	{
//		if (str.find(name) != string::npos&&str.find(course) != string::npos&&str.find("已提交") != string::npos)
//		{
//			cout << "课程成绩已提交，无法删除课程！" << endl;
//			Score_f.close();
//			return;
//		}
//	}
//	stu_it->deleteelcourse(course);
//	Score_f.close();
//
//}
//
////由名字寻找学生
//vector<Student>::iterator FindStuFromVec(string name)
//{
//	for (stu_it = stu.begin(); stu_it != stu.end(); stu_it++)
//	{
//		if (stu_it->getname() == name)
//			return stu_it;
//	}
//	cout << "没有找到" << name << "的信息!" << endl;
//
//}
//
////查看自己的学生信息
//void ViewMyStudent(string name)
//{
//	int i, Isfind = 0;
//	string str;
//	string course;
//	ifstream Select_f("选课信息.txt");                //这里用fstream会有奇怪的bug
//	if (!Select_f)
//	{
//		cout << "选课信息文件打开失败!" << endl;
//		return;
//	}
//	for (i = 0; i < tea.size(); i++)
//	{
//		if (tea[i].getname() == name)
//			break;
//	}
//	//寻找必修课的学生
//	for (int j = 0; j < tea[i].getrecourse().size(); j++)
//	{
//		course = tea[i].getrecourse()[j];
//		cout << "--必修--" << course << "的学生有：" << endl;
//		Select_f.clear();
//		Select_f.seekg(0, ios::beg);                 //把文件的读指针从文件开头位置向后移0个字节
//
//		for (stu_it = stu.begin(); stu_it != stu.end(); stu_it++)
//		{
//			cout << std::left << "学生姓名：" << setw(15) << stu_it->getname() << "  学号:" << setw(15) << stu_it->getid();
//			cout << "  班级:" << setw(15) << stu_it->getclass_id() << "  学院:" << setw(15) << stu_it->getcollege() << endl;
//		}
//		Isfind = 0;
//
//	}
//
//	//寻找选修课的学生
//	for (int j = 0; j < tea[i].getelcourse().size(); j++)
//	{
//		course = tea[i].getelcourse()[j];
//		Select_f.clear();
//		Select_f.seekg(0, ios::beg);//重置指针
//		cout << "--选修--" << course << "的学生有：" << endl;
//
//		for (stu_it = stu.begin(); stu_it != stu.end(); stu_it++)
//		{
//			for (int i = 0; i < stu_it->getelcourse().size(); i++)
//			{
//				if (stu_it->getelcourse()[i] == course)
//				{
//					cout << std::left << "学生姓名：" << setw(15) << stu_it->getname() << "  学号:" << setw(15) << stu_it->getid();
//					cout << "  班级:" << setw(15) << stu_it->getclass_id() << "  学院:" << setw(15) << stu_it->getcollege() << endl;
//				}
//			}
//		}
//		if (!Isfind) cout << "(这门课竟然没有学生。" << endl;
//		Isfind = 0;
//	}
//
//	while (1)
//	{
//		Isfind = 0;
//		cout << endl << "请选择你想查看学生信息的课程(输入0退出)：" << endl;
//		cin >> course;
//		if (course == "0") break;
//		for (int j = 0; j < tea[i].getrecourse().size(); j++)
//		{
//			if (course == tea[i].getrecourse()[j])
//			{
//				Isfind = 1;
//				break;
//			}
//		}
//		if (!Isfind)
//		{
//			for (int j = 0; j < tea[i].getelcourse().size(); j++)
//			{
//				if (course == tea[i].getelcourse()[j])
//				{
//					Isfind = 2;
//					break;
//				}
//			}
//		}
//		if (!Isfind)
//		{
//			cout << "这门不是你代的课，是不是输错了？" << endl;
//			continue;
//		}
//		Isfind = 0;
//		cout << endl << "请选择你想查看信息的学生姓名：" << endl;
//		string name;
//		cin >> name;
//		Select_f.clear();
//		Select_f.seekg(0, ios::beg);//重置指针
//		while (getline(Select_f, str))
//		{
//			if (str.find(name) != string::npos&&str.find(course) != string::npos)
//			{
//				stu_it = FindStuFromVec(name);
//				cout << "姓名：" << stu_it->getname() << "  学号:" << stu_it->getid() << "  学院:" << stu_it->getcollege();
//				cout << "  班级:" << stu_it->getclass_id() << endl;
//				Isfind = 1;
//				break;
//			}
//		}
//		if (!Isfind)
//			cout << "没有找到这个学生！" << endl;
//	}
//	Select_f.close();
//}
//
////打印老师代的课
//void PrintTeaCourse(string name)
//{
//	for (tea_it = tea.begin(); tea_it != tea.end(); tea_it++)
//	{
//		if (name == tea_it->getname())
//		{
//			for (int i = 0; i < tea_it->getrecourse().size(); i++)
//			{
//				if (i == 0) cout << "我代的必修课有：";
//				cout << tea_it->getrecourse()[i] << " ";
//			}
//			cout << endl;
//			for (int i = 0; i < tea_it->getelcourse().size(); i++)
//			{
//				if (i == 0) cout << "我代的选修课有：";
//				cout << tea_it->getelcourse()[i] << " ";
//			}
//			cout << endl;
//			return;
//		}
//	}
//}
//
////老师录入成绩
//void AddScore(string name)
//{
//
//	fstream Score_f("课程成绩.txt", ios::in | ios::out);
//	if (!Score_f)
//	{
//		cout << "课程成绩文件打开失败!" << endl;
//		return;
//	}
//	string course;
//	int Isfind = 0;
//	string score;
//	while (1)
//	{
//		Isfind = 0;        //必修课则值为1，选修为2
//		PrintTeaCourse(name);
//		cout << "请选择你想录入成绩的课程：(退出请输入0)" << endl;
//		cin >> course;
//		if (course == "0") break;
//		//确认这门课是否存在
//		for (int i = 0; i < tea_it->getrecourse().size(); i++)
//		{
//			if (course == tea_it->getrecourse()[i])
//			{
//				Isfind = 1;
//				break;
//			}
//		}
//		if (!Isfind)
//		{
//			for (int i = 0; i < tea_it->getelcourse().size(); i++)
//			{
//				if (course == tea_it->getelcourse()[i])
//				{
//					Isfind = 2;
//					break;
//				}
//			}
//		}
//
//		if (!Isfind)
//		{
//			cout << "你输入的课程有误，是不是输错了？" << endl;
//			continue;
//		}
//		//录入成绩（未提交
//		Score_f.seekg(0, ios::end);
//		if (Isfind == 1)
//		{
//			for (stu_it = stu.begin(); stu_it != stu.end(); stu_it++)
//			{
//				cout << "请为" << stu_it->getname() << "打分：";
//				cin >> score;
//				Score_f << stu_it->getname() << ' ' << course << ' ' << stu_it->getid() << ' ' << setw(8) << score << ' ' << "未提交" << endl;
//			}
//		}
//		else
//		{
//			for (stu_it = stu.begin(); stu_it != stu.end(); stu_it++)
//			{
//				for (int i = 0; i < stu_it->getelcourse().size(); i++)
//				{
//					if (stu_it->getelcourse()[i] == course)
//					{
//						cout << "请为" << stu_it->getname() << "打分：";
//						cin >> score;
//						Score_f << stu_it->getname() << ' ' << course << ' ' << stu_it->getid() << ' ' << setw(8) << score << ' ' << "未提交" << endl;
//						break;
//					}
//				}
//			}
//		}
//
//
//	}
//	Score_f.close();
//}
//
////老师提交成绩
//void SubmitScore(string name)
//{
//	fstream Score_f("课程成绩.txt", ios::in | ios::out);
//	if (!Score_f)
//	{
//		cout << "课程成绩文件打开失败!" << endl;
//		return;
//	}
//	string course;
//	int Isfind = 0;
//	string score;
//	while (1)
//	{
//		Isfind = 0;        //必修课则值为1，选修为2
//		PrintTeaCourse(name);
//		cout << "请选择你想提交成绩的课程：(退出请输入0)" << endl;
//		cin >> course;
//		if (course == "0") break;
//		//确认这门课是否存在
//		for (int i = 0; i < tea_it->getrecourse().size(); i++)
//		{
//			if (course == tea_it->getrecourse()[i])
//			{
//				Isfind = 1;
//				break;
//			}
//		}
//		if (!Isfind)
//		{
//			for (int i = 0; i < tea_it->getelcourse().size(); i++)
//			{
//				if (course == tea_it->getelcourse()[i])
//				{
//					Isfind = 2;
//					break;
//				}
//			}
//		}
//
//		if (!Isfind)
//		{
//			cout << "你输入的课程有误，是不是输错了？" << endl;
//			continue;
//		}
//		//提交成绩
//		string str;
//		long len = 0;
//		while (getline(Score_f, str))
//		{
//			if (str.find(course) != string::npos)
//			{
//				if (str.find("已提交") != string::npos)
//				{
//					cout << "成绩已提交！" << endl;
//					Isfind = 0;
//					break;
//				}
//				//	cout << str << endl;
//				//处理最后一行的情况
//				if (Score_f.eof())
//					Score_f.clear();
//
//				Score_f.seekg(len, ios::beg);
//				str.erase(str.end() - 6, str.end());
//				Score_f << str << "已提交" << endl;
//
//			}
//			len = Score_f.tellg();                                ///////////别的方法都有bug////////////
//		}
//
//
//		cout << "提交成功！" << endl;
//
//
//	}
//
//
//
//
//	Score_f.close();
//}
//
////老师修改成绩
//void ModifyScore(string name)
//{
//	fstream Score_f("课程成绩.txt", ios::in | ios::out);
//	if (!Score_f)
//	{
//		cout << "课程成绩文件打开失败!" << endl;
//		return;
//	}
//	string course;
//	int Isfind = 0;
//	string score;
//
//	while (1)
//	{
//		/////////*Score_f.clear();
//		////////Score_f.seekg(0, ios::beg);*/
//		Isfind = 0;        //必修课则值为1，选修为2
//		PrintTeaCourse(name);
//		cout << "请选择你想修改成绩的课程(输入0退出)：" << endl;
//		cin >> course;
//		if (course == "0") break;
//		//确认这门课是否存在
//		for (int i = 0; i < tea_it->getrecourse().size(); i++)
//		{
//			if (course == tea_it->getrecourse()[i])
//			{
//				Isfind = 1;
//				break;
//			}
//		}
//		if (!Isfind)
//		{
//			for (int i = 0; i < tea_it->getelcourse().size(); i++)
//			{
//				if (course == tea_it->getelcourse()[i])
//				{
//					Isfind = 2;
//					break;
//				}
//			}
//		}
//
//		if (!Isfind)
//		{
//			cout << "你输入的课程有误，是不是输错了？" << endl;
//			continue;
//		}
//
//		cout << "哪位同学中奖了呢？ " << endl;
//		string stuname;
//		string str;
//		long len = 0;
//		string modifyscore;
//		cin >> stuname;
//		stu_it = FindStuFromVec(stuname);
//		//修改成绩
//		Score_f.clear();
//		Score_f.seekg(0, ios::beg);
//		while (getline(Score_f, str))
//		{
//			if (str.find(stuname) != string::npos&&str.find(course) != string::npos)
//			{
//				if (str.find("已提交") != string::npos)
//				{
//					cout << "成绩已提交，无法修改！" << endl;
//					Isfind = 11;
//					break;
//				}
//				cout << str << endl;
//				Isfind = 1;
//				cout << "他应得的分数是： " << endl;
//				cin >> modifyscore;
//				if (Score_f.eof())
//					Score_f.clear();
//
//				Score_f.seekg(len, ios::beg);
//				Score_f << stu_it->getname() << ' ' << course << ' ' << stu_it->getid() << ' ' << setw(8) << modifyscore << ' ' << "未提交" << endl;
//				cout << "修改成功！" << endl;
//
//			}
//			len = Score_f.tellg();                                ///////////别的方法都有bug////////////
//		}
//
//		if (!Isfind)
//		{
//			cout << "没有找到学生信息！" << endl;
//			Isfind = 0;
//			continue;
//		}
//
//
//
//	}
//
//
//
//
//	Score_f.close();
//}
//
////学生查看成绩和绩点
//void ViewMyScore(string name)
//{
//	fstream Score_f("课程成绩.txt", ios::in | ios::out);
//	if (!Score_f)
//	{
//		cout << "课程成绩文件打开失败!" << endl;
//		return;
//	}
//
//	string course, str, id, score, Issubmit, stuname, stucourse;
//	int Isfind = 0;
//	float gpa;
//	cout << "你想查看哪门课的成绩(想看全部成绩请输入1)：" << endl;
//	cin >> course;
//	//输出全部已提交成绩
//	if (course == "1")
//	{
//		while (!Score_f.eof())
//		{
//			Isfind = 0;
//			Score_f >> stuname;
//			Score_f >> stucourse;
//			Score_f >> id;
//			Score_f >> score;
//			Score_f >> Issubmit;
//			if (stuname == name)
//			{
//				if (Issubmit == "未提交")
//				{
//					Isfind = 0;
//					continue;
//				}
//				for (re_c_it = re_c.begin(); re_c_it != re_c.end(); re_c_it++)
//				{
//					if (re_c_it->getcourse_name() == stucourse)
//					{
//						Isfind = 1;
//						break;
//					}
//				}
//				if (Isfind == 0)
//					for (el_c_it = el_c.begin(); el_c_it != el_c.end(); el_c_it++)
//					{
//						if (el_c_it->getcourse_name() == stucourse) {
//							Isfind = 2;
//							break;
//						}
//					}
//				if (Isfind == 1) gpa = re_c_it->count_gpa(stucourse, stuname);
//				else if (Isfind == 2) gpa = el_c_it->count_gpa(stucourse, stuname);
//				cout << "你的" << stucourse << "的成绩为：" << score << ",绩点为：" << gpa << endl;
//
//			}
//
//		}
//		Score_f.close();
//		return;
//	}
//	for (re_c_it = re_c.begin(); re_c_it != re_c.end(); re_c_it++)
//	{
//		if (re_c_it->getcourse_name() == course)
//		{
//			Isfind = 1;
//			break;
//		}
//	}
//	for (el_c_it = el_c.begin(); el_c_it != el_c.end(); el_c_it++)
//	{
//		if (el_c_it->getcourse_name() == course) {
//			Isfind = 2;
//			break;
//		}
//	}
//
//	while (!Score_f.eof())
//	{
//		Isfind = 0;
//		Score_f >> stuname;
//		Score_f >> stucourse;
//		Score_f >> id;
//		Score_f >> score;
//		Score_f >> Issubmit;
//		if (stuname == name && stucourse == course)
//		{
//			if (Issubmit == "未提交")
//			{
//				cout << "成绩未提交，无法查看！" << endl << endl;
//				Isfind = 0;
//				break;
//			}
//			if (Isfind == 1) gpa = re_c_it->count_gpa(stucourse, stuname);
//			else if (Isfind == 2) gpa = el_c_it->count_gpa(stucourse, stuname);
//			cout << "你的" << course << "的成绩为：" << score << ",绩点为：" << gpa << endl;
//			break;
//		}
//		Isfind = 4;
//	}
//	if (Isfind == 4)
//		cout << "没有找到这门课的成绩！" << endl << endl;
//	Score_f.close();
//	return;
//}
//
//void print()
//{
//	int iden, choice;
//	string name;
//	int IsLogout = 0;
//	while (1)
//	{
//		system("cls");
//		IsLogout = 0;
//		cout << "请选择身份：" << endl;
//		cout << "1.教师" << endl;
//		cout << "2.学生" << endl;
//		cin >> iden;
//		cout << "请输入你的名字：" << endl;
//		//名字先默认输入正确吧
//		cin >> name;
//
//		while (1)
//		{
//
//			if (iden == 2)
//			{
//				;
//				cout << "请选择操作：" << endl;
//				cout << "1.查看自己所有课程" << endl;
//				cout << "2.查看并选择所有可选选修课" << endl;
//				cout << "3.放弃已选选修课" << endl;
//				cout << "4.查看课程成绩与绩点" << endl;
//				cout << "5.查看学校所有课程信息" << endl;
//				cout << "6.注销" << endl;
//				cin >> choice;
//				switch (choice)
//				{
//				case 1:
//					FindMyCourse(name);
//					break;
//				case 2:
//					ViewAndSelectElCourse(name);
//					break;
//				case 3:
//					DeleteElCourse(name);
//					break;
//				case 4:
//					ViewMyScore(name);
//					break;
//				case 5:
//					ViewAllCourse();
//					break;
//				case 6:
//					IsLogout = 1;
//					break;
//				default:
//					break;
//				} //end for switch
//
//			}//end for if
//			else
//			{
//				cout << endl;
//				cout << "请选择操作：" << endl;
//				cout << "1.查看自己所有课程" << endl;
//				cout << "2.查看自己课程的学生名单" << endl;
//				cout << "3.录入学生成绩" << endl;
//				cout << "4.修改学生成绩" << endl;
//				cout << "5.提交学生成绩" << endl;
//				cout << "6.查看学校所有课程信息" << endl;
//				cout << "7.注销" << endl;
//				cin >> choice;
//				switch (choice)
//				{
//				case 1:
//					PrintTeaCourse(name);
//					break;
//				case 2:
//					ViewMyStudent(name);
//					break;
//				case 3:
//					AddScore(name);
//					break;
//				case 4:
//					ModifyScore(name);
//					break;
//				case 5:
//					SubmitScore(name);
//					break;
//				case 6:
//					ViewAllCourse();
//					break;
//				case 7:
//					IsLogout = 1;
//					break;
//				default:
//					break;
//				}
//			}
//			WriteSelectCourse(re_c, el_c, stu, tea);
//			if (IsLogout) break;
//		}// end for while
//	}// end for while
//}
//
//
//
//
//
//
//
//
