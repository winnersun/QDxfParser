
#ifndef QDXFDOTLINETYPE_H
#define QDXFDOTLINETYPE_H

#include "qdxflinetype.h"
#include <QList>
class QDxfDotLineType :
    public QDxfLineType
{
public:
    QDxfDotLineType(void);
    QDxfDotLineType(QString lineTypeName ,QString description);
    virtual ~QDxfDotLineType(void);
    virtual void write(QDxfWriter* writer);
protected:
    QList<double> m_elementLength;
};
#endif // QDXFDOTLINETYPE_H

