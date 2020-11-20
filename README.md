# Laboratorium V
## Wstęp
Na dzisiejszych zajęciach przyjrzymy się kontenerom dostępnym w STL.
Kontenery to klasy, które służą do przechowywania wielu obiektów danego typu.
Sposób przechowywania obiektów (struktura danych) jest jednym z najbardziej kluczowych zagadnień programowania.
W 1976r. Niklaus Wirth opublikował nawet książkę o słynnym tytule *Algorithms + Data Structures = Programs*.
Biblioteka standardowa oferuje szeroką gamę różnych kontenerów, której nie mamy niestety czasu omówić w pełni.
Zamiast tego, postaramy bliżej zapoznać się jedynie z kilkoma wybranymi kontenerami i wyciągnąć możliwie ogólne wnioski dotyczące korzystania z nich.
Podkreślmy, że nie ma kontenerów lepszych i gorszych, a jedynie takie, które lepiej lub gorzej nadają się do rozwiązania konkretnego problemu.

Aby móc skupić się na zachowaniu kontenerów, a nie szczegółach typów, które mają być w nich przechowywane, do niniejszej instrukcji dołączony jest plik `Human.hpp`, w którym zaimplementowana jest klasa reprezentująca człowieka.
Zadania zebrane poniżej zakładają, że czytelnik ma do niego dostęp.

## Wybrane typy kontenerów
Poniżej wymienione zostało kilka podstawowych kontenerów STL.
Warto rozumieć ich działanie, a przynajmniej wiedzieć o ich istnieniu.

- [`std::vector`](https://en.cppreference.com/w/cpp/container/vector) - dynamicznie alokuje ciągły blok pamięci na trzymane obiekty.
Po zapełnieniu alokuje nowy, większy blok pamięci i przepisuje do niego elementy.
- [`std::array`](https://en.cppreference.com/w/cpp/container/array) - statycznie alokuje blok pamięci o rozmiarze określonym przez parametr szablonu.
Pozwala na łatwe kopiowanie zawartości (ma dobrze zdefiniowane metody specjalne).
- [`std::map`](https://en.cppreference.com/w/cpp/container/map) - przechowuje pary klucz-element (typy obu określone przez parametry szablonu).
Pozwala na dostęp do elementów poprzez klucz, np. `mapa_ocen["Janina Kowalska"] = 5`.
- [`std::list`](https://en.cppreference.com/w/cpp/container/list) - rozprasza elementy w pamięci.
każdy element należy do komórki, która przechowuje wskaźnik do kolejnej komórki (ostatnia komórka wskazuje na `nullptr`).
W konsekwencji, aby dostać się do *i*-tego elementu musimy przejść przez *i*−1 elementów go poprzedzających.
- [`std::deque`](https://en.cppreference.com/w/cpp/container/deque) - dwukierunkowa kolejka (możemy dodawać elementy na końcu i na początku).
Typowe implementacje alokują pamięć blokami (np. na 16 elementów, nie na 1).
