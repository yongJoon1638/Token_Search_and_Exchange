#include "pch.h"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <regex>

using namespace std;

typedef regex_token_iterator<char*> Myiter;

//load txt file
void loadTxt(const char* inputfileName,const char* outputfileName) {
	ifstream in(inputfileName);
	ofstream out(outputfileName,ios::out);

	char* input = NULL;
	string file = "_FILE_";
	string line = " _LINE_,";
	string inputTmp = "";
	string output = "";

	//Regex
	regex fileRx("[a-z A-z 0-9]+\.h");
	regex lineRx("\d*,");

	//load all input.txt and store at inputTmp
	if (!in.is_open()) {
		cout << "Can`t find file!" << endl;
		return;
	}
	else {
		in.seekg(0, ios::end);
		int size = in.tellg();
		inputTmp.resize(size);
		in.seekg(0, ios::beg);
		in.read(&inputTmp[0], size);
		
		//transform string to char
		input = new char[inputTmp.length()];
		strcpy_s(input, inputTmp.length(),inputTmp.c_str());
	}
	
	//tokenize
	stringstream ss(inputTmp);
	string token;
	while (getline(ss, token, ' ')) {
		/*if (regex_search(token,fileRx)) {
			output += file;
		}
		else if (regex_match(token, lineRx)) {
			output += line;
		}
		else {
			output += token;
		}
		
		if (token != "\n") {
			output += " ";
		}*/
		cout << token << endl;
	}

	cout << output << endl;
}

int main()
{
	loadTxt("Input.txt", "Output.txt");

	return 0;
}