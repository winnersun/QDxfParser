#include "qdxfparser.h"

QDxfParser::QDxfParser( QDxfWriter* writer /*= NULL*/ ):m_writer(writer)
{

}

QDxfParser::~QDxfParser()
{
    qDeleteAll(ltypeList);
    qDeleteAll(lineList);
    qDeleteAll(layerList);
}

void QDxfParser::write()
{
    if (m_writer)
    {
        m_writer->startSection();
        m_writer->writeString(2,QString::fromStdString(c_sHeader));
        m_writer->endSection();
        m_writer->startSection();
        m_writer->writeString(2,QString::fromStdString(c_sTables));
        m_writer->writeString(0,QString::fromStdString(c_sTable));
        m_writer->writeString(2,QString::fromStdString(c_sLtype));
        for (int i = 0; i < ltypeList.size(); ++i)
        {
            ltypeList.at(i)->write(m_writer);
        }
        m_writer->writeString(0,QString::fromStdString(c_sEndtab));
        m_writer->writeString(0,QString::fromStdString(c_sTable));
        m_writer->writeString(2,QString::fromStdString(c_sLayer));
        for (int i = 0; i < layerList.size(); ++i)
        {
            layerList.at(i)->write(m_writer);
        }
    }
}

void QDxfParser::addLType( QDxfLineType* dxfLType )
{
    ltypeList.append(dxfLType);
}

void QDxfParser::addLine( QDxfLine* dxfLine )
{
    lineList.append(dxfLine);
}

void QDxfParser::addLayer( QDxfLayer* dxfLayer )
{
    layerList.append(dxfLayer);
}
