#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>





//function for finding the number of words,sentences,letters
void letterwordsentence(char text[]){
int words=1,sentences=0,letters=0,i=0;

    while(text[i]!='\0'){
        if(text[i] == '!'|| text[i] == '.'|| text[i] == '?'|| text[i] == ':'|| text[i] == ';'||text[i] ==' ' ||text[i] == ','){
            letters--;
            if(text[i] == '!'|| text[i] == '.'|| text[i] == '?'|| text[i] == ':'){
                sentences++;
                words++;
                }
            if(text[i] ==' ' ||text[i] == ',' ){
                words++;
                }
            }
            i++;
        }
        letters+=i;
        printf("\nnumber of letters= %d   number of words= %d   number of sentences= %d ",letters,words,sentences);
    }


    //Function for finding words in text
void wordsearch(char text[]){
    char word[25];
    printf("Enter the word you want to search\n");
    scanf("%s",word);
    if(strstr(text,word)==NULL){
        printf("The word you searched for was NOT found.\n");
    }
    else{
        printf("The word you searched for was found.\n");
    }
}


//function for finding plural words
void pluralwords(char text[]){

     int plural=0;
        for(int i=0;i<strlen(text)/sizeof(char);i++){
        if(text[i]=='l'&&(text[i+1]=='a'||text[i+1]=='e')&&(text[i+2]=='r')){
            plural++;
            }
        }
        printf("%d plural words found.\t",plural);
    char chardivide[]=" ,;.:!?";
    char *splitword=strtok(text,chardivide);

    for(int i=0;i<strlen(splitword)/sizeof(char);i++){
        if(splitword[i]=='l'&&(splitword[i+1]=='a'||splitword[i+1]=='e')&&(splitword[i+2]=='r')){
            printf("%s  ",splitword);
            }
        }
     while(splitword!=NULL){
        splitword=strtok(NULL,chardivide);
        for(int i=0;i<strlen(splitword)/sizeof(char);i++){
            if(splitword[i]=='l'&&(splitword[i+1]=='a'||splitword[i+1]=='e')&&(splitword[i+2]=='r')){
                printf("%s  ",splitword);
                }
        }

     }

}

//function for finding great vovel harmony
int buyukunlu(char splitword[]){

    int kalinunlu=0,inceunlu=0;
    for(int i=0;i<strlen(splitword)/sizeof(char);i++){
        if(splitword[i]=='a'||splitword[i]=='A'){kalinunlu++;}
        if(splitword[i]=='Ý'||splitword[i]=='I'){kalinunlu++;}
        if(splitword[i]=='o'||splitword[i]=='O'){kalinunlu++;}
        if(splitword[i]=='u'||splitword[i]=='U'){kalinunlu++;}
        if(splitword[i]=='e'||splitword[i]=='E'){inceunlu++;}
        if(splitword[i]=='i'||splitword[i]=='Ý'){inceunlu++;}
        if(splitword[i]=='ö'||splitword[i]=='Ö'){inceunlu++;}
        if(splitword[i]=='ü'||splitword[i]=='Ü'){inceunlu++;}// ö ü ve Ý de sýkýntý var


    }
    if(kalinunlu>0&&inceunlu>0){
        return 0;
    }
    else{
        return 1;
    }

}


//function for finding little vovel harmony
int kucukunlu(char splitword[]){

    int k,roundvowel=0,flatvowel=0,differentvovel=0;//roundvovel =yuvarlak unlu flatvovel =duz unlu

    for(int i=0;i<strlen(splitword);i++){
        if(splitword[i]=='a'||splitword[i]=='e'||splitword[i]=='i'){
        k=i+1;
            for(k;k<strlen(splitword);k++){
             if(splitword[k]=='a'||splitword[k]=='e'||splitword[k]=='i') {
              flatvowel++;
            }
             else if(splitword[k]=='o'||splitword[k]=='u'){
              differentvovel++;
             }
            }
            break;
         }


        if(splitword[i]=='o'||splitword[i]=='u'){
        k=i+1;
            for(k;k<strlen(splitword);k++){
                if(splitword[k]=='a'||splitword[k]=='e'||splitword[k]=='u') {
                roundvowel++;
                }
                else if(splitword[k]=='o'||splitword[k]=='i'){
                differentvovel++;
                }
            }
            break;
        }
    }

     if(flatvowel>0&&differentvovel==0){
            return 1;
        }
     else if(roundvowel>0&&differentvovel==0){
            return 1;
        }
     else{
            return 0;
        }

}
//function for printing little vovel harmony

void littleharmony(char text[]){
    printf("kucuk unlu uyumuna uyan kelimeler : ");
    char chardivide[]=" ,;.:!?";
    char *splitword=strtok(text,chardivide);
        if(kucukunlu(splitword)==1){
            printf("%s  ",splitword);
            }
        while(splitword!=NULL){
            splitword=strtok(NULL,chardivide);
            if(kucukunlu(splitword)==1){
                printf("%s  ",splitword);
            }
        }

}


//function for printing great vovel harmony
void greatharmony(char text[]){

    printf("buyuk unlu uyumuna uyan kelimeler : ");
    char chardivide[]=" ,;.:!?";
    char text2[1000];
    strcpy(text2,text);
    char *splitword=strtok(text,chardivide);
        if(buyukunlu(splitword)==1){
            printf("%s  ",splitword);
            }

        while(splitword!=NULL){
            splitword=strtok(NULL,chardivide);
            if(buyukunlu(splitword)==1){
                printf("%s  ",splitword);
            }
        }

        printf("\nkucuk unlu uyumuna uyan kelimeler : ");

        char *splitword2=strtok(text2,chardivide);
        if(kucukunlu(splitword2)==1){
            printf("%s  ",splitword2);
            }
        while(splitword2!=NULL){
            splitword2=strtok(NULL,chardivide);
            if(kucukunlu(splitword2)==1){
                printf("%s  ",splitword2);
            }
        }



}
//function for printing ulama
void printulama(char text[]){
    char consonant[43]="bcdfghjklmnprsþtvyzBCDFGHJKLMNPRSTVWXYZ";//sessiz harfler
    char vowels[17]="aeiouAEIOU";//sesli harfler
    char chardivide[]=" ,;.:!?";
    char *splitword=strtok(text,chardivide);
    char *firstword,*secondword;
    firstword=splitword;

    while(splitword!=NULL){

    splitword=strtok(NULL,chardivide);

    secondword=splitword;

        if((strchr(consonant,(int)firstword[strlen(firstword)-1])!=NULL) && (strchr(vowels, (int)secondword[0])!=NULL)){

                printf("%s %s  ,",firstword,secondword);
        }

     firstword=secondword;
    }

}


//function for finding ulama
void findulama(char text[]){

    char consonant[43]="bcdfghjklmnprsþtvyzBCDFGHJKLMNPRSTVWXYZ";//sessiz harfler
    char vowels[17]="aeiouAEIOU";//sesli harfler
    int ulama=0,i=0;
        while(text[i+2]!='\0'){
            if((strchr(consonant,(int)text[i])!=NULL)&& (text[i+1]==' ') && (strchr(vowels, (int)text[i + 2])!=NULL)){
                ulama ++;
            }
            i++;
        }
        printf("%d ulama found.   ",ulama);
        printulama(text);
}

void findstrongsoftconsonant(char text[]){
    int strongc=0,softc=0;
    for(int i=0;i<strlen(text);i++){
        if(text[i]=='f'||text[i]=='s'||text[i]=='k'||text[i]=='h'||text[i]=='t'||text[i]=='p'){
        strongc++;
        }
        else if(text[i]=='b'||text[i]=='c'||text[i]=='d'||text[i]=='g'||text[i]=='j'||text[i]=='l'||
                text[i]=='l'||text[i]=='m'||text[i]=='n'||text[i]=='r'||text[i]=='v'||text[i]=='y'||text[i]=='z'){
            softc++;
        }
    }
    printf("\n%d strong consonants found",strongc);
    printf("\n%d soft consonants found",softc);


}



int main()
{
    setlocale(LC_ALL,"Turkish_turkish.1254");
    SetConsoleCP(1254);
    SetConsoleOutputCP(1254);


    //for turkish character problem



    char text[1000];
    int choice;
    printf("Enter a text\n");
    gets(text);
    do{

        printf("\nSelect what you are searching for\n");
        printf("1.Connexion(Ulama)\n");//calisiyo
        printf("2.Great Vowel harmony\n");//buyuk unlu uyumu calisiyo ama donguden atiyo
        printf("3.Little vowel harmony\n");//kucuk unlu uyumu calisiyo ama donguden atiyo
        printf("4.Plural words\n");// calisiyo ama donguden atýyo
        printf("5.Number of words, number of sentences, number of letters,\n");//calisiyo
        printf("6.Word search\n");//calisiyo
        printf("7.Strong-soft vowel \n");
        printf("8.Exit\n");
        scanf("%d",&choice);
        if(choice==1){
            findulama(text);
        }
        else if(choice==2){
            greatharmony(text);
        }
        else if(choice==3){
            littleharmony(text);
        }
        else if(choice==4){
            pluralwords(text);
        }
        else if(choice==5){
            letterwordsentence(text);
        }
        else if(choice==6){
            wordsearch(text);
        }
        else if(choice==7){
            findstrongsoftconsonant(text);
        }
    }while(choice<=7&&choice>=1);


    return 0;
}
