import subprocess
import losuj_liczby
from zapisywanie_wynikow import zapisz_wynik


grupa_pierwsza = ["bubble_sort","insertion_sort","selection_sort"]
grupa_druga = ["quick_sort","shell_sort","heap_sort"]

# grupa_pierwsza_test = [x for x in range(100_000, 750_001,50_000)]
# grupa_druga_test = [x for x in range(1_000_000,15_000_001,1_000_000)]

grupa_pierwsza_test = [x for x in range(100_000, 350_001,50_000)]
grupa_druga_test = [x for x in range(100_000, 350_001,50_000)]

wszytskie_grupy = grupa_pierwsza + grupa_druga

#Kompiluj makefile
make_process = subprocess.run(['make'],capture_output=True,text=True)
if make_process.returncode != 0:
    print("Make filed with error: ")
    print(make_process.stderr)
    exit(1)

for algorytm in wszytskie_grupy:

    if algorytm in grupa_pierwsza:
        for wariant in range(3):
            for test in grupa_pierwsza_test:
                
                if wariant == 0:
                    losuj_liczby.generuj_losowe(test)
                elif wariant == 1:
                    losuj_liczby.generuj_losowe_rosnaco(test)
                else:
                    losuj_liczby.generuj_losowe_malejaco(test)

                print(f"Test dla {algorytm}, n = {test} wariant = {'losowo' if wariant == 0 else 'rosnaco' if wariant == 1 else 'malejaco'}")

                program_process = subprocess.run(['./sortowanie'] + [algorytm,str(test)],capture_output=True,text=True,check=True)

                czas = program_process.stdout
                wynik = f"{algorytm};{test};{'losowo' if wariant == 0 else 'rosnaco' if wariant == 1 else 'malejaco'};{czas}"
                zapisz_wynik(wynik)


    elif algorytm in grupa_druga:
        for wariant in range(3):
            for test in grupa_druga_test:

                if wariant == 0:
                    losuj_liczby.generuj_losowe(test)
                elif wariant == 1:
                    losuj_liczby.generuj_losowe_rosnaco(test)
                else:
                    losuj_liczby.generuj_losowe_malejaco(test)

                print(f"Test dla {algorytm}, n = {test} wariant = {'losowo' if wariant == 0 else 'rosnaco' if wariant == 1 else 'malejaco'}")

                program_process = subprocess.run(['./sortowanie'] + [algorytm,str(test)],capture_output=True,text=True,check=True)

                czas = program_process.stdout
                wynik = f"{algorytm};{test};{'losowo' if wariant == 0 else 'rosnaco' if wariant == 1 else 'malejaco'};{czas}"
                zapisz_wynik(wynik)

    else:
            print(f"Nie znaleziono algorytmu {algorytm} w żadnej z grup!")

print("Zakończono testy...")