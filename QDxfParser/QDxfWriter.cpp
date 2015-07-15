#include "QDxfWriter.h"


QDxfWriter::QDxfWriter(void)
{
    outStream = nullptr;
}

QDxfWriter::~QDxfWriter(void)
{
    myFile.close();
}

void QDxfWriter::writeString( int code ,const QString& value )
{
    if (outStream)
    {
        *outStream<<QString::number(code)<<endl<<value<<endl;
    }
}

void QDxfWriter::writeReal( int code ,double value )
{
    if (outStream)
    {
        *outStream<<QString::number(code)<<endl<<QString::number(value)<<endl;
    }
}

void QDxfWriter::writeInt( int code, int value )
{
    if (outStream)
    {
        *outStream<<QString::number(code)<<endl<<QString::number(value)<<endl;
    }
}

void QDxfWriter::startSection()
{
    if (outStream)
    {
        *outStream<<QString::number(0)<<endl<<QString::fromStdString(c_sSection)<<endl;
    }
}

void QDxfWriter::endSection()
{
    if (outStream)
    {
        *outStream<<QString::number(0)<<endl<<QString::fromStdString(c_sEndsec)<<endl;
    }
}

bool QDxfWriter::openFile( const QString& filePath )
{
    myFile.setFileName(filePath);
    if (!myFile.open(QIODevice::WriteOnly | QIODevice::Text))
        return false;
    outStream = new QTextStream(&myFile);
    outStream->setCodec("ANSI");
    //QTextCodec*
    //outStream->setCodec()
    return true;
}
