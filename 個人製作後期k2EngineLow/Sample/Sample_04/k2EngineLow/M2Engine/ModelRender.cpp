#include "k2EngineLowPreCompile.h"
#include "ModelRender.h"

namespace nsK2EngineLow
{

	bool ModelRender::Start()
	{
		
		return true;
	}



	void ModelRender::Init(const char* filePath, 
		AnimationClip* animationClips, 
		int numAnimationClips)
	{
		//tkm�t�@�C���̃t�@�C���p�X���w�肷��B
		initData.m_tkmFilePath = filePath;
		//�V�F�[�_�[�t�@�C���̃t�@�C���p�X���w�肷��B
		initData.m_fxFilePath = "Assets/shader/model.fx";
		//�X�P���g�������[�h�B
		InitSkeleton(filePath);
		// �A�j���[�V�������������B
		InitAnimation(animationClips, numAnimationClips);
		//�m���X�L�����b�V���p�̒��_�V�F�[�_�[�̃G���g���[�|�C���g���w�肷��B
		initData.m_vsEntryPointFunc = "VSMain";
		//�X�L�����b�V���p�̒��_�V�F�[�_�[�̃G���g���[�|�C���g���w��B
		initData.m_vsSkinEntryPointFunc = "VSSkinMain";
		//�X�P���g�����w�肷��B
		initData.m_skeleton = &m_skeleton;
		
		//���f���̏�������w�肷��B
		//3dsMax�ł̓f�t�H���gZ�A�b�v�ɂȂ��Ă��邪�A
		//���j�e�B�����̓A�j���[�V������Y�A�b�v�ɕύX����Ă���B
		initData.m_modelUpAxis = enModelUpAxisY;
		// 
		// ���[���h�s����X�V�B
		m_model.UpdateWorldMatrix(m_position, m_rotation, m_scale);

		//�쐬�����������f�[�^�����ƂɃ��f��������������A
		m_model.Init(initData);

	}

	void ModelRender::InitSkeleton(const char* filePath)
	{
		//�X�P���g���̃f�[�^��ǂݍ��݁B
		std::string skeletonFilePath = filePath;
		int pos = (int)skeletonFilePath.find(".tkm");
		skeletonFilePath.replace(pos, 4, ".tks");
		m_skeleton.Init(skeletonFilePath.c_str());
	}

	void ModelRender::InitAnimation(AnimationClip* animationClips, int numAnimationClips)
	{
		m_animationClips = animationClips;
		m_numAnimationClips = numAnimationClips;
		if (m_animationClips != nullptr) {
			m_animation.Init(m_skeleton,
				m_animationClips,
				numAnimationClips);
		}
	}

	void ModelRender::Update()
	{
		//�X�P���g�����X�V�B
		m_skeleton.Update(m_model.GetWorldMatrix());

		//�A�j���[�V������i�߂�B
		m_animation.Progress(g_gameTime->GetFrameDeltaTime());
		// ���[���h�s����X�V�B
		m_model.UpdateWorldMatrix(m_position, m_rotation, m_scale);


	}
	void ModelRender::Draw(RenderContext&rc)
	{
		m_model.Draw(rc);
	}
}