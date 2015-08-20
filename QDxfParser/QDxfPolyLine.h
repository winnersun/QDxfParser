
#ifndef QDXFPOLYLINE_H
#define QDXFPOLYLINE_H

#include "QDxfEntity.h"

class QDxfPolyLine :public QDxfEntity
{
public:
	QDxfPolyLine(const QString& layerName, QColor color, bool bClosed);
	QDxfPolyLine(const QList<QPointF>& pointList,const QString& layerName, QColor color,bool bClosed);
	~QDxfPolyLine(void);
	virtual void write(QDxfWriter* writer);
	void addPoint(const QPointF& point);
private:
	QList<QPointF> m_pointList;
	QString m_layerName;
	QColor m_color;
	bool m_bClosed;
};
#endif // QDXFPOLYLINE_H

