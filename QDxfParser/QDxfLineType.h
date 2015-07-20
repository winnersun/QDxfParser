#ifndef QDXFLINETYPE_H
#define QDXFLINETYPE_H
#include <QString>
#include "QDxfWriter.h"
class QDxfLineType
{
public:
    QDxfLineType(void);
    QDxfLineType(QString lineTypeName ,QString description);
    virtual ~QDxfLineType(void);
    virtual void write(QDxfWriter* writer);
    QString lineTypeName() const { return m_lineTypeName; }
    void setLineTypeName(QString val) { m_lineTypeName = val; }
protected:
    QString m_lineTypeName;

    QString m_description;
    int m_flag;
    int m_alignment;
    int m_elementCount;
    double m_patternLength;
};
#endif // QDXFLINETYPE_H

