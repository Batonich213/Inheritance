#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<fstream>
using namespace std;

void main()
{
	"1.txt201";
	cout << (bool).0000000001 << endl;

	setlocale(LC_ALL, "");
	const int IP_SIZE = 16;
	const int MAC_SIZE = 18;
	char sz_ip_buffer[IP_SIZE] = {};
	char sz_mac_buffer[MAC_SIZE] = {};

	char sz_room_number[FILENAME_MAX] = {};
	cout << "Ââåäèòå èìÿ ôàéëà: "; cin.getline(sz_room_number, FILENAME_MAX);
	char sz_src_filename[FILENAME_MAX] = {};
	char sz_wal_filename[FILENAME_MAX] = {};
	char sz_dhcpd_filename[FILENAME_MAX] = {};

	strcat(sz_src_filename, sz_room_number);
	strcat(sz_src_filename, " RAW.txt");

	strcat(sz_wal_filename, sz_room_number);
	strcat(sz_wal_filename, " ready.txt");

	strcat(sz_dhcpd_filename, sz_room_number);
	strcat(sz_dhcpd_filename, ".dhcpd");

	if (strcmp(sz_src_filename + strlen(sz_src_filename) - 4, ".txt"))
		strcat(sz_src_filename, ".txt");
	cout << sz_src_filename << endl;

	std::ofstream fout(sz_wal_filename);
	std::ifstream fin(sz_src_filename);
	if (fin.is_open())
	{
		while (!fin.eof())
		{
			fin >> sz_ip_buffer >> sz_mac_buffer;
			cout << sz_mac_buffer << "\t\t" << sz_ip_buffer << endl;
			fout << sz_mac_buffer << "\t\t" << sz_ip_buffer << endl;
		}
		fin.close();
	}
	else
	{
		std::cerr << "Error: File not found" << endl;
	}
	fout.close();

	char sz_command[FILENAME_MAX] = "start notepad ";
	strcat(sz_command, sz_wal_filename);

	system(sz_command);

	////////////////////////////////////////////////////////////////////////

	fout.open(sz_dhcpd_filename);
	fin.open(sz_src_filename);
	if (fin.is_open())
	{
		for (int i = 0; !fin.eof(); i++)
		{
			fin >> sz_ip_buffer >> sz_mac_buffer;

			if (strlen(sz_ip_buffer) == strlen(sz_mac_buffer))continue;

			for (int i = 0; sz_mac_buffer[i]; i++)
				if (sz_mac_buffer[i] == '-')sz_mac_buffer[i] = ':';

			cout << "host " << sz_room_number << "-" << i + 1 << endl;
			cout << "{\n";
			cout << "\thardware ethernet\t" << sz_mac_buffer << ";\n";
			cout << "\tfixed-address\t\t" << sz_ip_buffer << ";\n";
			cout << "}\n";
			cout << endl;

			fout << "host " << sz_room_number << "-" << i + 1 << endl;
			fout << "{\n";
			fout << "\thardware ethernet\t" << sz_mac_buffer << ";\n";
			fout << "\tfixed-address\t\t" << sz_ip_buffer << ";\n";
			fout << "}\n";
			fout << endl;
		}
		fin.close();
	}
	else
	{
		std::cerr << "Error: File not found" << endl;
	}
	fout.close();

	strcpy(sz_command, "start notepad ");	
	strcat(sz_command, sz_dhcpd_filename);
	system(sz_command);
}