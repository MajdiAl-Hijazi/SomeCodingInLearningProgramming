#include <iostream>
#include<cstdlib>
#include<ctime>

using namespace std;

enum enPrimeNotPrime { Prime = 1 ,NotPrime = 2};

int ReadPositiveNumber(string Message) {
    int Number = 0;  // Variable to store the user's input.
    do
    {
        cout << Message; // Display the prompt message.
        cin >> Number;           // Read the number entered by the user.
    } while (Number <= 0);       // Continue prompting if the number is not positive.

    return Number;  // Return the validated positive number.
}

void ReadArray(int Arr[100], int& ArrLenght) {

    ArrLenght = ReadPositiveNumber("Enter number of elements = ");

    for (int i = 0; i < ArrLenght; i++) {
    
        cout << "Element [" << i + 1 << "] : ";
        cin >> Arr[i];
    }

}

int RandomNumber(int From ,int To) {

    return (rand() % (To - From + 1) + From);
}

void FillArrayWithRandomNumber(int Arr[100], int ArrLenght) {

    for (int i = 0; i < ArrLenght; i++)
        Arr[i] = RandomNumber(0 ,100);

}

void PrintArray(int Arr[100] ,int ArrLenght) {

    /*cout << "\nArray elements = ";*/
    for (int i = 0; i < ArrLenght; i++)
        cout << Arr[i] << " ";
    cout << endl;
}

int TimesRepeated(int Arr[100] ,int ArrLenght ,int CheckNumber) {

    int count = 0;
    for (int i = 0; i < ArrLenght; i++)
        if (Arr[i] == CheckNumber)
            count++;
    return count;
}

int MaxNumberInArray(int Arr[100] ,int ArrLenght) {

    int Max = Arr[0];
    for (int i = 1; i < ArrLenght; i++)
        if (Arr[i] > Max)
            Max = Arr[i];
    return Max;

}

int MinNumberInArray(int Arr[100], int ArrLenght) {

    int Min = Arr[0];
    for (int i = 1; i < ArrLenght; i++)
        if (Arr[i] < Min)
            Min = Arr[i];
    return Min;

}

int SumOfArray(int Arr[100] ,int ArrLenght) {

    int Sum = 0;
    for (int i = 0; i < ArrLenght; i++)
        Sum += Arr[i];
    return Sum;
}

float AverageofArray(float Sum ,int ArrLenght) {

    return Sum / ArrLenght;
}

void CopyFromArray(int Arr1[100] ,int Arr2[100] ,int ArrLenght) {

    for (int i = 0; i < ArrLenght; i++)
        Arr2[i] = Arr1[i];
}

enPrimeNotPrime CheckPrimeNumber(int Number) {

    if (Number >= 2) {
        for (int i = 2; i <= Number / 2; i++) {
    
            if (Number % i == 0)
                return enPrimeNotPrime::NotPrime;
        }
        return enPrimeNotPrime::Prime;
    }
    return enPrimeNotPrime::NotPrime;
}

void CopyOnlyPrimeNumber(int Arr1[100] ,int Arr2[100] ,int Arr1Lenght ,int& Arr2Lenght) {

    for (int i = 0; i < Arr1Lenght; i++) {
    
        if (CheckPrimeNumber(Arr1[i]) == enPrimeNotPrime::Prime) {
        
            Arr2[Arr2Lenght] = Arr1[i];
            Arr2Lenght++;
        }
            
    }
}

void CalculateArray1AndArray2(int Arr1[100], int Arr2[100], int Arr3[100], int ArrLenght) {

    for (int i = 0; i < ArrLenght; i++)
        Arr3[i] = Arr1[i] + Arr2[i];
}

int main() {
    srand((unsigned)time(NULL));

    int Arr1[100], Arr2[100] , Arr3[100], ArrLenght;

    ArrLenght = ReadPositiveNumber("Enter number of elements  = ");

    FillArrayWithRandomNumber(Arr1 ,ArrLenght);
    cout << "\nArray 1 elements : ";
    PrintArray(Arr1 ,ArrLenght);
    FillArrayWithRandomNumber(Arr2, ArrLenght);
    cout << "\nArray 2 elements : ";
    PrintArray(Arr2, ArrLenght);
    CalculateArray1AndArray2(Arr1 ,Arr2 ,Arr3 ,ArrLenght);
    cout << "\nArray 3 elements : ";
    PrintArray(Arr3, ArrLenght);

    return 0;
}
