#include "Chart.h"

Chart::Chart(CSV* csv, QWidget* parent) :QChartView(parent)
{
	csv_ = csv;
	createChart();
}

Chart::~Chart()
{

}

void Chart::createChart()
{
	QLineSeries *series = new QLineSeries();
	for(int i=1;i<csv_->data.size()-2;i++)
	{
		auto time = QDateTime::fromString(csv_->data[i + 1].rowData[9].c_str(), " yyyy-MM-dd hh:mm:ss");
		series->append(time.toMSecsSinceEpoch(), QString::fromStdString(csv_->data[i + 1].rowData[0]).toDouble());
		i += zoom;
	}
	/*series->append(0, 6);
	series->append(2, 4);
	series->append(3, 8);
	series->append(7, 4);
	series->append(10, 5);
	*series << QPointF(11, 1) << QPointF(13, 3) << QPointF(17, 6) << QPointF(18, 3) << QPointF(20, 2);*/

	chart_ = new QChart();
	chart_->legend()->hide();
	chart_->addSeries(series);
	chart_->setTitle(u8"历史行情");
	//chart->createDefaultAxes();

	QDateTimeAxis *axisX_ = new QDateTimeAxis;
	axisX_->setTickCount(10);
	axisX_->setFormat("hh:mm:ss");
	axisX_->setTitleText("Time");
	chart_->addAxis(axisX_, Qt::AlignBottom);
	series->attachAxis(axisX_);

	QValueAxis *axisY_ = new QValueAxis;
	axisY_->setLabelFormat("%.2f");
	axisY_->setTitleText("Price");
	chart_->addAxis(axisY_, Qt::AlignLeft);
	series->attachAxis(axisY_);
	
	

	//chart->createDefaultAxes();
	

	setChart(chart_);
	setRenderHint(QPainter::Antialiasing);
}

void Chart::keyPressEvent(QKeyEvent *event) {
	if ((event->key() == Qt::Key_Enter || event->key() == Qt::Key_Return)) {
		emit viewFinish();
	}
}


void Chart::wheelEvent(QWheelEvent* event)
{
	if (event->delta() > 0)
	{
		if (zoom<300)
		{
			zoom++;
			oldChart_ = chart_;
			//delete chart_;
			createChart();
			delete oldChart_;
		}
	}
	else
	{
		if(zoom>0)
		{
			zoom--;
			oldChart_ = chart_;
			createChart();
			delete oldChart_;
		}
	}
}

//void Chart::wheelEvent(QWheelEvent* event)
//{
//	if (event->delta() > 0)
//	{
//		//emit mouseWheelZoom(false);
//		auto plotArea = chart_->plotArea();
//		/*auto b = a.bottomLeft();
//		auto c = a.bottomRight();
//		auto d = a.topLeft();
//		auto e = a.topRight();*/
//		//QPointF p = chart_->cursor().pos();
//		//p=chart_->mapFromParent(p);
//		auto width = plotArea.width() - 10;
//		auto x = mousePos.x() - plotArea.width() / 2;
//		auto height = plotArea.height() - 10;
//		auto y = mousePos.y() - plotArea.height() / 2;
//
//		QRectF area(x, y, width, height);
//
//		//x=x/2-(plotArea.width()/2)
//		//area.setX();
//		//chart_->zoomIn(a);
//		chart_->zoomIn(area);
//		
//	}
//	else
//	{
//		//emit mouseWheelZoom(true);
//
//		chart_->zoomOut();
//	}
//}



void Chart::mousePressEvent(QMouseEvent* event)
{
	if (event->button() == Qt::RightButton)
	{
		zoom=0;
		oldChart_ = chart_;
		createChart();
		delete oldChart_;
	}
}

