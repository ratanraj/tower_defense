#include "tower.h"
#include <iostream>
#include <cmath> // For sqrt function

Tower::Tower() {
x=500;
y=500;
range=100;
}

// Get the x-coordinate of the tower
int Tower::get_x() {
    return x;
}

// Get the y-coordinate of the tower
int Tower::get_y() {
    return y;
}

// Get the range of the tower
int Tower::get_range() {
    return range;
}

// Check if a point is within the tower's range
bool Tower::is_within_range(int targetX, int targetY) {
    // Calculate the distance between the tower and the point
    int dx = x - targetX;
    int dy = y - targetY;
    double distance = sqrt(dx * dx + dy * dy);

    // Return true if the distance is less than or equal to the range of the tower
    std::cout<<distance<<":"<<range<<std::endl;
    return distance <= range;
}

