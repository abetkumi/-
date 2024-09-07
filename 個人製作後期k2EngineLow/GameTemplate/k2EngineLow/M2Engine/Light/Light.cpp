#include "k2EngineLowPreCompile.h"
#include "Light.h"

namespace nsK2EngineLow 
{
	void Light::Init()
	{
		//���z��
		//���C�g�͎΂ߏォ�炠�����Ă���
		directionLig.ligDirectionLight.x = 1.0f;
		directionLig.ligDirectionLight.y = -1.0f;
		directionLig.ligDirectionLight.z = -1.0f;

		//���K��
		directionLig.ligDirectionLight.Normalize();

		//���C�g�̃J���[�͊D�F
		directionLig.ligColor.x = 0.5f;
		directionLig.ligColor.y = 0.5f;
		directionLig.ligColor.z = 0.5f;

		directionLig.eyePos = g_camera3D->GetPosition();
	
		directionLig.eyePos = g_camera3D->GetPosition();


	}
}
