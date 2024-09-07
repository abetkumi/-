#pragma once

namespace nsK2EngineLow
{
	struct DirectionLight
	{
		Vector3 ligDirectionLight;
		float pad;
		Vector3 ligColor;
		Vector3 eyePos;

	};

	struct PointLight
	{
		Vector3 ptPosition;
		float pad2;
		Vector3 ptColor;
		float Range;
	};

	class Light : public Noncopyable
	{
	public:
		void Init();
		DirectionLight directionLig;
		Vector3 ambinetLight;
	};
}

