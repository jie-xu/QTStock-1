#pragma once

#include <QObject>
#include <vector>
#include <string>

class CSVRow
{
public:
	CSVRow(std::string str);
	std::vector<std::string>rowData;
};

class CSV : public QObject
{
	Q_OBJECT

public:
	CSV();
	~CSV();
	std::vector<CSVRow>data;
};

