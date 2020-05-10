#ifndef LAB1_BOOKSHELF_H
#define LAB1_BOOKSHELF_H
#include "shelf.h"
#include <vector>

// Это заголовочный файл класса Книжныйшкаф. Тут будут комментарии только о новых штуках,
// подробнее см. классы Полка и Книга
// Большая часть методов здесь является обобщением методов класса Полка

    class Bookshelf {
        std::vector<Shelf> shelves; // это поле -- vector 10 элементов типа Полка

    public:
        explicit Bookshelf(unsigned  int size);

        bool findBook(std::string title, std::string author); // проверяет, есть ли книга в шкафу
        unsigned int findShelf(std::string title, std::string author);// возвращает номер полки, на которой лежит книга

        // выводит "адрес" -- два числа, номер полки и место книги на ней
        void writeAddress(std::string title, std::string author);

        void addBook(unsigned int shelf_number, PrintBook abook);
        void putBook(unsigned int shelf_number, PrintBook afterbook, PrintBook putbook);
        void writeAll();   //  выводит на экран ВСЁ. Весь шкаф...
        void writeNumber(); // выводит количество книг в шкафу
        void writeShelf(unsigned int number); // выводит на экран содержимое полки
        void removeBook(std::string title, std::string author); // можно удалить книгу по названию и автору
        void removeBook(unsigned int shelf_number, unsigned int place); // а можно по её адресу

        PrintBook & getBook(std::string title, std::string author);
        PrintBook & getBook(unsigned int place, unsigned int shelf_number);

        unsigned int getSize();  // возвращает количество полок в шкафу
        void writeSize();       // выводит его на экран


        ~Bookshelf(); // деструктор
    };

#endif
