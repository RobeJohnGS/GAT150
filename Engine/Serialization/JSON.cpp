#include "JSON.h"
#include "rapidjson/istreamwrapper.h"
#include "Core/Logger.h"
#include "Math/Vector2.h"
#include "Math/Color.h"
#include "Math/Rect.h"

#include <fstream>

namespace JREngine::json {
	bool Load(const std::string& filename, rapidjson::Document& document)
	{
		std::fstream stream(filename);
		if (!stream.is_open()) {
			LOG("JON file cannot be read %s", filename.c_str());
			return false;
		}

		rapidjson::IStreamWrapper istream(stream);
		document.ParseStream(istream);
		if (document.IsObject() == false) {
			LOG("JSON file cannot be read %s", filename.c_str());
			return false;
		}

		return true;
	}

	bool Get(const rapidjson::Value& value, const std::string& name, int& data)
	{
		if (value.HasMember(name.c_str()) == false || value[name.c_str()].IsInt() == false) {
			LOG("JSON file cannot be read %s", name.c_str());
			return false;
		}

		data = value[name.c_str()].GetInt();
		return true;
	}

	bool Get(const rapidjson::Value& value, const std::string& name, float& data)
	{
		if (value.HasMember(name.c_str()) == false || value[name.c_str()].IsNumber() == false) {
			LOG("JSON file cannot be read %s", name.c_str());
			return false;
		}

		data = value[name.c_str()].GetFloat();
		return true;
	}

	bool Get(const rapidjson::Value& value, const std::string& name, bool& data)
	{
		if (value.HasMember(name.c_str()) == false || value[name.c_str()].IsBool() == false) {
			LOG("JSON file cannot be read %s", name.c_str());
			return false;
		}

		data = value[name.c_str()].GetBool();
		return true;
	}

	bool Get(const rapidjson::Value& value, const std::string& name, std::string& data)
	{
		if (value.HasMember(name.c_str()) == false || value[name.c_str()].IsString() == false) {
			LOG("JSON file cannot be read %s", name.c_str());
			return false;
		}

		data = value[name.c_str()].GetString();
		return true;
	}

	bool Get(const rapidjson::Value& value, const std::string& name, Vector2& data)
	{
		if (value.HasMember(name.c_str()) == false || value[name.c_str()].IsArray() == false || value[name.c_str()].Size() != 2) {
			LOG("JSON file cannot be read %s", name.c_str());
			return false;
		}

		auto& array = value[name.c_str()];

		for (rapidjson::SizeType i = 0; i < array.Size(); i++) {
			if (!array[i].IsNumber()) {
				LOG("JSON file cannot be read %s", name.c_str());
				return false;
			}

			data[i] = array[i].GetFloat();
		}

		return true;
	}

	bool Get(const rapidjson::Value& value, const std::string& name, Color& data)
	{
		if (value.HasMember(name.c_str()) == false || value[name.c_str()].IsArray() == false || value[name.c_str()].Size() != 4) {
			LOG("JSON file cannot be read %s", name.c_str());
			return false;
		}

		auto& array = value[name.c_str()];

		for (rapidjson::SizeType i = 0; i < array.Size(); i++) {
			if (!array[i].IsInt()) {
				LOG("JSON file cannot be read %s", name.c_str());
				return false;
			}

			data[i] = array[i].GetFloat();
		}

		return true;
	}

	bool Get(const rapidjson::Value& value, const std::string& name, Rect& data)
	{
		if (value.HasMember(name.c_str()) == false || value[name.c_str()].IsArray() == false || value[name.c_str()].Size() != 4) {
			LOG("JSON file cannot be read %s", name.c_str());
			return false;
		}

		auto& array = value[name.c_str()];

		data.x = array[0].GetInt();
		data.x = array[1].GetInt();
		data.x = array[2].GetInt();
		data.x = array[3].GetInt();

		return true;
	}
}