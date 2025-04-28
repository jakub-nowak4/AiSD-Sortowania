def zapisz_wynik(text):
    try:
        with open("wyniki.txt", 'r+') as plik:  # tryb read+write
            zawartosc = plik.read()

            if not zawartosc:
                plik.write("algorytm;rozmiar_tab;wariant_testu;czas\n")
            
            plik.seek(0, 2)  # przesuwamy się na koniec pliku
            plik.write(f"{text}\n")
            plik.flush()
    except FileNotFoundError:
        # Jeśli plik nie istnieje, tworzymy go i od razu zapisujemy nagłówek
        with open("wyniki.txt", 'w') as plik:
            plik.write("algorytm;rozmiar_tab;wariant_testu;czas\n")
            plik.write(f"{text}\n")
            plik.flush()


zapisz_wynik("test;test")