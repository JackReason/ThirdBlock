
#include <iostream>
#include <string>



class Matrix
{
public:
    Matrix(const std::string& name, int x = 3, int y = 3) :rows(x), cols(y)
    {
        for (int i = 0; i < rows; i++)
        {
            Massive[i] = new int[cols];
        }

        for (int i = 0; i < rows; i++)
        { 
            for (int j = 0; j < cols; j++)
            {
                Massive[i][j] = rand()%99;
            }
        }

        pName = new std::string(name);
    }
    Matrix(const Matrix& Original)
    {
        std::cout << "Making a copy, not a crap like Matrix 4" << "\n\n";

        pName = new std::string(*(Original.pName));
        rows = Original.rows;
        cols = Original.cols;
        Massive = new int* [Original.rows];
        for (int i = 0; i < Original.rows; i++)
        {
            Massive[i] = new int[Original.cols];
        }
        for (int i = 0; i < Original.rows; i++)
        {
            for (int j = 0; j <Original.cols; j++)
            {
                Massive[i][j] = Original.Massive[i][j];
            }
        }
    }

    ~Matrix()
    {
        std::cout << "calling out the Destructors, both sisters Wachowski" << "\n";
        for (int i = 0; i < rows; i++)
        {
            delete[] Massive[i];
                
        }
        delete[] Massive;
        delete pName;
    }

    void PrintMatrix()
    {
        std::cout << "See the " << *pName << "\n\n";
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                std::cout << Massive[i][j] << "\t";
            }
            std::cout << "\n";
        }
        std::cout << "\n\n";
    }

private:
    std::string* pName;
    int rows;
    int cols;
    int** Massive = new int* [rows];
    
};

void CopyMakerFunction(Matrix M)
{
    std::cout << "Copied Ok and still better then Matrix 4! Watch this : " << "\n\n";
    M.PrintMatrix();
}

// Main programme

int main()
{
    Matrix Neo("Matrix Reloaded", 10, 10);

    Neo.PrintMatrix();

    CopyMakerFunction(Neo);

    return 0;
}

//class Vector
//{
//public:
//    Vector(float x = 0, float y = 0, float z = 0)
//    {
//        this->x = x;
//        this->y = y;
//        this->z = z;
//
//    }
//
// 
//    float GetX() const
//    {
//        return this->x;
//    }
//     float GetY() const
//    {
//        return this->y;
//    }
//     float GetZ() const
//    {
//        return this->z;
//    }
//
//     void SetX(float x) 
//     {
//         this->x = x;
//     }
//     void SetY(float y)
//     {
//         this->y = y;
//     }
//     void SetZ(float z)
//     {
//         this->z = z;
//     }
//
//    friend Vector operator+(const Vector& a, const Vector& b);
//
//    friend std::ostream& operator<<(std::ostream& os, const Vector& v);
//
//    friend std::istream& operator>>(std::istream& is, Vector& v);
//
//    friend bool operator>(const Vector& a, const Vector& b);
//
//    float operator[](int index)
//    {
//        switch (index)
//        {
//        case 0:
//            return x;
//            break;
//        case 1:
//            return y;
//            break;
//        case 2:
//            return z;
//            break;
//        default:
//            std::cout << "index error";
//        }
//
//       
//    }
//
//    Vector operator -(const Vector& a)
//    {
//        return Vector(this->x - a.x, this->y - a.y, this->z - a.z);
//    }
//
//    operator float()
//    {
//        return sqrt(x * x + y * y + z * z);
//    }
//private:
//    float x;
//    float y;
//    float z;
//};
//
//
//Vector operator+(const Vector& a, const Vector& b)
//{
//    return Vector(a.x + b.x, a.y + b.y, a.z + b.z);
//}
//
//std::ostream& operator<<(std::ostream& os, const Vector& v)
//{
//    os << " " << v.x << " " << v.y << " " << v.z << "\n";
//    return os;
//}
//
//std::istream& operator>>(std::istream& is, Vector& v)
//{
//    is >> v.x >> v.y >> v.z;
//    return is;
//}
//bool operator>(const Vector& a, const Vector& b)
//{
//    if (sqrt(a.x * a.x + a.y * a.y + a.z * a.z) > sqrt(b.x * b.x + b.y* b.y + b.z * b.z))
//        return true;
//
//    else return false ;
//}
//
//Vector operator*(const Vector& a, int b)
//{
//    Vector temp;
//    temp.SetX(a.GetX() * b);
//    temp.SetY(a.GetY() * b);
//    temp.SetZ(a.GetZ() * b);
//    return temp;
//}
//
//// main programme
//
//int main()
//{
//   
//    Vector v1(0, 1, 2);
//    Vector v2(3, 4, 5);
//    Vector v3(5, 5, 5);
//
//    std::cout << "v1 = " << v1 << "\n";
//    std::cout << "v2 = " << v2 << "\n";
//    std::cout << "v3 = " << v3 << "\n";
//
//    std::cout << "v1+v2 = " << v1 + v2 << "\n";
//
//    std::cout << "Convert to float = " << float(v3) << "\n\n";
//
//    std::cout <<"v2 * 10 = " << v2 * 10 << "\n";
//
//    std::cout << "v2 - Vec" << v3 - v2 << "\n";
//
//    std::cout << "create your own vector = ";
//
//    Vector MyVector;
//
//    std::cin >> MyVector;
//
//    std::cout<< "Your Vector is = " << MyVector;
//
//    
//}

