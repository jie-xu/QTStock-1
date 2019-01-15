#include "CSV.h"
#include <boost/algorithm/string/split.hpp>
#include <boost/algorithm/string/classification.hpp>

CSV::CSV()
{
}

CSV::~CSV()
{
}

CSVRow::CSVRow(std::string str)
{
	split(rowData, str, boost::is_any_of(","));
}
