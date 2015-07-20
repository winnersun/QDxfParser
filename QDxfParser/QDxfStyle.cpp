#include "QDxfStyle.h"
#include "QDxfWriter.h"

QDxfStyle::QDxfStyle( const QString& styleName ,QString fontName )
    :m_styleName(styleName),m_fontName(fontName),m_flag(0),m_textFlag(0),m_fixedTextHeight(0.00),m_widthFactor(1.00),m_lastUsedHeight(0.20),m_obliqueAngle(0.00)
{

}


QDxfStyle::~QDxfStyle(void)
{
}

void QDxfStyle::write( QDxfWriter* writer )
{
    writer->writeString(0,QString::fromStdString(c_sStyle));
    writer->writeString(2,m_styleName);
    writer->writeString(3,m_fontName);
    writer->writeInt(70,m_flag);
    writer->writeInt(71,m_textFlag);
    writer->writeReal(40,m_fixedTextHeight);
    writer->writeReal(41,m_widthFactor);
    writer->writeReal(42,m_lastUsedHeight);
    writer->writeReal(50,m_obliqueAngle);   
}
