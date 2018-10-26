#pragma once
template<typename T>
class Vec2_
{
public:

	Vec2_(T x_in, T y_in)
		:
		x(x_in),
		y(y_in)
	{
	}

	Vec2_(const Vec2_<float>& src)
		:
		x( (T)src.x),
		y( (T)src.y)
	{}

	Vec2_ operator+(const Vec2_<T>& rhs) const
	{
		return Vec2_<T>(x + rhs.x, y + rhs.y);
	}

	Vec2_& operator+=(const Vec2_<T>& rhs)
	{
		return *this = *this + rhs;
	}

	Vec2_ operator*(T rhs) const
	{
		return Vec2_<T>(x * rhs, y * rhs);
	}

	Vec2_& operator*=(T rhs)
	{
		return *this = *this * rhs;
	}

	Vec2_ operator-(const Vec2_<T>& rhs) const
	{
		return Vec2_<T>(x - rhs.x, y - rhs.y);
	}

	Vec2_& operator-=(const Vec2_<T>& rhs)
	{
		return *this = *this - rhs;
	}

	T GetLength() const
	{
		return (T)std::sqrt(GetLengthSq());
	}

	T GetLengthSq() const
	{
		return (T)(x * x + y * y);
	}

	Vec2_& Normalize()
	{
		return *this = GetNormalized();
	}

	Vec2_ GetNormalized() const
	{
		const T len = GetLength();
		if (len != 0.0f)
		{
			return (T)(*this * (1.0f / len));
		}
		return *this;
	}

	
public:
	T x;
	T y;
};

typedef Vec2_<float> Vec2;
typedef Vec2_<int> Vei2;
