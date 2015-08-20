
#ifndef QDXFSOLID_H
#define QDXFSOLID_H

#include "QDxfEntity.h"
class QDxfSolid :	public QDxfEntity
{
public:
	QDxfSolid(void);
	virtual ~QDxfSolid(void);
	virtual void writeBlock(QDxfWriter* writer) = 0;
};
#endif // QDXFSOLID_H

