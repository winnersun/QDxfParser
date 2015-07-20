#include "QDxfLine.h"
#include "QDxfWriter.h"
#include "DxfCommon.h"

QDxfLine::QDxfLine( const QPointF& beginPoint ,const QPointF& endPoint, const QString& layerName, QColor color)
    :m_beginPoint(beginPoint),m_endPoint(endPoint),m_layerName(layerName),m_color(color)
{
}


QDxfLine::~QDxfLine(void)
{
}

void QDxfLine::write( QDxfWriter* writer )
{
    writer->writeString(0,QString::fromStdString(c_sLine));
    writer->writeString(8,m_layerName);
    writer->writeInt(62,qcolorToAutoCadColorIndex(m_color));
    writer->writeReal(10,m_beginPoint.x());
    writer->writeReal(20,-m_beginPoint.y());
    writer->writeReal(11,m_endPoint.x());
    writer->writeReal(21,-m_endPoint.y());
}
