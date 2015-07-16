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
        //write LType Table
        m_writer->writeString(0,QString::fromStdString(c_sTable));
        m_writer->writeString(2,QString::fromStdString(c_sLtype));
        for (int i = 0; i < ltypeList.size(); ++i)
        {
            ltypeList.at(i)->write(m_writer);
        }
        m_writer->writeString(0,QString::fromStdString(c_sEndtab));
        //write Layer Table
        m_writer->writeString(0,QString::fromStdString(c_sTable));
        m_writer->writeString(2,QString::fromStdString(c_sLayer));
        for (int i = 0; i < layerList.size(); ++i)
        {
            layerList.at(i)->write(m_writer);
        }
        m_writer->writeString(0,QString::fromStdString(c_sEndtab));
        //write Style Table
        m_writer->writeString(0,QString::fromStdString(c_sTable));
        m_writer->writeString(2,QString::fromStdString(c_sStyle));
        for (int i = 0; i < styleList.size(); ++i)
        {
            styleList.at(i)->write(m_writer);
        }
        m_writer->writeString(0,QString::fromStdString(c_sEndtab));
        m_writer->endSection();
        m_writer->startSection();
        m_writer->writeString(2,QString::fromStdString(c_sEntities));
        for (int i = 0; i < lineList.size(); ++i)
        {
            lineList.at(i)->write(m_writer);
        }
        for (int i = 0; i < textList.size(); ++i)
        {
            textList.at(i)->write(m_writer);
        }
        m_writer->endSection();
        m_writer->eof();
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
    //TODO CHECK SAME
    layerList.append(dxfLayer);
}

void QDxfParser::addStyle( QDxfStyle* dxfStyle )
{
    styleList.append(dxfStyle);
}

void QDxfParser::addText( QDxfText* dxfText )
{
    textList.append(dxfText);
}
