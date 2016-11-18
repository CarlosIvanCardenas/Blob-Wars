/*Carlos Iván Cárdenas Cárdenas - A00820062
 * Tarea Integradora - Guerra de Blobs
 * ------------------------------------------------------------------
 * Algoritmo:
 *Declarar variables.
 * Inicializar matriz para el tablero inicial.
 * Hacer:
 *      Limpiar terminal.
 *      Llamar función MostrarTablero.
 *      Llamar función MoverFicha,
 *      Llamar función contar.
 *      Si: iPuntos1 + iPuntos2 es igual a 36, terminar ciclo.
 *      Hacer:
 *          Mostrar: "Quieren seguir jugando? (s/n)".
 *          Leer cSeguir.
 *      Mientras: cSeguir a minúscula sea diferente a 's' y 'n'.
 * Mientras: cSeguir a minúscula sea diferente a 'n'.
 * Si: iPuntos1 es mayor a iPuntos2, mostrar "EL JUGADOR 1 GANA."
 * Si: iPuntos1 es menor a iPuntos2, mostrar "EL JUGADOR 2 GANA."
 * Sino: Mostrar "EMPATE".
 */

#include <iostream>
#include <cstdlib>

using namespace std;

const int MAX = 6;

string Intro ()
{
    cout << "██████╗ ██╗      ██████╗ ██████╗     ██╗    ██╗ █████╗ ██████╗ ███████╗    \n"
            "██╔══██╗██║     ██╔═══██╗██╔══██╗    ██║    ██║██╔══██╗██╔══██╗██╔════╝    \n"
            "██████╔╝██║     ██║   ██║██████╔╝    ██║ █╗ ██║███████║██████╔╝███████╗    \n"
            "██╔══██╗██║     ██║   ██║██╔══██╗    ██║███╗██║██╔══██║██╔══██╗╚════██║    \n"
            "██████╔╝███████╗╚██████╔╝██████╔╝    ╚███╔███╔╝██║  ██║██║  ██║███████║    \n"
            "╚═════╝ ╚══════╝ ╚═════╝ ╚═════╝      ╚══╝╚══╝ ╚═╝  ╚═╝╚═╝  ╚═╝╚══════╝    \n"
            "                                                                           \n"
            "██████╗ ██╗   ██╗     ██████╗ █████╗ ██████╗ ██╗      ██████╗ ███████╗     \n"
            "██╔══██╗╚██╗ ██╔╝    ██╔════╝██╔══██╗██╔══██╗██║     ██╔═══██╗██╔════╝     \n"
            "██████╔╝ ╚████╔╝     ██║     ███████║██████╔╝██║     ██║   ██║███████╗     \n"
            "██╔══██╗  ╚██╔╝      ██║     ██╔══██║██╔══██╗██║     ██║   ██║╚════██║     \n"
            "██████╔╝   ██║       ╚██████╗██║  ██║██║  ██║███████╗╚██████╔╝███████║     \n"
            "╚═════╝    ╚═╝        ╚═════╝╚═╝  ╚═╝╚═╝  ╚═╝╚══════╝ ╚═════╝ ╚══════╝     \n"
            "                                                                           "
         << endl << "Pulse S para empezar..." <<endl;
}

//Función que muestra la matriz con los indicadores de renglón y columna.
void MostrarTablero (char cMatTablero[MAX][MAX])
{
    cout << " \t" << "0\t" << "1\t" << "2\t" << "3\t" << "4\t" << "5\t" << endl;
    for (int R = 0; R < MAX; R++)
    {
        cout << R << "\t";
        for (int C = 0; C < MAX; C++)
        {
            cout << cMatTablero[R][C] << "\t";
        }
        cout << endl;
    }
}

//Función que revisa si hay un blob contrario alrededor de la ficha movida.
//En caso de ser así convierte el blob contrario en propio.
void Alrededor (char cMatTablero[MAX][MAX], int iRen, int iCol, char cFicha1)
{
    char cFicha2;
    if (cFicha1 == 'X')
        cFicha2 = 'O';
    else
        cFicha2 = 'X';
    if (cMatTablero[iRen-1][iCol-1] == cFicha2)
        cMatTablero[iRen-1][iCol-1] = cFicha1;
    if (cMatTablero[iRen-1][iCol] == cFicha2)
        cMatTablero[iRen-1][iCol] = cFicha1;
    if (cMatTablero[iRen-1][iCol+1] == cFicha2)
        cMatTablero[iRen-1][iCol+1] = cFicha1;
    if (cMatTablero[iRen][iCol-1] == cFicha2)
        cMatTablero[iRen][iCol-1] = cFicha1;
    if (cMatTablero[iRen][iCol+1] == cFicha2)
        cMatTablero[iRen][iCol+1] = cFicha1;
    if (cMatTablero[iRen+1][iCol-1] == cFicha2)
        cMatTablero[iRen+1][iCol-1] = cFicha1;
    if (cMatTablero[iRen+1][iCol] == cFicha2)
        cMatTablero[iRen+1][iCol] = cFicha1;
    if (cMatTablero[iRen+1][iCol+1] == cFicha2)
        cMatTablero[iRen+1][iCol+1] = cFicha1;
}

//Función que revisa hacia donde se quiere clonar el blob.
void Direccion (char cMatTablero[MAX][MAX], char cDir, int iRen, int iCol, char cFicha)
{
    switch (cDir)
    {
        case 'q':
            if (cMatTablero[iRen-1][iCol-1] == '~')
            {
                cMatTablero[iRen-1][iCol-1] = cFicha;
                Alrededor(cMatTablero, iRen-1, iCol-1, cFicha);
            }
            break;
        case 'w':
            if (cMatTablero[iRen-1][iCol] == '~')
            {
                cMatTablero[iRen-1][iCol] = cFicha;
                Alrededor(cMatTablero, iRen-1, iCol, cFicha);
            }
            break;
        case 'e':
            if (cMatTablero[iRen-1][iCol+1] == '~')
            {
                cMatTablero[iRen-1][iCol+1] = cFicha;
                Alrededor(cMatTablero, iRen-1, iCol+1, cFicha);
            }
            break;
        case 'a':
            if (cMatTablero[iRen][iCol-1] == '~')
            {
                cMatTablero[iRen][iCol-1] = cFicha;
                Alrededor(cMatTablero, iRen, iCol-1, cFicha);
            }
            break;
        case 'd':
            if (cMatTablero[iRen][iCol+1] == '~')
            {
                cMatTablero[iRen][iCol+1] = cFicha;
                Alrededor(cMatTablero, iRen, iCol+1, cFicha);
            }
            break;
        case 'z':
            if (cMatTablero[iRen+1][iCol-1] == '~')
            {
                cMatTablero[iRen+1][iCol-1] = cFicha;
                Alrededor(cMatTablero, iRen+1, iCol-1, cFicha);
            }
            break;
        case 'x':
            if (cMatTablero[iRen+1][iCol] == '~')
            {
                cMatTablero[iRen+1][iCol] = cFicha;
                Alrededor(cMatTablero, iRen+1, iCol, cFicha);
            }
            break;
        case 'c':
            if (cMatTablero[iRen+1][iCol+1] == '~')
            {
                cMatTablero[iRen+1][iCol+1] = cFicha;
                Alrededor(cMatTablero, iRen+1, iCol+1, cFicha);
            }
            break;
    }
}

//Función que indica de quien es el turno.
//Recibe la casilla indicada y la direccion a la que se quiere clonar.
void MoverFicha (char cMatTablero[MAX][MAX], int &iTurno)
{
    int iRen, iCol, iVal = 0;
    char cDir;
    cout << (iTurno % 2 == 0? "Jugador1: X ": "Jugador2: O") << endl;
    do
    {
        cout << "Renglon-> ";
        cin >> iRen;
        cout << "Columna-> ";
        cin >> iCol;
    } while (iRen < 0 || iRen > 5 || iCol < 0 || iCol > 5 || iTurno % 2 == 0? cMatTablero[iRen][iCol] != 'X' : cMatTablero[iRen][iCol] != 'O');
    do
    {
        cout << "a - izq  x - aba  w - arr  d - der\n" <<
             "q - arriba a la izquierda e - arriba a la derecha\n" <<
             "z - abajo a la izquierda c - abajo a la derecha " << endl <<
             "Mover-> ";
        cin >> cDir;
        if (tolower(cDir) == 'q' | tolower(cDir) == 'w' | tolower(cDir) == 'e' | tolower(cDir) == 'a' | tolower(cDir) == 'd' | tolower(cDir) == 'z' | tolower(cDir) == 'x' | tolower(cDir) == 'c')
            iVal = 1;
    } while (iVal == 0);

    if (iTurno % 2 == 0)
    {
        if (cMatTablero[iRen][iCol] == 'X')
            Direccion(cMatTablero, tolower(cDir), iRen, iCol, 'X');
    }
    else
    {
        if (cMatTablero[iRen][iCol] == 'O')
            Direccion(cMatTablero, tolower(cDir), iRen, iCol, 'O');
    }
    iTurno++;
}

//Función que cuenta los puntos totales de cada jugador.
void Contar (char cMatTablero[MAX][MAX], int &iPuntos1, int &iPuntos2)
{
    iPuntos1 = iPuntos2 = 0;
    for (int R = 0; R < MAX; R++)
    {
        for (int C = 0; C < MAX; C++)
        {
            if (cMatTablero[R][C] == 'X')
                iPuntos1++;
            else if (cMatTablero[R][C] == 'O')
                iPuntos2++;
        }
    }
}

int main() {
    int iTurno = 0, iPuntos1, iPuntos2;
    char cSeguir, cMatTablero[MAX][MAX] = {{'X','~','~','~','~','X'},
                               {'~','~','~','~','~','~'},
                               {'~','~','~','~','~','~'},
                               {'~','~','~','~','~','~'},
                               {'~','~','~','~','~','~'},
                               {'O','~','~','~','~','O'}};
    do
    {
	system("clear");
        Intro();
        cin >> cSeguir;
    } while (tolower(cSeguir) != 's');
    do
    {
        system("clear");
        MostrarTablero(cMatTablero);
        MoverFicha(cMatTablero, iTurno);
        Contar(cMatTablero, iPuntos1, iPuntos2);
        if (iPuntos1 + iPuntos2 == 36)
            break;
        do
        {
            cout << "Quieren seguir jugando? (s/n) ";
            cin >> cSeguir;
        } while (tolower(cSeguir) != 's' && tolower(cSeguir) != 'n');
    } while (tolower(cSeguir) != 'n');
	system("clear");
    if (iPuntos1 > iPuntos2)
        cout << "███████╗██╗              ██╗██╗   ██╗ ██████╗  █████╗ ██████╗  ██████╗ ██████╗      ██╗     ██████╗  █████╗ ███╗   ██╗ █████╗    \n"
                "██╔════╝██║              ██║██║   ██║██╔════╝ ██╔══██╗██╔══██╗██╔═══██╗██╔══██╗    ███║    ██╔════╝ ██╔══██╗████╗  ██║██╔══██╗   \n"
                "█████╗  ██║              ██║██║   ██║██║  ███╗███████║██║  ██║██║   ██║██████╔╝    ╚██║    ██║  ███╗███████║██╔██╗ ██║███████║   \n"
                "██╔══╝  ██║         ██   ██║██║   ██║██║   ██║██╔══██║██║  ██║██║   ██║██╔══██╗     ██║    ██║   ██║██╔══██║██║╚██╗██║██╔══██║   \n"
                "███████╗███████╗    ╚█████╔╝╚██████╔╝╚██████╔╝██║  ██║██████╔╝╚██████╔╝██║  ██║     ██║    ╚██████╔╝██║  ██║██║ ╚████║██║  ██║██╗\n"
                "╚══════╝╚══════╝     ╚════╝  ╚═════╝  ╚═════╝ ╚═╝  ╚═╝╚═════╝  ╚═════╝ ╚═╝  ╚═╝     ╚═╝     ╚═════╝ ╚═╝  ╚═╝╚═╝  ╚═══╝╚═╝  ╚═╝╚═╝\n"
                "                                                                                                                                 " << endl;
    else if (iPuntos1 < iPuntos2)
        cout << "███████╗██╗              ██╗██╗   ██╗ ██████╗  █████╗ ██████╗  ██████╗ ██████╗     ██████╗      ██████╗  █████╗ ███╗   ██╗ █████╗    \n"
                "██╔════╝██║              ██║██║   ██║██╔════╝ ██╔══██╗██╔══██╗██╔═══██╗██╔══██╗    ╚════██╗    ██╔════╝ ██╔══██╗████╗  ██║██╔══██╗   \n"
                "█████╗  ██║              ██║██║   ██║██║  ███╗███████║██║  ██║██║   ██║██████╔╝     █████╔╝    ██║  ███╗███████║██╔██╗ ██║███████║   \n"
                "██╔══╝  ██║         ██   ██║██║   ██║██║   ██║██╔══██║██║  ██║██║   ██║██╔══██╗    ██╔═══╝     ██║   ██║██╔══██║██║╚██╗██║██╔══██║   \n"
                "███████╗███████╗    ╚█████╔╝╚██████╔╝╚██████╔╝██║  ██║██████╔╝╚██████╔╝██║  ██║    ███████╗    ╚██████╔╝██║  ██║██║ ╚████║██║  ██║██╗\n"
                "╚══════╝╚══════╝     ╚════╝  ╚═════╝  ╚═════╝ ╚═╝  ╚═╝╚═════╝  ╚═════╝ ╚═╝  ╚═╝    ╚══════╝     ╚═════╝ ╚═╝  ╚═╝╚═╝  ╚═══╝╚═╝  ╚═╝╚═╝\n"
                "                                                                                                                                     " << endl;
    else
        cout << "███████╗███╗   ███╗██████╗  █████╗ ████████╗███████╗\n"
                "██╔════╝████╗ ████║██╔══██╗██╔══██╗╚══██╔══╝██╔════╝\n"
                "█████╗  ██╔████╔██║██████╔╝███████║   ██║   █████╗  \n"
                "██╔══╝  ██║╚██╔╝██║██╔═══╝ ██╔══██║   ██║   ██╔══╝  \n"
                "███████╗██║ ╚═╝ ██║██║     ██║  ██║   ██║   ███████╗\n"
                "╚══════╝╚═╝     ╚═╝╚═╝     ╚═╝  ╚═╝   ╚═╝   ╚══════╝\n"
                "                                                    " << endl;
    return 0;
}
