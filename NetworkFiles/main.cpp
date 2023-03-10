#include <iostream>
#include <fstream>

using namespace std;

void main()
{
	setlocale(LC_ALL, "");
	const int IP_SIZE = 16;
	const int MAC_SIZE = 18;
	char sz_ip_buffer[IP_SIZE] = {};
	char sz_mac_buffer[MAC_SIZE] = {};
	std::ofstream fout("201 ready.txt");
	std::ifstream fin("201 RAW.txt");
	if (fin.is_open())
	{
		while (!fin.eof())
		{
			fin >> sz_ip_buffer >> sz_mac_buffer;
			cout << sz_ip_buffer << "\t\t" << sz_mac_buffer << endl;
			fout << sz_mac_buffer << "\t\t" << sz_ip_buffer << endl;
		}
		fin.close();
	}
	else
	{
		std::cerr << "Error: File not found" << endl;
	}
	fout.close();
	system("notepad 201 ready.txt");
}