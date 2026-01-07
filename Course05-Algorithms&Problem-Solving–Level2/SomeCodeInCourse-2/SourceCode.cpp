#include <iostream>
#include<string>
#include <cstdlib>
#include <ctime>

using namespace std;

enum enSearchElement { Found = 1 ,NotFound = 2};

enum enPrimeNotPrime{ Prime = 1 ,NotPrime = 2};

void Swap(int& Num1 ,int& Num2) {

    int Swap = Num2;
    Num2 = Num1;
    Num1 = Swap;
}

int ReadPositiveNumber(string Message) {
    int Number = 0;

    do {
        cout << Message;
        cin >> Number;

    } while (Number <= 0);

    return Number;
}

void ReadArray(int Arr1[100], int& Arr1Lenght) {

    Arr1Lenght = ReadPositiveNumber("Enter number of elements = ");

    for (int i = 0; i < Arr1Lenght; i++) {
        // cout << "Element [" << i + 1 << "] : ";
        Arr1[i] = i + 1;
    }
}

void ReadArrayFrom1ToN(int Arr[100], int& ArrLenght) {

    ArrLenght = ReadPositiveNumber("Enter number of elements = ");

    for (int i = 0; i < ArrLenght; i++) {
        // cout << "Element [" << i + 1 << "] : ";
        Arr[i] = i + 1;
    }
}

void PrintArray(int Arr[100], int ArrLenght) {
    for (int i = 0; i < ArrLenght; i++)
        cout << Arr[i] << " ";
    cout << endl;
}

void PrintStringArray(string Arr[100], int ArrLenght) {

    for (int i = 0; i < ArrLenght; i++)
        cout << "Array[" << i << "] : " << Arr[i] << endl;
}

int RandomNumber(int From, int To) {

    return (rand() % (To - From + 1) + From);
}

void FillArrayWithRandomNumber(int Arr[100], int& Arr1Lenght) {

    Arr1Lenght = ReadPositiveNumber("Enter number of elements = ");

    for (int i = 0; i < Arr1Lenght; i++) {
        
        Arr[i] = RandomNumber(-100 ,100);
    }
}

enSearchElement SearchElement(int Number, int Arr[], int ArrLenght) {

    for (int i = 0; i < ArrLenght; i++)
        if (Number == Arr[i])
            return enSearchElement::Found;

    return enSearchElement::NotFound;
}

void ArrayAfterShuffle1(int Arr2[] ,int ArrLenght) {

    int count = 0;
    Arr2[count] = RandomNumber(1 ,ArrLenght);
    count = 1;
    int RandomElement;

    while (count < ArrLenght) {
    
        RandomElement = RandomNumber(1 ,ArrLenght);
        if (SearchElement(RandomElement, Arr2, count) == enSearchElement::NotFound) {
        
            Arr2[count] = RandomElement;
            count++;
        }
    }
}

void ArrayAfterShuffle2(int Arr[100] ,int ArrLenght) {

    for (int i = 0; i < ArrLenght; i++) {
    
        Swap(Arr[RandomNumber(0 ,ArrLenght - 1)] ,Arr[RandomNumber(0, ArrLenght - 1)]);
    }
}

void CopyArray1InReversedOrder(int Arr1[100] ,int Arr2[100] ,int ArrLenght) {

    for (int i = 0; i < ArrLenght; i++) {
    
        Arr2[i] = Arr1[ArrLenght - 1 - i];
    }
}

string GenerateWord(short Lenght) {

    string Word = "";

    for (int i = 1; i <= Lenght; i++) {
    
        Word += char(RandomNumber(65 ,90));
    }
    
    return Word;
}

string GenerateKey() {

    string Key = "";
    Key = GenerateWord(4) + "-" + GenerateWord(4) + "-" + GenerateWord(4) + "-" + GenerateWord(4);

    return Key;
}

void FillArrayWithKeys(string Arr[100] ,int ArrLenght) {

    for (int i = 0; i < ArrLenght; i++) {
    
        Arr[i] = GenerateKey();
    }

}

short FindNumberPositionInArray(int Number, int arr[100], int arrLength)
{
    // Loop through each element in the array.
    for (int i = 0; i < arrLength; i++)
    {
        // Check if the current element equals the searched number.
        if (arr[i] == Number)
            return i; // Return the index immediately when the number is found.
    }

    // If the loop completes without finding the number, return -1.
    return -1;
}

void PrintIndexAndPositionForNumber(int Number, int Arr[100], int ArrLength) {

    int index = FindNumberPositionInArray(Number, Arr, ArrLength);

    if (index == -1)
        cout << "The number is not found :-(" << endl;
    else {

        cout << "The number found at position : " << index << endl;
        cout << "The number found at order : " << index + 1 << endl;
    }
}

bool IsNumberInArray(int Number, int Arr[100], int ArrLength) {

    return FindNumberPositionInArray(Number ,Arr ,ArrLength) != -1;
}

int ReadNumber(string Message) {

    int Number;
    cout << Message;
    cin >> Number;
    return Number;
}

void AddElementArray(int Number,int Arr[100] ,int& ArrLenght) {

    Arr[ArrLenght] = Number;
    ArrLenght++;
}

void InputUserInArray(int Arr[100] ,int& ArrLenght) {

    bool AddMore;

    do {
    
        AddElementArray(ReadNumber("Enter element  = "), Arr, ArrLenght);
        cout << "Do you want to add more numbers ? [0]:No, [1]:Yes ? ";
        cin >> AddMore;
        cout << endl;

    } while (AddMore);
}

void CopyArray(int Arr1[100] ,int Arr2[100] ,int Arr1Lenght ,int& Arr2Lenght) {

    while (Arr2Lenght < Arr1Lenght) {
    
        AddElementArray(Arr1[Arr2Lenght], Arr2, Arr2Lenght);
    }
}

void CopyOddNumbersOnly(int Arr1[100] ,int Arr2[100] ,int Arr1Lenght ,int& Arr2Lenght) {

    for (int i = 0; i < Arr1Lenght; i++)
        if (Arr1[i] % 2 != 0)
            AddElementArray(Arr1[i] ,Arr2 ,Arr2Lenght);
}

enPrimeNotPrime CheckPrimeNumber(int Number) {

    if (Number >= 2) {

        for (int i = 2; i <= Number / 2; i++)
            if (Number % i == 0)
                return enPrimeNotPrime::NotPrime;
    }
    else
        return enPrimeNotPrime::NotPrime;

    return enPrimeNotPrime::Prime;
}

void CopyPrimeNumbersOnly(int Arr1[100], int Arr2[100], int Arr1Lenght, int& Arr2Lenght) {

    for (int i = 0; i < Arr1Lenght; i++)
        if (CheckPrimeNumber(Arr1[i]) == enPrimeNotPrime::Prime)
            AddElementArray(Arr1[i], Arr2, Arr2Lenght);
}

void CopyDistinctNumber(int Arr1[], int Arr2[], int Arr1Lenght, int& Arr2Lenght) {

    for (int i = 0; i < Arr1Lenght; i++)
        if (!IsNumberInArray(Arr1[i], Arr2, Arr2Lenght))
            AddElementArray(Arr1[i] ,Arr2 ,Arr2Lenght);
}

string CheckPalindrome(int Arr1[100] ,int Arr2[100] ,int ArrLenght) {

    for (int i = 0; i < ArrLenght; i++)
        if (Arr1[i] != Arr2[i])
            return "The array is not Palindrom";

    return "The array is Palindrom";
}

bool IsPalindrome1Array(int Arr[100], int ArrLenght) {

    if (ArrLenght % 2 == 0) {

        int i = 0;
        int j = ArrLenght - 1;

        while (i < ArrLenght / 2 && j >= ArrLenght / 2) {

            if (Arr[i] != Arr[j])
                return false;
            i++;
            j--;
        }

        return true;
    }
    else
        return false;
}

bool IsPalindrome2Array(int Arr[100], int ArrLenght) {

    for (int i = 0; i < ArrLenght; i++)
        if (Arr[i] != Arr[ArrLenght - 1 - i])
            return false;
    return true;

}

void FillArray(int Arr[100]) {

    Arr[0] = 10;
    Arr[1] = 20;
    Arr[2] = 30;
    Arr[3] = 30;
    Arr[4] = 20;
    Arr[5] = 10;
}

int OddNumbersCountInArray(int Arr[100] ,int ArrLenght) {

    int count = 0;

    for (int i = 0; i < ArrLenght; i++)
        if (Arr[i] % 2 != 0)
            count++;

    return count;
}

int EvenNumbersCountInArray(int Arr[100], int ArrLenght) {

    int count = 0;

    for (int i = 0; i < ArrLenght; i++)
        if (Arr[i] % 2 == 0)
            count++;

    return count;
}

int PositiveNumbersCountInArray(int Arr[100], int ArrLenght) {

    int count = 0;

    for (int i = 0; i < ArrLenght; i++)
        if (Arr[i] >= 0)
            count++;

    return count;
}

int main() {

	srand((unsigned)time(NULL));
    int Arr[100], ArrLenght;
    FillArrayWithRandomNumber(Arr ,ArrLenght);

    cout << "\nArray elements :\n";
    PrintArray(Arr ,ArrLenght);

    cout << "\nPositive numbers count = " << PositiveNumbersCountInArray(Arr, ArrLenght) << endl;
    

	return 0;
}
