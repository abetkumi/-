#include "stdafx.h"
#include "Game.h"
#include "BackGround.h"

Game::~Game()
{
	//DeleteGO(m_backGround);
}

bool Game::Start()
{
	//m_backGround = NewGO<BackGround>(0,"BackGround");
	//g_camera3D->SetPosition(0.0f, 0.0f, 0.0f);
	
	//アニメーションクリップをロードする。
	m_animationClipArray[enAnimClip_Idle].Load("Assets/animData/idle.tka");
	m_animationClipArray[enAnimClip_Idle].SetLoopFlag(true);
	m_animationClipArray[enAnimClip_Run].Load("Assets/animData/walk.tka");
	m_animationClipArray[enAnimClip_Run].SetLoopFlag(true);
	
	m_modelRender.Init("Assets/modelData/unityChan.tkm", m_animationClipArray, enAnimClip_Num);
	//DDSファイル(画像データ)のファイルパスを指定する。
	m_spriteRender.Init("Assets/Image/sample.dds",512.0f,512.0f);
	m_spriteRender.SetPosition({ 600.0f, 200.0f, 0.0f });
	m_fontRender.SetText(L"Hello");
	m_fontRender.SetPosition({ -600.0f,-200.0f,0.0f });
	m_fontRender.SetColor(g_vec4White);



	return true;
}

void Game::Update()
{
	Move();
	AnimationMove();

	m_modelRender.Update();
	m_spriteRender.Update();
}

void Game::Move()
{
	// 左スティック(キーボード：WASD)で平行移動。
	m_position.x += g_pad[0]->GetLStickXF();
	m_position.y += g_pad[0]->GetLStickYF();

	// 右スティック(キーボード：上下左右)で回転。
	m_rotation.AddRotationY(g_pad[0]->GetRStickXF() * 0.05f);
	m_rotation.AddRotationX(g_pad[0]->GetRStickYF() * 0.05f);

	// 上下左右キー(キーボード：2, 4, 6, 8)で拡大
	if (g_pad[0]->IsPress(enButtonUp)) {
		m_scale.y += 0.02f;
	}
	if (g_pad[0]->IsPress(enButtonDown)) {
		m_scale.y -= 0.02f;
	}
	if (g_pad[0]->IsPress(enButtonRight)) {
		m_scale.x += 0.02f;
	}
	if (g_pad[0]->IsPress(enButtonLeft)) {
		m_scale.x -= 0.02f;
	}

	m_modelRender.SetPosition(m_position);
	m_modelRender.SetRotation(m_rotation);
	m_modelRender.SetScale(m_scale);
}

void Game::AnimationMove()
{
	// アニメーションの切り替え。
	if (g_pad[0]->IsPress(enButtonA)) {
		m_modelRender.PlayAnimation(enAnimClip_Idle, 0.2f);
	}
	if (g_pad[0]->IsPress(enButtonB)) {
		m_modelRender.PlayAnimation(enAnimClip_Run, 0.2f);
	}
}

void Game::Render(RenderContext& rc)
{
	m_modelRender.Draw(rc);
	m_spriteRender.Draw(rc);
	m_fontRender.Draw(rc);
}

