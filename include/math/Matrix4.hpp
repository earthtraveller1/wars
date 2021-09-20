#ifndef A5A0929D_1773_440B_8299_7A0CA2CEE722
#define A5A0929D_1773_440B_8299_7A0CA2CEE722

namespace wars::math
{
    template<typename T>
    class Matrix4
    {
    public:
        // Initializes an identity matrix.
        Matrix4(T value = 1)
        {
            m_matrix[(1 * 1)] = value;
            m_matrix[(2 * 2)] = value;
            m_matrix[(3 * 3)] = value;
            m_matrix[(4 * 4)] = value;
        }
        
    private:
        // The actual matrix
        T m_matrix[16];
    };
}

#endif /* A5A0929D_1773_440B_8299_7A0CA2CEE722 */
