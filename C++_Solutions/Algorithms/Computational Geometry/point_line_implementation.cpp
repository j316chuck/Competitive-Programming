//from http://blog.csdn.net/huanghongxun/article/details/50493334

struct Point {
    double x, y;
    Point(){}
    Point(double _x, double _y) : x(_x), y(_y) {}
    Point operator +(const Point &b) const { return Point(x + b.x, y + b.y); }
    Point operator -(const Point &b) const { return Point(x - b.x, y - b.y); }
    double operator *(const Point &b) const { return x * b.y - y * b.x; }
    Point operator *(double b) const { return Point(b * x, b * y); }
    Point normal() { return Point(-y, x); }
} p[N], poly[N];

struct Line {
    Point x, v;
    double ang;
    Line(){}
    Line(const Point &_x, const Point &_v) : x(_x), v(_v), ang(atan2(_v.y, _v.x)) { }

    bool operator <(const Line &b) const {
        if (ang == b.ang) return v * (b.x - x) < 0; // 极角相等时，这么算的叉积表示a在b的左边时返回Line a < b，unique的时候就会选择a而丢掉b。
        return ang < b.ang;
    }

    bool operator ==(const Line &b) const { return ang == b.ang; }

    Point intersection(const Line &b) {
        Point u = x - b.x;
        double t = (b.v * u) / (v * b.v); // 画了图才知道这么写的意思。。
        return x + v * t;
    }
};
vector<Line> lines;

//see if a point is on the rightside of line l
bool right(const Point &p, const Line &l) {
    return l.v * (p - l.x) <= 0;
}
