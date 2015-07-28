
#ifndef QDXFWRITER_H
#define QDXFWRITER_H
#include "DxfConst.h"
#include <QFile>
#include <QTextStream>
/************************************************************************
* @brief use to do raw file write.User can use QDxfParser instead.
* @note
* @author sunxb  
* @date  2015/7/14                                                                 
************************************************************************/
class QDxfWriter
{
public:
    QDxfWriter(void);
    ~QDxfWriter(void);
public:
    void writeString(int code ,const QString& value);
    void writeReal(int code ,double value);
    void writeInt(int code, int value);
    void startSection();
    void endSection();
    void eof();
    bool openFile(const QString& filePath);
	int getHandleNum();
private:
    QFile myFile;
    QTextStream* outStream;
	static int handleNum;
};
#endif // QDXFWRITER_H

