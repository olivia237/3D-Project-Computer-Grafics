#pragma once
#include "Lib.h"
#include <string>

// View setup
struct
{
	vec4 position;
	vec4 target;
	vec4 upVector;
	vec4 direction;
} ViewSetup;

// Perspective setup
struct
{
	float fovY;
	float aspect;
	float near_plane;
	float far_plane;
} PerspectiveSetup;

struct Character
{
	unsigned int TextureID; // ID handle of the glyph texture
	ivec2 Size;				// Size of glyph
	ivec2 Bearing;			// Offset from baseline to left/top of glyph
	unsigned int Advance;	// Horizontal offset to advance to next glyph
};

// Shader values
typedef struct
{
	string name;
	int value;
} Shader;

// Point light values
typedef struct
{
	vec3 position;
	vec3 color;
	GLfloat power;
} point_light;

// Shading data
typedef struct
{
	GLuint light_position_pointer;
	GLuint light_color_pointer;
	GLuint light_power_pointer;
	GLuint material_diffuse;
	GLuint material_ambient;
	GLuint material_specular;
	GLuint material_shininess;
} LightShaderUniform;

// Object materials
typedef enum
{
	RED_PLASTIC,
	EMERALD,
	BRASS,
	SNOW_WHITE,
	YELLOW,
	ROSA,
	MARRONE,
	NO_MATERIAL
} MaterialType;

// Shading options
typedef enum
{
	NONE,
	PHONG_SHADING_INTERPOLATIVO,
	PHONG_SHADING,
	ONDE_SHADING,
	BANDIERA_SHADING
} ShaderOption;

// Materials values
typedef struct
{
	string name;
	vec3 ambient;
	vec3 diffuse;
	vec3 specular;
	GLfloat shininess;
} Material;

// Shading types value
typedef enum
{
	GOURAUD,
	PHONG,
	BLINN,
	TOON,
	PASS_THROUGH,
	WAVE
} ShadingType;

// Mesh geometry data
typedef struct
{
	vec3 boundingBoxMax;
	vec3 boundingBoxMin;
	vector<vec3> vertici;
	vector<vec4> colori;
	vector<GLuint> indici;
	vector<vec3> normali;
	vector<vec2> texCoords;
	mat4 ModelM;
	int sceltaVS;
	int sceltaFS;
	GLuint VAO;
	GLuint VBO_G;
	GLuint VBO_C;
	GLuint VBO_normali;
	GLuint EBO_indici;
	GLuint VBO_coord_texture;
	ShadingType shading;
	MaterialType material;
	string nome;
	vec4 ancora_obj;
	vec4 ancora_world;
} Mesh;

// Mesh object data
typedef struct
{
	vec3 boundingBoxMax;
	vec3 boundingBoxMin;
	vector<vec3> vertici;
	vector<vec4> colori;
	vector<GLuint> indici;
	vector<vec3> normali;
	vector<vec2> texCoords;
	mat4 ModelM;
	int sceltaVS;
	int sceltaFS;
	GLuint VAO;
	GLuint VBO_G;
	GLuint VBO_C;
	GLuint VBO_normali;
	GLuint EBO_indici;
	GLuint VBO_coord_texture;
	ShadingType shading;
	Material materiale;
	string nome;
	vec4 ancora_obj;
	vec4 ancora_world;
} MeshObj;

static vector<Mesh> Scena;
