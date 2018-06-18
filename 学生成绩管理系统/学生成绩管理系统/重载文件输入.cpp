#include "�����ļ�����.h"
//�����ļ���fstream
//���޿���Ϣ
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
//ѡ�޿���Ϣ
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
//ѧ����Ϣ   ѡ����Ϣ
fstream &operator>>(fstream &input, Student &s)
{
	string id;                                 //ѧ��
	string name;                                     //����
	string college;                                  //ѧԺ
	string class_id;                        //�༶
	input >> id >> name >> college >> class_id;
	s.setid(id);
	s.setname(name);
	s.setcollege(college);
	s.setclass_id(class_id);

	return input;
}
//��ʦ��Ϣ
fstream &operator>>(fstream &input, Teacher &t)
{
	string id;                                 //ѧ��
	string name;                                     //����
	string college;                                  //ѧԺ
	string class_id;                        //�༶
	string onecourse;
	vector<string>recourse;                //�οογ�
	vector<string>elcourse;

	input >> id >> name >> college;
	t.setid(id);
	t.setname(name);
	t.setcollege(college);
	input >> onecourse;
	while (onecourse != "���޿�")
	{
		recourse.push_back(onecourse);
		input >> onecourse;
	}
	t.setrecourse(recourse);
	input >> onecourse;
	while (onecourse != "ѡ�޿�")
	{
		elcourse.push_back(onecourse);
		input >> onecourse;
	}
	t.setelcourse(elcourse);
	return input;
}
//�ɼ���Ϣ
fstream &operator>>(fstream &input, Student *s)
{
	string id;                                 //ѧ��
	string name;                                     //����
	string college;                                  //�γ�
	string class_id;                        //�Ƿ��ύ
	float score;
	input >> name >> college >> id >> score >> class_id;
	s->setid(id);
	s->setname(name);
	s->setcollege(college);
	s->setscore(score);
	s->setclass_id(class_id);
	return input;
}
//�ɼ���Ϣ
fstream &operator<<(fstream &output, Student s)
{
	string id;                                 //ѧ��
	string name;                                     //����
	string college;                                  //�γ�
	string class_id;                        //�Ƿ��ύ
	float score = s.getscore();
	output << s.getname() << " " << s.getcollege() << " " << s.getid() << " " << setw(8) << score << " " << s.getclass_id() << endl;

	return output;
}
//ѡ����Ϣ
fstream &operator<<(fstream &output, Student *s)
{
	string id;                                 //ѧ��
	string name;                                     //����
	string college;                                  //�γ�
	string class_id;                        //�Ƿ��ύ

	output << s->getid() << " " << s->getname() << " "  << s->getcollege() << " "<< s->getclass_id()<< endl;

	return output;
}