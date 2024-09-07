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
		//描画処理
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
		//アニメーション
		void PlayAnimation(int animNo, float interpolateTime = 0.0f)
		{
			m_animation.Play(animNo, interpolateTime);
		}
		// スケルトンを初期化
		void InitSkeleton(const char* filePath);
		/// <summary>
		/// アニメーションの初期化。
		/// </summary>
		/// <param name="animationClips">アニメーションクリップ。</param>
		/// <param name="numAnimationClips">アニメーションクリップの数。</param>
		/// <param name="enModelUpAxis">モデルの上向き。</param>
		void InitAnimation(AnimationClip* animationClips,
			int numAnimationClips);

		//モデルの取得
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
			// ここまで来るのはおかしい。
			return m_zprepassModel;
		}

	private:
		AnimationClip* m_animationClips = nullptr;			// アニメーションクリップ。
		int	m_numAnimationClips = 0;
		Vector3 m_position;				// 座標
		Quaternion m_rotation;			// 回転
		Vector3 m_scale = g_vec3One;
		ModelInitData initData;
		Model m_model;
		Animation m_animation;
		Skeleton m_skeleton;

		Model		m_zprepassModel;					// ZPrepassで描画されるモデル
		Model		m_forwardRenderModel;				// フォワードレンダリングの描画パスで描画されるモデル
		Model		m_translucentModel;					// 半透明モデル。
		Model		m_renderToGBufferModel;
	};
}