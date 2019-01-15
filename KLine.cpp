#include "KLine.h"

KLine::KLine(CSV* csv,QWidget* parent) :QChartView(parent)
{
	csv_ = csv;
	createCharts();
}


KLine::~KLine()
{
}



void KLine::createCharts()
{
	QCandlestickSeries *setSeries = new QCandlestickSeries();
	setSeries->setName("KLine");
	setSeries->setIncreasingColor(QColor(Qt::green));
	setSeries->setDecreasingColor(QColor(Qt::red));

	QStringList categories;

	for(int i=1;i<csv_->data.size()-2;i++)
	{
		QCandlestickSet *set = new QCandlestickSet();
		set->setOpen(QString::fromStdString(csv_->data[i].rowData[0]).toDouble());
		set->setHigh(QString::fromStdString(csv_->data[i].rowData[1]).toDouble());
		set->setLow(QString::fromStdString(csv_->data[i].rowData[2]).toDouble());
		set->setClose(QString::fromStdString(csv_->data[i].rowData[3]).toDouble());
		auto time = QDateTime::fromString(csv_->data[i].rowData[10].c_str(), " yyyy-MM-dd hh:mm:ss");
		set->setTimestamp(time.toMSecsSinceEpoch());
		setSeries->append(set);
		categories << time.toString("hh:mm");
		i += zoom;
	}
	chart_ = new QChart();
	chart_->addSeries(setSeries);
	chart_->setTitle("K-Line");
	chart_->setAnimationOptions(QChart::SeriesAnimations);

	chart_->createDefaultAxes();

	QBarCategoryAxis *axisX = qobject_cast<QBarCategoryAxis *>(chart_->axes(Qt::Horizontal).at(0));
	axisX->setCategories(categories);

	QValueAxis *axisY = qobject_cast<QValueAxis *>(chart_->axes(Qt::Vertical).at(0));
	axisY->setMax(axisY->max() * 1.01);
	axisY->setMin(axisY->min() * 0.99);

	chart_->legend()->setVisible(true);
	chart_->legend()->setAlignment(Qt::AlignBottom);

	setChart(chart_);
	setRenderHint(QPainter::Antialiasing);
}

void KLine::wheelEvent(QWheelEvent* event)
{
	if (event->delta() > 0)
	{
		if (zoom<50)
		{
			zoom++;
			oldChart_ = chart_;
			//delete chart_;
			createCharts();
			delete oldChart_;
		}
	}
	else
	{
		if (zoom>0)
		{
			zoom--;
			oldChart_ = chart_;
			createCharts();
			delete oldChart_;
		}
	}
}

void KLine::mousePressEvent(QMouseEvent* event)
{
	if (event->button() == Qt::RightButton)
	{
		zoom = 0;
		oldChart_ = chart_;
		createCharts();
		delete oldChart_;
	}
}