// DeleteAndUpdateRecordInFile.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <string>
#include <vector> 
using namespace std;
void PrintFileContent(string FileName)
{
	fstream MyFile;
	//ios::out delete old data in file 
	//ios::app append new data to file
	//ios::in read file
	MyFile.open(FileName, ios::in);//Read mode

	if (MyFile.is_open())
	{
		string Line;

		while (getline(MyFile, Line))
		{
			cout << Line << endl;
		}
		MyFile.close();
	}
}
void LoadDataFromFileToVector(string FileName, vector <string>& vFileContent)
{
	fstream MyFile;
	MyFile.open(FileName, ios::in);
	if (MyFile.is_open())
	{
		string Line;
		while (getline(MyFile, Line))
		{
			vFileContent.push_back(Line);
		}
		MyFile.close();
	}
}
void SaveVectorToFile(string FileName, vector <string> vFileContent)
{
	fstream MyFile;
	MyFile.open(FileName, ios::out);//Write Mode
	if (MyFile.is_open())
	{

		for (string& Line : vFileContent)
		{
			if (Line != "")
			{
				MyFile << Line << endl;
			}
		}
		MyFile.close();
	}
}
void DeleteRecordFromFile(string FileName, string Record)
{
	vector <string> vFileContent;
	LoadDataFromFileToVector(FileName, vFileContent);

	for (string& Line : vFileContent)
	{
		if (Line == Record)
		{
			Line = "";
		}
	}
	SaveVectorToFile(FileName, vFileContent);
}
void UpdateRecordInFile(string FileName, string Record, string UpdateTo)
{

	vector <string> vFileContent;
	LoadDataFromFileToVector(FileName, vFileContent);

	for (string& Line : vFileContent)
	{
		if (Line == Record)
		{
			Line = UpdateTo;
		}
	}
	SaveVectorToFile(FileName, vFileContent);
}
int main()
{
    std::cout << "Hello World!\n";
    //cout << "File Content before Delete: \n";
//PrintFileContent("MyFile.txt");
//
//DeleteRecordFromFile("MyFile.txt", "Ali");
//
//cout << "\n\nFile Content After Delete: \n";
//PrintFileContent("MyFile.txt");//#57


    cout << "File Content before Delete: \n";
    PrintFileContent("MyFile.txt");

    UpdateRecordInFile("MyFile.txt", "Ali", "Omar");

    cout << "\n\nFile Content After Delete: \n";
    PrintFileContent("MyFile.txt");//#58
    return 0;
}

