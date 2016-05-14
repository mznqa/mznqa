#pragma execution_character_set("utf-8")

#include "AppDelegate.h"

#include "interactive/manager/TargetInfo.h"
#include "interactive/assets/scene/SceneGuide.h"

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

	// 设置多分辨率支持策略
	setResolutionPolicy();

	// 显示 FPS
	director->setDisplayStats(true);

	// 设置 FPS
	director->setAnimationInterval(float(1.0 / 60.0));

	// 添加资源搜索目录
	FileUtils::getInstance()->addSearchPath("res");

	// 创建第一个场景：引导场景
	auto scene = SceneGuide::createScene();
	// 运行场景
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

void AppDelegate::setResolutionPolicy()
{
	auto director = Director::getInstance();
	auto glview = director->getOpenGLView();
	// 获取窗口大小
	Size frameSize = glview->getFrameSize();

	// 设置预定设计分辨率 //////////////////////////////////////////////////////////////////////////
	// 定义预定设计尺寸
	const cocos2d::Size designResolutionSize = cocos2d::Size(1920.0, 1080.0);
	// 设置设计分辨率，分辨率策略为完整显示高方向，即选用FIXED_HEIGHT
	glview->setDesignResolutionSize(designResolutionSize.width, designResolutionSize.height, ResolutionPolicy::FIXED_HEIGHT);
	//////////////////////////////////////////////////////////////////////////

	// 选用配套资源和设置内容缩放比 //////////////////////////////////////////////////////////////////////////
	// 定义最小支持尺寸
	const cocos2d::Size smallResolutionSize = cocos2d::Size(480.0, 270.0);
	// 定义中等支持尺寸
	const cocos2d::Size mediumResolutionSize = cocos2d::Size(960.0, 540.0);
	// 定义最高支持尺寸
	const cocos2d::Size largeResolutionSize = cocos2d::Size(1920.0, 1080.0);

	// 如果实际窗口大小大于预设的中等分辨率
	if (frameSize.width > mediumResolutionSize.width)
	{
		// 选用对应资源
		FileUtils::getInstance()->addSearchPath("res/images/HDR");
		// 基于预设的最大分辨率的高和预定的设计分辨率的高之比来设置内容缩放因子
		director->setContentScaleFactor(largeResolutionSize.height / designResolutionSize.height);
	}
	// 如果实际窗口大于预设的最小分辨率，且小于等于预设的中等分辨率
	else if (frameSize.width > smallResolutionSize.width)
	{
		// 选用对应资源
		FileUtils::getInstance()->addSearchPath("res/images/HD");
		// 基于预设的中等分辨率的高和预定的设计分辨率的高之比来设置内容缩放因子
		director->setContentScaleFactor(mediumResolutionSize.height / designResolutionSize.height);
	}
	// 如果实际的窗口大小小于等于预设的最小分辨率
	else
	{
		// 选用对应资源
		FileUtils::getInstance()->addSearchPath("res/images/SD");
		// 基于预设的最小分辨率的高和预定的设计分辨率的高之比来设置内容缩放因子
		director->setContentScaleFactor(smallResolutionSize.height / designResolutionSize.height);
	}
	//////////////////////////////////////////////////////////////////////////

	// 保存信息 //////////////////////////////////////////////////////////////////////////
	TargetInfo *const TargetInfoInstance = TargetInfo::Instance();
	// 保存窗口大小
	TargetInfoInstance->setWindowSize(frameSize.width, frameSize.height);

	// 保存预定的设计尺寸
	TargetInfoInstance->setExpectedDesignSize(designResolutionSize.width, designResolutionSize.height);

	// 计算实际的设计尺寸（被缩放后的）
	TargetInfoInstance->setRealityDesignSize(
		designResolutionSize.width * (frameSize.height / designResolutionSize.height),
		frameSize.height
		);

	// 计算实际设计尺寸原点（即设计尺寸左上角）在世界中的坐标
	// 旧 //////////////////////////////////////////////////////////////////////////
	//TargetInfoInstance->setRealityDesignOrigin(
	//	-0.5*(TargetInfoInstance->getRealityDesignSize().width - TargetInfoInstance->getWindowSize().width),
	//	TargetInfoInstance->getWindowSize().height
	//	);
	//////////////////////////////////////////////////////////////////////////
	TargetInfoInstance->setRealityDesignOrigin(
		-0.5*(TargetInfoInstance->getExpectedDesignSize().width - (TargetInfoInstance->getExpectedDesignSize().height / TargetInfoInstance->getWindowSize().height * TargetInfoInstance->getWindowSize().width)),
		TargetInfoInstance->getExpectedDesignSize().height
		);

	// 计算屏幕尺寸左上角在世界中的坐标
	TargetInfoInstance->setScreenLeftTopOrigin(
		0.0,
		TargetInfoInstance->getExpectedDesignSize().height
		);

	// 保存目标设备的语言
	switch (Application::getCurrentLanguage())
	{
	case LanguageType::CHINESE:
		TargetInfoInstance->setLanguage(TargetInfo::Language_Zh);
		break;
	case LanguageType::ENGLISH:
		TargetInfoInstance->setLanguage(TargetInfo::Language_En);
		break;
	default:
		TargetInfoInstance->setLanguage(TargetInfo::Language_Other);
		break;
	}
	//////////////////////////////////////////////////////////////////////////
}