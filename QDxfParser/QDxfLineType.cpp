#include "QDxfLineType.h"
#include "DxfConst.h"

QDxfLineType::QDxfLineType(void):m_alignment(65),m_flag(0),m_elementCount(0),m_patternLength(0.00)
{
    m_lineTypeName = "SolidLine";
    //description = QString::fromLocal8Bit("ÊµÏß¶Î");
    m_description = "SolidLine";
}

QDxfLineType::QDxfLineType( QString lineTypeName ,QString description )
    :m_alignment(65),m_flag(0),m_elementCount(0),m_patternLength(0.00),m_lineTypeName(lineTypeName),m_description(description)
{

}


QDxfLineType::~QDxfLineType(void)
{
}

void QDxfLineType::write( QDxfWriter* writer )
{
    writer->writeString(0,QString::fromStdString(c_sLtype));
    writer->writeString(2,m_lineTypeName);
    writer->writeInt(70,m_flag);
    writer->writeString(3,m_description);
    writer->writeInt(72,m_alignment);
    writer->writeInt(73,m_elementCount);
    writer->writeReal(40,m_patternLength);
}
