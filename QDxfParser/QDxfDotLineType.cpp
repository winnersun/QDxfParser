#include "QDxfDotLineType.h"


QDxfDotLineType::QDxfDotLineType(void)
{
    m_elementCount = 2;
    m_elementLength.push_back(0.00);
    m_elementLength.push_back(-3.17);
    m_lineTypeName = "DotLine";
    //description = QString::fromLocal8Bit("µãÏß¶Î");
    m_description = "DotLine";
}

QDxfDotLineType::QDxfDotLineType( QString lineTypeName ,QString description ):QDxfLineType(lineTypeName,description)
{

}


QDxfDotLineType::~QDxfDotLineType(void)
{
}

void QDxfDotLineType::write( QDxfWriter* writer )
{
    writer->writeString(0,QString::fromStdString(c_sLtype));
    writer->writeString(2,m_lineTypeName);
    writer->writeInt(70,m_flag);
    writer->writeString(3,m_description);
    writer->writeInt(72,m_alignment);
    writer->writeInt(73,m_elementCount);
    writer->writeReal(40,m_patternLength);
    Q_FOREACH(int length,m_elementLength)
    {
        writer->writeReal(49,length);
    }
}
