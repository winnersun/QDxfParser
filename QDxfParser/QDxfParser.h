#ifndef QDXFPARSER_H
#define QDXFPARSER_H

class QDxfWriter;
class QDxfParser
{
public:
    QDxfParser(QDxfWriter* writer = nullptr);
    ~QDxfParser();
    void setWriter(QDxfWriter* writer);
private:
    QDxfWriter* m_writer;
};

#endif // QDXFPARSER_H
