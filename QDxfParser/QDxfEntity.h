
#ifndef QDXFENTITY_H
#define QDXFENTITY_H

#include <QPoint>
#include <QtGui/QColor>
class QDxfWriter;

class QDxfEntity
{
public:
	QDxfEntity(void);
	virtual ~QDxfEntity(void);
	virtual void write(QDxfWriter* writer) = 0;
};
#endif // QDXFENTITY_H

