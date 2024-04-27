#include <iostream>
#include <list>
#include <stdexcept> // Для исключений
#include <cctype>    // Для проверки типа символа

template<typename T>
class Stack {
private:
    std::list<T> data; // Используем std::list для реализации стека
    std::string name; // Имя стека

public:
    // Конструктор, принимающий имя стека
    Stack(const std::string& name) : name(name) {}
    
    // Конструктор по умолчанию для типа double Stack() { name = "doubleStack"; data.push_back(0.0); }
    Stack() { 
        name = "doubleStack";
    }
    // Помещает элемент на вершину стека
    void push(const T& value) {
        // Проверка на ввод большой буквы
        if (std::isupper(value)) {
            throw std::runtime_error("Введена большая буква в стек '" + name + "'");
        }
        data.push_back(value);
    }

    // Удаляет и возвращает элемент с вершины стека
    T pop() {
        if (data.empty()) {
            throw std::runtime_error("Стек '" + name + "' пуст");
        }
        T value = data.back();
        data.pop_back();
        return value;
    }

    // Возвращает элемент с вершины стека, не удаляя его
    T top() const {
        if (data.empty()) {
            throw std::runtime_error("Стек '" + name + "' пуст");
        }
        return data.back();
    }

    // Проверяет, пуст ли стек
    bool empty() const {
        return data.empty();
    }

    // Возвращает размер стека
    size_t size() const {
        return data.size();
    }
};

int main() {
    setlocale(LC_ALL, "Russian");
    try {
        std::cout << "Стек Char" << std::endl;
        // Создание стека символов с именем "charStack"
        Stack<char> charStack("charStack");

        // Добавление элементов в стек символов
        charStack.push('a');
        charStack.push('b');
        charStack.push('C'); // Приведет к генерации исключения
        // Печать верхнего элемента стека целых чисел
        std::cout << "Верхний элемент charStack: " << charStack.top() << std::endl;

        //Удаление элемента из стека символов
        char poppedChar = charStack.pop();
        std::cout << "Извлеченный элемент из charStack: " << poppedChar << std::endl;

        // Печать размера стека целых чисел
        std::cout << "Размер charStack: " << charStack.size() << std::endl;
    }
    catch (const std::exception& e) {
        std::cerr << "Исключение: " << e.what() << std::endl;
    }
    try {
        std::cout << std::endl;
        std::cout << "Стек int" << std::endl;
        // Создание стека целых чисел
        Stack<int> intStack("intStack");

        // Добавление элементов в стек целых чисел
        intStack.push(1);
        intStack.push(2);
        intStack.push(3);

        // Печать верхнего элемента стека целых чисел
        std::cout << "Верхний элемент intStack: " << intStack.top() << std::endl;

        // Удаление элемента из стека целых чисел
        int poppedInt = intStack.pop();
        std::cout << "Извлеченный элемент из intStack: " << poppedInt << std::endl;

        // Печать размера стека целых чисел
        std::cout << "Размер intStack: " << intStack.size() << std::endl;

    }
    catch (const std::exception& e) {
        std::cerr << "Исключение: " << e.what() << std::endl;
    }
    // Создание стека чисел с плавающей запятой
    Stack<double> doubleStack;
    try {
        std::cout << std::endl;
        std::cout << "Стек double" << std::endl;
        // Добавление элемента в пустой стек
        doubleStack.pop(); // Приведет к генерации исключения
    }
    catch (const std::exception& e) {
        std::cerr << "Исключение: " << e.what() << std::endl;
    }

    return 0;
}