//Projekt zaliczeniowy
//Wykona³: Jakub Sypniewski
//Numer albumu: 73030
#include <iostream>
#include <stdio.h>
#include <cstdlib>

using namespace std;


void return_to_menu()
{
    cout << "Wybierz [1] aby zamkn¹æ program." << endl;
    cout << "Wciœnij dowolny inny klawisz aby powróciæ do menu." << endl;

    char user_input;
    cin >> user_input;

    if (user_input == '1')
    {
        cout << "Zamykam program." << endl;
        exit(0);
    }
}

void tabela_skladki()
{
    system("cls");
    cout << "=========================== Tabela sk³adek ===========================" << endl;
    cout << "======================================================================" << endl;
    cout << "-----------------------------------------------------------------------------------------------" << endl;
    printf("|%30s|%20s|%20s|%20s|", "rodzaj sk³adki", "stopy procentowe", "pokrywa pracownik", "pokrywa pracodawca");
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
    cout << "======================= Tabela kosztów uzyskania =====================" << endl;
    cout << "======================================================================" << endl;
    cout << "---------------------------------------------------------------------------------------------------------------------" << endl;
    printf("|%23s|%38s|%52s|", "  ", "miesiêczne koszty uzyskania przychodu", "roczne koszty uzyskania przychodu");
    printf("\n");
    cout << "---------------------------------------------------------------------------------------------------------------------" << endl;
    printf("|%23s|%38s|%52s|", "pracownik miejscowy", "111.25 z³", "1335 z³ z jednej umowy, 2002.05 z³ z wielu umów");
    printf("\n");
    cout << "---------------------------------------------------------------------------------------------------------------------" << endl;
    printf("|%23s|%38s|%52s|", "pracownik doje¿d¿aj¹cy", "139.06 z³", "1668,72 z³ z jednej umowy, 2502.56 z³ z wielu umów");
    printf("\n");
    cout << "---------------------------------------------------------------------------------------------------------------------" << endl;
    printf("\n");
}

void algorytm_obliczania_wynagrodzenia_netto()
{
    system("cls");
    cout << "=============== Algorytm obliczania wynagrodzenia netto ==============" << endl;
    cout << "======================================================================" << endl;
    cout << "1. Pobranie wynagrodzenia miesiêcznego brutto." << endl;
    cout << "2. Oliczenie sk³adek na ubezpieczenie: emerytalne, rentowe, chorobowe." << endl;
    cout << "3. Obliczenie sk³adki na ubezpieczenie zdrowotne." << endl;
    cout << "4. Obliczenie zaliczki na podatek dochodowy." << endl;
    cout << "5. Obliczenie zaliczki na podatek dochodowy do pobrania." << endl;
    cout << "6. Obliczenie wynagrodzenia netto." << endl;
    cout << "\n * Wyliczenie oparte na za³o¿eniu, ¿e wynagrodzenie brutto w ci¹gu roku nie ulega zmianie. \n" << endl;

}

void show_calculation_rules()
{
    char zasady_obliczania_wybor;

    do
    {
        system("cls");
        cout << "===============Zasady wyliczania wynagrodzenia netto.==============" << endl;
        cout << "===================================================================" << endl;
        cout << "Wybierz:" << endl;
        cout << "[0] - Zobacz tabelê sk³adek. " << endl;
        cout << "[1] - Zobacz tabelê kosztów uzyskania " << endl;
        cout << "[2] - SprawdŸ algorytm wyliczania wynagrodzenia netto " << endl;
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
            cout << "Niepoprawna odpowiedŸ. Wybierz miêdzy [0], [1] lub [2]." << endl;
            break;
        }
    } while (zasady_obliczania_wybor != '0' && zasady_obliczania_wybor != '1' && zasady_obliczania_wybor != '2');

    return_to_menu();
}

void how_to_prepare_input_file()
{
    cout << "Zasady przygotowania pliku wsadowego." << endl;
}


void calculate_salary()
{
    system("cls");

    cout << "Podaj wynagrodzenie brutto (miesiêczne):" << endl;
    float wynagrodzenie_brutto;
    cin >> wynagrodzenie_brutto;

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

    do
    {   

        cout << "Czy mieszkasz w miejscowoœci, w której pracujesz tak[1]/nie[0]?" << endl;
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
            cout << "Niepoprawna odpowiedŸ. Wybierz miêdzy TAK[1] oraz NIE[0]." << endl;
            break;
        }
    } while (pracownik_miejscowy_odpowiedz != '0' && pracownik_miejscowy_odpowiedz != '1');

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

    //Dodatkowo badam opcjê, gdy roczny przychód nie wyniós³ 3091z³. Wówczas podatek dochodowy jest zerowy
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
    
    printf("|%40s|%10.2f| \n", "Sk³adka na ubezpieczenie emerytalne", skladka_ubezpieczenie_emerytalne);
    cout << "-----------------------------------------------------" << endl;
    printf("|%40s|%10.2f| \n", "Sk³adka na ubezpieczenie chorobowe", skladka_ubezpieczenie_chorobowe);
    cout << "-----------------------------------------------------" << endl;
    printf("|%40s|%10.2f| \n", "Sk³adka na ubezpieczenie rentowe", skladka_ubezpieczenie_rentowe);
    cout << "-----------------------------------------------------" << endl;
    printf("|%40s|%10.2f| \n", "Sk³adka na ubezpieczenie zdrowotne", skladka_ubezpieczenie_zdrowotne);
    cout << "-----------------------------------------------------" << endl;
    printf("|%40s|%10.2f| \n", "Zaliczka na podatek dochodowy", zaliczka_podatek_dochodowy);
    cout << "-----------------------------------------------------" << endl;
    printf("|%40s|%10.2f| \n", "Wynagrodzenie netto", wynagrodzenie_netto);
    cout << "-----------------------------------------------------" << endl;
    printf("\n");
    
}



void info()
{
    cout << "======================Informacje====================" << endl;
    cout << "Projekt zaliczeniowy" << endl;
    cout << "Przedmiot: Podstawy programowania w C++" << endl;
    cout << "Wykona³: Jakub Sypniewski" << endl;
    cout << "Data oddania: XX-XX-XXXX";
}


int main()
{
    setlocale(LC_ALL, "pl_PL");
    while (true)
    {
        system("cls");
        cout << "====================================================" << endl;
        cout << "====================MENU============================" << endl;
        cout << "Wybierz jedn¹ z poni¿szych opcji aby przejœæ dalej" << endl;
        cout << "1 - SprawdŸ zasady wyliczeñ." << endl;
        cout << "2 - SprawdŸ jak przygotowaæ plik wejœciowy." << endl;
        cout << "3 - Wczytanie pliku." << endl;
        cout << "4 - Info." << endl;
        cout << "5 - Zakoñcz." << endl;
        cout << "====================================================" << endl;

        char menu_choice;
        cin >> menu_choice;

        switch (menu_choice)
        {
        case '1':
            show_calculation_rules();
            break;
        case '2':
            how_to_prepare_input_file();
            getchar();
            break;
        case '3':
            calculate_salary();
            getchar();
            getchar();
            break;
        case '4':
            info();
            getchar();
            getchar();
            break;
        case '5':
            system("cls");
            cout << "Zamykanie programu." << endl;
            exit(0);
            break;
        default:
            cout << "Podano z³¹ wartoœæ. Wybierz ponownie." << endl;
            getchar();
        }
    }
}

