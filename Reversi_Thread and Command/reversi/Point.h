/**
 * hadas berger: 316590215
 * sapir yamin: 316251818
 **/

#ifndef EX3ADVENCED_POINT_H
#define EX3ADVENCED_POINT_H

#include <map>
class Point {
public:
    Point();
    /**
     * constructor.
     * @param x1
     * @param y1
     */
    Point(int x1,int y1);
    /**
     * @return the x value
     */
    int getX();
    /**
     * @return the y value
     */
    int getY();
    void setPoint(int x, int y);

private:
    int x;
    int y;
};


#endif //EX3ADVENCED_POINT_H
