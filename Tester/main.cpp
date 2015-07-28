
#include <QtCore/QCoreApplication>
#include "QDxfParser.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QDxfWriter writer;
    if(writer.openFile("D:/test1.dxf"))
    {
        QDxfParser parser(&writer);
        QDxfLineType* solidLineType = new QDxfLineType(QString::fromLocal8Bit("solidLine1"),QString::fromLocal8Bit("solidLine1"));
        parser.addLType(solidLineType);
  //      QDxfDotLineType* dotLineType = new QDxfDotLineType;
  //      parser.addLType(dotLineType);
		//QDxfDashLineType* dashLineType = new QDxfDashLineType;
		//parser.addLType(dashLineType);

        QDxfLayer* barLayer = new QDxfLayer(QString::fromLocal8Bit("bar"),solidLineType->lineTypeName(),QColor(Qt::yellow));
        parser.addLayer(barLayer);
        QDxfLayer* barNameLayer = new QDxfLayer(QString::fromLocal8Bit("barName"),solidLineType->lineTypeName(),QColor(Qt::white));
        parser.addLayer(barNameLayer);
        QDxfStyle* textStyle = new QDxfStyle(QString("style1"),QString("TIMES.TTF"));
        parser.addStyle(textStyle);
        QDxfLine* testLine = new QDxfLine(QPointF(200,500),QPointF(6800,500),barLayer->layerName(),QColor(Qt::yellow));
        parser.addEntity(testLine);
        QDxfText* testText = new QDxfText(QPointF(-200,500),QString::fromLocal8Bit("²âÊÔ"),barNameLayer->layerName(),textStyle->styleName(),150.0,1,2);
        parser.addEntity(testText);
		QDxfCircle* circle = new QDxfCircle(QPointF(200,500),1000.0,barLayer->layerName(),QColor(Qt::darkBlue));
		parser.addEntity(circle);
		//QDxfSolidRect* solidRect = new QDxfSolidRect(QPointF(500,1000),QPointF(1500,200),barLayer->layerName(),solidLineType->lineTypeName(),QString("*u1"),Qt::red);
		//parser.addSolid(solidRect);
		QDxfSolidCircle* solidCircle = new QDxfSolidCircle(QPointF(1500,2000),1000.0,barLayer->layerName(),solidLineType->lineTypeName(),QString("*u3"),Qt::red);
		parser.addSolid(solidCircle);
		QDxfPolyLine* polyLine = new QDxfPolyLine(barLayer->layerName(),QColor(Qt::red),false);
		polyLine->addPoint(QPointF(500,1000));
		polyLine->addPoint(QPointF(550,200));
		polyLine->addPoint(QPointF(600,1000));
		polyLine->addPoint(QPointF(650,200));
		polyLine->addPoint(QPointF(700,1000));
		polyLine->addPoint(QPointF(750,200));
		polyLine->addPoint(QPointF(800,1000));
		polyLine->addPoint(QPointF(850,200));
		parser.addEntity(polyLine);
        parser.write();
    }
    return a.exec();
}
