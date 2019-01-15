#pragma once

#include <QObject>
#include "CSV.h"
#include <boost/filesystem/fstream.hpp>
#include <boost/filesystem/path.hpp>
#include <boost/filesystem/operations.hpp>
#include <boost/algorithm/string/split.hpp>
#include <boost/algorithm/string/classification.hpp>
#include <boost/lexical_cast.hpp>
#include <vector>
#include <string>

class Helper : public QObject
{
	Q_OBJECT

public:
	Helper();
	~Helper();
	static CSV* readFile();
	static QString unicodeDecoder(const char* str);

};
