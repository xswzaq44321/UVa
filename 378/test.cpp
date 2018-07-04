#include <cstdio>

struct Point {
	double x, y;
	Point(){
		this->x = -1e9;
		this->y = -1e9;
	}
	Point(double a, double b){
		this->x = a;
		this->y = b;
	}
	Point operator-(const Point& rhs){
		Point temp;
		temp.x = this->x - rhs.x;
		temp.y = this->y - rhs.y;
		return temp;
	}
	Point operator+(const Point& rhs){
		Point temp;
		temp.x = this->x + rhs.x;
		temp.y = this->y + rhs.y;
		return temp;
	}
	Point operator*(double p){
		Point temp;
		temp.x = this->x * p;
		temp.y = this->y * p;
		return temp;
	}
};    // 點的資料結構

bool operator==(const Point& lhs, const Point& rhs){
	if(lhs.x == rhs.x && lhs.y == rhs.y)
		return true;
	else
		return false;
}
bool operator!=(const Point& lhs, const Point &rhs){
	return !(lhs == rhs);
}

// 用於特殊情形。例如交點不存在，或者交點有無限多個。
Point INF(1e9, 1e9);
 
double cross(Point& a, Point& b)
{
    return a.x * b.y - a.y * b.x;
}

Point intersection(Point& p1, Point& p2, Point& p3, Point& p4)
{
    Point p12 = p2 - p1, p13 = p3 - p1, p34 = p4 - p3;
    double c1 = cross(p13, p34), c2 = cross(p12, p34);
    Point p31 = p1 - p3;
    double c3 = cross(p31, p12), c4 = cross(p34, p12);

    if (c2 < 0) c1 = -c1, c2 = -c2; // 調整一下正負號，方便判斷
    if (c4 < 0) c3 = -c3, c4 = -c4;

    if (c2 == 0){
        if (c1 == 0){
			printf("LINE\n");
            return INF;
		}else{
			printf("NONE\n");
            return INF;
		}
	}else{
			Point cross = p1 + (p12 * (c1 / c2));
			printf("POINT %.2lf %.2lf\n", cross.x, cross.y);
            return cross;
	}
}

int main(){
	int n;
	scanf("%d", &n);
	printf("INTERSECTING LINES OUTPUT\n");
	while(n--){
		Point lb, le;
		Point rb, re;
		scanf("%lf %lf %lf %lf", &lb.x, &lb.y, &le.x, &le.y);
		scanf("%lf %lf %lf %lf", &rb.x, &rb.y, &re.x, &re.y);
		intersection(lb, le, rb, re);
	}
	printf("END OF OUTPUT\n");
}
