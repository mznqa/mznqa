/*!
 * \file	Classes\helper\dataLoader\ParseStringSet.cpp
 *
 * \brief	定义类 ParseStringSet
 */

#pragma execution_character_set("utf-8")

#include "helper/dataLoader/ParseStringSet.h"

#include "json/reader.h"

std::map<int, std::string> ParseStringSet::bufferStringSet;

namespace ForParseStringSet
{
	/*!
	* \struct	ParseState
	*
	* \brief	ForParseStringSet::Handler 特需的用于记录解析节点状态的结构体
	*
	*/
	struct ParseState
	{
		enum State
		{
			State_Global = 0,
			State_StringSet = 1,
			State_String = 2,
		};

		int state;

		ParseState() :
			state(State_Global)
		{}

		ParseState& operator++()
		{
			if (state + 1 <= State_String)
				++state;
			return *this;
		}
		ParseState& operator--()
		{
			if (state - 1 >= State_Global)
				--state;
			return *this;
		}
	};

	/*!
	* \struct	Handler
	*
	* \brief	ParseStringSet 特需的用于处理解析过程的结构体
	*
	*/
	struct Handler : public rapidjson::BaseReaderHandler<rapidjson::UTF8<>>
	{
	private:
		ParseState ps;

		int keyTemp;
		std::string valueTemp;

	public:
		bool Null()
		{
			return true;
		}
		bool Bool(bool b)
		{
			return true;
		}
		bool Int(int i)
		{
			if (ps.state == ParseState::State_String)
				keyTemp = i;
			return true;
		}
		bool Uint(unsigned u)
		{
			if (ps.state == ParseState::State_String)
				keyTemp = u;
			return true;
		}
		bool Int64(int64_t i)
		{
			return true;
		}
		bool Uint64(uint64_t u)
		{
			return true;
		}
		bool Double(double d)
		{
			return true;
		}
		bool String(const char* str, rapidjson::SizeType length, bool copy)
		{
			if (ps.state == ParseState::State_String)
				valueTemp = std::string(str);
			return true;
		}
		bool StartObject()
		{
			++ps;
			return true;
		}
		bool Key(const char* str, rapidjson::SizeType length, bool copy)
		{
			return true;
		}
		bool EndObject(rapidjson::SizeType memberCount)
		{
			--ps;
			return true;
		}
		bool StartArray()
		{
			++ps;
			return true;
		}
		bool EndArray(rapidjson::SizeType elementCount)
		{
			if (ps.state == ParseState::State_String)
			{
				ParseStringSet::bufferStringSet.insert(std::pair<int, std::string>(keyTemp, valueTemp));
			}
			--ps;
			return true;
		}
	};
}

bool ParseStringSet::parse(const char *const data)
{
	// 解析所需特定流
	rapidjson::StringStream ss(data);
	// 解析器
	rapidjson::Reader reader;
	// 处理器
	ForParseStringSet::Handler handler;
	// 解析
	reader.Parse(ss, handler);
	// 判断解析是否出错
	if (reader.HasParseError())
	{
		bufferStringSet.clear();
		return false;
	}
	else
		return true;
}