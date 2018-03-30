#include <iostream>
#include "Matrix.h"
#include <fstream>

using namespace std;
 
int main()
{           
	int row, col;  

        try
        {
		  row=SetRow((char*)"A.txt");
		  col=SetCol((char*)"A.txt");
		  cMatrix A(row, col);
		  A.Wypelnij((char*)"A.txt");
  
		  row=SetRow((char*)"B.txt");
		  col=SetCol((char*)"B.txt");
		  cMatrix B(row, col);
		  B.Wypelnij((char*)"B.txt");
	  
		  cMatrix C(A.Row(), B.Col()); // macierz wynikowa

 
                int wybor;
                do{
			  cout << "1 - Wyswietl macierze" << endl;
			  cout << "2 - Dodawanie" << endl;
			  cout << "3 - Odejmowanie" << endl;
			  cout << "4 - Mnozenie" << endl;
			  cout << "5 - Odczyt pojedynczej wartosci" << endl;
			  cout << "6 - Zapis pojedynczej wartosci" << endl;
			  cout << "7 - Porownywanie" << endl;
			  cout << "8 - Wyjscie" << endl;
  
			  cin >> wybor;
			  cout << endl;
 
                        switch (wybor)
                        {
                    	
                    	case 1:
			{
				  cout << A;
				  cout << B;
				  break;
			}
						
                        case 2:
                        {
				    cout << "Operator + " << endl;
				    C = A + B;
				    cout << endl;
				    cout << "A + B = " << endl;
				    cout << C;
				    cout << endl << endl;
  
				    cout << "Operator += " << endl;
				    A += B;
				    cout << endl;
				    cout << "A += B " << endl;
				    cout << A;
				    cout << endl << endl;
				    break;
                        }
 
                        case 3:
                        {
				    cout << "Operator - " << endl;
				    C = A - B;
				    cout << endl;
				    cout << "A - B = " << endl;
				    cout << C;
				    cout << endl << endl;
  
				    cout << "Operator -= " << endl;
				    A -= B;
				    cout << endl;
				    cout << "A -= B " << endl;
				    cout << A;
				    cout << endl << endl;
				    break;
                        }
 
                        case 4:
                        {
				    cout << "Operator * " << endl;
				    C = A * B;
				    cout << endl;
				    cout << "A * B = " << endl;
				    cout << C;
				    cout << endl << endl;
  
				    cout << "Operator *= " << endl;
				    A *= B;    
				    cout << endl;
				    cout << "A *= B " << endl;
				    cout << A;
				    cout << endl << endl;
				    break;
                        }
 
 			case 5:
 			{
				    cout << "A(1,0)=" << A(2,1) << endl;
				    cout << "B(1,1)=" << B(0,0) << endl;
 				    break;		
			}
	
			case 6:
			{
				    double x;
				    cout << "Jaka liczbe chcesz zapisac? :";
				    cin >> x;
				    A(0,0)=x;
				    cout << "Zapisano!" << endl;
				    break;
			}
	
                        case 7:
                        {
				    cout << endl;
				    if (A == B)
				    {
					    cout << "Macierze sa sobie rowne" << endl;
				    }
				    else
				    {
					    cout << "Macierze nie sa sobie rowne" << endl;
				    }
				    cout << endl << endl;
				    break;
                        }
 
                        default: if (wybor != 8) cout << "WYBRALES ZLA OPCJE!!" << endl;
                        }
                } while (wybor != 8);
 
                cout << endl << endl;
        }   
        
        // obsluga bledow
        catch(WrongDimension&)  {       cout << endl << "ERROR: ZLE WYMIARY MACIERZY! WIELKOSCI MACIERZY MUSZA BYC JEDNAKOWE!!"   << endl << endl; }
        catch(WrongDimension2&) {       cout << endl << "ERROR: ZLE WYMIARY MACIERZY! LICZBA KOLUMN MACIERZY A MUSI BYC ROWNA LICZBIE WIERSZY MACIERZY B!!"  << endl << endl; }
        catch(IndexOutOfRange&) {       cout << endl << "ERROR: INDEKS TABLICY POZA PRZEDZIALEM!"  << endl << endl; }
        catch(FileOpenError&)   {       cout << endl << "ERROR: BLAD OTWARCIA PLIKU!"  << endl << endl; }
 
        return 0;
} 
