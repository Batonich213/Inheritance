#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<fstream>
#include <Windows.h>
#include <cstdio>

using namespace std;

//#define WRITE_TO_FILE
#define READ_FROM_FILE

const char* UNITS[] = { "B", "kB", "MB", "GB" };

int main()
{
	setlocale(LC_ALL, "");
	cout << "Hello World";
	cout << endl;
	//https://legacy.cplusplus.com/doc/tutorial/files/

//#ifdef WRITE_TO_FILE
	ofstream fout;			
	char oldfilename[] = "File.txt";
	char newfilename[128];
	char format[] = ".txt";
	cout << "������� ����� ��� �����: ";
	cin >> newfilename;
	if (strlen(newfilename) + strlen(format) < 128)
	{
		strcat(newfilename, format);
	}
	rename(oldfilename, newfilename);
	fout.close();			//4) ����� ���� ��� ������ � ����� ���������, ��� ����������� ����� �������!!!
	system("notepad File.txt");
//#endif // WRITE_TO_FILE

	//std::ifstream fin("File.txt");
	//cout << "��������� ������� �������: " << fin.tellg() << endl;
	//fin.seekg(0, ios::end);
	//int i = 0;
	//int filesize = fin.tellg();
	//cout << "�������� ������� �������: " << filesize << endl;
	//for (; filesize > 1024; i++, filesize /= 1024);
	//cout << "������ �����: " << filesize << " " << UNITS[i] << endl;
	////fin.tellg() - tell get position (������� ������ ������������ �������)
	//system("PAUSE");
	//if (fin.is_open())
	//{
	//	//TODO: ����� ������ �� �����
	//	const int SIZE = 1024 * 512;
	//	char sz_buffer[SIZE] = {};
	//	while (!fin.eof())
	//	{
	//		//fin >> sz_buffer;
	//		fin.getline(sz_buffer, SIZE);	//getline() ��������� ������ ������ � ���������, �� ��������� �����������
	//		//�� ���������, ������������ ��� fin.getline() �������� '\n'
	//		cout << sz_buffer << endl;
	//	}
	//	fin.close();
	//}
	//else
	//{
	//	std::cerr << "Error: file not found" << endl;
	//}
}