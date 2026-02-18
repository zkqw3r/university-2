#include <SFML/Graphics.hpp>
#include <functional> 
#include <cmath> 
#include <iostream>


// Функция для отрисовки графика
void drawGraph(sf::RenderWindow& window, std::function<float(float)> func, float xMin, float xMax, float scaleX, float scaleY, sf::Color color) {
    sf::VertexArray graph(sf::LinesStrip);

    for (float x = xMin; x <= xMax; x += 0.1f) {
        float y = func(x); // Вычисление значения функции

        // Преобразование координат в экранные
        float screenX = 400 + x * scaleX;
        float screenY = 300 - y * scaleY;

        // Добавление точки в массив вершин
        graph.append(sf::Vertex(sf::Vector2f(screenX, screenY), color));
    }

    window.draw(graph);
}

float f1(float x) {
    return x * x; // Пример функции y = x^2
}

float f2(float x) {
    return x + 9; // Пример функции y = x + 9
}

int main() {
    // Создание окна

    sf::RenderWindow window(sf::VideoMode(800, 600), "Application for displaying graphs");

    // Переменная для хранения пользовательской точки
    sf::CircleShape userPoint(5); // Радиус 5 пикселей
    userPoint.setFillColor(sf::Color::Red);
    bool userPointExists = false; // Переменная для проверки существования пользовательской точки

    // 1 _ Загрузка шрифта
    sf::Font font;
    if (!font.loadFromFile("arial.ttf")) {
        return -1;
    }
    // 2 _ Текст для отображения координат точки
    // Размер текста 20, положение текста (10,10), цвет белый.
    sf::Text coordinatesText;
    coordinatesText.setFont(font);
    coordinatesText.setCharacterSize(20);
    coordinatesText.setFillColor(sf::Color::White);
    coordinatesText.setPosition(10, 10);

    // Оси X и Y
    sf::VertexArray xAxis(sf::Lines, 2);
    xAxis[0].position = sf::Vector2f(50, 300); // Начало оси X
    xAxis[0].color = sf::Color::White; // Цвет оси
    xAxis[1].position = sf::Vector2f(750, 300); // Конец оси X
    xAxis[1].color = sf::Color::White;

    sf::VertexArray yAxis(sf::Lines, 2);
    yAxis[0].position = sf::Vector2f(400, 50); // Начало оси Y
    yAxis[0].color = sf::Color::White; // Цвет оси
    yAxis[1].position = sf::Vector2f(400, 550); // Конец оси Y
    yAxis[1].color = sf::Color::White;

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();

            // Проверка клика мышью
            if (event.type == sf::Event::MouseButtonPressed) {
                if (event.mouseButton.button == sf::Mouse::Left) {
                    // Получение позиции клика
                    sf::Vector2i mousePos = sf::Mouse::getPosition(window);

                    // Преобразование экранных координат в "математические"
                    float mathX = (mousePos.x - 400) / 10.0f; // Масштаб 10 по X
                    float mathY = -(mousePos.y - 300) / 10.0f; // Масштаб 10 по Y

                    // Установка новой пользовательской точки
                    userPoint.setPosition(mousePos.x - userPoint.getRadius(), mousePos.y - userPoint.getRadius());
                    userPointExists = true; // Помечаем, что точка существует

                    // 3 _ Логика проверки точки по переменным mathX и mathY

                    std::string pos;

                    if ( f2(mathX) == mathY || f1(mathX) == mathY) {
                        pos = "Граница";
                    }
                    else if (f2(mathX) > mathY && f1(mathX) > mathY) {
                        pos = "2";
                    }
                    else if (f2(mathX) > mathY && f1(mathX) < mathY) {
                        pos = "3";
                    }
                    else if (f2(mathX) < mathY && f1(mathX) < mathY) {
                        pos = "5";
                    }
                    else if ((f2(mathX) < mathY) && (f1(mathX) > mathY) && mathX < 0) {
                        pos = "1";
                    }
                    else if ((f2(mathX) < mathY) && (f1(mathX) > mathY) && mathX > 0) {
                        pos = "4";
                    }

                    // Обновление текста с координатами точки 
                    coordinatesText.setString("Coordinates: (" + std::to_string(mathX) + ", " + std::to_string(mathY) + ")\nArea: " + pos);
                }
            }
        }


        // 4 _ Очистка экрана
        window.clear();
        // 


        // Отрисовка осей
        window.draw(xAxis);
        window.draw(yAxis);



        // 5 _  Отрисовка графика y1 = x^2
        drawGraph(window, [](float x) { return x * x; }, -10, 10, 10, 10, sf::Color::Blue);

        // 5 _   Отрисовка графика y2 = x + 9
        drawGraph(window, [](float x) { return x + 9; }, -10, 10, 10, 10, sf::Color::Red);

        // Отрисовка пользовательской точки, если она существует
        if (userPointExists) {
            window.draw(userPoint);
            window.draw(coordinatesText);
        }

        // Отображение нового кадра
        window.display();
    }

    return 0;
}
