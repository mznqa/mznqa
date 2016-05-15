/*!
 * \file	Classes\interactive\manager\TargetInfo.h
 *
 * \brief	������ TargetInfo
 */

#pragma execution_character_set("utf-8")

#ifndef MZNQA_CLASSES_INTERACTIVE_MANAGER_TARGETINFO_H_
#define MZNQA_CLASSES_INTERACTIVE_MANAGER_TARGETINFO_H_

#include "common/arkca/Size.h"
#include "common/arkca/Vector2.h"

/*!
 * \class	TargetInfo
 *
 * \brief	[����]�йش��ں��豸���йصĳߴ硢�����Լ����Ե���Ϣ
 *
 */
class TargetInfo
{
public:

	/*!
	 * \fn	TargetInfo::~TargetInfo();
	 *
	 * \brief	��������
	 *
	 */
	~TargetInfo();

	/*!
	 * \fn	static TargetInfo* TargetInfo::Instance();
	 *
	 * \brief	��ȡ����
	 *
	 */
	static TargetInfo* Instance();

	/*!
	 * \enum	Language
	 *
	 * \brief	ö��Ŀ���豸������
	 */
	enum Language
	{
		Language_Other,	///< �����µ���һ����
		Language_Zh,	///< ����
		Language_En		///< Ӣ��
	};

	/*!
	 * \fn	void TargetInfo::setWindowSize(float width, float height)
	 *
	 * \brief	���ô��ڳߴ�
	 *
	 * \param	width 	ָ��һ�����ֵ
	 * \param	height	ָ��һ���߶�ֵ
	 */
	void setWindowSize(float width, float height)
	{
		windowSize.set(width, height);
	}

	/*!
	 * \fn	const ArKCa::Size<float>& TargetInfo::getWindowSize()const
	 *
	 * \brief	��ȡ���ڳߴ�
	 *
	 */
	const ArKCa::Size<float>& getWindowSize()const
	{
		return windowSize;
	}

	/*!
	 * \fn	void TargetInfo::setExpectedDesignSize(float width, float height)
	 *
	 * \brief	����Ԥ�����Ƴߴ�
	 *
	 * \param	width 	ָ��һ�����ֵ
	 * \param	height	ָ��һ���߶�ֵ
	 */
	void setExpectedDesignSize(float width, float height)
	{
		defineDesignSize.set(width, height);
	}

	/*!
	 * \fn	const ArKCa::Size<float>& TargetInfo::getExpectedDesignSize()const
	 *
	 * \brief	��ȡԤ�����Ƴߴ�
	 *
	 */
	const ArKCa::Size<float>& getExpectedDesignSize()const
	{
		return defineDesignSize;
	}

	/*!
	 * \fn	void TargetInfo::setRealityDesignSize(float width, float height)
	 *
	 * \brief	����ʵ�ʵ���Ƴߴ�
	 *
	 * \param	width 	ָ��һ�����ֵ
	 * \param	height	ָ��һ���߶�ֵ
	 */
	void setRealityDesignSize(float width, float height)
	{
		realityDesignSize.set(width, height);
	}

	/*!
	 * \fn	const ArKCa::Size<float>& TargetInfo::getRealityDesignSize()const
	 *
	 * \brief	��ȡʵ�ʵ���Ƴߴ�
	 *
	 */
	const ArKCa::Size<float>& getRealityDesignSize()const
	{
		return realityDesignSize;
	}

	/*!
	 * \fn	void TargetInfo::setRealityDesignOrigin(float x, float y)
	 *
	 * \brief	����ʵ����Ƴߴ�����Ͻǵ�����Ļ�е�����
	 *
	 * \param	x	ָ��������
	 * \param	y	ָ��������
	 */
	void setRealityDesignOrigin(float x, float y)
	{
		realityDesignOrigin.set(x, y);
	}

	/*!
	 * \fn	const ArKCa::Vector2<float>& TargetInfo::getDesignOrigin()const
	 *
	 * \brief	��ȡʵ����Ƴߴ�����Ͻǵ�����Ļ�е�����
	 *
	 */
	const ArKCa::Vector2<float>& getDesignOrigin()const
	{
		return realityDesignOrigin;
	}

	/*!
	 * \fn	void TargetInfo::setScreenLeftTopOrigin(float x, float y)
	 *
	 * \brief	������Ļ���Ͻ�����Ļ�е�����
	 *
	 * \param	x	ָ��������
	 * \param	y	ָ��������
	 */
	void setScreenLeftTopOrigin(float x, float y)
	{
		screenLeftTopOrigin.set(x, y);
	}

	/*!
	 * \fn	const ArKCa::Vector2<float>& TargetInfo::getScreenLeftTopOrigin()const
	 *
	 * \brief	��ȡ��Ļ���Ͻ�����Ļ�е�����
	 *
	 */
	const ArKCa::Vector2<float>& getScreenLeftTopOrigin()const
	{
		return screenLeftTopOrigin;
	}

	/*!
	 * \fn	void TargetInfo::setScreenSize(float x, float y)
	 *
	 * \brief	������Ļʵ�ʷֱ���
	 *
	 * \param	x	ָ�����
	 * \param	y	ָ���߶�
	 */
	void setScreenSize(float x, float y)
	{
		screenSize.set(x, y);
	}

	/*!
	 * \fn	const ArKCa::Size<float>& TargetInfo::getScreenSize()const
	 *
	 * \brief	��ȡ��Ļʵ�ʷֱ���
	 *
	 */
	const ArKCa::Size<float>& getScreenSize()const
	{
		return screenSize;
	}

	/*!
	 * \fn	void TargetInfo::setLanguage(Language language)
	 *
	 * \brief	����Ŀ���豸������
	 *
	 * \param	language	ָ������������Ŀ���豸������
	 */
	void setLanguage(Language language)
	{
		this->language = language;
	}

	/*!
	 * \fn	Language TargetInfo::getLanguage()const
	 *
	 * \brief	��ȡĿ���豸������
	 *
	 */
	Language getLanguage()const
	{
		return language;
	}

private:

	/*!
	 * \fn	TargetInfo::TargetInfo();
	 *
	 * \brief	���ص�Ĭ�Ϲ��캯��
	 *
	 */
	TargetInfo();

	/*!
	 * \fn	TargetInfo::TargetInfo(const TargetInfo &sizeManager);
	 *
	 * \brief	���صĿ������캯��
	 *
	 */
	TargetInfo(const TargetInfo &sizeManager);

	/*!
	 * \fn	TargetInfo& TargetInfo::operator=(const TargetInfo &sizeManager);
	 *
	 * \brief	���صĿ�����ֵ�����
	 *
	 */
	TargetInfo& operator=(const TargetInfo &sizeManager);

	/*! \brief	���ڣ���Ļ���ߴ� */
	ArKCa::Size<float> windowSize = ArKCa::Size<float>(0.0f, 0.0f);
	/*! \brief	Ԥ�����Ƴߴ� */
	ArKCa::Size<float> defineDesignSize = ArKCa::Size<float>(0.0f, 0.0f);
	/*! \brief	����ֱ���֧�ֲ���ƥ���豸�����ŵ�ʵ����Ƴߴ� */
	ArKCa::Size<float> realityDesignSize = ArKCa::Size<float>(0.0f, 0.0f);
	/*! \brief	ʵ����Ƴߴ�����Ͻǵ�����Ļ�е����� */
	ArKCa::Vector2<float> realityDesignOrigin = ArKCa::Vector2<float>(0.0f, 0.0f);
	/*! \brief	��Ļ���Ͻǵ���������Ļ�е����� */
	ArKCa::Vector2<float> screenLeftTopOrigin = ArKCa::Vector2<float>(0.0f, 0.0f);
	/*! \brief	����ʵ�ʷֱ��ʳߴ� */
	ArKCa::Size<float> screenSize = ArKCa::Size<float>(0.0f, 0.0f);

	/*! \brief	Ŀ���豸������ */
	Language language = Language_Zh;
};

#endif