#version 330 core
#define pi 3.14159235659
in vec4 ourColor;
out vec4 FragColor;  

in vec3 N, L, R, V, H;
uniform float time;
uniform vec2 resolution;
uniform int sceltaFS;
float strenght = 0.1;
struct PointLight
{
	vec3 position;
	vec3 color;
	float power;
};

//definizione di una varialie uniform che ha la struttura PointLight
uniform PointLight light;
struct Material 
{
    vec3 ambient;
    vec3 diffuse;
    vec3 specular;
    float shininess;
}; 

uniform Material material;
uniform sampler2D id_tex;
in vec2 frag_coord_st;
 
void main()
{
    if(sceltaFS == 0 || sceltaFS == 1 ||sceltaFS == 2 ||sceltaFS == 4)
    {
        //Shading interpolativo
        FragColor = mix(ourColor, texture(id_tex, vec2(frag_coord_st.x, frag_coord_st.y)), 0.3);
    }         
    else if (sceltaFS == 3)
    {
        //Shading di Phong per modello di illuminazione di Phong
        vec3 ambient = strenght * light.power * material.ambient;

        //diffuse
        float coseno_angolo_theta = max(dot(L, N), 0);
        vec3 diffuse = light.power * light.color * coseno_angolo_theta * material.diffuse;

        //speculare
        float coseno_angolo_alfa = pow(max(dot(V, R), 0), material.shininess);
        vec3 specular = light.power * light.color * coseno_angolo_alfa * material.specular;

        FragColor = vec4(ambient + diffuse + specular, 1.0);      
        FragColor = mix(FragColor, texture(id_tex, vec2(frag_coord_st.x, frag_coord_st.y)), 0.3);
    } 
    else if (sceltaFS == 5)
	{
        FragColor=ourColor;
    }
    else if (sceltaFS == 6)
	{
        //Shading di Phong per modello di illuminazione di Phong senza texturing da usare per mesh obj
        vec3 ambient = strenght * light.power * material.ambient;

        //diffuse
        float coseno_angolo_theta = max(dot(L, N), 0);
        vec3 diffuse = light.power * light.color * coseno_angolo_theta * material.diffuse;

        //speculare
        float coseno_angolo_alfa = pow(max(dot(V, R), 0), material.shininess);
        vec3 specular = light.power * light.color * coseno_angolo_alfa * material.specular;

        FragColor = vec4(ambient + diffuse + specular, 1.0);      

    } 
}