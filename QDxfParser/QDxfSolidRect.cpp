#include "QDxfSolidRect.h"
#include "QDxfWriter.h"
#include "DxfCommon.h"

QDxfSolidRect::QDxfSolidRect(const QPointF& lt, const QPointF& rb, const QString& layerName, const QString& lineTypeName, const QString& solidName, QColor color)
	:m_layerName(layerName),m_lineTypeName(lineTypeName),m_solidName(solidName),m_color(color)
{
	m_pointList.push_back(lt);
	m_pointList.push_back(QPointF(rb.x(),lt.y()));
	m_pointList.push_back(rb);
	m_pointList.push_back(QPointF(lt.x(),rb.y()));
}


QDxfSolidRect::~QDxfSolidRect(void)
{
}

void QDxfSolidRect::write(QDxfWriter* writer)
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
	writer->writeInt(1070,0);
	writer->writeInt(1070,1);
	writer->writeInt(1070,3);
	writer->writeReal(1040,m_pointList[1].x());
	writer->writeReal(1040,m_pointList[1].y());
	writer->writeReal(1040,m_pointList[0].x());
	writer->writeReal(1040,m_pointList[0].y());
	writer->writeReal(1040,m_pointList[3].x());
	writer->writeReal(1040,m_pointList[3].y());
	writer->writeReal(1040,m_pointList[2].x());
	writer->writeReal(1040,m_pointList[2].y());
	writer->writeInt(1071,1);
	writer->writeInt(1070,1);
	writer->writeInt(1070,1);
	writer->writeInt(1071,1);
	writer->writeString(1002,"}");
}

void QDxfSolidRect::writeBlock(QDxfWriter* writer)
{
	writer->writeString(0,QString("BLOCK"));
	writer->writeString(8,m_layerName);
	writer->writeString(2,m_solidName);
	writer->writeInt(70,1);
	writer->writeReal(10,0.0);
	writer->writeReal(20,0.0);
	writer->writeReal(30,0.0);
	writer->writeString(3,m_solidName);
	writer->writeString(0,"SOLID");
	writer->writeString(8,m_layerName);
	writer->writeString(6,m_lineTypeName);
	writer->writeInt(62,qcolorToAutoCadColorIndex(m_color));
	writer->writeReal(10,m_pointList[0].x());
	writer->writeReal(20,m_pointList[0].y());
	writer->writeReal(30,0.0);
	writer->writeReal(11,m_pointList[3].x());
	writer->writeReal(21,m_pointList[3].y());
	writer->writeReal(31,0.0);
	writer->writeReal(12,m_pointList[2].x());
	writer->writeReal(22,m_pointList[2].y());
	writer->writeReal(32,0.0);
	writer->writeReal(13,m_pointList[2].x());
	writer->writeReal(23,m_pointList[2].y());
	writer->writeReal(33,0.0);
	writer->writeString(0,"SOLID");
	writer->writeString(8,m_layerName);
	writer->writeString(6,m_lineTypeName);
	writer->writeInt(62,qcolorToAutoCadColorIndex(m_color));
	writer->writeReal(10,-m_pointList[0].x());
	writer->writeReal(20,m_pointList[0].y());
	writer->writeReal(30,0.0);
	writer->writeReal(11,-m_pointList[1].x());
	writer->writeReal(21,m_pointList[1].y());
	writer->writeReal(31,0.0);
	writer->writeReal(12,-m_pointList[2].x());
	writer->writeReal(22,m_pointList[2].y());
	writer->writeReal(32,0.0);
	writer->writeReal(13,-m_pointList[2].x());
	writer->writeReal(23,m_pointList[2].y());
	writer->writeReal(33,0.0);
	writer->writeReal(210,0.0);
	writer->writeReal(220,0.0);
	writer->writeReal(230,-1.0);
	writer->writeString(0,QString("ENDBLK"));
	writer->writeString(8,m_layerName);
}
