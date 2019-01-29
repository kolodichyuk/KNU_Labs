#include "MenuAndGenerators.h";

using namespace std;
int main() {
	setlocale(LC_ALL, "ukr");
	MenuAndGenerators* instance = new MenuAndGenerators();
	instance->MainLogic();
	delete instance;
	return 0;
}
