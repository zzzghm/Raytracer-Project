//////////////////////////////////////////////////////////////////////////////
//
//  --- Object.cpp ---
//  Created by Brian Summa
//
//////////////////////////////////////////////////////////////////////////////


#include "common.h"

/* -------------------------------------------------------------------------- */
/* -------------------------------------------------------------------------- */
Object::IntersectionValues Sphere::intersect(vec4 p0_w, vec4 V_w){
	vec4 P_o;
	double t_o;
	vec4 N_o;
  IntersectionValues result;
  vec4 p0_o = INVC*p0_w;
  vec4 V_o = INVCStar*V_w;
  V_o = normalize(V_o);
  t_o = raySphereIntersection(p0_o,V_o);

  vec4 temp = INVC * V_w;
  result.t_w = t_o/length(temp);
  result.P_w = p0_w + result.t_w * V_w;

  P_o = p0_o + t_o * V_o;
  N_o = P_o;
  N_o.w = 0;
  result.N_w = TRANINVC * N_o;
  result.N_w.w = 0;
  return result;
}

/* -------------------------------------------------------------------------- */
/* ------ Ray = p0 + t*V  sphere at origin O and radius r    : Find t ------- */
double Sphere::raySphereIntersection(vec4 p0, vec4 V, vec4 O, double r){
  double t   = std::numeric_limits< double >::infinity();
  //TODO: Ray-sphere intersection;
  double a = 1;
  double b = 2*dot((V), (p0-O));
  double c = pow(length(p0-O),2)-pow(r,2);

  if (pow(b,2) - 4 * a*c < 0) {
	  return t;
  }
  if (pow(b,2) - 4 * a*c >= 0) {
	  double t1 = (-b + sqrt(pow(b,2) - 4 * a*c)) / (2 * a);
	  double t2 = (-b - sqrt(pow(b,2) - 4 * a*c)) / (2 * a);

	  if (t1 >= 0 && t2 >= 0)
	  {
		  t = min(t1, t2);
	  }
	  if (t1 > 0.001 && t2 <= 0.001) {
		  t = t1;
	  }
	  if (t1 <= 0.001 && t2 > 0.001) {
		  t = t2;
	  }
	  if (t1 < 0.001 && t2 < 0.001) {
		  t = std::numeric_limits< double >::infinity();
	  }
	  return t;
  }
}

/* -------------------------------------------------------------------------- */
/* -------------------------------------------------------------------------- */
Object::IntersectionValues Square::intersect(vec4 p0_w, vec4 V_w){

  //TODO: Ray-square setup
  vec4 P_o;
  double t_o;
  vec4 N_o;
  IntersectionValues result;
  vec4 p0_o = INVC * p0_w;
  vec4 V_o = INVCStar * V_w;
  V_o = normalize(V_o);
  t_o = raySquareIntersection(p0_o, V_o);

  vec4 temp = INVC * V_w;
  result.t_w = t_o / length(temp);
  result.P_w = p0_w + result.t_w * V_w;

  P_o = p0_o+t_o*V_o;
  N_o = vec4(0,0,1,0);
  
  result.N_w = TRANINVC*N_o;
  result.N_w.w = 0;


  return result;

}

/* -------------------------------------------------------------------------- */
/* -------------------------------------------------------------------------- */
double Square::raySquareIntersection(vec4 p0, vec4 V){
  double t   = std::numeric_limits< double >::infinity();
  //TODO: Ray-square intersection;
  // vector w term=0
  // point w term=1
  vec4 N =normalize( vec4(0,0,5,0));
  double temp = dot(N, (mesh.vertices[0]-p0)) / dot(N, V);
  vec4 P = p0 + temp * V;
 
  if (( P.x > -1.001) && (P.x < 1.001)&&(P.y > -1.001) && (P.y < 1.001)) {
	
      if (temp >= 0) {
	      t = temp;
      }
   }
 
  return t;
}
