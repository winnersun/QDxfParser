#include "QDxfText.h"
#include "QDxfWriter.h"
#include "DxfCommon.h"

QDxfText::QDxfText( const QPointF& insertPoint ,const QString& textString ,const QString& layerName , const QString& styleName ,double height, int horizenAlign, int verticalAlign, QColor color)
    :m_insertPoint(insertPoint),m_textString(textString),m_layerName(layerName),m_styleName(styleName),m_height(height),m_horizenAlign(horizenAlign),m_verticalAlign(verticalAlign),m_color(color)
{
    m_alignmentPoint = QPointF(m_insertPoint.x()+10,m_insertPoint.y());
    m_rotation = 0.0;
}


QDxfText::~QDxfText(void)
{
}

void QDxfText::write( QDxfWriter* writer )
{
    writer->writeString(0,QString::fromStdString(c_sText));
    writer->writeString(8,m_layerName);
    writer->writeString(7,m_styleName);
    writer->writeReal(10,m_insertPoint.x());
    writer->writeReal(20,-m_insertPoint.y());
    writer->writeReal(30,0);
    writer->writeReal(11,m_alignmentPoint.x());
    writer->writeReal(21,-m_alignmentPoint.y());
    writer->writeReal(31,0);
    writer->writeReal(50,m_rotation);
    writer->writeInt(72,m_horizenAlign);
    writer->writeInt(73,m_verticalAlign);
    writer->writeReal(40,m_height);
    writer->writeInt(62,qcolorToAutoCadColorIndex(m_color));
    writer->writeString(1,m_textString);


}
