#include "QDxfLineType.h"
#include "DxfConst.h"

QDxfLineType::QDxfLineType(void):alignment(65),flag(0),elementCount(0),patternLength(0.00)
{
    lineTypeName = "SolidLine";
    //description = QString::fromLocal8Bit("ÊµÏß¶Î");
    description = "SolidLine";
}


QDxfLineType::~QDxfLineType(void)
{
}

void QDxfLineType::write( QDxfWriter* writer )
{
    writer->writeString(0,QString::fromStdString(c_sLtype));
    writer->writeString(2,lineTypeName);
    writer->writeInt(70,flag);
    writer->writeString(3,description);
    writer->writeInt(72,alignment);
    writer->writeInt(73,elementCount);
    writer->writeReal(40,patternLength);
}
