#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED
///-----BIBLIOTECAS-----
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <math.h>
///-----TAMS-----
#define TAM 1000
#define TAM_LINEA 30
#define TAM_PILA 340
#define TAM_COLA 340
#define COL 7
#define FIL 7
///-----ARGUMENTOS DE MAIN-----
#define ARG_TXT 1
#define ARG_BIN 2
#define EMPLEADOS 1
#define ALUMNO 2
#define OFUSCADO 3
///-----RETURNS-----
#define TODO_OK 0
#define ERROR_ARCH 1
#define ERROR_ARG 2
#define ERROR_LINEA_LARGA 3
#define SIN_MEMORIA 4
#define COLA_VACIA 5
#define PILA_VACIA 5
#define LISTA_VACIA 5
#define COLA_LLENA 9
#define PILA_LLENA 9
#define LISTA_LLENA 9
#define NO_INSERTO 6
#define NO_ELIMINO 7
#define DUPLICADO 8
#define SI 1
#define NO 0
#define CADENA_VACIA 8
///-----FUNCIONES EN MACRO-----
#define MINIMO(x,y) (x<=y)? x:y
#define MAXIMO(x,y) (x<=y)? y:x
#define ES_LETRA(x) ((x>='a' && x<='z') || (x>='A' && x<='Z'))
#define ES_BLANCO(x) ((x==' ')||(x=='\t'))
#define ES_NUMERO(x) ((x>='0' && x<='9'))
#define ES_MAYUSCULA(c) (((c)>='A') && ((c)<='Z'))
#define ES_MINUSCULA(c) (c>='a' && c<='z')
#define MIN_A_MAY(x) (((x)>='a'&&(x)<='z')? (x)-32:(x))
#define MAY_A_MIN(x) (((x)>='A'&&(x)<='Z')? (x)+32:(x))

typedef struct
{
    int dni;
    char ape[30];
    char nom[30];
    double sueldo;
} Empleado;

typedef struct
{
    int dni;
    char ape[30];
    char nom[30];
    float prom;
} Alumno;

typedef struct
{
    int dia;
    int mes;
    int anio;
} Fecha;

typedef struct
{
    int codigo;
    char descripcion[51];
    int cantidad;
    float preciouni;
    Fecha fechapreciouni;
} producto;

typedef int (*Cmp) (const void*, const void*);

///--------------------- O T R O S ---------------------

int cmp (const void* e1, const void* e2);
void intercambiar (void *a, void *b, int tamelem);
int menu_errores(int error);

///--------------------- V E C T O R E S ---------------------

void ordenarSeleccion(void* v, int cantElem,int tamelem,Cmp cmp);
void* buscarMenor(void *desde, void* hasta, int tamelem,Cmp cmp);
void mostrarvec(void* v, int ce, int tamelem);
void inicializarvecrandom(int* v, int ce);
int insercion_pos(int x,int pos,int*ce,int*V);
int insercionord(int x,int*ce,int*vec);
int eliminarpos(int pos,int*ce,int*vec);
int eliminar_primer_aparicion(int*vec,int*ce,int val);
int eliminarval(int*vec,int*cant,int val);

///--------------------- A R C H I V O S   B I N A R I O S ---------------------

int mostrarArchivosBin(const char* nomArchivo,int tamstruct);
int generarArchivoBin(const char* nomArchivo);
int AumentaSueldos(const char* arch1,const char* arch2);///arch1 = alumno    arch2=empleado

///--------------------- A R C H I V O S   D E  T E X T O ---------------------

int ofuscado();


///--------------------- F E C H A ---------------------

int esBisiesto(int anio);
int cantDiaMes(int mes,int anio);
Fecha* diaSiguiente(Fecha fec);
int esFechaVal(Fecha *fec);
int diaDelAnio(const Fecha* fec);
int diaRel(const Fecha* fec);
Fecha* sumarDias(Fecha* fec, int dias);
Fecha* restarDias(const Fecha* fec, int dias);
int diasEntreFechas(const Fecha* fec1, const Fecha* fec2);
int diaDeLaSemana(const Fecha* fec);

///--------------------- M A T R I C E S ---------------------

int menu_matrices ();
void diagonalprincipal(int mat[][COL]);
void diagonalsecundaria(int mat[][COL]);
void triangulosuperiorcd(int mat[][COL]);
void triangulosuperiorsd(int mat[][COL]);
void trianguloinferiorcd(int mat[][COL]);
void trianguloinferiorsd(int mat[][COL]);
void trianinfdiagsecun(int mat[][COL]);
void triansupdiagsecun(int mat[][COL]);
int suma_tri_sup(int mat[][COL]);
int traza(int mat[][COL]);
void mostrarmatriz(int mat[][COL]);
int matrizdiagonal(int mat[][COL]);
int matrizidentidad(int mat[][COL]);//no tendria que recorrer toda, si preguntar por toda
int essimetrica(int mat[][COL]);
void transponer(int mat[][COL]);
int escuadrada(int fil, int col);

///--------------------- S T R I N G  Y  C T Y P E ---------------------

int espalindromo(char *cad);
char* normalizar_nombre(char*s);
char* normalizar_texto(char*s);
void avanzar_3_espacios(char* s);

size_t mi_strlen(const char *cad);
char *mi_strncpy(char *cad_copia, const char *cad_orig, size_t n);
int mi_strcmp(const char* a,const char* b);
char *mi_strncat(char *cad_de_enlace, const char *cad_a_enlazar, size_t n);
char* mi_strchr(char* cad, int c);
char* mi_strrchr(char* cad, int c);
size_t mi_strcspn(const char *cad1, const char *cad2);
char *mi_strpbrk(char *cad1,char *cad2);
char *mi_strstr(char *cad1,char *cad2);
void invertirString(char* cad);
char* mi_itoa(int num, char* cad, int sistema);
int mi_atoi(const char* cad);
char* primeraPalabra(const char* cad);
int contarPalabras(const char* cad);
int vecesRepite(const char* pal, const char* cad);  /// ----------
int mi_ctoi(char c);
char *mi_strcpy(char *cad_copia, const char *cad_orig);

///--------------------- P I L A   E S T A T I C A ---------------------

typedef struct
{
    char vEle[TAM_PILA];
    int tope;
} t_pila_est;

void crearPila_est(t_pila_est *p);
int	pilaLlena_est(const t_pila_est *p, unsigned cantBytes);
int	apilar_est(t_pila_est *p, const void *d, unsigned cantBytes);
int	verTope_est(const t_pila_est *p, void *d, unsigned cantBytes);
int	pilaVacia_est(const t_pila_est *p);
int	desapilar_est(t_pila_est *p, void *d, unsigned cantBytes);
void vaciarPila_est(t_pila_est *p);

///--------------------- P I L A   D I N A M I C A ---------------------

typedef struct s_nodo
{
    void* info;
    unsigned taminfo;
    struct s_nodo *sig;
}t_nodo_pila;

typedef t_nodo_pila* t_pila;

void crearPila_din(t_pila *p);
int	pilaLlena_din(const t_pila *p, unsigned cantBytes);
int	apilar_din(t_pila *p, const void *d, unsigned cantBytes);
int	verTope_din(const t_pila *p,  void *d, unsigned cantBytes);
int	pilaVacia_din(const t_pila *p);
int	desapilar_din(t_pila *p, void *d, unsigned cantBytes);
void vaciarPila_din(t_pila *p);

///--------------------- C O L A   E S T A T I C A ---------------------

typedef struct
{
    char	cola[TAM_COLA];
    unsigned	pri,
                ult,
                tamDisp;
} t_cola_est;


void crearCola_est(t_cola_est *p);
int colaLlena_est(const t_cola_est *p, unsigned cantBytes);
int ponerEnCola_est(t_cola_est *p, const void *d, unsigned cantBytes);
int verPrimeroCola_est(const t_cola_est *p, void *d, unsigned cantBytes);
int colaVacia_est(const t_cola_est *p);
int sacarDeCola_est(t_cola_est *p, void *d, unsigned cantBytes);
void vaciarCola_est(t_cola_est *p);


///--------------------- C O L A   D I N A M I C A ---------------------

typedef struct sNodo
{
    void	*info;
    unsigned	tamInfo;
    struct sNodo	*sig;
} t_nodo_cola;

typedef struct
{
    t_nodo_cola *pri;
    t_nodo_cola *ult;
} t_cola;

void crearCola_din(t_cola *p);
int colaLlena_din(const t_cola *p, unsigned cantBytes);
int ponerEnCola_din(t_cola *p, const void *d, unsigned cantBytes);
int	verPrimeroCola_din(const t_cola *p, void *d, unsigned cantBytes);
int	colaVacia_din(const t_cola *p);
int	sacarDeCola_din(t_cola *p, void *d, unsigned cantBytes);
void vaciarCola_din(t_cola *p);

///--------------------- L I S T A   D I N A M I C A ---------------------

typedef struct snodo
{
    void	*info;
    unsigned	tamInfo;
    struct snodo	*sig;
}t_nodo_lista;

typedef t_nodo_lista *t_lista;

void crearlista(t_lista* l);
int listaVacia(const t_lista *l);
int listaLlena(const t_lista *l, unsigned cantBytes);
void vaciarLista(t_lista *l);
int ponerAlComienzo(t_lista *l, const void *d, unsigned cantBytes);
int sacarPrimeroLista(t_lista *l, void *d, unsigned cantBytes);
int verPrimeroLista(const t_lista *l, void *d, unsigned cantBytes);
int ponerAlFinal(t_lista *l, const void *d, unsigned cantBytes);
int sacarUltimoLista(t_lista *l, void *d, unsigned cantBytes);
int verUltimoLista(const t_lista *l, void *d, unsigned cantBytes);
int	ponerEnOrden(t_lista *p, const void *d, unsigned cantBytes,int (*comparar)(const void *, const void *),int (*acumular)(void **, unsigned *, const void *, unsigned));
void ordenar(t_lista *p, int (*comparar)(const void *, const void *));
#endif // FUNCIONES_H_INCLUDED