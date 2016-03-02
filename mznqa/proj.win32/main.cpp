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

// !!!DEBUG!!! 用于输出 LOG 可删 <1/10>
#define USE_WIN32_CONSOLE

int APIENTRY _tWinMain(HINSTANCE hInstance,
	HINSTANCE hPrevInstance,
	LPTSTR    lpCmdLine,
	int       nCmdShow)
{
	UNREFERENCED_PARAMETER(hPrevInstance);
	UNREFERENCED_PARAMETER(lpCmdLine);

	// !!!DEBUG!!! 用于输出 LOG 可删 <2/10>
#ifdef USE_WIN32_CONSOLE
	// !!!DEBUG!!! 用于输出 LOG 可删 <3/10>
	AllocConsole();
	// !!!DEBUG!!! 用于输出 LOG 可删 <4/10>
	freopen("CONIN$", "r", stdin);
	// !!!DEBUG!!! 用于输出 LOG 可删 <5/10>
	freopen("CONOUT$", "w", stdout);
	// !!!DEBUG!!! 用于输出 LOG 可删 <6/10>
	freopen("CONOUT$", "w", stderr);
	// !!!DEBUG!!! 用于输出 LOG 可删 <7/10>
#endif

	// create the application instance
	AppDelegate app;
	return Application::getInstance()->run();

	// !!!DEBUG!!! 用于输出 LOG 可删 <8/10>
#ifdef USE_WIN32_CONSOLE
	// !!!DEBUG!!! 用于输出 LOG 可删 <9/10>
	FreeConsole();
	// !!!DEBUG!!! 用于输出 LOG 可删 <10/10>
#endif
}