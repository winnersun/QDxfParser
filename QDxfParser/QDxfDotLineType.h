#pragma once
#include "qdxflinetype.h"
#include <QVector>
class QDxfDotLineType :
    public QDxfLineType
{
public:
    QDxfDotLineType(void);
    virtual ~QDxfDotLineType(void);
    virtual void write(QDxfWriter* writer);
protected:
    QVector<double> elementLength;
};

