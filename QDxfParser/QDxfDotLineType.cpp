#include "QDxfDotLineType.h"


QDxfDotLineType::QDxfDotLineType(void)
{
    elementCount = 2;
    elementLength.push_back(0.00);
    elementLength.push_back(-3.17);
    lineTypeName = "DotLine";
    //description = QString::fromLocal8Bit("µãÏß¶Î");
    description = "DotLine";
}


QDxfDotLineType::~QDxfDotLineType(void)
{
}

void QDxfDotLineType::write( QDxfWriter* writer )
{
    writer->writeString(0,QString::fromStdString(c_sLtype));
    writer->writeString(2,lineTypeName);
    writer->writeInt(70,flag);
    writer->writeString(3,description);
    writer->writeInt(72,alignment);
    writer->writeInt(73,elementCount);
    writer->writeReal(40,patternLength);
}
