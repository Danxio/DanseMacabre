#include "importuj.h"


Importuj::Importuj() {}

Importuj::Importuj(std::string path){
	loading(path);
}
Importuj::~Importuj() {}

void Importuj::loading(std::string path) {
	Assimp::Importer import;
	const aiScene * scene = import.ReadFile(path, aiProcess_Triangulate | aiProcess_FlipUVs | aiProcess_GenSmoothNormals);
	std::cout << import.GetErrorString() << std::endl;

	if (scene->HasMeshes()) {
		for (int i = 0; i < scene->mNumMeshes; i++) {
			siatki.push_back(Siatka());
			siatki[i].importMesh(scene->mMeshes[i]);
		}
		//importMesh(scene->mMeshes[8]);
	}

}

