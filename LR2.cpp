#include <iostream>
#include<math.h>


class Array
{
public:
    typedef signed int UINT;
    Array(UINT size, double* mas) throw();
    Array(UINT size, double k = 0) throw();
    Array(const double* begin, const double* end)throw();
    void Swap(Array& other);
    Array(const Array& a)throw(); 
    ~Array()throw(); 
    Array& operator=(const Array& rhs); 
    double& operator()(UINT index);
    const double& operator()(UINT index) const;
    double& operator[](UINT index) throw();

    const double& operator[](UINT index) const throw();
    Array& operator+=(const double& rhs);
    Array& operator+=(const Array& rhs);
    Array& operator/=(const Array& rhs);
    Array& operator-=(const Array& rhs);
    Array& operator*=(const double& rhs);
    Array& operator/=(const double& rhs);
    Array& operator-=(const double& rhs);
    UINT size() const { return size_array; };
    friend std::ostream& operator <<(std::ostream& to, const Array& a);
    friend std::istream& operator >>(std::istream& to, Array& a);
    friend Array operator+(const Array& a, const double& b);
    double norm()
    {
        double norma = 0;
        for (UINT i = 0; i < size_array; ++i) norma += data[i] * data[i];
        return pow(norma, 0.5);
    }
    Array& operator*=(const Array& rhs);
    Array& Sort(int napr)
    {
        int i, j;
        double prom;
        for (i = 0; i < size() - 1; i++)
            for (j = 0; j < size() - i - 1; j++)
            {
                if (napr == 0)
                {
                    if (data[j] > data[j + 1])
                    {
                        prom = data[j];
                        data[j] = data[j + 1];
                        data[j + 1] = prom;
                    };
                };
                if (napr == 1)
                {
                    if (data[j] < data[j + 1])
                    {
                        prom = data[j];
                        data[j] = data[j + 1];
                        data[j + 1] = prom;
                    };
                };
            };
        return *this;
    };

    double summa()
    {
        double prom = 0;
        for (UINT i = 0; i < size_array; ++i)prom += data[i];
        return prom;
    };
    double srar()
    {
        double prom = 0;
        for (UINT i = 0; i < size_array; ++i)prom += data[i];
        return prom / size_array;
    };
    double min()
    {
        double prom = data[0];
        for (UINT i = 1; i < size_array; ++i)if (prom > data[i])prom = data[i];
        return prom;
    };
    double max()
    {
        double prom = data[0];
        for (UINT i = 1; i < size_array; ++i)if (prom < data[i])prom = data[i];
        return prom;
    };
private:
    UINT size_array; 
    double* data; 
};

Array::Array(UINT size, double* k) throw()
{
    size_array = size; 
    data = new double[size_array]; 
    for (UINT i = 0; i < size_array; ++i) 
        data[i] = k[i]; 
}

Array::Array(UINT size, double k) throw()
{
    size_array = size; 
    data = new double[size_array]; 
    for (UINT i = 0; i < size_array; ++i) 
        data[i] = k; 
}

Array::Array(const double* begin, const double* end) throw() 
{
    if (begin < end)
    {
        size_array = (end - begin); 
        data = new double[size_array]; 
        for (UINT i = 0; i < size_array; ++i) 
            data[i] = *(begin + i);
    }

}


Array::~Array() throw()
{
    delete[]data; 
    data = 0; 

}

Array::Array(const Array& t) throw ()
    : size_array(t.size_array), data(new double[size_array])
{
    for (UINT i = 0; i < size_array; ++i)
        data[i] = t.data[i];
}

Array& Array::operator=(const Array& t)
{
    if (this != &t) 
    {
        size_array = t.size_array;
        double* new_data = new double[size_array];
        for (UINT i = 0; i < size_array; ++i)
            new_data[i] = t.data[i]; 
        delete[] data; 
        data = new_data;
    }
    return *this;
}

void Array::Swap(Array& other)
{
    std::swap(data, other.data); 
    std::swap(size_array, other.size_array);
}


double& Array::operator[](UINT index) throw ()
{
    if (index < size_array) return data[index];
    else throw std::out_of_range("index out of range!");
}

const double& Array::operator[](UINT index) const throw ()
{
    if (index < size_array) return data[index];
    else throw std::out_of_range("index out of range!");
}

double& Array::operator()(UINT index)
{
    if (index < size_array) return data[index];
    else throw std::out_of_range("index out of range!");
}

const double& Array::operator()(UINT index) const
{
    if (index < size_array) return data[index];
    else throw std::out_of_range("Index out of range!");
}

Array& Array::operator-=(const double& rhs)
{
    for (UINT i = 0; i < size_array; ++i)
        data[i] -= rhs; 
    return *this;
}

Array& Array::operator+=(const double& rhs)
{
    for (UINT i = 0; i < size_array; ++i)
        data[i] += rhs; 
    return *this;
}
Array& Array::operator/=(const double& rhs)
{
    if (rhs != 0)
        for (UINT i = 0; i < size_array; ++i)
            data[i] /= rhs; 
    return *this;
}
Array& Array::operator*=(const double& rhs)
{
    for (UINT i = 0; i < size_array; ++i)
        data[i] *= rhs; 
    return *this;
}
Array& Array::operator+=(const Array& rhs)
{
    if (size_array == rhs.size_array)
    {
        for (UINT i = 0; i < size_array; ++i)
            data[i] += rhs.data[i]; 
    }
    else
        throw std::out_of_range("Index out of range!");
    return *this;
}

Array& Array::operator-=(const Array& rhs)
{
    
    if (size_array == rhs.size_array) 
    {
        for (UINT i = 0; i < size_array; ++i)
            data[i] -= rhs.data[i]; 
    }
    else throw std::out_of_range("Index out of range!");
    return *this;
}
Array& Array::operator*=(const Array& rhs)
{
    int sum = 0;
    if (size_array == rhs.size_array)
    {
        for (UINT i = 0; i < size_array; ++i)
            data[i] *= rhs.data[i]; 
    }
    else throw std::out_of_range("Index out of range!");
    return *this;
}

Array& Array::operator/=(const Array& rhs)
{
    if (size_array == rhs.size_array) 
    {
        for (UINT i = 0; i < size_array; ++i)
            if (rhs.data[i] != 0)data[i] /= rhs.data[i];
            else throw("Devide by zero!");
    }
    else
        throw std::out_of_range("Index out of range!");
    return *this;
}


std::ostream& operator <<(std::ostream& to, const Array& a)
{
    for (Array::UINT i = 0; i < a.size(); ++i)
        to << a.data[i] << ' '; 
    return to;
}

std::istream& operator >>(std::istream& to, Array& a)
{
    for (Array::UINT i = 0; i < a.size(); ++i) to >> a.data[i];
    return to;
}

int main()
{
    int tmin, tmax, tsize;
    std::cin >> tmin >> tmax;
    tsize = tmax - tmin + 1;
    double* a, * b, * b1, c, d, n1, n2;
    a = new double[tsize];
    int i;
    for (i = 0; i < tsize; i++)std::cin >> a[i];
    b = new double[tsize];
    b1 = new double[tsize];
    for (i = 0; i < tsize; i++) { std::cin >> b[i]; b1[i] = b[i]; }
    std::cin >> c;
    Array Bitstring1(tsize, a);
    std::cout << "Array1= " << Bitstring1 << std::endl <<
        " min= " << Bitstring1.min() << " max= " << Bitstring1.max() <<
        " summa= " << Bitstring1.summa() << " srar= " << Bitstring1.srar() << std::endl;
    Array Vector3(tsize, a);
    Vector3 += c;
    Array Vector33(tsize, a);
    Vector33 *= c;
    Array Vector53(tsize, a);
    Vector53 /= c;
    std::cout << "Array1+const= " << Vector3 << std::endl;
    Array Vector30(tsize, a);
    Vector30 -= c;
    std::cout << "Array1-const= " << Vector30 << std::endl;
    std::cout << "Array1*const= " << Vector33 << std::endl;
    std::cout << "Array1/const= " << Vector53 << std::endl;
    Array Vector40(tsize, a);
    Vector40.Sort(0);
    std::cout << "sort up Array1= " << Vector40 << std::endl;
    Array Vector41(tsize, a);
    Vector41.Sort(1);
    std::cout << "sort down Array1= " << Vector41 << std::endl;
    Array Bitstring2(tsize, b);
    std::cout << "Array2= " << Bitstring2 << std::endl <<
        " min= " << Bitstring2.min() << " max= " << Bitstring2.max() <<
        " summa= " << Bitstring2.summa() << " srar= " << Bitstring2.srar() << std::endl;
    Array Vector34(tsize, b);
    Vector34 += c;
    Array Vector35(tsize, b);
    Vector35 *= c;
    Array Vector31(tsize, b);
    Vector31 -= c;
    Array Vector51(tsize, b);
    Vector51 /= c;
    std::cout << "Array2+const= " << Vector34 << std::endl;
    std::cout << "Array2-const= " << Vector31 << std::endl;
    std::cout << "Array2*const= " << Vector35 << std::endl;
    std::cout << "Array2/const= " << Vector51 << std::endl;
    Array Vector50(tsize, b);
    Vector50.Sort(0);
    std::cout << "sort up Array2= " << Vector50 << std::endl;
    Array Vector57(tsize, b);
    Vector57.Sort(1);
    std::cout << "sort down Array2= " << Vector57 << std::endl;
    Array Vector36(tsize, a);
    Vector36 += Bitstring2;
    std::cout << "summa= " << Vector36 << std::endl;
    Array Vector4(tsize, a);
    Vector4 -= Bitstring2;
    std::cout << "raznost= " << Vector4 << std::endl;
    Array Vector5(tsize, a);
    Vector5 *= Bitstring2;
    std::cout << "proizv = " << Vector5 << std::endl;
    Array Vector6(tsize, a);
    int prizn = 1;
    for (i = 0; i < tsize; i++)if (b[i] == 0)prizn = 0;
    if (prizn == 1)
    {
        Vector6 /= Bitstring2;
        std::cout << "delenie= " << Vector6 << std::endl;
    }
    else std::cout << "delenie na 0" << std::endl;
    int deistv = 1, tnom = 0;
    std::cin >> deistv;
    while (deistv != 0)
    {
        std::cin >> tnom;
        if (deistv == 1)
        {
            if ((tnom >= tmin) && (tnom <= tmax)) std::cout << "Array1" << deistv << "[" << tnom << "]= " << a[tnom - tmin] << std::endl;
            else std::cout << "Array" << deistv << " wrong index " << tnom << std::endl;
        }
        {if (deistv == 2)if ((tnom >= tmin) && (tnom <= tmax)) std::cout << "Array" << deistv << "[" << tnom << "]= " << b1[tnom - tmin] << std::endl;
        else std::cout << "Array" << deistv << " wrong index " << tnom << std::endl;

        }
        std::cin >> deistv;
    }
    ;
    return 0;
}
