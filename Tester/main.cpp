
#include <QtCore/QCoreApplication>
#include "QDxfParser.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QDxfWriter writer;
    if(writer.openFile("D:/test1.dxf"))
    {
        QDxfParser parser(&writer);
        parser.addLType(new QDxfLineType);
        parser.addLType(new QDxfDotLineType);
        parser.write();
    }
    return a.exec();
}
