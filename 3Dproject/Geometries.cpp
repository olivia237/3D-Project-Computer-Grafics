#include "Geometries.h"

void crea_cubo(Mesh *mesh)
{
	mesh->vertici.push_back(vec3(-1.0, -1.0, 1.0));
	mesh->colori.push_back(vec4(1.0, 0.0, 0.0, 0.5));
	mesh->vertici.push_back(vec3(1.0, -1.0, 1.0));
	mesh->colori.push_back(vec4(0.0, 1.0, 0.0, 0.5));
	mesh->vertici.push_back(vec3(1.0, 1.0, 1.0));
	mesh->colori.push_back(vec4(0.0, 0.0, 1.0, 0.5));
	mesh->vertici.push_back(vec3(-1.0, 1.0, 1.0));
	mesh->colori.push_back(vec4(1.0, 0.0, 1.0, 0.5));
	// back
	mesh->vertici.push_back(vec3(-1.0, -1.0, -1.0));
	mesh->colori.push_back(vec4(1.0, 1.0, 1.0, 0.5));
	mesh->vertici.push_back(vec3(1.0, -1.0, -1.0));
	mesh->colori.push_back(vec4(1.0, 1.0, 1.0, 0.5));
	mesh->vertici.push_back(vec3(1.0, 1.0, -1.0));
	mesh->colori.push_back(vec4(1.0, 1.0, 1.0, 0.5));
	mesh->vertici.push_back(vec3(-1.0, 1.0, -1.0));
	mesh->colori.push_back(vec4(1.0, 1.0, 1.0, 0.5));

	mesh->vertici.push_back(vec3(0.0, 0.0, 0.0));
	mesh->colori.push_back(vec4(0.0, 1.0, 0.0, 1.0));
	mesh->ancora_obj = (vec4(0.0, 0.0, 0.0, 1.0));

	mesh->indici.push_back(0);
	mesh->indici.push_back(1);
	mesh->indici.push_back(2);

	mesh->indici.push_back(2);
	mesh->indici.push_back(3);
	mesh->indici.push_back(0);

	mesh->indici.push_back(1);
	mesh->indici.push_back(5);
	mesh->indici.push_back(6);

	mesh->indici.push_back(6);
	mesh->indici.push_back(2);
	mesh->indici.push_back(1);

	mesh->indici.push_back(7);
	mesh->indici.push_back(6);
	mesh->indici.push_back(5);

	mesh->indici.push_back(5);
	mesh->indici.push_back(4);
	mesh->indici.push_back(7);

	mesh->indici.push_back(4);
	mesh->indici.push_back(0);
	mesh->indici.push_back(3);

	mesh->indici.push_back(3);
	mesh->indici.push_back(7);
	mesh->indici.push_back(4);

	mesh->indici.push_back(4);
	mesh->indici.push_back(5);
	mesh->indici.push_back(1);

	mesh->indici.push_back(1);
	mesh->indici.push_back(0);
	mesh->indici.push_back(4);

	mesh->indici.push_back(3);
	mesh->indici.push_back(2);
	mesh->indici.push_back(6);

	mesh->indici.push_back(6);
	mesh->indici.push_back(7);
	mesh->indici.push_back(3);

	mesh->normali.push_back(normalize(vec3(0, 0, 1)));
	mesh->normali.push_back(normalize(vec3(0, 0, 1)));
	mesh->normali.push_back(normalize(vec3(0, 0, 1)));
	mesh->normali.push_back(normalize(vec3(0, 0, 1)));
	mesh->normali.push_back(normalize(vec3(0, 0, -1)));
	mesh->normali.push_back(normalize(vec3(0, 0, -1)));
	mesh->normali.push_back(normalize(vec3(0, 0, -1)));
	mesh->normali.push_back(normalize(vec3(0, 0, -1)));

	int nv = mesh->vertici.size();
	mesh->indici.push_back(nv - 1);

	mesh->boundingBoxMax = TrovaMax(mesh);
	mesh->boundingBoxMin = TrovaMin(mesh);
}

void crea_piramide(Mesh *mesh)
{
	mesh->vertici.push_back(vec3(-1.0, 0.0, 1.0));
	mesh->colori.push_back(vec4(1.0, 0.0, 0.0, 0.5));
	mesh->vertici.push_back(vec3(1.0, 0.0, 1.0));
	mesh->colori.push_back(vec4(0.0, 1.0, 0.0, 0.5));
	mesh->vertici.push_back(vec3(1.0, 0.0, -1.0));
	mesh->colori.push_back(vec4(0.0, 0.0, 1.0, 0.5));
	mesh->vertici.push_back(vec3(-1.0, 0.0, -1.0));
	mesh->colori.push_back(vec4(1.0, 1.0, 0.0, 0.5));
	// Apice piramide
	mesh->vertici.push_back(vec3(0.0, 1.0, 0.0));
	mesh->colori.push_back(vec4(1.0, 1.0, 1.0, 1.0));

	for (int i = 0; i < mesh->vertici.size(); i++)
	{
		mesh->normali.push_back(vec3(0.0));
	}

	mesh->indici.push_back(0);
	mesh->indici.push_back(1);
	mesh->indici.push_back(2);

	mesh->indici.push_back(0);
	mesh->indici.push_back(2);
	mesh->indici.push_back(3);

	mesh->indici.push_back(0);
	mesh->indici.push_back(4);
	mesh->indici.push_back(3);

	mesh->indici.push_back(0);
	mesh->indici.push_back(1);
	mesh->indici.push_back(4);

	mesh->indici.push_back(3);
	mesh->indici.push_back(2);
	mesh->indici.push_back(4);

	mesh->indici.push_back(1);
	mesh->indici.push_back(2);
	mesh->indici.push_back(4);

	mesh->vertici.push_back(vec3(0.0, 0.3, 0.0));
	mesh->colori.push_back(vec4(0.0, 1.0, 0.0, 1.0));
	mesh->ancora_obj = (vec4(0.0, 0.3, 0.0, 1.0));

	int nv = mesh->vertici.size();
	mesh->indici.push_back(nv - 1);

	mesh->boundingBoxMax = TrovaMax(mesh);
	mesh->boundingBoxMin = TrovaMin(mesh);
}

void crea_piano(Mesh *mesh, vec4 color)
{
	mesh->vertici.push_back(vec3(-0.5, 0.0, 0.5));
	mesh->colori.push_back(color);
	mesh->vertici.push_back(vec3(0.5, 0.0, 0.5));
	mesh->colori.push_back(color);
	mesh->vertici.push_back(vec3(0.5, 0.0, -0.5));
	mesh->colori.push_back(color);
	mesh->vertici.push_back(vec3(-0.5, 0.0, -0.5));
	mesh->colori.push_back(color);

	mesh->indici.push_back(0);
	mesh->indici.push_back(1);
	mesh->indici.push_back(2);

	mesh->indici.push_back(0);
	mesh->indici.push_back(2);
	mesh->indici.push_back(3);

	mesh->normali.push_back(vec3(0.0, 1.0, 0.0));
	mesh->normali.push_back(vec3(0.0, 1.0, 0.0));
	mesh->normali.push_back(vec3(0.0, 1.0, 0.0));
	mesh->normali.push_back(vec3(0.0, 1.0, 0.0));

	mesh->texCoords.push_back(vec2(0.0, 1.0));
	mesh->texCoords.push_back(vec2(1.0, 1.0));
	mesh->texCoords.push_back(vec2(1.0, 0.0));
	mesh->texCoords.push_back(vec2(0.0, 0.0));

	mesh->vertici.push_back(vec3(0.0, 0.0, 0.0));
	mesh->colori.push_back(vec4(1.0, 0.0, 0.0, 1.0));
	mesh->ancora_obj = (vec4(0.0, 0.0, 0.0, 1.0));

	int nv = mesh->vertici.size();
	mesh->indici.push_back(nv - 1);

	mesh->boundingBoxMax = TrovaMax(mesh);
	mesh->boundingBoxMin = TrovaMin(mesh);
}

void crea_piano_suddiviso(Mesh *mesh, vec4 color)
{
	int N = 32;
	int i, j;

	for (i = 0; i < N; i++)
	{
		for (j = 0; j < N; j++)
		{
			mesh->vertici.push_back(vec3(-0.5 + (float)i / N, 0.0, -0.5 + (float)j / N));
			mesh->colori.push_back(color);
			mesh->normali.push_back(vec3(0.0, 1.0, 0.0));
		}
	}

	int cont = -1;

	for (i = 0; i <= pow(N, 2) - (N + 1); i++)
	{
		j = i % (N);

		if (j != N - 1)
		{
			mesh->indici.push_back(i);
			mesh->indici.push_back(i + 1);
			mesh->indici.push_back(i + N);

			mesh->indici.push_back(i + N + 1);
			mesh->indici.push_back(i + 1);
			mesh->indici.push_back(i + N);
		}
	}

	mesh->vertici.push_back(vec3(0.0, 0.0, 0.0));
	mesh->ancora_obj = (vec4(0.0, 0.0, 0.0, 1.0));
	mesh->colori.push_back(vec4(0.0, 1.0, 0.0, 1.0));

	int nv = mesh->vertici.size();
	mesh->indici.push_back(nv - 1);

	mesh->boundingBoxMax = TrovaMax(mesh);
	mesh->boundingBoxMin = TrovaMin(mesh);
}

void crea_sfera(Mesh *mesh, vec4 colore)
{
	vec3 centro = vec3(0.0, 0.0, 0.0);
	vec3 raggio = vec3(1.0, 1.0, 1.0);

	
	float s, t;
	// Numero di suddivisioni sull'asse y
	int Stacks = 100;
	// Numero di suddivisioni sull'asse x
	int Slices = 100;

	// Stacks= suddivisioni lungo l'asse y
	for (int i = 0; i <= Stacks; ++i)
	{
		float V = i / (float)Stacks;
		float phi = V * pi<float>();

		// Loop Through Slices suddivisioni lungo l'asse x
		for (int j = 0; j <= Slices; ++j)
		{
			float U = j / (float)Slices;
			float theta = U * (pi<float>() * 2);

			// Calc The Vertex Positions
			float x = centro.x + raggio.x * (cosf(theta) * sinf(phi));
			float y = centro.y + raggio.y * cosf(phi);
			float z = centro.z + raggio.z * sinf(theta) * sinf(phi);

			mesh->vertici.push_back(vec3(x, y, z)),
			mesh->colori.push_back(colore);

			// Normale nel vertice
			mesh->normali.push_back(vec3(x, y, z));
			// coordinata di Texture
			s = U;
			t = V;

			mesh->texCoords.push_back(vec2(s, t));
		}
	}

	// Calc The Index Positions
	for (int i = 0; i < Slices * Stacks + Slices; ++i)
	{
		mesh->indici.push_back(i);
		mesh->indici.push_back(i + Slices + 1);
		mesh->indici.push_back(i + Slices);

		mesh->indici.push_back(i + Slices + 1);
		mesh->indici.push_back(i);
		mesh->indici.push_back(i + 1);
	}

	mesh->vertici.push_back(vec3(0.0, 0.0, 0.0));
	mesh->colori.push_back(vec4(0.0, 1.0, 0.0, 1.0));
	mesh->ancora_obj = (vec4(0.0, 0.0, 0.0, 1.0));

	int nv = mesh->vertici.size();
	mesh->indici.push_back(nv - 1);

	mesh->boundingBoxMax = TrovaMax(mesh);
	mesh->boundingBoxMin = TrovaMin(mesh);
}

void crea_toro(Mesh *mesh, vec4 colore)
{
	// numero di suddivisioni sull'asse x
	int Stacks = 30;

	// numero di suddivisioni sull'asse y
	int Slices = 30;

	float R = 1, r = 0.5;
	float s, t;

	// Calc The Vertices
	for (int i = 0; i <= Stacks; ++i)
	{
		float V = i / (float)Stacks;
		float phi = V * glm::pi<float>() * 2;

		// Loop Through Slices
		for (int j = 0; j <= Slices; ++j)
		{
			float U = j / (float)Slices;
			float theta = U * (glm::pi<float>() * 2);

			// Calc The Vertex Positions
			float x = (R + r * cosf(phi)) * cosf(theta);
			float y = r * sinf(phi);
			float z = (R + r * cosf(phi)) * sinf(theta);

			// Push Back Vertex Data
			mesh->vertici.push_back(vec3(x, y, z));
			mesh->colori.push_back(colore);
			// Normale nel vertice
			mesh->normali.push_back(vec3(normalize(vec3(sin(phi) * cos(theta), cos(phi), sin(theta) * sin(phi)))));

			// Coordinata di Texture
			s = U;
			t = V;

			mesh->texCoords.push_back(vec2(s, t));
		}
	}

	// Calc The Index Positions
	for (int i = 0; i < Slices * Stacks + Slices; ++i)
	{
		mesh->indici.push_back(i);
		mesh->indici.push_back(i + Slices + 1);
		mesh->indici.push_back(i + Slices);

		mesh->indici.push_back(i + Slices + 1);
		mesh->indici.push_back(i);
		mesh->indici.push_back(i + 1);
	}

	mesh->ancora_obj = (vec4(0.0, 0.0, 0.0, 1.0));

	mesh->boundingBoxMax = TrovaMax(mesh);
	mesh->boundingBoxMin = TrovaMin(mesh);
}

void crea_cono(Mesh *mesh, vec4 colore)
{
	int Stacks = 30; // numero di suddivisioni sull'asse x
	int Slices = 30; // numero di suddivisioni sull'asse y
	float s, t;

	// Calc The Vertices
	for (int i = 0; i <= Stacks; ++i)
	{
		float V = i / (float)Stacks;
		float h = V;

		// Loop Through Slices
		for (int j = 0; j <= Slices; ++j)
		{
			float U = j / (float)Slices;
			float theta = U * (glm::pi<float>() * 2);

			// Calc The Vertex Positions
			float x = h * cosf(theta);
			float y = h;
			float z = h * sinf(theta);

			// Push Back Vertex Data
			mesh->vertici.push_back(vec3(x, y, z));
			mesh->colori.push_back(colore);
			// Normale nel vertice
			mesh->normali.push_back(normalize(vec3(cos(theta) / sqrt(2.0f), -1 / sqrt(2.0f), sin(theta) / sqrt(2.0f))));

			// coordinata di texture
			s = U;
			t = V;

			mesh->texCoords.push_back(vec2(s, t));
		}
		mesh->boundingBoxMax = TrovaMax(mesh);
		mesh->boundingBoxMin = TrovaMin(mesh);

	}

	// Calc The Index Positions
	for (int i = 0; i < Slices * Stacks + Slices; ++i)
	{
		mesh->indici.push_back(i);
		mesh->indici.push_back(i + Slices + 1);
		mesh->indici.push_back(i + Slices);

		mesh->indici.push_back(i + Slices + 1);
		mesh->indici.push_back(i);
		mesh->indici.push_back(i + 1);
	}
	
	mesh->ancora_obj = (vec4(0.0, 0.0, 0.0, 1.0));
}

void crea_cilindro(Mesh *mesh, vec4 colore)
{
	// numero di suddivisioni sull'asse x
	int Stacks = 30;
	// numero di suddivisioni sull'asse y
	int Slices = 30;
	float s, t;

	// Calc The Vertices
	for (int i = 0; i <= Stacks; ++i)
	{
		float V = i / (float)Stacks;
		float h = V;

		// Loop Through Slices
		for (int j = 0; j <= Slices; ++j)
		{
			float U = j / (float)Slices;
			float theta = U * (glm::pi<float>() * 2);

			// Calc The Vertex Positions
			float x = cosf(theta);
			float y = h;
			float z = sinf(theta);

			// Push Back Vertex Data
			mesh->vertici.push_back(vec3(x, y, z));
			mesh->colori.push_back(colore);

			// Normale nel vertice
			mesh->normali.push_back(vec3(normalize(vec3(cos(theta), 0, sin(theta)))));

			// Coordinata di texture
			s = U;
			t = V;

			mesh->texCoords.push_back(vec2(s, t));
		}
	}

	// Calc The Index Positions
	for (int i = 0; i < Slices * Stacks + Slices; ++i)
	{
		mesh->indici.push_back(i);
		mesh->indici.push_back(i + Slices + 1);
		mesh->indici.push_back(i + Slices);

		mesh->indici.push_back(i + Slices + 1);
		mesh->indici.push_back(i);
		mesh->indici.push_back(i + 1);
	}

	mesh->ancora_obj = (vec4(0.0, 0.0, 0.0, 1.0));
	mesh->boundingBoxMax = TrovaMax(mesh);
	mesh->boundingBoxMin = TrovaMin(mesh);
}

void crea_casa(Mesh *mesh, vec4 coloret, vec4 coloreb)
{
	mesh->vertici.push_back(vec3(2, -1, 2));
	mesh->colori.push_back(coloret);
	mesh->vertici.push_back(vec3(2, -1, -2));
	mesh->colori.push_back(coloreb);
	mesh->vertici.push_back(vec3(2, 1, -2));
	mesh->colori.push_back(coloret);
	mesh->vertici.push_back(vec3(2, 1, 2));
	mesh->colori.push_back(coloreb);
	mesh->vertici.push_back(vec3(1.5, 3.5, 0));
	mesh->colori.push_back(coloret);
	mesh->vertici.push_back(vec3(-1.5, 3.5, 0));
	mesh->colori.push_back(coloreb);
	mesh->vertici.push_back(vec3(-2, -1, 2));
	mesh->colori.push_back(coloret);
	mesh->vertici.push_back(vec3(-2, 1, 2));
	mesh->colori.push_back(coloreb);
	mesh->vertici.push_back(vec3(-2, 1, -2));
	mesh->colori.push_back(coloret);
	mesh->vertici.push_back(vec3(-2, -1, -2));
	mesh->colori.push_back(coloreb);

	for (int i = 0; i < mesh->vertici.size(); i++)
	{
		mesh->normali.push_back(vec3(0.0));
	}

	mesh->indici.push_back(0);
	mesh->indici.push_back(1);
	mesh->indici.push_back(2);

	mesh->indici.push_back(2);
	mesh->indici.push_back(3);
	mesh->indici.push_back(0);

	mesh->indici.push_back(3);
	mesh->indici.push_back(2);
	mesh->indici.push_back(4);

	mesh->indici.push_back(7);
	mesh->indici.push_back(3);
	mesh->indici.push_back(4);

	mesh->indici.push_back(4);
	mesh->indici.push_back(5);
	mesh->indici.push_back(7);

	mesh->indici.push_back(2);
	mesh->indici.push_back(8);
	mesh->indici.push_back(5);

	mesh->indici.push_back(5);
	mesh->indici.push_back(4);
	mesh->indici.push_back(2);

	mesh->indici.push_back(5);
	mesh->indici.push_back(8);
	mesh->indici.push_back(7);

	mesh->indici.push_back(0);
	mesh->indici.push_back(3);
	mesh->indici.push_back(7);

	mesh->indici.push_back(7);
	mesh->indici.push_back(6);
	mesh->indici.push_back(0);

	mesh->indici.push_back(0);
	mesh->indici.push_back(6);
	mesh->indici.push_back(9);

	mesh->indici.push_back(9);
	mesh->indici.push_back(1);
	mesh->indici.push_back(0);

	mesh->indici.push_back(2);
	mesh->indici.push_back(1);
	mesh->indici.push_back(9);

	mesh->indici.push_back(9);
	mesh->indici.push_back(8);
	mesh->indici.push_back(2);

	mesh->indici.push_back(6);
	mesh->indici.push_back(7);
	mesh->indici.push_back(8);

	mesh->indici.push_back(8);
	mesh->indici.push_back(9);
	mesh->indici.push_back(6);

	mesh->ancora_obj = (vec4(0.0, 0.0, 0.0, 1.0));

	mesh->boundingBoxMax = TrovaMax(mesh);
	mesh->boundingBoxMin = TrovaMin(mesh);
}
