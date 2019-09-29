#include <stdio.h>

int main(int argc, char *argv[]){
    
    if(argc!=2){
        printf("Usage : ./dump-parser [dumpname.txt]\n");
        return 0;
    }
    
    FILE *dump;
    char const* const fileName = argv[1];
    char line[256];
    int counter = 0;
    char firstChar[50000];

    if((dump = fopen(fileName,"r")) == NULL){
        printf("dump-parser: Could not open %s\n", *argv);
    } else {
        while( fgets(line, sizeof(line), dump) ){
            firstChar[counter] = line[0];
            printf("%d %s", counter++, line);
        }
        for(int i=0; i<(*firstChar/sizeof(*firstChar)); i++){
            printf("%c", firstChar[i]);
        }
        printf("\n");
    }
    fclose(dump);
    return 0;
}