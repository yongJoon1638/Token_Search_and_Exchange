#include "pch.h"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <regex>
#include <queue>
#include <iterator>

using namespace std;


//load txt file
void loadTxt(const char* inputfileName,const char* outputfileName) {
	ifstream in(inputfileName);
	ofstream out(outputfileName,ios::out);

	string file = "_FILE_ ";
	streamsize fileSize = file.size();
	string line = "_LINE_, ";
	streamsize lineSize = line.size();
	string inputTmp = "";

	//Regex
	regex fileRx("\\.h|\\.cpp");
	regex lineRx("\\b[0-9]+,");

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
	}
	
	//tokenize
	stringstream ss(inputTmp);
	vector<string> tokens;
	string buf;

	while (getline(ss, buf, ' ')) {
		if (buf != "\n") {
			buf += ' ';
		}
		tokens.push_back(buf);
	}

	vector<string>::iterator it;
	
	it = tokens.begin();
	while (it != tokens.end()) {
		if (regex_search(*it, fileRx)) {
			out.write(file.c_str(), fileSize);
		}
		else if (regex_search(*it, lineRx)) {
			out.write(line.c_str(), lineSize);
		}
		else {
			out.write(it->c_str(), it->size());
		}
		it++;
	}
	in.close();
	out.close();
}

int main()
{
	loadTxt("Input.txt", "Output.txt");

	return 0;
}