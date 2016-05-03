#pragma execution_character_set("utf-8")

#include "AppDelegate.h"
#include "engine/SceneDebug.h"
#include "engine/SizeController.h"

USING_NS_CC;

// 用于支持多分辨率的操作 //////////////////////////////////////////////////////////////////////////
// 定义设计尺寸
static cocos2d::Size designResolutionSize = cocos2d::Size(1920.0, 1080.0);

// 定义最小分辨率资源的适配尺寸
static cocos2d::Size smallResolutionSize = cocos2d::Size(480.0, 270.0);
// 定义中等分辨率资源的适配尺寸
static cocos2d::Size mediumResolutionSize = cocos2d::Size(960.0, 540.0);
// 定义最高分辨率资源的适配尺寸
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
		// 此处为调试用，在win32、mac、linux平台窗口化运行，在android等移动设备全屏幕运行
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WIN32) || (CC_TARGET_PLATFORM == CC_PLATFORM_MAC) || (CC_TARGET_PLATFORM == CC_PLATFORM_LINUX)
		glview = GLViewImpl::createWithRect("mznqa", Rect(0, 0, 960, 540));
#else
		glview = GLViewImpl::createWithFullScreen("mznqa");
#endif

		director->setOpenGLView(glview);
	}

	// 用于支持多分辨率的操作 //////////////////////////////////////////////////////////////////////////
	// 设置设计分辨率
	glview->setDesignResolutionSize(designResolutionSize.width, designResolutionSize.height, ResolutionPolicy::NO_BORDER);
	// 获取实际分辨率
	Size frameSize = glview->getFrameSize();
	// 以下基于设备的实际分辨率宽度来选择指定适配的资源，并设置资源的缩放系数 //////////////////////////////////////////////////////////////////////////
	// 如果实际分辨率（水平方向）大于预定义的中等适配分辨率
	if (frameSize.width > mediumResolutionSize.width)
	{
		// 则采用HDR下的资源
		FileUtils::getInstance()->addSearchPath("res/images/HDR");
		// 并设置资源的缩放系数
		director->setContentScaleFactor(largeResolutionSize.width / designResolutionSize.width);
	}
	// 如果实际分辨率（水平方向），小于或等于预定义的中等适配分辨率，而大于预定义的最小适配分辨率
	else if (frameSize.width > smallResolutionSize.width)
	{
		// 则采用HD下的资源
		FileUtils::getInstance()->addSearchPath("res/images/HD");
		// 并设置资源的缩放系数
		director->setContentScaleFactor(mediumResolutionSize.width / designResolutionSize.width);
	}
	// 如果实际分辨率（水平方向）小于等于预定义的最小适配分辨率
	else
	{
		// 则采用SD下的资源
		FileUtils::getInstance()->addSearchPath("res/images/SD");
		// 并设置资源的缩放系数
		director->setContentScaleFactor(smallResolutionSize.width / designResolutionSize.width);
	}
	//////////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////////

	// FPS 有关 //////////////////////////////////////////////////////////////////////////
	// 显示 FPS
	director->setDisplayStats(true);
	// 设置 FPS
	director->setAnimationInterval(float(1.0 / 60.0));
	//////////////////////////////////////////////////////////////////////////

	// 添加资源搜索目录
	FileUtils::getInstance()->addSearchPath("res");

	// 创建一个场景用于首次载入
	// 这里使用SceneDebug场景仅用于引导
	auto scene = SceneDebug::createScene();

	// 运行场景
	director->runWithScene(scene);

	// 记录相关尺寸信息 //////////////////////////////////////////////////////////////////////////
	// 记录设计分辨率 //////////////////////////////////////////////////////////////////////////
	SizeController::Instance()->designResolutionSizeWidth = director->getOpenGLView()->getDesignResolutionSize().width;
	SizeController::Instance()->designResolutionSizeHeight = director->getOpenGLView()->getDesignResolutionSize().height;
	//////////////////////////////////////////////////////////////////////////

	// 记录实际分辨率 //////////////////////////////////////////////////////////////////////////
	SizeController::Instance()->realityScreenSizeWidth = director->getOpenGLView()->getFrameSize().width;
	SizeController::Instance()->realityScreenSizeHeight = director->getOpenGLView()->getFrameSize().height;
	//////////////////////////////////////////////////////////////////////////

	// 记录可视区域的左边原点 //////////////////////////////////////////////////////////////////////////
	SizeController::Instance()->realityVisibleOriginX = director->getOpenGLView()->getVisibleOrigin().x;
	SizeController::Instance()->realityVisibleOriginY = director->getOpenGLView()->getVisibleOrigin().y;
	//////////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////////

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