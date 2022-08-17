#pragma once
#include "rapidjson/document.h"
#include <string>

//#define READ_DATA(value, data) JREngine::json::Get(value, #data, data)

namespace JREngine::json {
	bool Load(const std::string& filename, rapidjson::Document& document);

	bool Get(const rapidjson::Value& value, const std::string& name, int& data);
}