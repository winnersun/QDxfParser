
#include <QtCore/QCoreApplication>
#include "QDxfParser.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QDxfWriter writer;
    if(writer.openFile("D:/test1.dxf"))
    {
        QDxfParser parser(&writer);
        QDxfLineType* solidLineType = new QDxfLineType(QString::fromLocal8Bit("²âÊÔ1"),QString::fromLocal8Bit("²âÊÔ1"));
        parser.addLType(solidLineType);
        QDxfDotLineType* dotLineType = new QDxfDotLineType;
        parser.addLType(dotLineType);

        QDxfLayer* barLayer = new QDxfLayer(QString::fromLocal8Bit("¸Ö½î"),solidLineType->lineTypeName(),QColor(Qt::yellow));
        parser.addLayer(barLayer);
        QDxfLayer* barNameLayer = new QDxfLayer(QString::fromLocal8Bit("¸Ö½îÃû"),solidLineType->lineTypeName(),QColor(Qt::white));
        parser.addLayer(barNameLayer);
        QDxfStyle* textStyle = new QDxfStyle(QString("style1"),QString("TIMES.TTF"));
        parser.addStyle(textStyle);
        QDxfLine* testLine = new QDxfLine(QPointF(200,500),QPointF(6800,500),barLayer->layerName(),QColor(Qt::yellow));
        parser.addLine(testLine);
        QDxfText* testText = new QDxfText(QPointF(-200,500),QString::fromLocal8Bit("²âÊÔ"),barNameLayer->layerName(),textStyle->styleName(),150.0,1,2);
        parser.addText(testText);
        parser.write();
    }
    return a.exec();
}
