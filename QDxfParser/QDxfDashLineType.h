
#ifndef QDXFDASHLINETYPE_H
#define QDXFDASHLINETYPE_H

#include "qdxflinetype.h"
class QDxfDashLineType :
	public QDxfLineType
{
public:
	QDxfDashLineType(void);
	QDxfDashLineType(QString lineTypeName ,QString description);
	~QDxfDashLineType(void);
	virtual void write(QDxfWriter* writer);
protected:
	QList<double> m_elementLength;
};
#endif // QDXFDASHLINETYPE_H

