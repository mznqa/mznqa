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
		// �˴�Ϊ�����ã���win32��mac��linuxƽ̨���ڻ����У���android���ƶ��豸ȫ��Ļ����
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WIN32) || (CC_TARGET_PLATFORM == CC_PLATFORM_MAC) || (CC_TARGET_PLATFORM == CC_PLATFORM_LINUX)
		glview = GLViewImpl::createWithRect("mznqa", Rect(0, 0, 960, 540));
#else
		glview = GLViewImpl::createWithFullScreen("mznqa");
#endif

		director->setOpenGLView(glview);
	}

	// ���ö�ֱ���֧�ֲ���
	setResolutionPolicy();

	// ��ʾ FPS
	director->setDisplayStats(true);

	// ���� FPS
	director->setAnimationInterval(float(1.0 / 60.0));

	// �����Դ����Ŀ¼
	FileUtils::getInstance()->addSearchPath("res");

	// ������һ����������������
	auto scene = SceneGuide::createScene();
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

void AppDelegate::setResolutionPolicy()
{
	auto director = Director::getInstance();
	auto glview = director->getOpenGLView();
	// ��ȡ���ڴ�С
	Size frameSize = glview->getFrameSize();

	// ����Ԥ����Ʒֱ��� //////////////////////////////////////////////////////////////////////////
	// ����Ԥ����Ƴߴ�
	const cocos2d::Size designResolutionSize = cocos2d::Size(1920.0, 1080.0);
	// ������Ʒֱ��ʣ��ֱ��ʲ���Ϊ������ʾ�߷��򣬼�ѡ��FIXED_HEIGHT
	glview->setDesignResolutionSize(designResolutionSize.width, designResolutionSize.height, ResolutionPolicy::FIXED_HEIGHT);
	//////////////////////////////////////////////////////////////////////////

	// ѡ��������Դ�������������ű� //////////////////////////////////////////////////////////////////////////
	// ������С֧�ֳߴ�
	const cocos2d::Size smallResolutionSize = cocos2d::Size(480.0, 270.0);
	// �����е�֧�ֳߴ�
	const cocos2d::Size mediumResolutionSize = cocos2d::Size(960.0, 540.0);
	// �������֧�ֳߴ�
	const cocos2d::Size largeResolutionSize = cocos2d::Size(1920.0, 1080.0);

	// ���ʵ�ʴ��ڴ�С����Ԥ����еȷֱ���
	if (frameSize.width > mediumResolutionSize.width)
	{
		// ѡ�ö�Ӧ��Դ
		FileUtils::getInstance()->addSearchPath("res/images/HDR");
		// ����Ԥ������ֱ��ʵĸߺ�Ԥ������Ʒֱ��ʵĸ�֮��������������������
		director->setContentScaleFactor(largeResolutionSize.height / designResolutionSize.height);
	}
	// ���ʵ�ʴ��ڴ���Ԥ�����С�ֱ��ʣ���С�ڵ���Ԥ����еȷֱ���
	else if (frameSize.width > smallResolutionSize.width)
	{
		// ѡ�ö�Ӧ��Դ
		FileUtils::getInstance()->addSearchPath("res/images/HD");
		// ����Ԥ����еȷֱ��ʵĸߺ�Ԥ������Ʒֱ��ʵĸ�֮��������������������
		director->setContentScaleFactor(mediumResolutionSize.height / designResolutionSize.height);
	}
	// ���ʵ�ʵĴ��ڴ�СС�ڵ���Ԥ�����С�ֱ���
	else
	{
		// ѡ�ö�Ӧ��Դ
		FileUtils::getInstance()->addSearchPath("res/images/SD");
		// ����Ԥ�����С�ֱ��ʵĸߺ�Ԥ������Ʒֱ��ʵĸ�֮��������������������
		director->setContentScaleFactor(smallResolutionSize.height / designResolutionSize.height);
	}
	//////////////////////////////////////////////////////////////////////////

	// ������Ϣ //////////////////////////////////////////////////////////////////////////
	TargetInfo *const TargetInfoInstance = TargetInfo::Instance();
	// ���洰�ڴ�С
	TargetInfoInstance->setWindowSize(frameSize.width, frameSize.height);

	// ����Ԥ������Ƴߴ�
	TargetInfoInstance->setExpectedDesignSize(designResolutionSize.width, designResolutionSize.height);

	// ����ʵ�ʵ���Ƴߴ磨�����ź�ģ�
	TargetInfoInstance->setRealityDesignSize(
		designResolutionSize.width * (frameSize.height / designResolutionSize.height),
		frameSize.height
		);

	// ����ʵ����Ƴߴ�ԭ�㣨����Ƴߴ����Ͻǣ��������е�����
	// �� //////////////////////////////////////////////////////////////////////////
	//TargetInfoInstance->setRealityDesignOrigin(
	//	-0.5*(TargetInfoInstance->getRealityDesignSize().width - TargetInfoInstance->getWindowSize().width),
	//	TargetInfoInstance->getWindowSize().height
	//	);
	//////////////////////////////////////////////////////////////////////////
	TargetInfoInstance->setRealityDesignOrigin(
		-0.5*(TargetInfoInstance->getExpectedDesignSize().width - (TargetInfoInstance->getExpectedDesignSize().height / TargetInfoInstance->getWindowSize().height * TargetInfoInstance->getWindowSize().width)),
		TargetInfoInstance->getExpectedDesignSize().height
		);

	// ������Ļ�ߴ����Ͻ��������е�����
	TargetInfoInstance->setScreenLeftTopOrigin(
		0.0,
		TargetInfoInstance->getExpectedDesignSize().height
		);

	// ����Ŀ���豸������
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