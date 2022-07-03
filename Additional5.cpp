#include <iostream> // добавила библиотеку iostream

class Foo
{
public:
    Foo(int j) {
        Foo::l = j;
        i = new int[j];

        for (int k = 0; k < l; k++) // заполняем массив
            i[k] = k;
    }

    void print() {
        for (int k = 0; k < l; k++)
            std::cout << i[k] << std::endl;
    }

    Foo(const Foo& object) : i(object.i) { // добавлен конструктор копирования
        std::cout << "Foo copy constructor" << std::endl;

    }

    Foo& operator=(const Foo& object) { // добавлен оператор копирования
        std::cout << "Foo =" << std::endl;
        delete[] i;
        for (int k = 0; k < object.l; k++)
            i[k] = object.i[k];
        return *this;
    }

    virtual ~Foo() { delete[] i; } // virtual и удаление через delete[]
protected: // private в protected
    int* i;
    int l; // обьявили
};

class Bar : public Foo // наследование публичных методов
{
public:
    Bar(int j) : Foo(j) { // Foo(j)
        i = new char[j];
    }

    Bar(const Bar& object) : Foo(object) {
        std::cout << "Boo copy constructor" << std::endl;
    }

    Bar& operator=(const Bar& object) {
        std::cout << "Boo =" << std::endl;
        delete[] i;
        for (int k = 0; k < object.l; k++)
            i[k] = object.i[k];
        return *this;
    }

    virtual ~Bar() { delete[] i; } // delete[]
protected: // private в protected
    char* i;
};


int main() // void main() -> int main()
{
    Foo* f = new Foo(5);
    Foo* b = new Bar(3);
    f->print();
    std::cout << std::endl;
    b->print();
    std::cout << std::endl;
    f = b;

    f->print();
    std::cout << std::endl;
    b->print();
}
