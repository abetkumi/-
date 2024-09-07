#include "k2EngineLowPreCompile.h"
#include "Light.h"

namespace nsK2EngineLow 
{
	void Light::Init()
	{
		//太陽光
		//ライトは斜め上からあたっている
		directionLig.ligDirectionLight.x = 1.0f;
		directionLig.ligDirectionLight.y = -1.0f;
		directionLig.ligDirectionLight.z = -1.0f;

		//正規化
		directionLig.ligDirectionLight.Normalize();

		//ライトのカラーは灰色
		directionLig.ligColor.x = 0.5f;
		directionLig.ligColor.y = 0.5f;
		directionLig.ligColor.z = 0.5f;

		directionLig.eyePos = g_camera3D->GetPosition();
	
		directionLig.eyePos = g_camera3D->GetPosition();


	}
}
