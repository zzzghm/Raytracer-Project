#version 150
// Referece: http://www-cs.engr.ccny.cuny.edu/~wolberg/cs472/pdf/CSc472-12-ShadingOpenGL.pdf
uniform vec4 AmbientProduct;
uniform vec4 DiffuseProduct;
uniform vec4 SpecularProduct;
uniform vec4 LightPosition;
uniform float Shininess;

in vec4 pos;
in vec4 N;


out vec4 fragColor;

void main()
{
  // normal
  vec4 N=normalize(N);
  // eye-position to position, eye-position=(0,0,0,1)
  vec4 V=normalize(-pos);
  // light-position to position
  vec4 L=normalize(LightPosition-pos);
  // reflection
  vec4 R=normalize(2*N*dot(N,L)-L);

  // Ambient
  vec4 ambient = AmbientProduct;
  
  // Diffuse
 
  float D=max(dot(L,N),0.0);
  vec4  diffuse = D * DiffuseProduct;
  
  //Specular

  //blinn-phong
  //vec4 H=normalize(L+V);
  //float S=pow(max(dot(N,H),0.0),Shininess);
  //if(dot(L,N)<0.0){
  //specular=vec4(0,0,0,1);}

  // phong
  float S=pow(max(dot(V,R),0.0),Shininess);
  vec4  specular = S * SpecularProduct;
  


  fragColor = ambient + diffuse + specular;
}

