#include <cstdio>
#include <iostream>

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
    double c3 = cross(p13, p12);

    if (c2 < 0) c1 = -c1, c2 = -c2, c3 = -c3;

    if (c2 != 0 && c1 >= 0 && c1 <= c2 && c3 >= 0 && c3 <= c2)
        return p1 + (p12 * (c1 / c2));
    else
        return INF;
}

int main(){
	int n;
	scanf("%d", &n);
	while(n--){
		Point lb, le;
		Point rb, re;
		scanf("%lf %lf %lf %lf", &lb.x, &lb.y, &le.x, &le.y);
		scanf("%lf %lf %lf %lf", &rb.x, &rb.y, &re.x, &re.y);
		bool ans = false;
		if(rb.x > re.x){
			double temp = rb.x;
			rb.x = re.x;
			re.x = temp;
		}
		if(rb.y < re.y){
			double temp = rb.y;
			rb.y = re.y;
			re.y = temp;
		}
		if(lb.x >= rb.x && lb.x <= re.x && lb.y <= rb.y && lb.y >= re.y){
			ans = true;
		}else if(le.x >= rb.x && le.x <= re.x && le.y <= rb.y && le.y >= re.y){
			ans = true;
		}
		if(ans == false){
			Point e1 = {re.x, rb.y};
			Point e2 = {rb.x, re.y};
			ans = (intersection(lb, le, rb, e1) != INF) || (intersection(lb, le, e1, re) != INF) || (intersection(lb, le, re, e2) != INF) || (intersection(lb, le, e2, rb) != INF);
		}
		printf(ans ? "T\n" : "F\n");
	}
}
