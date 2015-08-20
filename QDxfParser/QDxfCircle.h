#ifndef QDXFCIRCLE_H
#define QDXFCIRCLE_H
#include "QDxfEntity.h"

class QDxfCircle:public QDxfEntity
{
public:
	QDxfCircle(const QPointF& center,double radius,const QString& layerName, QColor color = Qt::yellow);
	~QDxfCircle(void);
	virtual void write(QDxfWriter* writer);
private:
	QPointF m_centerPoint;
	double m_radius;
	QString m_layerName;
	QColor m_color;
};
#endif // QDXFCIRCLE_H

