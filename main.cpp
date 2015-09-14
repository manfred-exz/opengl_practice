#include <iostream>
#include "Display.h"
#include "Shader.h"

using namespace std;

int main() {
	Display display(800, 600, "Hello world!");

	Shader shader("./res/basicShader");

	while (!display.IsClosed()) {
		display.Clear(0.0f, 0.15f, 0.3f, 0.0f);
		shader.Bind();


		display.Update();
	}

	return 0;
}