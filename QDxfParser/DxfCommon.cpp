#include "DxfCommon.h"

int qcolorToAutoCadColorIndex(QColor color)
{
    if (color == Qt::black)
    {
        return 0;
    }
    else if (color == Qt::red)
    {
        return 1;
    }
    else if (color == Qt::yellow)
    {
        return 2;
    }
    else if (color == Qt::green)
    {
        return 3;
    }
    else if (color == Qt::cyan)
    {
        return 4;
    }
    else if (color == Qt::blue)
    {
        return 5;
    }
    else if (color == Qt::magenta)
    {
        return 6;
    }
    else if (color == Qt::white)
    {
        return 7;
    }
    else if (color == Qt::darkGray)
    {
        return 8;
    }
    else if (color == Qt::lightGray)
    {
        return 9;
    }
    else if (color == Qt::darkRed)
    {
        return 16;
    }
    else if (color == Qt::darkGreen)
    {
        return 96;
    }
    else if (color == Qt::darkBlue)
    {
        return 176;
    }
    else if (color == Qt::darkCyan)
    {
        return 136;
    }
    else if (color == Qt::darkMagenta)
    {
        return 216;
    }
    else if (color == Qt::darkYellow)
    {
        return 44;
    }
    return 0;
}