#include "siatka.h"

Siatka::Siatka(){}
Siatka::~Siatka(){}
void Siatka::importMesh(aiMesh* mesh) {
	for (int i = 0; i < mesh->mNumVertices; i++) {

		aiVector3D vertex = mesh->mVertices[i]; //aiVector3D podobny do glm::vec3

		verts.push_back(glm::vec4(vertex.x, vertex.y, vertex.z, 1));

		aiVector3D normal = mesh->mNormals[i]; //Wektory znormalizowane
		norms.push_back(glm::vec4(normal.x, normal.y, normal.z, 0));

		//liczba zdefiniowanych zestawów wsp. teksturowania (zestawów jest max 8)
		unsigned int liczba_zest = mesh->GetNumUVChannels();
		//Liczba sk³adowych wsp. teksturowania dla 0 zestawu.
		unsigned int wymiar_wsp_tex = mesh->mNumUVComponents[0];
		//0 to numer zestawu wspó³rzêdnych teksturowania
		aiVector3D texCoord = mesh->mTextureCoords[0][i];
		//x,y,z wykorzystywane jako u,v,w. 0 je¿eli tekstura ma mniej wymiarów
		texCoords.push_back(glm::vec2(texCoord.x, texCoord.y));
	}

	//dla ka¿dego wielok¹ta sk³adowego
	for (int i = 0; i < mesh->mNumFaces; i++) {
		aiFace& face = mesh->mFaces[i]; //face to jeden z wielok¹tów siatki
		//dla ka¿dego indeksu->wierzcho³ka tworz¹cego wielok¹t
		//dla aiProcess_Triangulate to zawsze bêdzie 3
		for (int j = 0; j < face.mNumIndices; j++) {
			indices.push_back(face.mIndices[j]);
		}
		//std::cout << std::endl;
	}
}

void Siatka::drawSolid(bool smooth){}
