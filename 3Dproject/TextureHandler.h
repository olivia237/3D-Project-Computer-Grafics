#pragma once
#include "Lib.h"

unsigned int loadTexture(char const *path, int flip);

unsigned int loadCubemap(vector<string> faces, int flip);