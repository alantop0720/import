// InvokeImport.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

#include <time.h> 
#include <stdio.h> 




using namespace std;


#include <string>
#include <time.h>


#include <stdio.h>
#include <string.h>
#include <time.h>

using namespace std;

void GetCurrentTime()
{
		struct tm t;   //tm结构指针
		time_t now;  //声明time_t类型变量
		time(&now);      //获取系统日期和时间
		localtime_s(&t, &now);   //获取当地日期和时间

		char szResult[20] = "\0";
		sprintf_s(szResult, 20, "%.4d-%.2d-%.2d %.2d:%.2d:%.2d", t.tm_year + 1900, t.tm_mon + 1, t.tm_mday, t.tm_hour, t.tm_min,t.tm_sec); //产生"123"
		
		cout << szResult << endl;
}



int main()
{
	GetCurrentTime();
	ifstream fin("result.txt");
	string line;
	int i = 1;
	while (getline(fin, line))
	{
		//cout << line << endl;
		cout << i++ << endl;
		string cmdline = "java -jar import.jar " + line;
		cout << cmdline << endl;
		system(cmdline.c_str());
	}
	return 1;
}



