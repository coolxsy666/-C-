
#include "ѧ����ʦ����.h"
#include "�����ļ�����.h"

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
			cout << endl << deelcourse << "��ɾ����" << endl << endl;
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


//ѧ�������Լ����������пγ�-----------------------
void FindMyCourse(string name)
{
	string str;
	int Isfind = 0;
	cout << "��ı��޿��У�" << endl;

	for (int i = 0; i < re_c.size(); i++)
	{
		cout << re_c[i].getcourse_name() << "  ";
		Isfind = 1;
	}
	cout << endl << "���ѡ�޿��У�" << endl;
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

	if (Isfind == 1) cout << "��";
	cout << endl;
	if (!Isfind) cout << "û���ҵ�" << name << "������Ŷ��" << endl;

}

//ѧ���鿴��ѡ���ѡѡ�޿�-------------------------------
void ViewAndSelectElCourse(string name)
{
	cout << "����ΪѧУ����ѡ�޿Σ�" << endl;
	//ѡ�޿���Ϣ
	cout << std::left << setw(20) << "�γ�����" << setw(15) << "�γ̱��" << setw(15) << "�γ�ѧ��" << endl;
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
		cout << "��ѡ������ѡ��ѡ�޿�(����γ�����,����������0):" << endl;
		cin >> course;
		if (course == "0") break;
		//ȷ��ѡ�޿������Ƿ�������ȷ
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
			cout << endl << "�����ѡ�޿����ǲ��Ǵ���ˣ�" << endl << endl;
			continue;
		}
		Isfind = 0;
		//ȷ��ѧ���Ƿ���ѡ�ÿγ�
		for (stu_it = stu.begin(); stu_it != stu.end(); stu_it++)
		{
			if (stu_it->getname() == name)
			{
				break;
			}
		}
		//����ҵ���
		for (int i = 0; i<stu_it->getelcourse().size(); i++)
		{
			if (stu_it->getelcourse()[i] == course)
			{
				Isfind = 1;
				break;
			}
		}
		if (Isfind)
			cout << endl << "���Ѿ�ѡ�����ſ��ˣ������ͬѧһ�������!" << endl << endl;
		else
		{
			cout << endl << "���γɹ���" << endl << endl;
			stu_it->addelcourse(course);
		}
	}

}

//ѧ��ɾ����ѡѡ�޿�------------------------------------
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

	//�����û��ѡ�޿�
	if (stu_it->getelcourse().size() == 0)
	{
		cout << "�㻹ûѡ�Ͽ��ǣ�ȥѡ�ΰɣ�" << endl << endl;
		return;
	}
	cout << "����Ϊ���Ѿ�ѡ���ѡ�޿Σ�" << endl;
	//ѡ�޿���Ϣ
	cout << std::left << setw(20) << "�γ�����" << setw(15) << "�γ̱��" << setw(15) << "�γ�ѧ��" << endl;
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
	cout << "��������Ҫɾ���Ŀγ�(����0����):" << endl;
	cin >> course;
	if (course == "0") return;
	//�鿴�ɼ��Ƿ����ύ
	fstream Score_f("�γ̳ɼ�.txt", ios::in | ios::out);
	if (!Score_f)
	{
		cout << "�γ̳ɼ��ļ���ʧ��!" << endl;
		return;
	}
	//while (getline(Score_f, str))
	while (!Score_f.eof())
	{
		Score_f >> s;
		if (name == s->getname() && course == s->getcollege() && "���ύ" == s->getclass_id())
		{
			cout << "�γ̳ɼ����ύ���޷�ɾ���γ̣�" << endl;
			Score_f.close();
			return;
		}
	}
	stu_it->deleteelcourse(course);
	Score_f.close();
	delete s;
}

//������Ѱ��ѧ��-----------------------------------
vector<Student>::iterator FindStuFromVec(string name)
{
	for (stu_it = stu.begin(); stu_it != stu.end(); stu_it++)
	{
		if (stu_it->getname() == name)
			return stu_it;
	}
	cout << "û���ҵ�" << name << "����Ϣ!" << endl;

}

//�鿴�Լ���ѧ����Ϣ--------------------------------
void ViewMyStudent(string name)
{
	int i, Isfind = 0;
	Student select;
	string str;
	string course;
	fstream Select_f("ѡ����Ϣ.txt");                //������fstream������ֵ�bug
	if (!Select_f)
	{
		cout << "ѡ����Ϣ�ļ���ʧ��!" << endl;
		return;
	}
	for (i = 0; i < tea.size(); i++)
	{
		if (tea[i].getname() == name)
			break;
	}
	//Ѱ�ұ��޿ε�ѧ��
	for (int j = 0; j < tea[i].getrecourse().size(); j++)
	{
		course = tea[i].getrecourse()[j];
		cout << "--����--" << course << "��ѧ���У�" << endl;
		Select_f.clear();
		Select_f.seekg(0, ios::beg);                 //���ļ��Ķ�ָ����ļ���ͷλ�������0���ֽ�

		for (stu_it = stu.begin(); stu_it != stu.end(); stu_it++)
		{
			cout << std::left << "ѧ��������" << setw(15) << stu_it->getname() << "  ѧ��:" << setw(15) << stu_it->getid();
			cout << "  �༶:" << setw(15) << stu_it->getclass_id() << "  ѧԺ:" << setw(15) << stu_it->getcollege() << endl;
		}


	}

	//Ѱ��ѡ�޿ε�ѧ��
	for (int j = 0; j < tea[i].getelcourse().size(); j++)
	{
		course = tea[i].getelcourse()[j];
		Select_f.clear();
		Select_f.seekg(0, ios::beg);//����ָ��
		cout << "--ѡ��--" << course << "��ѧ���У�" << endl;

		for (stu_it = stu.begin(); stu_it != stu.end(); stu_it++)
		{
			for (int i = 0; i < stu_it->getelcourse().size(); i++)
			{
				if (stu_it->getelcourse()[i] == course)
				{
					cout << std::left << "ѧ��������" << setw(15) << stu_it->getname() << "  ѧ��:" << setw(15) << stu_it->getid();
					cout << "  �༶:" << setw(15) << stu_it->getclass_id() << "  ѧԺ:" << setw(15) << stu_it->getcollege() << endl;
					Isfind = 1;
				}
			}
		}
		if (!Isfind) cout << "(���ſξ�Ȼû��ѧ����" << endl;
		Isfind = 0;
	}

	while (1)
	{
		Isfind = 0;
		cout << endl << "��ѡ������鿴ѧ����Ϣ�Ŀγ�(����0�˳�)��" << endl;
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
			cout << "���Ų�������ĿΣ��ǲ�������ˣ�" << endl;
			continue;
		}
		Isfind = 0;
		cout << endl << "��ѡ������鿴��Ϣ��ѧ��������" << endl;
		string name;
		cin >> name;
		Select_f.clear();
		Select_f.seekg(0, ios::beg);//����ָ��
									/*while (getline(Select_f, str))*/
		while (!Select_f.eof())
		{
			Select_f >> select;
			if (name == select.getname() && course == select.getcollege())
			{
				stu_it = FindStuFromVec(name);
				cout << "������" << stu_it->getname() << "  ѧ��:" << stu_it->getid() << "  ѧԺ:" << stu_it->getcollege();
				cout << "  �༶:" << stu_it->getclass_id() << endl;
				Isfind = 1;
				break;
			}
		}
		if (!Isfind)
			cout << "û���ҵ����ѧ����" << endl;
	}
	Select_f.close();
}

//��ӡ��ʦ���Ŀ�-------------------
void PrintTeaCourse(string name)
{
	for (tea_it = tea.begin(); tea_it != tea.end(); tea_it++)
	{
		if (name == tea_it->getname())
		{
			for (int i = 0; i < tea_it->getrecourse().size(); i++)
			{
				if (i == 0) cout << "�Ҵ��ı��޿��У�";
				cout << tea_it->getrecourse()[i] << " ";
			}
			cout << endl;
			for (int i = 0; i < tea_it->getelcourse().size(); i++)
			{
				if (i == 0) cout << "�Ҵ���ѡ�޿��У�";
				cout << tea_it->getelcourse()[i] << " ";
			}
			cout << endl;
			return;
		}
	}
}

//��ʦ¼��ɼ�--------------------
void AddScore(string name)
{

	fstream Score_f("�γ̳ɼ�.txt", ios::in | ios::out);
	if (!Score_f)
	{
		cout << "�γ̳ɼ��ļ���ʧ��!" << endl;
		return;
	}
	string course;
	int Isfind = 0;
	string score;
	Student *ss = new Student;
	while (1)
	{
		Isfind = 0;        //���޿���ֵΪ1��ѡ��Ϊ2
		PrintTeaCourse(name);
		cout << "��ѡ������¼��ɼ��Ŀγ̣�(�˳�������0)" << endl;
		cin >> course;
		if (course == "0") break;
		//ȷ�����ſ��Ƿ����
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
			cout << "������Ŀγ������ǲ�������ˣ�" << endl;
			continue;
		}
		//¼��ɼ���δ�ύ
		Score_f.seekg(0, ios::end);
		if (Isfind == 1)
		{
			for (stu_it = stu.begin(); stu_it != stu.end(); )
			{
				cout << "��Ϊ" << stu_it->getname() << "��֣�";
				try
				{
					cin >> score;
					examinenum(score);
				}
				catch (int)
				{
					cout << "��Ϸ���֣�ֻ�������֣�" << endl;

					continue;
				}
				/////num=atof(str.c_str())  
				//string ת float
				stu_it->setscore(atof(score.c_str()));

				//output >> s->getname() >>" ">> s->getcollege() >>" ">> s->getid()  >>" ">> setw(8) >> score>> " ">>"δ�ύ";
				//Score_f << stu_it->getname() << ' ' << course << ' ' << stu_it->getid() << ' ' << setw(8) << score << ' ' << "δ�ύ" << endl;

				*ss = *stu_it;
				ss->setcollege(course);
				ss->setclass_id("δ�ύ");
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
						cout << "��Ϊ" << stu_it->getname() << "��֣�";
						try
						{
							cin >> score;
							examinenum(score);
						}
						catch (int)
						{
							cout << "��Ϸ���֣�ֻ�������֣�" << endl;
							i--;
							continue;
						}
						//	Score_f << stu_it->getname() << ' ' << course << ' ' << stu_it->getid() << ' ' << setw(8) << score << ' ' << "δ�ύ" << endl;
						*ss = *stu_it;
						ss->setcollege(course);
						ss->setscore(atof(score.c_str()));
						ss->setclass_id("δ�ύ");
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



//��ʦ�ύ�ɼ�-----------------
void SubmitScore(string name)
{
	fstream Score_f("�γ̳ɼ�.txt", ios::in | ios::out);
	if (!Score_f)
	{
		cout << "�γ̳ɼ��ļ���ʧ��!" << endl;
		return;
	}
	string course;
	int Isfind = 0;
	string score;
	Student *s = new Student;
	while (1)
	{
		Isfind = 0;        //���޿���ֵΪ1��ѡ��Ϊ2
		PrintTeaCourse(name);
		cout << "��ѡ�������ύ�ɼ��Ŀγ̣�(�˳�������0)" << endl;
		cin >> course;
		if (course == "0") break;
		//ȷ�����ſ��Ƿ����
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
			cout << "������Ŀγ������ǲ�������ˣ�" << endl;
			continue;
		}
		//�ύ�ɼ�
		string str;
		long len = 0;
		int Is = 0;
		//while (getline(Score_f, str))
		while (!Score_f.eof())
		{
			Score_f >> s;
			if (course == s->getcollege())
			{
				if ("���ύ" == s->getclass_id())
				{
					cout << "�ɼ����ύ��" << endl;
					Isfind = 0;
					break;
				}
				//	cout << str << endl;
				//�������һ�е����
				if (Score_f.eof())
					Score_f.clear();

				Score_f.seekg(len, ios::beg);
				if (len && !Is)
				{
					Is = 1;
					Score_f << endl;
				}
				s->setclass_id("���ύ");
				Score_f << *s;

				/*str.erase(str.end() - 6, str.end());
				Score_f << str << "���ύ" << endl;*/

			}
			len = Score_f.tellg();                                ///////////��ķ�������bug////////////
		}


		cout << "�ύ�ɹ���" << endl;


	}



	delete s;
	Score_f.close();
}

//��ʦ�޸ĳɼ�---------------------------
void ModifyScore(string name)
{
	fstream Score_f("�γ̳ɼ�.txt", ios::in | ios::out);
	if (!Score_f)
	{
		cout << "�γ̳ɼ��ļ���ʧ��!" << endl;
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
		Isfind = 0;        //���޿���ֵΪ1��ѡ��Ϊ2
		PrintTeaCourse(name);
		cout << "��ѡ�������޸ĳɼ��Ŀγ�(����0�˳�)��" << endl;
		cin >> course;
		if (course == "0") break;
		//ȷ�����ſ��Ƿ����
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
			cout << "������Ŀγ������ǲ�������ˣ�" << endl;
			continue;
		}

		cout << "��λͬѧ�н����أ� " << endl;
		string stuname;
		string str;
		long len = 0;
		float score;
		string modifyscore;
		cin >> stuname;
		stu_it = FindStuFromVec(stuname);
		*tem = *stu_it;
		//�޸ĳɼ�
		Score_f.clear();
		Score_f.seekg(0, ios::beg);
		//while (getline(Score_f, str))
		while (!Score_f.eof())
		{
			Score_f >> ss;
			if (stuname == ss->getname() && course == ss->getcollege())
			{
				if ("���ύ" == ss->getclass_id())
				{
					cout << "�ɼ����ύ���޷��޸ģ�" << endl;
					Isfind = 11;
					break;
				}
				cout << ss->getname() << " " << ss->getscore() << endl;
				Isfind = 1;
				cout << "��Ӧ�õķ����ǣ� " << endl;
				cin >> modifyscore;
				if (Score_f.eof())
					Score_f.clear();

				Score_f.seekg(len, ios::beg);
				ss->setscore(atof(modifyscore.c_str()));
				//Score_f << stu_it->getname() << ' ' << course << ' ' << stu_it->getid() << ' ' << setw(8) << modifyscore << ' ' << "δ�ύ" << endl;
				if (len) Score_f << endl;
				Score_f << *ss;
				cout << "�޸ĳɹ���" << endl;
				break;
			}
			len = Score_f.tellg();                                ///////////��ķ�������bug////////////
		}

		if (!Isfind)
		{
			cout << "û���ҵ�ѧ����Ϣ��" << endl;
			Isfind = 0;
			continue;
		}



	}



	delete ss;
	delete tem;
	Score_f.close();
}

//ѧ���鿴�ɼ��ͼ���---------------------
void ViewMyScore(string name)
{
	fstream Score_f("�γ̳ɼ�.txt", ios::in | ios::out);
	if (!Score_f)
	{
		cout << "�γ̳ɼ��ļ���ʧ��!" << endl;
		return;
	}

	//string course, str, id, score, Issubmit, stuname, stucourse;
	string course;
	Student *ss = new Student;
	int Isfind = 0, Isfind1 = 0;
	float gpa;
	cout << "����鿴���ſεĳɼ�(�뿴ȫ���ɼ�������1)��" << endl;
	cin >> course;
	//���ȫ�����ύ�ɼ�
	if (course == "1")
	{
		while (!Score_f.eof())
		{
			Isfind = 0;
			Score_f >> ss;
			if (ss->getname() == name)
			{
				if (ss->getclass_id() == "δ�ύ")
				{

					cout << ss->getcollege() << "�ɼ�δ�ύ���޷��鿴��" << endl;
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
				cout << "���" << ss->getcollege() << "�ĳɼ�Ϊ��" << ss->getscore() << ",����Ϊ��" << gpa << endl;

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
			if (ss->getclass_id() == "δ�ύ")
			{
				cout << "�ɼ�δ�ύ���޷��鿴��" << endl << endl;
				Isfind = 0;
				break;
			}
			if (Isfind == 1) gpa = re_c_it->count_gpa(ss->getcollege(), ss->getname());
			else if (Isfind == 2) gpa = el_c_it->count_gpa(ss->getcollege(), ss->getname());
			cout << "���" << course << "�ĳɼ�Ϊ��" << ss->getscore() << ",����Ϊ��" << gpa << endl;
			break;
		}
		Isfind1 = 4;
	}
	if (Isfind1 == 4)
		cout << "û���ҵ����ſεĳɼ���" << endl << endl;
	Score_f.close();
	delete ss;
	return;
}

//��������Ƿ�Ϸ�-----
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

//����ַ����Ƿ�������֮����ַ�-----
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

//ѧ���鿴�����ĳɼ�
void PrintStuScore(string name)
{
	Student *s = new Student;
	vector<Student> vecstu;

	string str, str1;
	int Isfind;
	fstream Score_f("�γ̳ɼ�.txt", ios::in | ios::out);
	if (!Score_f)
	{
		cout << "�γ̳ɼ��ļ���ʧ��!" << endl;
		return;
	}
	while (!Score_f.eof())
	{
		Isfind = 0;
		Score_f >> s;
		if (s->getname() == name&&s->getclass_id() != "δ�ύ")
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


	cout << "�Լ��������������0���Գɼ�������������1��" << endl;
	cin >> str;
	cout << "����������밴0����������밴1��" << endl;
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

	cout << std::left << setw(15) << "�γ�" << "  " << setw(15) << "�ɼ�" << setw(15) << "����" << endl;
	for (stu_it = vecstu.begin(); stu_it != vecstu.end(); stu_it++)
	{
		cout << std::left << setw(15) << stu_it->getcollege() << "  " << setw(15) << stu_it->getscore() << setw(15) << stu_it->getcredit() << endl;
	}


	Score_f.close();
	delete s;
}

void PrintStuScoreForTea(string name)
{
	fstream Score_f("�γ̳ɼ�.txt", ios::in | ios::out);
	if (!Score_f)
	{
		cout << "�γ̳ɼ��ļ���ʧ��!" << endl;
		return;
	}
	Student *s = new Student;
	string course, str, str1;
	vector<Student> vecstu;
	int Isfind = 0, num = 0;
	while (1)
	{
		PrintTeaCourse(name);
		cout << "����������鿴�ɼ��Ŀγ̣�(�˳��밴0)" << endl;
		cin >> course;
		if (course == "0")  break;
		//ȷ�����ſ��Ƿ����
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
			cout << "������Ŀγ������ǲ�������ˣ�" << endl;
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
			cout << "���ſλ�û��¼��ɼ�Ŷ" << endl;
			continue;
		}
		cout << "��ѧ�Ž�����������0���Գɼ�������������1��" << endl;
		cin >> str;
		cout << "����������밴0����������밴1��" << endl;
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
		cout << std::left << setw(15) << "����" << "  " << setw(15) << "ѧ��" << setw(15) << "�ɼ�" << setw(15) << "���" << endl;
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
