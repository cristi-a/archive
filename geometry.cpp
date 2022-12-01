#include <bits/stdc++.h>
using namespace std;
using ld = long double;

struct Point {
    int x, y;
    Point operator+(const Point &other) {
        return {x + other.x, y + other.y};
    }
    Point operator-(const Point &other) {
        return {x - other.x, y - other.y};
    }
    Point operator*(const int scalar) {
        return {x * scalar, y * scalar};
    }
    // dot product
    // = 0 => perpendicular
    // > 0 => angle < 90 deg
    // < 0 => angle > 90 deg 
    int operator*(const Point &other) {
        return x * other.x + y * other.y;
    }
    // cross product
    // = 0 => colinear
    // > 0 => counterclockwise
    // < 0 => clockwise 
    int operator^(const Point &other) {
        return x * other.y - y * other.x;
    }
};

struct Line {
    // ax + by + c = 0
    // n - perpendicular
    int a, b, c;
    Point n;
    Line(Point p, Point q) {
        a = p.y - q.y;
        b = q.x - p.x;
        c = p.x * q.y - q.x * p.y;
        n = {-b, a};
    }
};

ld Length(Point temp) {
    return sqrt(temp * temp);
}

ld Dist(Point a, Line d) {
    return abs(d.a * a.x + d.b * a.y + d.c) / sqrt(d.a * d.a + d.b * d.b);
}
