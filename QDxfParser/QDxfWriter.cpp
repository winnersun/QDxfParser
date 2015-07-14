#include "QDxfWriter.h"


QDxfWriter::QDxfWriter(void)
{
}

QDxfWriter::~QDxfWriter(void)
{
}

void QDxfWriter::writeString( int code ,const QString& value )
{

}

void QDxfWriter::writeReal( int code ,double value )
{

}

void QDxfWriter::writeInt( int code, int value )
{

}

void QDxfWriter::startSection()
{

}

void QDxfWriter::endSection()
{

}

bool QDxfWriter::openFile( const QString& filePath )
{
    myFile.setFileName(filePath);
    return true;
}
