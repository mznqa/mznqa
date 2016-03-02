#include "main.h"
#include "AppDelegate.h"
#include "cocos2d.h"

USING_NS_CC;

#if _MSC_VER > 1800
#pragma comment(lib,"libcocos2d_2015.lib")
#pragma comment(lib,"libbox2d_2015.lib")
#pragma comment(lib,"libSpine_2015.lib")
#pragma comment(lib,"librecast_2015.lib")
#pragma comment(lib,"libbullet_2015.lib")
#else
#pragma comment(lib,"libcocos2d_2013.lib")
#pragma comment(lib,"libbox2d_2013.lib")
#pragma comment(lib,"libSpine_2013.lib")
#pragma comment(lib,"librecast_2013.lib")
#pragma comment(lib,"libbullet_2013.lib")
#endif

// !!!DEBUG!!! ������� LOG ��ɾ <1/10>
#define USE_WIN32_CONSOLE

int APIENTRY _tWinMain(HINSTANCE hInstance,
	HINSTANCE hPrevInstance,
	LPTSTR    lpCmdLine,
	int       nCmdShow)
{
	UNREFERENCED_PARAMETER(hPrevInstance);
	UNREFERENCED_PARAMETER(lpCmdLine);

	// !!!DEBUG!!! ������� LOG ��ɾ <2/10>
#ifdef USE_WIN32_CONSOLE
	// !!!DEBUG!!! ������� LOG ��ɾ <3/10>
	AllocConsole();
	// !!!DEBUG!!! ������� LOG ��ɾ <4/10>
	freopen("CONIN$", "r", stdin);
	// !!!DEBUG!!! ������� LOG ��ɾ <5/10>
	freopen("CONOUT$", "w", stdout);
	// !!!DEBUG!!! ������� LOG ��ɾ <6/10>
	freopen("CONOUT$", "w", stderr);
	// !!!DEBUG!!! ������� LOG ��ɾ <7/10>
#endif

	// create the application instance
	AppDelegate app;
	return Application::getInstance()->run();

	// !!!DEBUG!!! ������� LOG ��ɾ <8/10>
#ifdef USE_WIN32_CONSOLE
	// !!!DEBUG!!! ������� LOG ��ɾ <9/10>
	FreeConsole();
	// !!!DEBUG!!! ������� LOG ��ɾ <10/10>
#endif
}