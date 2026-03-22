#include <iostream>
#include <cmath>
#include <string>

using namespace std;


// ==================== ЗАДАЧА 2 ====================
class Vector {
private:
    long* data;
    int size;
    int state;

    static int objectCount;

public:
    // Коди стану
    static const int OK = 0;
    static const int MEMORY_ERROR = 1;
    static const int INDEX_ERROR = 2;
    static const int SIZE_ERROR = 3;

    // Конструктор без параметрів
    Vector() {
        size = 1;
        state = OK;
        data = new(nothrow) long[size];
        if (data) {
            data[0] = 0;
        } else {
            state = MEMORY_ERROR;
            size = 0;
        }
        objectCount++;
    }

    // Конструктор з одним параметром
    Vector(int n) {
        state = OK;
        if (n <= 0) {
            size = 1;
        } else {
            size = n;
        }

        data = new(nothrow) long[size];
        if (data) {
            for (int i = 0; i < size; i++) {
                data[i] = 0;
            }
        } else {
            state = MEMORY_ERROR;
            size = 0;
        }
        objectCount++;
    }

    // Конструктор з двома параметрами
    Vector(int n, long value) {
        state = OK;
        if (n <= 0) {
            size = 1;
        } else {
            size = n;
        }

        data = new(nothrow) long[size];
        if (data) {
            for (int i = 0; i < size; i++) {
                data[i] = value;
            }
        } else {
            state = MEMORY_ERROR;
            size = 0;
        }
        objectCount++;
    }

    // Конструктор копіювання
    Vector(const Vector& other) {
        size = other.size;
        state = other.state;

        data = new(nothrow) long[size];
        if (data) {
            for (int i = 0; i < size; i++) {
                data[i] = other.data[i];
            }
        } else {
            state = MEMORY_ERROR;
            size = 0;
        }
        objectCount++;
    }

    // Оператор присвоєння
    Vector& operator=(const Vector& other) {
        if (this == &other) {
            return *this;
        }

        delete[] data;

        size = other.size;
        state = other.state;

        data = new(nothrow) long[size];
        if (data) {
            for (int i = 0; i < size; i++) {
                data[i] = other.data[i];
            }
        } else {
            state = MEMORY_ERROR;
            size = 0;
        }

        return *this;
    }

    // Деструктор
    ~Vector() {
        delete[] data;
        objectCount--;
    }

    // Кількість об'єктів
    static int getObjectCount() {
        return objectCount;
    }

    // Отримати розмір
    int getSize() const {
        return size;
    }

    // Отримати стан
    int getState() const {
        return state;
    }

    // Встановити елемент
    void setElement(int index, long value = 0) {
        if (index < 0 || index >= size) {
            state = INDEX_ERROR;
            return;
        }
        data[index] = value;
        state = OK;
    }

    // Отримати елемент
    long getElement(int index) {
        if (index < 0 || index >= size) {
            state = INDEX_ERROR;
            return 0;
        }
        state = OK;
        return data[index];
    }

    // Друк
    void print() const {
        cout << "Vector: [ ";
        for (int i = 0; i < size; i++) {
            cout << data[i] << " ";
        }
        cout << "]\n";
        cout << "Size = " << size << ", State = " << state << "\n";
    }

    // Додавання
    Vector add(const Vector& other) {
        if (size != other.size) {
            Vector temp;
            temp.state = SIZE_ERROR;
            return temp;
        }

        Vector result(size);
        for (int i = 0; i < size; i++) {
            result.data[i] = data[i] + other.data[i];
        }
        return result;
    }

    // Віднімання
    Vector sub(const Vector& other) {
        if (size != other.size) {
            Vector temp;
            temp.state = SIZE_ERROR;
            return temp;
        }

        Vector result(size);
        for (int i = 0; i < size; i++) {
            result.data[i] = data[i] - other.data[i];
        }
        return result;
    }

    // Множення на unsigned int
    Vector multiply(unsigned int value) {
        Vector result(size);
        for (int i = 0; i < size; i++) {
            result.data[i] = data[i] * value;
        }
        return result;
    }

    // Менше
    bool isLess(const Vector& other) const {
        if (size != other.size) {
            return false;
        }

        for (int i = 0; i < size; i++) {
            if (data[i] >= other.data[i]) {
                return false;
            }
        }
        return true;
    }

    // Рівно
    bool isEqual(const Vector& other) const {
        if (size != other.size) {
            return false;
        }

        for (int i = 0; i < size; i++) {
            if (data[i] != other.data[i]) {
                return false;
            }
        }
        return true;
    }

    // Нерівно
    bool isNotEqual(const Vector& other) const {
        return !isEqual(other);
    }
};

int Vector::objectCount = 0;

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
    int choice;

    Vector v1;
    Vector v2(5);
    Vector v3(5, 10);

    do {
        cout << "\n===== ЗАДАЧА 2. Клас Vector =====\n";
        cout << "1 - Показати v1, v2, v3\n";
        cout << "2 - Встановити елемент у v2\n";
        cout << "3 - Отримати елемент v2\n";
        cout << "4 - Копіювання v3 у v4\n";
        cout << "5 - Присвоєння v1 = v3\n";
        cout << "6 - Додавання v2 + v3\n";
        cout << "7 - Віднімання v3 - v2\n";
        cout << "8 - Множення v3 на число\n";
        cout << "9 - Порівняння v2 і v3\n";
        cout << "10 - Кількість об'єктів\n";
        cout << "0 - Назад\n";
        cout << "Ваш вибір: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                cout << "\nv1:\n";
                v1.print();
                cout << "\nv2:\n";
                v2.print();
                cout << "\nv3:\n";
                v3.print();
                break;
            }

            case 2: {
                int index;
                long value;
                cout << "Введіть індекс: ";
                cin >> index;
                cout << "Введіть значення: ";
                cin >> value;
                v2.setElement(index, value);
                cout << "Після зміни:\n";
                v2.print();
                break;
            }

            case 3: {
                int index;
                cout << "Введіть індекс: ";
                cin >> index;
                cout << "Елемент = " << v2.getElement(index) << "\n";
                cout << "State = " << v2.getState() << "\n";
                break;
            }

            case 4: {
                Vector v4(v3);
                cout << "v4 після копіювання з v3:\n";
                v4.print();
                break;
            }

            case 5: {
                v1 = v3;
                cout << "v1 після присвоєння v1 = v3:\n";
                v1.print();
                break;
            }

            case 6: {
                Vector result = v2.add(v3);
                cout << "v2 + v3 = \n";
                result.print();
                break;
            }

            case 7: {
                Vector result = v3.sub(v2);
                cout << "v3 - v2 = \n";
                result.print();
                break;
            }

            case 8: {
                unsigned int k;
                cout << "Введіть число: ";
                cin >> k;
                Vector result = v3.multiply(k);
                cout << "v3 * " << k << " = \n";
                result.print();
                break;
            }

            case 9: {
                cout << "v2 == v3 : " << (v2.isEqual(v3) ? "true" : "false") << "\n";
                cout << "v2 != v3 : " << (v2.isNotEqual(v3) ? "true" : "false") << "\n";
                cout << "v2 < v3  : " << (v2.isLess(v3) ? "true" : "false") << "\n";
                break;
            }

            case 10: {
                cout << "Кількість об'єктів Vector: " << Vector::getObjectCount() << "\n";
                break;
            }

            case 0:
                break;

            default:
                cout << "Невірний вибір.\n";
        }

    } while (choice != 0);
}

// ==================== ЗАДАЧА 3 ====================
void task3() {
    cout << "\nТут буде код 3 задачі.\n";
}


// ==================== MAIN MENU ====================
int main() {
    int choice;

    do {
        cout << "\n========== ГОЛОВНЕ МЕНЮ ==========\n";
        cout << "1 - Задача 1 (Triangle)\n";
        cout << "2 - Задача 2\n";
        cout << "3 - Задача 3\n";
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
            case 0:
                cout << "Завершення програми.\n";
                break;
            default:
                cout << "Невірний вибір.\n";
        }
    } while (choice != 0);

    return 0;
}