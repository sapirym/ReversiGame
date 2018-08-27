


#include "Point.h"

Point::Point() {}
Point::Point(int x1,int y1) {
    x=x1;
    y=y1;
}
int Point::getX() {
    return x;
}
int Point::getY() {
    return y;
}
void Point::setPoint(int newX, int newY){
    x = newX;
    y= newY;
}