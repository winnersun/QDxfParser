
#ifndef QDXFLAYER_H
#define QDXFLAYER_H

class QDxfWriter;
class QDxfLayer
{
public:
    QDxfLayer(void);
    ~QDxfLayer(void);
    void write(QDxfWriter* writer);
};
#endif // QDXFLAYER_H

