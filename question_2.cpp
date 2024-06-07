/*
 * Question: На языке С++, написать минимум по 2 класса реализовывающих циклический буфер.
 * Объяснить плюсы и минусы каждой реализации.
 */

/*
 * Задачу можно реализовать двумя способами:
 * 1 - с использованием массива
 * 2 - с использованием стандартного контейнера std::deque
 */

#include <deque>
#include <iostream>
#include <stdexcept>

class CircularBufferArray {
private:
    int size;
    int* buffer;
    int start;
    int end;

public:
    CircularBufferArray(int size) : size(size), start(0), end(0) {
        buffer = new int[size];
    }

    ~CircularBufferArray() {
        delete[] buffer;
    }

    void push(int value) {
        end = (end + 1) % size;
        buffer[end] = value;
        if (end == start) {
            start = (start + 1) % size;
        }
    }

    int pop() {
        if (start != end) {
            start = (start + 1) % size;
            return buffer[start];
        } else {
            throw std::out_of_range("Buffer is empty");
        }
    }
};

/*
 * Реализация задания с использованием массива.
 * Плюсы: Быстрый доступ к элементам, поскольку массивы обсепечивают прямой доступ к элементами.
 * Минусы: Размер буфера фиксированный, необходимо вручную управлять памятью.
 */

class CircularBufferDeque {
private:
    int size;
    std::deque<int> buffer;

public:
    CircularBufferDeque(int size) : size(size) {}

    void push(int value) {
        if (buffer.size() == size) {
            buffer.pop_front();
        }
        buffer.push_back(value);
    }

    int pop() {
        if (!buffer.empty()) {
            int value = buffer.front();
            buffer.pop_front();
            return value;
        } else {
            throw std::out_of_range("Buffer is empty");
        }
    }
};

/*
 * Реализация задания с использованием std::deque.
 * Плюсы: Размер буфера динамический, не нужно вручную управлять памятью.
 * Минусы: Доступ к элементам медленнее, чем у массивов.
 */

extern "C" {
int question_2_main();
}

int question_2_main() {
    CircularBufferArray bufferArray(5);
    std::cout << "Pushing values into CircularBufferArray...\n";
    bufferArray.push(1);
    bufferArray.push(2);
    bufferArray.push(3);
    bufferArray.push(4);
    bufferArray.push(5);
    bufferArray.push(6);
    std::cout << "Finished pushing values into CircularBufferArray.\n";

    try {
        std::cout << "Popping values from CircularBufferArray...\n";
        for (int i = 0; i < 5; i++) {
            std::cout << bufferArray.pop() << std::endl;
        }
        std::cout << "Finished popping values from CircularBufferArray.\n";
    } catch (const std::out_of_range& e) {
        std::cerr << e.what() << std::endl;
    }

    CircularBufferDeque bufferDeque(5);
    std::cout << "Pushing values into CircularBufferDeque...\n";
    bufferDeque.push(1);
    bufferDeque.push(2);
    bufferDeque.push(3);
    bufferDeque.push(4);
    bufferDeque.push(5);
    bufferDeque.push(6);
    std::cout << "Finished pushing values into CircularBufferDeque.\n";

    try {
        std::cout << "Popping values from CircularBufferDeque...\n";
        for (int i = 0; i < 5; i++)
            std::cout << bufferDeque.pop() << std::endl;
        std::cout << "Finished popping values from CircularBufferDeque.\n";
    } catch (const std::out_of_range& e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}