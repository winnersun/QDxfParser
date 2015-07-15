#ifndef QDXFPARSER_H
#define QDXFPARSER_H
#include <QList>
#include "QDxfWriter.h"
#include "QDxfLineType.h"
#include "QDxfDotLineType.h"
#include "QDxfLine.h"
#include "QDxfLayer.h"

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
private:
    QDxfWriter* m_writer;
    QList<QDxfLineType*> ltypeList;
    QList<QDxfLine*> lineList;
    QList<QDxfLayer*> layerList;
};

#endif // QDXFPARSER_H
