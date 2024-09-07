#pragma once

namespace nsK2EngineLow
{
	class SpriteRender
	{
	public:
		/// 初期化。
/// </summary>
/// <param name="filePath">ファイルパス。</param>
/// <param name="w">画像の横幅。</param>
/// <param name="h">画像の縦幅。</param>
/// <param name="alphaBlendMode">デフォルトは半透明合成。</param>
		void Init(const char* filePath, const float w, const float h, AlphaBlendMode alphaBlendMode = AlphaBlendMode_Trans);
		void Update();
		void Draw(RenderContext& rc);

		void SetPosition(const Vector3& pos)
		{
			m_position = pos;
		}
		const Vector3& GetPosition() const
		{
			return m_position;
		}
		void SetScale(const Vector3& scale)
		{
			m_scale = scale;
		}
		const Vector3& GetScale() const
		{
			return m_scale;
		}
		void SetRotation(const Quaternion& rot)
		{
			m_rotation = rot;
		}
		const Quaternion& GetRotation() const
		{
			return m_rotation;
		}
		void SetPivot(const Vector2& pivot)
		{
			m_pivot = pivot;
		}
		const Vector2& GetPivot() const
		{
			return m_pivot;
		}
		void SetMulColor(const Vector4& mulColor)
		{
			m_sprite.SetMulColor(mulColor);
		}
		const Vector4& GetMulColor() const
		{
			return m_sprite.GetMulColor();
		}
	private:
		Sprite m_sprite;
		Vector3			m_position = Vector3::Zero;				//座標。
		Quaternion		m_rotation = Quaternion::Identity;		//回転。
		Vector3			m_scale = Vector3::One;					//大きさ。
		Vector2			m_pivot = Sprite::DEFAULT_PIVOT;
	};
}


