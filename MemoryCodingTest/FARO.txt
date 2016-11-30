I want to create a Halloween game for a scratch-and-win lottery with the following rules:
- The user will buy a card with N buckets whose content is hidden. One of these buckets contains a pumpkin, and one contains a ghost.
- The user may choose to scratch X buckets of his choice to reveal their contents.
- The user will win the prize if the pumpkin has been scratched and the ghost has NOT been scratched 
We want to evaluate the probability to win by using brutal force (i.e. assuming we cannot compute the probably in advance). 
Implement a short function in C++ that will generate a high number of random combinations and counts the number of winning ones.



We want to compute the center of gravity for a high number of pixels (1000+) given their coordinates in struct Coord { int x; int y;}. Implement a function receiving a vector of Coord and returning the center of gravity.

#inlcude <vector>

struct Coord    {
  int x;
  int y;
};

Coord getCenterOfGravity(const std::vector<Coord>& pixelsVector)    {
    
    Coord centerOfGravity;
    centerOfGravity.x = 0;
    centerOfGravity.y = 0;
    
    for (int i=0; i < pixelsVector.size(); i++)  {
        centerOfGravity.x += pixelsVector.at(i).x;
        centerOfGravity.y += pixelsVector.at(i).y;
    }
    
    centerOfGravity.x /= pixelsVector.size();
    centerOfGravity.y /= pixelsVector.size();
    
    return centerOfGravity;
}





Given a list of 2D rectangles (rectangle = quadrilateral with four right angles), implement a C++ function that will compute the smallest rectangle that include all these rectangles. A rectangle A is "included"in a rectnagle B when each of the 4 corners of rectangle A are either inside rectangle B, or on rectangle B's sides.


#include <vector>

struct Rectangle    {
    float left;
    float right;
    float top;
    float bottom;
};

Rectangle getSmallestRectangle(const std::vector<Rectangle>& rectVector)    {
    Rectangle smallest;
    smallest.left =   999999;
    smallest.right = -999999;
    smallest.top =   -999999;
    smallest.bottom = 999999;
    
    for (int i=0; i < rectVector.size(); i++)   {
        if(smallest.left   - rectVector.at(i).left   > 0.001)   smallest.left = rectVector.at(i).left ;
        if(smallest.right  - rectVector.at(i).right  < 0.001)   smallest.right = rectVector.at(i).right ;
        if(smallest.top    - rectVector.at(i).top    < 0.001)   smallest.top = rectVector.at(i).top ;
        if(smallest.bottom - rectVector.at(i).bottom > 0.001)   smallest.bottom = rectVector.at(i).bottom ;
    }
    
    return Rectangle;
}
