#include "pvo.h"

Pvo::Pvo(int x, int y, int z) : Point(x,y,z)
{
    pix = QPixmap(":/resource/PVO.jpg");
}

QPixmap Pvo::GetPixmap()
{
    return pix;
}
