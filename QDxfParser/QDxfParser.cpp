#include "qdxfparser.h"

QDxfParser::QDxfParser( QDxfWriter* writer):m_writer(writer)
{
	m_showHeight = 10000;
	m_centerPoint = QPointF(11000,-4000);
}

QDxfParser::~QDxfParser()
{
    qDeleteAll(ltypeList);
    qDeleteAll(entityList);
	qDeleteAll(solidList);
    qDeleteAll(layerList);
}

void QDxfParser::write()
{
    if (m_writer)
    {
        m_writer->startSection();
        m_writer->writeString(2,QString::fromStdString(c_sHeader));
		m_writer->writeString(9,QString("$ACADVER"));
		m_writer->writeString(1,QString("AC1009"));
        m_writer->endSection();
        m_writer->startSection();
        m_writer->writeString(2,QString::fromStdString(c_sTables));

		writeViewPort();

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
		//дAPPID
		m_writer->writeString(0,QString::fromStdString(c_sTable));
		addAPPID(QString("ACAD"));
		addAPPID(QString("GRADIENTCOLOR1ACI"));
		addAPPID(QString("GRADIENTCOLOR2ACI"));
		m_writer->writeString(2,QString("APPID"));
		m_writer->writeInt(70,11);
		for (int i = 0; i < appidList.size(); ++i)
		{
			m_writer->writeString(0,QString("APPID"));
			m_writer->writeString(2,appidList.at(i));
			m_writer->writeInt(70,0);
		}
		m_writer->writeString(0,QString::fromStdString(c_sEndtab));
		m_writer->endSection();
		if (!solidList.isEmpty())
		{
			m_writer->startSection();
			m_writer->writeString(2,QString("BLOCKS"));
			for (int i = 0; i < solidList.size(); ++i)
			{
				solidList.at(i)->writeBlock(m_writer);
			}
			m_writer->endSection();
		}
        
        m_writer->startSection();
        m_writer->writeString(2,QString::fromStdString(c_sEntities));
        for (int i = 0; i < entityList.size(); ++i)
        {
            entityList.at(i)->write(m_writer);
        }

		for (int i = 0; i < solidList.size(); ++i)
		{
			solidList.at(i)->write(m_writer);
		}
        m_writer->endSection();
        m_writer->eof();
    }
}

void QDxfParser::addLType( QDxfLineType* dxfLType )
{
    ltypeList.append(dxfLType);
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

void QDxfParser::setWriter( QDxfWriter* writer )
{
    m_writer = writer;
}

void QDxfParser::addAPPID(QString appid)
{
	if (!appidList.contains(appid))
	{
		appidList.append(appid);
	}
}

void QDxfParser::addSolid(QDxfSolid* dxfSolid)
{
	solidList.append(dxfSolid);
}

void QDxfParser::addEntity(QDxfEntity* dxfEntity)
{
	entityList.append(dxfEntity);
}

void QDxfParser::writeViewPort()
{
	m_writer->writeString(0,QString::fromStdString(c_sTable));
	m_writer->writeString(2,QString("VPORT"));
	m_writer->writeInt(70,1);
	m_writer->writeString(0,QString("VPORT"));
	m_writer->writeString(2,QString("*ACTIVE"));
	m_writer->writeInt(70,0);
	m_writer->writeReal(10,0.0);
	m_writer->writeReal(20,0.0);
	m_writer->writeReal(11,1.0);
	m_writer->writeReal(21,1.0);
	m_writer->writeReal(12,m_centerPoint.x());
	m_writer->writeReal(22,m_centerPoint.y());
	m_writer->writeReal(13,0.0);
	m_writer->writeReal(23,0.0);
	m_writer->writeReal(14,10.0);
	m_writer->writeReal(24,10.0);
	m_writer->writeReal(15,10.0);
	m_writer->writeReal(25,10.0);
	m_writer->writeReal(16,0.0);
	m_writer->writeReal(26,0.0);
	m_writer->writeReal(36,1.0);
	m_writer->writeReal(17,0.0);
	m_writer->writeReal(27,0.0);
	m_writer->writeReal(37,0.0);
	m_writer->writeReal(40,m_showHeight);
	m_writer->writeReal(41,2.375);
	m_writer->writeReal(42,50);
	m_writer->writeReal(43,0.0);
	m_writer->writeReal(44,0.0);
	m_writer->writeReal(50,0.0);
	m_writer->writeReal(51,0.0);
	m_writer->writeInt(71,0);
	m_writer->writeInt(72,1000);
	m_writer->writeInt(73,1);
	m_writer->writeInt(74,3);
	m_writer->writeInt(75,0);
	m_writer->writeInt(76,1);
	m_writer->writeInt(77,0);
	m_writer->writeInt(78,0);
	m_writer->writeString(0,QString::fromStdString(c_sEndtab));
}
