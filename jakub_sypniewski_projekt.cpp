//Projekt zaliczeniowy
//Wykona�: Jakub Sypniewski
//Numer albumu: 73030
#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include <fstream>
#include <vector>
#include <string>

using namespace std;


void powrot_do_menu()
{
    cout << "Wybierz [1] aby zamkn�� program." << endl;
    cout << "Wci�nij dowolny inny klawisz aby powr�ci� do menu." << endl;

    char user_input;
    cin >> user_input;

    if (user_input == '1')
    {
        cout << "Zamykam program." << endl;
        exit(0);
    }
}

void zapisz_do_pliku(float wynagrodzenie_brutto, float skladka_ubezpieczenie_emerytalne, float skladka_ubezpieczenie_chorobowe, float skladka_ubezpieczenie_rentowe,
    float skladka_ubezpieczenie_zdrowotne, float zaliczka_podatek_dochodowy, float wynagrodzenie_netto, string nazwa_pliku)
{
    FILE* pFile;

    nazwa_pliku = nazwa_pliku + ".txt";
    const char* nazwa_pliku_c = nazwa_pliku.c_str();

    pFile = fopen(nazwa_pliku_c, "w");

    fprintf(pFile, "----------------------------------------------------- \n");
    fprintf(pFile, "|%40s|%10.2f| \n", "Wynagrodzenie brutto", wynagrodzenie_brutto);
    fprintf(pFile, "===================================================== \n");

    fprintf(pFile, "|%40s|%10.2f| \n", "Sk�adka na ubezpieczenie emerytalne", skladka_ubezpieczenie_emerytalne);
    fprintf(pFile, "----------------------------------------------------- \n");
    fprintf(pFile, "|%40s|%10.2f| \n", "Sk�adka na ubezpieczenie chorobowe", skladka_ubezpieczenie_chorobowe);
    fprintf(pFile, "----------------------------------------------------- \n");
    fprintf(pFile, "|%40s|%10.2f| \n", "Sk�adka na ubezpieczenie rentowe", skladka_ubezpieczenie_rentowe);
    fprintf(pFile, "----------------------------------------------------- \n");
    fprintf(pFile, "|%40s|%10.2f| \n", "Sk�adka na ubezpieczenie zdrowotne", skladka_ubezpieczenie_zdrowotne);
    fprintf(pFile, "----------------------------------------------------- \n");
    fprintf(pFile, "|%40s|%10.2f| \n", "Zaliczka na podatek dochodowy", zaliczka_podatek_dochodowy);
    fprintf(pFile, "----------------------------------------------------- \n");
    fprintf(pFile, "|%40s|%10.2f| \n", "Wynagrodzenie netto", wynagrodzenie_netto);
    fprintf(pFile, "----------------------------------------------------- \n");
    printf("\n");

    fclose(pFile);
    printf("Zapisano do pliku.");
}

void tabela_skladki()
{
    system("cls");
    cout << "=========================== Tabela sk�adek ===========================" << endl;
    cout << "======================================================================" << endl;
    cout << "-----------------------------------------------------------------------------------------------" << endl;
    printf("|%30s|%20s|%20s|%20s|", "rodzaj sk�adki", "stopy procentowe", "pokrywa pracownik", "pokrywa pracodawca");
    printf("\n");
    cout << "-----------------------------------------------------------------------------------------------" << endl;
    printf("|%30s|%20s|%20s|%20s|", "na ubezpieczenie emerytalne", "19.52%", "9.76%", "9.76%");
    printf("\n");
    cout << "-----------------------------------------------------------------------------------------------" << endl;
    printf("|%30s|%20s|%20s|%20s|", "na ubezpieczenie rentowe", "8.00%", "1.50%", "6.50%");
    printf("\n");
    cout << "--------------------------------------------------------- --------------------------------------" << endl;
    printf("|%30s|%20s|%20s|%20s|", "na ubezpieczenie chorobowe", "2.45%", "2.45%", "  -  ");
    printf("\n");
    cout << "-----------------------------------------------------------------------------------------------" << endl;
    printf("\n");
}

void tabela_koszty_uzyskania()
{
    system("cls");
    cout << "======================= Tabela koszt�w uzyskania =====================" << endl;
    cout << "======================================================================" << endl;
    cout << "---------------------------------------------------------------------------------------------------------------------" << endl;
    printf("|%23s|%38s|%52s|", "  ", "miesi�czne koszty uzyskania przychodu", "roczne koszty uzyskania przychodu");
    printf("\n");
    cout << "---------------------------------------------------------------------------------------------------------------------" << endl;
    printf("|%23s|%38s|%52s|", "pracownik miejscowy", "111.25 z�", "1335 z� z jednej umowy, 2002.05 z� z wielu um�w");
    printf("\n");
    cout << "---------------------------------------------------------------------------------------------------------------------" << endl;
    printf("|%23s|%38s|%52s|", "pracownik doje�d�aj�cy", "139.06 z�", "1668,72 z� z jednej umowy, 2502.56 z� z wielu um�w");
    printf("\n");
    cout << "---------------------------------------------------------------------------------------------------------------------" << endl;
    printf("\n");
}

void algorytm_obliczania_wynagrodzenia_netto()
{
    system("cls");
    cout << "=============== Algorytm obliczania wynagrodzenia netto ==============" << endl;
    cout << "======================================================================" << endl;
    cout << "1. Pobranie wynagrodzenia miesi�cznego brutto." << endl;
    cout << "2. Oliczenie sk�adek na ubezpieczenie: emerytalne, rentowe, chorobowe." << endl;
    cout << "3. Obliczenie sk�adki na ubezpieczenie zdrowotne." << endl;
    cout << "4. Obliczenie zaliczki na podatek dochodowy." << endl;
    cout << "5. Obliczenie zaliczki na podatek dochodowy do pobrania." << endl;
    cout << "6. Obliczenie wynagrodzenia netto." << endl;
    cout << "\n * Wyliczenie oparte na za�o�eniu, �e wynagrodzenie brutto w ci�gu roku nie ulega zmianie. \n" << endl;

}

void zasady_obliczen()
{
    char zasady_obliczania_wybor;

    do
    {
        system("cls");
        cout << "===============Zasady wyliczania wynagrodzenia netto.==============" << endl;
        cout << "===================================================================" << endl;
        cout << "Wybierz:" << endl;
        cout << "[0] - Zobacz tabel� sk�adek. " << endl;
        cout << "[1] - Zobacz tabel� koszt�w uzyskania " << endl;
        cout << "[2] - Sprawd� algorytm wyliczania wynagrodzenia netto " << endl;
        cin >> zasady_obliczania_wybor;

        switch (zasady_obliczania_wybor)
        {
        case '0':
            tabela_skladki();
            break;
        case '1':
            tabela_koszty_uzyskania();
            break;
        case '2':
            algorytm_obliczania_wynagrodzenia_netto();
            break;
        default:
            cout << "Niepoprawna odpowied�. Wybierz mi�dzy [0], [1] lub [2]." << endl;
            break;
        }
    } while (zasady_obliczania_wybor != '0' && zasady_obliczania_wybor != '1' && zasady_obliczania_wybor != '2');

    powrot_do_menu();
}

void jak_przygotowac_plik()
{
    cout << "Zasady przygotowania pliku wsadowego." << endl;
    cout << "Plik wsadowy ma sta�� konwencj�. Pobierana jest informacja o imieniu, nazwisku osoby, jej wynagrodzenie brutto oraz czy mieszka w miejscu gdzie pracuje(0 - nie, 1 - tak)." << endl;
    cout << "Dane dla jednej powinny by� rozdzielone spacjami, kolejne osoby powinny by� zapisane od nowej linii." << endl;
    cout << "Przyk�ad:" << endl;
    cout << "/n";
    cout << "jan kowalski 7200 1" << endl;
    cout << "anna nowak 12000 0" << endl;
}

void policz_wyplate(bool lista, string imie = "", string nazwisko = "", float brutto = 0, bool czy_miejscowy = true)
{
    system("cls");
    float wynagrodzenie_brutto;

    if (lista == false)
    {
        cout << "Podaj wynagrodzenie brutto (miesi�czne):" << endl;
        cin >> wynagrodzenie_brutto;
    }
    else
    {
        wynagrodzenie_brutto = brutto;
    }

    float skladka_ubezpieczenie_emerytalne_stopa_proc = 0.0976;
    float skladka_ubezpieczenie_rentowe_stopa_proc = 0.0150;
    float skladka_ubezpieczenie_chorobowe_stopa_proc = 0.0245;

    float skladka_ubezpieczenie_emerytalne;
    float skladka_ubezpieczenie_rentowe;
    float skladka_ubezpieczenie_chorobowe;
    float suma_skladek_na_ubezpieczenie;

    skladka_ubezpieczenie_emerytalne = wynagrodzenie_brutto * skladka_ubezpieczenie_emerytalne_stopa_proc;
    skladka_ubezpieczenie_rentowe = wynagrodzenie_brutto * skladka_ubezpieczenie_rentowe_stopa_proc;
    skladka_ubezpieczenie_chorobowe = wynagrodzenie_brutto * skladka_ubezpieczenie_chorobowe_stopa_proc;

    suma_skladek_na_ubezpieczenie = skladka_ubezpieczenie_chorobowe + skladka_ubezpieczenie_emerytalne + skladka_ubezpieczenie_rentowe;

    float podstawa_do_skladki_zdrowotnej;
    podstawa_do_skladki_zdrowotnej = wynagrodzenie_brutto - suma_skladek_na_ubezpieczenie;

    float skladka_ubezpieczenie_zdrowotne_stopa_proc = 0.09;
    float skladka_ubezpieczenie_zdrowotne;

    skladka_ubezpieczenie_zdrowotne = podstawa_do_skladki_zdrowotnej * skladka_ubezpieczenie_zdrowotne_stopa_proc;

    bool czy_pracownik_miejscowy{};
    char pracownik_miejscowy_odpowiedz;

    if (lista == false)
    {
        do
        {

            cout << "Czy mieszkasz w miejscowo�ci, w kt�rej pracujesz tak[1]/nie[0]?" << endl;
            cin >> pracownik_miejscowy_odpowiedz;

            switch (pracownik_miejscowy_odpowiedz)
            {
            case '1':
                czy_pracownik_miejscowy = true;
                break;
            case '0':
                czy_pracownik_miejscowy = false;
                break;
            default:
                cout << "Niepoprawna odpowied�. Wybierz mi�dzy TAK[1] oraz NIE[0]." << endl;
                break;
            }
        } while (pracownik_miejscowy_odpowiedz != '0' && pracownik_miejscowy_odpowiedz != '1');
    }
    else
    {
        czy_pracownik_miejscowy = czy_miejscowy;
    }

    float przychod;
    float koszt_uzyskania_przychodu;

    if (czy_pracownik_miejscowy == true)
    {
        koszt_uzyskania_przychodu = 111.25;
    }
    else
    {
        koszt_uzyskania_przychodu = 139.06;
    }

    przychod = wynagrodzenie_brutto - suma_skladek_na_ubezpieczenie - koszt_uzyskania_przychodu;


    float podatek_dochodowy;
    float podatek_dochodowy_stopa_proc = 0.18;
    float podatek_dochodowy_stopa_proc_wyzsza = 0.32;
    float miesieczna_kwota_wolna_od_podatku = 46.33;
    float kwota_minimalna_podatku_doch = 14839.02;
    float prog_podatku_dochodowego = 85528;

    if (wynagrodzenie_brutto * 12 > prog_podatku_dochodowego)
    {
        podatek_dochodowy = (kwota_minimalna_podatku_doch + (85528 - 12 * wynagrodzenie_brutto) * podatek_dochodowy_stopa_proc_wyzsza) / 12; // do sprawdzenia
    }
    else
    {
        podatek_dochodowy = przychod * podatek_dochodowy_stopa_proc - miesieczna_kwota_wolna_od_podatku;
    }

    //Dodatkowo badam opcj�, gdy roczny przych�d nie wyni�s� 3091z�. W�wczas podatek dochodowy jest zerowy
    if (przychod * 12 < 3091)
    {
        podatek_dochodowy = 0;
    }

    float skladka_zdrowotna;
    float skladka_zdrowotna_stawka = 0.0775;
    skladka_zdrowotna = podstawa_do_skladki_zdrowotnej * skladka_zdrowotna_stawka;

    float zaliczka_podatek_dochodowy;
    zaliczka_podatek_dochodowy = podatek_dochodowy - skladka_zdrowotna;

    float wynagrodzenie_netto;
    wynagrodzenie_netto = wynagrodzenie_brutto - suma_skladek_na_ubezpieczenie - skladka_ubezpieczenie_zdrowotne - zaliczka_podatek_dochodowy;

    //Tabela z wynikami
    system("cls");
    cout << "-----------------------------------------------------" << endl;
    printf("|%40s|%10.2f| \n", "Wynagrodzenie brutto", wynagrodzenie_brutto);
    cout << "=====================================================" << endl;

    printf("|%40s|%10.2f| \n", "Sk�adka na ubezpieczenie emerytalne", skladka_ubezpieczenie_emerytalne);
    cout << "-----------------------------------------------------" << endl;
    printf("|%40s|%10.2f| \n", "Sk�adka na ubezpieczenie chorobowe", skladka_ubezpieczenie_chorobowe);
    cout << "-----------------------------------------------------" << endl;
    printf("|%40s|%10.2f| \n", "Sk�adka na ubezpieczenie rentowe", skladka_ubezpieczenie_rentowe);
    cout << "-----------------------------------------------------" << endl;
    printf("|%40s|%10.2f| \n", "Sk�adka na ubezpieczenie zdrowotne", skladka_ubezpieczenie_zdrowotne);
    cout << "-----------------------------------------------------" << endl;
    printf("|%40s|%10.2f| \n", "Zaliczka na podatek dochodowy", zaliczka_podatek_dochodowy);
    cout << "-----------------------------------------------------" << endl;
    printf("|%40s|%10.2f| \n", "Wynagrodzenie netto", wynagrodzenie_netto);
    cout << "-----------------------------------------------------" << endl;
    printf("\n");

    string nazwa_pliku;

    if (lista == false)
    {
        cout << "Podaj nazw� pliku do zapisu" << endl;
        cin >> nazwa_pliku;

        zapisz_do_pliku(wynagrodzenie_brutto, skladka_ubezpieczenie_emerytalne, skladka_ubezpieczenie_chorobowe, skladka_ubezpieczenie_rentowe,
            skladka_ubezpieczenie_zdrowotne, zaliczka_podatek_dochodowy, wynagrodzenie_netto, nazwa_pliku);
    }
    else
    {
        nazwa_pliku = imie + nazwisko;
        zapisz_do_pliku(wynagrodzenie_brutto, skladka_ubezpieczenie_emerytalne, skladka_ubezpieczenie_chorobowe, skladka_ubezpieczenie_rentowe,
            skladka_ubezpieczenie_zdrowotne, zaliczka_podatek_dochodowy, wynagrodzenie_netto, nazwa_pliku);
    }
}


void info()
{
    cout << "======================Informacje====================" << endl;
    cout << "Projekt zaliczeniowy" << endl;
    cout << "Przedmiot: Podstawy programowania w C++" << endl;
    cout << "Wykona�: Jakub Sypniewski" << endl;
}

void read_csv()
{
    string nazwa_pliku;
    cout << "Podaj nazw� pliku txt do wczytania. Podaj nazw� BEZ rozszerzenia (.txt)." << endl;
    cin >> nazwa_pliku;

    nazwa_pliku = nazwa_pliku + ".txt";
    const char* nazwa_pliku_c = nazwa_pliku.c_str();

    std::ifstream infile(nazwa_pliku_c);
    string imie, nazwisko;
    float wynagrodzenie_brutto;
    bool czy_miejscowy_pracownik;
    while (infile >> imie >> nazwisko >> wynagrodzenie_brutto >> czy_miejscowy_pracownik)
    {
        policz_wyplate(true, imie, nazwisko, wynagrodzenie_brutto, czy_miejscowy_pracownik);
    }
}


int main()
{
    setlocale(LC_ALL, "pl_PL");
    while (true)
    {
        system("cls");
        cout << "====================================================" << endl;
        cout << "====================MENU============================" << endl;
        cout << "Wybierz jedn� z poni�szych opcji aby przej�� dalej" << endl;
        cout << "1 - Sprawd� zasady wylicze�." << endl;
        cout << "2 - Sprawd� jak przygotowa� plik wej�ciowy." << endl;
        cout << "3 - Oblicz wynagrodzenie netto (pojedyncze)" << endl;
        cout << "4 - Oblicz wynagrodzenie - wczytanie pliku" << endl;
        cout << "5 - Info." << endl;
        cout << "6 - Zako�cz." << endl;
        cout << "====================================================" << endl;

        char menu_choice;
        cin >> menu_choice;

        switch (menu_choice)
        {
        case '1':
            zasady_obliczen();
            break;
        case '2':
            jak_przygotowac_plik();
            getchar();
            getchar();
            break;
        case '3':
            policz_wyplate(false);
            getchar();
            getchar();
            break;
        case '4':
            read_csv();
            system("cls");
            cout << "Zapisano wszystko do plik�w." << endl;
            
            getchar();
            getchar();
            break;
        case '5':
            info();
            getchar();
            getchar();
            break;
        case '6':
            system("cls");
            cout << "Zamykanie programu." << endl;
            exit(0);
            break;
        default:
            cout << "Podano z�� warto��. Wybierz ponownie." << endl;
            getchar();
        }
    }
}


