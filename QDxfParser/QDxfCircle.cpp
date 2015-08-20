#include "QDxfCircle.h"
#include "QDxfWriter.h"
#include "DxfCommon.h"

QDxfCircle::QDxfCircle(const QPointF& center,double radius,const QString& layerName, QColor color)
	:m_centerPoint(center),m_radius(radius),m_layerName(layerName),m_color(color)
{

}


QDxfCircle::~QDxfCircle(void)
{
}

void QDxfCircle::write(QDxfWriter* writer)
{
	writer->writeString(0,QString("CIRCLE"));
	writer->writeString(8,m_layerName);
	writer->writeInt(62,qcolorToAutoCadColorIndex(m_color));
	writer->writeReal(10,m_centerPoint.x());
	writer->writeReal(20,m_centerPoint.y());
	writer->writeReal(30,0.0);
	writer->writeReal(40,m_radius);
}
