//
// Created by manfred on 15-9-14.
//

#ifndef MODERN_OPENGL_DISPLAY_H
#define MODERN_OPENGL_DISPLAY_H
#include <SDL2/SDL.h>
#include <GL/glew.h>
#include <string>

class Display {
public:
	Display(int width, int height, const std::string& title);

	void Clear(float r, float g, float b, float a);
	void Update();
	bool IsClosed();
	virtual ~Display();

protected:
private:
	Display(const Display& other){}
//	Display& operator=(const Display& other){return nullptr;}

	SDL_Window* m_window;
	SDL_GLContext m_glContext;
	bool m_isClosed;
};


#endif //MODERN_OPENGL_DISPLAY_H
