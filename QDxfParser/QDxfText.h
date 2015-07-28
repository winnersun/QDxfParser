
#ifndef QDXFTEXT_H
#define QDXFTEXT_H
#include "QDxfEntity.h"
class QDxfText : public QDxfEntity
{
public:
    QDxfText(const QPointF& insertPoint ,const QString& textString ,const QString& layerName , const QString& styleName ,double height, int horizenAlign = 1, int verticalAlign = 1, QColor color = Qt::white);
    virtual ~QDxfText(void);
    virtual void write(QDxfWriter* writer);
private:
    QPointF m_insertPoint;
    QPointF m_alignmentPoint;
    QString m_layerName;
    QString m_textString;
    QString m_styleName;
    double  m_height;
    int     m_horizenAlign;
    int     m_verticalAlign;
    QColor  m_color;
    double  m_rotation;
};
#endif // QDXFTEXT_H

