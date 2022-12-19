#include "BoundingBox.h"

vec3 TrovaMax(Mesh* mesh)
{
	vec3 ris = mesh->vertici.at(0);
	
	for (int i = 0; i < mesh->vertici.size(); i++)
	{
		if (mesh->vertici.at(i).x > ris.x) {
			ris.x = mesh->vertici.at(i).x;
		}
		if (mesh->vertici.at(i).y > ris.y) {
			ris.y = mesh->vertici.at(i).y;
		}
		if (mesh->vertici.at(i).z > ris.z) {
			ris.z = mesh->vertici.at(i).z;
		}
	}
    return ris;
}

vec3 TrovaMin(Mesh* mesh)
{
	vec3 ris = mesh->vertici.at(0);

	for (int i = 0; i < mesh->vertici.size(); i++)
	{
		if (mesh->vertici.at(i).x < ris.x) {
			ris.x = mesh->vertici.at(i).x;
		}
		if (mesh->vertici.at(i).y < ris.y) {
			ris.y = mesh->vertici.at(i).y;
		}
		if (mesh->vertici.at(i).z < ris.z) {
			ris.z = mesh->vertici.at(i).z;
		}
	}
	return ris;
}

vec3 TrovaMax(MeshObj* mesh)
{
	vec3 ris = mesh->vertici.at(0);

	for (int i = 0; i < mesh->vertici.size(); i++)
	{
		if (mesh->vertici.at(i).x > ris.x) {
			ris.x = mesh->vertici.at(i).x;
		}
		if (mesh->vertici.at(i).y > ris.y) {
			ris.y = mesh->vertici.at(i).y;
		}
		if (mesh->vertici.at(i).z > ris.z) {
			ris.z = mesh->vertici.at(i).z;
		}
	}
	return ris;
}

vec3 TrovaMin(MeshObj* mesh)
{
	vec3 ris = mesh->vertici.at(0);

	for (int i = 0; i < mesh->vertici.size(); i++)
	{
		if (mesh->vertici.at(i).x < ris.x) {
			ris.x = mesh->vertici.at(i).x;
		}
		if (mesh->vertici.at(i).y < ris.y) {
			ris.y = mesh->vertici.at(i).y;
		}
		if (mesh->vertici.at(i).z < ris.z) {
			ris.z = mesh->vertici.at(i).z;
		}
	}
	return ris;
}
