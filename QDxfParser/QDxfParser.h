#ifndef QDXFPARSER_H
#define QDXFPARSER_H
#include <QList>
#include "QDxfWriter.h"
#include "QDxfLineType.h"
#include "QDxfDotLineType.h"
#include "QDxfLine.h"
#include "QDxfLayer.h"
#include "QDxfStyle.h"
#include "QDxfText.h"

class QDxfParser
{
public:
    QDxfParser(QDxfWriter* writer = nullptr);
    ~QDxfParser();
    void setWriter(QDxfWriter* writer);
    void write();
    void addLType(QDxfLineType* dxfLType);
    void addLine(QDxfLine* dxfLine);
    void addLayer(QDxfLayer* dxfLayer);
    void addStyle(QDxfStyle* dxfStyle);
    void addText(QDxfText* dxfText);
private:
    QDxfWriter* m_writer;
    QList<QDxfLineType*> ltypeList;
    QList<QDxfLine*> lineList;
    QList<QDxfLayer*> layerList;
    QList<QDxfStyle*> styleList;
    QList<QDxfText*> textList;
};

#endif // QDXFPARSER_H
