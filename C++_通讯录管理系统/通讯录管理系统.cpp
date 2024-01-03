#include<iostream>
#include<string>
using namespace std;
#define MAX 1000  // 通讯录最大人数的初始化

// 封装显示菜单界面且main中调用

// 菜单界面
void showMenu()
{
	cout << "***************************" << endl;
	cout << "*****  1、添加联系人  *****" << endl;
	cout << "*****  2、显示联系人  *****" << endl;
	cout << "*****  3、删除联系人  *****" << endl;
	cout << "*****  4、查找联系人  *****" << endl;
	cout << "*****  5、修改联系人  *****" << endl;
	cout << "*****  6、清空联系人  *****" << endl;
	cout << "*****  0、退出联系人  *****" << endl;
	cout << "***************************" << endl;
}

/*
添加联系人的步骤:
1.设计联系人的结构体
2.设计通讯录结构体
3.main函数中创建通讯录
4.封装添加联系人函数
5.测试添加联系人的功能
*/

// 联系人个体的结构体
struct person
{
	string name;
	int m_Sex; // 性别:1.男 2. 女
	int m_Age; // 年龄
	string m_Phone; // 电话
	string m_Address; // 住址
};

// 通讯录结构体
struct Addressbooks
{
	struct person personArray[MAX];
	int m_size;  // 通讯录人数
};

// 通讯录添加联系人的功能
void addPerson(Addressbooks* abs)
{
	// 判断通讯录是否满了
	if (abs->m_size == MAX)
	{
		cout << "通讯录存储已满，不能再添加啦！" << endl;
		return;
	}
	else
	{
		// 添加联系人信息
	// 姓名
		string name;
		cout << "请输入联系人的姓名:" << endl;
		cin >> name;
		abs->personArray[abs->m_size].name = name;
		// 性别
		cout << "请输入性别:" << endl;
		cout << "1---男" << endl;
		cout << "2---女" << endl;
		int sex;
		// 判断是否输入的格式正确 且只有正确才让他往下走
		while (1) {
			cin >> sex;
			if (sex == 1 || sex == 2) {
				abs->personArray[abs->m_size].m_Sex = sex;
				break;
			}
				cout << "输入格式错误，请在重新输入" << endl;
		}

		// 年龄
		cout << "请输入年龄" << endl;
		int age;
		cin >> age;
		abs->personArray[abs->m_size].m_Age = age;
		// 电话
		cout << "请输入电话号码:" << endl;
		string phone;
		cin >> phone;
		abs->personArray[abs->m_size].m_Phone = phone;
		// 住址
		cout << "请输入地址:" << endl;
		string address;
		cin >> address;
		abs->personArray[abs->m_size].m_Address = address;
		// 更新人数
		abs->m_size++;
		cout << "添加成功!" << endl;
	}

	system("pause"); // 请按任意键继续
	system("cls"); // 清屏
}

// 显示联系人的功能

void displayPerson(Addressbooks* abs)
{
	if (abs->m_size == 0)
	{
		cout << "联系人的列表为空,请先添加后在查询!" << endl;
		system("pause"); // 请按任意键继续
		system("cls"); // 清屏
		return;
	}
	else
	{
		for (int i = 0; i < abs->m_size; i++)
		{
			cout << "第" << i + 1 << "个联系人信息:" << endl;
			cout << "姓名: " << abs->personArray[i].name << "\t";
			cout << "性别: " << (abs->personArray[i].m_Sex == 1 ? "男" : "女") << "\t";
			cout <<"年龄: " << abs->personArray[i].m_Age << "\t";
			cout << "电话: " << abs->personArray[i].m_Phone << "\t";
			cout << "地址: " << abs->personArray[i].m_Address << endl;
		}
		cout << "显示通讯录信息完毕" << endl;
	}
	system("pause"); // 请按任意键继续
	system("cls"); // 清屏
}

// 检测联系人是否存在
int existPerson(Addressbooks* abs,string name)
{
	for (int i = 0; i < abs->m_size; i++)
	{
		if (abs->personArray[i].name == name) {
			return i;
			// 找到了就返回下标的位置
		}
	}
	return -1; // 找不到返回-1
}

// 删除联系人的功能
void deletePerson(Addressbooks* abs)
{
	cout << "请输入你要删除的联系人的姓名" << endl;
	string name;
	cin >> name;

	// 调用函数接口
	int ret = existPerson(abs, name);
	
	// ret == -1 未查到此人 如果不等于就是找到了
	if (ret == -1)
		cout << "查无此人!" << endl;
	else
	{
		for (int i = ret; i < abs->m_size; i++)
		{
			// 数据前移
			abs->personArray[i] = abs->personArray[i + 1];
		}
		abs->m_size--; // 更新联系人数量
		cout << "删除成功!" << endl;
	}
	system("pause"); // 请按任意键继续
	system("cls"); // 清屏
}

// 搜索联系人
void searchPerson(Addressbooks* abs)
{
	cout << "请输入你要查找的联系人姓名:" << endl;
	string name;
	cin >> name;

	// 调用函数接口
	int ret = existPerson(abs, name);

	// ret = -1 就查无此人 否则输出信息
	if (ret == -1)
	{
		cout << "查无此人！" << endl;
	}
	else
	{
		cout << "查到的联系人信息如下:" << endl;
		cout << "姓名: " << abs->personArray[ret].name << "\t";
		cout << "性别: " << (abs->personArray[ret].m_Sex == 1 ? "男" : "女") << "\t";
		cout << "年龄: " << abs->personArray[ret].m_Age << "\t";
		cout << "电话: " << abs->personArray[ret].m_Phone << "\t";
		cout << "地址: " << abs->personArray[ret].m_Address << endl;
	}
	system("pause"); // 请按任意键继续
	system("cls"); // 清屏
}

// 修改联系人的功能
void modifyPerson(Addressbooks* abs)
{
	cout << "请输入你要修改的联系人姓名:" << endl;
	string name;
	cin >> name;

	// 调用函数
	int ret = existPerson(abs, name);

	// ret = -1 就查无此人 否则就是开始修改的功能了
	if (ret == -1)
		cout << "查无此人" << endl;
	else
	{
		// 因为不知道他要改哪一项 所以把每一项都让用户重新输入
		cout << "接下来是对该联系人信息重置修改" << endl;
		// 姓名
		string name;
		cout << "请输入姓名: ";
		cin >> name;
		abs->personArray[ret].name = name;
		cout << endl;
		// 性别
		int sex;
		while (1) {
			cout << "请输入性别:" << endl;
			cout << "1 --- 男" << endl;
			cout << "2 --- 女" << endl;
			cin >> sex;
			if (sex == 1 || sex == 2) {
				abs->personArray[ret].m_Sex = sex;
				cout << endl;
				break;
			}
			else
			{
				cout << "输入格式错误，请重新输入!" << endl;
				system("pause"); 
				system("cls");
			}
		}
		// 年龄
		cout << "请输入年龄: ";
		int age;
		cin >> age;
		abs->personArray[ret].m_Age = age;
		cout << endl;
		// 电话
		cout << "请输入电话: ";
		string phone;
		cin >> phone;
		abs->personArray[ret].m_Phone = phone;
		cout << endl;
		// 地址
		cout << "请输入地址:";
		string address;
		cin >> address;
		abs->personArray[ret].m_Address = address;
		cout << endl;

		cout << "修改成功！" << endl;
	}
	system("pause");
	system("cls");
}

// 清空联系人的功能
void cleanPerson(Addressbooks* abs)
{
	abs->m_size = 0; // 直接大小清空为0 这样子无法遍历且重置
	cout << "恭喜你，清空成功！" << endl;
	system("pause");
	system("cls");
}

// 封装功能
void fuction()
{
	int select; // 用户的选择
	// 创建通讯录结构体变量
	Addressbooks abs;
	abs.m_size = 0;

	while (1) {
		// 菜单调用
		showMenu();
		cin >> select;
		switch (select)
		{
		case 1: // 1、添加联系人
			addPerson(&abs);
			break;
		case 2: // 2、显示联系人
			displayPerson(&abs);
			break;
		case 3: // 3、删除联系人
			/*{  // 这段只是用来测试的
				cout << "请输入你要删除联系人的姓名:" << endl;
				string k;
				cin >> k;
				if (existPerson(&abs, k) == -1)
					cout << "查无此人" << endl;
				else
					cout << "找到此人" << endl;
			}*/
			deletePerson(&abs);
			break;
		case 4: // 4、查找联系人
			searchPerson(&abs);
			break;
		case 5: // 5、修改联系人
			modifyPerson(&abs);
			break;
		case 6: // 6、清空联系人
			cleanPerson(&abs);
			break;
		case 0: // 0、退出联系人
			cout << "欢迎下次使用:" << endl;
			system("pause");
			return;
			break;
		}
	}
}

int main()
{
	// 调用功能按钮的函数
	fuction();
	return 0;
}