#include <iostream>
#include <vector>
using namespace std;

class Vector {
private:
    vector<int> data;
    int lowerBound;
    int upperBound;

public:
    // Конструктор з параметрами
    Vector(int lower, int upper) : lowerBound(lower), upperBound(upper) {
        // Ініціалізуємо вектор з нулями
        data.resize(upper - lower + 1, 0);
    }

    // Доступ до елементів вектору з перевіркою на межі індексів
    int& operator[](int index) {
        if (index < lowerBound || index > upperBound) {
           cerr << "Індекс знаходиться за межами допустимих значень\n";
            exit(1);
        }
        return data[index - lowerBound];
    }

    // Операції поелементного додавання
    Vector operator+(const Vector& other) const {
        if (lowerBound != other.lowerBound || upperBound != other.upperBound) {
            cerr << " Межі векторів не збігаються\n";
            exit(1);
        }
        Vector result(lowerBound, upperBound);
        for (int i = lowerBound; i <= upperBound; ++i) {
            result[i] = data[i - lowerBound] + other.data[i - lowerBound];
        }
        return result;
    }

    // Операції поелементного віднімання
    Vector operator-(const Vector& other) const {
        if (lowerBound != other.lowerBound || upperBound != other.upperBound) {
            cerr << " Межі векторів не збігаються\n";
            exit(1);
        }
        Vector result(lowerBound, upperBound);
        for (int i = lowerBound; i <= upperBound; ++i) {
            result[i] = data[i - lowerBound] - other.data[i - lowerBound];
        }
        return result;
    }

    // Операції множення на скаляр
    Vector operator*(int scalar) const {
        Vector result(lowerBound, upperBound);
        for (int i = lowerBound; i <= upperBound; ++i) {
            result[i] = data[i - lowerBound] * scalar;
        }
        return result;
    }

    // Операції ділення на скаляр
    Vector operator/(int scalar) const {
        Vector result(lowerBound, upperBound);
        if (scalar == 0) {
            cerr << "Ділення на нуль\n";
            exit(1);
        }
        for (int i = lowerBound; i <= upperBound; ++i) {
            result[i] = data[i - lowerBound] / scalar;
        }
        return result;
    }

    // Виведення елементів вектору на екран
    void print() const {
        for (int i = lowerBound; i <= upperBound; ++i) {
            cout << data[i - lowerBound] << " ";
        }
        cout << std::endl;
    }
};

int main() {
    setlocale(LC_CTYPE, "ukr");

    int lowerBound, upperBound;

    cout << "Введіть нижню межу для векторів: ";
    cin >> lowerBound;
    cout <<"Введіть верхню межу для векторів :";
    cin >> upperBound;

    Vector v1(lowerBound, upperBound);
    Vector v2(lowerBound, upperBound);

    cout << "Введіть елементи для вектора 1:" << std::endl;
    for (int i = lowerBound; i <= upperBound; ++i) {
        cout << "Введіть елемент " << i << ": ";
        cin >> v1[i];
    }

    cout << "Введіть елементи для вектора 2:" << std::endl;
    for (int i = lowerBound; i <= upperBound; ++i) {
        cout << "Введіть елемент " << i << ": ";
        cin >> v2[i];
    }

    Vector sum = v1 + v2;
    Vector difference = v1 - v2;
    Vector scalarProduct = v1 * 2;
    Vector scalarDivision = v1 / 2;

    cout << "Сума: ";
    sum.print();

    cout << "Різниця: ";
    difference.print();

    cout << "Скалярний добуток: ";
    scalarProduct.print();

    cout << "Скалярне ділення: ";
    scalarDivision.print();

    return 0;
}






