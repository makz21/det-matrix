#include <iostream>
 
using namespace std;
 
class WrongDimension{};         // wymiary macierzy
class WrongDimension2{};        // wymiary macierzy
class IndexOutOfRange{};        // przekroczenie zakresu tablicy
class FileOpenError{};          // z³e otwarcie pliku
 
class cMatrix
{
        private:
                int row;
                int col;
 
        public:
                struct sMatrix;
                sMatrix *matrix;
 
                // konstrktory i destruktor
                cMatrix(int _row, int _col);
                cMatrix(const cMatrix &wzor);
                ~cMatrix();
               
                int Col() const { return col; }
                int Row() const { return row; }
                void Wypelnij(char *nazwa);
               
                // operacje na macierzach
                void operator+=(const cMatrix &B);
                void operator-=(const cMatrix &B);
                void operator*=(const cMatrix &B);
 
                //odczyt i zapis macierzy (operacja na pojedynczych elementach)
                float& operator()(const int i, const int j);       // ZAPIS
                float operator()(const int i, const int j) const;  // ODCZYT
 
                cMatrix& operator=(const cMatrix &B);  
                friend ostream& operator<<(ostream& stream, const cMatrix &A);
};
 
cMatrix operator+(const cMatrix &A, const cMatrix &B);
cMatrix operator-(const cMatrix &A, const cMatrix &B);
cMatrix operator*(const cMatrix &A, const cMatrix &B);
bool operator==(cMatrix &A, cMatrix &B);
ostream& operator<<(ostream& stream, const cMatrix &A);
 
int SetRow(char *nazwa);
int SetCol(char *nazwa);
