#pragma execution_character_set("utf-8")

#include "AppDelegate.h"

USING_NS_CC;

// ����֧�ֶ�ֱ��ʵĲ��� //////////////////////////////////////////////////////////////////////////
// ������Ƴߴ�
static cocos2d::Size designResolutionSize = cocos2d::Size(1920.0, 1080.0);

// ������С֧�ֳߴ�
static cocos2d::Size smallResolutionSize = cocos2d::Size(480.0, 270.0);
// �����е�֧�ֳߴ�
static cocos2d::Size mediumResolutionSize = cocos2d::Size(960.0, 540.0);
// �������֧�ֳߴ�
static cocos2d::Size largeResolutionSize = cocos2d::Size(1920.0, 1080.0);
//////////////////////////////////////////////////////////////////////////

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
	if (!glview)
	{
		// �˴�Ϊ�����ã���win32��mac��linuxƽ̨���ڻ����У���android���ƶ��豸ȫ��Ļ����
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WIN32) || (CC_TARGET_PLATFORM == CC_PLATFORM_MAC) || (CC_TARGET_PLATFORM == CC_PLATFORM_LINUX)
		glview = GLViewImpl::createWithRect("mznqa", Rect(0, 0, 960, 540));
#else
		glview = GLViewImpl::createWithFullScreen("mznqa");
#endif

		director->setOpenGLView(glview);
	}

	// ����֧�ֶ�ֱ��ʵĲ��� //////////////////////////////////////////////////////////////////////////
	glview->setDesignResolutionSize(designResolutionSize.width, designResolutionSize.height, ResolutionPolicy::FIXED_WIDTH);
	Size frameSize = glview->getFrameSize();
	if (frameSize.width > mediumResolutionSize.width)
	{
		FileUtils::getInstance()->addSearchPath("res/images/HDR");
		director->setContentScaleFactor(largeResolutionSize.width / designResolutionSize.width);
	}
	else if (frameSize.width > smallResolutionSize.width)
	{
		FileUtils::getInstance()->addSearchPath("res/images/HD");
		director->setContentScaleFactor(mediumResolutionSize.width / designResolutionSize.width);
	}
	else
	{
		FileUtils::getInstance()->addSearchPath("res/images/SD");
		director->setContentScaleFactor(smallResolutionSize.width / designResolutionSize.width);
	}
	//////////////////////////////////////////////////////////////////////////

	// ��ʾ FPS
	director->setDisplayStats(true);

	// ���� FPS
	director->setAnimationInterval(float(1.0 / 60.0));

	// �����Դ����Ŀ¼
	FileUtils::getInstance()->addSearchPath("res");

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