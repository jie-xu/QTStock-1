#pragma once

#ifndef CANDLESTICKDATAREADER_H
#define CANDLESTICKDATAREADER_H

#include <QtCharts/QCandlestickSet>
#include <QtCore/QTextStream>
#include <QtCharts/QtCharts>
#include "CSV.h"

using namespace QtCharts;


class KLine : public QChartView
{

public:
	 KLine(CSV *csv,QWidget* parent = nullptr);
	~KLine();
	void createCharts();

protected:
	void wheelEvent(QWheelEvent* event) override;
	void mousePressEvent(QMouseEvent* event) override;

private:
	int zoom = 0;
	CSV * csv_;
	QChart *chart_;
	QChart *oldChart_;
};

#endif // CANDLESTICKDATAREADER_H