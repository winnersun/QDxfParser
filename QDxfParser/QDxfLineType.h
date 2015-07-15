#ifndef QDXFLINETYPE_H
#define QDXFLINETYPE_H
#include <QString>
#include "QDxfWriter.h"
class QDxfLineType
{
public:
    QDxfLineType(void);
    virtual ~QDxfLineType(void);
    virtual void write(QDxfWriter* writer);
protected:
    QString lineTypeName;
    QString description;
    int flag;
    int alignment;
    int elementCount;
    double patternLength;
};
#endif // QDXFLINETYPE_H

