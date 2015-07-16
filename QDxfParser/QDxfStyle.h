
#ifndef QDXFSTYLE_H
#define QDXFSTYLE_H
#include <QtGui/QFont>

class QDxfWriter;
class QDxfStyle
{
public:
    QDxfStyle( const QString& styleName ,QString fontName);
    ~QDxfStyle(void);
    void write(QDxfWriter* writer);
    QString styleName() const { return m_styleName; }
    void setStyleName(QString val) { m_styleName = val; }
private:
    QString m_styleName;

    QString m_fontName;
    int m_flag;
    int m_textFlag;
    double m_fixedTextHeight;
    double m_widthFactor;
    double m_lastUsedHeight;
    double m_obliqueAngle;
};
#endif // QDXFSTYLE_H

