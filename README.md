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
każdy element należy do komórki, która przechowuje wskaźnik do kolejnej komórki.
W konsekwencji, aby dostać się do *i*-tego elementu musimy przejść przez *i*−1 elementów go poprzedzających.
- [`std::deque`](https://en.cppreference.com/w/cpp/container/deque) - dwukierunkowa kolejka (możemy dodawać elementy na końcu i na początku).
Typowe implementacje alokują pamięć blokami (np. na 16 elementów, nie na 1).

## `std::vector`
Kontenerem, po który sięgamy najczęściej, jest wektor.
Wynika to z wygody, którą nam oferuje: zachowuje się z grubsza jak tradycyjna tablica (dane ciągłe w pamięci, indeksowany dostęp przy pomocy operatora `[ ]`), z tą różnicą, że potrafi dynamicznie zwiększać swoją pojemność według naszej potrzeby.
Pod maską, wektor składa się tak naprawdę z 3 pól: wskaźnika do pierwszego elementu, długości (`size`) i pojemności (`capacity`).
Kontener zbliżony do wektora poznaliśmy już na 2. laboratorium - wtedy pisaliśmy go sami.

### Tworzenie i niszczenie wektora
Najczęściej korzystamy z poniższych konstruktorów wektora typu `std::vector<T>`:
1. konstruktor domyślny - tworzy pusty wektor
2. konstruktor przyjmujący `unsigned int` - tworzy wektor o rozmiarze równym podanej liczbie, wypełniony elementami skonstruowanymi przy pomocy konstruktora domyślnego klasy T (jeżeli takiego nie ma nasz kod się nie skompiluje)
3. konstruktor przyjmujący `unsigned int` i obiekt typu `T` - wypełnia wektor liczbą kopii przyjętego obiektu równą podanej liczbie
4. konstruktor przyjmujący listę (w znaczeniu `std::initializer_list`) elementów, które mają zostać do niego podane
5. konstruktory kopiujące is przenoszące

Destruktor wektora poprawnie dealokuje pamięć, a w konsekwencji niszczy wszystkie zawarte w nim obiekty.
Zachowanie to jest zgodne z naszymi oczekiwaniami i pozwala nam skupić się na ważniejszych rzeczach; nie musimy martwić się o wołanie `delete[ ]`.

### Dodawanie elementów do wektora
Nowe elementy dodajemy do wektora przy pomocy metod `push_back` oraz `emplace_back`.
Nazewnictwo to zgodne jest z konwencją biblioteki standardowej:
- `push` - sugeruje, że wkładamy do tablicy element, który istnieje gdzie indziej w programie, tzn. wykonuje jego kopię i dodaje do wektora
- `emplace` - sugeruje, że element jest tworzony w miejscu (*in place*), tzn. `emplace_back` przyjmuje argumenty konstruktora elementu, który tworzony jest już w wektorze - omijamy kopię
- `back` - ten sufiks sugeruje, że element dodawany jest na końcu wektora (niektóre kontenery potrafią dodawać elementy także od przodu)

Zobaczmy różnicę między `push_back` i `emplace_back` na przykładzie:
```C++
std::vector<std::string> vs;      // pusty wektor stringów
std::string wyraz{"słowo"};       // przykładowy string
vs.push_back(wyraz);              // dodaj kopię istniejącego stringa do wektora
wyraz += " drugie słowo";         // obiekt wyraz istnieje niezależnie
vs.emplace_back("trzecie słowo"); // skonstruuj string na końcu wektora na podstawie const char*
```
Warto zaznaczyć, że tak naprawdę `push_back` woła `emplace_back` - wykorzystuje on wtedy konstruktor kopiujący (lub przenoszący).

### Indeksowanie
Indeksowanie po wektorze odbywa się przy pomocy operatora `[ ]`, dokładnie tak jak po zwykłej tablicy.
Sięgnięcie poza zakres (`v[i]`, gdzie `i >= v.size()`) jest nielegalne (zachowanie analogiczne do tradycyjnej tablicy).
Wektor trawersować możemy także używając iteratorów, ale o tym później.

### Usuwanie elementów
Ostatni element wektora możemy usunąć przy pomocy metody `pop_back`.

### Zadania
Przećwiczmy teraz wymienioną powyżej funkcjonalność szablonu `std::vector`.

#### Zadanie 1
Stwórz pusty wektor `int`ów.
Wyświetl jego rozmiar i pojemość.
Napisz pętlę, w której dodasz do niego dowolną liczbę całkowitą (użyj `push_back` lub `emplace_back`, w tym przypadku jest to bez znaczenia), a następnie wyświetlisz rozmiar i pojemność wektora.
Wykonaj ciało pętli np. 100 razy.
Jak zmienia się pojemność wektora, gdy jest on zapełniony i dodajesz do niego element?

#### Zadanie 2
W każdej iteracji napisanej pętli wyświetl dodatkowo adres pierwszego elementu (`&v[0]`).
Czy pozostaje on stały wraz ze wzrostem rozmiaru wektora?
Dlaczego tak/nie?

#### Zadanie 3
Stwórz przy pomocy konstruktora nr 3 wektor 100 `int`ów o wartości 42.
Wyświetl jego długość i pojemność.
Wykonaj program 2 razy, raz używając do inicjalizacji nawiasów `()`, a raz `{}`.
Jakie będą efekty?
Dlaczego tak się dzieje?
Zapytaj osobę prowadzącą zajęcia.

**Podpowiedź**: chodzi o specjalne zasady konstrukcji dotyczące `std::initializer_list`.

**Wniosek**: w większości przypadków nadal preferujemy inicjalizację przy pomocy nawiasów klamrowych, natomiast w przypadku klas posiadających konstruktory przyjmujące `std::initializer_list` musimy zachować czujność i postępować ostrożnie.

#### Zadanie 4
Napisz program, który tworzy w pętli na podstawie danych podanych do konsoli obiekty klasy `Human` i przechowuje je w wektorze (wczytuj z klawiatury przynajmniej imię).
Porównaj, jak wyglądał będzie program, gdy użyjesz `push_back` i `emplace_back`.
Zastanów się ile kopii obiektu `std::string` wykonujesz.
Przemyśl jak może Ci pomóc `std::move` (`std::string` ma dobrze zdefiniowaną semantykę przenoszenia).

#### Zadanie 5
Zmodyfikuj program tak, aby podanie do konsoli konkretnej wartości (np. "pop") powodowało usunięcie ostatniego elementu.

#### Zadanie 6
Zweryfikuj poprawne wykonanie poprzedniego zadania wyświetlając imiona osób zawartych w wektorze.

## `std::list`
Lista jest jedną z najprostszych struktur danych.
Składa się ona z węzłów (ang. *node*) - każdy węzeł przechowuje 1 element oraz wskaźnik do kolejnego węzła (ostatni węzeł wskazuje na `nullptr`).
Jeżeli węzły przechowują także wskaźnik do poprzedniego węzła, mówimy o liście dwukierunkowej.
Pomocna w zrozumieniu tej struktury danych może być następująca wizualizacja rozkładu w pamięci elementów listy jednokierunkowej:

![list.png](graphics/list.png)

Jak widać, możemy dodawać nowe elementy na dowolnej pozycji listy (z przodu, z tyłu, gdzieś w środku) bez konieczności przesuwania elementów już istniejących.
Ceną, którą płacimy za tę wygodę jest czas dostępu do elementów - aby dostać się do *i*-tego elementu, musimy przejść przez *i* - 1 elementów go poprzedzających.

Listy są tematem, na który moglibyśmy poświęcić osobne zajęcia.
Tutaj przytaczamy je jedynie dla kontrastu z wektorem, aby zobrazować, że biblioteka standardowa zapewnia podobny interfejs dla drastycznie różniących się kontenerów.

### Tworzenie i niszczenie listy
Na zajęciach rozważymy jedynie konstruktor domyślny, tworzący pustą listę.
Jak nietrudno się domyślić, destruktor listy niszczy wszystkie jej węzły, dzięki czemu nie doznajemy wycieku pamięci.

### Dodawanie elementów do listy
Na zajęciach pominiemy dodawanie elementów w środku listy (choć nie jest szczególnie skomplikowane, zainteresowanych odsyłamy do dokumentacji metody `insert`).
Rozważymy następujące 4 metody służące do dodawania elementów na końcach:
- `push_back`
- `emplace_back`
- `push_front`
- `emplace_front`

Ich działanie jest analogiczne wobec metod szablonu `std::vector`.
Jak widzimy ujednolicone nazewnictwo pomaga nam przy poznawaniu nowych kontenerów - nie musimy za każdym razem uczyć się nowych nazw metod.

### Dostęp do elementów listy
Dostęp do elementów listy uzyskujemy przeważnie przy pomocy iteratorów (o których powiemy niżej).
Na chwilę obecną ograniczymy się do metod `front` i `back`, które zwracają referencję odpowiednio do pierwszego i ostatniego elementu listy.

### Usuwanie elementów z listy
Pierwszy i ostatni element listy możemy usunąć odpowiednio przy użyciu metod `pop_front` i `pop_back`.
Metodę `erase`, usuwającą elementy ze środka listy, pozostawiamy dla chętnych.

#### Zadanie 7
Stwórz pustą listę typu `int`.
Dodaj do niej 1 element.
Wydrukuj pierwszy i ostatni element listy.

#### Zadanie 8
Dodaj do listy drugi element (z przodu lub z tyłu).
Wydrukuj je ponownie.

#### Zadanie 9
Wydrukuj adresy pierwszego i ostatniego elementu.
Czy są one blisko siebie?

#### Zadanie 10
Dodaj z przodu listy kilka elementów.
Czy zmienił się adres ostatniego elementu?
Dlaczego tak/nie?

#### Zadanie 11
Sprawdź, czy lista ma zdefiniowany operator nawiasów kwadratowych (indeksowania)?
Jak sądzisz, dlaczego tak jest?

## Iteratory
Jak zobaczyliśmy w zadaniu 11, 

- (forward) iterator - metody `begin()` i `end()`
- reverse iterator - metody `rbegin()` i `rend()`
- `const` (forward) iterator - metody `cbegin()` i `cend()`
- `const` reverse iterator - metody `crbegin()` i `crend()`

![iterators.png](graphics/iterators.png)

### `auto`

### Range-based `for` loop
