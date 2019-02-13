#ifndef _ENGINE_PRIMITIVE_RAY_H_
#define _ENGINE_PRIMITIVE_RAY_H_

#include <CppUtil/Engine/Primitive.h>
#include <glm/vec3.hpp>
#include <glm/mat4x4.hpp>

namespace CppUtil {
	namespace Engine {
		class Ray : public Primitive {
			ELE_SETUP(Ray)
		public:
			Ray(const glm::vec3 & origin, const glm::vec3 dir, float tMin = 0.001f, float tMax = FLT_MAX)
				: origin(origin), dir(dir), invDir(1.0f/dir.x, 1.0f/dir.y, 1.0f/dir.z), tMin(tMin), tMax(tMax) { }

			const glm::vec3 GetOrigin() const { return origin; }
			const glm::vec3 GetDir() const { return dir; }
			const glm::vec3 GetInvDir() const { return invDir; }
			float GetTMin() const { return tMin; }
			float GetTMax() const { return tMax; }
			void SetTMax(float tMax) { this->tMax = tMax; }
			const glm::vec3 EndPos() const { return At(tMax); }

			void Transform(const glm::mat4 & mat);

			const glm::vec3 At(float t) const { return origin + t * dir; }
		private:
			glm::vec3 origin;
			glm::vec3 dir;
			glm::vec3 invDir;
			float tMin;
			float tMax;
		};
	}
}

#endif//!_ENGINE_PRIMITIVE_RAY_H_