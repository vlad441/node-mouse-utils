#include <iostream>
#include <windows.h>

int main(int argc, char * argv[])
{	// = мышь =
	if(argc>=2&&strcmp(argv[1], "-setpos")==0)
	{ 	if(argc<4){ std::cout << "error: set - args not input." << std::endl; return 0; }
		SetCursorPos(atoi(argv[2]), atoi(argv[3])); std::cout << "done: set" << std::endl; return 1; }
	if(argc>=2&&strcmp(argv[1], "-getpos")==0){ POINT m; GetCursorPos(&m); std::cout << "done: " <<m.x<<" "<<m.y; return 1; }
	if(argc>=2&&strcmp(argv[1], "-click")==0)
	{ 	mouse_event(MOUSEEVENTF_LEFTDOWN | MOUSEEVENTF_LEFTUP, 0, 0, 0, 0); std::cout << "done: click" << std::endl; return 1; }
	if(argc>=2&&strcmp(argv[1], "-dclick")==0)
	{ 	mouse_event(MOUSEEVENTF_LEFTDOWN | MOUSEEVENTF_LEFTUP, 0, 0, 0, 0); Sleep(50);
		mouse_event(MOUSEEVENTF_LEFTDOWN | MOUSEEVENTF_LEFTUP, 0, 0, 0, 0); std::cout << "done: dclick" << std::endl; return 1; }
	if(argc>=2&&strcmp(argv[1], "-rclick")==0)
	{ 	mouse_event(MOUSEEVENTF_RIGHTDOWN | MOUSEEVENTF_RIGHTUP, 0, 0, 0, 0); std::cout << "done: rclick" << std::endl; return 1; }
	// = клавиатура =
	if(argc>=2&&strcmp(argv[1], "-press")==0)
	{ 	if(argc<3){ std::cout << "error: press - keycode not input." << std::endl; return 0; }
		keybd_event(char(atoi(argv[2])), 0,0,0); keybd_event(char(atoi(argv[2])), 0,KEYEVENTF_KEYUP,0); std::cout << "done: press" << std::endl; return 1; }
}