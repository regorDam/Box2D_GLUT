#include "gl/glut.h"
#include "Globals.h"

class cGame
{
public:

	bool Init();
	bool Loop();
	void Finalize();

	//Input
	void ReadKeyboard(unsigned char key, int x, int y, bool press);
	void ReadMouse(int button, int state, int x, int y);

	//Process
	bool Process();

	//Output
	void Render();



private:
	unsigned char keys[256];
	void ProcessPhysics();



};