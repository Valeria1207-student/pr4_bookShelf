#include "bookshelf.h"

/* Этот файл посвящен капусте.
 * многие методы здесь -- просто обобщение методов класса полка
 * с более высоким уровнем абстракции
 * т е методы шкафа просто находят нужную полку и говорят ей делать свои аналогичные методы самой
 */


Bookshelf::Bookshelf(unsigned int size) : shelves(size){    // конструктор, делает вектор полок размера size
}


bool Bookshelf::findBook(std::string title, std::string author) {  // проверка наличия книги в шкафу
    for (Shelf shelf : shelves){
        if (shelf.findBook(title, author)) return true;

    }
    return false;
}

/*
 * пора объяснить, почему капуста (абстракция)
 * в методе ниже есть эпическая запись
 * shelves[number].getPlace(getBook(title, author));
 * где number на самом деле тоже является результатом вызова какого-то метода
 * и получается что-то такое:
 * элемент_массива[так, метод поиска номера нужного элемента, найди мне номер]
 * и для него вызывается .метод_поиска_места()
 *
 * (этот метод был эпичнее, правда, но я его поменяла, но принцип понятен наверное
 * в main будут записи длиннее и с большим количиством участников)
 *
 * в итоге получается, что шкаф просто заставляет маленькие методы кооперироваться и выполнять задачу для шкафа
 * и их описание похоже на капусту ._.
 */
// метод ниже выводит "адрес" -- два числа, номер полки и место книги на ней

void Bookshelf::writeAddress(std::string title, std::string author) {
    unsigned int number = 0;
    unsigned int place = 0;
    if (this->findBook(title, author)){
        number = findShelf(title, author);
        place = shelves[number].getPlace(title, author);
        std::cout << number << place << std::endl;
    } else std::cout << "Книга с названием " + title + " и автором " + author + " не найдена" << std::endl;
}


void Bookshelf::addBook(unsigned int shelf_number, PrintBook abook) { // говорит полке добавить книгу
    shelves[shelf_number].addBook(abook);
}


void Bookshelf::putBook(unsigned int shelf_number, PrintBook afterbook, PrintBook putbook) { // говорит полке
    shelves[shelf_number].putBook(afterbook, putbook);                             // добавить книгу на конкретное место
}


void Bookshelf::writeAll() {    // выводит всё содержимое всего
    for (Shelf shelf : shelves){
        shelf.writeShelf();
    }
}

void Bookshelf::writeShelf(unsigned int number) {   // выводит содержимое полке
    shelves[number].writeShelf();                  // точнее, говорит полке самовывестись )
}


void Bookshelf::removeBook(std::string title, std::string author) {    // удадяет книгу
    shelves[findShelf(title, author)].removeBook(title, author);      // мне очень нравится
}

void Bookshelf::removeBook(unsigned int shelf_number, unsigned int place) {    // удаляет книгу с места
    shelves[shelf_number].removeBook(place);
}


unsigned int Bookshelf::getSize() {    // возвращает размер шкафа
    return shelves.size();
}

void Bookshelf::writeNumber() { // пишет размер шкафа на экран
    int all = 0;
    for (Shelf shelf : shelves){
        all += shelf.getSize();
    }
    std::cout << all << std::endl;
}



void Bookshelf::writeSize() {   // пишет размер полки
    std::cout << shelves.size() << std::endl;
}


////////////////////////////////// Эти методы используют исключения ////////////////////////////////////////////////////

unsigned int Bookshelf::findShelf(std::string title, std::string author){  // возвращает полку на которой книга
    for (int i = 0; i < shelves.size(); i++){
        if (shelves[i].findBook(title, author))
            return i;
    }   // если ни на одной из полок этой книги нет
    throw std::domain_error("Книга с названием " + title + " и автором " + author + " не найдена\n");
}

PrintBook & Bookshelf::getBook(std::string title, std::string author) {    // возвращает книгу по названию и автору
    return shelves[findShelf(title, author)].getBook(title, author);
}


PrintBook & Bookshelf::getBook(unsigned int place, unsigned int shelf_number) { // возвращает книгу по адресу
    return shelves[shelf_number].getBook(place);
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


Bookshelf::~Bookshelf() {   // вы знаете кто это

}
