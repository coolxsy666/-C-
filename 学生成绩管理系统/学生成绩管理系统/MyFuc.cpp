////#pragma once
//#include "MyClass.h"
//#include "My.h"
//int Readfile(vector<Required_Course>&re_c, vector<Elective_Course>&el_c, vector<Student>&stu, vector<Teacher>&tea)
//{
//	//��ȡ���޿γ���Ϣ
//	fstream Required("���޿γ���Ϣ.txt", ios::in | ios::out);
//	if (!Required)
//	{
//		cout << "���޿γ��ļ���ʧ��!";
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
//	//ѡ�޿γ��ļ���ȡ
//	fstream Elective("ѡ�޿γ���Ϣ.txt", ios::in | ios::out);
//	if (!Elective)
//	{
//		cout << "ѡ�޿γ��ļ���ʧ��!";
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
//	//ѧ����Ϣ��ȡ
//	fstream Stuf("ѧ����Ϣ.txt", ios::in | ios::out);
//	if (!Stuf)
//	{
//		cout << "ѧ����Ϣ�ļ���ʧ��!";
//		return 0;
//	}
//	fstream Select_f("ѡ����Ϣ.txt", ios::in | ios::out);//trunc ��˼����д�ļ�
//	if (!Select_f)
//	{
//		cout << "ѡ����Ϣ�ļ���ʧ��!" << endl;
//		return 0;
//	}
//	string id;                                 //ѧ��
//	string name;                                     //����
//	string college;                                  //ѧԺ
//	string class_id;                        //�༶
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
//			if (kind == "ѡ�޿�"&&name == s->getname())
//			{
//				s->addelcourse(course);
//			}
//		}
//		/*Stuf >> onecourse;
//		while (onecourse != "ѡ�޿�")
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
//	//��ʦ��Ϣ��ȡ
//	fstream Teaf("��ʦ��Ϣ.txt", ios::in | ios::out);
//	if (!Teaf)
//	{
//		cout << "��ʦ��Ϣ�ļ���ʧ��!";
//		return 0;
//	}
//
//	vector<string>recourse;                //�οογ�
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
//		while (onecourse != "���޿�")
//		{
//			recourse.push_back(onecourse);
//			Teaf >> onecourse;
//		}
//		t.setrecourse(recourse);
//		Teaf >> onecourse;
//		while (onecourse != "ѡ�޿�")
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
////ѡ����Ϣд���ļ�
//int WriteSelectCourse(vector<Required_Course>&re_c, vector<Elective_Course>&el_c, vector<Student>&stu, vector<Teacher>&tea)
//{
//	fstream Select_f("ѡ����Ϣ.txt", ios::in | ios::out | ios::trunc);//trunc ��˼����д�ļ�
//	if (!Select_f)
//	{
//		cout << "ѡ����Ϣ�ļ���ʧ��!" << endl;
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
//			Select_f << "���޿�";
//			Select_f << endl;
//		}
//		for (int i = 0; i<stu_it->getelcourse().size(); i++)
//		{
//			Select_f << stu_it->getid() << ' ';
//			Select_f << stu_it->getname() << ' ';
//			Select_f << stu_it->getelcourse()[i] << ' ';
//			Select_f << "ѡ�޿�";
//			Select_f << endl;
//		}
//	}
//
//
//
//	Select_f.close();
//}
//
////�鿴���пγ���Ϣ
//void ViewAllCourse()
//{
//	cout << "���޿�����:" << endl;
//	cout << std::left << setw(20) << "�γ�����" << setw(15) << "�γ̱��" << setw(15) << "�γ�ѧ��" << endl;
//	for (re_c_it = re_c.begin(); re_c_it != re_c.end(); re_c_it++)
//	{
//		cout << std::left << setw(20) << re_c_it->getcourse_name();
//		cout << std::left << setw(15) << re_c_it->getnumber();
//		cout << std::left << setw(15) << re_c_it->getcredit();
//		cout << endl;
//	}
//	cout << "ѡ�޿�����:" << endl;
//	cout << std::left << setw(20) << "�γ�����" << setw(15) << "�γ̱��" << setw(15) << "�γ�ѧ��" << endl;
//	for (el_c_it = el_c.begin(); el_c_it != el_c.end(); el_c_it++)
//	{
//		cout << std::left << setw(20) << el_c_it->getcourse_name();
//		cout << std::left << setw(15) << el_c_it->getnumber();
//		cout << std::left << setw(15) << el_c_it->getcredit();
//		cout << endl;
//	}
//	cout << endl;
//}
////ѧ�������Լ����������пγ�
//void FindMyCourse(string name)
//{
//	fstream Select_f("ѡ����Ϣ.txt", ios::in | ios::out);
//	if (!Select_f)
//	{
//		cout << "ѡ����Ϣ�ļ���ʧ��!" << endl;
//		return;
//	}
//	string str;
//	int Isfind = 0;
//	cout << "��ı��޿��У�" << endl;
//
//	for (int i = 0; i < re_c.size(); i++)
//	{
//		cout << re_c[i].getcourse_name() << "  ";
//		Isfind = 1;
//	}
//	cout << endl << "���ѡ�޿��У�" << endl;
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
//	if (Isfind == 1) cout << "��";
//	cout << endl;
//	if (!Isfind) cout << "û���ҵ�" << name << "������Ŷ��" << endl;
//
//}
//
////ѧ���鿴��ѡ���ѡѡ�޿�
//void ViewAndSelectElCourse(string name)
//{
//	cout << "����ΪѧУ����ѡ�޿Σ�" << endl;
//	//ѡ�޿���Ϣ
//	cout << std::left << setw(20) << "�γ�����" << setw(15) << "�γ̱��" << setw(15) << "�γ�ѧ��" << endl;
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
//		cout << "��ѡ������ѡ��ѡ�޿�(����γ�����,����������0):" << endl;
//		cin >> course;
//		if (course == "0") break;
//		//ȷ��ѡ�޿������Ƿ�������ȷ
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
//			cout << endl << "�����ѡ�޿����ǲ��Ǵ���ˣ�" << endl << endl;
//			continue;
//		}
//		Isfind = 0;
//		//ȷ��ѧ���Ƿ���ѡ�ÿγ�
//		for (stu_it = stu.begin(); stu_it != stu.end(); stu_it++)
//		{
//			if (stu_it->getname() == name)
//			{
//				break;
//			}
//		}
//		//����ҵ���
//		for (int i = 0; i<stu_it->getelcourse().size(); i++)
//		{
//			if (stu_it->getelcourse()[i] == course)
//			{
//				Isfind = 1;
//				break;
//			}
//		}
//		if (Isfind)
//			cout << endl << "���Ѿ�ѡ�����ſ��ˣ������ͬѧһ�������!" << endl << endl;
//		else
//		{
//			cout << endl << "���γɹ���" << endl << endl;
//			stu_it->addelcourse(course);
//		}
//	}
//
//}
//
////ѧ��ɾ����ѡѡ�޿�
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
//	//�����û��ѡ�޿�
//	if (stu_it->getelcourse().size() == 0)
//	{
//		cout << "�㻹ûѡ�Ͽ��ǣ�ȥѡ�ΰɣ�" << endl << endl;
//		return;
//	}
//	cout << "����Ϊ���Ѿ�ѡ���ѡ�޿Σ�" << endl;
//	//ѡ�޿���Ϣ
//	cout << std::left << setw(20) << "�γ�����" << setw(15) << "�γ̱��" << setw(15) << "�γ�ѧ��" << endl;
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
//	cout << "��������Ҫɾ���Ŀγ�(����0����):" << endl;
//	cin >> course;
//	if (course == "0") return;
//	//�鿴�ɼ��Ƿ����ύ
//	fstream Score_f("�γ̳ɼ�.txt", ios::in | ios::out);
//	if (!Score_f)
//	{
//		cout << "�γ̳ɼ��ļ���ʧ��!" << endl;
//		return;
//	}
//	while (getline(Score_f, str))
//	{
//		if (str.find(name) != string::npos&&str.find(course) != string::npos&&str.find("���ύ") != string::npos)
//		{
//			cout << "�γ̳ɼ����ύ���޷�ɾ���γ̣�" << endl;
//			Score_f.close();
//			return;
//		}
//	}
//	stu_it->deleteelcourse(course);
//	Score_f.close();
//
//}
//
////������Ѱ��ѧ��
//vector<Student>::iterator FindStuFromVec(string name)
//{
//	for (stu_it = stu.begin(); stu_it != stu.end(); stu_it++)
//	{
//		if (stu_it->getname() == name)
//			return stu_it;
//	}
//	cout << "û���ҵ�" << name << "����Ϣ!" << endl;
//
//}
//
////�鿴�Լ���ѧ����Ϣ
//void ViewMyStudent(string name)
//{
//	int i, Isfind = 0;
//	string str;
//	string course;
//	ifstream Select_f("ѡ����Ϣ.txt");                //������fstream������ֵ�bug
//	if (!Select_f)
//	{
//		cout << "ѡ����Ϣ�ļ���ʧ��!" << endl;
//		return;
//	}
//	for (i = 0; i < tea.size(); i++)
//	{
//		if (tea[i].getname() == name)
//			break;
//	}
//	//Ѱ�ұ��޿ε�ѧ��
//	for (int j = 0; j < tea[i].getrecourse().size(); j++)
//	{
//		course = tea[i].getrecourse()[j];
//		cout << "--����--" << course << "��ѧ���У�" << endl;
//		Select_f.clear();
//		Select_f.seekg(0, ios::beg);                 //���ļ��Ķ�ָ����ļ���ͷλ�������0���ֽ�
//
//		for (stu_it = stu.begin(); stu_it != stu.end(); stu_it++)
//		{
//			cout << std::left << "ѧ��������" << setw(15) << stu_it->getname() << "  ѧ��:" << setw(15) << stu_it->getid();
//			cout << "  �༶:" << setw(15) << stu_it->getclass_id() << "  ѧԺ:" << setw(15) << stu_it->getcollege() << endl;
//		}
//		Isfind = 0;
//
//	}
//
//	//Ѱ��ѡ�޿ε�ѧ��
//	for (int j = 0; j < tea[i].getelcourse().size(); j++)
//	{
//		course = tea[i].getelcourse()[j];
//		Select_f.clear();
//		Select_f.seekg(0, ios::beg);//����ָ��
//		cout << "--ѡ��--" << course << "��ѧ���У�" << endl;
//
//		for (stu_it = stu.begin(); stu_it != stu.end(); stu_it++)
//		{
//			for (int i = 0; i < stu_it->getelcourse().size(); i++)
//			{
//				if (stu_it->getelcourse()[i] == course)
//				{
//					cout << std::left << "ѧ��������" << setw(15) << stu_it->getname() << "  ѧ��:" << setw(15) << stu_it->getid();
//					cout << "  �༶:" << setw(15) << stu_it->getclass_id() << "  ѧԺ:" << setw(15) << stu_it->getcollege() << endl;
//				}
//			}
//		}
//		if (!Isfind) cout << "(���ſξ�Ȼû��ѧ����" << endl;
//		Isfind = 0;
//	}
//
//	while (1)
//	{
//		Isfind = 0;
//		cout << endl << "��ѡ������鿴ѧ����Ϣ�Ŀγ�(����0�˳�)��" << endl;
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
//			cout << "���Ų�������ĿΣ��ǲ�������ˣ�" << endl;
//			continue;
//		}
//		Isfind = 0;
//		cout << endl << "��ѡ������鿴��Ϣ��ѧ��������" << endl;
//		string name;
//		cin >> name;
//		Select_f.clear();
//		Select_f.seekg(0, ios::beg);//����ָ��
//		while (getline(Select_f, str))
//		{
//			if (str.find(name) != string::npos&&str.find(course) != string::npos)
//			{
//				stu_it = FindStuFromVec(name);
//				cout << "������" << stu_it->getname() << "  ѧ��:" << stu_it->getid() << "  ѧԺ:" << stu_it->getcollege();
//				cout << "  �༶:" << stu_it->getclass_id() << endl;
//				Isfind = 1;
//				break;
//			}
//		}
//		if (!Isfind)
//			cout << "û���ҵ����ѧ����" << endl;
//	}
//	Select_f.close();
//}
//
////��ӡ��ʦ���Ŀ�
//void PrintTeaCourse(string name)
//{
//	for (tea_it = tea.begin(); tea_it != tea.end(); tea_it++)
//	{
//		if (name == tea_it->getname())
//		{
//			for (int i = 0; i < tea_it->getrecourse().size(); i++)
//			{
//				if (i == 0) cout << "�Ҵ��ı��޿��У�";
//				cout << tea_it->getrecourse()[i] << " ";
//			}
//			cout << endl;
//			for (int i = 0; i < tea_it->getelcourse().size(); i++)
//			{
//				if (i == 0) cout << "�Ҵ���ѡ�޿��У�";
//				cout << tea_it->getelcourse()[i] << " ";
//			}
//			cout << endl;
//			return;
//		}
//	}
//}
//
////��ʦ¼��ɼ�
//void AddScore(string name)
//{
//
//	fstream Score_f("�γ̳ɼ�.txt", ios::in | ios::out);
//	if (!Score_f)
//	{
//		cout << "�γ̳ɼ��ļ���ʧ��!" << endl;
//		return;
//	}
//	string course;
//	int Isfind = 0;
//	string score;
//	while (1)
//	{
//		Isfind = 0;        //���޿���ֵΪ1��ѡ��Ϊ2
//		PrintTeaCourse(name);
//		cout << "��ѡ������¼��ɼ��Ŀγ̣�(�˳�������0)" << endl;
//		cin >> course;
//		if (course == "0") break;
//		//ȷ�����ſ��Ƿ����
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
//			cout << "������Ŀγ������ǲ�������ˣ�" << endl;
//			continue;
//		}
//		//¼��ɼ���δ�ύ
//		Score_f.seekg(0, ios::end);
//		if (Isfind == 1)
//		{
//			for (stu_it = stu.begin(); stu_it != stu.end(); stu_it++)
//			{
//				cout << "��Ϊ" << stu_it->getname() << "��֣�";
//				cin >> score;
//				Score_f << stu_it->getname() << ' ' << course << ' ' << stu_it->getid() << ' ' << setw(8) << score << ' ' << "δ�ύ" << endl;
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
//						cout << "��Ϊ" << stu_it->getname() << "��֣�";
//						cin >> score;
//						Score_f << stu_it->getname() << ' ' << course << ' ' << stu_it->getid() << ' ' << setw(8) << score << ' ' << "δ�ύ" << endl;
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
////��ʦ�ύ�ɼ�
//void SubmitScore(string name)
//{
//	fstream Score_f("�γ̳ɼ�.txt", ios::in | ios::out);
//	if (!Score_f)
//	{
//		cout << "�γ̳ɼ��ļ���ʧ��!" << endl;
//		return;
//	}
//	string course;
//	int Isfind = 0;
//	string score;
//	while (1)
//	{
//		Isfind = 0;        //���޿���ֵΪ1��ѡ��Ϊ2
//		PrintTeaCourse(name);
//		cout << "��ѡ�������ύ�ɼ��Ŀγ̣�(�˳�������0)" << endl;
//		cin >> course;
//		if (course == "0") break;
//		//ȷ�����ſ��Ƿ����
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
//			cout << "������Ŀγ������ǲ�������ˣ�" << endl;
//			continue;
//		}
//		//�ύ�ɼ�
//		string str;
//		long len = 0;
//		while (getline(Score_f, str))
//		{
//			if (str.find(course) != string::npos)
//			{
//				if (str.find("���ύ") != string::npos)
//				{
//					cout << "�ɼ����ύ��" << endl;
//					Isfind = 0;
//					break;
//				}
//				//	cout << str << endl;
//				//�������һ�е����
//				if (Score_f.eof())
//					Score_f.clear();
//
//				Score_f.seekg(len, ios::beg);
//				str.erase(str.end() - 6, str.end());
//				Score_f << str << "���ύ" << endl;
//
//			}
//			len = Score_f.tellg();                                ///////////��ķ�������bug////////////
//		}
//
//
//		cout << "�ύ�ɹ���" << endl;
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
////��ʦ�޸ĳɼ�
//void ModifyScore(string name)
//{
//	fstream Score_f("�γ̳ɼ�.txt", ios::in | ios::out);
//	if (!Score_f)
//	{
//		cout << "�γ̳ɼ��ļ���ʧ��!" << endl;
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
//		Isfind = 0;        //���޿���ֵΪ1��ѡ��Ϊ2
//		PrintTeaCourse(name);
//		cout << "��ѡ�������޸ĳɼ��Ŀγ�(����0�˳�)��" << endl;
//		cin >> course;
//		if (course == "0") break;
//		//ȷ�����ſ��Ƿ����
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
//			cout << "������Ŀγ������ǲ�������ˣ�" << endl;
//			continue;
//		}
//
//		cout << "��λͬѧ�н����أ� " << endl;
//		string stuname;
//		string str;
//		long len = 0;
//		string modifyscore;
//		cin >> stuname;
//		stu_it = FindStuFromVec(stuname);
//		//�޸ĳɼ�
//		Score_f.clear();
//		Score_f.seekg(0, ios::beg);
//		while (getline(Score_f, str))
//		{
//			if (str.find(stuname) != string::npos&&str.find(course) != string::npos)
//			{
//				if (str.find("���ύ") != string::npos)
//				{
//					cout << "�ɼ����ύ���޷��޸ģ�" << endl;
//					Isfind = 11;
//					break;
//				}
//				cout << str << endl;
//				Isfind = 1;
//				cout << "��Ӧ�õķ����ǣ� " << endl;
//				cin >> modifyscore;
//				if (Score_f.eof())
//					Score_f.clear();
//
//				Score_f.seekg(len, ios::beg);
//				Score_f << stu_it->getname() << ' ' << course << ' ' << stu_it->getid() << ' ' << setw(8) << modifyscore << ' ' << "δ�ύ" << endl;
//				cout << "�޸ĳɹ���" << endl;
//
//			}
//			len = Score_f.tellg();                                ///////////��ķ�������bug////////////
//		}
//
//		if (!Isfind)
//		{
//			cout << "û���ҵ�ѧ����Ϣ��" << endl;
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
////ѧ���鿴�ɼ��ͼ���
//void ViewMyScore(string name)
//{
//	fstream Score_f("�γ̳ɼ�.txt", ios::in | ios::out);
//	if (!Score_f)
//	{
//		cout << "�γ̳ɼ��ļ���ʧ��!" << endl;
//		return;
//	}
//
//	string course, str, id, score, Issubmit, stuname, stucourse;
//	int Isfind = 0;
//	float gpa;
//	cout << "����鿴���ſεĳɼ�(�뿴ȫ���ɼ�������1)��" << endl;
//	cin >> course;
//	//���ȫ�����ύ�ɼ�
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
//				if (Issubmit == "δ�ύ")
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
//				cout << "���" << stucourse << "�ĳɼ�Ϊ��" << score << ",����Ϊ��" << gpa << endl;
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
//			if (Issubmit == "δ�ύ")
//			{
//				cout << "�ɼ�δ�ύ���޷��鿴��" << endl << endl;
//				Isfind = 0;
//				break;
//			}
//			if (Isfind == 1) gpa = re_c_it->count_gpa(stucourse, stuname);
//			else if (Isfind == 2) gpa = el_c_it->count_gpa(stucourse, stuname);
//			cout << "���" << course << "�ĳɼ�Ϊ��" << score << ",����Ϊ��" << gpa << endl;
//			break;
//		}
//		Isfind = 4;
//	}
//	if (Isfind == 4)
//		cout << "û���ҵ����ſεĳɼ���" << endl << endl;
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
//		cout << "��ѡ����ݣ�" << endl;
//		cout << "1.��ʦ" << endl;
//		cout << "2.ѧ��" << endl;
//		cin >> iden;
//		cout << "������������֣�" << endl;
//		//������Ĭ��������ȷ��
//		cin >> name;
//
//		while (1)
//		{
//
//			if (iden == 2)
//			{
//				;
//				cout << "��ѡ�������" << endl;
//				cout << "1.�鿴�Լ����пγ�" << endl;
//				cout << "2.�鿴��ѡ�����п�ѡѡ�޿�" << endl;
//				cout << "3.������ѡѡ�޿�" << endl;
//				cout << "4.�鿴�γ̳ɼ��뼨��" << endl;
//				cout << "5.�鿴ѧУ���пγ���Ϣ" << endl;
//				cout << "6.ע��" << endl;
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
//				cout << "��ѡ�������" << endl;
//				cout << "1.�鿴�Լ����пγ�" << endl;
//				cout << "2.�鿴�Լ��γ̵�ѧ������" << endl;
//				cout << "3.¼��ѧ���ɼ�" << endl;
//				cout << "4.�޸�ѧ���ɼ�" << endl;
//				cout << "5.�ύѧ���ɼ�" << endl;
//				cout << "6.�鿴ѧУ���пγ���Ϣ" << endl;
//				cout << "7.ע��" << endl;
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
