# Змейка в терминале, на C++
Вот так выглядит захватывающий геймплей  
![Вывод в терминал](imgs/new.gif)
## Запуск змейки:
### С помощью Docker:
Один раз делаем билд:
```
docker build -t ifan/snake .
```
И теперь запускаем змейку с помощью:
```
docker run -it ifan/snake
```
### Либо собрать самим:
Установка необходимых компонентов:
```
apt-get update
apt-get install gcc cmake build-essential libncurses5-dev
```
Создание билда:
```
cmake -S . -B ./build
cmake --build build
```
Запуск змейки:
```
./build/terminal_snake
```
