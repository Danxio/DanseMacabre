#pragma once
#include "siatka.h"


class Importuj {
public:
	Importuj();
	Importuj(std::string path);
	~Importuj();

	std::vector<Siatka> siatki;

private:
	void loading(std::string path);
};


