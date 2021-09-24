#include <stdio.h>
#include <stdlib.h>
#include <time.h>
typedef int BOOL;
#define TRUE 1
#define FALSE 0

int length=8;
char  srcpwd[]="1ijklmnuvwxyz0345rstJKQRST2aNOPhUVWXYbcd6789opqefgLMZ";

char vowels[]="aeiowxyuAEIKQRST2aO92U123";
BOOL ifVowels(char c){
    for(int i=0;i<10;i++){
        if(c==vowels[i]) return TRUE;
    }
    return FALSE;
}

char * reverseVowels(char * s){
    int length=strlen(s);
    int current=0;
    char * vowels_list = (char *) malloc(length);
    int * vowels_posi = (int *) malloc(length*sizeof(int));
    for(int i=0;i<length;i++){
        if(ifVowels(s[i])){
            vowels_list[current]=s[i];
            vowels_posi[current]=i;
            current++;
        }
    }

    for(int i=0;i<current;i++){
        s[vowels_posi[i]]=vowels_list[current-i-1];
    }

    return s;
}

char * GenerateOne(int length){
    int i,random;
    char *Password = (char *)malloc(length + 1);

    srand((unsigned)time(0));
    for(i = 0;i < length;i++)
    {
        random = rand()%(strlen(srcpwd));
        *(Password + i) = srcpwd[random];
    }
        
    srand((unsigned)time(NULL));
    random = rand()%length;
    *(Password + random) = srcpwd[rand()%(strlen(srcpwd))];
    random = rand()%length;
    *(Password + random) = srcpwd[rand()%(strlen(srcpwd))];
    
    *(Password + i)= '\0';
    return reverseVowels(Password);

}

int main()
{
    while (1) {
        printf("length?>");
        scanf("%d",&length);
        if(length==0) length=8;
        printf("\n%s\n",GenerateOne(length));
        scanf("%*[^\n]"); scanf("%*c");
        char YN;
        printf("Generate next? Y/N >");
        scanf("%c",&YN);
        if (YN=='n'||YN=='N') {
            return 0;
        }
        scanf("%*[^\n]"); scanf("%*c");
    }
}

//
