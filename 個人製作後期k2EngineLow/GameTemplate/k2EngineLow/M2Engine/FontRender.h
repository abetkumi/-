#pragma once

namespace nsK2EngineLow
{
	class FontRender
	{
	public:
		void SetText(const wchar_t* text)
		{
			swprintf_s(m_text, text);
		}
		const wchar_t* GetText() const
		{
			return m_text;
		}
		void SetPosition(float x, float y, float z)
		{
			SetPosition({ x, y, z });
		}
		void SetPosition(const Vector3& position)
		{
			m_position = position;
		}
		const Vector3& GetPosition() const
		{
			return m_position;
		}
		void SetScale(const float scale)
		{
			m_scale = scale;
		}
		const float GetScale() const
		{
			return m_scale;
		}
		void SetColor(float r, float g, float b, float a)
		{
			SetColor({ r, g, b, a });
		}
		void SetColor(const Vector4& color)
		{
			m_color = color;
		}
		const Vector4& GetColor() const
		{
			return m_color;
		}
		void SetRotation(const float rotation)
		{
			m_rotation = rotation;
		}
		const float GetRotation() const
		{
			return m_rotation;
		}
		void SetPivot(float x, float y)
		{
			SetPivot({ x, y });
		}
		void SetPivot(const Vector2& pivot)
		{
			m_pivot = pivot;
		}
		const Vector2& GetPivot() const
		{
			return m_pivot;
		}
		void Draw(RenderContext& rc);
	private:
		Vector3							m_position = Vector3::Zero;			//座標。	
		float							m_scale = 1.0f;						//文字の大きさ。
		Vector4							m_color = g_vec4White;				//文字の色、デフォルトで白。
		float							m_rotation = 0.0f;					//回転。
		Vector2							m_pivot = Sprite::DEFAULT_PIVOT;	//ピボット。
		wchar_t							m_text[255];				//文字。
		Font							m_font;								//フォント。

	};
}


