#include "Funciones.h"

void intercambiar (void *a, void *b,int tamelem)///a,b,aux triangular pero generico
{
    char aux[tamelem];
    memcpy(aux,a,tamelem);
    memcpy(a,b,tamelem);
    memcpy(b,aux,tamelem);
}

int menu_errores(int error)
{
    if(error==0)
        return SI;
    switch(error)
    {
    case 1:
        puts("Se produjo un error con el archivo\nSaliendo...");
        return NO;
        break;

    ////////////////////////
    case 2:
        puts("Se produjo un error con el numero de argumentos enviados en el main\nSaliendo...");
        return NO;
        break;

    case 3:
        puts("\nSaliendo...");
        return NO;
        break;

    case 4:
        puts("No hay memoria para realizar la accion\nSaliendo...");
        return NO;
        break;

    case 5:
        puts("La pila/cola/lista esta vacia\nSaliendo...");
        return NO;
        break;

    case 9:
        puts("La pila/cola/lista esta llena\nSaliendo...");
        return NO;
        break;

    case 6:
        puts("El dato no se pudo insertar\nSaliendo...");
        return NO;
        break;

    case 7:
        puts("El dato no se elimino. Revise que el dato exista\nSaliendo...");
        return NO;
        break;

    case 8:
        puts("La cadena esta vacia\nSaliendo...");
        return NO;
        break;

//    case 3:
//        puts("\nSaliendo...");
//        return NO;
//        break;
    }
    return NO;
}


///----------------------------- V E C T O R E S ----------------------------------


void ordenarSeleccion(void* v, int cantElem,int tamelem,Cmp cmp)
{
    void* m;
    void * ult = v+ (cantElem -1)*tamelem; /// ult = v + sizeof(int)* (cantElem -1) /// producto q hace el compilador solo
    for(void* i=v; i < ult; i+=tamelem)
    {
        m = buscarMenor(i, ult,tamelem,cmp);
        if(m != i)
            intercambiar(m, i,tamelem);
    }
}

//////////////////////////////////////////////

void* buscarMenor(void *desde, void* hasta, int tamelem,Cmp cmp)
{
    void* m = desde;
    for(void* j = desde + tamelem; j <= hasta; j+=tamelem)
    {
        if(cmp(j,m)<0)
            m = j;
    }
    return m;
}

//////////////////////////////////////////////

void mostrarvec(void* v, int ce, int tamelem)
{
    void * ult = v + (ce-1) * tamelem;
    for(void* i=v; i<ult; i+=tamelem)
        printf("%d - ",*(int*)i);
}

//////////////////////////////////////////////

void inicializarvecrandom(int* v, int ce)
{
    int * ult = v+ce-1;
    srand(time(NULL));
    for(int* i= v; i<=ult; i++)
    {
        *i=rand()%100000;
    }
}

//////////////////////////////////////////////

int cmp (const void* e1, const void* e2)
{
    return *(int*)e1-*(int*)e2;
}

//////////////////////////////////////////////

int insercion_pos(int x,int pos,int*ce,int*V)
{
    int i;
    if(pos>(*ce)||pos<1)
        return NO_INSERTO;
    else
    {
        if(*(ce)==TAM)
            (*ce)--;//SE ELIMINARA EL ULTIMO
        (*ce)++;//agranda el vector y mueve todos los de la derecha uno hacia la derecha
        V+=*ce;
        for(i=*(ce); i>pos-1; i--)
        {
            *V=*(V-1);
            V--;
        }
        (*V)=x;
        return TODO_OK;
    }
}

//////////////////////////////////////////////

int insercionord(int x,int*ce,int*vec)
{
    (*ce)++;
    vec+=*ce;
    do
    {
        *vec=*(vec-1);
        vec--;
    }
    while(x<*(vec-1));
    *vec=x;
    return TODO_OK;
}

//////////////////////////////////////////////

int eliminarpos(int pos,int*ce,int*vec)
{
    if(pos>*ce||pos<0)
        return NO_INSERTO;
    vec+=pos-1;
    while(pos-1!=*ce)
    {
        *(vec)=*(vec+1);
        vec++;
        pos++;
    }
    (*ce)--;
    return TODO_OK;
}

//////////////////////////////////////////////

int eliminar_primer_aparicion(int*vec,int*ce,int val)
{
    int cont=0;
    while(val!=*vec&&cont<*ce)
    {
        vec++;
        cont++;
    }
    if(val!=*vec)
        return NO_ELIMINO;
    while(cont<*ce)
    {
        *(vec)=*(vec+1);
        vec++;
        cont++;
    }
    (*ce)--;
    return TODO_OK;
}

//////////////////////////////////////////////

int eliminarval(int*vec,int*cant,int val)
{
    int tam=*cant,*sig=vec;//sig=puntero de lectura   vec=puntero de escritura
    while(tam!=0)
    {
        if(*sig==val)
            (*cant)--;
        else
        {
            *vec=*sig;
            vec++;
        }
        sig++;
        tam--;
    }
    return sig!=vec;
}


///----------------------------- A R C H I V O S   B I N A R I O S ----------------------------------                                                           archivos binarios


int generarArchivoBin(const char* nomArchivo)///para llamarla se manda nombre del archivo
{
//    static producto vA[]=///vA= vector archivo
//    {
//        {2,"Mandarina",40},
//        {4,"Banana",100},
//        {7,"Pera",50},
//        {9,"Manzana",70},
//        {10,"Naranja",90}
//    };
//
    static Empleado vA[]=///vA= vector archivo
    {
        {1234,"Antunez","Gerardo",40000},
        {2345,"Antunez","Pedro",100000},
        {3456,"Antunez","Pedro",50000},
        {4567,"Chipan","Nestor",70000},
        {5678,"Lopez","Luis",90000}
    };
//    static Alumno vA[]=///vA= vector archivo
//    {
//        {1234,"Antunez","Gerardo",7},
//        {2345,"Antunez","Pedro",4},
//        {3456,"Antunez","Pedro",8},
//        {4567,"Chipan","Nestor",9},
//        {5688,"Zella","Ayrton",6},
//        {6789,"Zella","Ezequiel",7.5},
//    };
    FILE* pA = fopen(nomArchivo,"wb");///pA = puntero archivo
    if(!pA)
    {
        puts("Error abriendo archivo");
        return ERROR_ARCH;
    }
    fwrite(vA,sizeof(vA),1,pA);
    fclose(pA);
    return TODO_OK;
}

//////////////////////////////////////////////

int mostrarArchivosBin(const char* nomArchivo,int tamstruct)
{
    FILE* pA = fopen (nomArchivo,"rb");
    if(!pA)
    {
        puts("Error abriendo archivo");
        return ERROR_ARCH;
    }
//    producto reg;
    Empleado reg;
//    Alumno reg;
    fread(&reg,tamstruct,1,pA); ///-> fread(&reg,sizeof(empleado),1,pA);
    while(!feof(pA))
    {
//        printf("%d|%s|%d|%f|%d/%d/%d",reg.codigo,reg.descripcion,reg.cantidad,reg.preciouni,
//                reg.fechapreciouni.dia,reg.fechapreciouni.mes,reg.fechapreciouni.anio);           ///producto
        printf("%d\t%s\t%s\t%-.2lf\n",reg.dni,reg.ape,reg.nom,reg.sueldo);                        ///empleado
//        printf("%d\t%s\t%s\t%-.2f\n",reg.dni,reg.ape,reg.nom,reg.prom);                           ///alumno

        fread(&reg,tamstruct,1,pA);
    }
    fclose(pA);
    return TODO_OK;
}

int AumentaSueldos(const char* arch1,const char* arch2)///arch1 = alumno    arch2=empleado
{
    FILE* pA1 = fopen (arch1,"rb");
    FILE* pA2 = fopen (arch2,"r+b");
    if(!pA1||!pA2)
        return ERROR_ARCH;
    Alumno alu;
    Empleado emp;
    fread(&alu,sizeof(Alumno),1,pA1);
    fread(&emp,sizeof(Empleado),1,pA2);
    while(!feof(pA1)&&!feof(pA2))
    {
        int comparoapellido=mi_strcmp(emp.ape,alu.ape);
        int comparonombre=mi_strcmp(emp.nom,alu.nom);
        if((comparoapellido>0) || (comparoapellido==0 && comparonombre>0) || (comparoapellido==0 && comparonombre==0 && emp.dni>alu.dni))
            fread(&alu,sizeof(Alumno),1,pA1);
        else if(comparoapellido==0 && comparonombre==0 && emp.dni==alu.dni && alu.prom>=7)
        {
            fseek(pA2,-(long)sizeof(Empleado),SEEK_CUR);
            emp.sueldo+=emp.sueldo*0.0728;
            fwrite(&emp,sizeof(Empleado),1,pA2);
            fseek(pA2,0L,SEEK_CUR);
            fread(&alu,sizeof(Alumno),1,pA1);
            fread(&emp,sizeof(Empleado),1,pA2);
        }
        else
            fread(&emp,sizeof(Empleado),1,pA2);
    }
    return TODO_OK;
}


//////////////////////////////////////////////

//void acumularDuplicados(FILE* movsA,producto* mov)
//{
//    producto movDup;
//    producto prod;
//    fread(&movDup,sizeof(producto),1,movsA);
//    while(!feof(movsA)&& mov->codigo == movDup.codigo)
//    {
//        mov->cantidad += movDup.cantidad;
//        fread(&movDup,sizeof(producto),1,movsA);
//    }
//    fwrite(&prod,sizeof(producto),1,prodsTmpA);
//
//    if(!feof(movsA))
//        mov=movDup;
//}


///----------------------------- A R C H I V O S   D E  T E X T O ----------------------------------


int ofuscado(char* nombarch)
{
    char* pinipalmov;
    char* pfinpal;
    char* pinipal;
    int i;
    int numletpal;///numero de letra en la palabra
    FILE* ptxt=fopen(nombarch,"rt");
    FILE* pdestino=fopen("resultado.txt","wt");
    if(!ptxt||!pdestino)
        return ERROR_ARCH;
    char palabra[TAM_LINEA];
    while(fscanf(ptxt,"%s ",palabra)!=EOF)
    {
        i=0;
        numletpal=1;
        pinipal=pfinpal=pinipalmov=palabra;
        while((*(pfinpal+1))!='\0' && (*(pfinpal+1))!='\t' && (*(pfinpal+1))!=' ' && (*(pfinpal+1))!='\n')
            pfinpal++;
        while((*pfinpal)==','||(*pfinpal)=='.')
            pfinpal--;
        while((pinipalmov-1)!=pfinpal)
        {
            (*pinipalmov)-=numletpal;
            numletpal++;
            pinipalmov++;
            if((*pinipalmov)!='\0' && (*pinipalmov)!='\t' && (*pinipalmov)!=' ' && (*pinipalmov)!='\n')
            {
                if((*pinipalmov)-numletpal<'A' && ES_LETRA(*pinipalmov))
                    (*pinipalmov)+=58;
                if((*pinipalmov)-numletpal<'a'&& (*pinipalmov)-numletpal>'Z')
                    (*pinipalmov)-=7;
            }
        }
        invertirString(palabra);
        while(*(pinipal+i)=='.' || *(pinipal+i)==',' || *(pinipal+i)=='\n')
            i++;
        fprintf(pdestino,"%s",palabra+i);
        for(int j=0; j<i; j++)
            fprintf(pdestino,"%c",*(palabra+j));
        fprintf(pdestino," ");
    }
    fclose(ptxt);
    fclose(pdestino);
    return TODO_OK;
}

//////////////////////////////////////////////

int eliminarYMostrarRepetidos_MIO(tLista *p, FILE *fpPant,int comparar(const void *, const void *),void mostrar(const void *, FILE *))
{
    tNodo* p_busq;
    tNodo* p_busq_ant=NULL;
    tNodo* p_principio=*p;
    tNodo* p_elim;
    int cont=0;
    mostrar(NULL,fpPant);
    tFinal dni_a_elim;
    while(p_principio!=NULL)
    {
        p_busq=p_principio;                                                     ///pbusq se pone en el principio desde donde voy a recorrer eliminando
        if(contarApariciones(p_principio,comparar)>1)                           ///si tiene mas de una aparicion, se elimina
        {
            dni_a_elim=*((tFinal*)(p_principio->info));                         ///dni a eliminar
            while(p_busq!=NULL)                                                 ///hasta q pbusq no llegue al final no termino
            {
                if(comparar(&dni_a_elim,p_busq->info)==0)                       ///si son iguales procedo a eliminar
                {
                    cont++;                                                     ///sumo 1
                    if(p_busq!=(*p))                                            ///si es el primero de la lista, no tiene enganche
                        p_busq_ant->sig=p_busq->sig;                            ///engancho
                    if(p_busq==(*p))                                            ///si es el primero de la lista, tengo q mover el puntero lista
                        *p=p_busq->sig;                                          ///muevo puntero lista
                    if(p_busq==p_principio)                                     ///si estoy eliminando el del principio, muevo el principio
                        p_principio=p_principio->sig;                           ///muevo
                    p_elim=p_busq;                                              ///determino en pelim el q voy a eliminar
                    p_busq=p_busq->sig;                                         ///avanzo pbusq (pbusq ant sigue donde esta)
                    mostrar(p_elim->info,fpPant);                               ///muestro
                    free(p_elim->info);                                         ///libero
                    free(p_elim);                                               ///libero
                }
                else
                {
                    p_busq_ant=p_busq;                                          ///no es el dato a eliminar, avanzo
                    p_busq=p_busq->sig;                                         ///no es el dato a eliminar, avanzo
                }
            }
        }
        else
        {
            p_busq_ant=p_principio;
            p_principio=p_principio->sig;                                       ///no aparece mas de una vez, avanzo
        }
    }
    return cont;
}

//////////////////////////////////////////////

int eliminarYMostrarUnicos_MIO(tLista *p, FILE *fpPant,int comparar(const void *, const void *),void mostrar(const void *, FILE *))
{
    tNodo* p_busq=(*p)->sig;
    tNodo* p_busq_izq;
    tNodo* p_elim=*p;
    int cont=0;
    mostrar(NULL,fpPant);
    while(p_elim!=NULL)
    {
        p_busq_izq=*p;
        while(p_busq!=NULL && comparar(p_elim->info,p_busq->info)!=0)
            p_busq=p_busq->sig;                       ///avanzo
        if(p_busq==NULL)
            while(p_busq_izq->sig!=p_elim && comparar(p_elim->info,p_busq_izq->info)!=0)
                p_busq_izq=p_busq_izq->sig;

        if(p_busq==NULL && (p_busq_izq->sig==p_elim||p_busq_izq==p_elim))  ///ELIMINA
        {
            mostrar(p_elim->info,fpPant);            ///muestra
            if(p_busq_izq!=p_elim)
                p_busq_izq->sig=p_elim->sig;         ///engancho
            if(*p==p_elim)
                *p=(*p)->sig;
            p_busq=p_elim->sig;
            free(p_elim->info);                      ///libreo
            free(p_elim);                            ///libero
            p_elim=p_busq;
            cont++;                                  ///cuento
        }
        else
            p_elim=p_elim->sig;
        if(p_elim)
            p_busq=p_elim->sig;
    }
    return cont;
}


///----------------------------- F E C H A ----------------------------------


int esBisiesto(int anio)
{
    return (anio%400==0 || (anio%100!=0 && anio%4==0));
}

//////////////////////////////////////////////

int cantDiaMes(int mes,int anio)
{
    if(mes==4||mes==6||mes==9||mes==11)
        return 30;
    if(mes==2)
    {
        if(esBisiesto(anio))
            return 29;
        else
            return 28;
    }
    return 31;
}

//////////////////////////////////////////////

Fecha* diaSiguiente(Fecha fec)
{
    Fecha* fecRes=(Fecha*)malloc(sizeof(Fecha*));
    fecRes->dia=fec.dia;
    fecRes->mes=fec.mes;
    fecRes->anio=fec.anio;
    fecRes->dia++;
    if(fecRes->dia>cantDiaMes(fecRes->mes,fecRes->anio))
    {
        fecRes->dia=1;
        fecRes->mes++;
        if(fecRes->mes>12)
        {
            fecRes->mes=1;
            fecRes->anio++;
        }
    }
    return fecRes;
}

//////////////////////////////////////////////

int esFechaVal(Fecha *fec)
{
    if(fec->anio>=1600)
        if(fec->mes>0 && fec->mes<13)
            if(fec->dia>0 && fec->dia<=cantDiaMes(fec->mes,fec->anio))
                return SI;
    return NO;
}

//////////////////////////////////////////////

int diaDelAnio(const Fecha* fec)
{
    static int diaMes[2][13]= {{0,31,59,90,120,151,181,212,243,273,304,334,365},
        {0,31,60,91,121,152,182,213,244,274,305,335,366}
    };
    return diaMes[esBisiesto(fec->anio)?1:0][fec->mes-1]+fec->dia;
}

//////////////////////////////////////////////

int diaRel(const Fecha* fec)
{
    int difAnios=fec->anio-1601;
    return difAnios*365+difAnios/4-difAnios/100+difAnios/400+diaDelAnio(fec);
}

//////////////////////////////////////////////

Fecha* sumarDias(Fecha* fec, int dias)
{
    Fecha* fecR=(Fecha*)malloc(sizeof(Fecha*));
    fecR->dia=fec->dia;
    fecR->mes=fec->mes;
    fecR->anio=fec->anio;
    fecR->dia+=dias;
    if(fecR->dia>cantDiaMes(fecR->mes,fecR->anio))
    {
        while(fecR->dia>cantDiaMes(fecR->mes,fecR->anio))
        {
            fecR->dia-=cantDiaMes(fecR->mes,fecR->anio);
            fecR->mes++;
        }
        while(fecR->mes>12)
        {
            fecR->mes-=12;
            fecR->anio++;
        }
    }
    return fecR;
}

//////////////////////////////////////////////

Fecha* restarDias(const Fecha* fec, int dias)
{
    Fecha* fecR=(Fecha*)malloc(sizeof(Fecha*));
    fecR->dia=fec->dia;
    fecR->mes=fec->mes;
    fecR->anio=fec->anio;
    fecR->dia-=dias;
    while(fecR->dia<1)
    {
        fecR->mes--;
        if(fecR->mes<1)
        {
            fecR->mes=12;
            fecR->anio--;
        }
        fecR->dia+=cantDiaMes(fecR->mes,fecR->anio);
    }
    return fecR;
}

//////////////////////////////////////////////

int diasEntreFechas(const Fecha* fec1, const Fecha* fec2)
{
    return abs(diaRel(fec1)-diaRel(fec2));
}

//////////////////////////////////////////////

int diaDeLaSemana(const Fecha* fec) ///ACLARACION SI RETORNA 0 ES MIECOLES, 1 JUEVES, ETC
{
    Fecha fechaBase= {1,1,1601};
    int dif=diasEntreFechas(&fechaBase,fec);
    return dif%7;
}


///----------------------------- M A T R I C E S ----------------------------------


int menu_matrices ()
{
    int opcion;
    printf("Opciones:\n \
    1.  Elementos de la diagonal principal (con formato) \n \
    2.  Elementos de la diagonal secundaria (con formato)\n \
    3.  Elementos del triangulo superior con diagonal (con formato)\n \
    4.  Elementos del triangulo superior sin diagonal (con formato)\n \
    5.  Elementos del triangulo inferior con diagonal (con formato)\n \
    6.  Elementos del triangulo inferior sin diagonal (con formato)\n \
    7.  Elementos del triangulo inferior + diagonal secundaria (con formato)\n \
    8.  Elementos del triangulo superior + diagonal secundaria (con formato)\n \
    9.  Suma del triangulo superior (sin diagonal)\n \
    10. Traza de la matriz (suma de la diagonal principal)\n \
    11. Es matriz diagonal?\n \
    12. Es matriz identidad?\n \
    13. Es simetrica?\n \
    15. Transponer matriz\n \
    16. \n \
    17. \n \
    18. \n \
    19. \n \
    0. Exit\n\
ingrese un numero para elegir una opcion:");
    scanf("%d",&opcion);
    return opcion;
}

//////////////////////////////////////////////

void diagonalprincipal(int mat[][COL])
{
    int i,j;
    for(i=0; i<COL; i++)
    {
        printf("%d\n",mat[i][i]);
        for(j=0; j<=i; j++)
            printf("\t");
    }
}

//////////////////////////////////////////////

void diagonalsecundaria(int mat[][COL])
{
    int i,a;
    for(i=0; i<FIL; i++)
    {
        for(a=0; a<COL-1-i; a++)
            printf("\t");
        printf("%d\n",mat[i][COL-1-i]);
    }
}

//////////////////////////////////////////////

void triangulosuperiorcd(int mat[][COL])
{
    int i, j,a;
    for(i=0; i<FIL; i++)
    {
        for(j=i; j<COL; j++)
            printf("%d\t",mat[i][j]);
        printf("\n");
        for(a=0; a<=i; a++)
            printf("\t");
    }
}

//////////////////////////////////////////////

void triangulosuperiorsd(int mat[][COL])
{
    int i, j,a;
    for(i=0; i<FIL-1; i++)
    {
        printf("\n");
        for(a=0; a<=i; a++)
            printf("\t");
        for(j=i+1; j<=COL-1; j++)
            printf("%d\t",mat[i][j]);
    }
}

//////////////////////////////////////////////

void trianguloinferiorcd(int mat[][COL])
{
    int i,j;
    for(i=0; i<COL; i++)
    {
        for(j=0; j<=i; j++)
            printf("%d\t",mat[i][j]);
        printf("\n");
    }
}

//////////////////////////////////////////////

void trianguloinferiorsd(int mat[][COL])
{
    int i,j;
    for(i=1; i<COL; i++)
    {
        for(j=0; j<i; j++)
            printf("%d\t",mat[i][j]);
        printf("\n");
    }
}

//////////////////////////////////////////////

void triansupdiagsecun(int mat[][COL])//tab en la fila anterior y esta
{
    int i,j,b=COL/2,cont=0;
    float a;
    for(i=0; i<FIL; i++)
    {
        if(i<=(FIL/2))
            cont++;
        else
            cont--;

        for(b=1; b<cont; b++)
            printf("\t");

        if(i>=FIL/2)
            printf("%d",mat[i][COL-1-i]);//dato diagonal

        for(a=2; a<i; a+=0.5)//tab 2
            printf("\t");

        for(j=i+1; j<=COL-1; j++)
            printf("%d\t",mat[i][j]);//dato triangulo

        puts(" ");
    }
}

//////////////////////////////////////////////

void trianinfdiagsecun(int mat[][COL])
{
    int i,j,a=COL-1,b;
    for(i=0; i<COL; i++)
    {
        if(i==0)
        {
            for(j=0; j<COL-1; j++)
                printf("\t");
            printf("%d\t",mat[i][COL-1]);
        }
        else
            for(j=0; j<i; j++)
                printf("%d\t",mat[i][j]);
        for(b=COL-1; b>i*2; b--)
            printf("\t");
        if(j<=a&&i!=0)
            printf("%d",mat[i][a]);
        printf("\n");
        a--;
    }
}

//////////////////////////////////////////////

int suma_tri_sup(int mat[][COL])
{
    int sum=0,i,j;
    for(i=0; i<FIL; i++)
        for(j=i+1; j<COL; j++)
            sum+=mat[i][j];
    return sum;
}

//////////////////////////////////////////////

void rotarMat180_MIO(int m[][COLUM], int filas, int colum)
{
    int i,j,aux;
    for(i=0; i<filas/2; i++)
        for(j=0; j<colum; j++)
        {
            aux=m[i][j];
            m[i][j]=m[filas-i-1][colum-j-1];
            m[filas-i-1][colum-j-1]=aux;
        }
    if(filas%2!=0)
        for(j=0; j<colum/2; j++)
        {
            aux=m[i][j];
            m[i][j]=m[filas-i-1][colum-j-1];
            m[filas-i-1][colum-j-1]=aux;
        }
}

//////////////////////////////////////////////

void rotarMat90(int m[][TAM_MAT], int filas, int colum)
{
    printf("\n\n");
    int i,j,aux;
    for(i=0; i<filas/2; i++)
        for(j=0; j<colum; j++)
        {
            aux=m[i][j];
            m[i][j]=m[filas-i-1][j];
            m[filas-i-1][j]=aux;
        }

    ///----------------------------

    for(i=0; i<=filas-2; i++)
        for(j=0; j<=colum-i-2; j++)
        {
            aux=m[i][j];
            m[i][j]=m[filas-j-1][colum-1-i];
            m[filas-j-1][colum-1-i]=aux;
        }
}

//////////////////////////////////////////////

int traza(int mat[][COL])
{
    int sum=0,i;
    for(i=0; i<FIL; i++)
        sum+=mat[i][i];
    return sum;
}

//////////////////////////////////////////////

void mostrarmatriz(int mat[][COL])
{
    int i,j;
    for(i=0; i<FIL; i++)
    {
        for(j=0; j<COL; j++)
            printf("%d\t",mat[i][j]);
        printf("\n");
    }
}

//////////////////////////////////////////////

int matrizdiagonal(int mat[][COL])
{
    int i,j;
    for(i=0; i<FIL; i++)
        for(j=0; j<COL; j++)
            if(mat[i][j]!=0&&i!=j)
                return NO;
    return SI;
}

//////////////////////////////////////////////

int matrizidentidad(int mat[][COL])//no tendria que recorrer toda, si preguntar por toda
{
    int i,j;
    for(i=0; i<FIL; i++)
        for(j=0; j<COL; j++)
            if((mat[i][j]!=0&&i!=j)||(i==j&&mat[i][j]!=1))
                return NO;
    return SI;
}

//////////////////////////////////////////////

int essimetrica(int mat[][COL])
{
    int i,j;
    for(i=0; i<FIL; i++)
        for(j=i+1; j<COL; j++)
            if(mat[i][j]!=mat[j][i])
                return NO;
    return SI;
}

//////////////////////////////////////////////

void transponer(int mat[][COL])
{
    int i,j,aux;

    for(j=0; j<COL; j++)
        for(i=j+1; i<FIL; i++)
        {
            aux=mat[i][j];
            mat[i][j]=mat[j][i];
            mat[j][i]=aux;
        }
}

//////////////////////////////////////////////

int escuadrada(int fil, int col)
{
    return fil==col;
}


///----------------------------- S T R I N G  Y  C T Y P E ----------------------------------


int espalindromo(char *cad)
{
    char* pfin=cad;
    while(*(pfin+1)!='\0')//strlen?
        pfin++;
    while(*cad==*pfin)
    {
        cad++;
        pfin--;
        if(cad+1==pfin||cad==pfin)
            return SI;
        if(*cad==' ')
            cad++;
        if(*pfin==' ')
            pfin--;
    }
    return NO;
}

//////////////////////////////////////////////

char* normalizar_nombre(char* s)///todas las palabras con la primera en mayuscula y resto en minuscula
{
    char*ori=s;
    char*des=s;
    while(*ori)
    {
        while(ES_BLANCO(*ori))
            ori++;
        if(*ori)
        {
            *des=MIN_A_MAY(*ori);
            des++;
            ori++;
            while(!ES_BLANCO(*ori)&&*ori)
            {
                *des=MAY_A_MIN(*ori);
                des++;
                ori++;
            }
            if(ES_BLANCO(*ori))
            {
                *des=MAY_A_MIN(*ori);
                ori++;
                des++;
            }
        }
    }
    if(des>s&&*(des-1)==' ')
        des--;
    *des='\0';
    return s;
}

//////////////////////////////////////////////

char* normalizar_texto(char*s)
{
    char*plect=s;///plect=puntero de lectura
    char*pescr=s;///pescr=puntero de escritura
    int primerpalabra =1;
    while(*plect)
    {
        while(ES_BLANCO(*plect))
            plect++;
        if(ES_LETRA(*plect)&&primerpalabra==1)
        {
            *pescr=MIN_A_MAY(*plect);
            primerpalabra=0;
            plect++;
            pescr++;
        }
        while(ES_LETRA(*plect))
        {
            *pescr=MAY_A_MIN(*plect);
            plect++;
            pescr++;
        }
        while(ES_NUMERO(*plect))
        {
            *pescr=*plect;
            plect++;
            pescr++;
        }
        if(ES_BLANCO(*plect))
        {
            *pescr=*plect;
            plect++;
            pescr++;
        }
        if(*plect=='$' && !ES_NUMERO(*(plect+1)))
            plect++;
        else if(*plect=='$' && ES_NUMERO(*(plect+1)))
        {
            *pescr=*plect;
            plect++;
            pescr++;
        }
        if(*plect=='.'||*plect==','||*plect=='?'||*plect=='!')
        {
            if(*plect=='.'||*plect=='?'||*plect=='!')
                primerpalabra=1;
            if(plect==pescr)
            {
                avanzar_3_espacios(plect);
                plect+=3;
            }
            *pescr=*plect;
            pescr++;
            *pescr=' ';
            pescr++;
            plect++;
        }
    }
    while(*(pescr-1)==' ')
        pescr--;
    *pescr='\0';
    return s;
}

//////////////////////////////////////////////

void avanzar_3_espacios(char* s)
{
    char* pfin=s;
    while(*pfin!='\0')
        pfin++;
    while(pfin>=s)
    {
        *(pfin+3)=*pfin;
        pfin--;
    }
}

//////////////////////////////////////////////

size_t mi_strlen(const char *cad)
{
    size_t i = 0;
    while(*(cad)!='\0')
    {
        cad++;
        i++;
    }
    return i;
}

//////////////////////////////////////////////

char *mi_strncpy(char *cad_copia, const char *cad_orig, size_t n)
{
    int i;
    for(i=0; i<n; i++)
    {
        *(cad_copia) = *(cad_orig);
        cad_copia++;
        cad_orig++;
    }
    *(cad_copia) = '\0';

    return cad_copia;
}

//////////////////////////////////////////////

int mi_strcmp(const char* a,const char* b)
{
    char *i=(char*)a;
    char *j=(char*)b;
    while(*i && *j && (*i==*j))
    {
        i++;
        j++;
    }
    return *i>*j ? 1 : *i<*j ? -1 : 0;
}

//////////////////////////////////////////////

char *mi_strncat(char *cad_de_enlace, const char *cad_a_enlazar, size_t n)
{
    int i;
    while(*(cad_de_enlace)!='\0')
        cad_de_enlace++;
    for(i=0; i<n; i++)
    {
        *(cad_de_enlace) = *(cad_a_enlazar);
        cad_de_enlace++;
        cad_a_enlazar++;
    }
    *(cad_de_enlace) = '\0';
    return cad_de_enlace;
}

//////////////////////////////////////////////

char* mi_strchr(const char* cad2, int c)
{
    char* cad=(char*)cad2;
    while(*cad!=c && *cad)
        cad++;
    if(!*cad)
        return NULL;
    return cad;
}

//////////////////////////////////////////////

char* mi_strrchr(const char* cad2, int c)
{
    char* cad=(char*)cad2;
    char *ini = cad;
    while(*(cad)!='\0')
        cad++;
    while(*cad!=c && cad!=ini)
        cad--;
    if(*cad==*ini)
        return NULL;
    return cad;
}

//////////////////////////////////////////////

size_t mi_strcspn(const char *cad1, const char *cad2)
{
    size_t i = 0;
    const char *p = cad2;
    while(*cad1!='\0')
    {
        while(*cad2!='\0')
        {
            if(*(cad1)==*(cad2))
                return i;
            cad2++;
        }
        cad2 = p;
        cad1++;
        i++;
    }
    return i;
}

//////////////////////////////////////////////

char *mi_strpbrk(char *cad1,char *cad2)
{
    char *ini2 = cad2;

    while(*cad1!='\0')
    {
        while(*cad2!='\0')
        {
            if(*(cad1)==*(cad2))
                return cad1;
            cad2++;
        }
        cad2 = ini2;
        cad1++;
    }
    return NULL;
}

//////////////////////////////////////////////

char *mi_strstr(char *cad1,char *cad2)
{
    char *ini1 = cad1, *ini2 = cad2;
    while(*(cad1)!='\0')
    {
        if(*(cad2)=='\0')
            return ini1;
        if(*(cad1)!=*(cad2))
        {
            cad2 = ini2;
            cad1++;
            ini1 = cad1;
        }
        else
        {
            cad2++;
            cad1++;
        }
    }
    return NULL;
}

//////////////////////////////////////////////

void invertirString(char* cad)
{
    char* i=cad;
    char aux;
    char* fin= cad + mi_strlen(cad)-1;
    while(i<fin)
    {
        aux=*i;
        *i=*fin;
        *fin=aux;
        i++;
        fin--;
    }
}

//////////////////////////////////////////////

char* mi_itoa(int num, char* cad, int sistema)
{
    char* i=cad;
    int uni=num%sistema;
    do
    {
        *i=(uni>=10)?uni+'a'-10:uni+'0';
        i++;
        num/=sistema;
        uni=num%sistema;
    }
    while(num);
    *i='\0';
    invertirString(cad);
    return cad;
}

//////////////////////////////////////////////

int mi_atoi(const char* cad)
{
    int x=0;
    char* i=(char*)cad;
    while(*i)
    {
        x*=10;
        x+=*i-'0';
        i++;
    }
    return x;
}

//////////////////////////////////////////////

char* primeraPalabra(const char* cad)
{
    char* r=(char*)malloc(sizeof(char*));
    char* j=r;
    char* i=(char*)cad;
    while(*i<'A' || (*i>'Z' && *i<'a') || *i>'z')
        i++;
    while((*i>='A' && *i<='Z') || (*i>='a' && *i<='z'))
    {
        *j=*i;
        j++;
        i++;
    }
    *j='\0';
    return r;
}

//////////////////////////////////////////////

int contarPalabras(const char* cad)
{
    int cont=0;
    char* pcad=(char*)cad;
    while(*pcad!='\0')
    {
        if(ES_LETRA(*pcad))
        {
            while(ES_LETRA(*pcad))
                pcad++;
            cont++;
        }
        if(*pcad)
            pcad++;
    }
    return cont;
}

//////////////////////////////////////////////

int vecesRepite(const char* pal,const char* cad)
{
    if(*pal=='\0')
        return CADENA_VACIA;
    char* pala = (char*) pal;
    char* cada = (char*) cad;
    int cont=0;
    while(*cada!='\0')
    {
        while(*cada==*pala)
        {
            cada++;
            pala++;
        }
        if(*pala=='\0')
            cont++;
        pala=(char*)pal;
        cada++;
    }
    return cont;
}

int contarOcurrencias1_MIO(const char *cad, const char *sub)///anana = 2 veces ana
{
    if(*sub=='\0')
        return 1;
    char* subp = (char*) sub;
    char* cadp = (char*) cad;
    char* cadpini;
    int cont=0;
    while(*cadp!='\0')
    {
        while(MAY_A_MIN(*cadp)!=MAY_A_MIN(*subp)&&*cadp!='\0')
            cadp++;
        cadpini=cadp;
        cadpini++;
        while(MAY_A_MIN(*cadp)==MAY_A_MIN(*subp)&&*cadp!='\0')
        {
            cadp++;
            subp++;
        }
        if(*subp=='\0')
        {
            cont++;
            cadp=cadpini;
        }
        subp=(char*)sub;
    }
    return cont;
}

int contarOcurrencias2_MIO(const char *cad, const char *sub) ///anana = 1 vez ana
{
    if(*sub=='\0')
        return 1;
    char* palp = (char*) sub;
    char* cadp = (char*) cad;
    int cont=0;
    while(*cadp!='\0')
    {
        while(MAY_A_MIN(*cadp)!=MAY_A_MIN(*palp) && *cadp!='\0')
            cadp++;
        while(MAY_A_MIN(*cadp)==MAY_A_MIN(*palp) && *cadp!='\0')
        {
            cadp++;
            palp++;
        }
        if(*palp=='\0')
            cont++;
        palp=(char*)sub;
    }
    return cont;
}
//////////////////////////////////////////////

int mi_ctoi(char c)
{
    return c -'0';
}

//////////////////////////////////////////////

char *mi_strcpy(char *cad_copia, const char *cad_orig)
{
    while(*(cad_orig)!='\0')
    {
        *(cad_copia) = *(cad_orig);
        cad_copia++;
        cad_orig++;
    }
    *(cad_copia) = '\0';

    return cad_copia;
}

//////////////////////////////////////////////

int palabramaslarga(const char* cad)
{
    int tampal=0;
    int cont=0;
    char* pcad=(char*)cad;
    while(*pcad!='\0')
    {
        if(ES_LETRA(*pcad))
        {
            while(ES_LETRA(*pcad))
            {
                pcad++;
                cont++;
            }
            if(cont>tampal)
                tampal=cont;
            cont=0;
        }
        if(*pcad)
            pcad++;
    }
    return tampal;
}

//////////////////////////////////////////////

int buscar_Y_Reemplazar(char *cade, int tam,const char *busc, const char *reem)
{
    char* inireem=(char*)reem;
    char* inibusc=(char*)busc;
    char* inicade=(char*)cade;
    char* fincade=(char*)cade;
    char* fincadecopiar;
    int masomenos;
    char* fincadepegar;
    int cantpalbusc=0, cantpalreemp=0, cantpalcade=0, cantveces=0;

    while(*fincade!='\0')
        fincade++;

    while(*busc!='\0')
    {
        busc++;
        cantpalbusc++;
    }
    busc=inibusc;

    while(*reem!='\0')
    {
        reem++;
        cantpalreemp++;
    }
    reem=inireem;

    while(*cade!='\0')
    {
        cade++;
        cantpalcade++;
    }
    cade=inicade;
    int diferencia=cantpalreemp-cantpalbusc;

    ///vamo a lo importante
    while(*cade!='\0')
    {
        while(tolower(*cade)==tolower(*busc) && *busc!='\0')
        {
            busc++;
            cade++;
        }
        if(*busc=='\0' && cantpalcade+diferencia<=tam)
        {
            cantveces++;
            cantpalcade+=diferencia;
            if(diferencia>0)
            {                           ///en cade voy a empezar a poner letra x letra una vez mueva todo hacia la derecha
                fincadecopiar=fincade;
                fincade+=diferencia;
                fincadepegar=fincade;
                masomenos=-1;
            }
            else
            {
                fincadecopiar=cade;
                fincadepegar=cade+diferencia;
                masomenos=1;
            }
            while((masomenos==1&&*(fincadecopiar-1)!='\0')||(masomenos==-1&&fincadecopiar!=cade-1))///muevo todo x cantidad de lugares hacia la derecha o izquierda
            {
                *fincadepegar=*fincadecopiar;
                fincadecopiar+=masomenos;
                fincadepegar+=masomenos;
            }
            cade-=cantpalbusc;
            while(*reem!='\0')
            {
                *cade=*reem;
                cade++;
                reem++;
            }
            reem=inireem;
        }
        else if(cantpalcade+diferencia>tam)
            return -(cantveces+1);
        busc=inibusc;
        cade++;
    }
    return cantveces;
}

//////////////////////////////////////////////

int contarletras(const char* cad)
{
    int cont=0;
    char* mov=(char*)cad;
    while(*mov!='\0')
    {
        if(ES_LETRA(*mov))
            cont++;
        mov++;
    }
    return cont;
}

//////////////////////////////////////////////

int contarapariciones(char carac,char* caden)
{
    int cont=0;
    while(*caden!='\0')
    {
        if(My_toupper(*caden)==carac)
            cont++;
        caden++;
    }
    return cont;
}

//////////////////////////////////////////////

int esAnagrama(const char *s1, const char *s2)
{
    char* cad1=(char*)s1;
    if(contarletras(s1)==contarletras(s2))
        while(*cad1!='\0')
        {
            if(ES_LETRA(*cad1)&&
                    contarapariciones(My_toupper(*cad1),(char*)s1)!=contarapariciones(My_toupper(*cad1),(char*)s2))
                return 0;
            cad1++;
        }
    else
        return 0;
    return 1;
}

///----------------------------- P I L A   E S T A T I C A ----------------------------------


void crearPila_est(t_pila_est *p)
{
    p->tope = TAM_PILA;
}

//////////////////////////////////////////////

int	pilaLlena_est(const t_pila_est *p, unsigned cantBytes)
{
    return p->tope < cantBytes + sizeof(unsigned);
}

//////////////////////////////////////////////

int	apilar_est(t_pila_est *p, const void *d, unsigned cantBytes)
{
    if(p->tope < cantBytes + sizeof(unsigned))
        return 0;
    p->tope -= cantBytes;
    memcpy(p->vEle + p->tope, d, cantBytes);
    p->tope -= sizeof(unsigned);
    memcpy(p->vEle + p->tope, &cantBytes, sizeof(unsigned));
    return 1;
}

//////////////////////////////////////////////

int	verTope_est(const t_pila_est *p, void *d, unsigned cantBytes)
{
    unsigned tamInfo;
    if(p->tope == TAM_PILA)
        return 0;
    memcpy(&tamInfo, p->vEle + p->tope, sizeof(unsigned));
    memcpy(d, p->vEle + p->tope + sizeof(unsigned),
           MINIMO(cantBytes, tamInfo));
    return 1;
}

//////////////////////////////////////////////

int	pilaVacia_est(const t_pila_est *p)
{
    return p->tope == TAM_PILA;
}

//////////////////////////////////////////////

int	desapilar_est(t_pila_est *p, void *d, unsigned cantBytes)
{
    unsigned tamInfo;

    if(p->tope == TAM_PILA)
        return 0;
    memcpy(&tamInfo, p->vEle + p->tope, sizeof(unsigned));
    p->tope += sizeof(unsigned);
    memcpy(d, p->vEle + p->tope, MINIMO(cantBytes, tamInfo));
    p->tope += tamInfo;
    return 1;
}

//////////////////////////////////////////////

void vaciarPila_est(t_pila_est *p)
{
    p->tope = TAM_PILA;
}



///----------------------------- P I L A   D I N A M I C A ----------------------------------


void crearPila_din(t_pila *p)
{
    *p = NULL;
}

//////////////////////////////////////////////

//int	pilaLlena_din(const t_pila *p, unsigned cantBytes)
//{
//    tNodo	*aux = (tNodo *)malloc(sizeof(tNodo));
//    void	*info = malloc(cantBytes);
//
//    free(aux);
//    free(info);
//    return aux == NULL || info == NULL;
//}

//////////////////////////////////////////////

int	ponerEnPila_din(t_pila *p, const void *d, unsigned cantBytes)
{
    tNodo *nue;

    if((nue = (tNodo *)malloc(sizeof(tNodo))) == NULL ||
            (nue->info = malloc(cantBytes)) == NULL)
    {
        free(nue);
        return 0;
    }
    memcpy(nue->info, d, cantBytes);
    nue->tamInfo = cantBytes;
    nue->sig = *p;
    *p = nue;
    return 1;
}

//////////////////////////////////////////////

int	verTope_din(const t_pila *p, void *d, unsigned cantBytes)
{
    if(*p == NULL)
        return 0;
    memcpy(d, (*p)->info, MINIMO(cantBytes, (*p)->tamInfo));
    return 1;
}

//////////////////////////////////////////////

int	pilaVacia_din(const t_pila *p)
{
    return *p == NULL;
}

//////////////////////////////////////////////

int	sacarDePila_din(t_pila *p, void *d, unsigned cantBytes)
{
    tNodo *aux = *p;

    if(aux == NULL)
        return 0;
    *p = aux->sig;
    memcpy(d, aux->info, MINIMO(cantBytes, aux->tamInfo));
    free(aux->info);
    free(aux);
    return 1;
}

//////////////////////////////////////////////

void vaciarPila_din(t_pila *p)
{
    while(*p)
    {
        tNodo *aux = *p;

        *p = aux->sig;
        free(aux->info);
        free(aux);
    }
}


///----------------------------- C O L A   E S T A T I C A ----------------------------------


void crearCola_est(t_cola_est *p)
{
    p->pri	= TAM_COLA - 70;
    p->ult	= TAM_COLA - 70;
    p->tamDisp = TAM_COLA;
}

//////////////////////////////////////////////

int colaLlena_est(const t_cola_est *p, unsigned cantBytes)
{
    return p->tamDisp < cantBytes + sizeof(unsigned);
}

//////////////////////////////////////////////

int ponerEnCola_est(t_cola_est *p, const void *d, unsigned cantBytes)
{
    unsigned	ini,fin;
    if(p->tamDisp < sizeof(unsigned) + cantBytes)
        return 0;
    p->tamDisp -= sizeof(unsigned) + cantBytes;
    if((ini = MINIMO(sizeof(cantBytes), TAM_COLA - p->ult)) != 0)
        memcpy(p->cola + p->ult, &cantBytes, ini);
    if((fin = sizeof(cantBytes) - ini) != 0)
        memcpy(p->cola, ((char *)&cantBytes) + ini, fin);
    p->ult = fin ? fin : p->ult + ini;
    if((ini = MINIMO(cantBytes, TAM_COLA - p->ult)) != 0)
        memcpy(p->cola + p->ult, d, ini);
    if((fin = cantBytes - ini) != 0)
        memcpy(p->cola, ((char *)d) + ini, fin);
    p->ult = fin ? fin : p->ult + ini;
    return 1;
}

//////////////////////////////////////////////

int	verPrimeroCola_est(const t_cola_est *p, void *d, unsigned cantBytes)
{
    unsigned tamInfo, ini, fin, pos = p->pri;
    if(p->tamDisp == TAM_COLA)
        return 0;
    if((ini = MINIMO(sizeof(unsigned), TAM_COLA - pos)) !=0)
        memcpy(&tamInfo, p->cola + pos, ini);
    if((fin = sizeof(unsigned) - ini) != 0)
        memcpy(((char *)&tamInfo) + ini, p->cola, fin);
    pos = fin ? fin : pos + ini;
    tamInfo = MINIMO(tamInfo, cantBytes);
    if((ini = MINIMO(tamInfo, TAM_COLA - pos)) != 0)
        memcpy(d, p->cola + pos, ini);
    if((fin = tamInfo - ini) != 0)
        memcpy(((char *)d) + ini, p->cola, fin);
    return 1;
}

//////////////////////////////////////////////

int	colaVacia_est(const t_cola_est *p)
{
    return p->tamDisp == TAM_COLA;
}

//////////////////////////////////////////////

int	sacarDeCola_est(t_cola_est *p, void *d, unsigned cantBytes)
{
    unsigned tamInfo,ini,fin;
    if(p->tamDisp == TAM_COLA)
        return 0;
    if((ini = MINIMO(sizeof(unsigned), TAM_COLA - p->pri)) != 0)
        memcpy(&tamInfo, p->cola + p->pri, ini);
    if((fin = sizeof(unsigned) - ini) != 0)
        memcpy(((char *)&tamInfo) + ini, p->cola, fin);
    p->pri = fin ? fin : p->pri + ini;
    p->tamDisp += sizeof(unsigned) + tamInfo;
    tamInfo = MINIMO(tamInfo, cantBytes);
    if((ini = MINIMO(tamInfo, TAM_COLA - p->pri)) != 0)
        memcpy(d, p->cola + p->pri, ini);
    if((fin = tamInfo - ini) != 0)
        memcpy(((char *)d) + ini, p->cola, fin);
    p->pri = fin ? fin : p->pri + ini;
    return 1;
}

//////////////////////////////////////////////

void vaciarCola_est(t_cola_est *p)
{
    p->ult = p->pri;
    p->tamDisp = TAM_COLA;
}


///----------------------------- C O L A   D I N A M I C A ----------------------------------


void crearCola_din(t_cola *p)
{
    p->pri = NULL;
    p->ult = NULL;
}

//////////////////////////////////////////////

int colaLlena_din(const t_cola *p, unsigned cantBytes)
{
    tNodo *aux = (tNodo *)malloc(sizeof(tNodo));
    void	*info = malloc(cantBytes);
    free(aux);
    free(info);
    return aux == NULL || info == NULL;
}

//////////////////////////////////////////////

int ponerEnCola_din(t_cola *p, const void *d, unsigned cantBytes)
{
    tNodo *nue = (tNodo *) malloc(sizeof(tNodo));
    if(nue == NULL || (nue->info = malloc(cantBytes)) == NULL)
    {
        free(nue);
        return 0;
    }
    memcpy(nue->info, d, cantBytes);
    nue->tamInfo = cantBytes;
    nue->sig = NULL;
    if(p->ult)
        p->ult->sig = nue;
    else
        p->pri = nue;
    p->ult = nue;
    return 1;
}

//////////////////////////////////////////////

int	verPrimeroCola_din(const t_cola *p, void *d, unsigned cantBytes)
{
    if(p->pri == NULL)
        return 0;
    memcpy(d, p->pri->info, MINIMO(cantBytes, p->pri->tamInfo));
    return 1;
}

//////////////////////////////////////////////

int	colaVacia_din(const t_cola *p)
{
    return p->pri == NULL;
}

//////////////////////////////////////////////

int	sacarDeCola_din(t_cola *p, void *d, unsigned cantBytes)
{
    tNodo *aux = p->pri;
    if(aux == NULL)
        return 0;
    p->pri = aux->sig;
    memcpy(d, aux->info, MINIMO(aux->tamInfo, cantBytes));
    free(aux->info);
    free(aux);
    if(p->pri == NULL)
        p->ult = NULL;
    return 1;
}

//////////////////////////////////////////////

void vaciarCola_din(t_cola *p)
{
    while(p->pri)
    {
        tNodo *aux = p->pri;
        p->pri = aux->sig;
        free(aux->info);
        free(aux);
    }
    p->ult = NULL;
}


///----------------------------- L I S T A   D I N A M I C A ----------------------------------


void crearlista(t_lista* l)
{
    *l=NULL;
}

//////////////////////////////////////////////

int listaVacia(const t_lista* l)
{
    return *l==NULL;
}

////////////////////////////////////////////////

//int listaLlena(const t_lista *l, unsigned cantBytes)
//{
//    tNodo *aux = (tNodo *)malloc(sizeof(tNodo));
//    void *info = malloc(cantBytes);
//    free(aux);
//    free(info);
//    return aux == NULL || info == NULL;
//}

////////////////////////////////////////////////

void vaciarLista(t_lista *l)
{
    while(*l)
    {
        tNodo *aux = *l;
        *l = aux->sig;
        free(aux->info);
        free(aux);
    }
}

////////////////////////////////////////////////

int ponerAlComienzo(t_lista *l, const void *d, unsigned cantBytes)
{
    tNodo *nue;
    if((nue = (tNodo *)malloc(sizeof(tNodo))) == NULL ||(nue->info = malloc(cantBytes)) == NULL)
    {
        free(nue);
        return 0;
    }
    memcpy(nue->info, d, cantBytes);
    nue->tamInfo = cantBytes;
    nue->sig = *l;
    *l = nue;
    return 1;
}

////////////////////////////////////////////////

int sacarPrimeroLista(t_lista *l, void *d, unsigned cantBytes)
{
    tNodo *aux = *l;
    if(aux == NULL)
        return 0;
    *l = aux->sig;
    memcpy(d, aux->info, MINIMO(cantBytes, aux->tamInfo));
    free(aux->info);
    free(aux);
    return 1;
}

////////////////////////////////////////////////

int verPrimeroLista(const t_lista *p, void *d, unsigned cantBytes)
{
    if(*p == NULL)
        return 0;
    memcpy(d, (*p)->info, MINIMO(cantBytes, (*p)->tamInfo));
    return 1;
}

////////////////////////////////////////////////

int ponerAlFinal(t_lista *l, const void *d, unsigned cantBytes)
{
    tNodo *nue;
    while(*l)
        l = &(*l)->sig;
    if((nue = (tNodo *)malloc(sizeof(tNodo))) == NULL || (nue->info = malloc(cantBytes)) == NULL)
    {
        free(nue);
        return 0;
    }
    memcpy(nue->info, d, cantBytes);
    nue->tamInfo = cantBytes;
    nue->sig = NULL;
    *l = nue;
    return 1;
}

////////////////////////////////////////////////

int sacarUltimoLista(t_lista *l, void *d, unsigned cantBytes)
{
    if(*l == NULL)
        return 0;
    while((*l)->sig)
        l = &(*l)->sig;
    memcpy(d, (*l)->info, MINIMO(cantBytes, (*l)->tamInfo));
    free((*l)->info);
    free(*l);
    *l = NULL;
    return 1;
}

////////////////////////////////////////////////

int verUltimoLista(const t_lista *l, void *d, unsigned cantBytes)
{
    if(*l == NULL)
        return 0;
    while((*l)->sig)
        l = &(*l)->sig;
    memcpy(d, (*l)->info, MINIMO(cantBytes, (*l)->tamInfo));
    return 1;
}

////////////////////////////////////////////////

int	ponerEnOrden(t_lista *p, const void *d, unsigned cantBytes,int (*comparar)(const void *, const void *),int (*acumular)(void **, unsigned *, const void *,	unsigned))
{
    tNodo	*nue;
    while(*p && comparar((*p)->info, d) < 0)
        p = &(*p)->sig;
    if(*p && comparar((*p)->info, d) == 0)
    {
        if(acumular)
            if(!acumular(&(*p)->info, &(*p)->tamInfo, d, cantBytes))
                return SIN_MEMORIA;
        return DUPLICADO;//CLA_DUP
    }
    if((nue = (tNodo	*)malloc(sizeof(tNodo))) == NULL ||(nue->info = malloc(cantBytes)) == NULL)
    {
        free(nue);
        return SIN_MEMORIA;
    }
    memcpy(nue->info, d, cantBytes);
    nue->tamInfo = cantBytes;
    nue->sig = *p;
    *p = nue;
    return TODO_OK;
}

////////////////////////////////////////////////

void ordenar(t_lista *p, int (*comparar)(const void *, const void *))
{
    t_lista	*pri = p;
    if(*p == NULL)
        return;
    while((*p)->sig)
    {
        if(comparar((*p)->info, (*p)->sig->info) > 0)
        {
            t_lista *q = pri;
            tNodo *aux = (*p)->sig;
            (*p)->sig = aux->sig;
            while(comparar((*q)->info, aux->info) > 0)
                q = &(*q)->sig;
            aux->sig = *q;
            *q = aux;
        }
        else
            p = &(*p)->sig;
    }
}

int mostrarLista(const tLista *p,void (*mostrar)(const void *, FILE *), FILE *fp)
{
    int cont=0;
    mostrar(NULL,fp);
    while(*p)
    {
        mostrar((*p)->info,fp);
        cont++;
        p=&(*p)->sig;
    }
    return cont;
}



///----------------------------- P I L A   C I R C U L A R ----------------------------------


void crear_pila_cir(tPila *p)
{
    *p=NULL;
}

////////////////////////////////////////////////

int poner_en_pila_cir(tPila*p,const void*d,unsigned cantBytes)
{
    tNodo *nue=(tNodo*)malloc(sizeof(tNodo));
    nue->info=malloc(cantBytes);
    if(nue==NULL||nue->info==NULL)
    {
        free(nue);
        return PILA_LLENA;
    }
    memcpy(nue->info,d,cantBytes);
    nue->tamInfo=cantBytes;
    if(*p==NULL)
    {
        *p=nue;
        nue->sig=nue;
    }
    else
    {
        nue->sig=(*p)->sig;
        (*p)->sig=nue;
    }
    return TODO_OK;
}

////////////////////////////////////////////////

int sacar_de_pila_cir(tPila*p,void*d,unsigned cantBytes)
{
    tNodo* elim;
    if(!*p)
        return PILA_VACIA;
    elim=(*p)->sig;
    memcpy(d,elim->info,MINIMO(cantBytes,elim->tamInfo));
    if(elim==*p)
        *p=NULL;
    else
        (*p)->sig=elim->sig;
    free(elim->info);
    free(elim);
    return TODO_OK;
}

////////////////////////////////////////////////

int ver_tope_cir(const tPila*p, void*d, unsigned cantBytes)
{
    if(!*p)
        return PILA_VACIA;
    memcpy(d,(*p)->sig->info,MINIMO(cantBytes,(*p)->sig->tamInfo));
    return TODO_OK;
}

int pila_vacia_cir(const tPila*p)
{
    return *p == NULL;
}

////////////////////////////////////////////////

//int pila_llena_cir(const tPila*p,unsigned cantBytes)
//{
//    tNodo*nue=(tNodo*)malloc(sizeof(tNodo));
//    nue->info=malloc(cantBytes);
//    free(nue->info);
//    free(nue);
//    return nue == NULL || nue->info == NULL;
//}

////////////////////////////////////////////////

void vaciar_pila_cir(tPila*p)
{
    while(*p)
    {
        tNodo* elim=(*p)->sig;
        if(elim!=*p)
            (*p)->sig=elim->sig;
        else
            *p=NULL;
        free(elim->info);
        free(elim);
    }
}


///----------------------------- C O L A   C I R C U L A R ----------------------------------


void crearCola_cir(tCola *pc)
{
    *pc = NULL;
}

////////////////////////////////////////////////

int cola_vacia_cir(const tCola *pc)
{
    return *pc == NULL;
}

////////////////////////////////////////////////

//int cola_llena_cir(const tCola *pc, unsigned tamInfo)
//{
//    tNodo *nue;
//    nue = (tNodo*) malloc(sizeof(tNodo));
//    void *info = malloc(tamInfo);
//    free(info);
//    free(nue);
//    return nue==NULL || nue->info == NULL;
//}

////////////////////////////////////////////////

int poner_en_cola_cir(tCola *pc, const void *info, unsigned tamInfo)
{
    tNodo *nue;
    if((nue = (tNodo*)malloc(sizeof(tNodo))) == NULL ||
            (nue->info = malloc(tamInfo)) == NULL)
    {
        free(nue);
        return COLA_LLENA;
    }
    memcpy(nue->info,info,tamInfo);
    nue->tamInfo = tamInfo;
    if(*pc == NULL)
        nue->sig=nue;
    else
    {
        nue->sig=(*pc)->sig;
        (*pc)->sig=nue;
    }
    *pc = nue;
    return TODO_OK;
}

////////////////////////////////////////////////

int sacar_de_cola_cir(tCola *pc, void *info, unsigned tamInfo)
{
    tNodo* elim;
    if(*pc==NULL)
        return COLA_VACIA;
    elim=(*pc)->sig;
    memcpy(info,elim->info,MINIMO(tamInfo,elim->tamInfo));
    if(elim==(*pc))
        *pc=NULL;
    else
        (*pc)->sig=elim->sig;
    free(elim->info);
    free(elim);
    return TODO_OK;
}

////////////////////////////////////////////////

void vaciar_cola_cir(tCola *pc)
{
    while(*pc)
    {
        tNodo* elim=(*pc)->sig;
        if(elim==*pc)
            *pc=NULL;
        else
            (*pc)->sig=elim->sig;
        free(elim->info);
        free(elim);
    }
}

////////////////////////////////////////////////

int ver_primero_cir(const tCola *pc, void *info, unsigned tamInfo)
{
    if(*pc==NULL)
        return COLA_VACIA;
    memcpy(info,(*pc)->sig->info,MINIMO(tamInfo,(*pc)->sig->tamInfo));
    return TODO_OK;
}


///----------------------------- L I S T A   D O B L E ----------------------------------


void crearListaDoble(tListaDoble *l)
{
    *l = NULL;
}

////////////////////////////////////////////////

int listaDobleVacia(const tListaDoble *l)
{
    return *l == NULL;
}

////////////////////////////////////////////////

int listaDobleLlena(const tListaDoble *l, unsigned tamElem)
{
    tNodoDoble *aux = (tNodoDoble*)malloc(sizeof(tNodoDoble));
    void *info = malloc(tamElem);
    free(aux);
    free(info);
    return aux == NULL || info == NULL;
}

////////////////////////////////////////////////

void vaciarListaDoble(tListaDoble *l)
{
    while((*l)->ant)
        *l = (*l)->ant;
    while(*l)
    {
        tNodoDoble *aux = *l;
        *l = aux->sig;
        free(aux->pInfo);
        free(aux);
    }
}

////////////////////////////////////////////////

void vaciarListaDobleYMostrar(tListaDoble *l, tMostrar mostrar)
{
    int i=1;
    while((*l)->ant)
        *l = (*l)->ant;
    while(*l)
    {
        tNodoDoble *aux = *l;
        *l = aux->sig;
        printf("Nodo %d: ",i);
        mostrar(aux->pInfo);
        free(aux->pInfo);
        free(aux);
        i++;
    }
}

////////////////////////////////////////////////

int insertarPrincipioListaDoble(tListaDoble *l, void *pInfo, unsigned tamElem)
{
    tNodoDoble *nue = (tNodoDoble*)malloc(sizeof(tNodoDoble));
    tNodoDoble *act = *l;
    if(act)
    {
        while(act->ant)
        act = act->ant;
    }
    if(!nue)
    {
        printf("Sin memoria.\n");
        return SIN_MEMORIA;
    }
    nue->pInfo = malloc(tamElem);
    if(!nue->pInfo)
    {
        free(nue);
        printf("Sin memoria.\n");
        return SIN_MEMORIA;
    }
    memcpy(nue->pInfo,pInfo,tamElem);
    nue->ant = NULL;
    nue->sig = act;
    nue->tamElem = tamElem;
    if(act)
        act->ant = nue;
    else
        *l = nue;
    return VERDADERO;
}

////////////////////////////////////////////////

int insertarFinalListaDoble(tListaDoble *l, void *pInfo, unsigned tamElem)
{
    tNodoDoble *nue = (tNodoDoble*)malloc(sizeof(tNodoDoble));
    tNodoDoble *act = *l;
    if(act)
    {
        while(act->sig)
        act = act->sig;
    }
    if(!nue)
    {
        printf("Sin memoria.\n");
        return SIN_MEMORIA;
    }
    nue->pInfo = malloc(tamElem);
    if(!nue->pInfo)
    {
        printf("Sin memoria.\n");
        free(nue);
        return SIN_MEMORIA;
    }
    memcpy(nue->pInfo,pInfo,tamElem);
    nue->tamElem = tamElem;
    nue->ant = act;
    nue->sig = NULL;
    if(act)
        act->sig = nue;
    else
        *l = nue;
    return VERDADERO;

}

////////////////////////////////////////////////

int insertarOrdenadoListaDoble(tListaDoble *l, void *pInfo, unsigned tamElem, tCmp comparar)
{
    tNodoDoble *act,*nueant,*nuesig,*nue;
    act=(*l);
    if(act)
    {
        while(act->ant && comparar(pInfo,act->pInfo)<0)
            act=act->ant;
        while(act->sig && comparar(pInfo,act->pInfo)>0)
            act=act->sig;
        if(comparar(pInfo,act->pInfo)>0)
        {
            nueant=act;
            nuesig=act->sig;
        }
        else
        {
            nueant=act->ant;
            nuesig=act;
        }
    }
    else
    {
        nueant=NULL;
        nuesig=NULL;
    }
    nue=(tNodoDoble*)malloc(sizeof(tNodoDoble));
    if(!nue)
    {
        printf("Sin memoria.\n");
        return FALSO;
    }
    nue->pInfo = malloc(tamElem);
    if(!nue->pInfo)
    {
        free(nue);
        printf("Sin memoria.\n");
        return FALSO;
    }
    memcpy(nue->pInfo,pInfo,tamElem);
    nue->tamElem = tamElem;
    nue->ant=nueant;
    nue->sig=nuesig;
    if(nueant) nueant->sig=nue;
    if(nuesig) nuesig->ant=nue;
    (*l)=nue;
    return VERDADERO;
}

////////////////////////////////////////////////

int verPrimeroListaDoble(tListaDoble *l, void *pInfo, unsigned tamElem)
{
    if(!*l)
        return FALSO;
    while((*l)->ant)
        *l = (*l)->ant;
    memcpy(pInfo,(*l)->pInfo,MINIMO(tamElem,(*l)->tamElem));
    return VERDADERO;
}

////////////////////////////////////////////////

int verUltimoListaDoble(tListaDoble *l, void *pInfo, unsigned tamElem)
{
    if(!*l)
        return FALSO;
    while((*l)->sig)
        *l = (*l)->sig;
    memcpy(pInfo,(*l)->pInfo,MINIMO(tamElem,(*l)->tamElem));
    return VERDADERO;
}

////////////////////////////////////////////////

int sacarPrimeroListaDoble(tListaDoble *l, void *pInfo, unsigned tamElem)
{
    if(!*l)
        return FALSO;
    tNodoDoble *elim = *l, *elimSig;
    while(elim->ant)
        elim = elim->ant;
    elimSig = elim->sig;
    if(elim == *l)
        *l = elimSig;
    if(elimSig)
            elimSig->ant = NULL;
    memcpy(pInfo,elim->pInfo,MINIMO(tamElem,elim->tamElem));
    free(elim->pInfo);
    free(elim);
    return VERDADERO;
}

////////////////////////////////////////////////

int sacarUltimoListaDoble(tListaDoble *l, void *pInfo, unsigned tamElem)
{
    if(!*l)
        return FALSO;
    tNodoDoble *elim = *l, *elimAnt;
    while(elim->sig)
        elim = elim->sig;
    elimAnt = elim->ant;
    if(elim == *l)
        *l = elimAnt;
    if(elimAnt)
            elimAnt->sig = NULL;
    memcpy(pInfo,elim->pInfo,MINIMO(tamElem,elim->tamElem));
    free(elim->pInfo);
    free(elim);
    return VERDADERO;
}

////////////////////////////////////////////////

int buscarYSacarListaDoble(tListaDoble *l, void *pInfo, unsigned tamElem, tCmp comparar)
{
    tNodoDoble *act = *l,*ant,*aux;
    if(act)
    {
        while(act->sig && comparar(pInfo, act->pInfo) > 0)
            act = act->sig;
        while(act->ant&& comparar(pInfo, act->pInfo) < 0)
            act = act->ant;
        if(!comparar(pInfo, act->pInfo))
        {
            aux = act;
            memcpy(pInfo,aux->pInfo,MINIMO(tamElem,aux->tamElem));
            ant = act->ant;
            act = act->sig;
            if(ant)
                ant->sig = act;
            if(act)
                act->ant = ant;
            if((act && !ant) || (act && ant))
                *l = act;
            else
            {
                if((!act && ant))
                    *l = ant;
                else
                    *l = NULL;
            }
            free(aux);
            return VERDADERO;
        }
    }
    return FALSO;
}

////////////////////////////////////////////////

void mostrarListaDoble(tListaDoble *l, tMostrar mostrar)
{
    while((*l)->ant)
        *l = (*l)->ant;
    while(*l)
    {
        mostrar((*l)->pInfo);
        l = &(*l)->sig;
    }
}


///---------------------------------- A R B O L --------------------------------------


void crearArbolBinBusq(tArbolBinBusq *p)
{
    *p = NULL;
}

////////////////////////////////////////////////

int	insertarArbolBinBusq(tArbolBinBusq *p, const void *d, unsigned tam, int (*cmp)(const void *, const void *))
{
    tNodoArbol *nue;
    int	rc;

    while(*p)
    {
        if((rc = cmp(d, (*p)->info)) < 0)
            p = &(*p)->izq;
        else if (rc > 0)
            p = &(*p)->der;
        else
            return DUPLICADO;
    }
    if(!reservarMemoriaNodo(nue, sizeof(tNodoArbol), nue->info, tam))
        return SIN_MEMORIA;
    nue->tamInfo = tam;
    memcpy(nue->info, d, tam);
    nue->der = nue->izq = NULL;
    *p = nue;
    return TODO_OK;
}

////////////////////////////////////////////////

int	insertarRecArbolBinBusq(tArbolBinBusq *p, const void *d, unsigned tam,int (*cmp)(const void *, const void *))
{
    tNodoArbol *nue;
    int	rc;

    if(*p)
    {
        if((rc = cmp(d, (*p)->info)) < 0)
            return insertarRecArbolBinBusq(&(*p)->izq, d, tam, cmp);
        if (rc > 0)
            return insertarRecArbolBinBusq(&(*p)->der, d, tam, cmp);
        return DUPLICADO;
    }
    if(!reservarMemoriaNodo(nue, sizeof(tNodoArbol), nue->info, tam))
        return SIN_MEMORIA;
    nue->tamInfo = tam;
    memcpy(nue->info, d, tam);
    nue->der = NULL;
    nue->izq = NULL;
    *p = nue;
    return TODO_OK;
}

////////////////////////////////////////////////

void recorrerEnOrdenRecArbolBinBusq(const tArbolBinBusq * p, unsigned n, void * params,void (*accion)(void *, unsigned, unsigned, void*))
{
    if(!*p)
        return;
    recorrerEnOrdenRecArbolBinBusq(&(*p)->izq, n+1, params, accion);
    accion((*p)->info, (*p)->tamInfo, n, params);
    recorrerEnOrdenRecArbolBinBusq(&(*p)->der, n+1, params, accion);
}

////////////////////////////////////////////////

void recorrerEnOrdenArbolBinBusq(const tArbolBinBusq * p, void * params,void (*accion)(void *, unsigned, unsigned, void *))
{
    recorrerEnOrdenRecArbolBinBusq(p, 0, params, accion);
}

////////////////////////////////////////////////

void recorrerEnOrdenInversoRecArbolBinBusq(const tArbolBinBusq * p, unsigned n, void*params,void (*accion)(void *, unsigned, unsigned, void *))
{
    if(!*p)
        return;
    recorrerEnOrdenInversoRecArbolBinBusq(&(*p)->der, n+1, params, accion);
    accion((*p)->info, (*p)->tamInfo, n, params);
    recorrerEnOrdenInversoRecArbolBinBusq(&(*p)->izq, n+1, params, accion);
}

////////////////////////////////////////////////

void recorrerEnOrdenInversoArbolBinBusq(const tArbolBinBusq * p, void * params,void (*accion)(void *, unsigned, unsigned, void *))
{
    recorrerEnOrdenInversoRecArbolBinBusq(p, 0, params, accion);
}

////////////////////////////////////////////////

void recorrerPreOrdenRecArbolBinBusq(const tArbolBinBusq * p, unsigned n, void * params,void (*accion)(void *, unsigned, unsigned, void*))
{
    if(!*p)
        return;
    accion((*p)->info, (*p)->tamInfo, n, params);
    recorrerPreOrdenRecArbolBinBusq(&(*p)->izq, n+1, params, accion);
    recorrerPreOrdenRecArbolBinBusq(&(*p)->der, n+1, params, accion);
}

////////////////////////////////////////////////

void recorrerPreOrdenArbolBinBusq(const tArbolBinBusq * p, void * params,void (*accion)(void *, unsigned, unsigned, void*))
{
    recorrerPreOrdenRecArbolBinBusq(p, 0, params, accion);
}

////////////////////////////////////////////////

void recorrerPosOrdenRecArbolBinBusq(const tArbolBinBusq * p, unsigned n,void * params, void (*accion)(void *, unsigned, unsigned, void *))
{
    if(!*p)
        return;
    recorrerPosOrdenRecArbolBinBusq(&(*p)->izq, n+1, params, accion);
    recorrerPosOrdenRecArbolBinBusq(&(*p)->der, n+1, params, accion);
    accion((*p)->info, (*p)->tamInfo, n, params);
}

////////////////////////////////////////////////

void recorrerPosOrdenArbolBinBusq(const tArbolBinBusq * p, void * params,void (*accion)(void *, unsigned, unsigned, void*))
{
    recorrerPosOrdenRecArbolBinBusq(p, 0, params, accion);
}

////////////////////////////////////////////////

void recorrerEnOrdenSimpleArbolBinBusq(const tArbolBinBusq * p,void * params, void (*accion)(void *,unsigned, void *))
{
    if(!*p)
        return;
    recorrerEnOrdenSimpleArbolBinBusq(&(*p)->izq, params, accion);
    accion((*p)->info, (*p)->tamInfo, params);
    recorrerEnOrdenSimpleArbolBinBusq(&(*p)->der, params, accion);
}

////////////////////////////////////////////////

void recorrerPreOrdenSimpleArbolBinBusq(const tArbolBinBusq * p,void * params, void (*accion)(void *,unsigned, void *))
{
    if(!*p)
        return;
    accion((*p)->info, (*p)->tamInfo, params);
    recorrerPreOrdenSimpleArbolBinBusq(&(*p)->izq, params, accion);
    recorrerPreOrdenSimpleArbolBinBusq(&(*p)->der, params, accion);
}

////////////////////////////////////////////////

void recorrerPosOrdenSimpleArbolBinBusq(const tArbolBinBusq * p,void * params, void (*accion)(void *,unsigned, void *))
{
    if(!*p)
        return;
    recorrerPosOrdenSimpleArbolBinBusq(&(*p)->izq, params, accion);
    recorrerPosOrdenSimpleArbolBinBusq(&(*p)->der, params, accion);
    accion((*p)->info, (*p)->tamInfo, params);
}

////////////////////////////////////////////////

int	eliminarRaizArbolBinBusq(tArbolBinBusq * p)
{
    tNodoArbol ** remp,
               * elim;
    if(!*p)
        return 0; ///ARBOL_VACIO
    free((*p)->info);
    if (!(*p)->izq && !(*p)->der)
    {
        free(*p);
        *p = NULL;
        return 1; ///OK
    }

    remp = alturaArbolBin(&(*p)->izq)>alturaArbolBin(&(*p)->der)?
           mayorNodoArbolBinBusq(&(*p)->izq):
           menorNodoArbolBinBusq(&(*p)->der);
    elim = *remp;
    (*p)->info = elim->info;
    (*p)->tamInfo = elim->tamInfo;
    *remp = elim->izq ? elim->izq : elim->der;
    free(elim);
    return 1; ///OK
}

////////////////////////////////////////////////

int eliminarElemArbolBinBusq(tArbolBinBusq * p, void * d, unsigned tam,
                             int (*cmp)(const void*, const void *))
{
    if(!(p = buscarNodoArbolBinBusq(p,d,cmp)))
        return 0; ///NO_EXISTE
    memcpy(d, (*p)->info, MINIMO(tam, (*p)->tamInfo));
    return eliminarRaizArbolBinBusq(p);
}

////////////////////////////////////////////////

int buscarElemArbolBinBusq(const tArbolBinBusq *p, void *d, unsigned tam,int (*cmp)(const void *, const void *))
{
    if(!(p = buscarNodoArbolBinBusq(p,d,cmp)))
        return 0; ///NO_EXISTE
    memcpy(d, (*p)->info, MINIMO(tam, (*p)->tamInfo));
    return 1;
}

////////////////////////////////////////////////

unsigned leerDesdeArchivoBin(void ** d, void * pf, unsigned pos, void * params)
{
    unsigned tam = *((int*)params);
    *d = malloc(tam);
    if(!*d)
        return 0;
    fseek((FILE*)pf, pos*tam, SEEK_SET);
    return fread(*d, tam, 1, (FILE*)pf);
}

////////////////////////////////////////////////

int cargarDesdeDatosOrdenadosRec(tArbolBinBusq * p, void * ds,unsigned (*leer)(void **, void *, unsigned, void * params),int li, int ls, void * params)
{
    int m = (li+ls)/2,
        r;
    if (li>ls)
        return TODO_OK;
    (*p) = (tNodoArbol*) malloc(sizeof(tNodoArbol));

    if	(!*p || !((*p)->tamInfo = leer(&(*p)->info, ds, m, params)))
    {
        free(*p);
        return SIN_MEMORIA;
    }
    (*p)->izq = (*p)->der = NULL;
    if((r=cargarDesdeDatosOrdenadosRec(&(*p)->izq, ds, leer, li, m-1, params))!= TODO_OK)
        return r;
    return cargarDesdeDatosOrdenadosRec(&(*p)->der, ds, leer, m+1, ls, params);
}

////////////////////////////////////////////////

int cargarArchivoBinOrdenadoAbiertoArbolBinBusq(tArbolBinBusq * p, FILE * pf,unsigned tamInfo)
{
    int cantReg;
    if(*p || !pf)
        return 0;
    fseek(pf, 0L, SEEK_END);
    cantReg = ftell(pf)/tamInfo;
    return cargarDesdeDatosOrdenadosRec(p, pf, leerDesdeArchivoBin, 0, cantReg-1, & tamInfo);
}

////////////////////////////////////////////////

int cargarArchivoBinOrdenadoArbolBinBusq(tArbolBinBusq * p, const char * path,unsigned tamInfo)
{
    int cantReg,r;
    FILE * pf;
    if(*p)
        return SIN_INICIALIZAR;
    if(!(pf= fopen(path, "rb")))
        return ERROR_ARCH;
    fseek(pf, 0L, SEEK_END);
    cantReg = ftell(pf)/tamInfo;
    r = cargarDesdeDatosOrdenadosRec(p, pf, leerDesdeArchivoBin, 0, cantReg-1, & tamInfo);
    fclose(pf);
    return r;
}

////////////////////////////////////////////////

int cargarDesdeDatosOrdenadosArbolBinBusq(tArbolBinBusq * p, void * ds, unsigned cantReg,unsigned (*leer)(void **, void *, unsigned, void *params),void * params)
{
    if(*p || !ds)
        return 0;
    return cargarDesdeDatosOrdenadosRec(p, ds, leer, 0, cantReg-1, params);
}

////////////////////////////////////////////////

tNodoArbol ** buscarNodoArbolBinBusq(const tArbolBinBusq * p, const void * d,int (*cmp)(const void*, const void *))
{
    int rc;
    while(*p && (rc=cmp(d, (*p)->info)))
    {
        if(rc<0)
            p = &(*p)->izq;
        else
            p = &(*p)->der;
    }
    if(!*p)
        return NULL;
    return (tNodoArbol **)p;
}

////////////////////////////////////////////////

tNodoArbol ** buscarRecNodoArbolBinBusq(const tArbolBinBusq * p, const void * d,int (*cmp)(const void*, const void *))
{
    int rc;
    if(!*p)
        return NULL;
    if(*p && (rc=cmp(d, (*p)->info)))
    {
        if(rc<0)
            return buscarRecNodoArbolBinBusq(&(*p)->izq, d, cmp);
        return buscarRecNodoArbolBinBusq(&(*p)->der, d, cmp);
    }
    return (tNodoArbol **) p;
}

////////////////////////////////////////////////

tNodoArbol ** mayorNodoArbolBinBusq(const tArbolBinBusq	* p)
{
    if(!*p)
        return NULL;
    while((*p)->der)
        p = &(*p)->der;
    return (tNodoArbol **) p;
}

////////////////////////////////////////////////

tNodoArbol ** menorNodoArbolBinBusq(const tArbolBinBusq	* p)
{
    if(!*p)
        return NULL;
    while((*p)->izq)
        p = &(*p)->izq;
    return (tNodoArbol **) p;
}

////////////////////////////////////////////////

tNodoArbol ** mayorRecNodoArbolBinBusq(const tArbolBinBusq *p)
{
    if(!*p)
        return NULL;
    if(!(*p)->der)
        return (tNodoArbol **) p;
    return mayorRecNodoArbolBinBusq(&(*p)->der);
}

////////////////////////////////////////////////

tNodoArbol ** menorRecNodoArbolBinBusq(const tArbolBinBusq *p)
{
    if(!*p)
        return NULL;
    if(!(*p)->izq)
        return (tNodoArbol **) p;
    return menorRecNodoArbolBinBusq(&(*p)->izq);
}

////////////////////////////////////////////////

int mayorElemNoClaveArbolBinBusq(const tArbolBinBusq *p, void *d, unsigned tam,int (*cmp)(const void *, const void *))
{
    const tArbolBinBusq * mayor = p;
    if (!*p)
        return 0;
    mayor = mayorNodoNoClaveArbolBinBusq(&(*p)->izq, mayor, cmp);
    mayor = mayorNodoNoClaveArbolBinBusq(&(*p)->der, mayor, cmp);
    memcpy(d, (*mayor)->info, MINIMO(tam, (*mayor)->tamInfo));
    return 1;
}

////////////////////////////////////////////////

const tArbolBinBusq * mayorNodoNoClaveArbolBinBusq(const tArbolBinBusq *p, const tArbolBinBusq *mayor,int (*cmp)(const void *, const void *))
{
    if (!*p)
        return mayor;
    if (cmp((*p)->info, (*mayor)->info)>0)
        mayor = p;
    mayor = mayorNodoNoClaveArbolBinBusq(&(*p)->izq, mayor, cmp);
    mayor = mayorNodoNoClaveArbolBinBusq(&(*p)->der, mayor, cmp);
    return mayor;
}

////////////////////////////////////////////////

int menorElemNoClaveArbolBinBusq(const tArbolBinBusq *p, void *d, unsigned tam,
                                 int (*cmp)(const void *, const void *))
{
    const tArbolBinBusq * menor = p;
    if (!*p)
        return 0;
    menor = menorNodoNoClaveArbolBinBusq(&(*p)->izq, menor, cmp);
    menor = menorNodoNoClaveArbolBinBusq(&(*p)->der, menor, cmp);
    memcpy(d, (*menor)->info, MINIMO(tam, (*menor)->tamInfo));
    return 1;
}

////////////////////////////////////////////////

const tArbolBinBusq * menorNodoNoClaveArbolBinBusq(const tArbolBinBusq *p, const tArbolBinBusq *menor,int (*cmp)(const void *, const void *))
{
    if (!*p)
        return menor;
    if (cmp((*p)->info, (*menor)->info)<0)
        menor = p;
    menor = menorNodoNoClaveArbolBinBusq(&(*p)->izq, menor, cmp);
    menor = menorNodoNoClaveArbolBinBusq(&(*p)->der, menor, cmp);
    return menor;
}

////////////////////////////////////////////////

int buscarElemNoClaveArbolBinBusq(const tArbolBinBusq *p, void *d, unsigned tam,int (*cmp)(const void *, const void *))
{
    const tArbolBinBusq * busq = NULL;
    if (!*p)
        return 0;
    if(cmp((*p)->info, d)==0)
        busq = p;
    else if ((busq = buscarNodoNoClaveArbolBinBusq(&(*p)->izq, d, cmp))==NULL)
    {
        busq = buscarNodoNoClaveArbolBinBusq(&(*p)->der, d, cmp);
    }
    if (busq==NULL)
        return 0;
    memcpy(d, (*busq)->info, MINIMO(tam, (*busq)->tamInfo));
    return 1;
}

////////////////////////////////////////////////

const tArbolBinBusq * buscarNodoNoClaveArbolBinBusq(const tArbolBinBusq *p, const void *d,int (*cmp)(const void *, const void *))
{
    const tArbolBinBusq * busq = NULL;
    if (!*p)
        return NULL;
    if (cmp((*p)->info, d)<0)
        return p;
    if((busq = buscarNodoNoClaveArbolBinBusq(&(*p)->izq, busq, cmp)))
        return busq;
    return buscarNodoNoClaveArbolBinBusq(&(*p)->der, busq, cmp);
}

////////////////////////////////////////////////

unsigned alturaArbolBin(const tArbolBinBusq * p)
{
    int hi,
        hd;
    if(!*p)
        return 0;
    hi= alturaArbolBin(&(*p)->izq);
    hd= alturaArbolBin(&(*p)->der);
    return (hi>hd ? hi : hd) +1;
}

////////////////////////////////////////////////

unsigned cantNodosArbolBin(const tArbolBinBusq * p)
{
    if(!*p)
        return 0;
    return cantNodosArbolBin(&(*p)->izq)
           + cantNodosArbolBin(&(*p)->der)
           + 1;
}

////////////////////////////////////////////////

int	mayorElemArbolBinBusq(const tArbolBinBusq * p, void	* d,	unsigned	tam)
{
    if(!(p = mayorNodoArbolBinBusq(p)))
        return 0;
    memcpy(d, (*p)->info, MINIMO(tam, (*p)->tamInfo));
    return 1;
}

////////////////////////////////////////////////

int	menorElemArbolBinBusq(const tArbolBinBusq * p, void	* d,	unsigned	tam)
{
    if(!(p = menorNodoArbolBinBusq(p)))
        return 0;
    memcpy(d, (*p)->info, MINIMO(tam, (*p)->tamInfo));
    return 1;
}

////////////////////////////////////////////////

unsigned cantNodosHastaNivelArbolBin(const tArbolBinBusq *p,	int n)
{
    if(!*p)
        return 0;
    if(n==0)
        return 1;
    return cantNodosHastaNivelArbolBin(&(*p)->izq, n-1)
           + cantNodosHastaNivelArbolBin(&(*p)->der, n-1)
           + 1;
}

////////////////////////////////////////////////

int	esCompletoHastaNivelArbolBin(const tArbolBinBusq *p, int n)
{
    if(!*p)
        return n<0;
    if(n==0)
        return 1;
    return esCompletoHastaNivelArbolBin(&(*p)->izq,n-1) && esCompletoHastaNivelArbolBin(&(*p)->der,n-1);
}

////////////////////////////////////////////////

int	esCompletoArbolBin(const tArbolBinBusq *p)
{
    return esCompletoHastaNivelArbolBin(p,alturaArbolBin(p)-1);
}

////////////////////////////////////////////////

int	esBalanceadoArbolBin(const tArbolBinBusq *p)
{
    return esCompletoHastaNivelArbolBin(p,alturaArbolBin(p)-2);
}

////////////////////////////////////////////////

int	esAVLArbolBin(const tArbolBinBusq *p)
{
    int hi,
        hd;
    if(!*p)
        return 1;
    hi = alturaArbolBin(&(*p)->izq);
    hd = alturaArbolBin(&(*p)->der);
    if (abs(hi-hd)>1)
        return 0;
    return esAVLArbolBin(&(*p)->izq) &&
           esAVLArbolBin(&(*p)->der);
}

////////////////////////////////////////////////

int	esCompleto2ArbolBin(const tArbolBinBusq *p)
{
    int h = alturaArbolBin(p);
    return cantNodosArbolBin(p) == pow(2,h)-1;
}

////////////////////////////////////////////////

int	esBalanceado2ArbolBin(const tArbolBinBusq *p)
{
    int h = alturaArbolBin(p);
    return cantNodosHastaNivelArbolBin(p, h-2) == pow(2,h-1)-1;
}

////////////////////////////////////////////////

int	esAVL2CalculoArbolBin(const tArbolBinBusq *p)
{
    int hi,
        hd;
    if(!*p)
        return 0;
    hi= esAVL2CalculoArbolBin(&(*p)->izq);
    hd= esAVL2CalculoArbolBin(&(*p)->der);
    if(hi<0 || hd<0 || abs(hi-hd)>1)
        return -1;
    return (hi>hd ? hi : hd) +1;
}

////////////////////////////////////////////////

int	esAVL2ArbolBin(const tArbolBinBusq *p)
{
    return esAVL2CalculoArbolBin(p)>=0;
}
