#pragma execution_character_set("utf-8")

#include "AppDelegate.h"
#include "engine/SceneDebug.h"

USING_NS_CC;

AppDelegate::AppDelegate() {
}

AppDelegate::~AppDelegate()
{
}

//if you want a different context,just modify the value of glContextAttrs
//it will takes effect on all platforms
void AppDelegate::initGLContextAttrs()
{
	//set OpenGL context attributions,now can only set six attributions:
	//red,green,blue,alpha,depth,stencil
	GLContextAttrs glContextAttrs = { 8, 8, 8, 8, 24, 8 };

	GLView::setGLContextAttrs(glContextAttrs);
}

bool AppDelegate::applicationDidFinishLaunching() {
	// initialize director
	auto director = Director::getInstance();
	auto glview = director->getOpenGLView();
	if (!glview) {
		// !!!DEBUG!!! �˴�Ϊ�����ã���win32ƽ̨���ڻ����У���androidȫ��Ļ����
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WIN32)
		glview = GLViewImpl::createWithRect("mznqa", Rect(0, 0, 960, 540));
#else
		glview = GLViewImpl::createWithFullScreen("mznqa");
#endif

		director->setOpenGLView(glview);
	}

	// ������Ƴߴ������ģʽ
	director->getOpenGLView()->setDesignResolutionSize(1920, 1080, ResolutionPolicy::SHOW_ALL);

	// ��ʾ FPS
	director->setDisplayStats(true);

	// ���� FPS
	director->setAnimationInterval(float(1.0 / 60.0));

	// �����Դ����Ŀ¼
	FileUtils::getInstance()->addSearchPath("res");

	// ����һ�����������״�����
	// ����ʹ��SceneDebug��������������
	auto scene = SceneDebug::createScene();

	// ���г���
	director->runWithScene(scene);

	return true;
}

// This function will be called when the app is inactive. When comes a phone call,it's be invoked too
void AppDelegate::applicationDidEnterBackground() {
	Director::getInstance()->stopAnimation();

	// if you use SimpleAudioEngine, it must be pause
	// SimpleAudioEngine::getInstance()->pauseBackgroundMusic();
}

// this function will be called when the app is active again
void AppDelegate::applicationWillEnterForeground() {
	Director::getInstance()->startAnimation();

	// if you use SimpleAudioEngine, it must resume here
	// SimpleAudioEngine::getInstance()->resumeBackgroundMusic();
}