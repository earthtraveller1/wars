#ifndef B0F9CEAB_54FF_4726_A816_ADDC48B90C0C
#define B0F9CEAB_54FF_4726_A816_ADDC48B90C0C

#include <math/Matrix4.hpp>
#include <math/Vector3.hpp>

namespace wars
{
    // A class containing common Math utility functions that aren't provided by
    // the C or C++ standard library, which are mainly matrix transformations.
    // The reason that this is a class and not a namespace is because I can't 
    // get namespace friends to work for some reasons. So, yeah.
    class Math
    {
    public:
        // Returns a scale matrix
        template<typename T>
        static math::Matrix4<T> scale(T x, T y, T z)
        {
            math::Matrix4<T> result;
            result.m_matrix[0][0] = x;
            result.m_matrix[1][1] = y;
            result.m_matrix[2][2] = z;
        }
        
        
        template<typename T>
        static math::Matrix4<T> scale(math::Vector3<T> s)
        {
            scale(s.getX(), s.getY(), s.getZ());
        }
        
        
        
        
        // Returns a translation matrix
        template<typename T>
        static math::Matrix4<T> translate(T x, T y, T z)
        {
            math::Matrix4<T> result;
            result.m_matrix[3][0] = x;
            result.m_matrix[3][1] = y;
            result.m_matrix[3][2] = z;
        }
        
        template<typename T>
        static math::Matrix4<T> translate(math::Vector3<T> t)
        {
            translate(t.getX(), t.getY(), t.getZ());
        }
        
        
        
        
        // Returns a rotation matrix
        template<typename T>
        static math::Matrix4<T> rotate(T angle, T uX, T uY, T uZ)
        {
            return
            {
                {
                    {
                        cos(angle) + pow(uX, 2.0) * (1 - cos(angle)),
                        uX * uY * (1 - cos(angle)) - uZ * sin(angle),
                        uX * uZ * (1 - cos(angle)) + uY * sin(angle),
                        0
                    },
                    {
                        uY * uX * (1 - cos(angle)) + uZ * sin(angle),
                        cos(angle) + pow(uY, 2.0) * (1 - cos(angle)),
                        uY * uZ * (1 - cos(angle)) - uX * sin(angle),
                        0
                    },
                    {
                        uZ * uX * (1 - cos(angle)) - uY * cos(angle),
                        uZ * uY * (1 - cos(angle)) + uX * sin(angle),
                        cos(angle) + pow(uZ, 2.0) * (1 - cos(angle)),
                    }
                }
            };
        }
        
        template<typename T>
        static math::Matrix4<T> rotate(T angle, math::Vector3<T> u)
        {
            rotate(angle, u.m_x, u.m_y, u.m_z);
        }
        
        
        
        
        // Returns an orthographic projection matrix
        template<typename T>
        static math::Matrix4<T> ortho(T r, T l, T t, T b, T f, T n)
        {
            math::Matrix4<T> result;
            result.m_matrix[0][0] = 2 / (r - l);
            result.m_matrix[0][3] = -((r + l) / (r - l));
            result.m_matrix[1][1] = 2 / (t - b);
            result.m_matrix[1][3] = -((t + b) / (t - b));
            result.m_matrix[2][2] = -2 / (f - n);
            result.m_matrix[2][3] = -((f + n) / (f - n));
            
            return result;
        }
    };
}

#endif /* B0F9CEAB_54FF_4726_A816_ADDC48B90C0C */
