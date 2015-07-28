#ifndef QDXFPARSER_H
#define QDXFPARSER_H
#include <QList>
#include "QDxfWriter.h"
#include "QDxfLineType.h"
#include "QDxfDotLineType.h"
#include "QDxfLine.h"
#include "QDxfLayer.h"
#include "QDxfStyle.h"
#include "QDxfText.h"
#include "QDxfDashLineType.h"
#include "QDxfPolyLine.h"
#include "QDxfSolidRect.h"
#include "QDxfCircle.h"
#include "QDxfSolidCircle.h"

class QDxfParser
{
public:
    QDxfParser(QDxfWriter* writer = nullptr);
    ~QDxfParser();
    void setWriter(QDxfWriter* writer);
    void write();
    void addLType(QDxfLineType* dxfLType);
    void addLayer(QDxfLayer* dxfLayer);
    void addStyle(QDxfStyle* dxfStyle);
	void addAPPID(QString appid);
	void addSolid(QDxfSolid* dxfSolid);
	void addEntity(QDxfEntity* dxfEntity);
	void setCenterPoint(const QPointF& centerPoint)
	{
		m_centerPoint = centerPoint;
	}
	void setShowHeight(double height)
	{
		m_showHeight = height;
	}
	QList<QDxfLineType*>& getLtypeList() { return ltypeList; }
	QList<QDxfStyle*> getStyleList() const { return styleList; }
	QList<QDxfLayer*> getLayerList() const { return layerList; }
private:
	void writeViewPort();
    QDxfWriter* m_writer;
    QList<QDxfLineType*> ltypeList;
	
	QList<QDxfLayer*> layerList;
	QList<QDxfStyle*> styleList;
	QList<QDxfEntity*> entityList;
	QList<QDxfSolid*> solidList;
	QList<QString> appidList;
	QPointF m_centerPoint;
	double m_showHeight;
};

#endif // QDXFPARSER_H
