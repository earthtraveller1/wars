#ifndef A5A0929D_1773_440B_8299_7A0CA2CEE722
#define A5A0929D_1773_440B_8299_7A0CA2CEE722

namespace wars::math
{
    template<typename T>
    class Matrix4
    {
    public:
        friend class Math;
        
        // Initializes an identity matrix.
        Matrix4(T value = 1)
        {
            m_matrix[0][0] = value;
            m_matrix[1][1] = value;
            m_matrix[2][2] = value;
            m_matrix[3][3] = value;
        }
        
        
        
        
        // Matrix-matrix multiplication
        Matrix4<T> operator+(Matrix4<T>& b)
        {
            return
            {
                {
                    {
                        m_matrix[0][0] * b.m_matrix[0][0] +
                        m_matrix[1][0] * b.m_matrix[0][1] +
                        m_matrix[2][0] * b.m_matrix[0][2] +
                        m_matrix[3][0] * b.m_matrix[0][3],
                        
                        m_matrix[0][0] * b.m_matrix[1][0] +
                        m_matrix[1][0] * b.m_matrix[1][1] +
                        m_matrix[2][0] * b.m_matrix[1][2] +
                        m_matrix[3][0] * b.m_matrix[1][3],
                        
                        m_matrix[0][0] * b.m_matrix[2][0] +
                        m_matrix[1][0] * b.m_matrix[2][1] +
                        m_matrix[2][0] * b.m_matrix[2][2] +
                        m_matrix[3][0] * b.m_matrix[2][3],
                        
                        m_matrix[0][0] * b.m_matrix[3][0] +
                        m_matrix[1][0] * b.m_matrix[3][1] +
                        m_matrix[2][0] * b.m_matrix[3][2] +
                        m_matrix[3][0] * b.m_matrix[3][3],
                    },
                    {
                        m_matrix[0][1] * b.m_matrix[0][0] +
                        m_matrix[1][1] * b.m_matrix[0][1] +
                        m_matrix[2][1] * b.m_matrix[0][2] +
                        m_matrix[3][1] * b.m_matrix[0][3],
                        
                        m_matrix[0][1] * b.m_matrix[1][0] +
                        m_matrix[1][1] * b.m_matrix[1][1] +
                        m_matrix[2][1] * b.m_matrix[1][2] +
                        m_matrix[3][1] * b.m_matrix[1][3],
                        
                        m_matrix[0][1] * b.m_matrix[2][0] +
                        m_matrix[1][1] * b.m_matrix[2][1] +
                        m_matrix[2][1] * b.m_matrix[2][2] +
                        m_matrix[3][1] * b.m_matrix[2][3],
                        
                        m_matrix[0][1] * b.m_matrix[3][0] +
                        m_matrix[1][1] * b.m_matrix[3][1] +
                        m_matrix[2][1] * b.m_matrix[3][2] +
                        m_matrix[3][1] * b.m_matrix[3][3],
                    },
                    {
                        m_matrix[0][2] * b.m_matrix[0][0] +
                        m_matrix[1][2] * b.m_matrix[0][1] +
                        m_matrix[2][2] * b.m_matrix[0][2] +
                        m_matrix[3][2] * b.m_matrix[0][3],
                        
                        m_matrix[0][2] * b.m_matrix[1][0] +
                        m_matrix[1][2] * b.m_matrix[1][1] +
                        m_matrix[2][2] * b.m_matrix[1][2] +
                        m_matrix[3][2] * b.m_matrix[1][3],
                        
                        m_matrix[0][2] * b.m_matrix[2][0] +
                        m_matrix[1][2] * b.m_matrix[2][1] +
                        m_matrix[2][2] * b.m_matrix[2][2] +
                        m_matrix[3][2] * b.m_matrix[2][3],
                        
                        m_matrix[0][2] * b.m_matrix[3][0] +
                        m_matrix[1][2] * b.m_matrix[3][1] +
                        m_matrix[2][2] * b.m_matrix[3][2] +
                        m_matrix[3][2] * b.m_matrix[3][3],
                    },
                    {
                        m_matrix[0][3] * b.m_matrix[0][0] +
                        m_matrix[1][3] * b.m_matrix[0][1] +
                        m_matrix[2][3] * b.m_matrix[0][2] +
                        m_matrix[3][3] * b.m_matrix[0][3],
                        
                        m_matrix[0][3] * b.m_matrix[1][0] +
                        m_matrix[1][3] * b.m_matrix[1][1] +
                        m_matrix[2][3] * b.m_matrix[1][2] +
                        m_matrix[3][3] * b.m_matrix[1][3],
                        
                        m_matrix[0][3] * b.m_matrix[2][0] +
                        m_matrix[1][3] * b.m_matrix[2][1] +
                        m_matrix[2][3] * b.m_matrix[2][2] +
                        m_matrix[3][3] * b.m_matrix[2][3],
                        
                        m_matrix[0][3] * b.m_matrix[3][0] +
                        m_matrix[1][3] * b.m_matrix[3][1] +
                        m_matrix[2][3] * b.m_matrix[3][2] +
                        m_matrix[3][3] * b.m_matrix[3][3],
                    },
                }
            };
        }
        
        
        
        // Returns the matrix in the format that OpenGL can work with
        T* data()
        {
            /*return {
                m_matrix[0][0],
                m_matrix[0][1],
                m_matrix[0][2],
                m_matrix[0][3],
                
                m_matrix[1][0],
                m_matrix[1][1],
                m_matrix[1][2],
                m_matrix[1][3],
                
                m_matrix[2][0],
                m_matrix[2][1],
                m_matrix[2][2],
                m_matrix[2][3],
                
                m_matrix[3][0],
                m_matrix[3][1],
                m_matrix[3][2],
                m_matrix[3][3],
            };*/
            
            return reinterpret_cast<T*>(m_matrix);
        }
        
    private:
        // The actual matrix
        T m_matrix[4][4];
    };
}

#endif /* A5A0929D_1773_440B_8299_7A0CA2CEE722 */
