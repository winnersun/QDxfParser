#ifndef QDXFSOLIDCIRCLE_H
#define QDXFSOLIDCIRCLE_H
#include "QDxfSolid.h"

class QDxfSolidCircle : public QDxfSolid
{
public:
	QDxfSolidCircle(const QPointF& center,double radius,const QString& layerName,  const QString& lineTypeName, const QString& solidName, QColor color = Qt::yellow);
	~QDxfSolidCircle(void);
	virtual void write(QDxfWriter* writer);
	virtual void writeBlock(QDxfWriter* writer);
private:
	QPair<double,double> computeXpos(double ypos);
	QPointF m_centerPoint;
	double m_radius;
	QString m_layerName;
	QString m_lineTypeName;
	QString m_solidName;
	QColor m_color;
};
#endif // QDXFSOLIDCIRCLE_H

