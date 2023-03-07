#include<iostream>
#include<fstream>
using namespace std;

#define write_to_file
#define read_from_file
void main()
{
	setlocale(LC_ALL, "");
#ifdef write_to_file
	ofstream fout;
	fout.open("File.txt", std::ios_base::app);
	fout << "Hello Files" << endl;
	fout << "Всем привет" << endl;
	fout.close();
	system("notepad File.txt");
#endif 
}