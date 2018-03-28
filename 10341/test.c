#include <stdio.h>
#include <math.h>

double p, q, r, s, t, u;

double f(double x){
	return p * exp(-x) + q * sin(x) + r * cos(x) + s * tan(x) + t * x * x + u;
}

int main(){
	while(scanf("%lf %lf %lf %lf %lf %lf", &p, &q, &r, &s, &t, &u) != EOF){
		double left = 0, right = 1, middle;
		while(right - left < 0.00001){
			middle = (left + right) / 2;
			if(f(middle) > 0){
				left = middle;
			}else{
				right = middle;
			}
		}
		printf("[%lf]\n", middle);
		if(middle == 0 || middle == 1){
			printf("No solution\n");
			continue;
		}
		printf("%lf", middle);
	}
}
