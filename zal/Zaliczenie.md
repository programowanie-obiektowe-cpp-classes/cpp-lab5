# Zaliczenie Laboratorium V
Twoim zadaniem jest napisanie w pliku `foo.hpp` funkcji `foo`, która:
- Przyjmuje przez referencję listę obiektów typu `Human`.
- Zwraca wektor obiektów typu `char`.
- Inkrementuje pole `age` wszystkich obiektów w podanej liście poprzez zawołanie metody `birthday`.
- Do zwracanego wektora wpisuje znaki `y` lub `n` (yes/no) w zależności od tego, czy dana osoba lubi co najmniej jedno ze zbioru zwierząt {pies, kot} (`y` jeżeli tak, `n` jeżeli nie).
Kolejność znaków powinna być odwrotna od kolejności osób.
Do sprawdzenia warunku użyj metody `isMonster`.
Innymi słowy, jeżeli metoda `isMonster` *i*-tej osoby na liście zwróci wartość `true`, to (*n* - *i*)-ty element zwracanego wektora powinien mieć wartość `n`
