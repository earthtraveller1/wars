#ifndef CDE1A3B8_31A6_4931_9014_32CD68A86CB8
#define CDE1A3B8_31A6_4931_9014_32CD68A86CB8

#include <pch.hpp>

namespace wars::math
{
    // A class that represents a 3 component vector
    template<typename T>
    class Vector3
    {
    public:
        Vector3(T x = 0, T y = 0, T z = 0): m_x(x), m_y(y), m_z(z) {}
        
        // Scalar operations
        // ===============================================
        Vector3<T> operator+(T b) { return { m_x + b, m_y + b, m_z + b }; }
        Vector3<T> operator-(T b) { return { m_x - b, m_y - b, m_z - b }; }
        Vector3<T> operator*(T b) { return { m_x * b, m_y * b, m_z * b }; }
        Vector3<T> operator/(T b) { return { m_x / b, m_y / b, m_z / b }; }
        
        Vector3<T>& operator+=(T b)
        {
            m_x += b;
            m_y += b;
            m_z += b;
            return *this;
        }
        Vector3<T>& operator-=(T b)
        {
            m_x -= b;
            m_y -= b;
            m_z -= b;
            return *this;
        }
        Vector3<T>& operator*=(T b)
        {
            m_x *= b;
            m_y *= b;
            m_z *= b;
            return *this;
        }
        Vector3<T>& operator/=(T b)
        {
            m_x /= b;
            m_y /= b;
            m_z /= b;
            return *this;
        }
        
        
        
        
        // Vector-vector operations
        // ===============================================
        Vector3<T> operator+(Vector3<T> b) 
        { return { m_x + b.m_x, m_y + b.m_y, m_z + b.m_z }; }
        Vector3<T> operator-(Vector3<T> b) 
        { return { m_x - b.m_x, m_y - b.m_y, m_z - b.m_z }; }
        
        Vector3<T>& operator+=(Vector3<T> b) 
        {
            m_x += b.m_x;
            m_y += b.m_y;
            m_z += b.m_z;
            return *this;
        }
        Vector3<T>& operator-=(Vector3<T> b) 
        {
            m_x -= b.m_x;
            m_y -= b.m_y;
            m_z += b.m_z;
            return *this;
        }
        
        // Multiplication operations
        // ===============================================
        
        // Dot Product
        T dot(Vector3<T>& b)
        {
            T x = m_x * b.m_x;
            T y = m_y * b.m_y;
            T z = m_z * b.m_z;
            return x + y + z;
        }
        
        
        
        
        // Negation
        Vector3<T>& operator-() { return { -m_x, -m_y, -m_z }; }
        
        // Obtain the length of the vector
        T length() { return sqrt(pow(m_x, 2.0) + pow(m_y, 2.0) + pow(m_y, 2.0)); }
        
        // Normalize this vector
        void normalize() { operator/=(length()); }
        
        
        
        
        // Getters
        // ================================================
        T getX() { return m_x; }
        T getY() { return m_y; }
        T getZ() { return m_z; }
        
        
        
        
        // Setters
        void setX(T x) { m_x = x; }
        void setY(T y) { m_y = y; }
        void setZ(T z) { m_z = z; }

        // The vector components
        T m_x;
        T m_y;
        T m_z;
    };
}

#endif /* CDE1A3B8_31A6_4931_9014_32CD68A86CB8 */
