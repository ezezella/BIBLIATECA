#include "Funciones.h"

int main()
{
    printf("\
    Hola Gente:\n\
        Esta biblioteca es para que tengamos todos un FUNCIONES.c y FUNCIONES.h bien completo.\n\
        por el momento solo se incluira todo lo del primer parcial ya que con el segundo se volveria muy largo!\n\
        \n\
        Consejo: para buscar algo en Funciones.c, escriban en buscador incremental la primer letra\n\
        de la tematica y espacio.\n\
        Es decir, si desean buscar la seccion FECHA, escriban en el buscador incremental \"f \" \n\n\n\n");
    return 0;
}




//int main() ///MATRICES
//{
//    int opcion;
//    int mat[FIL][COL]= {{00,01,02,03,04,05,06},
//                        {10,11,12,13,14,15,16},
//                        {20,21,22,23,24,25,26},
//                        {30,31,32,33,34,35,36},
//                        {40,41,42,43,44,45,46},
//                        {50,51,52,53,54,55,56},
//                        {60,61,62,63,64,65,66}};
//
//    int mati[FIL][COL]= {{1,0,0,0,0},
//                        {0,1,0,0,0},
//                        {0,0,1,0,0},
//                        {0,0,0,1,0},
//                        {0,0,0,0,1}};
//
//    int matsim[FIL][COL]= {{1,0,0,9,0},
//                           {0,1,0,7,9},
//                           {0,0,1,0,0},
//                           {9,7,0,1,0},
//                           {0,9,0,0,1}};
//
//    int matnc[2][COL]={{1,2,3,4,5},
//                       {6,7,8,9,10}};
//    do
//    {
//        opcion=menu_matrices();
//        switch(opcion)
//        {
//        case 1:
//            diagonalprincipal(mat);
//            break;
//
//        ////////////////////////
//
//        case 2:
//            diagonalsecundaria(mat);
//            break;
//
//        ///////////////////////
//
//        case 3:
//            triangulosuperiorcd(mat);
//            break;
//
//        ////////////////////////
//
//        case 4:
//            triangulosuperiorsd(mat);
//            break;
//
//        ////////////////////////
//
//        case 5:
//            trianguloinferiorcd(mat);
//            break;
//
//        ////////////////////////
//
//        case 6:
//            trianguloinferiorsd(mat);
//            break;
//
//        ////////////////////////
//
//        case 7:
//            trianinfdiagsecun(mat);
//            break;
//
//        ////////////////////////
//
//        case 8:
//            triansupdiagsecun(mat);
//            break;
//
//        ////////////////////////
//
//        case 9:
//            printf("la suma del triangulo superior (sin diagonal) es: %d",suma_tri_sup(mat));
//            break;
//
//         ////////////////////////
//
//        case 10:
//            printf("la traza de la matriz es: %d",traza(mat));
//            break;
//
//         ////////////////////////
//
//        case 11:
//            if(matrizdiagonal(mati))
//                printf("Es matriz diagonal");
//            else
//                printf("No es matriz diagonal");
//            break;
//
//         ////////////////////////
//
//        case 12:
//            if(matrizidentidad(mat))
//                printf("Es matriz identidad");
//            else
//                printf("No es matriz identidad");
//            break;
//
//         ////////////////////////
//
//        case 13:
//            if(essimetrica(mati))
//                printf("Es simetrica");
//            else
//                printf("No es simetrica");
//            break;
//
//         ////////////////////////
//
//        case 14:
//            printf("Antes de transponer:\n");
//            mostrarmatriz(mat);
//            if(escuadrada(matnc))
//            {
//                printf("\nDespues de transponer\n");
//                transponer(mat);
//                mostrarmatriz(mat);
//            }
//            else printf("No es cuadrada");
//            break;
//
//         ////////////////////////
//
//        case 15:
//            break;
//
//         ////////////////////////
//
//        case 16:
//            break;
//
//         ////////////////////////
//
//        case 17:
//            break;
//
//         ////////////////////////
//
//        case 18:
//            break;
//
//         ////////////////////////
//
//        case 0:
//            return 0;
//            break;
//        }
//        printf("\n\nDesea seguir (1=si, 0=no):");
//        fflush(stdin);
//        scanf("%d",&opcion);
//        fflush(stdin);
//    }
//    while(opcion!=0);
//    return 0;
//}


//int main() ///STRING
//{
//    char cad []={"hola bigote, como andas . bigote de leche"};
//    char subcad[]={"bigote"};
//    printf("Se repite %d veces\n\n",vecesRepite(subcad,cad));
////    const char cad2[]={"ezEquIeL AyrTon zeLLa"};
//    char cad2[100]={
//    "holA,cOmo andAs?bieN.t$oDo pa$ncho man!  la  verdad Que JoYa,que CarA que Esta lA CeboLLa,$50   "};
//    normalizar_texto(cad2);
//    printf("-%s-\n\n",cad2);
//    puts(cad2);
//    return 0;
//}

//int main(int cantarch, char* nombarch[]) ///MERGE
//{
////    if(generarArchivoBin(nombarch[ALUMNO]))
////    {
////        puts("No abrio el archivo, ERROR");
////        return 0;
////    }
////    if(generarArchivoBin(nombarch[EMPLEADOS]))
////    {
////        puts("No abrio el archivo, ERROR");
////        return 0;
////    }
//    if(AumentaSueldos(nombarch[ALUMNO],nombarch[EMPLEADOS])!=0)
//    {
//        puts("Ocurrio un error y no se pudo aumentar");
//        return 1;
//    }
//
//    mostrarArchivosBin(nombarch[EMPLEADOS],sizeof(Empleado));
////    mostrarArchivosBin(nombarch[ALUMNO],sizeof(Alumno));
//    return 0;
//}

/*
Nombarch[1] -> empleados.bin
nombarch[2] -> alumnos.bin

#define EMPLEADOS 1
#define ALUMNO 2

empleados.bin -> 1
alumno.bin -> 2

*/


//int main(int cantarch, char* nombarch[]) ///OFUSCADO
//{
//    ofuscado(nombarch[OFUSCADO]);
//    return 0;
//}
