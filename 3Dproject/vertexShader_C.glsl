#version 330 core
layout (location = 0) in vec3 aPos;   // the position variable has attribute position 0
layout (location = 1) in vec4 aColor; // the color variable has attribute position 1
layout (location = 2) in vec3 vertexNormal; // Attributo Normale 2
layout (location = 3) in vec2 coord_st; // Attributo texture

uniform mat4 Model;
uniform mat4 Projection;
uniform mat4 View;
uniform int sceltaVS;
uniform float time;
uniform vec3 viewPos;

//Struttura per la gestione di un punto luce
struct PointLight
{
    vec3 position;
    vec3 color;
    float power;
};

float strenght=0.1;
//definizione di una variabile uniform che ha la struttura PointLight
uniform PointLight light;

//Struttura per la gestione di un materiale
struct Material 
{
    vec3 ambient;
    vec3 diffuse;
    vec3 specular;
    float shininess;
};

uniform Material material;
out vec2  frag_coord_st;
// output a color to the fragment shader
out vec4 ourColor;      
out vec3 N, V, L, R, H;
 
void main()
{
    // set ourColor to the input color we got from the vertex data
    ourColor = aColor;     
     
    if (sceltaVS == 0)
    {
        gl_Position = Projection * View * Model * vec4(aPos, 1.0); 
    }
    if (sceltaVS == 1)
    {
        //Modello di illuminazione di  Phong con shading interpolativo
        gl_Position = Projection * View * Model * vec4(aPos, 1.0);

        //Trasformare le coordinate del vertice da elaborare (aPos) in coordinate di vista
        vec4 eyePosition= View*Model*vec4(aPos,1.0);

        //Trasformiamo la posizione della luce nelle coordinate di vista

        vec4 eyeLightPos= View * vec4(light.position, 1.0);

        //trasformare le normali nel vertice in esame nel sistema di coordinate di vista
        mat3 G = mat3(transpose(inverse(View * Model)));
        N = normalize(G * vertexNormal);      
        
        //Calcoliamo la direzione della luce L, la direzione riflessione R e di vista
        V = normalize(viewPos - eyePosition.xyz);
        L = normalize((eyeLightPos - eyePosition).xyz);
        // Costruisce la direzione riflessa di L rispesso alla normale
        R = reflect(-L, N);  

        //ambientale
        vec3 ambient = strenght * light.power * material.ambient;

        //diffuse
        float coseno_angolo_theta= max(dot(L, N), 0);
        vec3 diffuse = light.power * light.color * coseno_angolo_theta * material.diffuse;

        //speculare
        float coseno_angolo_alfa = pow(max(dot(V, R), 0), material.shininess);
        vec3 specular = light.power * light.color * coseno_angolo_alfa * material.specular;

        ourColor = vec4(ambient + diffuse + specular, 1.0);   
        frag_coord_st = coord_st;   
    }
    if (sceltaVS == 2)
    {        
        //Modello di illuminazione di Blinn-Phong con shading interpolativo
        gl_Position = Projection * View * Model * vec4(aPos, 1.0);

        //Trasformare le coordinate del vertice da elaborare (aPos) in coordinate di vista
        vec4 eyePosition = View * Model * vec4(aPos, 1.0);

        //Trasformia la posizione della luce nelle coordinate di vista
        vec4 eyeLightPos = View * vec4(light.position, 1.0);

        //trasformare le normali nel vertice in esame nel sistema di coordinate di vista
        mat3 G = mat3(transpose(inverse(View * Model)));
        N = normalize(G * vertexNormal);

        //Calcoliamo la direzione della luce L, la direzione riflessione R e di vista
        V = normalize(viewPos - eyePosition.xyz);
        L = normalize((eyeLightPos - eyePosition).xyz);
             
        //Costruisce il vettore H a met� tra direzione di luce e di vista
        H = normalize(L + V);
        //ambientale
        vec3 ambient = strenght * light.power * material.ambient;

        //diffuse
        float coseno_angolo_theta= max(dot(L,N), 0);
        vec3 diffuse = light.power * light.color * coseno_angolo_theta * material.diffuse;

        //speculare BLINN
        float coseno_angolo_beta = pow(max(dot(N, H), 0), material.shininess);
        vec3 specular = light.power * light.color * coseno_angolo_beta * material.specular;

        ourColor = vec4(ambient + diffuse + specular, 1.0);
        frag_coord_st = coord_st;  
    }
    if (sceltaVS == 3)
    {
        //Modello di illuminazione di Phong con shading di Phong
        gl_Position = Projection * View * Model * vec4(aPos, 1.0);

        //Trasformare le coordinate del vertice da elaborare (aPos) in coordinate di vista
        vec4 eyePosition = View * Model * vec4(aPos, 1.0);

        //Trasformiamo la posizione della luce nelle coordinate di vista
        vec4 eyeLightPos = View * vec4(light.position, 1.0);

        //trasformare le normali nel vertice in esame nel sistema di coordinate di vista
        mat3 G = mat3(transpose(inverse(View * Model)));
        N = normalize(G * vertexNormal);     
    
        //Calcoliamo la direzione della luce L, la direzione riflessione R e di vista
        V = normalize(viewPos - eyePosition.xyz);
        L = normalize((eyeLightPos - eyePosition).xyz);
        //Costruisce la direzione riflessa di L rispesso alla normale
        R = reflect(-L,N); 

        frag_coord_st = coord_st;
    }
    if (sceltaVS == 4)
    {
        //Shader  tipo cartoon
        gl_Position = Projection*View*Model*vec4(aPos, 1.0);

        //Trasformare le coordinate del vertice da elaborare (aPos) in coordinate di vista
        vec4 eyePosition = View * Model * vec4(aPos, 1.0);
        vec4 eyeLightPos = View * vec4(light.position, 1.0);
        L = normalize((eyeLightPos - eyePosition).xyz);
        mat3 G = mat3(transpose(inverse(View * Model)));
        N = normalize(G * vertexNormal);     

        float intensity = normalize(dot(L, N));

        if (intensity > 0.95)
        {
            ourColor  = vec4(0.5, 1.0, 0.5, 1.0);
        }
        else if (intensity > 0.5)
        {
            ourColor  = vec4(0.3, 0.8, 0.3, 1.0);
        }
        else if (intensity > 0.25)
        {
            ourColor  = vec4(0.1, 0.4, 0.1, 1.0);
        }
        else
        {
            ourColor  = vec4(0.0, 0.2, 0.0, 1.0);
        }

        frag_coord_st = coord_st;
    }     
}  

