
#include "ѧ����ʦ��.h"
#include "�����ļ�����.h"

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
	//��ȡ���޿γ���Ϣ
	fstream Required("���޿γ���Ϣ.txt", ios::in | ios::out);
	if (!Required)
	{
		cout << "���޿γ��ļ���ʧ��!";
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


	//ѡ�޿γ��ļ���ȡ--------------------
	fstream Elective("ѡ�޿γ���Ϣ.txt", ios::in | ios::out);
	if (!Elective)
	{
		cout << "ѡ�޿γ��ļ���ʧ��!";
		system("pause");
		return 0;
	}

	Elective_Course ec;
	while (!Elective.eof()) {
		Elective >> ec;
		el_c.push_back(ec);
	}


	Elective.close();

	//ѧ����Ϣ��ȡ
	fstream Stuf("ѧ����Ϣ.txt", ios::in | ios::out);
	if (!Stuf)
	{
		cout << "ѧ����Ϣ�ļ���ʧ��!";
		system("pause");
		return 0;
	}
	fstream Select_f("ѡ����Ϣ.txt", ios::in | ios::out);//trunc ��˼����д�ļ�
	if (!Select_f)
	{
		cout << "ѡ����Ϣ�ļ���ʧ��!" << endl;
		system("pause");
		return 0;
	}
	string id;                                 //ѧ��
	string name;                                     //����
	string college;                                  //ѧԺ
	string class_id;                        //�༶
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
			cout << "ѧ����Ϣ�ļ��д��ڲ��Ϸ�����,�뾡���޸ģ�" << endl;
			system("pause");
				
		}

		int Isfind = 0;
		Select_f.clear();
		Select_f.seekg(0, ios::beg);
		while (!Select_f.eof())
		{
			Isfind = 0;
			Select_f >> select;
			if (select.getclass_id() == "ѡ�޿�"&&select.getname() == s.getname())
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

	//��ʦ��Ϣ��ȡ
	fstream Teaf("��ʦ��Ϣ.txt", ios::in | ios::out);
	if (!Teaf)
	{
		cout << "��ʦ��Ϣ�ļ���ʧ��!";
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
			cout << "��ʦ��Ϣ�ļ��д��ڲ��Ϸ�����,�뾡���޸ģ�" << endl;
			system("pause");

		}
		tea.push_back(t);

	}


	Teaf.close();
}

//ѡ����Ϣд���ļ�
int WriteSelectCourse(vector<Required_Course>&re_c, vector<Elective_Course>&el_c, vector<Student>&stu, vector<Teacher>&tea)
{
	fstream Select_f("ѡ����Ϣ.txt", ios::in | ios::out | ios::trunc);//trunc ��˼����д�ļ�
	if (!Select_f)
	{
		cout << "ѡ����Ϣ�ļ���ʧ��!" << endl;
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
			ss->setclass_id("���޿�");
			Select_f << ss;
		}
		for (int i = 0; i<stu_it->getelcourse().size(); i++)
		{
			ss->setcollege(stu_it->getelcourse()[i]);
			ss->setclass_id("ѡ�޿�");
			Select_f << ss;
		}
	}


	delete ss;
	Select_f.close();
}