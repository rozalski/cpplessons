#include <SFML/Graphics.hpp>
#include <iostream>

using namespace sf;

class Player
{
public:
    float x,y,w,h,dx,dy,speed; // координаты х и у, высота и ширина игрока, ускорение и скорость
    int dir; // направление движения
    String File; //файл с расширением
    Image image;//сфмл изображение
    Texture texture;//сфмл текстура
    Sprite sprite;//сфмл спрайт
    Player(String F, float X, float Y, float W, float H)  //Конструктор с параметрами(формальными) для класса Player. При создании объекта класса мы будем задавать имя файла, координату Х и У, ширину и высоту
    {
        dx=0;
        dy=0;
        speed=0;
        dir=0;
        File = F;//имя файла+расширение
        w = W;
        h = H;//высота и ширина
        image.loadFromFile("images/" + File);//запихиваем в image наше изображение вместо File мы передадим то, что пропишем при создании объекта. В нашем случае "hero.png" и получится запись идентичная image.loadFromFile("images/hero/png");
        image.createMaskFromColor(Color(41, 33, 59));//убираем ненужный темно-синий цвет, эта тень мне показалась не красивой.
        texture.loadFromImage(image);//закидываем наше изображение в текстуру
        sprite.setTexture(texture);//заливаем спрайт текстурой
        x = X;
        y = Y;//координата появления спрайта
        sprite.setTextureRect(IntRect(0, 0, w, h)); //Задаем спрайту один прямоугольник для вывода одного льва, а не кучи львов сразу. IntRect - приведение типов
    }
    void update(float time) //функция "оживления" объекта класса. update - обновление. принимает в себя время SFML , вследствие чего работает бесконечно, давая персонажу движение.
    {
        switch (dir)//реализуем поведение в зависимости от направления. (каждая цифра соответствует направлению)
        {
        case 0:
            dx = speed;
            dy = 0;
            break;//по иксу задаем положительную скорость, по игреку зануляем. получаем, что персонаж идет только вправо
        case 1:
            dx = -speed;
            dy = 0;
            break;//по иксу задаем отрицательную скорость, по игреку зануляем. получается, что персонаж идет только влево
        case 2:
            dx = 0;
            dy = speed;
            break;//по иксу задаем нулевое значение, по игреку положительное. получается, что персонаж идет только вниз
        case 3:
            dx = 0;
            dy = -speed;
            break;//по иксу задаем нулевое значение, по игреку отрицательное. получается, что персонаж идет только вверх
        }

        x += dx*time;//то движение из прошлого урока. наше ускорение на время получаем смещение координат и как следствие движение
        y += dy*time;//аналогично по игреку

        speed = 0;//зануляем скорость, чтобы персонаж остановился.
        sprite.setPosition(x,y); //выводим спрайт в позицию x y , посередине. бесконечно выводим в этой функции, иначе бы наш спрайт стоял на месте.
    }

};

int main()
{

    RenderWindow window(sf::VideoMode(640, 480), "Lesson 4. kychka-pc.ru");

Player p("bart.png", 50, 0, 21, 40);//создаем объект p класса player,задаем "hero.png" как имя файла+расширение, далее координата Х,У, ширина, высота.


    Texture herotexture;
    herotexture.loadFromFile("images/bart.png");
    int stepFrX =50;
    Sprite herosprite;
    herosprite.setTexture(herotexture);
    herosprite.setTextureRect(IntRect(50,0,21,40));
    herosprite.setPosition(50, 250);
    float curentFrame = 1;
    Clock clock;

    while (window.isOpen())
    {
        float time = clock.getElapsedTime().asMicroseconds();
        clock.restart();
        time =time/800;
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        if(Keyboard::isKeyPressed(Keyboard::Right))
        {

            curentFrame += 0.01*time;
            if(curentFrame>4)
            {
                curentFrame -=4;
            }
            herosprite.setTextureRect(IntRect(50+(int(curentFrame)*19),0,21,40)); //x,y
            herosprite.move(0.1*time,0);
        }
        if(Keyboard::isKeyPressed(Keyboard::Left))
        {
            curentFrame += 0.01*time;
            if(curentFrame>4)
            {
                curentFrame -=4;
            }

            herosprite.setTextureRect(IntRect(50+(int(curentFrame)*19+21),0,-21,40)); //x,y

            herosprite.move(-0.1*time,0);
        }
        if(Keyboard::isKeyPressed(Keyboard::Up))
        {
            herosprite.setScale(1.5,1.5);


            //  herosprite.move(0,-0.1*time);
        }
        if(Keyboard::isKeyPressed(Keyboard::Down))
        {
            herosprite.setScale(1,1);
            //herosprite.move(0,0.1*time);
        }

        window.clear();
        window.draw(herosprite);
        window.display();
    }

    return 0;
}
