#pragma once

#include <QtCharts/QLineSeries>
#include <QtCharts/QtCharts>
#include "CSV.h"

class Chart : public QChartView
{
	Q_OBJECT
public:
	Chart(CSV* csv,QWidget* parent = nullptr);
	~Chart();

signals:
	void viewFinish();
	void mouseWheelZoom(bool flag);

protected:
	void keyPressEvent(QKeyEvent *event) override;
	void wheelEvent(QWheelEvent* event) override;
	void mousePressEvent(QMouseEvent* event) override;
private:
	void createChart();
	CSV* csv_;
	QChart * chart_;
	QChart * oldChart_;
	int zoom=0;

};
