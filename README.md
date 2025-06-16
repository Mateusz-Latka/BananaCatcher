# 🍌 Banana Catcher

**Banana Catcher** to prosta gra 2D stworzona w języku **C++** z wykorzystaniem biblioteki **SFML 3.0**. Gracz wciela się w małpkę i łapie spadające banany, zdobywając punkty. Zbyt wiele pominiętych bananów kończy grę!

---

## 🎮 Zasady gry

- Poruszaj małpką w lewo i prawo za pomocą **strzałek ← / →**
- Zbieraj banany zanim spadną na ziemię
- Każdy złapany banan to **+1 punkt**
- Każdy nietrafiony banan to **-1 życie**
- Po utracie wszystkich żyć pojawia się ekran **Game Over**, a gra się restartuje

---

## 🧩 Funkcje

- Obsługa klawiatury (strzałki)
- Losowe spadanie bananów
- Detekcja kolizji (gracz–banan)
- Licznik punktów i żyć
- Proste grafiki wczytywane z plików PNG
- Łatwe do rozbudowania o dźwięki, poziomy, menu itd.

---

## 🛠 Wymagania

- Visual Studio 2022+ (lub kompatybilne środowisko C++)
- SFML 3.0 (https://www.sfml-dev.org/)

---

## 🧪 Budowanie i uruchamianie

1. Skonfiguruj ścieżki do SFML:

   - **C/C++ → General → Additional Include Directories**:  
     `C:\Libraries\SFML\include`

   - **Linker → General → Additional Library Directories**:  
     `C:\Libraries\SFML\lib`

   - **Linker → Input → Additional Dependencies (Debug)**:
     ```
     sfml-graphics-d.lib
     sfml-window-d.lib
     sfml-system-d.lib
     ```

2. Upewnij się, że pliki:
   - `banana.png`
   - `monkey.png`
   - `jungle.png`  
   znajdują się w katalogu wykonywalnym (`x64/Debug` lub `Release`).

3. Zbuduj projekt (`BananaCatcher.sln`) i uruchom grę.

