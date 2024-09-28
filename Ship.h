#ifndef SHIP_H
#define SHIP_H

#include <vector>

enum class SegmentState {
    INTACT,      
    DAMAGED,     
    DESTROYED   
};

class Ship {
public:
    Ship(int length, bool isHorizontal);
    int getLength() const;
    bool isHorizontal() const;
    SegmentState getSegmentState(int index) const;
    void hitSegment(int index);
    bool isSunk() const;
private:
    int length;
    bool horizontal;
    std::vector<SegmentState> segments;
};

#endif
