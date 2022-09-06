#include "Model.h"
#include "Core/File.h"
#include "Core/Logger.h"
#include "Math/Transform.h"
#include "Math/MathUtils.h"

#include <cstdarg>
#include <iostream>
#include <sstream>

namespace JREngine
{

	Model::Model(const std::string& filename)
	{
		Load(filename);
		m_radius = CalculateRadius();
	}

	bool Model::Create(const std::string filename, ...) {
		if (!Load(filename)) {
			LOG("Error could not create model %s", filename.c_str());
			return false;
		}
		va_list args;
		va_start(args, filename);
		Renderer& renderer = va_arg(args, Renderer);
		va_end(args);
		//return Create(filename, renderer);
		return true;
	}

	void Model::Draw(Renderer& renderer, const Vector2& position, float angle, const Vector2& scale){

		for (size_t i = 0; i < m_points.size() - 1; i++)
		{
			Vector2 p1 = Vector2::Rotate((m_points[i] * scale), angle) + position;
			Vector2 p2 = Vector2::Rotate((m_points[i + 1] * scale), angle) + position;
			renderer.DrawLine(p1, p2, m_color);
		}
	}

	void Model::Draw(Renderer& renderer, const Transform& transform){
		/*if (m_points.size() == 0) {
			return;
		}*/

		Matrix3x3 mx = transform.matrix;

		for (size_t i = 0; i < m_points.size() - 1; i++)
		{
			/*Vector2 p1 = Vector2::Rotate((points_[i] * transform.scale), Math::DegToRad(transform.rotation)) + transform.position;
			Vector2 p2 = Vector2::Rotate((points_[i + 1] * transform.scale), Math::DegToRad(transform.rotation)) + transform.position;*/
			Vector2 p1 = mx * m_points[i];
			Vector2 p2 = mx * m_points[i + 1];
			renderer.DrawLine(p1, p2, m_color);
		}
	}

	bool Model::Load(const std::string& filename){
		std::string buffer;
		//JREngine::ReadFile(filename, buffer);
		if (!JREngine::ReadFile(filename, buffer)) {
			LOG("Error could not load model %s", filename.c_str());
			return false;
		}

		std::istringstream stream(buffer);
		stream >> m_color;

		std::string line;
		std::getline(stream, line);
		size_t numPoints = std::stoi(line);

		for (size_t i = 0; i < numPoints; i++)
		{
			Vector2 point;

			stream >> point;
			m_points.push_back(point);
		}

		return true;
	}

	float Model::CalculateRadius()
	{
		float radius = 0;

		for (auto& point : m_points) {
			if (point.Length() > radius) {
				radius = point.Length();
			}
		}

		return radius;
	}
}