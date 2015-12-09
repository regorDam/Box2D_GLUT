/*
* Copyright (c) 2006-2007 Erin Catto http://www.box2d.org
*
* This software is provided 'as-is', without any express or implied
* warranty.  In no event will the authors be held liable for any damages
* arising from the use of this software.
* Permission is granted to anyone to use this software for any purpose,
* including commercial applications, and to alter it and redistribute it
* freely, subject to the following restrictions:
* 1. The origin of this software must not be misrepresented; you must not
* claim that you wrote the original software. If you use this software
* in a product, an acknowledgment in the product documentation would be
* appreciated but is not required.
* 2. Altered source versions must be plainly marked as such, and must not be
* misrepresented as being the original software.
* 3. This notice may not be removed or altered from any source distribution.
*/


#include "Globals.h"
#include "gl/glut.h"
#include <stdio.h>
#include <conio.h>
#include "cGame.h"
#include <process.h>

cGame Game;

void AppRender(){
	Game.Render();
}
//Reshaping handler (required even in fullscreen-only modes)
void reshape(int w, int h)
{
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	// Calculate the aspect ratio and set the clipping volume
	gluPerspective(45, (float)w / (float)h, 0.1, 10000.0);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

void AppKeyboard(unsigned char key, int x, int y)
{
	Game.ReadKeyboard(key, x, y, true);
}

void AppKeboardUp(unsigned char key, int x, int y)
{
	Game.ReadKeyboard(key, x, y, false);
}

void AppSpecialKeys(int key, int x, int y)
{
	Game.ReadKeyboard(key, x, y, true);
}

void AppSpecialKeysUp(int key, int x, int y)
{
	Game.ReadKeyboard(key, x, y, false);
}
void AppMouse(int button, int state, int x, int y)
{
	Game.ReadMouse(button, state, x, y);
}

void AppIdle()
{
	int timeAct = glutGet(GLUT_ELAPSED_TIME);
	if (Game.Loop()) exit(0);	
}



// This is a simple example of building and running a simulation
// using Box2D. Here we create a large ground box and a small dynamic
// box.
// There are no graphics for this example. Box2D is meant to be used
// with your rendering engine in your game engine.
int main(int argc, char** argv)
{

	//GLUT initialization
	glutInit(&argc, argv);

	//RGBA with double buffer
	glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE);

	glutInitWindowPosition(100, 100);
	glutInitWindowSize(GAME_WIDTH, GAME_HEIGHT);
	glutCreateWindow("My Game");

	//Register callback functions
	glutDisplayFunc(AppRender);
	//glutReshapeFunc(reshape);
	glutKeyboardFunc(AppKeyboard);
	glutKeyboardUpFunc(AppKeboardUp);
	glutSpecialFunc(AppSpecialKeys);
	glutSpecialUpFunc(AppSpecialKeysUp);
	glutMouseFunc(AppMouse);
	glutIdleFunc(AppIdle);

	//Game initializations
	

	//Application loop
	glutMainLoop();
	return 0;
}
