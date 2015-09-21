#include <iostream>
#include "Display.h"
#include "Shader.h"
#include "Mesh.h"
#include "Texture.h"

using namespace std;

int main() {
	Display display(800, 600, "Hello world!");

	Vertex vertices[] = {Vertex(glm::vec3(-0.5, -0.5, 0), glm::vec2(0.0, 0.0)),
	                     Vertex(glm::vec3(0, 0.5, 0), glm::vec2(0.5, 1.0)),
	                     Vertex(glm::vec3(0.5, -0.5, 0), glm::vec2(1.0, 0.0)),
	};

	Mesh mesh(vertices, sizeof(vertices) / sizeof(vertices[0]));
	Shader shader("./res/basicShader");
	Texture texture("./res/bricks.jpg");
	Transform transform;

	float counter = 0.0f;

	while (!display.IsClosed()) {
		display.Clear(0.0f, 0.15f, 0.3f, 1.0f);

		transform.getPos().x = sinf(counter);
		transform.getRot().z = counter * 50;
		transform.setScale(glm::vec3(sinf(counter)));

		shader.Bind();
		shader.Update(transform);
		texture.Bind(0);
		mesh.Draw();

		display.Update();
		counter += 0.01f;
	}

	return 0;
}