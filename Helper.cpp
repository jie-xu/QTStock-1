#define MAX_STR_SIZE 1000

#include "Helper.h"
#include "Windows.h"
#include <qstring.h>
#include <QtCore>

using namespace boost::filesystem;
using namespace std;

Helper::Helper()
{
}

Helper::~Helper()
{
}

CSV* Helper::readFile()
{
	auto path_ = new path(current_path().string() + "\\data.csv");
	if (exists(*path_) &&
		is_regular_file(*path_))
	{
		auto csv_ = new CSV();
		boost::filesystem::fstream fs(*path_, std::ios_base::in);
		char str[MAX_STR_SIZE];
		while (!fs.eof()) {
			fs.getline(str, MAX_STR_SIZE);
			csv_->data.push_back(CSVRow(str));
		}
		fs.close();
		return csv_;
	}
	else
	{
		return nullptr;
	}
}

QString Helper::unicodeDecoder(const char* str)
{
	QString result;
	for (int i = 0; str[i] != 0; i++)
	{
		//auto m = str[i];
		if (str[i] == '\\')//strcmp(&str[i],'\\')!=0
		{
			//result += str[i];
			i++;
			int AA, BB;
			char c[4];
			for (int j = 0; j<4; j++, i++)
			{
				c[j] = str[i];
			}
			sscanf(c, "%02x%02x", &AA, &BB);

			char x[2];
			x[0] = BB;
			x[1] = AA;

			wchar_t* hexchar = (wchar_t*)x;
			//string res = QString::fromWCharArray(hexchar, sizeof(hexchar)).toStdString();
			//result += res;
			int pSize = WideCharToMultiByte(CP_OEMCP, 0, hexchar, wcslen(hexchar), NULL, 0, NULL, NULL);
			char* pCStrKey = new char[pSize + 1];
			//第二次调用将双字节字符串转换成单字节字符串
			WideCharToMultiByte(CP_OEMCP, 0, hexchar, wcslen(hexchar), pCStrKey, pSize, NULL, NULL);
			pCStrKey[pSize] = '\0';
			QString qstr = QString::fromLocal8Bit(pCStrKey);
			//string pkey = pCStrKey;
			//result += pkey;
			result += qstr;
			i--;
		}
		else
		{
			result += str[i];
		}
	}
	//qDebug(result.c_str());
	return result;
}
