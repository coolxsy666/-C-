#include "ȫ�ֱ�������.h"
#include "�ļ���д.h"
#include "ѧ����ʦ����.h"
#include "�γ̺���.h"

int main()
{
	Readfile(re_c, el_c, stu, tea);
	WriteSelectCourse(re_c, el_c, stu, tea);
	int iden, choice;
	string name;
	int IsLogout = 0;
	while (1)
	{

		IsLogout = 0;
		cout << "��ѡ����ݣ�" << endl;
		cout << "1.��ʦ" << endl;
		cout << "2.ѧ��" << endl;
		cin >> iden;
		cout << "������������֣�" << endl;
		//������Ĭ��������ȷ��
		try {
			cin >> name;
			examine(name);
		}
		catch (int)
		{
			cout << "�����벻�����ֵĺϷ�������" << endl;
			continue;
		}

		while (1)
		{

			if (iden == 2)
			{
				cout << "                    �x�x�x�x�x�x�x�x�x�x�x�x�x�x�x�x�x�x�x�x�x�x" << endl;

				cout << "                    ��                                        ��" << endl;

				cout << "                    ��        1.�鿴�Լ����пγ�              ��" << endl;

				cout << "                    ��        2.�鿴��ѡ�����п�ѡѡ�޿�      �� " << endl;

				cout << "                    ��        3.������ѡѡ�޿�                ��" << endl;

				cout << "                    ��        4.�鿴�γ̳ɼ��뼨��            ��" << endl;

				cout << "                    ��        5.�鿴ѧУ���пγ���Ϣ          ��" << endl;

				cout << "                    ��        6.�鿴�ҵĳɼ���Ϣ              ��" << endl;

				cout << "                    ��        7.ע��                          ��" << endl;


				cout << "                    ��������������������������������������������" << endl;

				cin >> choice;
				switch (choice)
				{
				case 1:
					FindMyCourse(name);
					break;
				case 2:
					ViewAndSelectElCourse(name);
					break;
				case 3:
					DeleteElCourse(name);
					break;
				case 4:
					ViewMyScore(name);
					break;
				case 5:
					ViewAllCourse();
					break;
				case 6:
					PrintStuScore(name);
					break;
				case 7:
					IsLogout = 1;
					break;
				default:
					break;
				} //end for switch

			}//end for if
			else
			{

				cout << endl;
				
				cout << "                    �x�x�x�x�x�x�x�x�x�x�x�x�x�x�x�x�x�x�x�x�x�x" << endl;

				cout << "                    ��                                        ��" << endl;

				cout << "                    ��        1.�鿴�Լ����пγ�              ��" << endl;

				cout << "                    ��        2.�鿴�Լ��γ̵�ѧ������        �� " << endl;

				cout << "                    ��        3.¼��ѧ���ɼ�                  ��" << endl;

				cout << "                    ��        4.�޸�ѧ���ɼ�                  ��" << endl;

				cout << "                    ��        5.�ύѧ���ɼ�                  ��" << endl;

				cout << "                    ��        6.�鿴ѧУ���пγ���Ϣ          ��" << endl;

				cout << "                    ��        7.�鿴ѧ���ɼ�������            ��" << endl;

				cout << "                    ��        8.ע��                          ��" << endl;

				cout << "                    ��������������������������������������������" << endl;
				cin >> choice;
				switch (choice)
				{
				case 1:
					PrintTeaCourse(name);
					break;
				case 2:
					ViewMyStudent(name);
					break;
				case 3:
					AddScore(name);
					break;
				case 4:
					ModifyScore(name);
					break;
				case 5:
					SubmitScore(name);
					break;
				case 6:
					ViewAllCourse();
					break;
				case 7:
					PrintStuScoreForTea(name);
					break;
				case 8:
					IsLogout = 1;
					break;
				default:
					break;
				}
			}
			WriteSelectCourse(re_c, el_c, stu, tea);
			if (IsLogout) break;
		}// end for while
	}// end for while

	return 0;
}