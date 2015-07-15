#include "QDxfLine.h"
#include "QDxfWriter.h"
#include "DxfCommon.h"
#include <DxfCommon.h>
//QDxfLine::QDxfLine(void)
//{
//}

QDxfLine::QDxfLine( const QPointF& beginPoint ,const QPointF& endPoint, QString lineTypeName, QString layerName, QColor color, double lineWidth)
    :m_beginPoint(beginPoint),m_endPoint(endPoint),m_lineTypeName(lineTypeName),m_layerName(layerName),m_color(color),m_lineWidth(lineWidth)
{
}


QDxfLine::~QDxfLine(void)
{
}

void QDxfLine::write( QDxfWriter* writer )
{
    writer->writeInt(73,qcolorToAutoCadColorIndex(m_color));
}
