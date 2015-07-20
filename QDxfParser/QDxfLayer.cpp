#include "QDxfLayer.h"
#include "QDxfWriter.h"
#include "DxfCommon.h"

QDxfLayer::QDxfLayer( const QString& layerName ,const QString& lineTypeName ,QColor& color )
    :m_flag(0),m_layerName(layerName),m_lineTypeName(lineTypeName),m_color(color)
{

}


QDxfLayer::~QDxfLayer(void)
{
}

void QDxfLayer::write( QDxfWriter* writer )
{
    writer->writeString(0,QString::fromStdString(c_sLayer));
    writer->writeString(2,m_layerName);
    writer->writeInt(70,m_flag);
    writer->writeInt(62,qcolorToAutoCadColorIndex(m_color));
    writer->writeString(6,m_lineTypeName);
}
