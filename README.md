#Машина на Тюринг

Да се реализира библиотека за ефективна работа с машини на Тюринг. Машините на Тюринг имат потенциално безкрайна двупосочна лента, в която могат да бъдат записвани произволни символи. Първоначално лентата е инициализирана с интервали.

Машината на Тюринг се задава със следния синтаксис:
* <състояние> ::= ​{ <низ> }
* <команда> ::= ​L​ | ​R​ | ​S
* <преход> ::= <символ><състояние> ​->​ <символ><състояние><команда>

Командите управляват движението на главата, съответно наляво (L), надясно (R), или без промяна (S). Специалното състояние ​{halt}​ спира изпълнението на машината.

Пример:​ ​6{increment} -> 7{decrement}L

Да се поддържат следните операции над машини на Тюринг:
* композиция на две машини на Тюринг
* разклонение на две машини на Тюринг относно трета (пуска се третата машина над даден вход и в зависимост дали крайният резултат е 1 (истина) или 0 (лъжа), се пуска първата или втората машина над същия вход
* функция, която връща машина на Тюринг, реализираща while-цикъл над дадена машина на Тюринг, където условието се задава с друга машина на Тюринг

Да се реализира програма, която прочита от входен файл информация за машина на Тюринг и състояние на лентата, след което изпълнява машината на Тюринг върху така зададената лента. Ако машината завърши, да се изведе в изходен файл състоянието на изходната лента.