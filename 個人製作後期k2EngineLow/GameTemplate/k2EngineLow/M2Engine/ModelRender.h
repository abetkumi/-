#pragma once

namespace nsK2EngineLow 
{
	class ModelRender
	{
	public:
		bool Start();
		void Update();
		void Draw(RenderContext&rc);
		void Init(const char* filePath,
			AnimationClip* animationClips = nullptr,
			int numAnimationClips = 0);
		//�`�揈��
		void SetPosition(const Vector3& pos)
		{
			m_position = pos;
		}
		void SetPosition(float x, float y, float z)
		{
			SetPosition({ x, y, z });
		}
		void SetRotation(const Quaternion& rotation)
		{
			m_rotation = rotation;
		}
		void SetScale(const Vector3& scale)
		{
			m_scale = scale;
		}
		void SetScale(float x, float y, float z)
		{
			SetScale({ x, y, z });
		}
		//�A�j���[�V����
		void PlayAnimation(int animNo, float interpolateTime = 0.0f)
		{
			m_animation.Play(animNo, interpolateTime);
		}
		// �X�P���g����������
		void InitSkeleton(const char* filePath);
		/// <summary>
		/// �A�j���[�V�����̏������B
		/// </summary>
		/// <param name="animationClips">�A�j���[�V�����N���b�v�B</param>
		/// <param name="numAnimationClips">�A�j���[�V�����N���b�v�̐��B</param>
		/// <param name="enModelUpAxis">���f���̏�����B</param>
		void InitAnimation(AnimationClip* animationClips,
			int numAnimationClips);

		//���f���̎擾
		Model& GetModel()
		{
			if (m_renderToGBufferModel.IsInited()) {
				return m_renderToGBufferModel;
			}
			else if (m_forwardRenderModel.IsInited()) {
				return m_forwardRenderModel;
			}
			else if (m_translucentModel.IsInited())
			{
				return m_translucentModel;
			}
			// �����܂ŗ���̂͂��������B
			return m_zprepassModel;
		}

	private:
		AnimationClip* m_animationClips = nullptr;			// �A�j���[�V�����N���b�v�B
		int	m_numAnimationClips = 0;
		Vector3 m_position;				// ���W
		Quaternion m_rotation;			// ��]
		Vector3 m_scale = g_vec3One;
		ModelInitData initData;
		Model m_model;
		Animation m_animation;
		Skeleton m_skeleton;

		Model		m_zprepassModel;					// ZPrepass�ŕ`�悳��郂�f��
		Model		m_forwardRenderModel;				// �t�H���[�h�����_�����O�̕`��p�X�ŕ`�悳��郂�f��
		Model		m_translucentModel;					// ���������f���B
		Model		m_renderToGBufferModel;
	};
}