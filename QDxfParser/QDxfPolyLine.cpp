#include "QDxfPolyLine.h"
#include "QDxfWriter.h"
#include "DxfCommon.h"



QDxfPolyLine::QDxfPolyLine(const QString& layerName, QColor color, bool bClosed):m_layerName(layerName),m_color(color),m_bClosed(bClosed)
{

}

QDxfPolyLine::QDxfPolyLine(const QList<QPointF>& pointList,const QString& layerName, QColor color, bool bClosed):m_layerName(layerName),m_color(color),m_pointList(pointList),m_bClosed(bClosed)
{

}

QDxfPolyLine::~QDxfPolyLine(void)
{
}

void QDxfPolyLine::write(QDxfWriter* writer)
{
	writer->writeString(0,QString("POLYLINE"));
	//m_handleNum = writer->getHandleNum();
	//writer->writeInt(5,m_handleNum);
	writer->writeString(8,m_layerName);
	writer->writeInt(66,1);
	writer->writeInt(62,qcolorToAutoCadColorIndex(m_color));
	writer->writeReal(10,0.0);
	writer->writeReal(20,0.0);
	writer->writeReal(30,0.0);
	if (m_bClosed)
	{
		writer->writeInt(70,1);
	}
	else
	{
		writer->writeInt(70,0);
	}
	for (int i = 0; i < m_pointList.size(); ++i)
	{
		writer->writeString(0,QString("VERTEX"));
		writer->writeString(8,m_layerName);
		writer->writeReal(10,m_pointList.at(i).x());
		writer->writeReal(20,m_pointList.at(i).y());
		writer->writeReal(30,0.0);
	}
	writer->writeString(0,QString("SEQEND"));
}

void QDxfPolyLine::addPoint(const QPointF& point)
{
	m_pointList.append(point);
}
