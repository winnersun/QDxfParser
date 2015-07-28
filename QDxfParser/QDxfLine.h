
#ifndef QDXFLINE_H
#define QDXFLINE_H

#include "QDxfEntity.h"
class QDxfLine :public QDxfEntity
{
public:
    QDxfLine(const QPointF& beginPoint ,const QPointF& endPoint ,const QString& layerName, QColor color = Qt::yellow);
    ~QDxfLine(void);
    virtual void write(QDxfWriter* writer);
protected:
    QPointF m_beginPoint;
    QPointF m_endPoint;
    //QString m_lineTypeName;
    QString m_layerName;
    QColor m_color;
    //double m_lineWidth;
};
#endif // QDXFLINE_H

