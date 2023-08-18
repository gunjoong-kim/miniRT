#ifndef VEC3_H
# define VEC3_H

# include "minirt.h"

typedef struct s_vec3
{
	double	x;
	double	y;
	double	z;
}	t_vec3;

typedef t_vec3	t_point3;
typedef t_vec3	t_color;

double	vec3_length(t_vec3 *v); //벡터의 길이 구하는 함수
double	vec3_squared(t_vec3 *v); //벡터 거리 제곱
t_vec3	vec3_random(void); //random vec3
bool	vec3_near_zero(t_vec3 *v); //vec3가 0vector인지
void	vec3_print(t_vec3 *v); //print vec3
t_vec3	vec3_add(t_vec3 *left, t_vec3 *right); //left + right의 대한 값 반환
t_vec3	vec3_minus(t_vec3 *left, t_vec3 *right); //left - right의 대한 값 반환
t_vec3	vec3_mul_vec3(t_vec3 *left, t_vec3 *right); //left * right의 대한 값 반환
t_vec3	vec3_mul_scalar(t_vec3 *left, double right); //left * scalar의 대한 값 반환
double	vec3_dot(t_vec3 *left, t_vec3 *right); // dot product
t_vec3	vec3_cross(t_vec3 *left, t_vec3 *right); // cross product
t_vec3	vec3_unit(t_vec3 *v); //make unit vector from v
t_vec3	vec3_random_in_unit_sphere(void); //return vector in unitsphere
t_vec3	vec3_random_unit(void); //return random unit vector
t_vec3	vec3_reflect(t_vec3 *v, t_vec3 *n); //return reflect vector
t_vec3	vec3_refract(t_vec3 *uv, t_vec3 *n, double etai_over_etat);

#endif