#include "JSON.h"
#include "rapidjson/istreamwrapper.h"
#include "Core/Logger.h"
#include <fstream>

namespace JREngine {

	bool json::Load(const std::string& filename, rapidjson::Document& document)
	{
		std::fstream fS(filename);
		if (!fS.is_open()) {
			LOG("JSON file can not be read%", filename.c_str());
			return false;
		}
		
		rapidjson::IStreamWrapper istream(fS);
		document.ParseStream(istream);
		if (document.IsObject() == false) {
			LOG("json file cannot be read %s.", filename.c_str());
			return false;
		}

		return true;
	}

	bool json::Get(const rapidjson::Value& value, const std::string& name, int& data)
	{
		if (value.HasMember(name.c_str()) == false || value[name.c_str()].IsInt() == false) {

		}
		return false;
	}
}