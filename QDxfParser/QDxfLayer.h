
#ifndef QDXFLAYER_H
#define QDXFLAYER_H
#include <QtGui/QColor>
class QDxfWriter;
class QDxfLayer
{
public:
    QDxfLayer(const QString& layerName ,const QString& lineTypeName ,QColor& color);
    ~QDxfLayer(void);
    void write(QDxfWriter* writer);
    QString layerName() const { return m_layerName; }
    void setLayerName(QString val) { m_layerName = val; }
private:
    QString m_layerName;
    QString m_lineTypeName;
    QColor m_color;
    int m_flag;
};
#endif // QDXFLAYER_H

