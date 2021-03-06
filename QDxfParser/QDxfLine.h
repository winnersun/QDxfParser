
#ifndef QDXFLINE_H
#define QDXFLINE_H

#include <QPoint>
#include <QtGui/QColor>
class QDxfWriter;
class QDxfLine
{
public:
    //QDxfLine(void);
    QDxfLine(const QPointF& beginPoint ,const QPointF& endPoint ,const QString& layerName, QColor color = Qt::yellow);
    ~QDxfLine(void);
    void write(QDxfWriter* writer);
protected:
    QPointF m_beginPoint;
    QPointF m_endPoint;
    //QString m_lineTypeName;
    QString m_layerName;
    QColor m_color;
    //double m_lineWidth;
};
#endif // QDXFLINE_H

