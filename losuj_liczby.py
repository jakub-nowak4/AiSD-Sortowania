import random

min,max = -100, 100

def generuj_losowe(n):

    with open("./dane.txt","w") as file:
        for _ in range(n):
            liczba = random.randint(min,max)
            file.write(f"{liczba}\n")



def generuj_losowe_rosnaco(n):

    with open("./dane.txt","w") as file:
        liczby = [random.randint(min,max) for _ in range(n)]
        liczby.sort()

        for liczba in liczby:
            file.write(f"{liczba}\n")


def generuj_losowe_malejaco(n):

    with open("./dane.txt","w") as file:
        liczby = [random.randint(min,max) for _ in range(n)]
        liczby.sort(reverse=True)

        for liczba in liczby:
            file.write(f"{liczba}\n")
