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
#define SIN_INICIALIZAR 10
#define VERDADERO 1
#define FALSO 0
///-----FUNCIONES EN MACRO-----
#define MINIMO(x,y) (x<=y)? x:y
#define MAXIMO(x,y) (x<=y)? y:x
#define ES_LETRA(i) ((i>='A' && i<='Z') || (i>='a' && i<='z') || (i>=160 && i<=165)|| (i==129) || (i==130) || (i==181) || (i==233) || (i==224) || (i==144) || (i==214))
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

typedef struct sNodo
{
    void* info;
    unsigned tamInfo;
    struct sNodo *sig;
} tNodo;

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
int eliminarYMostrarRepetidos_MIO(tLista *p, FILE *fpPant,int comparar(const void *, const void *),void mostrar(const void *, FILE *));
int eliminarYMostrarUnicos_MIO(tLista *p, FILE *fpPant,int comparar(const void *, const void *),void mostrar(const void *, FILE *));

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
char* mi_strchr(const char* cad2, int c);
char* mi_strrchr(const char* cad2, int c);
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
int buscarYReemplazar_MIO(char *cade, int tam,const char *busc, const char *reem);

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

typedef tNodo* t_pila;

void crearPila_din(t_pila *p);
//int	pilaLlena_din(const t_pila *p, unsigned cantBytes);
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

typedef struct
{
    tNodo *pri;
    tNodo *ult;
} t_cola;

void crearCola_din(t_cola *p);
//int colaLlena_din(const t_cola *p, unsigned cantBytes);
int ponerEnCola_din(t_cola *p, const void *d, unsigned cantBytes);
int	verPrimeroCola_din(const t_cola *p, void *d, unsigned cantBytes);
int	colaVacia_din(const t_cola *p);
int	sacarDeCola_din(t_cola *p, void *d, unsigned cantBytes);
void vaciarCola_din(t_cola *p);

///--------------------- L I S T A   D I N A M I C A ---------------------

typedef tNodo *t_lista;

void crearlista(t_lista* l);
int listaVacia(const t_lista *l);
//int listaLlena(const t_lista *l, unsigned cantBytes);
void vaciarLista(t_lista *l);
int ponerAlComienzo(t_lista *l, const void *d, unsigned cantBytes);
int sacarPrimeroLista(t_lista *l, void *d, unsigned cantBytes);
int verPrimeroLista(const t_lista *l, void *d, unsigned cantBytes);
int ponerAlFinal(t_lista *l, const void *d, unsigned cantBytes);
int sacarUltimoLista(t_lista *l, void *d, unsigned cantBytes);
int verUltimoLista(const t_lista *l, void *d, unsigned cantBytes);
int	ponerEnOrden(t_lista *p, const void *d, unsigned cantBytes,int (*comparar)(const void *, const void *),int (*acumular)(void **, unsigned *, const void *, unsigned));
void ordenar(t_lista *p, int (*comparar)(const void *, const void *));
int mostrarLista(const tLista *p,void (*mostrar)(const void *, FILE *), FILE *fp);

///--------------------- P I L A   C I R C U L A R ---------------------

typedef tNodo* tPila;

void crear_pila_cir(tPila *p);
int poner_en_pila_cir(tPila*p,const void*d,unsigned cantBytes);
int sacar_de_pila_cir(tPila*p,void*d,unsigned cantBytes);
int ver_tope_cir(const tPila*p,void*d,unsigned cantBytes);
int pila_vacia_cir(const tPila*p);
//int pila_llena_cir(const tPila*p,unsigned taminfo);
void vaciar_pila_cir(tPila*p);

///--------------------- C O L A  C I R C U L A R ---------------------

typedef tNodo *tCola;

void crearCola_cir(tCola *pc);
int poner_en_cola_cir(tCola *pc, const void *info, unsigned tamInfo);
int sacar_de_cola_cir(tCola *pc, void *info, unsigned tamInfo);
int cola_vacia_cir(const tCola *pc);
//int cola_llena(const tCola *pc, unsigned tamInfo);
void vaciar_cola_cir(tCola *pc);
int ver_primero_cir(const tCola *pc, void *info, unsigned tamInfo);


///--------------------- L I S T A   D O B L E ---------------------

typedef struct sNodoDoble
{
    void *pInfo;
    unsigned tamElem;
    struct sNodoDoble *ant;
    struct sNodoDoble *sig;
}tNodoDoble;

typedef tNodoDoble* tListaDoble;
typedef int(*tCmp)(const void*, const void*);
typedef void(*tMostrar)(const void*);

void crearListaDoble(tListaDoble*);
int listaDobleVacia(const tListaDoble*);
int listaDobleLlena(const tListaDoble*, unsigned);
void vaciarListaDoble(tListaDoble*);
void vaciarListaDobleYMostrar(tListaDoble*, tMostrar);
int insertarPrincipioListaDoble(tListaDoble*, void*, unsigned);
int insertarFinalListaDoble(tListaDoble*, void*, unsigned);
int insertarOrdenadoListaDoble(tListaDoble*, void*, unsigned, tCmp);
int verPrimeroListaDoble(tListaDoble*, void*, unsigned);
int verUltimoListaDoble(tListaDoble*, void*, unsigned);
int sacarPrimeroListaDoble(tListaDoble*, void*, unsigned);
int sacarUltimoListaDoble(tListaDoble*, void*, unsigned);
int buscarYSacarListaDoble(tListaDoble*, void*, unsigned, tCmp);
void mostrarListaDoble(tListaDoble*, tMostrar);

///--------------------------- A R B O L ----------------------------

#define reservarMemoriaNodo( X , Y , Z , W ) ((( X ) = (typeof( X ))malloc( Y ) ) == NULL || ((Z) = malloc( W ) ) == NULL ? free( X ), 0 : 1	)


typedef struct sNodoArbol
{
    void *info;
    unsigned tamInfo;
    struct sNodoArbol *izq,
                      *der;
}tNodoArbol;

typedef tNodoArbol *tArbolBinBusq;

tNodoArbol **mayorNodoArbolBinBusq(const tArbolBinBusq *p);
tNodoArbol **menorNodoArbolBinBusq(const tArbolBinBusq *p);
tNodoArbol **mayorRecNodoArbolBinBusq(const tArbolBinBusq *p);
tNodoArbol **menorRecNodoArbolBinBusq(const tArbolBinBusq *p);
tNodoArbol **buscarNodoArbolBinBusq(const tArbolBinBusq *p, const void *d,int (*cmp)(const void *, const void *));
tNodoArbol **buscarRecNodoArbolBinBusq(const tArbolBinBusq *p, const void *d,int (*cmp)(const void *, const void*));
int esCompletoHastaNivelArbolBin(const tArbolBinBusq *p, int n);
int esAVL2CalculoArbolBin(const tArbolBinBusq *p);
const tArbolBinBusq * mayorNodoNoClaveArbolBinBusq(const tArbolBinBusq *p,	const tArbolBinBusq *mayor,int (*cmp)(const void *, const void *));
const tArbolBinBusq * menorNodoNoClaveArbolBinBusq(const tArbolBinBusq *p, const tArbolBinBusq *menor,int (*cmp)(const void *, const void *));
const tArbolBinBusq * buscarNodoNoClaveArbolBinBusq(const tArbolBinBusq *p, const void *d,int (*cmp)(const void *, const void *));

void crearArbolBinBusq(tArbolBinBusq *p);
int insertarArbolBinBusq(tArbolBinBusq *p, const void *d, unsigned tam,	int (*cmp)(const void *, const void *));
int insertarRecArbolBinBusq(tArbolBinBusq *p, const void *d, unsigned tam, 	int (*cmp)(const void*, const void *));
void recorrerEnOrdenArbolBinBusq(const tArbolBinBusq * p, void * params,void (*accion)(void *, unsigned, unsigned, void*));
void recorrerEnOrdenInversoArbolBinBusq(const tArbolBinBusq * p, void * params, void (*accion)(void *, unsigned, unsigned, void *));
void recorrerPreOrdenArbolBinBusq(const tArbolBinBusq * p, void * params,void (*accion)(void *, unsigned, unsigned, void*));
void recorrerPosOrdenArbolBinBusq(const tArbolBinBusq * p, void * params,void (*accion)(void *, unsigned, unsigned, void*));
void recorrerEnOrdenSimpleArbolBinBusq(const tArbolBinBusq *p, void *params,void (*accion)(void *, unsigned, void *));
void recorrerPreOrdenSimpleArbolBinBusq(const tArbolBinBusq *p, void *params,void (*accion)(void *, unsigned, void *));
void recorrerPosOrdenSimpleArbolBinBusq(const tArbolBinBusq *p, void *params,void (*accion)(void *, unsigned, void *));
int eliminarRaizArbolBinBusq(tArbolBinBusq *p);
int eliminarElemArbolBinBusq(tArbolBinBusq *p, void *d, unsigned tam, int (*cmp)(const void *, const void *));
int buscarElemArbolBinBusq(const tArbolBinBusq *p, void *d, unsigned tam, int (*cmp)(const void *, const void *));
int cargarArchivoBinOrdenadoAbiertoArbolBinBusq(tArbolBinBusq *p, FILE *pf, unsigned tamInfo);
int cargarArchivoBinOrdenadoArbolBinBusq(tArbolBinBusq * p, const char * path, unsigned tamInfo);
int cargarDesdeDatosOrdenadosArbolBinBusq(tArbolBinBusq *p,void *ds, unsigned cantReg,unsigned (*leer)(void **, void *, unsigned, void *params),void * params);
int mayorElemNoClaveArbolBinBusq(const tArbolBinBusq *p, void *d, unsigned tam,	int (*cmp)(const void *, const void *));
int menorElemNoClaveArbolBinBusq(const tArbolBinBusq *p, void *d, unsigned tam,	int (*cmp)(const void *, const void *));
int buscarElemNoClaveArbolBinBusq(const tArbolBinBusq *p, void *d, unsigned tam, int (*cmp)(const void *, const void *));

///Utils
unsigned alturaArbolBin(const tArbolBinBusq *p);
unsigned cantNodosArbolBin(const tArbolBinBusq *p);
unsigned cantNodosHastaNivelArbolBin(const tArbolBinBusq *p, int n);
int mayorElemArbolBinBusq(const tArbolBinBusq *p, void *d, unsigned tam);
int menorElemArbolBinBusq(const tArbolBinBusq *p, void *d, unsigned tam);
int esCompletoArbolBin(const tArbolBinBusq *p);
int esBalanceadoArbolBin(const tArbolBinBusq *p);
int esAVLArbolBin(const tArbolBinBusq *p);
int esCompleto2ArbolBin(const tArbolBinBusq *p); int esBalanceado2ArbolBin(const tArbolBinBusq *p);
int esAVL2ArbolBin(const tArbolBinBusq *p);

#endif // FUNCIONES_H_INCLUDED
