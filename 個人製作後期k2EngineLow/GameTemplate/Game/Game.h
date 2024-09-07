#pragma once
//#include "Level3DRender/LevelRender.h"

class BackGround;

class Game : public IGameObject
{
public:
	~Game();

	bool Start();
	void Update();
	void Render(RenderContext& rc);
	void Move();
	void AnimationMove();
	void FontDraw(RenderContext& rc,
		wchar_t const* text,
		const Vector2& position,
		const Vector4& color,
		float rotation,
		float scale,
		Vector2 pivot);
	enum EnAnimationClip {
		enAnimClip_Idle,	// 0 : �ҋ@�A�j���[�V�����A
		enAnimClip_Run,		// 1 : ����A�j���[�V�����B
		enAnimClip_Num,		// 2 :�A�j���[�V�����N���b�v�̐��B
	};

	Vector3 m_position;				// ���W
	Quaternion m_rotation;			// ��]
	Vector3 m_scale = g_vec3One;
	ModelInitData initData;
	ModelRender m_modelRender;
	AnimationClip m_animationClipArray[enAnimClip_Num];	// �A�j���[�V�����N���b�v
	Animation m_animation;
	Skeleton m_skeleton;

	SpriteRender m_spriteRender;
	FontRender m_fontRender;

//private:
	BackGround* m_backGround;
};

