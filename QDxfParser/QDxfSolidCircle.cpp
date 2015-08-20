#include "QDxfSolidCircle.h"
#include "QDxfWriter.h"
#include "DxfCommon.h"
#include <QtMath>

QDxfSolidCircle::QDxfSolidCircle(const QPointF& center,double radius,const QString& layerName, const QString& lineTypeName, const QString& solidName, QColor color)
		:m_centerPoint(center),m_radius(radius),m_layerName(layerName),m_lineTypeName(lineTypeName),m_solidName(solidName),m_color(color)
{

}


QDxfSolidCircle::~QDxfSolidCircle(void)
{
}

void QDxfSolidCircle::write(QDxfWriter* writer)
{
	writer->writeString(0,QString("INSERT"));
	writer->writeString(8,m_layerName);
	writer->writeString(6,m_lineTypeName);
	writer->writeInt(62,qcolorToAutoCadColorIndex(m_color));
	writer->writeString(2,m_solidName);
	writer->writeReal(10,0.0);
	writer->writeReal(20,0.0);
	writer->writeReal(30,0.0);
	writer->writeString(1001,"GRADIENTCOLOR1ACI");
	writer->writeInt(1070,5);
	writer->writeString(1001,"GRADIENTCOLOR2ACI");
	writer->writeInt(1070,2);
	writer->writeString(1001,"ACAD");
	writer->writeString(1002,"{");
	writer->writeString(1000,"R14_HATCH_DATA");
	//m_handleNum = writer->getHandleNum();
	//writer->writeInt(5,m_handleNum);
	//writer->writeInt(1000,writer->getHandleNum());
	writer->writeReal(1011,1.0);
	writer->writeReal(1021,0.0);
	writer->writeReal(1031,0.0);
	writer->writeReal(1021,0.0);
	writer->writeReal(1031,0.0);
	writer->writeReal(1011,0.0);
	writer->writeReal(1021,0.0);
	writer->writeReal(1031,0.0);
	writer->writeReal(1021,1.0);
	writer->writeReal(1031,0.0);
	writer->writeReal(1011,0.0);
	writer->writeReal(1021,0.0);
	writer->writeReal(1031,0.0);
	writer->writeReal(1021,0.0);
	writer->writeReal(1031,1.0);
	writer->writeReal(1040,0.0);
	writer->writeReal(1010,0.0);
	writer->writeReal(1020,0.0);
	writer->writeReal(1030,1.0);
	writer->writeString(1000,"SOLID");
	writer->writeInt(1070,1);
	writer->writeInt(1070,1);
	writer->writeInt(1071,1);
	writer->writeInt(1071,7);
	writer->writeInt(1070,1);
	writer->writeInt(1070,1);
	writer->writeInt(1070,2);
	writer->writeReal(1040,m_centerPoint.x() - m_radius);
	writer->writeReal(1040,m_centerPoint.y());
	writer->writeReal(1040,1.0);
	writer->writeReal(1040,m_centerPoint.x() + m_radius);
	writer->writeReal(1040,m_centerPoint.y());
	writer->writeReal(1040,1.0);
	writer->writeInt(1071,1);
	writer->writeInt(1070,1);
	writer->writeInt(1070,1);
	writer->writeInt(1071,1);
	writer->writeString(1002,"}");
}

const int factor = 50;
void QDxfSolidCircle::writeBlock(QDxfWriter* writer)
{
	double diameter = m_radius*2;
	double piece = diameter / (factor + 1);
	double firstY = m_centerPoint.y() + m_radius - piece / 2;

	writer->writeString(0,QString("BLOCK"));
	writer->writeString(8,m_layerName);
	writer->writeString(2,m_solidName);
	writer->writeInt(70,1);
	writer->writeReal(10,0.0);
	writer->writeReal(20,0.0);
	writer->writeReal(30,0.0);
	writer->writeString(3,m_solidName);

	double downY0 = m_centerPoint.y() + m_radius - piece / 2;
	QPair<double,double> xpair0 = computeXpos(downY0);
	writer->writeString(0,"SOLID");
	writer->writeString(8,m_layerName);
	writer->writeString(6,m_lineTypeName);
	writer->writeInt(62,qcolorToAutoCadColorIndex(m_color));
	writer->writeReal(10,m_centerPoint.x());
	writer->writeReal(20,m_centerPoint.y() + m_radius);
	writer->writeReal(30,0.0);
	writer->writeReal(11,xpair0.first);
	writer->writeReal(21,downY0);
	writer->writeReal(31,0.0);
	writer->writeReal(12,xpair0.second);
	writer->writeReal(22,downY0);
	writer->writeReal(32,0.0);
	writer->writeReal(13,xpair0.second);
	writer->writeReal(23,downY0);
	writer->writeReal(33,0.0);
	writer->writeReal(210,0.0);
	writer->writeReal(220,0.0);
	writer->writeReal(230,1.0);

	for (int i = 0;i < factor; ++i)
	{
		double upY = firstY - i*piece;
		double downY = firstY - (i+1)*piece;
		QPair<double,double> upXpair = computeXpos(upY);
		QPair<double,double> downXpair = computeXpos(downY);

		writer->writeString(0,"SOLID");
		writer->writeString(8,m_layerName);
		writer->writeString(6,m_lineTypeName);
		writer->writeInt(62,qcolorToAutoCadColorIndex(m_color));
		writer->writeReal(10,upXpair.first);
		writer->writeReal(20,upY);
		writer->writeReal(30,0.0);
		writer->writeReal(11,downXpair.first);
		writer->writeReal(21,downY);
		writer->writeReal(31,0.0);
		writer->writeReal(12,downXpair.second);
		writer->writeReal(22,downY);
		writer->writeReal(32,0.0);
		writer->writeReal(13,downXpair.second);
		writer->writeReal(23,downY);
		writer->writeReal(33,0.0);
		writer->writeReal(210,0.0);
		writer->writeReal(220,0.0);
		writer->writeReal(230,1.0);

		writer->writeString(0,"SOLID");
		writer->writeString(8,m_layerName);
		writer->writeString(6,m_lineTypeName);
		writer->writeInt(62,qcolorToAutoCadColorIndex(m_color));
		writer->writeReal(10,-upXpair.first);
		writer->writeReal(20,upY);
		writer->writeReal(30,0.0);
		writer->writeReal(11,-upXpair.second);
		writer->writeReal(21,upY);
		writer->writeReal(31,0.0);
		writer->writeReal(12,-downXpair.second);
		writer->writeReal(22,downY);
		writer->writeReal(32,0.0);
		writer->writeReal(13,-downXpair.second);
		writer->writeReal(23,downY);
		writer->writeReal(33,0.0);
		writer->writeReal(210,0.0);
		writer->writeReal(220,0.0);
		writer->writeReal(230,-1.0);
	}

	double upY0 = m_centerPoint.y() - m_radius + piece / 2;
	QPair<double,double> xPairUp = computeXpos(upY0);
	writer->writeString(0,"SOLID");
	writer->writeString(8,m_layerName);
	writer->writeString(6,m_lineTypeName);
	writer->writeInt(62,qcolorToAutoCadColorIndex(m_color));
	writer->writeReal(10,xPairUp.first);
	writer->writeReal(20,upY0);
	writer->writeReal(30,0.0);
	writer->writeReal(11,xPairUp.second);
	writer->writeReal(21,upY0);
	writer->writeReal(31,0.0);
	writer->writeReal(12,m_centerPoint.x());
	writer->writeReal(22,m_centerPoint.y() - m_radius);
	writer->writeReal(32,0.0);
	writer->writeReal(13,m_centerPoint.x());
	writer->writeReal(23,m_centerPoint.y() - m_radius);
	writer->writeReal(33,0.0);
	writer->writeReal(210,0.0);
	writer->writeReal(220,0.0);
	writer->writeReal(230,1.0);

	writer->writeString(0,QString("ENDBLK"));
	writer->writeString(8,m_layerName);
}

QPair<double,double> QDxfSolidCircle::computeXpos(double ypos)
{
	double xvalue = qSqrt(m_radius*m_radius - (ypos - m_centerPoint.y())*(ypos - m_centerPoint.y()));
	return QPair<double,double>(-xvalue + m_centerPoint.x(),xvalue + m_centerPoint.x());
}
