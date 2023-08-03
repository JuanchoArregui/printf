#include <stdio.h>
#include <stdlib.h>



typedef struct s_print {
    char *print;
    int length;
} t_print;

void third_function(t_print **struc) {
    // Hacer algo con la estructura
    (*struc)->length = 1142;
    (*struc)->print = "kkdevaka";
}

void internal_function(t_print **struc) {
    // Hacer algo con la estructura
    (*struc)->length = 42;
    third_function(struc);
}

void external_function(t_print **struc) {
    (*struc)->print = "hola caracola";
    internal_function(struc);
}

int main() {
    t_print *struc = (t_print *)malloc(sizeof(t_print));

    // Inicializar la estructura o hacer lo que necesites
    struc->print = "Hola, mundo";
    struc->length = 0;

    external_function(&struc);

    // Usar la estructura modificada por la función interna
    printf("Length: %d\n", struc->length);
    printf("Length: %s\n", struc->print);

    // Liberar la memoria cuando ya no la necesites
    free(struc);

    return 0;
}