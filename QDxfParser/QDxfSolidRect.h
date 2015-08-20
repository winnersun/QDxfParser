
#ifndef QDXFSOLIDRECT_H
#define QDXFSOLIDRECT_H
#include "QDxfSolid.h"

class QDxfSolidRect : public QDxfSolid
{
public:
	QDxfSolidRect(const QPointF& lt, const QPointF& rb, const QString& layerName, const QString& lineTypeName, const QString& solidName, QColor color );
	~QDxfSolidRect(void);
	virtual void write(QDxfWriter* writer);
	virtual void writeBlock(QDxfWriter* writer);
private:
	QList<QPointF> m_pointList;
	QString m_layerName;
	QString m_lineTypeName;
	QString m_solidName;
	QColor m_color;
};
#endif // QDXFSOLIDRECT_H

