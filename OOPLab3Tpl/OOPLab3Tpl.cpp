#include <iostream>
#include <cmath>
#include <string>

using namespace std;

// ==================== ЗАДАЧА 1 ====================
// Клас Triangle
class Triangle {
private:
    double a, b, c;
    string color;

    bool isValidTriangle(double x, double y, double z) const {
        return x > 0 && y > 0 && z > 0 &&
               x + y > z &&
               x + z > y &&
               y + z > x;
    }

public:
    // Конструктор без параметрів
    Triangle() {
        a = 3;
        b = 4;
        c = 5;
        color = "white";
    }

    // Конструктор з параметрами
    Triangle(double x, double y, double z, const string& col) {
        if (isValidTriangle(x, y, z)) {
            a = x;
            b = y;
            c = z;
        } else {
            cout << "Некоректні сторони. Встановлено значення за замовчуванням.\n";
            a = 3;
            b = 4;
            c = 5;
        }

        if (!col.empty()) {
            color = col;
        } else {
            cout << "Некоректний колір. Встановлено значення white.\n";
            color = "white";
        }
    }

    bool setSides(double x, double y, double z) {
        if (isValidTriangle(x, y, z)) {
            a = x;
            b = y;
            c = z;
            return true;
        }
        cout << "Помилка: такі сторони не утворюють трикутник.\n";
        return false;
    }

    bool setColor(const string& col) {
        if (!col.empty()) {
            color = col;
            return true;
        }
        cout << "Помилка: колір не може бути порожнім.\n";
        return false;
    }

    double getA() const { return a; }
    double getB() const { return b; }
    double getC() const { return c; }
    string getColor() const { return color; }

    double perimeter() const {
        return a + b + c;
    }

    double area() const {
        double p = perimeter() / 2.0;
        return sqrt(p * (p - a) * (p - b) * (p - c));
    }

    void print() const {
        cout << "\nТрикутник:\n";
        cout << "Сторони: " << a << ", " << b << ", " << c << "\n";
        cout << "Колір: " << color << "\n";
        cout << "Периметр: " << perimeter() << "\n";
        cout << "Площа: " << area() << "\n";
    }
};

// Функція демонстрації 1 задачі
void task1() {
    Triangle t1;
    Triangle t2(6, 8, 10, "blue");

    int choice;
    do {
        cout << "\n===== ЗАДАЧА 1. Клас Triangle =====\n";
        cout << "1 - Показати трикутник за замовчуванням\n";
        cout << "2 - Показати трикутник з параметрами\n";
        cout << "3 - Змінити сторони трикутника t1\n";
        cout << "4 - Змінити колір трикутника t1\n";
        cout << "5 - Показати периметр і площу t1\n";
        cout << "0 - Назад у головне меню\n";
        cout << "Ваш вибір: ";
        cin >> choice;

        switch (choice) {
            case 1:
                t1.print();
                break;
            case 2:
                t2.print();
                break;
            case 3: {
                double x, y, z;
                cout << "Введіть 3 сторони: ";
                cin >> x >> y >> z;
                t1.setSides(x, y, z);
                break;
            }
            case 4: {
                string col;
                cout << "Введіть колір: ";
                cin >> col;
                t1.setColor(col);
                break;
            }
            case 5:
                cout << "\nПериметр t1 = " << t1.perimeter() << "\n";
                cout << "Площа t1 = " << t1.area() << "\n";
                break;
            case 0:
                break;
            default:
                cout << "Невірний вибір.\n";
        }
    } while (choice != 0);
}

// ==================== ЗАДАЧА 2 ====================
void task2() {
    cout << "\nТут буде код 2 задачі.\n";
}

// ==================== ЗАДАЧА 3 ====================
void task3() {
    cout << "\nТут буде код 3 задачі.\n";
}

// ==================== ЗАДАЧА 4 ====================
void task4() {
    cout << "\nТут буде код 4 задачі.\n";
}

// ==================== MAIN MENU ====================
int main() {
    int choice;

    do {
        cout << "\n========== ГОЛОВНЕ МЕНЮ ==========\n";
        cout << "1 - Задача 1 (Triangle)\n";
        cout << "2 - Задача 2\n";
        cout << "3 - Задача 3\n";
        cout << "4 - Задача 4\n";
        cout << "0 - Вихід\n";
        cout << "Ваш вибір: ";
        cin >> choice;

        switch (choice) {
            case 1:
                task1();
                break;
            case 2:
                task2();
                break;
            case 3:
                task3();
                break;
            case 4:
                task4();
                break;
            case 0:
                cout << "Завершення програми.\n";
                break;
            default:
                cout << "Невірний вибір.\n";
        }
    } while (choice != 0);

    return 0;
}