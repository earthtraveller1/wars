#ifndef C80D0B7B_66A3_4425_A546_7A50085B2B3D
#define C80D0B7B_66A3_4425_A546_7A50085B2B3D

#include <pch.hpp>

namespace wars::math
{
    // A class to represent a vector with 2 members. Currently supports all
    // vector operations.
    template<typename T>
    class Vector2
    {
    public:
        Vector2(T x = 0, T y = 0): m_x(x), m_y(y) {}
        
        // Scalar operations
        // ===============================================
        Vector2<T> operator+(T b) { return { m_x + b, m_y + b }; }
        Vector2<T> operator-(T b) { return { m_x - b, m_y - b }; }
        Vector2<T> operator*(T b) { return { m_x * b, m_y * b }; }
        Vector2<T> operator/(T b) { return { m_x / b, m_y / b }; }
        
        Vector2<T>& operator+=(T b)
        {
            m_x += b;
            m_y += b;
            return *this;
        }
        Vector2<T>& operator-=(T b)
        {
            m_x -= b;
            m_y -= b;
            return *this;
        }
        Vector2<T>& operator*=(T b)
        {
            m_x *= b;
            m_y *= b;
            return *this;
        }
        Vector2<T>& operator/=(T b)
        {
            m_x /= b;
            m_y /= b;
            return *this;
        }
        
        
        
        
        // Vector-vector operations
        // ===============================================
        Vector2<T> operator+(Vector2<T> b) 
        { return { m_x + b.m_x, m_y + b.m_y }; }
        Vector2<T> operator-(Vector2<T> b) 
        { return { m_x - b.m_x, m_y - b.m_y }; }
        
        Vector2<T>& operator+=(Vector2<T> b) 
        {
            m_x += b.m_x;
            m_y += b.m_y;
            return *this;
        }
        Vector2<T>& operator-=(Vector2<T> b) 
        {
            m_x -= b.m_x;
            m_y -= b.m_y;
            return *this;
        }
        
        // Multiplication operations
        // ===============================================
        
        // Dot Product
        T dot(Vector2<T>& b)
        {
            T x = m_x * b.m_x;
            T y = m_y * b.m_y;
            return x + y;
        }
        
        
        
        
        // Negation
        Vector2<T>& operator-() { return { -m_x, -m_y }; }
        
        // Obtain the length of the vector
        T length() { return sqrt(pow(m_x, 2.0) + pow(m_y, 2.0)); }
        
        // Normalize this vector
        void normalize() { operator/=(length()); }
        
        
        
        
        // Getters
        // ================================================
        T getX() { return m_x; }
        T getY() { return m_y; }
        
        
        
        
        // Setters
        void setX(T x) { m_x = x; }
        void setY(T y) { m_y = y; }

        // The actual members.
        T m_x;
        T m_y;
    };
}

#endif /* C80D0B7B_66A3_4425_A546_7A50085B2B3D */
