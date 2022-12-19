#pragma once
#include "Lib.h"
#include "Strutture.h"

vec3 TrovaMax(Mesh* mesh); // trovo i massimi per ogni asse
vec3 TrovaMin(Mesh* mesh); // trovo i minimi per ogni asse

vec3 TrovaMax(MeshObj* mesh); // trovo i massimi per ogni asse
vec3 TrovaMin(MeshObj* mesh); // trovo i minimi per ogni asse
