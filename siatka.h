#pragma once
#include <GL/glew.h>
#include <vector>
#include <glm/glm.hpp>
#include <GLFW/glfw3.h>
#include "constants.h"
#include <iostream>
#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>
class Siatka
{
public:
	Siatka();
	~Siatka();

	std::vector<unsigned int> indices;
	std::vector<glm::vec4> verts;
	std::vector<glm::vec4> norms;
	std::vector<glm::vec2> texCoords;

	void drawSolid(bool smooth = false);
	void importMesh(aiMesh* mesh);
};

