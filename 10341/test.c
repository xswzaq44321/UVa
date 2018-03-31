#include <stdio.h>
#include <math.h>

double p, q, r, s, t, u;

double f(double x){
	return p * exp(-x) + q * sin(x) + r * cos(x) + s * tan(x) + t * x * x + u;
}

int main(){
	while(scanf("%lf %lf %lf %lf %lf %lf", &p, &q, &r, &s, &t, &u) != EOF){
		double left = 0, right = 1, middle;
		while(right - left > 1e-9){
			middle = (left + right) / 2;
			if(f(middle) > 0){
				left = middle;
			}else{
				right = middle;
			}
		}
		fprintf(stderr, "[%lf]\n", f(middle));
		if(fabs(f(middle)) > 1e-4){
			printf("No solution\n");
			continue;
		}
		printf("%.4lf\n", middle);
	}
}
