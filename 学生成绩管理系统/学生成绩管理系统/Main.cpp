#include "全局变量声明.h"
#include "文件读写.h"
#include "学生老师函数.h"
#include "课程函数.h"

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
		cout << "请选择身份：" << endl;
		cout << "1.教师" << endl;
		cout << "2.学生" << endl;
		cin >> iden;
		cout << "请输入你的名字：" << endl;
		//名字先默认输入正确吧
		try {
			cin >> name;
			examine(name);
		}
		catch (int)
		{
			cout << "请输入不含数字的合法姓名！" << endl;
			continue;
		}

		while (1)
		{

			if (iden == 2)
			{
				cout << "                    ▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁" << endl;

				cout << "                    ▏                                        ▕" << endl;

				cout << "                    ▏        1.查看自己所有课程              ▕" << endl;

				cout << "                    ▏        2.查看并选择所有可选选修课      ▕ " << endl;

				cout << "                    ▏        3.放弃已选选修课                ▕" << endl;

				cout << "                    ▏        4.查看课程成绩与绩点            ▕" << endl;

				cout << "                    ▏        5.查看学校所有课程信息          ▕" << endl;

				cout << "                    ▏        6.查看我的成绩信息              ▕" << endl;

				cout << "                    ▏        7.注销                          ▕" << endl;


				cout << "                    ▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔" << endl;

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
				
				cout << "                    ▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁" << endl;

				cout << "                    ▏                                        ▕" << endl;

				cout << "                    ▏        1.查看自己所有课程              ▕" << endl;

				cout << "                    ▏        2.查看自己课程的学生名单        ▕ " << endl;

				cout << "                    ▏        3.录入学生成绩                  ▕" << endl;

				cout << "                    ▏        4.修改学生成绩                  ▕" << endl;

				cout << "                    ▏        5.提交学生成绩                  ▕" << endl;

				cout << "                    ▏        6.查看学校所有课程信息          ▕" << endl;

				cout << "                    ▏        7.查看学生成绩并排序            ▕" << endl;

				cout << "                    ▏        8.注销                          ▕" << endl;

				cout << "                    ▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔" << endl;
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