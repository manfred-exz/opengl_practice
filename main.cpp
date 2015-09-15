#include <iostream>
#include "Display.h"
#include "Shader.h"
#include "Mesh.h"

using namespace std;

int main() {
	Display display(800, 600, "Hello world!");

	Vertex vertices[] = { Vertex(glm::vec3(-0.5, -0.5, 0)),
	                      Vertex(glm::vec3(0, 0.5, 0)),
	                      Vertex(glm::vec3(0.5, -0.5, 0)),
	};

	Mesh mesh(vertices, sizeof(vertices)/sizeof(vertices[0]));


	Shader shader("./res/basicShader");

	while (!display.IsClosed()) {
		display.Clear(0.0f, 0.15f, 0.3f, 0.0f);
		shader.Bind();

		mesh.Draw();

		display.Update();
	}

	return 0;
}