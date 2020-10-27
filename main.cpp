#include <iostream>
#include <conio.h>
#include <time.h>
#include <vector>

std::vector<char> readFile()
{
    std::vector <char> text;
    char tmp;

    FILE* inFile = fopen("inFile.in", "r");

    while(!feof(inFile)){
        fscanf(inFile, "%c", &tmp);
        text.push_back(tmp);
    }

    fclose(inFile);

    return text;
}

int main()
{
    std::vector<char> text = readFile();
    unsigned int misstakes = 0;
    clock_t tStart = clock();

    for(auto i: text)
        printf("%c", i);

    for(unsigned int i = 0; i < text.size() - 2; i++){
        if(text[i] != getch()){
            misstakes++;
            i--;
        }else
            printf("%c", text[i]);
    }

    printf("\n\nWPN %.0f. ", text.size()/5/(((double)(clock() - tStart)/CLOCKS_PER_SEC)/60));
    printf("Accuracy: %.2f%%.\n", 100 - (double)misstakes * 100 / text.size());
}
